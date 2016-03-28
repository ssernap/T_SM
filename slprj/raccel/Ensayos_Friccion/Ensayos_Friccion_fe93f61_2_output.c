#include "__cf_Ensayos_Friccion.h"
#include <math.h>
#include <string.h>
#include "pm_std.h"
#include "sm_std.h"
#include "sm_ssci_run_time_errors.h"
PmfMessageId Ensayos_Friccion_fe93f61_2_output ( const double * state , const
double * input , const double * inputDot , const double * inputDdot , const
double * discreteState , double * output , NeuDiagnosticManager * neDiagMgr )
{ ( void ) input ; ( void ) inputDot ; ( void ) inputDdot ; ( void )
discreteState ; ( void ) neDiagMgr ; output [ 0 ] = state [ 0 ] ; output [ 1
] = state [ 1 ] ; return NULL ; }
