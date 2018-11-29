//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: imresize.h
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 15-Jan-2018 19:08:03
//
#ifndef IMRESIZE_H
#define IMRESIZE_H

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
extern void b_contributions(emxArray_real_T *weights, emxArray_int32_T *indices);
extern void contributions(emxArray_real_T *weights, emxArray_int32_T *indices);

#endif

//
// File trailer for imresize.h
//
// [EOF]
//
