//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: test_diff_terminate.cpp
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 15-Jan-2018 19:08:03
//

// Include Files
#include "rt_nonfinite.h"
#include "test_diff.h"
#include "test_diff_terminate.h"
#include "test_diff_rtwutil.h"
#include "test_diff_data.h"

// Function Definitions

//
// Arguments    : void
// Return Type  : void
//
void test_diff_terminate()
{
  emlrtFreeThreadStackData();
  omp_destroy_nest_lock(&emlrtNestLockGlobal);
}

//
// File trailer for test_diff_terminate.cpp
//
// [EOF]
//
