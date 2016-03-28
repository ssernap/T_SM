#include "__cf_Ensayos_Friccion.h"
#include <math.h>
#include <string.h>
#include "pm_std.h"
#include "sm_std.h"
#include "sm_ssci_run_time_errors.h"
PmfMessageId Ensayos_Friccion_fe93f61_2_deriv ( const double * state , const
double * input , const double * inputDot , const double * inputDdot , const
double * discreteState , double * deriv , NeuDiagnosticManager * neDiagMgr )
{ double xx [ 33 ] ; int ii [ 3 ] ; ( void ) inputDot ; ( void ) inputDdot ;
( void ) discreteState ; ( void ) neDiagMgr ; xx [ 0 ] = 8.967312880221034e-7
; xx [ 1 ] = 3.676898337281796e-3 ; xx [ 3 ] = 0.9999932401860591 ; xx [ 4 ]
= xx [ 0 ] ; xx [ 5 ] = - xx [ 1 ] ; xx [ 6 ] = xx [ 3 ] ; xx [ 7 ] = xx [ 0
] * state [ 1 ] ; xx [ 8 ] = - xx [ 1 ] * state [ 1 ] ; xx [ 9 ] = xx [ 3 ] *
state [ 1 ] ; xx [ 10 ] = 1.5897006298646e-10 * state [ 1 ] ; xx [ 11 ] = -
3.60688884808375e-8 * state [ 1 ] ; xx [ 12 ] = 1.698279719297039e-4 * state
[ 1 ] ; pm_math_cross3 ( xx + 7 , xx + 10 , xx + 13 ) ; xx [ 2 ] =
0.08138427610682734 ; xx [ 10 ] = 1.218848741692602e-9 ; xx [ 12 ] =
7.298480168461341e-8 ; xx [ 16 ] = xx [ 2 ] ; xx [ 17 ] = - xx [ 10 ] ; xx [
18 ] = - xx [ 12 ] ; xx [ 11 ] = 0.06009143298117723 ; xx [ 19 ] = xx [ 2 ] *
state [ 1 ] ; xx [ 20 ] = - xx [ 10 ] * state [ 1 ] ; xx [ 21 ] = - xx [ 12 ]
* state [ 1 ] ; pm_math_cross3 ( xx + 7 , xx + 19 , xx + 22 ) ; xx [ 7 ] = xx
[ 11 ] * xx [ 22 ] ; xx [ 8 ] = xx [ 11 ] * xx [ 23 ] ; xx [ 9 ] = xx [ 11 ]
* xx [ 24 ] ; xx [ 2 ] = 5.678365776361167e-4 ; ii [ 1 ] = factorSymmetric (
xx + 2 , 1 , xx + 11 , xx + 10 , ii + 0 , ii + 2 ) ; if ( ii [ 2 ] != 0 ) {
return sm_ssci_recordRunTimeError (
"sm:compiler:messages:simulationErrors:DegenerateMass" ,
 "'Ensayos_Friccion/DeltaSM/Revolute1' has a degenerate mass distribution on its follower side."
, neDiagMgr ) ; } xx [ 10 ] = 4.890497773395039e-3 / xx [ 2 ] ; xx [ 11 ] = -
7.324236747561318e-11 / xx [ 2 ] ; xx [ 12 ] = - 4.385761319075458e-9 / xx [
2 ] ; xx [ 19 ] = 2.0 ; xx [ 20 ] = 0.354202515340608 ; xx [ 21 ] =
0.3529025217116608 ; xx [ 22 ] = - 0.6112457451802167 ; xx [ 23 ] = -
0.6134973735029505 ; xx [ 24 ] = 0.5 * state [ 0 ] ; xx [ 26 ] = sin ( xx [
24 ] ) ; xx [ 29 ] = cos ( xx [ 24 ] ) ; xx [ 30 ] = xx [ 0 ] * xx [ 26 ] ;
xx [ 31 ] = - xx [ 1 ] * xx [ 26 ] ; xx [ 32 ] = xx [ 3 ] * xx [ 26 ] ;
pm_math_quatCompose ( xx + 20 , xx + 29 , xx + 24 ) ; xx [ 0 ] =
9.810000000000001 ; xx [ 1 ] = xx [ 0 ] * xx [ 25 ] ; xx [ 3 ] = xx [ 0 ] *
xx [ 26 ] ; xx [ 29 ] = xx [ 19 ] * ( xx [ 27 ] * xx [ 1 ] - xx [ 24 ] * xx [
3 ] ) ; xx [ 30 ] = ( xx [ 24 ] * xx [ 1 ] + xx [ 27 ] * xx [ 3 ] ) * xx [ 19
] ; xx [ 31 ] = xx [ 0 ] - ( xx [ 25 ] * xx [ 1 ] + xx [ 26 ] * xx [ 3 ] ) *
xx [ 19 ] ; deriv [ 0 ] = state [ 1 ] ; deriv [ 1 ] = ( input [ 0 ] - (
pm_math_dot3 ( xx + 4 , xx + 13 ) + pm_math_dot3 ( xx + 16 , xx + 7 ) ) ) /
xx [ 2 ] - pm_math_dot3 ( xx + 10 , xx + 29 ) ; return NULL ; }
