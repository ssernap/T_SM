#ifndef __c11_Opera_DeltaSM_Control_Fricc_h__
#define __c11_Opera_DeltaSM_Control_Fricc_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc11_Opera_DeltaSM_Control_FriccInstanceStruct
#define typedef_SFc11_Opera_DeltaSM_Control_FriccInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c11_sfEvent;
  boolean_T c11_isStable;
  boolean_T c11_doneDoubleBufferReInit;
  uint8_T c11_is_active_c11_Opera_DeltaSM_Control_Fricc;
} SFc11_Opera_DeltaSM_Control_FriccInstanceStruct;

#endif                                 /*typedef_SFc11_Opera_DeltaSM_Control_FriccInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c11_Opera_DeltaSM_Control_Fricc_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c11_Opera_DeltaSM_Control_Fricc_get_check_sum(mxArray *plhs[]);
extern void c11_Opera_DeltaSM_Control_Fricc_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
