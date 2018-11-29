//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: power.h
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 15-Jan-2018 19:08:03
//
#ifndef POWER_H
#define POWER_H

// Include Files
#include <cmath>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "omp.h"
#include "test_diff_types.h"

// Function Declarations
extern void b_power(const double a[3200], double y[3200]);
extern void c_power(const double a[2400], double y[2400]);
extern void d_power(const double a[2400], double y[2400]);
extern void power(const double a[3200], double y[3200]);

#endif

//
// File trailer for power.h
//
// [EOF]
//
