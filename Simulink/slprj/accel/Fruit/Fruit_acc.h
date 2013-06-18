/*
 * Fruit_acc.h
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
#ifndef RTW_HEADER_Fruit_acc_h_
#define RTW_HEADER_Fruit_acc_h_
#ifndef Fruit_acc_COMMON_INCLUDES_
# define Fruit_acc_COMMON_INCLUDES_
#include <stdlib.h>
#include <stddef.h>
#define S_FUNCTION_NAME                simulink_only_sfcn
#define S_FUNCTION_LEVEL               2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "HostLib_Video.h"
#include "HostLib_Multimedia.h"
#include "rt_nonfinite.h"
#endif                                 /* Fruit_acc_COMMON_INCLUDES_ */

#include "Fruit_acc_types.h"

/* Block signals (auto storage) */
typedef struct {
  real_T B_1_3_1[45];                  /* '<Root>/NID Skeleton' */
  uint32_T B_1_2_0;                    /* '<Root>/NID IMAQ' */
  uint8_T B_1_3_2[921600];             /* '<Root>/NID Skeleton' */
  boolean_T B_1_3_0;                   /* '<Root>/NID Skeleton' */
  boolean_T B_0_0_1[307200];           /* '<Root>/MATLAB Function' */
  char pad_B_0_0_1[3];
} BlockIO;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T ImageDisplay_ToVideoDevice[137];/* '<Root>/Image Display' */
  real_T ImageDisplay_VideoInfo[10];   /* '<Root>/Image Display' */
  real_T ImageDisplay1_ToVideoDevice[137];/* '<Root>/Image Display1' */
  real_T ImageDisplay1_VideoInfo[10];  /* '<Root>/Image Display1' */
  uint8_T ImageDisplay_ID_Dwork[1025]; /* '<Root>/Image Display' */
  uint8_T ImageDisplay1_ID_Dwork[1025];/* '<Root>/Image Display1' */
  char pad_ImageDisplay1_ID_Dwork[6];
} D_Work;

/* Parameters (auto storage) */
struct Parameters_ {
  real_T P_0;                          /* Expression: openAtMdlStart
                                        * Referenced by: '<Root>/Image Display'
                                        */
  real_T P_1;                          /* Expression: inputColorFormat
                                        * Referenced by: '<Root>/Image Display'
                                        */
  real_T P_2;                          /* Expression: openAtMdlStart
                                        * Referenced by: '<Root>/Image Display1'
                                        */
  real_T P_3;                          /* Expression: inputColorFormat
                                        * Referenced by: '<Root>/Image Display1'
                                        */
  real_T P_4[2];                       /* Computed Parameter: P_4
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */
  real_T P_5;                          /* Expression: 1
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */
  real_T P_6[2];                       /* Computed Parameter: P_6
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */
  real_T P_7;                          /* Expression: res_fps
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */
  real_T P_8[2];                       /* Computed Parameter: P_8
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */
  real_T P_9;                          /* Expression: imaq_sample_time
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */
  real_T P_10[2];                      /* Computed Parameter: P_10
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */
  real_T P_11;                         /* Expression: imaq_depth
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */
  real_T P_12[2];                      /* Computed Parameter: P_12
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */
  real_T P_13;                         /* Expression: imaq_motion
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */
  real_T P_14[2];                      /* Computed Parameter: P_14
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */
  real_T P_15;                         /* Expression: imaq_image
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */
  real_T P_16[2];                      /* Computed Parameter: P_16
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */
  real_T P_17;                         /* Expression: imaq_skeleton
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */
  real_T P_18[2];                      /* Computed Parameter: P_18
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */
  real_T P_19;                         /* Expression: imaq_ir
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */
  real_T P_20[2];                      /* Computed Parameter: P_20
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */
  real_T P_21;                         /* Expression: 0
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */
  real_T P_22[2];                      /* Computed Parameter: P_22
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */
  real_T P_23;                         /* Expression: 0
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */
  real_T P_24[2];                      /* Computed Parameter: P_24
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */
  real_T P_25;                         /* Expression: 0
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */
  real_T P_26[2];                      /* Computed Parameter: P_26
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */
  real_T P_27;                         /* Expression: view_point
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */
  real_T P_28[2];                      /* Computed Parameter: P_28
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */
  real_T P_29;                         /* Expression: mirror_image
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */
  real_T P_30[2];                      /* Computed Parameter: P_30
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */
  real_T P_31;                         /* Expression: 0
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */
  real_T P_32[2];                      /* Computed Parameter: P_32
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */
  real_T P_33;                         /* Expression: 0
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */
  real_T P_34[2];                      /* Computed Parameter: P_34
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */
  real_T P_35;                         /* Expression: angle
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */
  real_T P_36[2];                      /* Computed Parameter: P_36
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */
  real_T P_37;                         /* Expression: near_mode
                                        * Referenced by: '<Root>/NID IMAQ'
                                        */
  real_T P_38[2];                      /* Computed Parameter: P_38
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */
  real_T P_39;                         /* Expression: 5
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */
  real_T P_40[2];                      /* Computed Parameter: P_40
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */
  real_T P_41;                         /* Expression: 0
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */
  real_T P_42[2];                      /* Computed Parameter: P_42
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */
  real_T P_43;                         /* Expression: -1
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */
  real_T P_44[2];                      /* Computed Parameter: P_44
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */
  real_T P_45;                         /* Expression: 0
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */
  real_T P_46[2];                      /* Computed Parameter: P_46
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */
  real_T P_47;                         /* Expression: 0
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */
  real_T P_48[2];                      /* Computed Parameter: P_48
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */
  real_T P_49;                         /* Expression: 0
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */
  real_T P_50[2];                      /* Computed Parameter: P_50
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */
  real_T P_51;                         /* Expression: 0
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */
  real_T P_52[2];                      /* Computed Parameter: P_52
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */
  real_T P_53;                         /* Expression: 0
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */
  real_T P_54[2];                      /* Computed Parameter: P_54
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */
  real_T P_55;                         /* Expression: 0
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */
  real_T P_56[2];                      /* Computed Parameter: P_56
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */
  real_T P_57;                         /* Expression: 0
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */
  real_T P_58[2];                      /* Computed Parameter: P_58
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */
  real_T P_59;                         /* Expression: viewer
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */
  real_T P_60[2];                      /* Computed Parameter: P_60
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */
  real_T P_61;                         /* Expression: 0
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */
  real_T P_62[2];                      /* Computed Parameter: P_62
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */
  real_T P_63;                         /* Expression: 0
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */
  real_T P_64[2];                      /* Computed Parameter: P_64
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */
  real_T P_65;                         /* Expression: conv_XYZ_RW
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */
  real_T P_66[2];                      /* Computed Parameter: P_66
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */
  real_T P_67;                         /* Expression: needPsiPose
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */
  real_T P_68[2];                      /* Computed Parameter: P_68
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */
  real_T P_69;                         /* Expression: 0
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */
  real_T P_70[2];                      /* Computed Parameter: P_70
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */
  real_T P_71;                         /* Expression: 0
                                        * Referenced by: '<Root>/NID Skeleton'
                                        */
};

extern Parameters rtDefaultParameters; /* parameters */

#endif                                 /* RTW_HEADER_Fruit_acc_h_ */
