/*
 * This file is not available for use in any application other than as a
 * MATLAB(R) MEX file for use with the Simulink(R) product.
 */

/*
 * Fruit_acc.c
 *
 * Code generation for model "Fruit_acc.mdl".
 *
 * Model version              : 1.9
 * Simulink Coder version : 8.0 (R2011a) 09-Mar-2011
 * C source code generated on : Sat Apr 28 14:29:22 2012
 *
 * Target selection: accel.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include <math.h>
#include "Fruit_acc.h"
#include "Fruit_acc_private.h"
#include <stdio.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat                     S-Function
#define AccDefine1                     Accelerator_S-Function

/* Outputs for root system: '<Root>' */
static void mdlOutputs(SimStruct *S, int_T tid)
{
  if (ssIsSampleHit(S, 1, 0)) {
    /* Level2 S-Function Block: '<Root>/B_1_0' (sfun_nid) */
    /* Call into Simulink for MEX-version of S-function */
    ssCallAccelRunBlock(S, 1, 2, SS_CALL_MDL_OUTPUTS);

    /* Level2 S-Function Block: '<Root>/B_1_1' (sfun_nid) */
    /* Call into Simulink for MEX-version of S-function */
    ssCallAccelRunBlock(S, 1, 3, SS_CALL_MDL_OUTPUTS);

    /* Level2 S-Function Block: '<S1>/B_0_0' (stateflow) */
    /* Call into Simulink for MEX-version of S-function */
    ssCallAccelRunBlock(S, 0, 0, SS_CALL_MDL_OUTPUTS);
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  char_T *sErr;
  if (ssIsSampleHit(S, 1, 0)) {
    sErr = GetErrorBuffer(((D_Work *) ssGetRootDWork(S))
                          ->ImageDisplay_ToVideoDevice);
    LibUpdate_Video(((D_Work *) ssGetRootDWork(S))->ImageDisplay_ToVideoDevice,
                    &((BlockIO *) _ssGetBlockIO(S))->B_0_0_1[0], GetNullPointer(),
                    GetNullPointer(), 640, 480);
    if (*sErr != 0) {
      ssSetErrorStatus(S, sErr);
      ssSetStopRequested(S, 1);
    }

    sErr = GetErrorBuffer(((D_Work *) ssGetRootDWork(S))
                          ->ImageDisplay1_ToVideoDevice);
    LibUpdate_Video(((D_Work *) ssGetRootDWork(S))->ImageDisplay1_ToVideoDevice,
                    &((BlockIO *) _ssGetBlockIO(S))->B_1_3_2[0], GetNullPointer(),
                    GetNullPointer(), 640, 480);
    if (*sErr != 0) {
      ssSetErrorStatus(S, sErr);
      ssSetStopRequested(S, 1);
    }
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Function to initialize sizes */
static void mdlInitializeSizes(SimStruct *S)
{
  /* checksum */
  ssSetChecksumVal(S, 0, 1252755944U);
  ssSetChecksumVal(S, 1, 3596219918U);
  ssSetChecksumVal(S, 2, 2888239280U);
  ssSetChecksumVal(S, 3, 2239816892U);

  /* options */
  ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);

  /* Accelerator check memory map size match for DWork */
  if (ssGetSizeofDWork(S) != sizeof(D_Work)) {
    ssSetErrorStatus(S,"Unexpected error: Internal DWork sizes do "
                     "not match for accelerator mex file.");
  }

  /* Accelerator check memory map size match for BlockIO */
  if (ssGetSizeofGlobalBlockIO(S) != sizeof(BlockIO)) {
    ssSetErrorStatus(S,"Unexpected error: Internal BlockIO sizes do "
                     "not match for accelerator mex file.");
  }

  /* model parameters */
  _ssSetDefaultParam(S, (real_T *) &rtDefaultParameters);

  /* non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/* mdlInitializeSampleTimes function (used to set up function-call connections) */
static void mdlInitializeSampleTimes(SimStruct *S)
{
  /* register function-calls */
  {
    SimStruct *childS;
    SysOutputFcn *callSysFcns;

    /* Level2 S-Function Block: '<S1>/B_0_0' (stateflow) */
    childS = ssGetSFunction(S, 0);
    callSysFcns = ssGetCallSystemOutputFcnList(childS);

    /* Unconnected function-call */
    callSysFcns[3 + 0] = (SysOutputFcn) (NULL);
  }
}

/* Empty mdlTerminate function (never called) */
static void mdlTerminate(SimStruct *S)
{
}

/* MATLAB MEX Glue */
#include "simulink.c"
