//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: test_diff_rtwutil.cpp
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 15-Jan-2018 19:08:03
//

// Include Files
#include "rt_nonfinite.h"
#include "test_diff.h"
#include "test_diff_rtwutil.h"

// Variable Definitions
static test_diffTLS *test_diffTLSGlobal;

#pragma omp threadprivate (test_diffTLSGlobal)

// Function Definitions

//
// Arguments    : void
// Return Type  : void
//
void emlrtFreeThreadStackData()
{
  int i;

#pragma omp parallel for schedule(static)\
 num_threads(omp_get_max_threads())

  for (i = 1; i <= omp_get_max_threads(); i++) {
    free(test_diffTLSGlobal);
  }
}

//
// Arguments    : void
// Return Type  : test_diffTLS *
//
test_diffTLS *emlrtGetThreadStackData()
{
  return test_diffTLSGlobal;
}

//
// Arguments    : void
// Return Type  : void
//
void emlrtInitThreadStackData()
{
  int i;

#pragma omp parallel for schedule(static)\
 num_threads(omp_get_max_threads())

  for (i = 1; i <= omp_get_max_threads(); i++) {
    test_diffTLSGlobal = (test_diffTLS *)malloc(1U * sizeof(test_diffTLS));
  }
}

//
// File trailer for test_diff_rtwutil.cpp
//
// [EOF]
//
