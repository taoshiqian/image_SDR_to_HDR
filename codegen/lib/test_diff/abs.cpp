//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: abs.cpp
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 15-Jan-2018 19:08:03
//

// Include Files
#include "rt_nonfinite.h"
#include "test_diff.h"
#include "abs.h"

// Function Definitions

//
// Arguments    : const double x[3200]
//                double y[3200]
// Return Type  : void
//
void b_abs(const double x[3200], double y[3200])
{
  int k;
  for (k = 0; k < 3200; k++) {
    y[k] = std::abs(x[k]);
  }
}

//
// Arguments    : const double x[2400]
//                double y[2400]
// Return Type  : void
//
void c_abs(const double x[2400], double y[2400])
{
  int k;
  for (k = 0; k < 2400; k++) {
    y[k] = std::abs(x[k]);
  }
}

//
// File trailer for abs.cpp
//
// [EOF]
//
