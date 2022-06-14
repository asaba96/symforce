# -----------------------------------------------------------------------------
# This file was autogenerated by symforce from template:
#     backends/python/templates/cam_package/ops/CLASS/camera_ops.py.jinja
# Do NOT modify by hand.
# -----------------------------------------------------------------------------

import math
import numpy
import typing as T

import sym  # pylint: disable=unused-import


class CameraOps(object):
    """
    Python CameraOps implementation for <class 'symforce.cam.linear_camera_cal.LinearCameraCal'>.
    """

    @staticmethod
    def focal_length(self):
        # type: (sym.LinearCameraCal) -> T.List[float]
        """
        Return the focal length.
        """

        # Total ops: 0

        # Input arrays
        _self = self.data

        # Intermediate terms (0)

        # Output terms
        _focal_length = [0.0] * 2
        _focal_length[0] = _self[0]
        _focal_length[1] = _self[1]
        return _focal_length

    @staticmethod
    def principal_point(self):
        # type: (sym.LinearCameraCal) -> T.List[float]
        """
        Return the principal point.
        """

        # Total ops: 0

        # Input arrays
        _self = self.data

        # Intermediate terms (0)

        # Output terms
        _principal_point = [0.0] * 2
        _principal_point[0] = _self[2]
        _principal_point[1] = _self[3]
        return _principal_point

    @staticmethod
    def pixel_from_camera_point(self, point, epsilon):
        # type: (sym.LinearCameraCal, T.Sequence[float], float) -> T.Tuple[T.List[float], float]
        """
        Project a 3D point in the camera frame into 2D pixel coordinates.

        Return:
            pixel: (x, y) coordinate in pixels if valid
            is_valid: 1 if the operation is within bounds else 0
        """

        # Total ops: 11

        # Input arrays
        _self = self.data

        # Intermediate terms (1)
        _tmp0 = max(epsilon, abs(point[2])) ** (-1)

        # Output terms
        _pixel = [0.0] * 2
        _pixel[0] = _self[0] * _tmp0 * point[0] + _self[2]
        _pixel[1] = _self[1] * _tmp0 * point[1] + _self[3]
        _is_valid = max(0, (0.0 if point[2] == 0 else math.copysign(1, point[2])))
        return _pixel, _is_valid

    @staticmethod
    def pixel_from_camera_point_with_jacobians(self, point, epsilon):
        # type: (sym.LinearCameraCal, T.Sequence[float], float) -> T.Tuple[T.List[float], float, numpy.ndarray, numpy.ndarray]
        """
        Project a 3D point in the camera frame into 2D pixel coordinates.

        Return:
            pixel: (x, y) coordinate in pixels if valid
            is_valid: 1 if the operation is within bounds else 0
            pixel_D_cal: Derivative of pixel with respect to intrinsic calibration parameters
            pixel_D_point: Derivative of pixel with respect to point
        """

        # Total ops: 26

        # Input arrays
        _self = self.data

        # Intermediate terms (7)
        _tmp0 = abs(point[2])
        _tmp1 = max(_tmp0, epsilon)
        _tmp2 = _tmp1 ** (-1)
        _tmp3 = _self[0] * _tmp2
        _tmp4 = _self[1] * _tmp2
        _tmp5 = 0.0 if point[2] == 0 else math.copysign(1, point[2])
        _tmp6 = (
            (1.0 / 2.0)
            * _tmp5
            * ((0.0 if _tmp0 - epsilon == 0 else math.copysign(1, _tmp0 - epsilon)) + 1)
            / _tmp1 ** 2
        )

        # Output terms
        _pixel = [0.0] * 2
        _pixel[0] = _self[2] + _tmp3 * point[0]
        _pixel[1] = _self[3] + _tmp4 * point[1]
        _is_valid = max(0, _tmp5)
        _pixel_D_cal = numpy.zeros((2, 4))
        _pixel_D_cal[0, 0] = _tmp2 * point[0]
        _pixel_D_cal[1, 0] = 0
        _pixel_D_cal[0, 1] = 0
        _pixel_D_cal[1, 1] = _tmp2 * point[1]
        _pixel_D_cal[0, 2] = 1
        _pixel_D_cal[1, 2] = 0
        _pixel_D_cal[0, 3] = 0
        _pixel_D_cal[1, 3] = 1
        _pixel_D_point = numpy.zeros((2, 3))
        _pixel_D_point[0, 0] = _tmp3
        _pixel_D_point[1, 0] = 0
        _pixel_D_point[0, 1] = 0
        _pixel_D_point[1, 1] = _tmp4
        _pixel_D_point[0, 2] = -_self[0] * _tmp6 * point[0]
        _pixel_D_point[1, 2] = -_self[1] * _tmp6 * point[1]
        return _pixel, _is_valid, _pixel_D_cal, _pixel_D_point

    @staticmethod
    def camera_ray_from_pixel(self, pixel, epsilon):
        # type: (sym.LinearCameraCal, T.Sequence[float], float) -> T.Tuple[T.List[float], float]
        """
        Backproject a 2D pixel coordinate into a 3D ray in the camera frame.

        TODO(hayk): Add a normalize boolean argument? Like in `cam.Camera`

        Return:
            camera_ray: The ray in the camera frame (NOT normalized)
            is_valid: 1 if the operation is within bounds else 0
        """

        # Total ops: 4

        # Input arrays
        _self = self.data

        # Intermediate terms (0)

        # Output terms
        _camera_ray = [0.0] * 3
        _camera_ray[0] = (-_self[2] + pixel[0]) / _self[0]
        _camera_ray[1] = (-_self[3] + pixel[1]) / _self[1]
        _camera_ray[2] = 1
        _is_valid = 1
        return _camera_ray, _is_valid

    @staticmethod
    def camera_ray_from_pixel_with_jacobians(self, pixel, epsilon):
        # type: (sym.LinearCameraCal, T.Sequence[float], float) -> T.Tuple[T.List[float], float, numpy.ndarray, numpy.ndarray]
        """
        Backproject a 2D pixel coordinate into a 3D ray in the camera frame.

        Return:
            camera_ray: The ray in the camera frame (NOT normalized)
            is_valid: 1 if the operation is within bounds else 0
            point_D_cal: Derivative of point with respect to intrinsic calibration parameters
            point_D_pixel: Derivation of point with respect to pixel
        """

        # Total ops: 14

        # Input arrays
        _self = self.data

        # Intermediate terms (4)
        _tmp0 = -_self[2] + pixel[0]
        _tmp1 = _self[0] ** (-1)
        _tmp2 = -_self[3] + pixel[1]
        _tmp3 = _self[1] ** (-1)

        # Output terms
        _camera_ray = [0.0] * 3
        _camera_ray[0] = _tmp0 * _tmp1
        _camera_ray[1] = _tmp2 * _tmp3
        _camera_ray[2] = 1
        _is_valid = 1
        _point_D_cal = numpy.zeros((3, 4))
        _point_D_cal[0, 0] = -_tmp0 / _self[0] ** 2
        _point_D_cal[1, 0] = 0
        _point_D_cal[2, 0] = 0
        _point_D_cal[0, 1] = 0
        _point_D_cal[1, 1] = -_tmp2 / _self[1] ** 2
        _point_D_cal[2, 1] = 0
        _point_D_cal[0, 2] = -_tmp1
        _point_D_cal[1, 2] = 0
        _point_D_cal[2, 2] = 0
        _point_D_cal[0, 3] = 0
        _point_D_cal[1, 3] = -_tmp3
        _point_D_cal[2, 3] = 0
        _point_D_pixel = numpy.zeros((3, 2))
        _point_D_pixel[0, 0] = _tmp1
        _point_D_pixel[1, 0] = 0
        _point_D_pixel[2, 0] = 0
        _point_D_pixel[0, 1] = 0
        _point_D_pixel[1, 1] = _tmp3
        _point_D_pixel[2, 1] = 0
        return _camera_ray, _is_valid, _point_D_cal, _point_D_pixel
