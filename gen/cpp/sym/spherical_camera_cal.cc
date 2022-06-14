// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     backends/cpp/templates/cam_package/CLASS.cc.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#include "./spherical_camera_cal.h"

// Camera operation implementations
namespace sym {

template <typename Scalar>
Eigen::Matrix<Scalar, 2, 1> SphericalCameraCal<Scalar>::FocalLength() const {
  // Total ops: 0

  // Input arrays
  const Eigen::Matrix<Scalar, 9, 1>& _self = Data();

  // Intermediate terms (0)

  // Output terms (1)
  Eigen::Matrix<Scalar, 2, 1> _focal_length;

  _focal_length(0, 0) = _self[0];
  _focal_length(1, 0) = _self[1];

  return _focal_length;
}

template <typename Scalar>
Eigen::Matrix<Scalar, 2, 1> SphericalCameraCal<Scalar>::PrincipalPoint() const {
  // Total ops: 0

  // Input arrays
  const Eigen::Matrix<Scalar, 9, 1>& _self = Data();

  // Intermediate terms (0)

  // Output terms (1)
  Eigen::Matrix<Scalar, 2, 1> _principal_point;

  _principal_point(0, 0) = _self[2];
  _principal_point(1, 0) = _self[3];

  return _principal_point;
}

template <typename Scalar>
Eigen::Matrix<Scalar, 2, 1> SphericalCameraCal<Scalar>::PixelFromCameraPoint(
    const Eigen::Matrix<Scalar, 3, 1>& point, const Scalar epsilon, Scalar* const is_valid) const {
  // Total ops: 30

  // Input arrays
  const Eigen::Matrix<Scalar, 9, 1>& _self = Data();

  // Intermediate terms (4)
  const Scalar _tmp0 = std::sqrt(
      Scalar(epsilon + std::pow(point(0, 0), Scalar(2)) + std::pow(point(1, 0), Scalar(2))));
  const Scalar _tmp1 = std::atan2(_tmp0, point(2, 0));
  const Scalar _tmp2 = std::min<Scalar>(_tmp1, _self[4] - epsilon);
  const Scalar _tmp3 =
      (_self[5] *
           [&]() {
             const Scalar base = _tmp2;
             return base * base * base;
           }() +
       _self[6] * std::pow(_tmp2, Scalar(5)) + _self[7] * std::pow(_tmp2, Scalar(7)) +
       _self[8] * std::pow(_tmp2, Scalar(9)) + _tmp2) /
      _tmp0;

  // Output terms (2)
  Eigen::Matrix<Scalar, 2, 1> _pixel;

  _pixel(0, 0) = _self[0] * _tmp3 * point(0, 0) + _self[2];
  _pixel(1, 0) = _self[1] * _tmp3 * point(1, 0) + _self[3];

  if (is_valid != nullptr) {
    Scalar& _is_valid = (*is_valid);

    _is_valid = std::max<Scalar>(0, (((_self[4] - _tmp1) > 0) - ((_self[4] - _tmp1) < 0)));
  }

  return _pixel;
}

template <typename Scalar>
Eigen::Matrix<Scalar, 2, 1> SphericalCameraCal<Scalar>::PixelFromCameraPointWithJacobians(
    const Eigen::Matrix<Scalar, 3, 1>& point, const Scalar epsilon, Scalar* const is_valid,
    Eigen::Matrix<Scalar, 2, 8>* const pixel_D_cal,
    Eigen::Matrix<Scalar, 2, 3>* const pixel_D_point) const {
  // Total ops: 129

  // Input arrays
  const Eigen::Matrix<Scalar, 9, 1>& _self = Data();

  // Intermediate terms (40)
  const Scalar _tmp0 = -epsilon;
  const Scalar _tmp1 = std::pow(point(1, 0), Scalar(2));
  const Scalar _tmp2 = std::pow(point(0, 0), Scalar(2));
  const Scalar _tmp3 = _tmp1 + _tmp2 + epsilon;
  const Scalar _tmp4 = std::sqrt(_tmp3);
  const Scalar _tmp5 = std::atan2(_tmp4, point(2, 0));
  const Scalar _tmp6 = std::min<Scalar>(_tmp5, _self[4] + _tmp0);
  const Scalar _tmp7 = std::pow(_tmp6, Scalar(5));
  const Scalar _tmp8 = std::pow(_tmp6, Scalar(7));
  const Scalar _tmp9 = std::pow(_tmp6, Scalar(9));
  const Scalar _tmp10 = [&]() {
    const Scalar base = _tmp6;
    return base * base * base;
  }();
  const Scalar _tmp11 =
      _self[5] * _tmp10 + _self[6] * _tmp7 + _self[7] * _tmp8 + _self[8] * _tmp9 + _tmp6;
  const Scalar _tmp12 = Scalar(1.0) / (_tmp4);
  const Scalar _tmp13 = _tmp11 * _tmp12;
  const Scalar _tmp14 = _tmp13 * point(0, 0);
  const Scalar _tmp15 = _tmp13 * point(1, 0);
  const Scalar _tmp16 = _self[4] - _tmp5;
  const Scalar _tmp17 = _self[0] * point(0, 0);
  const Scalar _tmp18 = _tmp12 * _tmp17;
  const Scalar _tmp19 = _self[1] * point(1, 0);
  const Scalar _tmp20 = _tmp12 * _tmp19;
  const Scalar _tmp21 = _tmp12 * _tmp9;
  const Scalar _tmp22 = (Scalar(9) / Scalar(2)) * _self[8] * std::pow(_tmp6, Scalar(8));
  const Scalar _tmp23 = ((((_tmp0 + _tmp16) > 0) - ((_tmp0 + _tmp16) < 0)) + 1) /
                        (_tmp3 + std::pow(point(2, 0), Scalar(2)));
  const Scalar _tmp24 = _tmp12 * point(2, 0);
  const Scalar _tmp25 = _tmp23 * _tmp24;
  const Scalar _tmp26 = _tmp22 * _tmp25;
  const Scalar _tmp27 = (Scalar(5) / Scalar(2)) * _self[6] * std::pow(_tmp6, Scalar(4));
  const Scalar _tmp28 = _tmp25 * _tmp27;
  const Scalar _tmp29 = (Scalar(7) / Scalar(2)) * _self[7] * std::pow(_tmp6, Scalar(6));
  const Scalar _tmp30 = _tmp25 * _tmp29;
  const Scalar _tmp31 = (Scalar(3) / Scalar(2)) * _self[5] * std::pow(_tmp6, Scalar(2));
  const Scalar _tmp32 = _tmp25 * _tmp31;
  const Scalar _tmp33 = (Scalar(1) / Scalar(2)) * _tmp23;
  const Scalar _tmp34 = _tmp24 * _tmp33;
  const Scalar _tmp35 = _tmp26 * point(0, 0) + _tmp28 * point(0, 0) + _tmp30 * point(0, 0) +
                        _tmp32 * point(0, 0) + _tmp34 * point(0, 0);
  const Scalar _tmp36 = _tmp11 / (_tmp3 * std::sqrt(_tmp3));
  const Scalar _tmp37 = _tmp26 * point(1, 0) + _tmp28 * point(1, 0) + _tmp30 * point(1, 0) +
                        _tmp32 * point(1, 0) + _tmp34 * point(1, 0);
  const Scalar _tmp38 = _tmp23 * _tmp4;
  const Scalar _tmp39 = _tmp12 * (-_tmp22 * _tmp38 - _tmp27 * _tmp38 - _tmp29 * _tmp38 -
                                  _tmp31 * _tmp38 - _tmp33 * _tmp4);

  // Output terms (4)
  Eigen::Matrix<Scalar, 2, 1> _pixel;

  _pixel(0, 0) = _self[0] * _tmp14 + _self[2];
  _pixel(1, 0) = _self[1] * _tmp15 + _self[3];

  if (is_valid != nullptr) {
    Scalar& _is_valid = (*is_valid);

    _is_valid = std::max<Scalar>(0, (((_tmp16) > 0) - ((_tmp16) < 0)));
  }

  if (pixel_D_cal != nullptr) {
    Eigen::Matrix<Scalar, 2, 8>& _pixel_D_cal = (*pixel_D_cal);

    _pixel_D_cal(0, 0) = _tmp14;
    _pixel_D_cal(1, 0) = 0;
    _pixel_D_cal(0, 1) = 0;
    _pixel_D_cal(1, 1) = _tmp15;
    _pixel_D_cal(0, 2) = 1;
    _pixel_D_cal(1, 2) = 0;
    _pixel_D_cal(0, 3) = 0;
    _pixel_D_cal(1, 3) = 1;
    _pixel_D_cal(0, 4) = _tmp10 * _tmp18;
    _pixel_D_cal(1, 4) = _tmp10 * _tmp20;
    _pixel_D_cal(0, 5) = _tmp18 * _tmp7;
    _pixel_D_cal(1, 5) = _tmp20 * _tmp7;
    _pixel_D_cal(0, 6) = _tmp18 * _tmp8;
    _pixel_D_cal(1, 6) = _tmp20 * _tmp8;
    _pixel_D_cal(0, 7) = _tmp17 * _tmp21;
    _pixel_D_cal(1, 7) = _tmp19 * _tmp21;
  }

  if (pixel_D_point != nullptr) {
    Eigen::Matrix<Scalar, 2, 3>& _pixel_D_point = (*pixel_D_point);

    _pixel_D_point(0, 0) = _self[0] * _tmp13 - _self[0] * _tmp2 * _tmp36 + _tmp18 * _tmp35;
    _pixel_D_point(1, 0) = -_tmp19 * _tmp36 * point(0, 0) + _tmp20 * _tmp35;
    _pixel_D_point(0, 1) = -_tmp17 * _tmp36 * point(1, 0) + _tmp18 * _tmp37;
    _pixel_D_point(1, 1) = -_self[1] * _tmp1 * _tmp36 + _self[1] * _tmp13 + _tmp20 * _tmp37;
    _pixel_D_point(0, 2) = _tmp17 * _tmp39;
    _pixel_D_point(1, 2) = _tmp19 * _tmp39;
  }

  return _pixel;
}

// Print implementations
std::ostream& operator<<(std::ostream& os, const SphericalCameraCald& a) {
  const Eigen::IOFormat fmt(Eigen::StreamPrecision, Eigen::DontAlignCols, ", ", "\n", "[", "]");
  os << "<SphericalCameraCald " << a.Data().transpose().format(fmt) << ">";
  return os;
}

std::ostream& operator<<(std::ostream& os, const SphericalCameraCalf& a) {
  const Eigen::IOFormat fmt(Eigen::StreamPrecision, Eigen::DontAlignCols, ", ", "\n", "[", "]");
  os << "<SphericalCameraCalf " << a.Data().transpose().format(fmt) << ">";
  return os;
}

}  // namespace sym

// Concept implementations for this class
#include "./ops/spherical_camera_cal/storage_ops.h"

// Explicit instantiation
template class sym::SphericalCameraCal<double>;
template class sym::SphericalCameraCal<float>;
