// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     backends/cpp/templates/function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once


#include <Eigen/Dense>
#include <Eigen/Sparse>



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
*     result: Matrix36_84
*/
template <typename Scalar>
Eigen::SparseMatrix<Scalar> ComputeBBibd93(const Scalar x0, const Scalar x1, const Scalar x2, const Scalar x3, const Scalar x4) {

    // Total ops: 449

    // Input arrays

    // Intermediate terms (77)
    const Scalar _tmp0 = x2 + 2;
    const Scalar _tmp1 = Scalar(1.0) / (x0);
    const Scalar _tmp2 = _tmp1*x4;
    const Scalar _tmp3 = -_tmp2;
    const Scalar _tmp4 = x0 - 2;
    const Scalar _tmp5 = -_tmp0;
    const Scalar _tmp6 = x1*x3;
    const Scalar _tmp7 = 2*x1;
    const Scalar _tmp8 = std::pow(x1, Scalar(2));
    const Scalar _tmp9 = (Scalar(1)/Scalar(2))*x1;
    const Scalar _tmp10 = x1 - 2;
    const Scalar _tmp11 = x1*x4;
    const Scalar _tmp12 = x2*x3;
    const Scalar _tmp13 = 2*x4;
    const Scalar _tmp14 = Scalar(1.0) / (x3);
    const Scalar _tmp15 = x0*x2;
    const Scalar _tmp16 = -_tmp13;
    const Scalar _tmp17 = x2 + x3;
    const Scalar _tmp18 = 4*x3;
    const Scalar _tmp19 = 2*x3;
    const Scalar _tmp20 = -_tmp19;
    const Scalar _tmp21 = -x2;
    const Scalar _tmp22 = 3*x0;
    const Scalar _tmp23 = -x3;
    const Scalar _tmp24 = x0 + x2;
    const Scalar _tmp25 = x0*x1;
    const Scalar _tmp26 = x3 + 3;
    const Scalar _tmp27 = x0 + 1;
    const Scalar _tmp28 = x3*x4;
    const Scalar _tmp29 = x0 + 2;
    const Scalar _tmp30 = 2*x0;
    const Scalar _tmp31 = -_tmp30;
    const Scalar _tmp32 = _tmp7 + x3;
    const Scalar _tmp33 = x4 + 2;
    const Scalar _tmp34 = _tmp7*x0;
    const Scalar _tmp35 = x2 + 1;
    const Scalar _tmp36 = -x4;
    const Scalar _tmp37 = x0 - 1;
    const Scalar _tmp38 = _tmp23 + 1;
    const Scalar _tmp39 = _tmp6*x0;
    const Scalar _tmp40 = -x0;
    const Scalar _tmp41 = x0*x3;
    const Scalar _tmp42 = x2 + x4;
    const Scalar _tmp43 = x1 + x4;
    const Scalar _tmp44 = _tmp19*x0;
    const Scalar _tmp45 = -x1;
    const Scalar _tmp46 = _tmp11*x0;
    const Scalar _tmp47 = Scalar(1.0) / (x2);
    const Scalar _tmp48 = x2 - 2;
    const Scalar _tmp49 = 2*x2;
    const Scalar _tmp50 = x1 + 1;
    const Scalar _tmp51 = x3 + 1;
    const Scalar _tmp52 = x1 - 1;
    const Scalar _tmp53 = x4 - 1;
    const Scalar _tmp54 = Scalar(1.0) / (x1);
    const Scalar _tmp55 = _tmp41*_tmp54;
    const Scalar _tmp56 = _tmp14*x4;
    const Scalar _tmp57 = _tmp23 + x0;
    const Scalar _tmp58 = x0 + x4;
    const Scalar _tmp59 = _tmp36 + x1;
    const Scalar _tmp60 = _tmp13 - 2;
    const Scalar _tmp61 = _tmp21 + x3;
    const Scalar _tmp62 = std::pow(x0, Scalar(2));
    const Scalar _tmp63 = x1*x2;
    const Scalar _tmp64 = _tmp40 + 2;
    const Scalar _tmp65 = x3 + 2;
    const Scalar _tmp66 = _tmp21 + x0;
    const Scalar _tmp67 = x4 - 2;
    const Scalar _tmp68 = 2 - _tmp7;
    const Scalar _tmp69 = Scalar(1.0) / (x4);
    const Scalar _tmp70 = -_tmp49;
    const Scalar _tmp71 = _tmp36 + x0;
    const Scalar _tmp72 = 2*_tmp14;
    const Scalar _tmp73 = x3 - 2;
    const Scalar _tmp74 = _tmp63 + x4;
    const Scalar _tmp75 = _tmp13 - 1;
    const Scalar _tmp76 = x3 - 1;

    // Output terms (1)
    static constexpr int kRows_result = 36;
    static constexpr int kCols_result = 84;
    static constexpr int kNumNonZero_result = 245;
    static constexpr int kColPtrs_result[] = {0, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45, 48, 51, 54, 57, 60, 63, 66, 69, 72, 75, 78, 80, 83, 86, 89, 92, 95, 98, 99, 102, 105, 108, 111, 114, 117, 120, 123, 126, 128, 131, 134, 137, 140, 143, 146, 149, 152, 155, 158, 161, 164, 167, 170, 173, 176, 179, 182, 184, 187, 190, 193, 196, 199, 202, 205, 208, 211, 214, 217, 220, 223, 226, 228, 231, 233, 236, 239, 242, 245};
    static constexpr int kRowIndices_result[] = {0, 1, 8, 0, 2, 9, 0, 3, 10, 0, 4, 11, 0, 5, 12, 0, 6, 13, 0, 7, 14, 1, 2, 15, 1, 3, 16, 1, 4, 17, 1, 5, 18, 1, 6, 19, 1, 7, 20, 2, 3, 21, 2, 4, 22, 2, 5, 23, 2, 6, 24, 2, 7, 25, 3, 4, 26, 3, 5, 27, 3, 6, 28, 3, 7, 29, 4, 5, 30, 4, 6, 31, 4, 7, 32, 5, 6, 33, 5, 7, 6, 7, 35, 8, 9, 15, 8, 10, 16, 8, 11, 17, 8, 12, 18, 8, 13, 19, 20, 9, 10, 21, 9, 11, 22, 9, 12, 23, 9, 13, 24, 9, 14, 25, 10, 11, 26, 10, 12, 27, 10, 13, 28, 10, 14, 29, 11, 12, 11, 13, 31, 11, 14, 32, 12, 13, 33, 12, 14, 34, 13, 14, 35, 15, 16, 21, 15, 17, 22, 15, 18, 23, 15, 19, 24, 15, 20, 25, 16, 17, 26, 16, 18, 27, 16, 19, 28, 16, 20, 29, 17, 18, 30, 17, 19, 31, 17, 20, 32, 18, 19, 33, 18, 34, 19, 20, 35, 21, 22, 26, 21, 23, 27, 21, 24, 28, 21, 25, 29, 22, 23, 30, 22, 24, 31, 22, 25, 32, 23, 24, 33, 23, 25, 34, 24, 25, 35, 26, 27, 30, 26, 28, 31, 26, 29, 32, 27, 28, 27, 29, 34, 29, 35, 30, 31, 33, 30, 32, 34, 31, 32, 35, 33, 34, 35};
    Scalar result_empty_value_ptr[245];
    Eigen::SparseMatrix<Scalar> result = Eigen::Map<const Eigen::SparseMatrix<Scalar>>(
        kRows_result,
        kCols_result,
        kNumNonZero_result,
        kColPtrs_result,
        kRowIndices_result,
        result_empty_value_ptr
    );
    Scalar* result_value_ptr = result.valuePtr();


    result_value_ptr[0] = _tmp0 + x3;
    result_value_ptr[1] = -_tmp3 - 1;
    result_value_ptr[2] = -_tmp4;
    result_value_ptr[3] = _tmp5;
    result_value_ptr[4] = x3*(_tmp6 + 1);
    result_value_ptr[5] = -6;
    result_value_ptr[6] = -_tmp7 - x4;
    result_value_ptr[7] = 3*x1 + 3;
    result_value_ptr[8] = _tmp8;
    result_value_ptr[9] = _tmp9 + 1;
    result_value_ptr[10] = x3;
    result_value_ptr[11] = _tmp10*x1;
    result_value_ptr[12] = 2;
    result_value_ptr[13] = -Scalar(1.0)*x3;
    result_value_ptr[14] = x4;
    result_value_ptr[15] = x2 - 1;
    result_value_ptr[16] = _tmp11;
    result_value_ptr[17] = -8*_tmp12;
    result_value_ptr[18] = _tmp13;
    result_value_ptr[19] = -_tmp14*(_tmp15 + 2);
    result_value_ptr[20] = _tmp16 + x1;
    result_value_ptr[21] = _tmp17;
    result_value_ptr[22] = -_tmp18 + _tmp7 - 8;
    result_value_ptr[23] = -_tmp20 - 2*std::pow(x3, Scalar(2)) - 1;
    result_value_ptr[24] = _tmp13 + _tmp7;
    result_value_ptr[25] = -_tmp21 - _tmp9;
    result_value_ptr[26] = x2*(_tmp1*_tmp12 + x0);
    result_value_ptr[27] = _tmp22 - 8;
    result_value_ptr[28] = 3 - _tmp17;
    result_value_ptr[29] = -_tmp23 - _tmp24;
    result_value_ptr[30] = _tmp25;
    result_value_ptr[31] = -_tmp26;
    result_value_ptr[32] = _tmp27 + x3;
    result_value_ptr[33] = _tmp28 - _tmp29;
    result_value_ptr[34] = _tmp3;
    result_value_ptr[35] = -_tmp31 - _tmp32;
    result_value_ptr[36] = _tmp30 - 4;
    result_value_ptr[37] = 1;
    result_value_ptr[38] = x3/_tmp33;
    result_value_ptr[39] = -_tmp34 + _tmp35;
    result_value_ptr[40] = -_tmp36 - _tmp37*x2 - _tmp38;
    result_value_ptr[41] = _tmp15 - _tmp6;
    result_value_ptr[42] = x2;
    result_value_ptr[43] = -_tmp21 - _tmp39;
    result_value_ptr[44] = _tmp5;
    result_value_ptr[45] = _tmp23;
    result_value_ptr[46] = x2/(_tmp21 + _tmp40 + _tmp41 + x4);
    result_value_ptr[47] = x1*(_tmp26 + _tmp36);
    result_value_ptr[48] = -_tmp42 - 3;
    result_value_ptr[49] = _tmp35*x3 - x0;
    result_value_ptr[50] = -x4/(_tmp38 + _tmp43);
    result_value_ptr[51] = Scalar(2.0);
    result_value_ptr[52] = -_tmp44 - x1;
    result_value_ptr[53] = _tmp21;
    result_value_ptr[54] = _tmp33*x2;
    result_value_ptr[55] = -1;
    result_value_ptr[56] = _tmp45;
    result_value_ptr[57] = x0 + 4;
    result_value_ptr[58] = -_tmp21 - _tmp46;
    result_value_ptr[59] = (Scalar(1)/Scalar(2))*_tmp15;
    result_value_ptr[60] = x3*(_tmp19 + x2);
    result_value_ptr[61] = Scalar(4.0)*x1;
    result_value_ptr[62] = -_tmp15*_tmp18;
    result_value_ptr[63] = _tmp43;
    result_value_ptr[64] = 2*_tmp2*(x1 + Scalar(1.0));
    result_value_ptr[65] = _tmp46;
    result_value_ptr[66] = -_tmp13*x2 + 2*_tmp47;
    result_value_ptr[67] = -_tmp48*(_tmp11 + 1);
    result_value_ptr[68] = -_tmp20 - _tmp27;
    result_value_ptr[69] = -x0 - 5;
    result_value_ptr[70] = _tmp10*_tmp28;
    result_value_ptr[71] = _tmp49 + x0 - 5;
    result_value_ptr[72] = _tmp50*x4 + x4;
    result_value_ptr[73] = -_tmp49 - _tmp51;
    result_value_ptr[74] = (Scalar(1)/Scalar(2))*x0 + (Scalar(3)/Scalar(2))*x4;
    result_value_ptr[75] = -_tmp30*_tmp52;
    result_value_ptr[76] = _tmp16 + _tmp32;
    result_value_ptr[77] = _tmp23 + _tmp53*x1;
    result_value_ptr[78] = -_tmp47 - x4;
    result_value_ptr[79] = -_tmp24;
    result_value_ptr[80] = _tmp27*_tmp55;
    result_value_ptr[81] = -_tmp27 - _tmp56*x2;
    result_value_ptr[82] = -_tmp52*(x1 - 4);
    result_value_ptr[83] = -_tmp35 - _tmp7;
    result_value_ptr[84] = -_tmp57*x0;
    result_value_ptr[85] = -_tmp43 - _tmp58*x4;
    result_value_ptr[86] = _tmp59;
    result_value_ptr[87] = -_tmp30 - _tmp7 - 4;
    result_value_ptr[88] = -x3*(_tmp7 + x2) - x3;
    result_value_ptr[89] = _tmp19;
    result_value_ptr[90] = -_tmp45 - x0;
    result_value_ptr[91] = -_tmp60;
    result_value_ptr[92] = x0 - 4;
    result_value_ptr[93] = 2;
    result_value_ptr[94] = _tmp60;
    result_value_ptr[95] = 4*x2;
    result_value_ptr[96] = -_tmp61 + Scalar(-1.0);
    result_value_ptr[97] = _tmp36 + _tmp62*x3;
    result_value_ptr[98] = -_tmp57 - x4;
    result_value_ptr[99] = -4*_tmp15;
    result_value_ptr[100] = -_tmp39*_tmp47*x4;
    result_value_ptr[101] = _tmp29;
    result_value_ptr[102] = -_tmp63 - _tmp64;
    result_value_ptr[103] = _tmp31;
    result_value_ptr[104] = _tmp4*x0 + _tmp45;
    result_value_ptr[105] = _tmp22 + 2;
    result_value_ptr[106] = _tmp49;
    result_value_ptr[107] = -_tmp9*x0 - x0;
    result_value_ptr[108] = _tmp0 + _tmp36;
    result_value_ptr[109] = -_tmp6 - 3;
    result_value_ptr[110] = _tmp65*x1;
    result_value_ptr[111] = _tmp27*x4/_tmp42;
    result_value_ptr[112] = _tmp13*_tmp66;
    result_value_ptr[113] = _tmp19 - 4;
    result_value_ptr[114] = -5;
    result_value_ptr[115] = -x0*std::pow(x4, Scalar(2)) - 2;
    result_value_ptr[116] = _tmp42*x3 - 1;
    result_value_ptr[117] = _tmp30;
    result_value_ptr[118] = -_tmp56;
    result_value_ptr[119] = _tmp11 + 2;
    result_value_ptr[120] = _tmp4*(_tmp23 + x2);
    result_value_ptr[121] = -_tmp11*_tmp62;
    result_value_ptr[122] = -_tmp62*_tmp67*x1;
    result_value_ptr[123] = -_tmp4 - _tmp52*x1;
    result_value_ptr[124] = -_tmp49 - 4;
    result_value_ptr[125] = -_tmp23 - x3*(_tmp11 + x1);
    result_value_ptr[126] = _tmp30 + x3;
    result_value_ptr[127] = _tmp29*_tmp66*x3;
    result_value_ptr[128] = _tmp68;
    result_value_ptr[129] = _tmp34;
    result_value_ptr[130] = x3*(_tmp13 + _tmp17);
    result_value_ptr[131] = -_tmp50;
    result_value_ptr[132] = x1*(_tmp61 + x4);
    result_value_ptr[133] = -_tmp29;
    result_value_ptr[134] = -_tmp4 - x4;
    result_value_ptr[135] = -_tmp35*_tmp54;
    result_value_ptr[136] = -_tmp51*x3;
    result_value_ptr[137] = x0*(_tmp39 + 1);
    result_value_ptr[138] = -_tmp13*x0 - x0;
    result_value_ptr[139] = -2;
    result_value_ptr[140] = -_tmp36 - _tmp54*x0;
    result_value_ptr[141] = _tmp47*x3 + Scalar(-2.0);
    result_value_ptr[142] = x4*(_tmp23 + x1) - 2;
    result_value_ptr[143] = _tmp6*x4 + 2;
    result_value_ptr[144] = _tmp51;
    result_value_ptr[145] = _tmp17 + _tmp67;
    result_value_ptr[146] = _tmp48*x3;
    result_value_ptr[147] = -x1 + Scalar(1.0) / (_tmp41 + 1);
    result_value_ptr[148] = -_tmp40 - x1 - x2;
    result_value_ptr[149] = -4*_tmp69;
    result_value_ptr[150] = _tmp15*x4 - 2;
    result_value_ptr[151] = -_tmp30 - _tmp70;
    result_value_ptr[152] = -_tmp55;
    result_value_ptr[153] = _tmp71;
    result_value_ptr[154] = _tmp33;
    result_value_ptr[155] = -_tmp1*(x1 + 2) - _tmp24;
    result_value_ptr[156] = -_tmp56 - _tmp64;
    result_value_ptr[157] = _tmp15 + _tmp23;
    result_value_ptr[158] = -1;
    result_value_ptr[159] = -_tmp35;
    result_value_ptr[160] = _tmp59 + 2;
    result_value_ptr[161] = -_tmp21 - _tmp23 - _tmp27;
    result_value_ptr[162] = x0*(4*_tmp11 + 4);
    result_value_ptr[163] = -_tmp36 - _tmp67*x3;
    result_value_ptr[164] = _tmp16 + _tmp30 + _tmp63;
    result_value_ptr[165] = _tmp52*_tmp8;
    result_value_ptr[166] = _tmp51*x0;
    result_value_ptr[167] = _tmp10 + (Scalar(1)/Scalar(2))*_tmp8;
    result_value_ptr[168] = _tmp48/(_tmp21 + x1);
    result_value_ptr[169] = -_tmp72 - x0;
    result_value_ptr[170] = _tmp52;
    result_value_ptr[171] = -Scalar(1)/Scalar(4)*x2;
    result_value_ptr[172] = _tmp68;
    result_value_ptr[173] = Scalar(-1.0);
    result_value_ptr[174] = x4 - 4;
    result_value_ptr[175] = -x3*(_tmp49 + _tmp7);
    result_value_ptr[176] = _tmp0*_tmp13;
    result_value_ptr[177] = _tmp43 + x2;
    result_value_ptr[178] = -_tmp37 - Scalar(1)/Scalar(2)*x3;
    result_value_ptr[179] = -_tmp7*x4;
    result_value_ptr[180] = -2*_tmp6 - 4;
    result_value_ptr[181] = -x2*(_tmp7 - 4);
    result_value_ptr[182] = -_tmp4*_tmp48*x4;
    result_value_ptr[183] = -_tmp12 - _tmp33;
    result_value_ptr[184] = -_tmp12*_tmp73 - _tmp23;
    result_value_ptr[185] = 2 - _tmp28;
    result_value_ptr[186] = _tmp48;
    result_value_ptr[187] = -_tmp1*(_tmp7 + 2);
    result_value_ptr[188] = _tmp30 - 1;
    result_value_ptr[189] = _tmp40;
    result_value_ptr[190] = -_tmp44;
    result_value_ptr[191] = -_tmp30*_tmp69;
    result_value_ptr[192] = -x3/(_tmp6 - 2);
    result_value_ptr[193] = -x4*(_tmp36 + _tmp65);
    result_value_ptr[194] = x4;
    result_value_ptr[195] = _tmp35*x0;
    result_value_ptr[196] = x0*(_tmp49 + 2);
    result_value_ptr[197] = _tmp48 + x4*(_tmp70 + x1);
    result_value_ptr[198] = 2;
    result_value_ptr[199] = 1 - _tmp7;
    result_value_ptr[200] = 3*_tmp14*_tmp54;
    result_value_ptr[201] = _tmp24 + _tmp36;
    result_value_ptr[202] = -_tmp37*x3 - x3;
    result_value_ptr[203] = _tmp21;
    result_value_ptr[204] = x4 + Scalar(-0.5);
    result_value_ptr[205] = -_tmp74;
    result_value_ptr[206] = 3;
    result_value_ptr[207] = _tmp41 + x1;
    result_value_ptr[208] = _tmp42*_tmp75 + 1;
    result_value_ptr[209] = _tmp19 + 2;
    result_value_ptr[210] = -2*(_tmp51 + x4)*(x0 + x1);
    result_value_ptr[211] = 4*x0*(_tmp53 + x3);
    result_value_ptr[212] = _tmp16;
    result_value_ptr[213] = -4;
    result_value_ptr[214] = _tmp40;
    result_value_ptr[215] = -_tmp45 - _tmp60*x1;
    result_value_ptr[216] = 2 - std::pow(_tmp73, Scalar(2));
    result_value_ptr[217] = _tmp75;
    result_value_ptr[218] = x1;
    result_value_ptr[219] = -x0 - 3;
    result_value_ptr[220] = _tmp44;
    result_value_ptr[221] = -_tmp40 - _tmp69 - 1;
    result_value_ptr[222] = _tmp45 + x4 + 1;
    result_value_ptr[223] = _tmp17*_tmp35 + _tmp25;
    result_value_ptr[224] = -x0*(_tmp56 + x2);
    result_value_ptr[225] = -x4*(x2 + 2/_tmp76);
    result_value_ptr[226] = _tmp61 + 4;
    result_value_ptr[227] = _tmp24 + _tmp74;
    result_value_ptr[228] = _tmp16;
    result_value_ptr[229] = -_tmp12 + _tmp35;
    result_value_ptr[230] = _tmp13 + x3 + 6;
    result_value_ptr[231] = -Scalar(1)/Scalar(4)*_tmp14;
    result_value_ptr[232] = _tmp23 + _tmp63;
    result_value_ptr[233] = -_tmp20 - _tmp30;
    result_value_ptr[234] = -_tmp4*x2;
    result_value_ptr[235] = -_tmp69*(_tmp12 + x2) + 2;
    result_value_ptr[236] = _tmp19*_tmp42;
    result_value_ptr[237] = -_tmp58;
    result_value_ptr[238] = _tmp71;
    result_value_ptr[239] = -1;
    result_value_ptr[240] = _tmp36 + _tmp7;
    result_value_ptr[241] = _tmp65 + _tmp72;
    result_value_ptr[242] = _tmp10*x2;
    result_value_ptr[243] = _tmp28 - 1;
    result_value_ptr[244] = -_tmp14*_tmp76;

    return result;
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
