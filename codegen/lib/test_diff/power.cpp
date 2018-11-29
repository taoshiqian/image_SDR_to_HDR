//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: power.cpp
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 15-Jan-2018 19:08:03
//

// Include Files
#include "rt_nonfinite.h"
#include "test_diff.h"
#include "power.h"

// Function Declarations
static double rt_powd_snf(double u0, double u1);

// Function Definitions

//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
static double rt_powd_snf(double u0, double u1)
{
  double y;
  double d0;
  double d1;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else {
    d0 = std::abs(u0);
    d1 = std::abs(u1);
    if (rtIsInf(u1)) {
      if (d0 == 1.0) {
        y = 1.0;
      } else if (d0 > 1.0) {
        if (u1 > 0.0) {
          y = rtInf;
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = rtInf;
      }
    } else if (d1 == 0.0) {
      y = 1.0;
    } else if (d1 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = std::sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > std::floor(u1))) {
      y = rtNaN;
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

//
// Arguments    : const double a[3200]
//                double y[3200]
// Return Type  : void
//
void b_power(const double a[3200], double y[3200])
{
  int k;
  for (k = 0; k < 3200; k++) {
    y[k] = rt_powd_snf(a[k], 3.0);
  }
}

//
// Arguments    : const double a[2400]
//                double y[2400]
// Return Type  : void
//
void c_power(const double a[2400], double y[2400])
{
  int k;
  for (k = 0; k < 2400; k++) {
    y[k] = a[k] * a[k];
  }
}

//
// Arguments    : const double a[2400]
//                double y[2400]
// Return Type  : void
//
void d_power(const double a[2400], double y[2400])
{
  int k;
  for (k = 0; k < 2400; k++) {
    y[k] = rt_powd_snf(a[k], 3.0);
  }
}

//
// Arguments    : const double a[3200]
//                double y[3200]
// Return Type  : void
//
void power(const double a[3200], double y[3200])
{
  int k;
  for (k = 0; k < 3200; k++) {
    y[k] = a[k] * a[k];
  }
}

//
// File trailer for power.cpp
//
// [EOF]
//
