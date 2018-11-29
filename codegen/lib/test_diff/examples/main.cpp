//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: main.cpp
//
// MATLAB Coder version            : 3.3
// C/C++ source code generated on  : 15-Jan-2018 19:08:03
//

//***********************************************************************
// This automatically generated example C main file shows how to call
// entry-point functions that MATLAB Coder generated. You must customize
// this file for your application. Do not modify this file directly.
// Instead, make a copy of this file, modify it, and integrate it into
// your development environment.
//
// This file initializes entry-point function arguments to a default
// size and value before calling the entry-point functions. It does
// not store or use any values returned from the entry-point functions.
// If necessary, it does pre-allocate memory for returned values.
// You can use this file as a starting point for a main function that
// you can deploy in your application.
//
// After you copy the file, and before you deploy it, you must make the
// following changes:
// * For variable-size function arguments, change the example sizes to
// the sizes that your application requires.
// * Change the example values of function arguments to the values that
// your application requires.
// * If the entry-point functions return values, store these values or
// otherwise use them as required by your application.
//
//***********************************************************************
// Include Files
#include "rt_nonfinite.h"
#include "test_diff.h"
#include "main.h"
#include "test_diff_terminate.h"
#include "test_diff_initialize.h"

// Function Declarations
static void argInit_640x480x3_uint8_T(unsigned char result[921600]);
static unsigned char argInit_uint8_T();
static void main_test_diff();

// Function Definitions

//
// Arguments    : unsigned char result[921600]
// Return Type  : void
//
static void argInit_640x480x3_uint8_T(unsigned char result[921600])
{
  int idx0;
  int idx1;
  int idx2;

  // Loop over the array to initialize each element.
  for (idx0 = 0; idx0 < 640; idx0++) {
    for (idx1 = 0; idx1 < 480; idx1++) {
      for (idx2 = 0; idx2 < 3; idx2++) {
        // Set the value of the array element.
        // Change this value to the value that the application requires.
        result[(idx0 + 640 * idx1) + 307200 * idx2] = argInit_uint8_T();
      }
    }
  }
}

//
// Arguments    : void
// Return Type  : unsigned char
//
static unsigned char argInit_uint8_T()
{
  return 0;
}

//
// Arguments    : void
// Return Type  : void
//
static void main_test_diff()
{
  static unsigned char uv0[921600];
  static double dt0_v[76800];

  // Initialize function 'test_diff' input arguments.
  // Initialize function input argument 'I'.
  // Call the entry-point 'test_diff'.
  argInit_640x480x3_uint8_T(uv0);
  test_diff(uv0, dt0_v);
}

//
// Arguments    : int argc
//                const char * const argv[]
// Return Type  : int
//
int main(int, const char * const [])
{
  // Initialize the application.
  // You do not need to do this more than one time.
  test_diff_initialize();

  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  main_test_diff();

  // Terminate the application.
  // You do not need to do this more than one time.
  test_diff_terminate();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
