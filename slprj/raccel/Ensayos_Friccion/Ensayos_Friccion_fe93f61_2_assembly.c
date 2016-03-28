#include "__cf_Ensayos_Friccion.h"
#include <math.h>
#include <string.h>
#include "pm_std.h"
#include "sm_std.h"
#include "sm_ssci_run_time_errors.h"
void Ensayos_Friccion_fe93f61_2_resetStateVector ( const void * mech , double
* state ) { double xx [ 1 ] ; ( void ) mech ; xx [ 0 ] = 0.0 ; state [ 0 ] =
xx [ 0 ] ; state [ 1 ] = xx [ 0 ] ; } PmfMessageId
Ensayos_Friccion_fe93f61_2_initializeTrackedAngleState ( const void * mech ,
double * state , void * neDiagMgr0 ) { NeuDiagnosticManager * neDiagMgr = (
NeuDiagnosticManager * ) neDiagMgr0 ; ( void ) mech ; ( void ) state ; return
NULL ; } void Ensayos_Friccion_fe93f61_2_computeDiscreteState ( const void *
mech , double * state ) { ( void ) mech ; ( void ) state ; } void
Ensayos_Friccion_fe93f61_2_adjustPosition ( const void * mech , const double
* dofDeltas , double * state ) { ( void ) mech ; state [ 0 ] = state [ 0 ] +
dofDeltas [ 0 ] ; } static void perturbState_0_0 ( double mag , double *
state ) { state [ 0 ] = state [ 0 ] + mag ; } static void perturbState_0_0v (
double mag , double * state ) { state [ 0 ] = state [ 0 ] + mag ; state [ 1 ]
= state [ 1 ] - 0.875 * mag ; } void Ensayos_Friccion_fe93f61_2_perturbState
( const void * mech , size_t stageIdx , size_t primIdx , double mag , bool
doPerturbVelocity , double * state ) { ( void ) mech ; ( void ) stageIdx ; (
void ) primIdx ; ( void ) mag ; ( void ) doPerturbVelocity ; ( void ) state ;
switch ( ( stageIdx * 6 + primIdx ) * 2 + ( doPerturbVelocity ? 1 : 0 ) ) {
case 0 : perturbState_0_0 ( mag , state ) ; break ; case 1 :
perturbState_0_0v ( mag , state ) ; break ; } } void
Ensayos_Friccion_fe93f61_2_propagateMotion ( const void * mech , const double
* state , double * motionData ) { double xx [ 20 ] ; ( void ) mech ; xx [ 0 ]
= 0.354202515340608 ; xx [ 1 ] = 0.3529025217116608 ; xx [ 2 ] = -
0.6112457451802167 ; xx [ 3 ] = - 0.6134973735029505 ; xx [ 4 ] = 0.5 * state
[ 0 ] ; xx [ 6 ] = 8.967312880221034e-7 ; xx [ 7 ] = sin ( xx [ 4 ] ) ; xx [
5 ] = 3.676898337281796e-3 ; xx [ 10 ] = 0.9999932401860591 ; xx [ 12 ] = cos
( xx [ 4 ] ) ; xx [ 13 ] = xx [ 6 ] * xx [ 7 ] ; xx [ 14 ] = - xx [ 5 ] * xx
[ 7 ] ; xx [ 15 ] = xx [ 10 ] * xx [ 7 ] ; pm_math_quatCompose ( xx + 0 , xx
+ 12 , xx + 16 ) ; xx [ 0 ] = - 6.56720411565304e-9 ; xx [ 1 ] =
0.08141675170891022 ; xx [ 2 ] = - 8.682655069882864e-3 ; pm_math_quatXform (
xx + 16 , xx + 0 , xx + 7 ) ; motionData [ 0 ] = xx [ 16 ] ; motionData [ 1 ]
= xx [ 17 ] ; motionData [ 2 ] = xx [ 18 ] ; motionData [ 3 ] = xx [ 19 ] ;
motionData [ 4 ] = - ( 0.02798926501499193 + xx [ 7 ] ) ; motionData [ 5 ] =
- ( 0.05918460043841842 + xx [ 8 ] ) ; motionData [ 6 ] = - (
0.02400000000000001 + xx [ 9 ] ) ; motionData [ 7 ] = xx [ 6 ] * state [ 1 ]
; motionData [ 8 ] = - xx [ 5 ] * state [ 1 ] ; motionData [ 9 ] = xx [ 10 ]
* state [ 1 ] ; motionData [ 10 ] = 0.08138427610682734 * state [ 1 ] ;
motionData [ 11 ] = - 1.218848741692602e-9 * state [ 1 ] ; motionData [ 12 ]
= - 7.298480168461341e-8 * state [ 1 ] ; } size_t
Ensayos_Friccion_fe93f61_2_computeAssemblyError ( const void * mech , size_t
constraintIdx , const double * state , const double * motionData , double *
error ) { ( void ) mech ; ( void ) state ; ( void ) motionData ; ( void )
error ; ( void ) state ; switch ( constraintIdx ) { } return 0 ; } size_t
Ensayos_Friccion_fe93f61_2_computeAssemblyJacobian ( const void * mech ,
size_t constraintIdx , bool forVelocitySatisfaction , const double * state ,
const double * motionData , double * J ) { ( void ) mech ; ( void ) state ; (
void ) forVelocitySatisfaction ; ( void ) motionData ; ( void ) J ; switch (
constraintIdx ) { } return 0 ; } size_t
Ensayos_Friccion_fe93f61_2_computeFullAssemblyJacobian ( const void * mech ,
const double * state , const double * motionData , double * J ) { ( void )
mech ; ( void ) state ; ( void ) motionData ; ( void ) J ; return 0 ; }
PmfMessageId Ensayos_Friccion_fe93f61_2_convertStateVector ( const void *
asmMech , const void * simMech , const double * asmState , double * simState
, void * neDiagMgr0 ) { NeuDiagnosticManager * neDiagMgr = (
NeuDiagnosticManager * ) neDiagMgr0 ; ( void ) asmMech ; ( void ) simMech ;
simState [ 0 ] = asmState [ 0 ] ; simState [ 1 ] = asmState [ 1 ] ; return
NULL ; }
