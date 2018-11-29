//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: diff.cpp
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 15-Jan-2018 19:08:03
//

// Include Files
#include "rt_nonfinite.h"
#include "test_diff.h"
#include "diff.h"

// Function Definitions

//
// Arguments    : const double x[76800]
//                double y[76560]
// Return Type  : void
//
void diff(const double x[76800], double y[76560])
{
  int ixStart;
  int iyStart;
  int r;
  int ixLead;
  int iyLead;
  double work;
  int m;
  double tmp1;
  ixStart = 1;
  iyStart = 0;
  for (r = 0; r < 240; r++) {
    ixLead = ixStart;
    iyLead = iyStart;
    work = x[ixStart - 1];
    for (m = 0; m < 319; m++) {
      tmp1 = work;
      work = x[ixLead];
      tmp1 = x[ixLead] - tmp1;
      ixLead++;
      y[iyLead] = tmp1;
      iyLead++;
    }

    ixStart += 320;
    iyStart += 319;
  }
}

//
// File trailer for diff.cpp
//
// [EOF]
//
