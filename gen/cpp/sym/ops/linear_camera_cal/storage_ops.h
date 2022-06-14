// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     backends/cpp/templates/ops/CLASS/storage_ops.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <lcmtypes/sym/type_t.hpp>

#include "../storage_ops.h"

// Forward declare class, without including header
// We could include the class header here, but we forward declare to be consistent
// with "./group_ops.h", which must forward declare. See that file for an explanation.
namespace sym {
template <typename ScalarType>
class LinearCameraCal;
}  // namespace sym

namespace sym {

/**
 * C++ StorageOps implementation for <class 'symforce.cam.linear_camera_cal.LinearCameraCal'>.
 */
template <typename ScalarType>
struct StorageOps<LinearCameraCal<ScalarType>> {
  using T = LinearCameraCal<ScalarType>;
  using Scalar = ScalarType;

  static constexpr int32_t StorageDim() {
    return 4;
  }

  static void ToStorage(const T& a, ScalarType* out);
  static T FromStorage(const ScalarType* data);

  static constexpr type_t TypeEnum() {
    return type_t::LINEAR_CAMERA_CAL;
  }
};

}  // namespace sym

// Explicit instantiation
extern template struct sym::StorageOps<sym::LinearCameraCal<double>>;
extern template struct sym::StorageOps<sym::LinearCameraCal<float>>;
