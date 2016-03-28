#include "__cf_Ensayos_Friccion.h"
#include "nesl_rtw.h"
#include "Ensayos_Friccion_fe93f61_1.h"
#include "Ensayos_Friccion_fe93f61_2.h"
void Ensayos_Friccion_fe93f61_gateway ( void ) { NeModelParameters
modelparams = { ( NeSolverType ) 0 , 0.001 , 1 , 0.001 , 0 , 0 , 0 , 0 , (
SscLoggingSetting ) 0 , } ; NeSolverParameters solverparams = { 0 , 0 , 1 , 0
, 0 , 0.001 , 1e-06 , 1e-09 , 0 , 1 , 1e-09 , 0 , ( NeAdvancerChoice ) 0 ,
0.0005 , 0 , 30 , 2 , ( NeLinearAlgebraChoice ) 1 , 2048 , 1 , 0.001 , } ;
const NeInputParameters * inputparameters = NULL ; const NeOutputParameters *
outputparameters = NULL ; const NeLinearAlgebra * linear_algebra_ptr = ( (
solverparams . mLinearAlgebra == NE_FULL_LA ) ? get_rtw_linear_algebra ( ) :
neu_get_csparse_linear_algebra ( ) ) ; NeDae * dae [ 2 ] ; size_t numInputs =
0 ; size_t numOutputs = 0 ; { static const NeInputParameters
inputparameters_init [ ] = { { 0 , 0 , 0 , 0.001 , 1 , 0 ,
 "Ensayos_Friccion/DeltaSM/Friccion \nCoulomb\nR/Expandido/Simulink-PS\nConverter"
, } , { 0 , 0 , 0 , 0.001 , 1 , 0 ,
 "Ensayos_Friccion/DeltaSM/Friccion \nCoulomb\nR2/Expandido/Simulink-PS\nConverter"
, } , { 1 , 0 , 0 , 0.001 , 1 , 0 ,
"Ensayos_Friccion/DeltaSM/Solver\nConfiguration1" , } , } ; inputparameters =
inputparameters_init ; numInputs = sizeof ( inputparameters_init ) / sizeof (
inputparameters_init [ 0 ] ) ; } { static const NeOutputParameters
outputparameters_init [ ] = { { 0 , 0 ,
"Ensayos_Friccion/DeltaSM/Solver\nConfiguration1" , } , { 1 , 0 ,
"Ensayos_Friccion/DeltaSM/Solver\nConfiguration1" , } , } ; outputparameters
= outputparameters_init ; numOutputs = sizeof ( outputparameters_init ) /
sizeof ( outputparameters_init [ 0 ] ) ; } Ensayos_Friccion_fe93f61_1_dae ( &
dae [ 0 ] , & modelparams , & solverparams , linear_algebra_ptr ) ;
Ensayos_Friccion_fe93f61_2_dae ( & dae [ 1 ] , & modelparams , & solverparams
, linear_algebra_ptr ) ; nesl_register_simulator_group (
"Ensayos_Friccion/DeltaSM/Solver Configuration1" , 2 , dae , solverparams ,
modelparams , numInputs , inputparameters , numOutputs , outputparameters ) ;
}
