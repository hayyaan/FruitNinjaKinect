/* Include files */

#include "blascompat32.h"
#include "Fruit_sfun.h"
#include "c2_Fruit.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Fruit_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[11] = { "imageCoordinates", "p", "X",
  "Y", "nargin", "nargout", "tracking", "skeleton", "image1", "image2",
  "bothHands" };

static const char * c2_b_debug_family_names[4] = { "JointIndex", "JointName",
  "nargin", "nargout" };

static const char * c2_c_debug_family_names[6] = { "index", "JointName",
  "nargin", "nargout", "Joints", "Coordinates" };

static const char * c2_d_debug_family_names[4] = { "JointIndex", "JointName",
  "nargin", "nargout" };

static const char * c2_e_debug_family_names[6] = { "index", "JointName",
  "nargin", "nargout", "Joints", "Coordinates" };

/* Function Declarations */
static void initialize_c2_Fruit(SFc2_FruitInstanceStruct *chartInstance);
static void initialize_params_c2_Fruit(SFc2_FruitInstanceStruct *chartInstance);
static void enable_c2_Fruit(SFc2_FruitInstanceStruct *chartInstance);
static void disable_c2_Fruit(SFc2_FruitInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_Fruit(SFc2_FruitInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_Fruit(SFc2_FruitInstanceStruct
  *chartInstance);
static void set_sim_state_c2_Fruit(SFc2_FruitInstanceStruct *chartInstance,
  const mxArray *c2_st);
static void finalize_c2_Fruit(SFc2_FruitInstanceStruct *chartInstance);
static void sf_c2_Fruit(SFc2_FruitInstanceStruct *chartInstance);
static void c2_chartstep_c2_Fruit(SFc2_FruitInstanceStruct *chartInstance);
static void initSimStructsc2_Fruit(SFc2_FruitInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_FruitInstanceStruct *chartInstance, const
  mxArray *c2_bothHands, const char_T *c2_identifier, boolean_T c2_y[307200]);
static void c2_b_emlrt_marshallIn(SFc2_FruitInstanceStruct *chartInstance, const
  mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, boolean_T c2_y[307200]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_FruitInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_d_emlrt_marshallIn(SFc2_FruitInstanceStruct *chartInstance, const
  mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[307200]);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static c2_s7XUNvDD2qgIelqD6Zf8rpH c2_e_emlrt_marshallIn(SFc2_FruitInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_f_emlrt_marshallIn(SFc2_FruitInstanceStruct *chartInstance, const
  mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[2]);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_g_emlrt_marshallIn(SFc2_FruitInstanceStruct *chartInstance, const
  mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[30]);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_i_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_j_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[31]);
static void c2_GetJointCoordinates(SFc2_FruitInstanceStruct *chartInstance,
  real_T c2_Joints[30], real_T c2_Coordinates[2]);
static void c2_b_GetJointCoordinates(SFc2_FruitInstanceStruct *chartInstance,
  real_T c2_Joints[30], real_T c2_Coordinates[2]);
static void c2_is_flint_colon(SFc2_FruitInstanceStruct *chartInstance);
static real_T c2_power(SFc2_FruitInstanceStruct *chartInstance, real_T c2_a,
  real_T c2_b);
static void c2_eml_error(SFc2_FruitInstanceStruct *chartInstance);
static void c2_eml_integer_colon(SFc2_FruitInstanceStruct *chartInstance);
static void c2_checkrange(SFc2_FruitInstanceStruct *chartInstance);
static void c2_b_eml_integer_colon(SFc2_FruitInstanceStruct *chartInstance);
static void c2_meshgrid(SFc2_FruitInstanceStruct *chartInstance, real_T c2_x[640],
  real_T c2_y[480], real_T c2_xx[307200], real_T c2_yy[307200]);
static void c2_b_power(SFc2_FruitInstanceStruct *chartInstance, real_T c2_a
  [307200], real_T c2_b, real_T c2_y[307200]);
static real_T c2_mpower(SFc2_FruitInstanceStruct *chartInstance, real_T c2_a);
static const mxArray *c2_k_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_h_emlrt_marshallIn(SFc2_FruitInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_i_emlrt_marshallIn(SFc2_FruitInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_Fruit, const char_T *c2_identifier);
static uint8_T c2_j_emlrt_marshallIn(SFc2_FruitInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_FruitInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_Fruit(SFc2_FruitInstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_Fruit = 0U;
}

static void initialize_params_c2_Fruit(SFc2_FruitInstanceStruct *chartInstance)
{
}

static void enable_c2_Fruit(SFc2_FruitInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_Fruit(SFc2_FruitInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_Fruit(SFc2_FruitInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c2_Fruit(SFc2_FruitInstanceStruct
  *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  static boolean_T c2_u[307200];
  const mxArray *c2_b_y = NULL;
  int32_T c2_i1;
  static boolean_T c2_b_u[307200];
  const mxArray *c2_c_y = NULL;
  int32_T c2_i2;
  static boolean_T c2_c_u[307200];
  const mxArray *c2_d_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  boolean_T (*c2_image2)[307200];
  boolean_T (*c2_image1)[307200];
  boolean_T (*c2_bothHands)[307200];
  c2_bothHands = (boolean_T (*)[307200])ssGetOutputPortSignal(chartInstance->S,
    3);
  c2_image2 = (boolean_T (*)[307200])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_image1 = (boolean_T (*)[307200])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(4));
  for (c2_i0 = 0; c2_i0 < 307200; c2_i0++) {
    c2_u[c2_i0] = (*c2_bothHands)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 11, 0U, 1U, 0U, 2, 480, 640));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  for (c2_i1 = 0; c2_i1 < 307200; c2_i1++) {
    c2_b_u[c2_i1] = (*c2_image1)[c2_i1];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_u, 11, 0U, 1U, 0U, 2, 480, 640));
  sf_mex_setcell(c2_y, 1, c2_c_y);
  for (c2_i2 = 0; c2_i2 < 307200; c2_i2++) {
    c2_c_u[c2_i2] = (*c2_image2)[c2_i2];
  }

  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_c_u, 11, 0U, 1U, 0U, 2, 480, 640));
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_Fruit;
  c2_d_u = c2_hoistedGlobal;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 3, c2_e_y);
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_Fruit(SFc2_FruitInstanceStruct *chartInstance,
  const mxArray *c2_st)
{
  const mxArray *c2_u;
  static boolean_T c2_bv0[307200];
  int32_T c2_i3;
  static boolean_T c2_bv1[307200];
  int32_T c2_i4;
  static boolean_T c2_bv2[307200];
  int32_T c2_i5;
  boolean_T (*c2_bothHands)[307200];
  boolean_T (*c2_image1)[307200];
  boolean_T (*c2_image2)[307200];
  c2_bothHands = (boolean_T (*)[307200])ssGetOutputPortSignal(chartInstance->S,
    3);
  c2_image2 = (boolean_T (*)[307200])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_image1 = (boolean_T (*)[307200])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
                      "bothHands", c2_bv0);
  for (c2_i3 = 0; c2_i3 < 307200; c2_i3++) {
    (*c2_bothHands)[c2_i3] = c2_bv0[c2_i3];
  }

  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
                      "image1", c2_bv1);
  for (c2_i4 = 0; c2_i4 < 307200; c2_i4++) {
    (*c2_image1)[c2_i4] = c2_bv1[c2_i4];
  }

  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)),
                      "image2", c2_bv2);
  for (c2_i5 = 0; c2_i5 < 307200; c2_i5++) {
    (*c2_image2)[c2_i5] = c2_bv2[c2_i5];
  }

  chartInstance->c2_is_active_c2_Fruit = c2_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 3)), "is_active_c2_Fruit");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_Fruit(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_Fruit(SFc2_FruitInstanceStruct *chartInstance)
{
}

static void sf_c2_Fruit(SFc2_FruitInstanceStruct *chartInstance)
{
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  boolean_T *c2_tracking;
  boolean_T (*c2_bothHands)[307200];
  boolean_T (*c2_image2)[307200];
  real_T (*c2_skeleton)[45];
  boolean_T (*c2_image1)[307200];
  c2_bothHands = (boolean_T (*)[307200])ssGetOutputPortSignal(chartInstance->S,
    3);
  c2_image2 = (boolean_T (*)[307200])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_skeleton = (real_T (*)[45])ssGetInputPortSignal(chartInstance->S, 1);
  c2_image1 = (boolean_T (*)[307200])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_tracking = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c2_tracking, 0U);
  for (c2_i6 = 0; c2_i6 < 307200; c2_i6++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c2_image1)[c2_i6], 1U);
  }

  for (c2_i7 = 0; c2_i7 < 45; c2_i7++) {
    _SFD_DATA_RANGE_CHECK((*c2_skeleton)[c2_i7], 2U);
  }

  for (c2_i8 = 0; c2_i8 < 307200; c2_i8++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c2_image2)[c2_i8], 3U);
  }

  for (c2_i9 = 0; c2_i9 < 307200; c2_i9++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c2_bothHands)[c2_i9], 4U);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_Fruit(chartInstance);
  sf_debug_check_for_state_inconsistency(_FruitMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_Fruit(SFc2_FruitInstanceStruct *chartInstance)
{
  boolean_T c2_hoistedGlobal;
  boolean_T c2_tracking;
  int32_T c2_i10;
  real_T c2_skeleton[45];
  uint32_T c2_debug_family_var_map[11];
  real_T c2_imageCoordinates[30];
  c2_s7XUNvDD2qgIelqD6Zf8rpH c2_p;
  static real_T c2_X[307200];
  static real_T c2_Y[307200];
  real_T c2_nargin = 2.0;
  real_T c2_nargout = 3.0;
  static boolean_T c2_image1[307200];
  static boolean_T c2_image2[307200];
  static boolean_T c2_bothHands[307200];
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  real_T c2_a[15];
  int32_T c2_i14;
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_i19;
  int32_T c2_i20;
  int32_T c2_i21;
  real_T c2_b_imageCoordinates[30];
  real_T c2_dv0[2];
  int32_T c2_i22;
  int32_T c2_i23;
  real_T c2_c_imageCoordinates[30];
  real_T c2_dv1[2];
  int32_T c2_i24;
  int32_T c2_i25;
  real_T c2_dv2[640];
  int32_T c2_i26;
  real_T c2_dv3[480];
  static real_T c2_b_Y[307200];
  static real_T c2_b_X[307200];
  int32_T c2_i27;
  int32_T c2_i28;
  real_T c2_b_p;
  int32_T c2_i29;
  static real_T c2_c_X[307200];
  real_T c2_c_p;
  int32_T c2_i30;
  static real_T c2_c_Y[307200];
  real_T c2_d0;
  int32_T c2_i31;
  real_T c2_d_p;
  int32_T c2_i32;
  static real_T c2_d_X[307200];
  real_T c2_e_p;
  int32_T c2_i33;
  static real_T c2_d_Y[307200];
  real_T c2_d1;
  int32_T c2_i34;
  int32_T c2_i35;
  static boolean_T c2_b_image2[307200];
  int32_T c2_i36;
  static boolean_T c2_b_image1[307200];
  int32_T c2_i37;
  int32_T c2_i38;
  int32_T c2_i39;
  int32_T c2_i40;
  int32_T c2_i41;
  int32_T c2_i42;
  int32_T c2_i43;
  boolean_T *c2_b_tracking;
  boolean_T (*c2_c_image1)[307200];
  boolean_T (*c2_c_image2)[307200];
  boolean_T (*c2_b_bothHands)[307200];
  real_T (*c2_b_skeleton)[45];
  c2_b_bothHands = (boolean_T (*)[307200])ssGetOutputPortSignal(chartInstance->S,
    3);
  c2_c_image2 = (boolean_T (*)[307200])ssGetOutputPortSignal(chartInstance->S, 2);
  c2_b_skeleton = (real_T (*)[45])ssGetInputPortSignal(chartInstance->S, 1);
  c2_c_image1 = (boolean_T (*)[307200])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_tracking = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_tracking;
  c2_tracking = c2_hoistedGlobal;
  for (c2_i10 = 0; c2_i10 < 45; c2_i10++) {
    c2_skeleton[c2_i10] = (*c2_b_skeleton)[c2_i10];
  }

  sf_debug_symbol_scope_push_eml(0U, 11U, 11U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c2_imageCoordinates, 0U,
    c2_g_sf_marshallOut, c2_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_p, 1U, c2_f_sf_marshallOut,
    c2_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_X, 2U, c2_e_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_Y, 3U, c2_e_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 4U, c2_d_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 5U, c2_d_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_tracking, 6U, c2_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c2_skeleton, 7U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_image1, 8U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_image2, 9U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_bothHands, 10U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  if (CV_EML_IF(0, 0, (real_T)c2_tracking == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
    for (c2_i11 = 0; c2_i11 < 307200; c2_i11++) {
      c2_image1[c2_i11] = FALSE;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
    for (c2_i12 = 0; c2_i12 < 30; c2_i12++) {
      c2_imageCoordinates[c2_i12] = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 6);
    for (c2_i13 = 0; c2_i13 < 15; c2_i13++) {
      c2_a[c2_i13] = c2_skeleton[c2_i13];
    }

    for (c2_i14 = 0; c2_i14 < 15; c2_i14++) {
      c2_a[c2_i14] *= 1000.0;
    }

    c2_i15 = 0;
    for (c2_i16 = 0; c2_i16 < 15; c2_i16++) {
      c2_imageCoordinates[c2_i15] = c2_a[c2_i16];
      c2_i15 += 2;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
    for (c2_i17 = 0; c2_i17 < 15; c2_i17++) {
      c2_a[c2_i17] = c2_skeleton[c2_i17 + 15];
    }

    for (c2_i18 = 0; c2_i18 < 15; c2_i18++) {
      c2_a[c2_i18] *= 1000.0;
    }

    c2_i19 = 0;
    for (c2_i20 = 0; c2_i20 < 15; c2_i20++) {
      c2_imageCoordinates[c2_i19 + 1] = c2_a[c2_i20];
      c2_i19 += 2;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
    for (c2_i21 = 0; c2_i21 < 30; c2_i21++) {
      c2_b_imageCoordinates[c2_i21] = c2_imageCoordinates[c2_i21];
    }

    c2_GetJointCoordinates(chartInstance, c2_b_imageCoordinates, c2_dv0);
    for (c2_i22 = 0; c2_i22 < 2; c2_i22++) {
      c2_p.rhand[c2_i22] = c2_dv0[c2_i22];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
    for (c2_i23 = 0; c2_i23 < 30; c2_i23++) {
      c2_c_imageCoordinates[c2_i23] = c2_imageCoordinates[c2_i23];
    }

    c2_b_GetJointCoordinates(chartInstance, c2_c_imageCoordinates, c2_dv1);
    for (c2_i24 = 0; c2_i24 < 2; c2_i24++) {
      c2_p.lhand[c2_i24] = c2_dv1[c2_i24];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
    c2_is_flint_colon(chartInstance);
    c2_eml_integer_colon(chartInstance);
    c2_b_eml_integer_colon(chartInstance);
    for (c2_i25 = 0; c2_i25 < 640; c2_i25++) {
      c2_dv2[c2_i25] = 1.0 + (real_T)c2_i25;
    }

    for (c2_i26 = 0; c2_i26 < 480; c2_i26++) {
      c2_dv3[c2_i26] = 1.0 + (real_T)c2_i26;
    }

    c2_meshgrid(chartInstance, c2_dv2, c2_dv3, c2_b_X, c2_b_Y);
    for (c2_i27 = 0; c2_i27 < 307200; c2_i27++) {
      c2_X[c2_i27] = c2_b_X[c2_i27];
    }

    for (c2_i28 = 0; c2_i28 < 307200; c2_i28++) {
      c2_Y[c2_i28] = c2_b_Y[c2_i28];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 12);
    c2_b_p = c2_p.rhand[0];
    for (c2_i29 = 0; c2_i29 < 307200; c2_i29++) {
      c2_c_X[c2_i29] = c2_X[c2_i29] - c2_b_p;
    }

    c2_b_power(chartInstance, c2_c_X, 2.0, c2_b_X);
    c2_c_p = c2_p.rhand[1];
    for (c2_i30 = 0; c2_i30 < 307200; c2_i30++) {
      c2_c_Y[c2_i30] = c2_Y[c2_i30] - c2_c_p;
    }

    c2_b_power(chartInstance, c2_c_Y, 2.0, c2_b_Y);
    c2_d0 = c2_mpower(chartInstance, 20.0);
    for (c2_i31 = 0; c2_i31 < 307200; c2_i31++) {
      c2_image1[c2_i31] = ((real_T)(c2_b_X[c2_i31] + c2_b_Y[c2_i31] < c2_d0) ==
                           1.0);
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 13);
    c2_d_p = c2_p.lhand[0];
    for (c2_i32 = 0; c2_i32 < 307200; c2_i32++) {
      c2_d_X[c2_i32] = c2_X[c2_i32] - c2_d_p;
    }

    c2_b_power(chartInstance, c2_d_X, 2.0, c2_b_X);
    c2_e_p = c2_p.lhand[1];
    for (c2_i33 = 0; c2_i33 < 307200; c2_i33++) {
      c2_d_Y[c2_i33] = c2_Y[c2_i33] - c2_e_p;
    }

    c2_b_power(chartInstance, c2_d_Y, 2.0, c2_b_Y);
    c2_d1 = c2_mpower(chartInstance, 20.0);
    for (c2_i34 = 0; c2_i34 < 307200; c2_i34++) {
      c2_image2[c2_i34] = ((real_T)(c2_b_X[c2_i34] + c2_b_Y[c2_i34] < c2_d1) ==
                           1.0);
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 14);
    for (c2_i35 = 0; c2_i35 < 307200; c2_i35++) {
      c2_b_image2[c2_i35] = c2_image2[c2_i35];
    }

    for (c2_i36 = 0; c2_i36 < 307200; c2_i36++) {
      c2_b_image1[c2_i36] = c2_image1[c2_i36];
    }

    for (c2_i37 = 0; c2_i37 < 307200; c2_i37++) {
      c2_bothHands[c2_i37] = (c2_b_image2[c2_i37] || c2_b_image1[c2_i37]);
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 16);
    for (c2_i38 = 0; c2_i38 < 307200; c2_i38++) {
      c2_image1[c2_i38] = FALSE;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 17);
    for (c2_i39 = 0; c2_i39 < 307200; c2_i39++) {
      c2_image2[c2_i39] = FALSE;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 18);
    for (c2_i40 = 0; c2_i40 < 307200; c2_i40++) {
      c2_bothHands[c2_i40] = FALSE;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -18);
  sf_debug_symbol_scope_pop();
  for (c2_i41 = 0; c2_i41 < 307200; c2_i41++) {
    (*c2_c_image1)[c2_i41] = c2_image1[c2_i41];
  }

  for (c2_i42 = 0; c2_i42 < 307200; c2_i42++) {
    (*c2_c_image2)[c2_i42] = c2_image2[c2_i42];
  }

  for (c2_i43 = 0; c2_i43 < 307200; c2_i43++) {
    (*c2_b_bothHands)[c2_i43] = c2_bothHands[c2_i43];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_Fruit(SFc2_FruitInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c2_chartNumber, 0U, sf_debug_get_script_id(
    "C:/Users/Hayyaan/Desktop/PRJ/Fruit/GetJointCoordinates.m"));
  _SFD_SCRIPT_TRANSLATION(c2_chartNumber, 1U, sf_debug_get_script_id(
    "C:/Users/Hayyaan/Desktop/PRJ/Fruit/GetJointIndex.m"));
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i44;
  int32_T c2_i45;
  int32_T c2_i46;
  static boolean_T c2_b_inData[307200];
  int32_T c2_i47;
  int32_T c2_i48;
  int32_T c2_i49;
  static boolean_T c2_u[307200];
  const mxArray *c2_y = NULL;
  SFc2_FruitInstanceStruct *chartInstance;
  chartInstance = (SFc2_FruitInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i44 = 0;
  for (c2_i45 = 0; c2_i45 < 640; c2_i45++) {
    for (c2_i46 = 0; c2_i46 < 480; c2_i46++) {
      c2_b_inData[c2_i46 + c2_i44] = (*(boolean_T (*)[307200])c2_inData)[c2_i46
        + c2_i44];
    }

    c2_i44 += 480;
  }

  c2_i47 = 0;
  for (c2_i48 = 0; c2_i48 < 640; c2_i48++) {
    for (c2_i49 = 0; c2_i49 < 480; c2_i49++) {
      c2_u[c2_i49 + c2_i47] = c2_b_inData[c2_i49 + c2_i47];
    }

    c2_i47 += 480;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 11, 0U, 1U, 0U, 2, 480, 640));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_FruitInstanceStruct *chartInstance, const
  mxArray *c2_bothHands, const char_T *c2_identifier, boolean_T c2_y[307200])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_bothHands), &c2_thisId,
                        c2_y);
  sf_mex_destroy(&c2_bothHands);
}

static void c2_b_emlrt_marshallIn(SFc2_FruitInstanceStruct *chartInstance, const
  mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, boolean_T c2_y[307200])
{
  static boolean_T c2_bv3[307200];
  int32_T c2_i50;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_bv3, 1, 11, 0U, 1, 0U, 2, 480,
                640);
  for (c2_i50 = 0; c2_i50 < 307200; c2_i50++) {
    c2_y[c2_i50] = c2_bv3[c2_i50];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_bothHands;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  static boolean_T c2_y[307200];
  int32_T c2_i51;
  int32_T c2_i52;
  int32_T c2_i53;
  SFc2_FruitInstanceStruct *chartInstance;
  chartInstance = (SFc2_FruitInstanceStruct *)chartInstanceVoid;
  c2_bothHands = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_bothHands), &c2_thisId,
                        c2_y);
  sf_mex_destroy(&c2_bothHands);
  c2_i51 = 0;
  for (c2_i52 = 0; c2_i52 < 640; c2_i52++) {
    for (c2_i53 = 0; c2_i53 < 480; c2_i53++) {
      (*(boolean_T (*)[307200])c2_outData)[c2_i53 + c2_i51] = c2_y[c2_i53 +
        c2_i51];
    }

    c2_i51 += 480;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i54;
  int32_T c2_i55;
  int32_T c2_i56;
  real_T c2_b_inData[45];
  int32_T c2_i57;
  int32_T c2_i58;
  int32_T c2_i59;
  real_T c2_u[45];
  const mxArray *c2_y = NULL;
  SFc2_FruitInstanceStruct *chartInstance;
  chartInstance = (SFc2_FruitInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i54 = 0;
  for (c2_i55 = 0; c2_i55 < 3; c2_i55++) {
    for (c2_i56 = 0; c2_i56 < 15; c2_i56++) {
      c2_b_inData[c2_i56 + c2_i54] = (*(real_T (*)[45])c2_inData)[c2_i56 +
        c2_i54];
    }

    c2_i54 += 15;
  }

  c2_i57 = 0;
  for (c2_i58 = 0; c2_i58 < 3; c2_i58++) {
    for (c2_i59 = 0; c2_i59 < 15; c2_i59++) {
      c2_u[c2_i59 + c2_i57] = c2_b_inData[c2_i59 + c2_i57];
    }

    c2_i57 += 15;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 3, 1, 15, 3));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  boolean_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_FruitInstanceStruct *chartInstance;
  chartInstance = (SFc2_FruitInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(boolean_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_FruitInstanceStruct *chartInstance;
  chartInstance = (SFc2_FruitInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_FruitInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d2;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d2, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d2;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_FruitInstanceStruct *chartInstance;
  chartInstance = (SFc2_FruitInstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i60;
  int32_T c2_i61;
  int32_T c2_i62;
  static real_T c2_b_inData[307200];
  int32_T c2_i63;
  int32_T c2_i64;
  int32_T c2_i65;
  static real_T c2_u[307200];
  const mxArray *c2_y = NULL;
  SFc2_FruitInstanceStruct *chartInstance;
  chartInstance = (SFc2_FruitInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i60 = 0;
  for (c2_i61 = 0; c2_i61 < 640; c2_i61++) {
    for (c2_i62 = 0; c2_i62 < 480; c2_i62++) {
      c2_b_inData[c2_i62 + c2_i60] = (*(real_T (*)[307200])c2_inData)[c2_i62 +
        c2_i60];
    }

    c2_i60 += 480;
  }

  c2_i63 = 0;
  for (c2_i64 = 0; c2_i64 < 640; c2_i64++) {
    for (c2_i65 = 0; c2_i65 < 480; c2_i65++) {
      c2_u[c2_i65 + c2_i63] = c2_b_inData[c2_i65 + c2_i63];
    }

    c2_i63 += 480;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 480, 640));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static void c2_d_emlrt_marshallIn(SFc2_FruitInstanceStruct *chartInstance, const
  mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[307200])
{
  static real_T c2_dv4[307200];
  int32_T c2_i66;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv4, 1, 0, 0U, 1, 0U, 2, 480,
                640);
  for (c2_i66 = 0; c2_i66 < 307200; c2_i66++) {
    c2_y[c2_i66] = c2_dv4[c2_i66];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_Y;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  static real_T c2_y[307200];
  int32_T c2_i67;
  int32_T c2_i68;
  int32_T c2_i69;
  SFc2_FruitInstanceStruct *chartInstance;
  chartInstance = (SFc2_FruitInstanceStruct *)chartInstanceVoid;
  c2_Y = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Y), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_Y);
  c2_i67 = 0;
  for (c2_i68 = 0; c2_i68 < 640; c2_i68++) {
    for (c2_i69 = 0; c2_i69 < 480; c2_i69++) {
      (*(real_T (*)[307200])c2_outData)[c2_i69 + c2_i67] = c2_y[c2_i69 + c2_i67];
    }

    c2_i67 += 480;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  c2_s7XUNvDD2qgIelqD6Zf8rpH c2_u;
  const mxArray *c2_y = NULL;
  int32_T c2_i70;
  real_T c2_b_u[2];
  const mxArray *c2_b_y = NULL;
  int32_T c2_i71;
  real_T c2_c_u[2];
  const mxArray *c2_c_y = NULL;
  SFc2_FruitInstanceStruct *chartInstance;
  chartInstance = (SFc2_FruitInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(c2_s7XUNvDD2qgIelqD6Zf8rpH *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createstruct("structure", 2, 1, 1));
  for (c2_i70 = 0; c2_i70 < 2; c2_i70++) {
    c2_b_u[c2_i70] = c2_u.rhand[c2_i70];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 1, 2));
  sf_mex_addfield(c2_y, c2_b_y, "rhand", "rhand", 0);
  for (c2_i71 = 0; c2_i71 < 2; c2_i71++) {
    c2_c_u[c2_i71] = c2_u.lhand[c2_i71];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 1, 2));
  sf_mex_addfield(c2_y, c2_c_y, "lhand", "lhand", 0);
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static c2_s7XUNvDD2qgIelqD6Zf8rpH c2_e_emlrt_marshallIn(SFc2_FruitInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  c2_s7XUNvDD2qgIelqD6Zf8rpH c2_y;
  emlrtMsgIdentifier c2_thisId;
  static const char * c2_fieldNames[2] = { "rhand", "lhand" };

  c2_thisId.fParent = c2_parentId;
  sf_mex_check_struct(c2_parentId, c2_u, 2, c2_fieldNames, 0U, 0);
  c2_thisId.fIdentifier = "rhand";
  c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u, "rhand",
    "rhand", 0)), &c2_thisId, c2_y.rhand);
  c2_thisId.fIdentifier = "lhand";
  c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c2_u, "lhand",
    "lhand", 0)), &c2_thisId, c2_y.lhand);
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_f_emlrt_marshallIn(SFc2_FruitInstanceStruct *chartInstance, const
  mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[2])
{
  real_T c2_dv5[2];
  int32_T c2_i72;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv5, 1, 0, 0U, 1, 0U, 1, 2);
  for (c2_i72 = 0; c2_i72 < 2; c2_i72++) {
    c2_y[c2_i72] = c2_dv5[c2_i72];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_p;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  c2_s7XUNvDD2qgIelqD6Zf8rpH c2_y;
  SFc2_FruitInstanceStruct *chartInstance;
  chartInstance = (SFc2_FruitInstanceStruct *)chartInstanceVoid;
  c2_p = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_p), &c2_thisId);
  sf_mex_destroy(&c2_p);
  *(c2_s7XUNvDD2qgIelqD6Zf8rpH *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i73;
  int32_T c2_i74;
  int32_T c2_i75;
  real_T c2_b_inData[30];
  int32_T c2_i76;
  int32_T c2_i77;
  int32_T c2_i78;
  real_T c2_u[30];
  const mxArray *c2_y = NULL;
  SFc2_FruitInstanceStruct *chartInstance;
  chartInstance = (SFc2_FruitInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i73 = 0;
  for (c2_i74 = 0; c2_i74 < 15; c2_i74++) {
    for (c2_i75 = 0; c2_i75 < 2; c2_i75++) {
      c2_b_inData[c2_i75 + c2_i73] = (*(real_T (*)[30])c2_inData)[c2_i75 +
        c2_i73];
    }

    c2_i73 += 2;
  }

  c2_i76 = 0;
  for (c2_i77 = 0; c2_i77 < 15; c2_i77++) {
    for (c2_i78 = 0; c2_i78 < 2; c2_i78++) {
      c2_u[c2_i78 + c2_i76] = c2_b_inData[c2_i78 + c2_i76];
    }

    c2_i76 += 2;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 2, 15));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static void c2_g_emlrt_marshallIn(SFc2_FruitInstanceStruct *chartInstance, const
  mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[30])
{
  real_T c2_dv6[30];
  int32_T c2_i79;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv6, 1, 0, 0U, 1, 0U, 2, 2, 15);
  for (c2_i79 = 0; c2_i79 < 30; c2_i79++) {
    c2_y[c2_i79] = c2_dv6[c2_i79];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_imageCoordinates;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[30];
  int32_T c2_i80;
  int32_T c2_i81;
  int32_T c2_i82;
  SFc2_FruitInstanceStruct *chartInstance;
  chartInstance = (SFc2_FruitInstanceStruct *)chartInstanceVoid;
  c2_imageCoordinates = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_imageCoordinates),
                        &c2_thisId, c2_y);
  sf_mex_destroy(&c2_imageCoordinates);
  c2_i80 = 0;
  for (c2_i81 = 0; c2_i81 < 15; c2_i81++) {
    for (c2_i82 = 0; c2_i82 < 2; c2_i82++) {
      (*(real_T (*)[30])c2_outData)[c2_i82 + c2_i80] = c2_y[c2_i82 + c2_i80];
    }

    c2_i80 += 2;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i83;
  char_T c2_b_inData[19];
  int32_T c2_i84;
  char_T c2_u[19];
  const mxArray *c2_y = NULL;
  SFc2_FruitInstanceStruct *chartInstance;
  chartInstance = (SFc2_FruitInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i83 = 0; c2_i83 < 19; c2_i83++) {
    c2_b_inData[c2_i83] = (*(char_T (*)[19])c2_inData)[c2_i83];
  }

  for (c2_i84 = 0; c2_i84 < 19; c2_i84++) {
    c2_u[c2_i84] = c2_b_inData[c2_i84];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 19));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static const mxArray *c2_i_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i85;
  real_T c2_b_inData[2];
  int32_T c2_i86;
  real_T c2_u[2];
  const mxArray *c2_y = NULL;
  SFc2_FruitInstanceStruct *chartInstance;
  chartInstance = (SFc2_FruitInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i85 = 0; c2_i85 < 2; c2_i85++) {
    c2_b_inData[c2_i85] = (*(real_T (*)[2])c2_inData)[c2_i85];
  }

  for (c2_i86 = 0; c2_i86 < 2; c2_i86++) {
    c2_u[c2_i86] = c2_b_inData[c2_i86];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 2));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_Coordinates;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[2];
  int32_T c2_i87;
  SFc2_FruitInstanceStruct *chartInstance;
  chartInstance = (SFc2_FruitInstanceStruct *)chartInstanceVoid;
  c2_Coordinates = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Coordinates), &c2_thisId,
                        c2_y);
  sf_mex_destroy(&c2_Coordinates);
  for (c2_i87 = 0; c2_i87 < 2; c2_i87++) {
    (*(real_T (*)[2])c2_outData)[c2_i87] = c2_y[c2_i87];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_j_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i88;
  char_T c2_b_inData[18];
  int32_T c2_i89;
  char_T c2_u[18];
  const mxArray *c2_y = NULL;
  SFc2_FruitInstanceStruct *chartInstance;
  chartInstance = (SFc2_FruitInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i88 = 0; c2_i88 < 18; c2_i88++) {
    c2_b_inData[c2_i88] = (*(char_T (*)[18])c2_inData)[c2_i88];
  }

  for (c2_i89 = 0; c2_i89 < 18; c2_i89++) {
    c2_u[c2_i89] = c2_b_inData[c2_i89];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 18));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

const mxArray *sf_c2_Fruit_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[31];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i90;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 31));
  for (c2_i90 = 0; c2_i90 < 31; c2_i90++) {
    c2_r0 = &c2_info[c2_i90];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i90);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i90);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i90);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i90);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i90);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i90);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i90);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i90);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[31])
{
  c2_info[0].context = "";
  c2_info[0].name = "mtimes";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[0].fileTimeLo = 1306955264U;
  c2_info[0].fileTimeHi = 30114266U;
  c2_info[0].mFileTimeLo = 0U;
  c2_info[0].mFileTimeHi = 0U;
  c2_info[1].context = "";
  c2_info[1].name = "GetJointCoordinates";
  c2_info[1].dominantType = "char";
  c2_info[1].resolved =
    "[E]C:/Users/Hayyaan/Desktop/PRJ/Fruit/GetJointCoordinates.m";
  c2_info[1].fileTimeLo = 917061719U;
  c2_info[1].fileTimeHi = 30221104U;
  c2_info[1].mFileTimeLo = 0U;
  c2_info[1].mFileTimeHi = 0U;
  c2_info[2].context =
    "[E]C:/Users/Hayyaan/Desktop/PRJ/Fruit/GetJointCoordinates.m";
  c2_info[2].name = "GetJointIndex";
  c2_info[2].dominantType = "char";
  c2_info[2].resolved = "[E]C:/Users/Hayyaan/Desktop/PRJ/Fruit/GetJointIndex.m";
  c2_info[2].fileTimeLo = 685521719U;
  c2_info[2].fileTimeHi = 30221104U;
  c2_info[2].mFileTimeLo = 0U;
  c2_info[2].mFileTimeHi = 0U;
  c2_info[3].context = "";
  c2_info[3].name = "colon";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c2_info[3].fileTimeLo = 1161574144U;
  c2_info[3].fileTimeHi = 30107986U;
  c2_info[3].mFileTimeLo = 0U;
  c2_info[3].mFileTimeHi = 0U;
  c2_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!is_flint_colon";
  c2_info[4].name = "isfinite";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c2_info[4].fileTimeLo = 361574144U;
  c2_info[4].fileTimeHi = 30107986U;
  c2_info[4].mFileTimeLo = 0U;
  c2_info[4].mFileTimeHi = 0U;
  c2_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c2_info[5].name = "isinf";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c2_info[5].fileTimeLo = 381574144U;
  c2_info[5].fileTimeHi = 30107986U;
  c2_info[5].mFileTimeLo = 0U;
  c2_info[5].mFileTimeHi = 0U;
  c2_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c2_info[6].name = "isnan";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c2_info[6].fileTimeLo = 381574144U;
  c2_info[6].fileTimeHi = 30107986U;
  c2_info[6].mFileTimeLo = 0U;
  c2_info[6].mFileTimeHi = 0U;
  c2_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!is_flint_colon";
  c2_info[7].name = "floor";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[7].fileTimeLo = 201574144U;
  c2_info[7].fileTimeHi = 30107986U;
  c2_info[7].mFileTimeLo = 0U;
  c2_info[7].mFileTimeHi = 0U;
  c2_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[8].name = "eml_scalar_floor";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[8].fileTimeLo = 41574144U;
  c2_info[8].fileTimeHi = 30107986U;
  c2_info[8].mFileTimeLo = 0U;
  c2_info[8].mFileTimeHi = 0U;
  c2_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!maxabs";
  c2_info[9].name = "abs";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[9].fileTimeLo = 4016541440U;
  c2_info[9].fileTimeHi = 30107985U;
  c2_info[9].mFileTimeLo = 0U;
  c2_info[9].mFileTimeHi = 0U;
  c2_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[10].name = "eml_scalar_abs";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[10].fileTimeLo = 4196541440U;
  c2_info[10].fileTimeHi = 30107985U;
  c2_info[10].mFileTimeLo = 0U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!is_flint_colon";
  c2_info[11].name = "eps";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[11].fileTimeLo = 3936541440U;
  c2_info[11].fileTimeHi = 30107985U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[12].name = "realmin";
  c2_info[12].dominantType = "";
  c2_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c2_info[12].fileTimeLo = 461574144U;
  c2_info[12].fileTimeHi = 30107986U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
  c2_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c2_info[13].name = "mpower";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[13].fileTimeLo = 1201574144U;
  c2_info[13].fileTimeHi = 30107986U;
  c2_info[13].mFileTimeLo = 0U;
  c2_info[13].mFileTimeHi = 0U;
  c2_info[14].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[14].name = "power";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[14].fileTimeLo = 1221574144U;
  c2_info[14].fileTimeHi = 30107986U;
  c2_info[14].mFileTimeLo = 0U;
  c2_info[14].mFileTimeHi = 0U;
  c2_info[15].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[15].name = "eml_scalar_eg";
  c2_info[15].dominantType = "double";
  c2_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[15].fileTimeLo = 741574144U;
  c2_info[15].fileTimeHi = 30107986U;
  c2_info[15].mFileTimeLo = 0U;
  c2_info[15].mFileTimeHi = 0U;
  c2_info[16].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[16].name = "eml_scalexp_alloc";
  c2_info[16].dominantType = "double";
  c2_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[16].fileTimeLo = 741574144U;
  c2_info[16].fileTimeHi = 30107986U;
  c2_info[16].mFileTimeLo = 0U;
  c2_info[16].mFileTimeHi = 0U;
  c2_info[17].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[17].name = "eml_error";
  c2_info[17].dominantType = "char";
  c2_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c2_info[17].fileTimeLo = 4076541440U;
  c2_info[17].fileTimeHi = 30107985U;
  c2_info[17].mFileTimeLo = 0U;
  c2_info[17].mFileTimeHi = 0U;
  c2_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c2_info[18].name = "realmax";
  c2_info[18].dominantType = "char";
  c2_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c2_info[18].fileTimeLo = 441574144U;
  c2_info[18].fileTimeHi = 30107986U;
  c2_info[18].mFileTimeLo = 0U;
  c2_info[18].mFileTimeHi = 0U;
  c2_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon";
  c2_info[19].name = "mrdivide";
  c2_info[19].dominantType = "double";
  c2_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[19].fileTimeLo = 4145986304U;
  c2_info[19].fileTimeHi = 30130901U;
  c2_info[19].mFileTimeLo = 1306955264U;
  c2_info[19].mFileTimeHi = 30114266U;
  c2_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[20].name = "rdivide";
  c2_info[20].dominantType = "double";
  c2_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[20].fileTimeLo = 1221574144U;
  c2_info[20].fileTimeHi = 30107986U;
  c2_info[20].mFileTimeLo = 0U;
  c2_info[20].mFileTimeHi = 0U;
  c2_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[21].name = "eml_div";
  c2_info[21].dominantType = "double";
  c2_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[21].fileTimeLo = 4056541440U;
  c2_info[21].fileTimeHi = 30107985U;
  c2_info[21].mFileTimeLo = 0U;
  c2_info[21].mFileTimeHi = 0U;
  c2_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon";
  c2_info[22].name = "eml_index_class";
  c2_info[22].dominantType = "";
  c2_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[22].fileTimeLo = 561574144U;
  c2_info[22].fileTimeHi = 30107986U;
  c2_info[22].mFileTimeLo = 0U;
  c2_info[22].mFileTimeHi = 0U;
  c2_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon";
  c2_info[23].name = "intmax";
  c2_info[23].dominantType = "char";
  c2_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[23].fileTimeLo = 341574144U;
  c2_info[23].fileTimeHi = 30107986U;
  c2_info[23].mFileTimeLo = 0U;
  c2_info[23].mFileTimeHi = 0U;
  c2_info[24].context = "";
  c2_info[24].name = "meshgrid";
  c2_info[24].dominantType = "double";
  c2_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/meshgrid.m";
  c2_info[24].fileTimeLo = 421574144U;
  c2_info[24].fileTimeHi = 30107986U;
  c2_info[24].mFileTimeLo = 0U;
  c2_info[24].mFileTimeHi = 0U;
  c2_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/meshgrid.m";
  c2_info[25].name = "repmat";
  c2_info[25].dominantType = "double";
  c2_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  c2_info[25].fileTimeLo = 461574144U;
  c2_info[25].fileTimeHi = 30107986U;
  c2_info[25].mFileTimeLo = 0U;
  c2_info[25].mFileTimeHi = 0U;
  c2_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  c2_info[26].name = "eml_assert_valid_size_arg";
  c2_info[26].dominantType = "double";
  c2_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[26].fileTimeLo = 4016541440U;
  c2_info[26].fileTimeHi = 30107985U;
  c2_info[26].mFileTimeLo = 0U;
  c2_info[26].mFileTimeHi = 0U;
  c2_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  c2_info[27].name = "eml_index_minus";
  c2_info[27].dominantType = "int32";
  c2_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[27].fileTimeLo = 561574144U;
  c2_info[27].fileTimeHi = 30107986U;
  c2_info[27].mFileTimeLo = 0U;
  c2_info[27].mFileTimeHi = 0U;
  c2_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  c2_info[28].name = "eml_index_prod";
  c2_info[28].dominantType = "int32";
  c2_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_prod.m";
  c2_info[28].fileTimeLo = 581574144U;
  c2_info[28].fileTimeHi = 30107986U;
  c2_info[28].mFileTimeLo = 0U;
  c2_info[28].mFileTimeHi = 0U;
  c2_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_prod.m";
  c2_info[29].name = "eml_index_times";
  c2_info[29].dominantType = "int32";
  c2_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c2_info[29].fileTimeLo = 581574144U;
  c2_info[29].fileTimeHi = 30107986U;
  c2_info[29].mFileTimeLo = 0U;
  c2_info[29].mFileTimeHi = 0U;
  c2_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  c2_info[30].name = "eml_index_plus";
  c2_info[30].dominantType = "int32";
  c2_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[30].fileTimeLo = 561574144U;
  c2_info[30].fileTimeHi = 30107986U;
  c2_info[30].mFileTimeLo = 0U;
  c2_info[30].mFileTimeHi = 0U;
}

static void c2_GetJointCoordinates(SFc2_FruitInstanceStruct *chartInstance,
  real_T c2_Joints[30], real_T c2_Coordinates[2])
{
  uint32_T c2_debug_family_var_map[6];
  real_T c2_index;
  char_T c2_JointName[19];
  real_T c2_nargin = 2.0;
  real_T c2_nargout = 1.0;
  int32_T c2_i91;
  static char_T c2_cv0[19] = { 'S', 'K', 'E', 'L', 'E', 'T', 'O', 'N', '_', 'R',
    'I', 'G', 'H', 'T', '_', 'H', 'A', 'N', 'D' };

  uint32_T c2_b_debug_family_var_map[4];
  real_T c2_JointIndex;
  char_T c2_b_JointName[19];
  real_T c2_b_nargin = 1.0;
  real_T c2_b_nargout = 1.0;
  int32_T c2_i92;
  int32_T c2_i93;
  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c2_c_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c2_index, 0U, c2_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c2_JointName, 1U, c2_h_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 2U, c2_d_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 3U, c2_d_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_Joints, 4U, c2_g_sf_marshallOut,
    c2_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_Coordinates, 5U,
    c2_i_sf_marshallOut, c2_f_sf_marshallIn);
  for (c2_i91 = 0; c2_i91 < 19; c2_i91++) {
    c2_JointName[c2_i91] = c2_cv0[c2_i91];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 3);
  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c2_b_debug_family_names,
    c2_b_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_JointIndex, 0U,
    c2_d_sf_marshallOut, c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c2_b_JointName, 1U, c2_h_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_b_nargin, 2U, c2_d_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_b_nargout, 3U,
    c2_d_sf_marshallOut, c2_b_sf_marshallIn);
  for (c2_i92 = 0; c2_i92 < 19; c2_i92++) {
    c2_b_JointName[c2_i92] = c2_cv0[c2_i92];
  }

  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 3);
  CV_SCRIPT_IF(1, 0, FALSE);
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 5);
  CV_SCRIPT_IF(1, 1, FALSE);
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 7);
  CV_SCRIPT_IF(1, 2, FALSE);
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 9);
  CV_SCRIPT_IF(1, 3, FALSE);
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 11);
  CV_SCRIPT_IF(1, 4, FALSE);
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 13);
  CV_SCRIPT_IF(1, 5, FALSE);
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 15);
  CV_SCRIPT_IF(1, 6, FALSE);
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 17);
  CV_SCRIPT_IF(1, 7, FALSE);
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 19);
  CV_SCRIPT_IF(1, 8, TRUE);
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 20);
  c2_JointIndex = 9.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, -34);
  sf_debug_symbol_scope_pop();
  c2_index = 9.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 4);
  for (c2_i93 = 0; c2_i93 < 2; c2_i93++) {
    c2_Coordinates[c2_i93] = c2_Joints[c2_i93 + 16];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -4);
  sf_debug_symbol_scope_pop();
}

static void c2_b_GetJointCoordinates(SFc2_FruitInstanceStruct *chartInstance,
  real_T c2_Joints[30], real_T c2_Coordinates[2])
{
  uint32_T c2_debug_family_var_map[6];
  real_T c2_index;
  char_T c2_JointName[18];
  real_T c2_nargin = 2.0;
  real_T c2_nargout = 1.0;
  int32_T c2_i94;
  static char_T c2_cv1[18] = { 'S', 'K', 'E', 'L', 'E', 'T', 'O', 'N', '_', 'L',
    'E', 'F', 'T', '_', 'H', 'A', 'N', 'D' };

  uint32_T c2_b_debug_family_var_map[4];
  real_T c2_JointIndex;
  char_T c2_b_JointName[18];
  real_T c2_b_nargin = 1.0;
  real_T c2_b_nargout = 1.0;
  int32_T c2_i95;
  int32_T c2_i96;
  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c2_e_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c2_index, 0U, c2_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c2_JointName, 1U, c2_j_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 2U, c2_d_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 3U, c2_d_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_Joints, 4U, c2_g_sf_marshallOut,
    c2_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_Coordinates, 5U,
    c2_i_sf_marshallOut, c2_f_sf_marshallIn);
  for (c2_i94 = 0; c2_i94 < 18; c2_i94++) {
    c2_JointName[c2_i94] = c2_cv1[c2_i94];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 3);
  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c2_d_debug_family_names,
    c2_b_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_JointIndex, 0U,
    c2_d_sf_marshallOut, c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c2_b_JointName, 1U, c2_j_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_b_nargin, 2U, c2_d_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_b_nargout, 3U,
    c2_d_sf_marshallOut, c2_b_sf_marshallIn);
  for (c2_i95 = 0; c2_i95 < 18; c2_i95++) {
    c2_b_JointName[c2_i95] = c2_cv1[c2_i95];
  }

  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 3);
  CV_SCRIPT_IF(1, 0, FALSE);
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 5);
  CV_SCRIPT_IF(1, 1, FALSE);
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 7);
  CV_SCRIPT_IF(1, 2, FALSE);
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 9);
  CV_SCRIPT_IF(1, 3, FALSE);
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 11);
  CV_SCRIPT_IF(1, 4, FALSE);
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 13);
  CV_SCRIPT_IF(1, 5, TRUE);
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 14);
  c2_JointIndex = 6.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, -34);
  sf_debug_symbol_scope_pop();
  c2_index = 6.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 4);
  for (c2_i96 = 0; c2_i96 < 2; c2_i96++) {
    c2_Coordinates[c2_i96] = c2_Joints[c2_i96 + 10];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -4);
  sf_debug_symbol_scope_pop();
}

static void c2_is_flint_colon(SFc2_FruitInstanceStruct *chartInstance)
{
}

static real_T c2_power(SFc2_FruitInstanceStruct *chartInstance, real_T c2_a,
  real_T c2_b)
{
  real_T c2_ak;
  real_T c2_bk;
  real_T c2_x;
  real_T c2_b_x;
  c2_ak = c2_a;
  c2_bk = c2_b;
  if (c2_ak < 0.0) {
    c2_x = c2_bk;
    c2_b_x = c2_x;
    c2_b_x = muDoubleScalarFloor(c2_b_x);
    if (c2_b_x != c2_bk) {
      c2_eml_error(chartInstance);
    }
  }

  return muDoubleScalarPower(c2_ak, c2_bk);
}

static void c2_eml_error(SFc2_FruitInstanceStruct *chartInstance)
{
  int32_T c2_i97;
  static char_T c2_varargin_1[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm',
    'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c2_u[31];
  const mxArray *c2_y = NULL;
  for (c2_i97 = 0; c2_i97 < 31; c2_i97++) {
    c2_u[c2_i97] = c2_varargin_1[c2_i97];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 31));
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c2_y));
}

static void c2_eml_integer_colon(SFc2_FruitInstanceStruct *chartInstance)
{
  c2_checkrange(chartInstance);
}

static void c2_checkrange(SFc2_FruitInstanceStruct *chartInstance)
{
}

static void c2_b_eml_integer_colon(SFc2_FruitInstanceStruct *chartInstance)
{
}

static void c2_meshgrid(SFc2_FruitInstanceStruct *chartInstance, real_T c2_x[640],
  real_T c2_y[480], real_T c2_xx[307200], real_T c2_yy[307200])
{
  int32_T c2_i98;
  real_T c2_a[640];
  int32_T c2_ia;
  int32_T c2_ib;
  int32_T c2_iacol;
  int32_T c2_jcol;
  int32_T c2_itilerow;
  int32_T c2_b_a;
  int32_T c2_c_a;
  int32_T c2_i99;
  real_T c2_d_a[480];
  int32_T c2_b_ib;
  int32_T c2_jtilecol;
  int32_T c2_b_ia;
  int32_T c2_k;
  int32_T c2_e_a;
  int32_T c2_f_a;
  for (c2_i98 = 0; c2_i98 < 640; c2_i98++) {
    c2_a[c2_i98] = c2_x[c2_i98];
  }

  c2_ia = 0;
  c2_ib = 1;
  c2_iacol = 0;
  for (c2_jcol = 1; c2_jcol < 641; c2_jcol++) {
    for (c2_itilerow = 1; c2_itilerow < 481; c2_itilerow++) {
      c2_ia = c2_iacol + 1;
      c2_xx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c2_ib), 1, 307200, 1, 0) - 1] = c2_a[_SFD_EML_ARRAY_BOUNDS_CHECK
        ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_ia), 1, 640, 1, 0) - 1];
      c2_b_a = c2_ia;
      c2_ia = c2_b_a;
      c2_c_a = c2_ib + 1;
      c2_ib = c2_c_a;
    }

    c2_iacol = c2_ia;
  }

  for (c2_i99 = 0; c2_i99 < 480; c2_i99++) {
    c2_d_a[c2_i99] = c2_y[c2_i99];
  }

  c2_b_ib = 1;
  for (c2_jtilecol = 1; c2_jtilecol < 641; c2_jtilecol++) {
    c2_b_ia = 1;
    for (c2_k = 1; c2_k < 481; c2_k++) {
      c2_yy[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c2_b_ib), 1, 307200, 1, 0) - 1] =
        c2_d_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c2_b_ia), 1, 480, 1, 0) - 1];
      c2_e_a = c2_b_ia + 1;
      c2_b_ia = c2_e_a;
      c2_f_a = c2_b_ib + 1;
      c2_b_ib = c2_f_a;
    }
  }
}

static void c2_b_power(SFc2_FruitInstanceStruct *chartInstance, real_T c2_a
  [307200], real_T c2_b, real_T c2_y[307200])
{
  real_T c2_k;
  real_T c2_b_k;
  real_T c2_ak;
  real_T c2_bk;
  real_T c2_x;
  real_T c2_b_x;
  for (c2_k = 1.0; c2_k <= 307200.0; c2_k++) {
    c2_b_k = c2_k;
    c2_ak = c2_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c2_b_k), 1, 307200, 1, 0) - 1];
    c2_bk = c2_b;
    if (c2_ak < 0.0) {
      c2_x = c2_bk;
      c2_b_x = c2_x;
      c2_b_x = muDoubleScalarFloor(c2_b_x);
      if (c2_b_x != c2_bk) {
        c2_eml_error(chartInstance);
      }
    }

    c2_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c2_b_k),
      1, 307200, 1, 0) - 1] = muDoubleScalarPower(c2_ak, c2_bk);
  }
}

static real_T c2_mpower(SFc2_FruitInstanceStruct *chartInstance, real_T c2_a)
{
  return c2_power(chartInstance, c2_a, 2.0);
}

static const mxArray *c2_k_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_FruitInstanceStruct *chartInstance;
  chartInstance = (SFc2_FruitInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static int32_T c2_h_emlrt_marshallIn(SFc2_FruitInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i100;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i100, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i100;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_FruitInstanceStruct *chartInstance;
  chartInstance = (SFc2_FruitInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_i_emlrt_marshallIn(SFc2_FruitInstanceStruct *chartInstance,
  const mxArray *c2_b_is_active_c2_Fruit, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_is_active_c2_Fruit),
    &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_Fruit);
  return c2_y;
}

static uint8_T c2_j_emlrt_marshallIn(SFc2_FruitInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_FruitInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_Fruit_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1043584068U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1052658210U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(244599023U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3869028720U);
}

mxArray *sf_c2_Fruit_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3322418514U);
    pr[1] = (double)(4293119050U);
    pr[2] = (double)(2118002308U);
    pr[3] = (double)(3687147018U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,3,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(15);
      pr[2] = (double)(3);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(480);
      pr[1] = (double)(640);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(480);
      pr[1] = (double)(640);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(480);
      pr[1] = (double)(640);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c2_Fruit(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[9],T\"bothHands\",},{M[1],M[5],T\"image1\",},{M[1],M[8],T\"image2\",},{M[8],M[0],T\"is_active_c2_Fruit\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_Fruit_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_FruitInstanceStruct *chartInstance;
    chartInstance = (SFc2_FruitInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_FruitMachineNumber_,
          2,
          1,
          1,
          5,
          0,
          0,
          0,
          0,
          2,
          &(chartInstance->chartNumber),
          &(chartInstance->instanceNumber),
          ssGetPath(S),
          (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_FruitMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_FruitMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_FruitMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"tracking");
          _SFD_SET_DATA_PROPS(1,2,0,1,"image1");
          _SFD_SET_DATA_PROPS(2,1,1,0,"skeleton");
          _SFD_SET_DATA_PROPS(3,2,0,1,"image2");
          _SFD_SET_DATA_PROPS(4,2,0,1,"bothHands");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,735);
        _SFD_CV_INIT_EML_IF(0,0,70,85,610,735);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"GetJointCoordinates",0,-1,135);
        _SFD_CV_INIT_SCRIPT(1,1,15,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"GetJointIndex",0,-1,1218);
        _SFD_CV_INIT_SCRIPT_IF(1,0,57,100,125,1217);
        _SFD_CV_INIT_SCRIPT_IF(1,1,125,172,193,1217);
        _SFD_CV_INIT_SCRIPT_IF(1,2,193,241,262,1217);
        _SFD_CV_INIT_SCRIPT_IF(1,3,262,318,339,1217);
        _SFD_CV_INIT_SCRIPT_IF(1,4,339,392,417,1217);
        _SFD_CV_INIT_SCRIPT_IF(1,5,417,469,490,1217);
        _SFD_CV_INIT_SCRIPT_IF(1,6,490,547,568,1217);
        _SFD_CV_INIT_SCRIPT_IF(1,7,568,622,643,1217);
        _SFD_CV_INIT_SCRIPT_IF(1,8,643,696,721,1217);
        _SFD_CV_INIT_SCRIPT_IF(1,9,721,774,802,1217);
        _SFD_CV_INIT_SCRIPT_IF(1,10,802,854,884,1217);
        _SFD_CV_INIT_SCRIPT_IF(1,11,884,936,958,1217);
        _SFD_CV_INIT_SCRIPT_IF(1,12,958,1012,1034,1217);
        _SFD_CV_INIT_SCRIPT_IF(1,13,1034,1087,1109,1217);
        _SFD_CV_INIT_SCRIPT_IF(1,14,1109,1162,1188,1217);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 480;
          dimVector[1]= 640;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          unsigned int dimVector[3];
          dimVector[0]= 1;
          dimVector[1]= 15;
          dimVector[2]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,3,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 480;
          dimVector[1]= 640;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 480;
          dimVector[1]= 640;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          boolean_T *c2_tracking;
          boolean_T (*c2_image1)[307200];
          real_T (*c2_skeleton)[45];
          boolean_T (*c2_image2)[307200];
          boolean_T (*c2_bothHands)[307200];
          c2_bothHands = (boolean_T (*)[307200])ssGetOutputPortSignal
            (chartInstance->S, 3);
          c2_image2 = (boolean_T (*)[307200])ssGetOutputPortSignal
            (chartInstance->S, 2);
          c2_skeleton = (real_T (*)[45])ssGetInputPortSignal(chartInstance->S, 1);
          c2_image1 = (boolean_T (*)[307200])ssGetOutputPortSignal
            (chartInstance->S, 1);
          c2_tracking = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_tracking);
          _SFD_SET_DATA_VALUE_PTR(1U, *c2_image1);
          _SFD_SET_DATA_VALUE_PTR(2U, *c2_skeleton);
          _SFD_SET_DATA_VALUE_PTR(3U, *c2_image2);
          _SFD_SET_DATA_VALUE_PTR(4U, *c2_bothHands);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_FruitMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c2_Fruit(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_FruitInstanceStruct*) chartInstanceVar)->S,0);
  initialize_params_c2_Fruit((SFc2_FruitInstanceStruct*) chartInstanceVar);
  initialize_c2_Fruit((SFc2_FruitInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_Fruit(void *chartInstanceVar)
{
  enable_c2_Fruit((SFc2_FruitInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_Fruit(void *chartInstanceVar)
{
  disable_c2_Fruit((SFc2_FruitInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_Fruit(void *chartInstanceVar)
{
  sf_c2_Fruit((SFc2_FruitInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_Fruit(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_Fruit((SFc2_FruitInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_Fruit();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c2_Fruit(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_Fruit();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_Fruit((SFc2_FruitInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_Fruit(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_Fruit(S);
}

static void sf_opaque_set_sim_state_c2_Fruit(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c2_Fruit(S, st);
}

static void sf_opaque_terminate_c2_Fruit(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_FruitInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_Fruit((SFc2_FruitInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_Fruit((SFc2_FruitInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_Fruit(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_Fruit((SFc2_FruitInstanceStruct*)(((ChartInfoStruct *)
      ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_Fruit(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"Fruit","Fruit",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"Fruit","Fruit",2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"Fruit","Fruit",2,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"Fruit","Fruit",2,2);
      sf_mark_chart_reusable_outputs(S,"Fruit","Fruit",2,3);
    }

    sf_set_rtw_dwork_info(S,"Fruit","Fruit",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(948129118U));
  ssSetChecksum1(S,(2771474618U));
  ssSetChecksum2(S,(2252287238U));
  ssSetChecksum3(S,(2033742373U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_Fruit(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "Fruit", "Fruit",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_Fruit(SimStruct *S)
{
  SFc2_FruitInstanceStruct *chartInstance;
  chartInstance = (SFc2_FruitInstanceStruct *)malloc(sizeof
    (SFc2_FruitInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_FruitInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_Fruit;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_Fruit;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_Fruit;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_Fruit;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_Fruit;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_Fruit;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_Fruit;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_Fruit;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_Fruit;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_Fruit;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_Fruit;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c2_Fruit_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_Fruit(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_Fruit(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_Fruit(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_Fruit_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
