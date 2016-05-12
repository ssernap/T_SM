/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Arti_DeltaSM_Angulos_sfun.h"
#include "c1_Arti_DeltaSM_Angulos.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Arti_DeltaSM_Angulos_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c1_debug_family_names[18] = { "i", "DesNorm", "nargin",
  "nargout", "Time", "TiempoAcu", "A1", "A2", "A3", "ThetaM1", "ThPM1", "ThPPM1",
  "ThetaM2", "ThPM2", "ThPPM2", "ThetaM3", "ThPM3", "ThPPM3" };

/* Function Declarations */
static void initialize_c1_Arti_DeltaSM_Angulos
  (SFc1_Arti_DeltaSM_AngulosInstanceStruct *chartInstance);
static void initialize_params_c1_Arti_DeltaSM_Angulos
  (SFc1_Arti_DeltaSM_AngulosInstanceStruct *chartInstance);
static void enable_c1_Arti_DeltaSM_Angulos
  (SFc1_Arti_DeltaSM_AngulosInstanceStruct *chartInstance);
static void disable_c1_Arti_DeltaSM_Angulos
  (SFc1_Arti_DeltaSM_AngulosInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_Arti_DeltaSM_Angulos
  (SFc1_Arti_DeltaSM_AngulosInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_Arti_DeltaSM_Angulos
  (SFc1_Arti_DeltaSM_AngulosInstanceStruct *chartInstance);
static void set_sim_state_c1_Arti_DeltaSM_Angulos
  (SFc1_Arti_DeltaSM_AngulosInstanceStruct *chartInstance, const mxArray *c1_st);
static void finalize_c1_Arti_DeltaSM_Angulos
  (SFc1_Arti_DeltaSM_AngulosInstanceStruct *chartInstance);
static void sf_gateway_c1_Arti_DeltaSM_Angulos
  (SFc1_Arti_DeltaSM_AngulosInstanceStruct *chartInstance);
static void c1_chartstep_c1_Arti_DeltaSM_Angulos
  (SFc1_Arti_DeltaSM_AngulosInstanceStruct *chartInstance);
static void initSimStructsc1_Arti_DeltaSM_Angulos
  (SFc1_Arti_DeltaSM_AngulosInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_Arti_DeltaSM_AngulosInstanceStruct
  *chartInstance, const mxArray *c1_ThPPM3, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_Arti_DeltaSM_AngulosInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_info_helper(const mxArray **c1_info);
static const mxArray *c1_emlrt_marshallOut(const char * c1_u);
static const mxArray *c1_b_emlrt_marshallOut(const uint32_T c1_u);
static real_T c1_polyval(SFc1_Arti_DeltaSM_AngulosInstanceStruct *chartInstance,
  real_T c1_p[6], real_T c1_x);
static void c1_polyder(SFc1_Arti_DeltaSM_AngulosInstanceStruct *chartInstance,
  real_T c1_u[6], real_T c1_a_data[], int32_T c1_a_sizes[2]);
static boolean_T c1_isfinite(SFc1_Arti_DeltaSM_AngulosInstanceStruct
  *chartInstance, real_T c1_x);
static real_T c1_b_polyval(SFc1_Arti_DeltaSM_AngulosInstanceStruct
  *chartInstance, real_T c1_p_data[], int32_T c1_p_sizes[2], real_T c1_x);
static void c1_b_polyder(SFc1_Arti_DeltaSM_AngulosInstanceStruct *chartInstance,
  real_T c1_u_data[], int32_T c1_u_sizes[2], real_T c1_a_data[], int32_T
  c1_a_sizes[2]);
static void c1_trim_leading_zeros(SFc1_Arti_DeltaSM_AngulosInstanceStruct
  *chartInstance, real_T c1_x_data[], int32_T c1_x_sizes[2], real_T c1_y_data[],
  int32_T c1_y_sizes[2]);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_c_emlrt_marshallIn(SFc1_Arti_DeltaSM_AngulosInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_d_emlrt_marshallIn(SFc1_Arti_DeltaSM_AngulosInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_Arti_DeltaSM_Angulos, const
  char_T *c1_identifier);
static uint8_T c1_e_emlrt_marshallIn(SFc1_Arti_DeltaSM_AngulosInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_Arti_DeltaSM_AngulosInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_Arti_DeltaSM_Angulos
  (SFc1_Arti_DeltaSM_AngulosInstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_is_active_c1_Arti_DeltaSM_Angulos = 0U;
}

static void initialize_params_c1_Arti_DeltaSM_Angulos
  (SFc1_Arti_DeltaSM_AngulosInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_Arti_DeltaSM_Angulos
  (SFc1_Arti_DeltaSM_AngulosInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_Arti_DeltaSM_Angulos
  (SFc1_Arti_DeltaSM_AngulosInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_update_debugger_state_c1_Arti_DeltaSM_Angulos
  (SFc1_Arti_DeltaSM_AngulosInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c1_Arti_DeltaSM_Angulos
  (SFc1_Arti_DeltaSM_AngulosInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_b_hoistedGlobal;
  real_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_c_hoistedGlobal;
  real_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  real_T c1_d_hoistedGlobal;
  real_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  real_T c1_e_hoistedGlobal;
  real_T c1_e_u;
  const mxArray *c1_f_y = NULL;
  real_T c1_f_hoistedGlobal;
  real_T c1_f_u;
  const mxArray *c1_g_y = NULL;
  real_T c1_g_hoistedGlobal;
  real_T c1_g_u;
  const mxArray *c1_h_y = NULL;
  real_T c1_h_hoistedGlobal;
  real_T c1_h_u;
  const mxArray *c1_i_y = NULL;
  real_T c1_i_hoistedGlobal;
  real_T c1_i_u;
  const mxArray *c1_j_y = NULL;
  uint8_T c1_j_hoistedGlobal;
  uint8_T c1_j_u;
  const mxArray *c1_k_y = NULL;
  real_T *c1_ThPM1;
  real_T *c1_ThPM2;
  real_T *c1_ThPM3;
  real_T *c1_ThPPM1;
  real_T *c1_ThPPM2;
  real_T *c1_ThPPM3;
  real_T *c1_ThetaM1;
  real_T *c1_ThetaM2;
  real_T *c1_ThetaM3;
  c1_ThPPM3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c1_ThPM3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c1_ThetaM3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c1_ThPPM2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_ThPM2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_ThetaM2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_ThPPM1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_ThPM1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_ThetaM1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(10, 1), false);
  c1_hoistedGlobal = *c1_ThPM1;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = *c1_ThPM2;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_hoistedGlobal = *c1_ThPM3;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_d_hoistedGlobal = *c1_ThPPM1;
  c1_d_u = c1_d_hoistedGlobal;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 3, c1_e_y);
  c1_e_hoistedGlobal = *c1_ThPPM2;
  c1_e_u = c1_e_hoistedGlobal;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 4, c1_f_y);
  c1_f_hoistedGlobal = *c1_ThPPM3;
  c1_f_u = c1_f_hoistedGlobal;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 5, c1_g_y);
  c1_g_hoistedGlobal = *c1_ThetaM1;
  c1_g_u = c1_g_hoistedGlobal;
  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 6, c1_h_y);
  c1_h_hoistedGlobal = *c1_ThetaM2;
  c1_h_u = c1_h_hoistedGlobal;
  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_create("y", &c1_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 7, c1_i_y);
  c1_i_hoistedGlobal = *c1_ThetaM3;
  c1_i_u = c1_i_hoistedGlobal;
  c1_j_y = NULL;
  sf_mex_assign(&c1_j_y, sf_mex_create("y", &c1_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 8, c1_j_y);
  c1_j_hoistedGlobal = chartInstance->c1_is_active_c1_Arti_DeltaSM_Angulos;
  c1_j_u = c1_j_hoistedGlobal;
  c1_k_y = NULL;
  sf_mex_assign(&c1_k_y, sf_mex_create("y", &c1_j_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 9, c1_k_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_Arti_DeltaSM_Angulos
  (SFc1_Arti_DeltaSM_AngulosInstanceStruct *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T *c1_ThPM1;
  real_T *c1_ThPM2;
  real_T *c1_ThPM3;
  real_T *c1_ThPPM1;
  real_T *c1_ThPPM2;
  real_T *c1_ThPPM3;
  real_T *c1_ThetaM1;
  real_T *c1_ThetaM2;
  real_T *c1_ThetaM3;
  c1_ThPPM3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c1_ThPM3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c1_ThetaM3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c1_ThPPM2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_ThPM2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_ThetaM2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_ThPPM1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_ThPM1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_ThetaM1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_u = sf_mex_dup(c1_st);
  *c1_ThPM1 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    0)), "ThPM1");
  *c1_ThPM2 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    1)), "ThPM2");
  *c1_ThPM3 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    2)), "ThPM3");
  *c1_ThPPM1 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    3)), "ThPPM1");
  *c1_ThPPM2 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    4)), "ThPPM2");
  *c1_ThPPM3 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    5)), "ThPPM3");
  *c1_ThetaM1 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 6)), "ThetaM1");
  *c1_ThetaM2 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 7)), "ThetaM2");
  *c1_ThetaM3 = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 8)), "ThetaM3");
  chartInstance->c1_is_active_c1_Arti_DeltaSM_Angulos = c1_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 9)),
     "is_active_c1_Arti_DeltaSM_Angulos");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_Arti_DeltaSM_Angulos(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_Arti_DeltaSM_Angulos
  (SFc1_Arti_DeltaSM_AngulosInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c1_Arti_DeltaSM_Angulos
  (SFc1_Arti_DeltaSM_AngulosInstanceStruct *chartInstance)
{
  int32_T c1_i0;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  real_T *c1_Time;
  real_T *c1_ThetaM1;
  real_T *c1_ThPM1;
  real_T *c1_ThPPM1;
  real_T *c1_ThetaM2;
  real_T *c1_ThPM2;
  real_T *c1_ThPPM2;
  real_T *c1_ThetaM3;
  real_T *c1_ThPM3;
  real_T *c1_ThPPM3;
  real_T (*c1_A3)[24];
  real_T (*c1_A2)[24];
  real_T (*c1_A1)[24];
  real_T (*c1_TiempoAcu)[5];
  c1_ThPPM3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c1_ThPM3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c1_A3 = (real_T (*)[24])ssGetInputPortSignal(chartInstance->S, 4);
  c1_A2 = (real_T (*)[24])ssGetInputPortSignal(chartInstance->S, 3);
  c1_A1 = (real_T (*)[24])ssGetInputPortSignal(chartInstance->S, 2);
  c1_TiempoAcu = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 1);
  c1_ThetaM3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c1_ThPPM2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_ThPM2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_ThetaM2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_ThPPM1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_ThPM1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_ThetaM1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_Time = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c1_Time, 0U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_Arti_DeltaSM_Angulos(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Arti_DeltaSM_AngulosMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*c1_ThetaM1, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_ThPM1, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_ThPPM1, 3U);
  _SFD_DATA_RANGE_CHECK(*c1_ThetaM2, 4U);
  _SFD_DATA_RANGE_CHECK(*c1_ThPM2, 5U);
  _SFD_DATA_RANGE_CHECK(*c1_ThPPM2, 6U);
  _SFD_DATA_RANGE_CHECK(*c1_ThetaM3, 7U);
  for (c1_i0 = 0; c1_i0 < 5; c1_i0++) {
    _SFD_DATA_RANGE_CHECK((*c1_TiempoAcu)[c1_i0], 8U);
  }

  for (c1_i1 = 0; c1_i1 < 24; c1_i1++) {
    _SFD_DATA_RANGE_CHECK((*c1_A1)[c1_i1], 9U);
  }

  for (c1_i2 = 0; c1_i2 < 24; c1_i2++) {
    _SFD_DATA_RANGE_CHECK((*c1_A2)[c1_i2], 10U);
  }

  for (c1_i3 = 0; c1_i3 < 24; c1_i3++) {
    _SFD_DATA_RANGE_CHECK((*c1_A3)[c1_i3], 11U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_ThPM3, 12U);
  _SFD_DATA_RANGE_CHECK(*c1_ThPPM3, 13U);
}

static void c1_chartstep_c1_Arti_DeltaSM_Angulos
  (SFc1_Arti_DeltaSM_AngulosInstanceStruct *chartInstance)
{
  real_T c1_hoistedGlobal;
  real_T c1_Time;
  int32_T c1_i4;
  real_T c1_TiempoAcu[5];
  int32_T c1_i5;
  real_T c1_A1[24];
  int32_T c1_i6;
  real_T c1_A2[24];
  int32_T c1_i7;
  real_T c1_A3[24];
  uint32_T c1_debug_family_var_map[18];
  real_T c1_i;
  real_T c1_DesNorm;
  real_T c1_nargin = 5.0;
  real_T c1_nargout = 9.0;
  real_T c1_ThetaM1;
  real_T c1_ThPM1;
  real_T c1_ThPPM1;
  real_T c1_ThetaM2;
  real_T c1_ThPM2;
  real_T c1_ThPPM2;
  real_T c1_ThetaM3;
  real_T c1_ThPM3;
  real_T c1_ThPPM3;
  real_T c1_A;
  real_T c1_B;
  real_T c1_x;
  real_T c1_y;
  real_T c1_b_x;
  real_T c1_b_y;
  real_T c1_c_x;
  real_T c1_c_y;
  real_T c1_d_y;
  int32_T c1_b_i;
  int32_T c1_i8;
  real_T c1_b_A1[6];
  real_T c1_b_A;
  real_T c1_b_B;
  real_T c1_d_x;
  real_T c1_e_y;
  real_T c1_e_x;
  real_T c1_f_y;
  real_T c1_f_x;
  real_T c1_g_y;
  real_T c1_h_y;
  int32_T c1_c_i;
  int32_T c1_i9;
  real_T c1_b_A2[6];
  real_T c1_c_A;
  real_T c1_c_B;
  real_T c1_g_x;
  real_T c1_i_y;
  real_T c1_h_x;
  real_T c1_j_y;
  real_T c1_i_x;
  real_T c1_k_y;
  real_T c1_l_y;
  int32_T c1_d_i;
  int32_T c1_i10;
  real_T c1_b_A3[6];
  real_T c1_d_A;
  real_T c1_d_B;
  real_T c1_j_x;
  real_T c1_m_y;
  real_T c1_k_x;
  real_T c1_n_y;
  real_T c1_l_x;
  real_T c1_o_y;
  real_T c1_p_y;
  int32_T c1_e_i;
  int32_T c1_i11;
  real_T c1_c_A1[6];
  int32_T c1_tmp_sizes[2];
  real_T c1_tmp_data[5];
  int32_T c1_b_tmp_sizes[2];
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_loop_ub;
  int32_T c1_i14;
  real_T c1_b_tmp_data[5];
  real_T c1_e_A;
  real_T c1_e_B;
  real_T c1_m_x;
  real_T c1_q_y;
  real_T c1_n_x;
  real_T c1_r_y;
  real_T c1_o_x;
  real_T c1_s_y;
  real_T c1_t_y;
  int32_T c1_f_i;
  int32_T c1_i15;
  real_T c1_c_A2[6];
  int32_T c1_c_tmp_sizes[2];
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_b_loop_ub;
  int32_T c1_i18;
  real_T c1_c_tmp_data[5];
  real_T c1_f_A;
  real_T c1_f_B;
  real_T c1_p_x;
  real_T c1_u_y;
  real_T c1_q_x;
  real_T c1_v_y;
  real_T c1_r_x;
  real_T c1_w_y;
  real_T c1_x_y;
  int32_T c1_g_i;
  int32_T c1_i19;
  real_T c1_c_A3[6];
  int32_T c1_d_tmp_sizes[2];
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_c_loop_ub;
  int32_T c1_i22;
  real_T c1_d_tmp_data[5];
  real_T c1_g_A;
  real_T c1_g_B;
  real_T c1_s_x;
  real_T c1_y_y;
  real_T c1_t_x;
  real_T c1_ab_y;
  real_T c1_u_x;
  real_T c1_bb_y;
  real_T c1_cb_y;
  int32_T c1_h_i;
  int32_T c1_i23;
  real_T c1_d_A1[6];
  int32_T c1_e_tmp_sizes[2];
  int32_T c1_i24;
  int32_T c1_i25;
  int32_T c1_d_loop_ub;
  int32_T c1_i26;
  real_T c1_e_tmp_data[5];
  int32_T c1_f_tmp_sizes[2];
  real_T c1_f_tmp_data[4];
  int32_T c1_g_tmp_sizes[2];
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_e_loop_ub;
  int32_T c1_i29;
  real_T c1_g_tmp_data[4];
  real_T c1_h_A;
  real_T c1_h_B;
  real_T c1_v_x;
  real_T c1_db_y;
  real_T c1_w_x;
  real_T c1_eb_y;
  real_T c1_x_x;
  real_T c1_fb_y;
  real_T c1_gb_y;
  int32_T c1_i_i;
  int32_T c1_i30;
  real_T c1_d_A2[6];
  int32_T c1_h_tmp_sizes[2];
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_f_loop_ub;
  int32_T c1_i33;
  real_T c1_h_tmp_data[5];
  int32_T c1_i_tmp_sizes[2];
  int32_T c1_i34;
  int32_T c1_i35;
  int32_T c1_g_loop_ub;
  int32_T c1_i36;
  real_T c1_i_tmp_data[4];
  real_T c1_i_A;
  real_T c1_i_B;
  real_T c1_y_x;
  real_T c1_hb_y;
  real_T c1_ab_x;
  real_T c1_ib_y;
  real_T c1_bb_x;
  real_T c1_jb_y;
  real_T c1_kb_y;
  int32_T c1_j_i;
  int32_T c1_i37;
  real_T c1_d_A3[6];
  int32_T c1_j_tmp_sizes[2];
  int32_T c1_i38;
  int32_T c1_i39;
  int32_T c1_h_loop_ub;
  int32_T c1_i40;
  real_T c1_j_tmp_data[5];
  int32_T c1_k_tmp_sizes[2];
  int32_T c1_i41;
  int32_T c1_i42;
  int32_T c1_i_loop_ub;
  int32_T c1_i43;
  real_T c1_k_tmp_data[4];
  real_T *c1_b_ThPPM3;
  real_T *c1_b_ThPM3;
  real_T *c1_b_ThetaM3;
  real_T *c1_b_ThPPM2;
  real_T *c1_b_ThPM2;
  real_T *c1_b_ThetaM2;
  real_T *c1_b_ThPPM1;
  real_T *c1_b_ThPM1;
  real_T *c1_b_ThetaM1;
  real_T *c1_b_Time;
  real_T (*c1_e_A3)[24];
  real_T (*c1_e_A2)[24];
  real_T (*c1_e_A1)[24];
  real_T (*c1_b_TiempoAcu)[5];
  c1_b_ThPPM3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c1_b_ThPM3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c1_e_A3 = (real_T (*)[24])ssGetInputPortSignal(chartInstance->S, 4);
  c1_e_A2 = (real_T (*)[24])ssGetInputPortSignal(chartInstance->S, 3);
  c1_e_A1 = (real_T (*)[24])ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_TiempoAcu = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_ThetaM3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c1_b_ThPPM2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c1_b_ThPM2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c1_b_ThetaM2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c1_b_ThPPM1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c1_b_ThPM1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_ThetaM1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_Time = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_Time;
  c1_Time = c1_hoistedGlobal;
  for (c1_i4 = 0; c1_i4 < 5; c1_i4++) {
    c1_TiempoAcu[c1_i4] = (*c1_b_TiempoAcu)[c1_i4];
  }

  for (c1_i5 = 0; c1_i5 < 24; c1_i5++) {
    c1_A1[c1_i5] = (*c1_e_A1)[c1_i5];
  }

  for (c1_i6 = 0; c1_i6 < 24; c1_i6++) {
    c1_A2[c1_i6] = (*c1_e_A2)[c1_i6];
  }

  for (c1_i7 = 0; c1_i7 < 24; c1_i7++) {
    c1_A3[c1_i7] = (*c1_e_A3)[c1_i7];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 18U, 18U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_DesNorm, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 2U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 3U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_Time, 4U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_TiempoAcu, 5U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_A1, 6U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_A2, 7U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_A3, 8U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ThetaM1, 9U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ThPM1, 10U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ThPPM1, 11U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ThetaM2, 12U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ThPM2, 13U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ThPPM2, 14U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ThetaM3, 15U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ThPM3, 16U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ThPPM3, 17U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_i = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  while (CV_EML_WHILE(0, 1, 0, c1_Time >
                      c1_TiempoAcu[_SFD_EML_ARRAY_BOUNDS_CHECK("TiempoAcu",
           (int32_T)c1_i, 1, 5, 1, 0) - 1])) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 6);
    c1_i++;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_i--;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 9);
  if (CV_EML_IF(0, 1, 0, c1_i == 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 10);
    c1_i = 1.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 12);
  c1_DesNorm = c1_TiempoAcu[_SFD_EML_ARRAY_BOUNDS_CHECK("TiempoAcu", (int32_T)
    (c1_i + 1.0), 1, 5, 1, 0) - 1] - c1_TiempoAcu[_SFD_EML_ARRAY_BOUNDS_CHECK(
    "TiempoAcu", (int32_T)c1_i, 1, 5, 1, 0) - 1];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
  c1_A = c1_Time - c1_TiempoAcu[(int32_T)c1_i - 1];
  c1_B = c1_DesNorm;
  c1_x = c1_A;
  c1_y = c1_B;
  c1_b_x = c1_x;
  c1_b_y = c1_y;
  c1_c_x = c1_b_x;
  c1_c_y = c1_b_y;
  c1_d_y = c1_c_x / c1_c_y;
  c1_b_i = _SFD_EML_ARRAY_BOUNDS_CHECK("A1", (int32_T)c1_i, 1, 4, 1, 0) - 1;
  for (c1_i8 = 0; c1_i8 < 6; c1_i8++) {
    c1_b_A1[c1_i8] = c1_A1[c1_b_i + (c1_i8 << 2)];
  }

  c1_ThetaM1 = c1_polyval(chartInstance, c1_b_A1, c1_d_y);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 15);
  c1_b_A = c1_Time - c1_TiempoAcu[(int32_T)c1_i - 1];
  c1_b_B = c1_DesNorm;
  c1_d_x = c1_b_A;
  c1_e_y = c1_b_B;
  c1_e_x = c1_d_x;
  c1_f_y = c1_e_y;
  c1_f_x = c1_e_x;
  c1_g_y = c1_f_y;
  c1_h_y = c1_f_x / c1_g_y;
  c1_c_i = (int32_T)c1_i - 1;
  for (c1_i9 = 0; c1_i9 < 6; c1_i9++) {
    c1_b_A2[c1_i9] = c1_A2[c1_c_i + (c1_i9 << 2)];
  }

  c1_ThetaM2 = c1_polyval(chartInstance, c1_b_A2, c1_h_y);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 16);
  c1_c_A = c1_Time - c1_TiempoAcu[(int32_T)c1_i - 1];
  c1_c_B = c1_DesNorm;
  c1_g_x = c1_c_A;
  c1_i_y = c1_c_B;
  c1_h_x = c1_g_x;
  c1_j_y = c1_i_y;
  c1_i_x = c1_h_x;
  c1_k_y = c1_j_y;
  c1_l_y = c1_i_x / c1_k_y;
  c1_d_i = (int32_T)c1_i - 1;
  for (c1_i10 = 0; c1_i10 < 6; c1_i10++) {
    c1_b_A3[c1_i10] = c1_A3[c1_d_i + (c1_i10 << 2)];
  }

  c1_ThetaM3 = -c1_polyval(chartInstance, c1_b_A3, c1_l_y);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 18);
  c1_d_A = c1_Time - c1_TiempoAcu[(int32_T)c1_i - 1];
  c1_d_B = c1_DesNorm;
  c1_j_x = c1_d_A;
  c1_m_y = c1_d_B;
  c1_k_x = c1_j_x;
  c1_n_y = c1_m_y;
  c1_l_x = c1_k_x;
  c1_o_y = c1_n_y;
  c1_p_y = c1_l_x / c1_o_y;
  c1_e_i = (int32_T)c1_i - 1;
  for (c1_i11 = 0; c1_i11 < 6; c1_i11++) {
    c1_c_A1[c1_i11] = c1_A1[c1_e_i + (c1_i11 << 2)];
  }

  c1_polyder(chartInstance, c1_c_A1, c1_tmp_data, c1_tmp_sizes);
  c1_b_tmp_sizes[0] = 1;
  c1_b_tmp_sizes[1] = c1_tmp_sizes[1];
  c1_i12 = c1_b_tmp_sizes[0];
  c1_i13 = c1_b_tmp_sizes[1];
  c1_loop_ub = c1_tmp_sizes[0] * c1_tmp_sizes[1] - 1;
  for (c1_i14 = 0; c1_i14 <= c1_loop_ub; c1_i14++) {
    c1_b_tmp_data[c1_i14] = c1_tmp_data[c1_i14];
  }

  c1_ThPM1 = c1_b_polyval(chartInstance, c1_b_tmp_data, c1_b_tmp_sizes, c1_p_y);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 19);
  c1_e_A = c1_Time - c1_TiempoAcu[(int32_T)c1_i - 1];
  c1_e_B = c1_DesNorm;
  c1_m_x = c1_e_A;
  c1_q_y = c1_e_B;
  c1_n_x = c1_m_x;
  c1_r_y = c1_q_y;
  c1_o_x = c1_n_x;
  c1_s_y = c1_r_y;
  c1_t_y = c1_o_x / c1_s_y;
  c1_f_i = (int32_T)c1_i - 1;
  for (c1_i15 = 0; c1_i15 < 6; c1_i15++) {
    c1_c_A2[c1_i15] = c1_A2[c1_f_i + (c1_i15 << 2)];
  }

  c1_polyder(chartInstance, c1_c_A2, c1_tmp_data, c1_tmp_sizes);
  c1_c_tmp_sizes[0] = 1;
  c1_c_tmp_sizes[1] = c1_tmp_sizes[1];
  c1_i16 = c1_c_tmp_sizes[0];
  c1_i17 = c1_c_tmp_sizes[1];
  c1_b_loop_ub = c1_tmp_sizes[0] * c1_tmp_sizes[1] - 1;
  for (c1_i18 = 0; c1_i18 <= c1_b_loop_ub; c1_i18++) {
    c1_c_tmp_data[c1_i18] = c1_tmp_data[c1_i18];
  }

  c1_ThPM2 = c1_b_polyval(chartInstance, c1_c_tmp_data, c1_c_tmp_sizes, c1_t_y);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 20);
  c1_f_A = c1_Time - c1_TiempoAcu[(int32_T)c1_i - 1];
  c1_f_B = c1_DesNorm;
  c1_p_x = c1_f_A;
  c1_u_y = c1_f_B;
  c1_q_x = c1_p_x;
  c1_v_y = c1_u_y;
  c1_r_x = c1_q_x;
  c1_w_y = c1_v_y;
  c1_x_y = c1_r_x / c1_w_y;
  c1_g_i = (int32_T)c1_i - 1;
  for (c1_i19 = 0; c1_i19 < 6; c1_i19++) {
    c1_c_A3[c1_i19] = c1_A3[c1_g_i + (c1_i19 << 2)];
  }

  c1_polyder(chartInstance, c1_c_A3, c1_tmp_data, c1_tmp_sizes);
  c1_d_tmp_sizes[0] = 1;
  c1_d_tmp_sizes[1] = c1_tmp_sizes[1];
  c1_i20 = c1_d_tmp_sizes[0];
  c1_i21 = c1_d_tmp_sizes[1];
  c1_c_loop_ub = c1_tmp_sizes[0] * c1_tmp_sizes[1] - 1;
  for (c1_i22 = 0; c1_i22 <= c1_c_loop_ub; c1_i22++) {
    c1_d_tmp_data[c1_i22] = c1_tmp_data[c1_i22];
  }

  c1_ThPM3 = -c1_b_polyval(chartInstance, c1_d_tmp_data, c1_d_tmp_sizes, c1_x_y);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 22);
  c1_g_A = c1_Time - c1_TiempoAcu[(int32_T)c1_i - 1];
  c1_g_B = c1_DesNorm;
  c1_s_x = c1_g_A;
  c1_y_y = c1_g_B;
  c1_t_x = c1_s_x;
  c1_ab_y = c1_y_y;
  c1_u_x = c1_t_x;
  c1_bb_y = c1_ab_y;
  c1_cb_y = c1_u_x / c1_bb_y;
  c1_h_i = (int32_T)c1_i - 1;
  for (c1_i23 = 0; c1_i23 < 6; c1_i23++) {
    c1_d_A1[c1_i23] = c1_A1[c1_h_i + (c1_i23 << 2)];
  }

  c1_polyder(chartInstance, c1_d_A1, c1_tmp_data, c1_tmp_sizes);
  c1_e_tmp_sizes[0] = 1;
  c1_e_tmp_sizes[1] = c1_tmp_sizes[1];
  c1_i24 = c1_e_tmp_sizes[0];
  c1_i25 = c1_e_tmp_sizes[1];
  c1_d_loop_ub = c1_tmp_sizes[0] * c1_tmp_sizes[1] - 1;
  for (c1_i26 = 0; c1_i26 <= c1_d_loop_ub; c1_i26++) {
    c1_e_tmp_data[c1_i26] = c1_tmp_data[c1_i26];
  }

  c1_b_polyder(chartInstance, c1_e_tmp_data, c1_e_tmp_sizes, c1_f_tmp_data,
               c1_f_tmp_sizes);
  c1_g_tmp_sizes[0] = 1;
  c1_g_tmp_sizes[1] = c1_f_tmp_sizes[1];
  c1_i27 = c1_g_tmp_sizes[0];
  c1_i28 = c1_g_tmp_sizes[1];
  c1_e_loop_ub = c1_f_tmp_sizes[0] * c1_f_tmp_sizes[1] - 1;
  for (c1_i29 = 0; c1_i29 <= c1_e_loop_ub; c1_i29++) {
    c1_g_tmp_data[c1_i29] = c1_f_tmp_data[c1_i29];
  }

  c1_ThPPM1 = c1_b_polyval(chartInstance, c1_g_tmp_data, c1_g_tmp_sizes, c1_cb_y);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 23);
  c1_h_A = c1_Time - c1_TiempoAcu[(int32_T)c1_i - 1];
  c1_h_B = c1_DesNorm;
  c1_v_x = c1_h_A;
  c1_db_y = c1_h_B;
  c1_w_x = c1_v_x;
  c1_eb_y = c1_db_y;
  c1_x_x = c1_w_x;
  c1_fb_y = c1_eb_y;
  c1_gb_y = c1_x_x / c1_fb_y;
  c1_i_i = (int32_T)c1_i - 1;
  for (c1_i30 = 0; c1_i30 < 6; c1_i30++) {
    c1_d_A2[c1_i30] = c1_A2[c1_i_i + (c1_i30 << 2)];
  }

  c1_polyder(chartInstance, c1_d_A2, c1_tmp_data, c1_tmp_sizes);
  c1_h_tmp_sizes[0] = 1;
  c1_h_tmp_sizes[1] = c1_tmp_sizes[1];
  c1_i31 = c1_h_tmp_sizes[0];
  c1_i32 = c1_h_tmp_sizes[1];
  c1_f_loop_ub = c1_tmp_sizes[0] * c1_tmp_sizes[1] - 1;
  for (c1_i33 = 0; c1_i33 <= c1_f_loop_ub; c1_i33++) {
    c1_h_tmp_data[c1_i33] = c1_tmp_data[c1_i33];
  }

  c1_b_polyder(chartInstance, c1_h_tmp_data, c1_h_tmp_sizes, c1_f_tmp_data,
               c1_f_tmp_sizes);
  c1_i_tmp_sizes[0] = 1;
  c1_i_tmp_sizes[1] = c1_f_tmp_sizes[1];
  c1_i34 = c1_i_tmp_sizes[0];
  c1_i35 = c1_i_tmp_sizes[1];
  c1_g_loop_ub = c1_f_tmp_sizes[0] * c1_f_tmp_sizes[1] - 1;
  for (c1_i36 = 0; c1_i36 <= c1_g_loop_ub; c1_i36++) {
    c1_i_tmp_data[c1_i36] = c1_f_tmp_data[c1_i36];
  }

  c1_ThPPM2 = c1_b_polyval(chartInstance, c1_i_tmp_data, c1_i_tmp_sizes, c1_gb_y);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 24);
  c1_i_A = c1_Time - c1_TiempoAcu[(int32_T)c1_i - 1];
  c1_i_B = c1_DesNorm;
  c1_y_x = c1_i_A;
  c1_hb_y = c1_i_B;
  c1_ab_x = c1_y_x;
  c1_ib_y = c1_hb_y;
  c1_bb_x = c1_ab_x;
  c1_jb_y = c1_ib_y;
  c1_kb_y = c1_bb_x / c1_jb_y;
  c1_j_i = (int32_T)c1_i - 1;
  for (c1_i37 = 0; c1_i37 < 6; c1_i37++) {
    c1_d_A3[c1_i37] = c1_A3[c1_j_i + (c1_i37 << 2)];
  }

  c1_polyder(chartInstance, c1_d_A3, c1_tmp_data, c1_tmp_sizes);
  c1_j_tmp_sizes[0] = 1;
  c1_j_tmp_sizes[1] = c1_tmp_sizes[1];
  c1_i38 = c1_j_tmp_sizes[0];
  c1_i39 = c1_j_tmp_sizes[1];
  c1_h_loop_ub = c1_tmp_sizes[0] * c1_tmp_sizes[1] - 1;
  for (c1_i40 = 0; c1_i40 <= c1_h_loop_ub; c1_i40++) {
    c1_j_tmp_data[c1_i40] = c1_tmp_data[c1_i40];
  }

  c1_b_polyder(chartInstance, c1_j_tmp_data, c1_j_tmp_sizes, c1_f_tmp_data,
               c1_f_tmp_sizes);
  c1_k_tmp_sizes[0] = 1;
  c1_k_tmp_sizes[1] = c1_f_tmp_sizes[1];
  c1_i41 = c1_k_tmp_sizes[0];
  c1_i42 = c1_k_tmp_sizes[1];
  c1_i_loop_ub = c1_f_tmp_sizes[0] * c1_f_tmp_sizes[1] - 1;
  for (c1_i43 = 0; c1_i43 <= c1_i_loop_ub; c1_i43++) {
    c1_k_tmp_data[c1_i43] = c1_f_tmp_data[c1_i43];
  }

  c1_ThPPM3 = -c1_b_polyval(chartInstance, c1_k_tmp_data, c1_k_tmp_sizes,
    c1_kb_y);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -24);
  _SFD_SYMBOL_SCOPE_POP();
  *c1_b_ThetaM1 = c1_ThetaM1;
  *c1_b_ThPM1 = c1_ThPM1;
  *c1_b_ThPPM1 = c1_ThPPM1;
  *c1_b_ThetaM2 = c1_ThetaM2;
  *c1_b_ThPM2 = c1_ThPM2;
  *c1_b_ThPPM2 = c1_ThPPM2;
  *c1_b_ThetaM3 = c1_ThetaM3;
  *c1_b_ThPM3 = c1_ThPM3;
  *c1_b_ThPPM3 = c1_ThPPM3;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_Arti_DeltaSM_Angulos
  (SFc1_Arti_DeltaSM_AngulosInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber)
{
  (void)c1_machineNumber;
  (void)c1_chartNumber;
  (void)c1_instanceNumber;
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_Arti_DeltaSM_AngulosInstanceStruct *chartInstance;
  chartInstance = (SFc1_Arti_DeltaSM_AngulosInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_Arti_DeltaSM_AngulosInstanceStruct
  *chartInstance, const mxArray *c1_ThPPM3, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_ThPPM3), &c1_thisId);
  sf_mex_destroy(&c1_ThPPM3);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_Arti_DeltaSM_AngulosInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_ThPPM3;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_Arti_DeltaSM_AngulosInstanceStruct *chartInstance;
  chartInstance = (SFc1_Arti_DeltaSM_AngulosInstanceStruct *)chartInstanceVoid;
  c1_ThPPM3 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_ThPPM3), &c1_thisId);
  sf_mex_destroy(&c1_ThPPM3);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i44;
  int32_T c1_i45;
  int32_T c1_i46;
  real_T c1_b_inData[24];
  int32_T c1_i47;
  int32_T c1_i48;
  int32_T c1_i49;
  real_T c1_u[24];
  const mxArray *c1_y = NULL;
  SFc1_Arti_DeltaSM_AngulosInstanceStruct *chartInstance;
  chartInstance = (SFc1_Arti_DeltaSM_AngulosInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i44 = 0;
  for (c1_i45 = 0; c1_i45 < 6; c1_i45++) {
    for (c1_i46 = 0; c1_i46 < 4; c1_i46++) {
      c1_b_inData[c1_i46 + c1_i44] = (*(real_T (*)[24])c1_inData)[c1_i46 +
        c1_i44];
    }

    c1_i44 += 4;
  }

  c1_i47 = 0;
  for (c1_i48 = 0; c1_i48 < 6; c1_i48++) {
    for (c1_i49 = 0; c1_i49 < 4; c1_i49++) {
      c1_u[c1_i49 + c1_i47] = c1_b_inData[c1_i49 + c1_i47];
    }

    c1_i47 += 4;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 4, 6), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i50;
  real_T c1_b_inData[5];
  int32_T c1_i51;
  real_T c1_u[5];
  const mxArray *c1_y = NULL;
  SFc1_Arti_DeltaSM_AngulosInstanceStruct *chartInstance;
  chartInstance = (SFc1_Arti_DeltaSM_AngulosInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i50 = 0; c1_i50 < 5; c1_i50++) {
    c1_b_inData[c1_i50] = (*(real_T (*)[5])c1_inData)[c1_i50];
  }

  for (c1_i51 = 0; c1_i51 < 5; c1_i51++) {
    c1_u[c1_i51] = c1_b_inData[c1_i51];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 5), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

const mxArray *sf_c1_Arti_DeltaSM_Angulos_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_createstruct("structure", 2, 23, 1),
                false);
  c1_info_helper(&c1_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(const mxArray **c1_info)
{
  const mxArray *c1_rhs0 = NULL;
  const mxArray *c1_lhs0 = NULL;
  const mxArray *c1_rhs1 = NULL;
  const mxArray *c1_lhs1 = NULL;
  const mxArray *c1_rhs2 = NULL;
  const mxArray *c1_lhs2 = NULL;
  const mxArray *c1_rhs3 = NULL;
  const mxArray *c1_lhs3 = NULL;
  const mxArray *c1_rhs4 = NULL;
  const mxArray *c1_lhs4 = NULL;
  const mxArray *c1_rhs5 = NULL;
  const mxArray *c1_lhs5 = NULL;
  const mxArray *c1_rhs6 = NULL;
  const mxArray *c1_lhs6 = NULL;
  const mxArray *c1_rhs7 = NULL;
  const mxArray *c1_lhs7 = NULL;
  const mxArray *c1_rhs8 = NULL;
  const mxArray *c1_lhs8 = NULL;
  const mxArray *c1_rhs9 = NULL;
  const mxArray *c1_lhs9 = NULL;
  const mxArray *c1_rhs10 = NULL;
  const mxArray *c1_lhs10 = NULL;
  const mxArray *c1_rhs11 = NULL;
  const mxArray *c1_lhs11 = NULL;
  const mxArray *c1_rhs12 = NULL;
  const mxArray *c1_lhs12 = NULL;
  const mxArray *c1_rhs13 = NULL;
  const mxArray *c1_lhs13 = NULL;
  const mxArray *c1_rhs14 = NULL;
  const mxArray *c1_lhs14 = NULL;
  const mxArray *c1_rhs15 = NULL;
  const mxArray *c1_lhs15 = NULL;
  const mxArray *c1_rhs16 = NULL;
  const mxArray *c1_lhs16 = NULL;
  const mxArray *c1_rhs17 = NULL;
  const mxArray *c1_lhs17 = NULL;
  const mxArray *c1_rhs18 = NULL;
  const mxArray *c1_lhs18 = NULL;
  const mxArray *c1_rhs19 = NULL;
  const mxArray *c1_lhs19 = NULL;
  const mxArray *c1_rhs20 = NULL;
  const mxArray *c1_lhs20 = NULL;
  const mxArray *c1_rhs21 = NULL;
  const mxArray *c1_lhs21 = NULL;
  const mxArray *c1_rhs22 = NULL;
  const mxArray *c1_lhs22 = NULL;
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("mrdivide"), "name", "name", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1388463696U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1370017086U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c1_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c1_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363717480U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c1_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c1_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286825996U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c1_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c1_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1389311520U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c1_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("polyval"), "name", "name", 7);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/polyval.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1305325202U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c1_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/polyval.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 8);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c1_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 9);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1389311520U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c1_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 10);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("polyder"), "name", "name", 10);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/polyder.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1378303192U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c1_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/polyder.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 11);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c1_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/polyder.m!trim_leading_zeros"),
                  "context", "context", 12);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 12);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c1_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 13);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("intmax"), "name", "name", 13);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1362265482U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c1_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 14);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1381857500U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c1_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/polyder.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 15);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1375987888U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c1_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/polyder.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("isfinite"), "name", "name", 16);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363717456U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c1_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 17);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c1_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("isinf"), "name", "name", 18);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363717456U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c1_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 19);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c1_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("isnan"), "name", "name", 20);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363717458U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c1_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 21);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c1_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/polyfun/polyder.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("coder.internal.nan"), "name",
                  "name", 22);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/nan.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1362265632U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c1_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs22), "lhs", "lhs",
                  22);
  sf_mex_destroy(&c1_rhs0);
  sf_mex_destroy(&c1_lhs0);
  sf_mex_destroy(&c1_rhs1);
  sf_mex_destroy(&c1_lhs1);
  sf_mex_destroy(&c1_rhs2);
  sf_mex_destroy(&c1_lhs2);
  sf_mex_destroy(&c1_rhs3);
  sf_mex_destroy(&c1_lhs3);
  sf_mex_destroy(&c1_rhs4);
  sf_mex_destroy(&c1_lhs4);
  sf_mex_destroy(&c1_rhs5);
  sf_mex_destroy(&c1_lhs5);
  sf_mex_destroy(&c1_rhs6);
  sf_mex_destroy(&c1_lhs6);
  sf_mex_destroy(&c1_rhs7);
  sf_mex_destroy(&c1_lhs7);
  sf_mex_destroy(&c1_rhs8);
  sf_mex_destroy(&c1_lhs8);
  sf_mex_destroy(&c1_rhs9);
  sf_mex_destroy(&c1_lhs9);
  sf_mex_destroy(&c1_rhs10);
  sf_mex_destroy(&c1_lhs10);
  sf_mex_destroy(&c1_rhs11);
  sf_mex_destroy(&c1_lhs11);
  sf_mex_destroy(&c1_rhs12);
  sf_mex_destroy(&c1_lhs12);
  sf_mex_destroy(&c1_rhs13);
  sf_mex_destroy(&c1_lhs13);
  sf_mex_destroy(&c1_rhs14);
  sf_mex_destroy(&c1_lhs14);
  sf_mex_destroy(&c1_rhs15);
  sf_mex_destroy(&c1_lhs15);
  sf_mex_destroy(&c1_rhs16);
  sf_mex_destroy(&c1_lhs16);
  sf_mex_destroy(&c1_rhs17);
  sf_mex_destroy(&c1_lhs17);
  sf_mex_destroy(&c1_rhs18);
  sf_mex_destroy(&c1_lhs18);
  sf_mex_destroy(&c1_rhs19);
  sf_mex_destroy(&c1_lhs19);
  sf_mex_destroy(&c1_rhs20);
  sf_mex_destroy(&c1_lhs20);
  sf_mex_destroy(&c1_rhs21);
  sf_mex_destroy(&c1_lhs21);
  sf_mex_destroy(&c1_rhs22);
  sf_mex_destroy(&c1_lhs22);
}

static const mxArray *c1_emlrt_marshallOut(const char * c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c1_u)), false);
  return c1_y;
}

static const mxArray *c1_b_emlrt_marshallOut(const uint32_T c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 7, 0U, 0U, 0U, 0), false);
  return c1_y;
}

static real_T c1_polyval(SFc1_Arti_DeltaSM_AngulosInstanceStruct *chartInstance,
  real_T c1_p[6], real_T c1_x)
{
  real_T c1_y;
  int32_T c1_k;
  real_T c1_b_k;
  (void)chartInstance;
  c1_y = c1_p[0];
  for (c1_k = 0; c1_k < 5; c1_k++) {
    c1_b_k = 2.0 + (real_T)c1_k;
    c1_y = c1_x * c1_y + c1_p[(int32_T)c1_b_k - 1];
  }

  return c1_y;
}

static void c1_polyder(SFc1_Arti_DeltaSM_AngulosInstanceStruct *chartInstance,
  real_T c1_u[6], real_T c1_a_data[], int32_T c1_a_sizes[2])
{
  int32_T c1_nlead0;
  int32_T c1_k;
  int32_T c1_b_k;
  int32_T c1_ny;
  const mxArray *c1_y = NULL;
  int32_T c1_tmp_sizes[2];
  int32_T c1_iv0[2];
  int32_T c1_i52;
  int32_T c1_i53;
  int32_T c1_loop_ub;
  int32_T c1_i54;
  real_T c1_tmp_data[5];
  int32_T c1_i55;
  int32_T c1_b_ny;
  int32_T c1_c_k;
  int32_T c1_n;
  int32_T c1_i56;
  int32_T c1_d_k;
  int32_T c1_e_k;
  boolean_T exitg1;
  c1_nlead0 = 0;
  c1_k = 1;
  exitg1 = false;
  while ((exitg1 == false) && (c1_k < 5)) {
    c1_b_k = c1_k - 1;
    if (c1_u[c1_b_k] == 0.0) {
      c1_nlead0++;
      c1_k++;
    } else {
      exitg1 = true;
    }
  }

  c1_ny = 5 - c1_nlead0;
  if (c1_ny <= 5) {
  } else {
    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", "Assertion failed.", 15, 0U, 0U, 0U,
      2, 1, strlen("Assertion failed.")), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14, c1_y);
  }

  c1_tmp_sizes[0] = 1;
  c1_iv0[0] = 1;
  c1_iv0[1] = (int32_T)_SFD_NON_NEGATIVE_CHECK("", (real_T)c1_ny);
  c1_tmp_sizes[1] = c1_iv0[1];
  c1_i52 = c1_tmp_sizes[0];
  c1_i53 = c1_tmp_sizes[1];
  c1_loop_ub = (int32_T)_SFD_NON_NEGATIVE_CHECK("", (real_T)c1_ny) - 1;
  for (c1_i54 = 0; c1_i54 <= c1_loop_ub; c1_i54++) {
    c1_tmp_data[c1_i54] = 0.0;
  }

  for (c1_i55 = 0; c1_i55 < 2; c1_i55++) {
    c1_a_sizes[c1_i55] = c1_tmp_sizes[c1_i55];
  }

  c1_b_ny = c1_ny;
  for (c1_c_k = 1; c1_c_k <= c1_b_ny; c1_c_k++) {
    c1_b_k = c1_c_k;
    c1_a_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_b_k, 1, c1_a_sizes[1], 1, 0) -
      1] = c1_u[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_b_k + c1_nlead0, 1, 6, 1, 0)
      - 1];
  }

  c1_n = c1_a_sizes[1] - 1;
  c1_i56 = c1_n;
  for (c1_d_k = 1; c1_d_k <= c1_i56; c1_d_k++) {
    c1_e_k = c1_d_k;
    c1_a_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_e_k, 1, c1_a_sizes[1], 1, 0) -
      1] = c1_a_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_e_k, 1, c1_a_sizes[1], 1,
      0) - 1] * (real_T)((c1_n - c1_e_k) + 2);
  }

  if (!c1_isfinite(chartInstance, c1_u[5])) {
    c1_a_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_a_sizes[1], 1, c1_a_sizes[1], 1,
      0) - 1] = rtNaN;
  }
}

static boolean_T c1_isfinite(SFc1_Arti_DeltaSM_AngulosInstanceStruct
  *chartInstance, real_T c1_x)
{
  real_T c1_b_x;
  boolean_T c1_b_b;
  boolean_T c1_b0;
  real_T c1_c_x;
  boolean_T c1_c_b;
  boolean_T c1_b1;
  (void)chartInstance;
  c1_b_x = c1_x;
  c1_b_b = muDoubleScalarIsInf(c1_b_x);
  c1_b0 = !c1_b_b;
  c1_c_x = c1_x;
  c1_c_b = muDoubleScalarIsNaN(c1_c_x);
  c1_b1 = !c1_c_b;
  return c1_b0 && c1_b1;
}

static real_T c1_b_polyval(SFc1_Arti_DeltaSM_AngulosInstanceStruct
  *chartInstance, real_T c1_p_data[], int32_T c1_p_sizes[2], real_T c1_x)
{
  real_T c1_y;
  real_T c1_nc;
  boolean_T c1_b2;
  boolean_T c1_b3;
  real_T c1_b_nc;
  int32_T c1_i57;
  int32_T c1_k;
  real_T c1_b_k;
  (void)chartInstance;
  c1_nc = (real_T)c1_p_sizes[1];
  c1_b2 = (c1_p_sizes[1] == 0);
  c1_b3 = c1_b2;
  if (!c1_b3) {
    (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", 1, 1, c1_p_sizes[1], 1, 0);
    c1_y = c1_p_data[0];
    c1_b_nc = c1_nc;
    c1_i57 = (int32_T)(c1_b_nc + -1.0) - 1;
    for (c1_k = 0; c1_k <= c1_i57; c1_k++) {
      c1_b_k = 2.0 + (real_T)c1_k;
      c1_y = c1_x * c1_y + c1_p_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        c1_b_k, 1, c1_p_sizes[1], 1, 0) - 1];
    }
  }

  return c1_y;
}

static void c1_b_polyder(SFc1_Arti_DeltaSM_AngulosInstanceStruct *chartInstance,
  real_T c1_u_data[], int32_T c1_u_sizes[2], real_T c1_a_data[], int32_T
  c1_a_sizes[2])
{
  int32_T c1_b_u_sizes[2];
  int32_T c1_u;
  int32_T c1_b_u;
  int32_T c1_loop_ub;
  int32_T c1_i58;
  real_T c1_b_u_data[5];
  int32_T c1_n;
  int32_T c1_i59;
  int32_T c1_k;
  int32_T c1_b_k;
  boolean_T c1_b4;
  c1_b_u_sizes[0] = 1;
  c1_b_u_sizes[1] = c1_u_sizes[1];
  c1_u = c1_b_u_sizes[0];
  c1_b_u = c1_b_u_sizes[1];
  c1_loop_ub = c1_u_sizes[0] * c1_u_sizes[1] - 1;
  for (c1_i58 = 0; c1_i58 <= c1_loop_ub; c1_i58++) {
    c1_b_u_data[c1_i58] = c1_u_data[c1_i58];
  }

  c1_trim_leading_zeros(chartInstance, c1_b_u_data, c1_b_u_sizes, c1_a_data,
                        c1_a_sizes);
  c1_n = c1_a_sizes[1] - 1;
  c1_i59 = c1_n;
  for (c1_k = 1; c1_k <= c1_i59; c1_k++) {
    c1_b_k = c1_k;
    c1_a_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_b_k, 1, c1_a_sizes[1], 1, 0) -
      1] = c1_a_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_b_k, 1, c1_a_sizes[1], 1,
      0) - 1] * (real_T)((c1_n - c1_b_k) + 2);
  }

  c1_b4 = (c1_u_sizes[1] == 0);
  if (!c1_b4) {
    if (!c1_isfinite(chartInstance, c1_u_data[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          c1_u_sizes[1], 1, c1_u_sizes[1], 1, 0) - 1])) {
      c1_a_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_a_sizes[1], 1, c1_a_sizes[1],
        1, 0) - 1] = rtNaN;
    }
  }
}

static void c1_trim_leading_zeros(SFc1_Arti_DeltaSM_AngulosInstanceStruct
  *chartInstance, real_T c1_x_data[], int32_T c1_x_sizes[2], real_T c1_y_data[],
  int32_T c1_y_sizes[2])
{
  int32_T c1_nx;
  int32_T c1_nymax;
  int32_T c1_tmp_sizes[2];
  int32_T c1_iv1[2];
  int32_T c1_i60;
  int32_T c1_i61;
  int32_T c1_loop_ub;
  int32_T c1_i62;
  real_T c1_tmp_data[4];
  int32_T c1_i63;
  boolean_T c1_b5;
  boolean_T c1_b6;
  int32_T c1_nlead0;
  int32_T c1_i64;
  int32_T c1_k;
  int32_T c1_b_k;
  int32_T c1_ny;
  const mxArray *c1_y = NULL;
  int32_T c1_iv2[2];
  int32_T c1_i65;
  int32_T c1_i66;
  int32_T c1_b_loop_ub;
  int32_T c1_i67;
  int32_T c1_i68;
  int32_T c1_b_ny;
  int32_T c1_c_k;
  boolean_T guard1 = false;
  boolean_T exitg1;
  (void)chartInstance;
  c1_nx = c1_x_sizes[1];
  if (c1_nx < 2) {
    c1_nymax = 1;
  } else {
    c1_nymax = c1_nx - 1;
  }

  c1_tmp_sizes[0] = 1;
  c1_iv1[0] = 1;
  c1_iv1[1] = c1_nymax;
  c1_tmp_sizes[1] = c1_iv1[1];
  c1_i60 = c1_tmp_sizes[0];
  c1_i61 = c1_tmp_sizes[1];
  c1_loop_ub = c1_nymax - 1;
  for (c1_i62 = 0; c1_i62 <= c1_loop_ub; c1_i62++) {
    c1_tmp_data[c1_i62] = 0.0;
  }

  for (c1_i63 = 0; c1_i63 < 2; c1_i63++) {
    c1_y_sizes[c1_i63] = c1_tmp_sizes[c1_i63];
  }

  c1_b5 = (c1_x_sizes[1] == 0);
  guard1 = false;
  if (c1_b5) {
    guard1 = true;
  } else {
    c1_b6 = (c1_x_sizes[1] == 1);
    if (c1_b6) {
      guard1 = true;
    } else {
      c1_nlead0 = 0;
      c1_i64 = c1_nymax;
      c1_k = 1;
      exitg1 = false;
      while ((exitg1 == false) && (c1_k <= c1_i64 - 1)) {
        c1_b_k = c1_k;
        if (c1_x_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_b_k, 1, c1_x_sizes[1],
             1, 0) - 1] == 0.0) {
          c1_nlead0++;
          c1_k++;
        } else {
          exitg1 = true;
        }
      }

      c1_ny = c1_nymax - c1_nlead0;
      if (c1_ny <= c1_nymax) {
      } else {
        c1_y = NULL;
        sf_mex_assign(&c1_y, sf_mex_create("y", "Assertion failed.", 15, 0U, 0U,
          0U, 2, 1, strlen("Assertion failed.")), false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14, c1_y);
      }

      c1_tmp_sizes[0] = 1;
      c1_iv2[0] = 1;
      c1_iv2[1] = (int32_T)_SFD_NON_NEGATIVE_CHECK("", (real_T)c1_ny);
      c1_tmp_sizes[1] = c1_iv2[1];
      c1_i65 = c1_tmp_sizes[0];
      c1_i66 = c1_tmp_sizes[1];
      c1_b_loop_ub = (int32_T)_SFD_NON_NEGATIVE_CHECK("", (real_T)c1_ny) - 1;
      for (c1_i67 = 0; c1_i67 <= c1_b_loop_ub; c1_i67++) {
        c1_tmp_data[c1_i67] = 0.0;
      }

      for (c1_i68 = 0; c1_i68 < 2; c1_i68++) {
        c1_y_sizes[c1_i68] = c1_tmp_sizes[c1_i68];
      }

      c1_b_ny = c1_ny;
      for (c1_c_k = 1; c1_c_k <= c1_b_ny; c1_c_k++) {
        c1_b_k = c1_c_k;
        c1_y_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_b_k, 1, c1_y_sizes[1], 1, 0)
          - 1] = c1_x_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c1_b_k + c1_nlead0, 1,
          c1_x_sizes[1], 1, 0) - 1];
      }
    }
  }

  if (guard1 == true) {
    c1_y_data[0] = 0.0;
  }
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_Arti_DeltaSM_AngulosInstanceStruct *chartInstance;
  chartInstance = (SFc1_Arti_DeltaSM_AngulosInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int32_T c1_c_emlrt_marshallIn(SFc1_Arti_DeltaSM_AngulosInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i69;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i69, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i69;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_Arti_DeltaSM_AngulosInstanceStruct *chartInstance;
  chartInstance = (SFc1_Arti_DeltaSM_AngulosInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_d_emlrt_marshallIn(SFc1_Arti_DeltaSM_AngulosInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_Arti_DeltaSM_Angulos, const
  char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_Arti_DeltaSM_Angulos), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_Arti_DeltaSM_Angulos);
  return c1_y;
}

static uint8_T c1_e_emlrt_marshallIn(SFc1_Arti_DeltaSM_AngulosInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_Arti_DeltaSM_AngulosInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c1_Arti_DeltaSM_Angulos_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(817466022U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1541358166U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1095689250U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2708233547U);
}

mxArray *sf_c1_Arti_DeltaSM_Angulos_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("ktFQFRkEHGfRKBnKp2GfhB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(5);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(6);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(6);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(6);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,9,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_Arti_DeltaSM_Angulos_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_Arti_DeltaSM_Angulos_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c1_Arti_DeltaSM_Angulos(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[29],T\"ThPM1\",},{M[1],M[30],T\"ThPM2\",},{M[1],M[31],T\"ThPM3\",},{M[1],M[32],T\"ThPPM1\",},{M[1],M[33],T\"ThPPM2\",},{M[1],M[34],T\"ThPPM3\",},{M[1],M[8],T\"ThetaM1\",},{M[1],M[9],T\"ThetaM2\",},{M[1],M[10],T\"ThetaM3\",},{M[8],M[0],T\"is_active_c1_Arti_DeltaSM_Angulos\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 10, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_Arti_DeltaSM_Angulos_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_Arti_DeltaSM_AngulosInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc1_Arti_DeltaSM_AngulosInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Arti_DeltaSM_AngulosMachineNumber_,
           1,
           1,
           1,
           0,
           14,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_Arti_DeltaSM_AngulosMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Arti_DeltaSM_AngulosMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Arti_DeltaSM_AngulosMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Time");
          _SFD_SET_DATA_PROPS(1,2,0,1,"ThetaM1");
          _SFD_SET_DATA_PROPS(2,2,0,1,"ThPM1");
          _SFD_SET_DATA_PROPS(3,2,0,1,"ThPPM1");
          _SFD_SET_DATA_PROPS(4,2,0,1,"ThetaM2");
          _SFD_SET_DATA_PROPS(5,2,0,1,"ThPM2");
          _SFD_SET_DATA_PROPS(6,2,0,1,"ThPPM2");
          _SFD_SET_DATA_PROPS(7,2,0,1,"ThetaM3");
          _SFD_SET_DATA_PROPS(8,1,1,0,"TiempoAcu");
          _SFD_SET_DATA_PROPS(9,1,1,0,"A1");
          _SFD_SET_DATA_PROPS(10,1,1,0,"A2");
          _SFD_SET_DATA_PROPS(11,1,1,0,"A3");
          _SFD_SET_DATA_PROPS(12,2,0,1,"ThPM3");
          _SFD_SET_DATA_PROPS(13,2,0,1,"ThPPM3");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,1,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,837);
        _SFD_CV_INIT_EML_IF(0,1,0,166,174,-1,187);
        _SFD_CV_INIT_EML_WHILE(0,1,0,118,143,158);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          real_T *c1_Time;
          real_T *c1_ThetaM1;
          real_T *c1_ThPM1;
          real_T *c1_ThPPM1;
          real_T *c1_ThetaM2;
          real_T *c1_ThPM2;
          real_T *c1_ThPPM2;
          real_T *c1_ThetaM3;
          real_T *c1_ThPM3;
          real_T *c1_ThPPM3;
          real_T (*c1_TiempoAcu)[5];
          real_T (*c1_A1)[24];
          real_T (*c1_A2)[24];
          real_T (*c1_A3)[24];
          c1_ThPPM3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 9);
          c1_ThPM3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
          c1_A3 = (real_T (*)[24])ssGetInputPortSignal(chartInstance->S, 4);
          c1_A2 = (real_T (*)[24])ssGetInputPortSignal(chartInstance->S, 3);
          c1_A1 = (real_T (*)[24])ssGetInputPortSignal(chartInstance->S, 2);
          c1_TiempoAcu = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 1);
          c1_ThetaM3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
          c1_ThPPM2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c1_ThPM2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c1_ThetaM2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c1_ThPPM1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c1_ThPM1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c1_ThetaM1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c1_Time = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_Time);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_ThetaM1);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_ThPM1);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_ThPPM1);
          _SFD_SET_DATA_VALUE_PTR(4U, c1_ThetaM2);
          _SFD_SET_DATA_VALUE_PTR(5U, c1_ThPM2);
          _SFD_SET_DATA_VALUE_PTR(6U, c1_ThPPM2);
          _SFD_SET_DATA_VALUE_PTR(7U, c1_ThetaM3);
          _SFD_SET_DATA_VALUE_PTR(8U, *c1_TiempoAcu);
          _SFD_SET_DATA_VALUE_PTR(9U, *c1_A1);
          _SFD_SET_DATA_VALUE_PTR(10U, *c1_A2);
          _SFD_SET_DATA_VALUE_PTR(11U, *c1_A3);
          _SFD_SET_DATA_VALUE_PTR(12U, c1_ThPM3);
          _SFD_SET_DATA_VALUE_PTR(13U, c1_ThPPM3);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Arti_DeltaSM_AngulosMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "fcZq21JlIn0BuxQWPvTlVB";
}

static void sf_opaque_initialize_c1_Arti_DeltaSM_Angulos(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_Arti_DeltaSM_AngulosInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_Arti_DeltaSM_Angulos
    ((SFc1_Arti_DeltaSM_AngulosInstanceStruct*) chartInstanceVar);
  initialize_c1_Arti_DeltaSM_Angulos((SFc1_Arti_DeltaSM_AngulosInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_Arti_DeltaSM_Angulos(void *chartInstanceVar)
{
  enable_c1_Arti_DeltaSM_Angulos((SFc1_Arti_DeltaSM_AngulosInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_Arti_DeltaSM_Angulos(void *chartInstanceVar)
{
  disable_c1_Arti_DeltaSM_Angulos((SFc1_Arti_DeltaSM_AngulosInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_Arti_DeltaSM_Angulos(void *chartInstanceVar)
{
  sf_gateway_c1_Arti_DeltaSM_Angulos((SFc1_Arti_DeltaSM_AngulosInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_Arti_DeltaSM_Angulos
  (SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_Arti_DeltaSM_Angulos
    ((SFc1_Arti_DeltaSM_AngulosInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_Arti_DeltaSM_Angulos();/* state var info */
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

extern void sf_internal_set_sim_state_c1_Arti_DeltaSM_Angulos(SimStruct* S,
  const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c1_Arti_DeltaSM_Angulos();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_Arti_DeltaSM_Angulos((SFc1_Arti_DeltaSM_AngulosInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_Arti_DeltaSM_Angulos(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c1_Arti_DeltaSM_Angulos(S);
}

static void sf_opaque_set_sim_state_c1_Arti_DeltaSM_Angulos(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c1_Arti_DeltaSM_Angulos(S, st);
}

static void sf_opaque_terminate_c1_Arti_DeltaSM_Angulos(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_Arti_DeltaSM_AngulosInstanceStruct*) chartInstanceVar
      )->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Arti_DeltaSM_Angulos_optimization_info();
    }

    finalize_c1_Arti_DeltaSM_Angulos((SFc1_Arti_DeltaSM_AngulosInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_Arti_DeltaSM_Angulos((SFc1_Arti_DeltaSM_AngulosInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_Arti_DeltaSM_Angulos(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c1_Arti_DeltaSM_Angulos
      ((SFc1_Arti_DeltaSM_AngulosInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_Arti_DeltaSM_Angulos(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Arti_DeltaSM_Angulos_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,1,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,9);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=9; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 5; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3723278634U));
  ssSetChecksum1(S,(374870855U));
  ssSetChecksum2(S,(2163992522U));
  ssSetChecksum3(S,(4271076164U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_Arti_DeltaSM_Angulos(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_Arti_DeltaSM_Angulos(SimStruct *S)
{
  SFc1_Arti_DeltaSM_AngulosInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc1_Arti_DeltaSM_AngulosInstanceStruct *)utMalloc(sizeof
    (SFc1_Arti_DeltaSM_AngulosInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_Arti_DeltaSM_AngulosInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_Arti_DeltaSM_Angulos;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_Arti_DeltaSM_Angulos;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_Arti_DeltaSM_Angulos;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_Arti_DeltaSM_Angulos;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_Arti_DeltaSM_Angulos;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_Arti_DeltaSM_Angulos;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_Arti_DeltaSM_Angulos;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_Arti_DeltaSM_Angulos;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_Arti_DeltaSM_Angulos;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_Arti_DeltaSM_Angulos;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_Arti_DeltaSM_Angulos;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c1_Arti_DeltaSM_Angulos_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_Arti_DeltaSM_Angulos(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_Arti_DeltaSM_Angulos(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_Arti_DeltaSM_Angulos(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_Arti_DeltaSM_Angulos_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
