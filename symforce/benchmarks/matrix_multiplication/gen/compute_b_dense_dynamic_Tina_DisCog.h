// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     backends/cpp/templates/function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once


#include <Eigen/Dense>



namespace sym {


/**
* This function was autogenerated. Do not modify by hand.
*
* Args:
*     x0: Scalar
*     x1: Scalar
*     x2: Scalar
*     x3: Scalar
*     x4: Scalar
*
* Outputs:
*     result: Matrix11_11
*/
template <typename Scalar>
Eigen::Matrix<Scalar, Eigen::Dynamic, Eigen::Dynamic> ComputeBDenseDynamicTinaDiscog(const Scalar x0, const Scalar x1, const Scalar x2, const Scalar x3, const Scalar x4) {

    // Total ops: 95

    // Input arrays

    // Intermediate terms (13)
    const Scalar _tmp0 = 2*x0;
    const Scalar _tmp1 = 2*x2;
    const Scalar _tmp2 = 2*x4;
    const Scalar _tmp3 = x2 + 1;
    const Scalar _tmp4 = -x2;
    const Scalar _tmp5 = (Scalar(1)/Scalar(2))*x4;
    const Scalar _tmp6 = x4 - 2;
    const Scalar _tmp7 = -x3;
    const Scalar _tmp8 = x1*x4;
    const Scalar _tmp9 = x0 + 1;
    const Scalar _tmp10 = -x4;
    const Scalar _tmp11 = _tmp0*x3;
    const Scalar _tmp12 = x1 + x2;

    // Output terms (1)
    Eigen::Matrix<Scalar, Eigen::Dynamic, Eigen::Dynamic> _result(11, 11);

    _result.setZero();

    _result(2, 0) = _tmp0 + x1 - 2;
    _result(9, 0) = _tmp1 + 6;
    _result(0, 1) = _tmp0;
    _result(2, 1) = x0*x4;
    _result(4, 1) = 3 - _tmp2;
    _result(7, 1) = x2*x3*(x2 + 2);
    _result(8, 1) = -x1 - x3*x4 - 2;
    _result(9, 1) = -x0 + x1 - 6;
    _result(0, 2) = _tmp3*x0*x1;
    _result(8, 2) = _tmp0 + 1;
    _result(9, 2) = -_tmp4 - x4 - 4;
    _result(1, 3) = _tmp4 + x1;
    _result(2, 3) = _tmp5 - Scalar(1)/Scalar(2)*x0 + x3;
    _result(4, 3) = _tmp6 + 3*x0;
    _result(5, 3) = _tmp3 + _tmp7 + x0;
    _result(6, 3) = _tmp2 + x0;
    _result(7, 3) = -4*std::pow(x1, Scalar(2))*x2;
    _result(10, 3) = -x3 - 1;
    _result(2, 4) = -_tmp0*x4 + x2*x4;
    _result(5, 4) = -x0 - 3;
    _result(9, 4) = _tmp0*_tmp8;
    _result(0, 5) = -x1*x2 + 2;
    _result(1, 5) = x0*(_tmp8 + x4);
    _result(2, 5) = _tmp7 + x1*x3 + 2;
    _result(4, 5) = _tmp9*(_tmp10 + x0);
    _result(10, 5) = _tmp7 + x1;
    _result(2, 6) = _tmp11 + 2;
    _result(3, 6) = -_tmp11 - _tmp7;
    _result(4, 6) = -6;
    _result(5, 6) = -x3*(2*x1 + 1);
    _result(7, 6) = x2 + x3 - 2;
    _result(8, 6) = _tmp1 + _tmp7 + _tmp9;
    _result(1, 7) = -3;
    _result(2, 7) = -x0 - x2;
    _result(3, 7) = _tmp1 + x3;
    _result(4, 7) = -_tmp5*x2 + Scalar(1)/Scalar(2);
    _result(5, 7) = -_tmp6 - x0;
    _result(6, 7) = x2*(x3 + 2)/_tmp3;
    _result(8, 7) = 2 - 2/(x1 + 1);
    _result(10, 7) = x0/x4;
    _result(6, 8) = 6*x0 - 3;
    _result(0, 9) = _tmp10 + _tmp9;
    _result(2, 9) = _tmp0*x2;
    _result(4, 9) = _tmp8;
    _result(6, 10) = _tmp12;
    _result(7, 10) = -1;
    _result(8, 10) = -_tmp12 - 4;

    return _result;
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
