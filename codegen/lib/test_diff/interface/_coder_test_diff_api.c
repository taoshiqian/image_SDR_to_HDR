/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_test_diff_api.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 15-Jan-2018 19:08:03
 */

/* Include Files */
#include "tmwtypes.h"
#include "_coder_test_diff_api.h"
#include "_coder_test_diff_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131450U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "test_diff",                         /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static uint8_T (*b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId))[921600];
static uint8_T (*c_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId))[921600];
static uint8_T (*emlrt_marshallIn(const mxArray *I, const char_T *identifier))
  [921600];
static const mxArray *emlrt_marshallOut(const real_T u[76800]);

/* Function Definitions */

/*
 * Arguments    : const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : uint8_T (*)[921600]
 */
static uint8_T (*b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId))[921600]
{
  uint8_T (*y)[921600];
  y = c_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
/*
 * Arguments    : const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : uint8_T (*)[921600]
 */
  static uint8_T (*c_emlrt_marshallIn(const mxArray *src, const
  emlrtMsgIdentifier *msgId))[921600]
{
  uint8_T (*ret)[921600];
  static const int32_T dims[3] = { 640, 480, 3 };

  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "uint8", false, 3U,
    dims);
  ret = (uint8_T (*)[921600])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const mxArray *I
 *                const char_T *identifier
 * Return Type  : uint8_T (*)[921600]
 */
static uint8_T (*emlrt_marshallIn(const mxArray *I, const char_T *identifier))
  [921600]
{
  uint8_T (*y)[921600];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(emlrtAlias(I), &thisId);
  emlrtDestroyArray(&I);
  return y;
}
/*
 * Arguments    : const real_T u[76800]
 * Return Type  : const mxArray *
 */
  static const mxArray *emlrt_marshallOut(const real_T u[76800])
{
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv0[2] = { 0, 0 };

  static const int32_T iv1[2] = { 320, 240 };

  y = NULL;
  m0 = emlrtCreateNumericArray(2, iv0, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m0, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m0, *(int32_T (*)[2])&iv1[0], 2);
  emlrtAssign(&y, m0);
  return y;
}

/*
 * Arguments    : const mxArray * const prhs[1]
 *                const mxArray *plhs[1]
 * Return Type  : void
 */
void test_diff_api(const mxArray * const prhs[1], const mxArray *plhs[1])
{
  real_T (*dt0_v)[76800];
  uint8_T (*I)[921600];
  dt0_v = (real_T (*)[76800])mxMalloc(sizeof(real_T [76800]));

  /* Marshall function inputs */
  I = emlrt_marshallIn(emlrtAlias((const mxArray *)prhs[0]), "I");

  /* Invoke the target function */
  test_diff(*I, *dt0_v);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*dt0_v);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void test_diff_atexit(void)
{
  mexFunctionCreateRootTLS();
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  test_diff_xil_terminate();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void test_diff_initialize(void)
{
  mexFunctionCreateRootTLS();
  emlrtClearAllocCountR2012b(emlrtRootTLSGlobal, false, 0U, 0);
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void test_diff_terminate(void)
{
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_test_diff_api.c
 *
 * [EOF]
 */
