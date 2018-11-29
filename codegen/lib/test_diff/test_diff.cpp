//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: test_diff.cpp
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 15-Jan-2018 19:08:03
//

// Include Files
#include "rt_nonfinite.h"
#include "test_diff.h"
#include "test_diff_rtwutil.h"
#include "diff.h"
#include "test_diff_emxutil.h"
#include "imresize.h"

// Function Declarations
static double rt_roundd_snf(double u);

// Function Definitions

//
// Arguments    : double u
// Return Type  : double
//
static double rt_roundd_snf(double u)
{
  double y;
  if (std::abs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = std::floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = std::ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

//
// camera a, b
// Arguments    : const unsigned char I[921600]
//                double dt0_v[76800]
// Return Type  : void
//
void test_diff(const unsigned char I[921600], double dt0_v[76800])
{
  int j;
  emxArray_real_T *weights;
  unsigned char mtmp;
  emxArray_int32_T *indices;
  int ix;
  static unsigned char t_b[307200];
  int inCInd;
  static unsigned char APartialResize[153600];
  emxArray_real_T *b_weights;
  emxArray_int32_T *b_indices;
  int linearInds;
  double sumVal1;
  int pixelIndex;
  unsigned char B[76800];
  int k;
  int outCInd;
  unsigned char u0;
  test_diffTLS *test_diffTLSThread;
  test_diffTLSThread = emlrtGetThreadStackData();
  for (j = 0; j < 307200; j++) {
    mtmp = I[j];
    for (ix = j + 307200; ix + 1 <= j + 614401; ix += 307200) {
      if (I[ix] > mtmp) {
        mtmp = I[ix];
      }
    }

    t_b[j] = mtmp;
  }

  emxInit_real_T(&weights, 2);
  emxInit_int32_T(&indices, 2);

  //  also work for single-channel image
  //  Resize first dimension
  contributions(weights, indices);

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(linearInds,sumVal1,pixelIndex,k,u0)

  for (inCInd = 0; inCInd < 480; inCInd++) {
    for (pixelIndex = 0; pixelIndex < 320; pixelIndex++) {
      sumVal1 = 0.0;
      linearInds = 1 + weights->size[0] * pixelIndex;

      //  Core - first dimension
      for (k = 0; k < weights->size[0]; k++) {
        sumVal1 += weights->data[linearInds - 1] * (double)t_b[(indices->
          data[linearInds - 1] + 640 * inCInd) - 1];
        linearInds++;
      }

      sumVal1 = rt_roundd_snf(sumVal1);
      if (sumVal1 < 256.0) {
        if (sumVal1 >= 0.0) {
          u0 = (unsigned char)sumVal1;
        } else {
          u0 = 0;
        }
      } else if (sumVal1 >= 256.0) {
        u0 = MAX_uint8_T;
      } else {
        u0 = 0;
      }

      APartialResize[pixelIndex + 320 * inCInd] = u0;
    }
  }

  emxFree_int32_T(&indices);
  emxFree_real_T(&weights);
  emxInit_real_T(&b_weights, 2);
  emxInit_int32_T(&b_indices, 2);

  //  Resize second dimension
  b_contributions(b_weights, b_indices);

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(pixelIndex,linearInds,sumVal1,outCInd,k,u0)

  for (inCInd = 0; inCInd < 320; inCInd++) {
    for (outCInd = 0; outCInd < 240; outCInd++) {
      sumVal1 = 0.0;

      //  Core - second dimension
      linearInds = 1 + b_weights->size[0] * outCInd;
      for (k = 0; k < b_weights->size[0]; k++) {
        pixelIndex = (inCInd + (b_indices->data[linearInds - 1] - 1) * 320) + 1;
        sumVal1 += b_weights->data[linearInds - 1] * (double)
          APartialResize[pixelIndex - 1];
        linearInds++;
      }

      sumVal1 = rt_roundd_snf(sumVal1);
      if (sumVal1 < 256.0) {
        if (sumVal1 >= 0.0) {
          u0 = (unsigned char)sumVal1;
        } else {
          u0 = 0;
        }
      } else if (sumVal1 >= 256.0) {
        u0 = MAX_uint8_T;
      } else {
        u0 = 0;
      }

      B[inCInd + 320 * outCInd] = u0;
    }
  }

  emxFree_int32_T(&b_indices);
  emxFree_real_T(&b_weights);
  for (j = 0; j < 76800; j++) {
    test_diffTLSThread->f0.fin[j] = (double)B[j] / 255.0;
  }

  diff(test_diffTLSThread->f0.fin, test_diffTLSThread->f0.dv0);
  for (j = 0; j < 240; j++) {
    memcpy(&dt0_v[j * 320], &test_diffTLSThread->f0.dv0[j * 319], 319U * sizeof
           (double));
    dt0_v[319 + 320 * j] = test_diffTLSThread->f0.fin[320 * j] -
      test_diffTLSThread->f0.fin[319 + 320 * j];
  }
}

//
// File trailer for test_diff.cpp
//
// [EOF]
//
