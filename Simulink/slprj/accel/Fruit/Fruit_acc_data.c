/*
 * Fruit_acc_data.c
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

#include "Fruit_acc.h"
#include "Fruit_acc_private.h"

/* Block parameters (auto storage) */
Parameters rtDefaultParameters = {
  1.0,                                 /* Expression: openAtMdlStart
                                        * Referenced by: '<Root>/Image Display'
                                        */
  1.0,                                 /* Expression: inputColorFormat
                                        * Referenced by: '<Root>/Image Display'
                                        */
  1.0,                                 /* Expression: openAtMdlStart
                                        * Referenced by: '<Root>/Image Display1'
                                        */
  1.0,                                 /* Expression: inputColorFormat
                                        * Referenced by: '<Root>/Image Display1'
                                        */

  /*  Computed Parameter: P_4
   * Referenced by: '<Root>/NID IMAQ'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */

  /*  Computed Parameter: P_6
   * Referenced by: '<Root>/NID IMAQ'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: res_fps
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */

  /*  Computed Parameter: P_8
   * Referenced by: '<Root>/NID IMAQ'
   */
  { 1.0, 1.0 },
  0.033333333333333333,                /* Expression: imaq_sample_time
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */

  /*  Computed Parameter: P_10
   * Referenced by: '<Root>/NID IMAQ'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: imaq_depth
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */

  /*  Computed Parameter: P_12
   * Referenced by: '<Root>/NID IMAQ'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: imaq_motion
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */

  /*  Computed Parameter: P_14
   * Referenced by: '<Root>/NID IMAQ'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: imaq_image
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */

  /*  Computed Parameter: P_16
   * Referenced by: '<Root>/NID IMAQ'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: imaq_skeleton
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */

  /*  Computed Parameter: P_18
   * Referenced by: '<Root>/NID IMAQ'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: imaq_ir
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */

  /*  Computed Parameter: P_20
   * Referenced by: '<Root>/NID IMAQ'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */

  /*  Computed Parameter: P_22
   * Referenced by: '<Root>/NID IMAQ'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */

  /*  Computed Parameter: P_24
   * Referenced by: '<Root>/NID IMAQ'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */

  /*  Computed Parameter: P_26
   * Referenced by: '<Root>/NID IMAQ'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: view_point
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */

  /*  Computed Parameter: P_28
   * Referenced by: '<Root>/NID IMAQ'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: mirror_image
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */

  /*  Computed Parameter: P_30
   * Referenced by: '<Root>/NID IMAQ'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */

  /*  Computed Parameter: P_32
   * Referenced by: '<Root>/NID IMAQ'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */

  /*  Computed Parameter: P_34
   * Referenced by: '<Root>/NID IMAQ'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: angle
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */

  /*  Computed Parameter: P_36
   * Referenced by: '<Root>/NID IMAQ'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: near_mode
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */

  /*  Computed Parameter: P_38
   * Referenced by: '<Root>/NID Skeleton'
   */
  { 1.0, 1.0 },
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */

  /*  Computed Parameter: P_40
   * Referenced by: '<Root>/NID Skeleton'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */

  /*  Computed Parameter: P_42
   * Referenced by: '<Root>/NID Skeleton'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */

  /*  Computed Parameter: P_44
   * Referenced by: '<Root>/NID Skeleton'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */

  /*  Computed Parameter: P_46
   * Referenced by: '<Root>/NID Skeleton'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */

  /*  Computed Parameter: P_48
   * Referenced by: '<Root>/NID Skeleton'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */

  /*  Computed Parameter: P_50
   * Referenced by: '<Root>/NID Skeleton'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */

  /*  Computed Parameter: P_52
   * Referenced by: '<Root>/NID Skeleton'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */

  /*  Computed Parameter: P_54
   * Referenced by: '<Root>/NID Skeleton'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */

  /*  Computed Parameter: P_56
   * Referenced by: '<Root>/NID Skeleton'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */

  /*  Computed Parameter: P_58
   * Referenced by: '<Root>/NID Skeleton'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: viewer
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */

  /*  Computed Parameter: P_60
   * Referenced by: '<Root>/NID Skeleton'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */

  /*  Computed Parameter: P_62
   * Referenced by: '<Root>/NID Skeleton'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */

  /*  Computed Parameter: P_64
   * Referenced by: '<Root>/NID Skeleton'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: conv_XYZ_RW
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */

  /*  Computed Parameter: P_66
   * Referenced by: '<Root>/NID Skeleton'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: needPsiPose
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */

  /*  Computed Parameter: P_68
   * Referenced by: '<Root>/NID Skeleton'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */

  /*  Computed Parameter: P_70
   * Referenced by: '<Root>/NID Skeleton'
   */
  { 1.0, 1.0 },
  0.0                                  /* Expression: 0
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */
};
