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
*     result: Matrix20_15
*/
template <typename Scalar>
Eigen::Matrix<Scalar, 20, 15> ComputeADenseN3C4B2(const Scalar x0, const Scalar x1, const Scalar x2, const Scalar x3, const Scalar x4) {

    // Total ops: 133

    // Input arrays

    // Intermediate terms (23)
    const Scalar _tmp0 = x1*x2;
    const Scalar _tmp1 = x1 + 2;
    const Scalar _tmp2 = -x1;
    const Scalar _tmp3 = _tmp2 + x4;
    const Scalar _tmp4 = 4*x4;
    const Scalar _tmp5 = -x4;
    const Scalar _tmp6 = std::pow(x2, Scalar(2));
    const Scalar _tmp7 = 2*_tmp6;
    const Scalar _tmp8 = 2*x0;
    const Scalar _tmp9 = x3*x4;
    const Scalar _tmp10 = x1 - 2;
    const Scalar _tmp11 = -x3;
    const Scalar _tmp12 = 4*x1;
    const Scalar _tmp13 = x0*x3;
    const Scalar _tmp14 = (Scalar(1)/Scalar(2))*x0;
    const Scalar _tmp15 = 2*x1;
    const Scalar _tmp16 = x3 + x4;
    const Scalar _tmp17 = x2 - 1;
    const Scalar _tmp18 = 2*x4;
    const Scalar _tmp19 = x1 - 1;
    const Scalar _tmp20 = _tmp8 + x2;
    const Scalar _tmp21 = -_tmp18;
    const Scalar _tmp22 = x1*x3;

    // Output terms (1)
    Eigen::Matrix<Scalar, 20, 15> _result;

    _result.setZero();

    _result(9, 0) = -_tmp0;
    _result(15, 0) = -x4 - 6;
    _result(18, 0) = -_tmp1*x4;
    _result(19, 0) = x3*(x3 - 1) - 1;
    _result(8, 1) = 2;
    _result(14, 1) = -_tmp3 - 2;
    _result(17, 1) = x0*std::pow(x3, Scalar(2))*(x0 - 2);
    _result(19, 1) = -2/x1;
    _result(7, 2) = _tmp4;
    _result(13, 2) = -_tmp5 - x1/x2;
    _result(16, 2) = x2 - 2;
    _result(19, 2) = -_tmp5 - x0;
    _result(6, 3) = -_tmp7*x4;
    _result(12, 3) = x1 - 4;
    _result(17, 3) = x2 + 3;
    _result(18, 3) = -_tmp8*x3 + 1;
    _result(5, 4) = _tmp9*(x0 + x1);
    _result(11, 4) = _tmp7;
    _result(16, 4) = x3*(x0 + 7);
    _result(18, 4) = -_tmp10*(_tmp11 + x1);
    _result(4, 5) = -_tmp1;
    _result(10, 5) = -_tmp8 - 1;
    _result(16, 5) = _tmp12 + x4;
    _result(17, 5) = -_tmp13 - x0 - x3;
    _result(3, 6) = _tmp9*(1 - x2/x0);
    _result(12, 6) = _tmp14 - _tmp15;
    _result(14, 6) = -x0*(_tmp16 + 2) + 2;
    _result(15, 6) = -_tmp12 - _tmp4;
    _result(2, 7) = 2 - _tmp9/_tmp17;
    _result(11, 7) = -_tmp15*x3 - 2;
    _result(13, 7) = x0;
    _result(15, 7) = -_tmp10 - x3;
    _result(1, 8) = x3*(-_tmp18*x2 + x1);
    _result(10, 8) = -_tmp19*x3 - x0;
    _result(13, 8) = -_tmp11 - x2 - 2;
    _result(14, 8) = -4/(_tmp8 - 2);
    _result(0, 9) = -_tmp13 - 2;
    _result(10, 9) = _tmp14;
    _result(11, 9) = _tmp11 + _tmp20;
    _result(12, 9) = -x3*(_tmp2 + x2 + 1);
    _result(3, 10) = -_tmp8*(x0 + x2) - 2;
    _result(6, 10) = _tmp21 + 2*x2 + 2;
    _result(8, 10) = -_tmp16;
    _result(9, 10) = x1 + x2 - 3;
    _result(2, 11) = 2 - _tmp15;
    _result(5, 11) = _tmp13*x1;
    _result(7, 11) = -2*_tmp0*(x1 + 1);
    _result(9, 11) = 3;
    _result(1, 12) = -_tmp6*(x3 - 2);
    _result(4, 12) = -_tmp19;
    _result(7, 12) = _tmp22;
    _result(8, 12) = -_tmp15*_tmp9;
    _result(0, 13) = 1 - x4;
    _result(4, 13) = -_tmp3 - _tmp9*x2;
    _result(5, 13) = _tmp17 + x4;
    _result(6, 13) = -_tmp20;
    _result(0, 14) = -_tmp22;
    _result(1, 14) = _tmp19;
    _result(2, 14) = _tmp0*x0 + _tmp8;
    _result(3, 14) = -_tmp21 - x1;

    return _result;
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
