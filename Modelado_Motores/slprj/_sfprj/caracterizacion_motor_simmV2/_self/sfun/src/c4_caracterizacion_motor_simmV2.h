#ifndef __c4_caracterizacion_motor_simmV2_h__
#define __c4_caracterizacion_motor_simmV2_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc4_caracterizacion_motor_simmV2InstanceStruct
#define typedef_SFc4_caracterizacion_motor_simmV2InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  boolean_T c4_isStable;
  boolean_T c4_doneDoubleBufferReInit;
  uint8_T c4_is_active_c4_caracterizacion_motor_simmV2;
} SFc4_caracterizacion_motor_simmV2InstanceStruct;

#endif                                 /*typedef_SFc4_caracterizacion_motor_simmV2InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c4_caracterizacion_motor_simmV2_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_caracterizacion_motor_simmV2_get_check_sum(mxArray *plhs[]);
extern void c4_caracterizacion_motor_simmV2_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
