// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     backends/cpp/templates/ops/CLASS/lie_group_ops.cc.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#include "./lie_group_ops.h"

#include <cmath>

#include <sym/spherical_camera_cal.h>

namespace sym {

template <typename Scalar>
sym::SphericalCameraCal<Scalar> LieGroupOps<SphericalCameraCal<Scalar>>::FromTangent(
    const TangentVec& vec, const Scalar epsilon) {
  // Total ops: 0

  // Input arrays

  // Intermediate terms (0)

  // Output terms (1)
  Eigen::Matrix<Scalar, 9, 1> _res;

  _res[0] = vec(0, 0);
  _res[1] = vec(1, 0);
  _res[2] = vec(2, 0);
  _res[3] = vec(3, 0);
  _res[4] = vec(4, 0);
  _res[5] = vec(5, 0);
  _res[6] = vec(6, 0);
  _res[7] = vec(7, 0);
  _res[8] = vec(8, 0);

  return sym::SphericalCameraCal<Scalar>(_res);
}

template <typename Scalar>
typename LieGroupOps<SphericalCameraCal<Scalar>>::TangentVec
LieGroupOps<SphericalCameraCal<Scalar>>::ToTangent(const sym::SphericalCameraCal<Scalar>& a,
                                                   const Scalar epsilon) {
  // Total ops: 0

  // Input arrays
  const Eigen::Matrix<Scalar, 9, 1>& _a = a.Data();

  // Intermediate terms (0)

  // Output terms (1)
  Eigen::Matrix<Scalar, 9, 1> _res;

  _res(0, 0) = _a[0];
  _res(1, 0) = _a[1];
  _res(2, 0) = _a[2];
  _res(3, 0) = _a[3];
  _res(4, 0) = _a[4];
  _res(5, 0) = _a[5];
  _res(6, 0) = _a[6];
  _res(7, 0) = _a[7];
  _res(8, 0) = _a[8];

  return _res;
}

template <typename Scalar>
sym::SphericalCameraCal<Scalar> LieGroupOps<SphericalCameraCal<Scalar>>::Retract(
    const sym::SphericalCameraCal<Scalar>& a, const TangentVec& vec, const Scalar epsilon) {
  // Total ops: 9

  // Input arrays
  const Eigen::Matrix<Scalar, 9, 1>& _a = a.Data();

  // Intermediate terms (0)

  // Output terms (1)
  Eigen::Matrix<Scalar, 9, 1> _res;

  _res[0] = _a[0] + vec(0, 0);
  _res[1] = _a[1] + vec(1, 0);
  _res[2] = _a[2] + vec(2, 0);
  _res[3] = _a[3] + vec(3, 0);
  _res[4] = _a[4] + vec(4, 0);
  _res[5] = _a[5] + vec(5, 0);
  _res[6] = _a[6] + vec(6, 0);
  _res[7] = _a[7] + vec(7, 0);
  _res[8] = _a[8] + vec(8, 0);

  return sym::SphericalCameraCal<Scalar>(_res);
}

template <typename Scalar>
typename LieGroupOps<SphericalCameraCal<Scalar>>::TangentVec
LieGroupOps<SphericalCameraCal<Scalar>>::LocalCoordinates(const sym::SphericalCameraCal<Scalar>& a,
                                                          const sym::SphericalCameraCal<Scalar>& b,
                                                          const Scalar epsilon) {
  // Total ops: 9

  // Input arrays
  const Eigen::Matrix<Scalar, 9, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 9, 1>& _b = b.Data();

  // Intermediate terms (0)

  // Output terms (1)
  Eigen::Matrix<Scalar, 9, 1> _res;

  _res(0, 0) = -_a[0] + _b[0];
  _res(1, 0) = -_a[1] + _b[1];
  _res(2, 0) = -_a[2] + _b[2];
  _res(3, 0) = -_a[3] + _b[3];
  _res(4, 0) = -_a[4] + _b[4];
  _res(5, 0) = -_a[5] + _b[5];
  _res(6, 0) = -_a[6] + _b[6];
  _res(7, 0) = -_a[7] + _b[7];
  _res(8, 0) = -_a[8] + _b[8];

  return _res;
}

}  // namespace sym

// Explicit instantiation
template struct sym::LieGroupOps<sym::SphericalCameraCal<double>>;
template struct sym::LieGroupOps<sym::SphericalCameraCal<float>>;
