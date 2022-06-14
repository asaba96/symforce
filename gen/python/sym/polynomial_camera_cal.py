# -----------------------------------------------------------------------------
# This file was autogenerated by symforce from template:
#     backends/python/templates/cam_package/CLASS.py.jinja
# Do NOT modify by hand.
# -----------------------------------------------------------------------------

import numpy
import typing as T

from .ops import polynomial_camera_cal as ops


class PolynomialCameraCal(object):
    """
    Autogenerated Python implementation of <class 'symforce.cam.polynomial_camera_cal.PolynomialCameraCal'>.

    Polynomial camera model in the style of OpenCV.
    Distortion is a multiplicitive factor applied to the image plane coordinates in the camera
    frame. Mapping between distorted image plane coordinates and image coordinates is done using
    a standard linear model.

    The distortion function is a 6th order even polynomial that is a function of the radius of the
    image plane coordinates.
    r = (p_img[0] ** 2 + p_img[1]**2) ** 0.5
    distorted_weight = 1 + c0 * r^2 + c1 * r^4 + c2 * r^6
    uv = p_img * distorted_weight
    """

    __slots__ = ["data"]

    # This is because of an issue where mypy doesn't recognize attributes defined in __slots__
    # See https://github.com/python/mypy/issues/5941
    if T.TYPE_CHECKING:
        data = []  # type: T.List[float]

    def __init__(
        self, focal_length, principal_point, critical_undistorted_radius, distortion_coeffs
    ):
        # type: (T.Sequence[float], T.Sequence[float], float, T.Sequence[float]) -> None
        self.data = []
        if len(focal_length) != 2:
            raise ValueError(
                "Expected focal_length to be a sequence of length 2, was instead length {}.".format(
                    len(focal_length)
                )
            )
        if len(principal_point) != 2:
            raise ValueError(
                "Expected principal_point to be a sequence of length 2, was instead length {}.".format(
                    len(principal_point)
                )
            )
        if len(distortion_coeffs) != 3:
            raise ValueError(
                "Expected distortion_coeffs to be a sequence of length 3, was instead length {}.".format(
                    len(distortion_coeffs)
                )
            )

        self.data.extend(focal_length)
        self.data.extend(principal_point)
        self.data.append(critical_undistorted_radius)
        self.data.extend(distortion_coeffs)

    def __repr__(self):
        # type: () -> str
        return "<{} {}>".format(self.__class__.__name__, self.data)

    # --------------------------------------------------------------------------
    # CameraOps
    # --------------------------------------------------------------------------

    def focal_length(self):
        # type: (PolynomialCameraCal) -> T.List[float]
        """
        Return the focal length.
        """

        return ops.CameraOps.focal_length(self)

    def principal_point(self):
        # type: (PolynomialCameraCal) -> T.List[float]
        """
        Return the principal point.
        """

        return ops.CameraOps.principal_point(self)

    def pixel_from_camera_point(self, point, epsilon):
        # type: (PolynomialCameraCal, T.Sequence[float], float) -> T.Tuple[T.List[float], float]
        """
        Project a 3D point in the camera frame into 2D pixel coordinates.

        Return:
            pixel: (x, y) coordinate in pixels if valid
            is_valid: 1 if the operation is within bounds else 0
        """

        return ops.CameraOps.pixel_from_camera_point(self, point, epsilon)

    def pixel_from_camera_point_with_jacobians(self, point, epsilon):
        # type: (PolynomialCameraCal, T.Sequence[float], float) -> T.Tuple[T.List[float], float, numpy.ndarray, numpy.ndarray]
        """
        Project a 3D point in the camera frame into 2D pixel coordinates.

        Return:
            pixel: (x, y) coordinate in pixels if valid
            is_valid: 1 if the operation is within bounds else 0
            pixel_D_cal: Derivative of pixel with respect to intrinsic calibration parameters
            pixel_D_point: Derivative of pixel with respect to point
        """

        return ops.CameraOps.pixel_from_camera_point_with_jacobians(self, point, epsilon)

    # --------------------------------------------------------------------------
    # StorageOps concept
    # --------------------------------------------------------------------------

    @staticmethod
    def storage_dim():
        # type: () -> int
        return 8

    def to_storage(self):
        # type: () -> T.List[float]
        return list(self.data)

    @classmethod
    def from_storage(cls, vec):
        # type: (T.Sequence[float]) -> PolynomialCameraCal
        instance = cls.__new__(cls)

        if isinstance(vec, list):
            instance.data = vec
        else:
            instance.data = list(vec)

        if len(vec) != cls.storage_dim():
            raise ValueError(
                "{} has storage dim {}, got {}.".format(cls.__name__, cls.storage_dim(), len(vec))
            )

        return instance

    # --------------------------------------------------------------------------
    # LieGroupOps concept
    # --------------------------------------------------------------------------

    @staticmethod
    def tangent_dim():
        # type: () -> int
        return 8

    @classmethod
    def from_tangent(cls, vec, epsilon=1e-8):
        # type: (T.Sequence[float], float) -> PolynomialCameraCal
        if len(vec) != cls.tangent_dim():
            raise ValueError(
                "Vector dimension ({}) not equal to tangent space dimension ({}).".format(
                    len(vec), cls.tangent_dim()
                )
            )
        return ops.LieGroupOps.from_tangent(vec, epsilon)

    def to_tangent(self, epsilon=1e-8):
        # type: (float) -> T.List[float]
        return ops.LieGroupOps.to_tangent(self, epsilon)

    def retract(self, vec, epsilon=1e-8):
        # type: (T.Sequence[float], float) -> PolynomialCameraCal
        if len(vec) != self.tangent_dim():
            raise ValueError(
                "Vector dimension ({}) not equal to tangent space dimension ({}).".format(
                    len(vec), self.tangent_dim()
                )
            )
        return ops.LieGroupOps.retract(self, vec, epsilon)

    def local_coordinates(self, b, epsilon=1e-8):
        # type: (PolynomialCameraCal, float) -> T.List[float]
        return ops.LieGroupOps.local_coordinates(self, b, epsilon)

    # --------------------------------------------------------------------------
    # General Helpers
    # --------------------------------------------------------------------------
    def __eq__(self, other):
        # type: (T.Any) -> bool
        if isinstance(other, PolynomialCameraCal):
            return self.data == other.data
        else:
            return False
