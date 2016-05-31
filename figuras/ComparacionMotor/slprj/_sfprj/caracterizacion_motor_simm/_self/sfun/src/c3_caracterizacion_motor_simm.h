#ifndef __c3_caracterizacion_motor_simm_h__
#define __c3_caracterizacion_motor_simm_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_caracterizacion_motor_simmInstanceStruct
#define typedef_SFc3_caracterizacion_motor_simmInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  boolean_T c3_isStable;
  boolean_T c3_doneDoubleBufferReInit;
  uint8_T c3_is_active_c3_caracterizacion_motor_simm;
} SFc3_caracterizacion_motor_simmInstanceStruct;

#endif                                 /*typedef_SFc3_caracterizacion_motor_simmInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c3_caracterizacion_motor_simm_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_caracterizacion_motor_simm_get_check_sum(mxArray *plhs[]);
extern void c3_caracterizacion_motor_simm_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
