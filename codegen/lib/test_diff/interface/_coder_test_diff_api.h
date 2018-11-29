/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_test_diff_api.h
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 15-Jan-2018 19:08:03
 */

#ifndef _CODER_TEST_DIFF_API_H
#define _CODER_TEST_DIFF_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_test_diff_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void test_diff(uint8_T I[921600], real_T dt0_v[76800]);
extern void test_diff_api(const mxArray * const prhs[1], const mxArray *plhs[1]);
extern void test_diff_atexit(void);
extern void test_diff_initialize(void);
extern void test_diff_terminate(void);
extern void test_diff_xil_terminate(void);

#endif

/*
 * File trailer for _coder_test_diff_api.h
 *
 * [EOF]
 */
