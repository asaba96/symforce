# High level build commands for symforce

BUILD_DIR=build

PYTHON=***REMOVED***/bin/***REMOVED***
PYTHON2=***REMOVED***/bin/mc_python

BLACK_EXCLUDE='symforce/codegen/python/templates|/gen/|test_data/'

# -----------------------------------------------------------------------------
# Main
# -----------------------------------------------------------------------------

# Build documentation, run tests, measure coverage, show in browser
all: clean docs coverage coverage_open docs_open

# Install all needed packages
all_reqs: reqs test_reqs docs_reqs

# Install python requirements for core library
reqs:
	${PYTHON} -m pip install -r requirements.txt

# Format using black
format:
	$(PYTHON) -m black --line-length 100 . --exclude $(BLACK_EXCLUDE)

# Check formatting using black - print diff, do not modify files
check_format:
	$(PYTHON) -m black --line-length 100 . --exclude $(BLACK_EXCLUDE) --check --diff

# Check type hints using mypy
check_types:
	$(PYTHON) -m mypy --py2 . test --disallow-untyped-defs

# Lint check for formatting and type hints
# This needs pass before any merge.
lint: check_types check_format

# Clean all artifacts
clean: docs_clean coverage_clean
	rm -rf $(BUILD_DIR)

.PHONY: all reqs format check_format check_types lint clean

# -----------------------------------------------------------------------------
# Tests
# -----------------------------------------------------------------------------

TEST_ENV=SYMFORCE_LOGLEVEL=WARNING
TEST_CMD=-m unittest discover -s test/ -p *_test.py -v

test_reqs:
	${PYTHON} -m pip install -r test/requirements.txt

test:
	$(TEST_ENV) $(PYTHON) $(TEST_CMD)

.PHONY: test_reqs test

# -----------------------------------------------------------------------------
# Test coverage
# -----------------------------------------------------------------------------
COVERAGE_DIR=$(BUILD_DIR)/coverage

coverage_clean:
	rm -rf $(COVERAGE_DIR)

coverage_run:
	$(TEST_ENV) $(PYTHON) -m coverage run --source=symforce,gen --omit=symforce/codegen/python/templates/* $(TEST_CMD)

coverage_html:
	$(PYTHON) -m coverage html -d $(COVERAGE_DIR) && echo "Coverage report at $(COVERAGE_DIR)/index.html"

coverage: coverage_clean coverage_run coverage_html

coverage_open: coverage
	open $(COVERAGE_DIR)/index.html

.PHONY: coverage_clean coverage_run coverage_html coverage coverage_open

# -----------------------------------------------------------------------------
# Documentation
# -----------------------------------------------------------------------------
DOCS_DIR=$(BUILD_DIR)/docs

docs_reqs:
	${PYTHON} -m pip install -r test/requirements.txt

docs_clean:
	rm -rf $(DOCS_DIR); rm -rf docs/api

docs_apidoc:
	sphinx-apidoc --separate --module-first -o docs/api ./symforce

docs_html:
	SYMFORCE_LOGLEVEL=WARNING $(PYTHON) -m sphinx -b html docs $(DOCS_DIR) -j4

docs: docs_clean docs_apidoc docs_html

docs_open: docs
	open $(DOCS_DIR)/index.html

.PHONY: docs_reqs docs_clean docs_apidoc docs_html docs docs_open

# -----------------------------------------------------------------------------
# Notebook
# -----------------------------------------------------------------------------

notebook:
	PYTHONPATH=..:../.. $(PYTHON2) -m jupyter notebook --notebook-dir=notebooks --ip=0.0.0.0 --port=8777 --no-browser

notebook_open:
	PYTHONPATH=..:../.. $(PYTHON) -m jupyter notebook --notebook-dir=notebooks --ip=localhost --port=8777
