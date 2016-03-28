#include "__cf_Ensayos_Friccion.h"
#include "rt_logging_mmi.h"
#include "Ensayos_Friccion_capi.h"
#include <math.h>
#include "Ensayos_Friccion.h"
#include "Ensayos_Friccion_private.h"
#include "Ensayos_Friccion_dt.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
const boolean_T gbl_raccel_isMultitasking = 1 ;
#else
const boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
const boolean_T gbl_raccel_tid01eq = 0 ; const int_T gbl_raccel_NumST = 2 ;
const char_T * gbl_raccel_Version = "8.6 (R2014a) 27-Dec-2013" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj\\raccel\\Ensayos_Friccion\\Ensayos_Friccion_Jpattern.mat" ; const
int_T gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
const int_T gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [
] = { - 1 } ; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ;
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; X rtX ; MassMatrix rtMassMatrix ; DW rtDW ; static SimStruct model_S
; SimStruct * const rtS = & model_S ; void MdlInitialize ( void ) { boolean_T
tmp ; int_T tmp_p ; char * tmp_e ; char * tmp_i ; tmp = false ; if ( tmp ) {
tmp_p = strcmp ( "ode23t" , ssGetSolverName ( rtS ) ) ; if ( tmp_p != 0 ) {
tmp_e = solver_mismatch_message ( "ode23t" , ssGetSolverName ( rtS ) ) ;
ssSetErrorStatus ( rtS , tmp_e ) ; } } rtw_diagnostics_reset ( ) ;
rtw_diagnostics_reset ( ) ; rtw_diagnostics_reset ( ) ; rtw_diagnostics_reset
( ) ; tmp = false ; if ( tmp ) { tmp_p = strcmp ( "ode23t" , ssGetSolverName
( rtS ) ) ; if ( tmp_p != 0 ) { tmp_i = solver_mismatch_message ( "ode23t" ,
ssGetSolverName ( rtS ) ) ; ssSetErrorStatus ( rtS , tmp_i ) ; } }
rtw_diagnostics_reset ( ) ; rtw_diagnostics_reset ( ) ; rtw_diagnostics_reset
( ) ; rtw_diagnostics_reset ( ) ; rtw_diagnostics_reset ( ) ; { static int_T
modelMassMatrixIr [ 3 ] = { 0 , 1 , 2 } ; static int_T modelMassMatrixJc [ 4
] = { 0 , 1 , 2 , 3 } ; static real_T modelMassMatrixPr [ 3 ] = { 1.0 , 1.0 ,
1.0 } ; ( void ) memcpy ( rtMassMatrix . ir , modelMassMatrixIr , 3 * sizeof
( int_T ) ) ; ( void ) memcpy ( rtMassMatrix . jc , modelMassMatrixJc , 4 *
sizeof ( int_T ) ) ; ( void ) memcpy ( rtMassMatrix . pr , modelMassMatrixPr
, 3 * sizeof ( real_T ) ) ; } } void MdlStart ( void ) { NeuDiagnosticManager
* diagnosticManager ; NeBoolVector fimtsVector ; boolean_T fimts ; real_T
modelParameters_mSolverTolerance ; real_T modelParameters_mFixedStepSize ;
boolean_T modelParameters_mVariableStepSolver ; NeslSimulator * simulator ;
NeuDiagnosticTree * diagnosticTree ; int32_T tmp ; char * msg ;
NeslSimulationData * simulationData ; real_T time ; NeBoolVector
fimtsVector_p ; boolean_T fimts_p [ 2 ] ; real_T time_p ; NeBoolVector
fimtsVector_e ; boolean_T fimts_e [ 3 ] ; real_T time_e ; NeBoolVector
fimtsVector_i ; boolean_T fimts_i [ 3 ] ; real_T time_i ; NeBoolVector
fimtsVector_m ; boolean_T fimts_m [ 2 ] ; real_T time_m ; NeBoolVector
fimtsVector_g ; boolean_T fimts_g [ 3 ] ; real_T time_g ; NeBoolVector
fimtsVector_j ; boolean_T fimts_j [ 3 ] ; real_T time_j ; NeBoolVector
fimtsVector_f ; boolean_T fimts_f [ 3 ] ; real_T time_f ; NeBoolVector
fimtsVector_c ; boolean_T fimts_c [ 2 ] ; real_T time_c ; NeModelParameters
expl_temp ; NeModelParameters expl_temp_p ; NeModelParameters expl_temp_e ;
NeModelParameters expl_temp_i ; NeModelParameters expl_temp_m ;
NeModelParameters expl_temp_g ; NeModelParameters expl_temp_j ;
NeModelParameters expl_temp_f ; NeModelParameters expl_temp_c ; simulator =
nesl_lease_simulator ( "Ensayos_Friccion/DeltaSM/Solver Configuration1" , 0 ,
1 ) ; rtDW . gk0htlbrma = ( void * ) simulator ;
modelParameters_mVariableStepSolver = pointer_is_null ( rtDW . gk0htlbrma ) ;
if ( modelParameters_mVariableStepSolver ) { Ensayos_Friccion_fe93f61_gateway
( ) ; simulator = nesl_lease_simulator (
"Ensayos_Friccion/DeltaSM/Solver Configuration1" , 0 , 1 ) ; rtDW .
gk0htlbrma = ( void * ) simulator ; } simulationData =
nesl_create_simulation_data ( ) ; rtDW . is0xydhs4l = ( void * )
simulationData ; diagnosticManager = rtw_create_diagnostics ( ) ; rtDW .
ka0rn1jqlo = ( void * ) diagnosticManager ; fimts = false ; fimtsVector . mN
= 1 ; fimtsVector . mX = & fimts ; modelParameters_mSolverTolerance = 0.001 ;
modelParameters_mFixedStepSize = 0.0 ; modelParameters_mVariableStepSolver =
true ; simulator = ( NeslSimulator * ) rtDW . gk0htlbrma ; diagnosticManager
= ( NeuDiagnosticManager * ) rtDW . ka0rn1jqlo ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; expl_temp .
mVariableStepSolver = modelParameters_mVariableStepSolver ; expl_temp .
mUseSimState = false ; expl_temp . mStartTime = 0.0 ; expl_temp . mSolverType
= NE_SOLVER_TYPE_DAE ; expl_temp . mSolverTolerance =
modelParameters_mSolverTolerance ; expl_temp . mLoggingMode =
SSC_LOGGING_NONE ; expl_temp . mLoadInitialState = false ; expl_temp .
mLinTrimCompile = false ; expl_temp . mFixedStepSize =
modelParameters_mFixedStepSize ; tmp = nesl_initialize_simulator ( simulator
, expl_temp , & fimtsVector , diagnosticManager ) ; if ( tmp != 0 ) { tmp =
rtw_diagnostics_message_count ( ) ; if ( tmp == 0 ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
simulationData = ( NeslSimulationData * ) rtDW . is0xydhs4l ; time = ssGetT (
rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time ; simulationData -> mData -> mContStates . mN = 2 ;
simulationData -> mData -> mContStates . mX = ( real_T * ) & rtX . hdzhv0kuvm
; simulationData -> mData -> mDiscStates . mN = 0 ; simulationData -> mData
-> mDiscStates . mX = NULL ; simulationData -> mData -> mModeVector . mN = 0
; simulationData -> mData -> mModeVector . mX = NULL ;
modelParameters_mVariableStepSolver = ( ssIsMajorTimeStep ( rtS ) &&
ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents ) ; simulationData -> mData
-> mFoundZcEvents = modelParameters_mVariableStepSolver ; simulationData ->
mData -> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ;
modelParameters_mVariableStepSolver = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags .
solverAssertCheck == 1U ) ; simulationData -> mData -> mIsSolverAssertCheck =
modelParameters_mVariableStepSolver ; modelParameters_mVariableStepSolver =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = modelParameters_mVariableStepSolver ;
modelParameters_mVariableStepSolver = ssIsSolverComputingJacobian ( rtS ) ;
simulationData -> mData -> mIsComputingJacobian =
modelParameters_mVariableStepSolver ; modelParameters_mVariableStepSolver =
ssIsSolverRequestingReset ( rtS ) ; simulationData -> mData ->
mIsSolverRequestingReset = modelParameters_mVariableStepSolver ; simulator =
( NeslSimulator * ) rtDW . gk0htlbrma ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . ka0rn1jqlo ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; tmp =
ne_simulator_method ( simulator , NESL_SIM_START , simulationData ,
diagnosticManager ) ; if ( tmp != 0 ) { tmp = rtw_diagnostics_message_count (
) ; if ( tmp == 0 ) { msg = rtw_diagnostics_msg ( diagnosticTree ) ;
ssSetErrorStatus ( rtS , msg ) ; } } simulator = nesl_lease_simulator (
"Ensayos_Friccion/DeltaSM/Solver Configuration1" , 3 , 1 ) ; rtDW .
akflnq5gjx = ( void * ) simulator ; modelParameters_mVariableStepSolver =
pointer_is_null ( rtDW . akflnq5gjx ) ; if (
modelParameters_mVariableStepSolver ) { Ensayos_Friccion_fe93f61_gateway ( )
; simulator = nesl_lease_simulator (
"Ensayos_Friccion/DeltaSM/Solver Configuration1" , 3 , 1 ) ; rtDW .
akflnq5gjx = ( void * ) simulator ; } simulationData =
nesl_create_simulation_data ( ) ; rtDW . b2mtd04ww2 = ( void * )
simulationData ; diagnosticManager = rtw_create_diagnostics ( ) ; rtDW .
mxmjsp3mlq = ( void * ) diagnosticManager ; fimts_p [ 0U ] = false ; fimts_p
[ 1U ] = false ; fimtsVector_p . mN = 2 ; fimtsVector_p . mX = & fimts_p [ 0U
] ; modelParameters_mSolverTolerance = 0.001 ; modelParameters_mFixedStepSize
= 0.0 ; modelParameters_mVariableStepSolver = true ; simulator = (
NeslSimulator * ) rtDW . akflnq5gjx ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . mxmjsp3mlq ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; expl_temp_p .
mVariableStepSolver = modelParameters_mVariableStepSolver ; expl_temp_p .
mUseSimState = false ; expl_temp_p . mStartTime = 0.0 ; expl_temp_p .
mSolverType = NE_SOLVER_TYPE_DAE ; expl_temp_p . mSolverTolerance =
modelParameters_mSolverTolerance ; expl_temp_p . mLoggingMode =
SSC_LOGGING_NONE ; expl_temp_p . mLoadInitialState = false ; expl_temp_p .
mLinTrimCompile = false ; expl_temp_p . mFixedStepSize =
modelParameters_mFixedStepSize ; tmp = nesl_initialize_simulator ( simulator
, expl_temp_p , & fimtsVector_p , diagnosticManager ) ; if ( tmp != 0 ) { tmp
= rtw_diagnostics_message_count ( ) ; if ( tmp == 0 ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
simulationData = ( NeslSimulationData * ) rtDW . b2mtd04ww2 ; time_p = ssGetT
( rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time_p ; simulationData -> mData -> mContStates . mN = 0 ;
simulationData -> mData -> mContStates . mX = NULL ; simulationData -> mData
-> mDiscStates . mN = 0 ; simulationData -> mData -> mDiscStates . mX = NULL
; simulationData -> mData -> mModeVector . mN = 0 ; simulationData -> mData
-> mModeVector . mX = NULL ; modelParameters_mVariableStepSolver = (
ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents
) ; simulationData -> mData -> mFoundZcEvents =
modelParameters_mVariableStepSolver ; simulationData -> mData ->
mIsMajorTimeStep = true ; modelParameters_mVariableStepSolver = (
ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck =
modelParameters_mVariableStepSolver ; modelParameters_mVariableStepSolver =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = modelParameters_mVariableStepSolver ; simulationData
-> mData -> mIsComputingJacobian = false ;
modelParameters_mVariableStepSolver = ssIsSolverRequestingReset ( rtS ) ;
simulationData -> mData -> mIsSolverRequestingReset =
modelParameters_mVariableStepSolver ; simulator = ( NeslSimulator * ) rtDW .
akflnq5gjx ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW . mxmjsp3mlq
; diagnosticTree = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp = ne_simulator_method ( simulator , NESL_SIM_START
, simulationData , diagnosticManager ) ; if ( tmp != 0 ) { tmp =
rtw_diagnostics_message_count ( ) ; if ( tmp == 0 ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
simulator = nesl_lease_simulator (
"Ensayos_Friccion/DeltaSM/Solver Configuration1" , 2 , 0 ) ; rtDW .
depbo03vrk = ( void * ) simulator ; modelParameters_mVariableStepSolver =
pointer_is_null ( rtDW . depbo03vrk ) ; if (
modelParameters_mVariableStepSolver ) { Ensayos_Friccion_fe93f61_gateway ( )
; simulator = nesl_lease_simulator (
"Ensayos_Friccion/DeltaSM/Solver Configuration1" , 2 , 0 ) ; rtDW .
depbo03vrk = ( void * ) simulator ; } simulationData =
nesl_create_simulation_data ( ) ; rtDW . bjxpzefqp3 = ( void * )
simulationData ; diagnosticManager = rtw_create_diagnostics ( ) ; rtDW .
g5mb0p1qhu = ( void * ) diagnosticManager ; fimts_e [ 0U ] = false ; fimts_e
[ 1U ] = true ; fimts_e [ 2U ] = true ; fimtsVector_e . mN = 3 ;
fimtsVector_e . mX = & fimts_e [ 0U ] ; modelParameters_mSolverTolerance =
0.001 ; modelParameters_mFixedStepSize = 0.0 ;
modelParameters_mVariableStepSolver = true ; simulator = ( NeslSimulator * )
rtDW . depbo03vrk ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW .
g5mb0p1qhu ; diagnosticTree = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; expl_temp_e . mVariableStepSolver =
modelParameters_mVariableStepSolver ; expl_temp_e . mUseSimState = false ;
expl_temp_e . mStartTime = 0.0 ; expl_temp_e . mSolverType =
NE_SOLVER_TYPE_DAE ; expl_temp_e . mSolverTolerance =
modelParameters_mSolverTolerance ; expl_temp_e . mLoggingMode =
SSC_LOGGING_NONE ; expl_temp_e . mLoadInitialState = false ; expl_temp_e .
mLinTrimCompile = false ; expl_temp_e . mFixedStepSize =
modelParameters_mFixedStepSize ; tmp = nesl_initialize_simulator ( simulator
, expl_temp_e , & fimtsVector_e , diagnosticManager ) ; if ( tmp != 0 ) { tmp
= rtw_diagnostics_message_count ( ) ; if ( tmp == 0 ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
simulationData = ( NeslSimulationData * ) rtDW . bjxpzefqp3 ; time_e = ssGetT
( rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time_e ; simulationData -> mData -> mContStates . mN = 0 ;
simulationData -> mData -> mContStates . mX = NULL ; simulationData -> mData
-> mDiscStates . mN = 1 ; simulationData -> mData -> mDiscStates . mX = &
rtDW . px2h4fxqvc ; simulationData -> mData -> mModeVector . mN = 0 ;
simulationData -> mData -> mModeVector . mX = NULL ;
modelParameters_mVariableStepSolver = ( ssIsMajorTimeStep ( rtS ) &&
ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents ) ; simulationData -> mData
-> mFoundZcEvents = modelParameters_mVariableStepSolver ; simulationData ->
mData -> mIsMajorTimeStep = true ; modelParameters_mVariableStepSolver = (
ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck =
modelParameters_mVariableStepSolver ; modelParameters_mVariableStepSolver =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = modelParameters_mVariableStepSolver ; simulationData
-> mData -> mIsComputingJacobian = false ;
modelParameters_mVariableStepSolver = ssIsSolverRequestingReset ( rtS ) ;
simulationData -> mData -> mIsSolverRequestingReset =
modelParameters_mVariableStepSolver ; simulator = ( NeslSimulator * ) rtDW .
depbo03vrk ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW . g5mb0p1qhu
; diagnosticTree = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp = ne_simulator_method ( simulator , NESL_SIM_START
, simulationData , diagnosticManager ) ; if ( tmp != 0 ) { tmp =
rtw_diagnostics_message_count ( ) ; if ( tmp == 0 ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
simulator = nesl_lease_simulator (
"Ensayos_Friccion/DeltaSM/Solver Configuration1" , 2 , 1 ) ; rtDW .
eioh2xr3aq = ( void * ) simulator ; modelParameters_mVariableStepSolver =
pointer_is_null ( rtDW . eioh2xr3aq ) ; if (
modelParameters_mVariableStepSolver ) { Ensayos_Friccion_fe93f61_gateway ( )
; simulator = nesl_lease_simulator (
"Ensayos_Friccion/DeltaSM/Solver Configuration1" , 2 , 1 ) ; rtDW .
eioh2xr3aq = ( void * ) simulator ; } simulationData =
nesl_create_simulation_data ( ) ; rtDW . khywewrhhg = ( void * )
simulationData ; diagnosticManager = rtw_create_diagnostics ( ) ; rtDW .
gr25vq2fuc = ( void * ) diagnosticManager ; fimts_i [ 0U ] = false ; fimts_i
[ 1U ] = true ; fimts_i [ 2U ] = true ; fimtsVector_i . mN = 3 ;
fimtsVector_i . mX = & fimts_i [ 0U ] ; modelParameters_mSolverTolerance =
0.001 ; modelParameters_mFixedStepSize = 0.0 ;
modelParameters_mVariableStepSolver = true ; simulator = ( NeslSimulator * )
rtDW . eioh2xr3aq ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW .
gr25vq2fuc ; diagnosticTree = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; expl_temp_i . mVariableStepSolver =
modelParameters_mVariableStepSolver ; expl_temp_i . mUseSimState = false ;
expl_temp_i . mStartTime = 0.0 ; expl_temp_i . mSolverType =
NE_SOLVER_TYPE_DAE ; expl_temp_i . mSolverTolerance =
modelParameters_mSolverTolerance ; expl_temp_i . mLoggingMode =
SSC_LOGGING_NONE ; expl_temp_i . mLoadInitialState = false ; expl_temp_i .
mLinTrimCompile = false ; expl_temp_i . mFixedStepSize =
modelParameters_mFixedStepSize ; tmp = nesl_initialize_simulator ( simulator
, expl_temp_i , & fimtsVector_i , diagnosticManager ) ; if ( tmp != 0 ) { tmp
= rtw_diagnostics_message_count ( ) ; if ( tmp == 0 ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
simulationData = ( NeslSimulationData * ) rtDW . khywewrhhg ; time_i = ssGetT
( rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time_i ; simulationData -> mData -> mContStates . mN = 0 ;
simulationData -> mData -> mContStates . mX = NULL ; simulationData -> mData
-> mDiscStates . mN = 1 ; simulationData -> mData -> mDiscStates . mX = &
rtDW . gt0elxwjeb ; simulationData -> mData -> mModeVector . mN = 0 ;
simulationData -> mData -> mModeVector . mX = NULL ;
modelParameters_mVariableStepSolver = ( ssIsMajorTimeStep ( rtS ) &&
ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents ) ; simulationData -> mData
-> mFoundZcEvents = modelParameters_mVariableStepSolver ; simulationData ->
mData -> mIsMajorTimeStep = true ; modelParameters_mVariableStepSolver = (
ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck =
modelParameters_mVariableStepSolver ; modelParameters_mVariableStepSolver =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = modelParameters_mVariableStepSolver ; simulationData
-> mData -> mIsComputingJacobian = false ;
modelParameters_mVariableStepSolver = ssIsSolverRequestingReset ( rtS ) ;
simulationData -> mData -> mIsSolverRequestingReset =
modelParameters_mVariableStepSolver ; simulator = ( NeslSimulator * ) rtDW .
eioh2xr3aq ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW . gr25vq2fuc
; diagnosticTree = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp = ne_simulator_method ( simulator , NESL_SIM_START
, simulationData , diagnosticManager ) ; if ( tmp != 0 ) { tmp =
rtw_diagnostics_message_count ( ) ; if ( tmp == 0 ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
simulator = nesl_lease_simulator (
"Ensayos_Friccion/DeltaSM/Solver Configuration1" , 0 , 0 ) ; rtDW .
lwg50jsxft = ( void * ) simulator ; modelParameters_mVariableStepSolver =
pointer_is_null ( rtDW . lwg50jsxft ) ; if (
modelParameters_mVariableStepSolver ) { Ensayos_Friccion_fe93f61_gateway ( )
; simulator = nesl_lease_simulator (
"Ensayos_Friccion/DeltaSM/Solver Configuration1" , 0 , 0 ) ; rtDW .
lwg50jsxft = ( void * ) simulator ; } simulationData =
nesl_create_simulation_data ( ) ; rtDW . j1rpvtehmk = ( void * )
simulationData ; diagnosticManager = rtw_create_diagnostics ( ) ; rtDW .
lidhiurvks = ( void * ) diagnosticManager ; fimts_m [ 0U ] = false ; fimts_m
[ 1U ] = false ; fimtsVector_m . mN = 2 ; fimtsVector_m . mX = & fimts_m [ 0U
] ; modelParameters_mSolverTolerance = 0.001 ; modelParameters_mFixedStepSize
= 0.0 ; modelParameters_mVariableStepSolver = true ; simulator = (
NeslSimulator * ) rtDW . lwg50jsxft ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . lidhiurvks ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; expl_temp_m .
mVariableStepSolver = modelParameters_mVariableStepSolver ; expl_temp_m .
mUseSimState = false ; expl_temp_m . mStartTime = 0.0 ; expl_temp_m .
mSolverType = NE_SOLVER_TYPE_DAE ; expl_temp_m . mSolverTolerance =
modelParameters_mSolverTolerance ; expl_temp_m . mLoggingMode =
SSC_LOGGING_NONE ; expl_temp_m . mLoadInitialState = false ; expl_temp_m .
mLinTrimCompile = false ; expl_temp_m . mFixedStepSize =
modelParameters_mFixedStepSize ; tmp = nesl_initialize_simulator ( simulator
, expl_temp_m , & fimtsVector_m , diagnosticManager ) ; if ( tmp != 0 ) { tmp
= rtw_diagnostics_message_count ( ) ; if ( tmp == 0 ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
simulationData = ( NeslSimulationData * ) rtDW . j1rpvtehmk ; time_m = ssGetT
( rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time_m ; simulationData -> mData -> mContStates . mN = 1 ;
simulationData -> mData -> mContStates . mX = & rtX . axhrigh31z ;
simulationData -> mData -> mDiscStates . mN = 0 ; simulationData -> mData ->
mDiscStates . mX = NULL ; simulationData -> mData -> mModeVector . mN = 0 ;
simulationData -> mData -> mModeVector . mX = NULL ;
modelParameters_mVariableStepSolver = ( ssIsMajorTimeStep ( rtS ) &&
ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents ) ; simulationData -> mData
-> mFoundZcEvents = modelParameters_mVariableStepSolver ; simulationData ->
mData -> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ;
modelParameters_mVariableStepSolver = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags .
solverAssertCheck == 1U ) ; simulationData -> mData -> mIsSolverAssertCheck =
modelParameters_mVariableStepSolver ; modelParameters_mVariableStepSolver =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = modelParameters_mVariableStepSolver ;
modelParameters_mVariableStepSolver = ssIsSolverComputingJacobian ( rtS ) ;
simulationData -> mData -> mIsComputingJacobian =
modelParameters_mVariableStepSolver ; modelParameters_mVariableStepSolver =
ssIsSolverRequestingReset ( rtS ) ; simulationData -> mData ->
mIsSolverRequestingReset = modelParameters_mVariableStepSolver ; simulator =
( NeslSimulator * ) rtDW . lwg50jsxft ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . lidhiurvks ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; tmp =
ne_simulator_method ( simulator , NESL_SIM_START , simulationData ,
diagnosticManager ) ; if ( tmp != 0 ) { tmp = rtw_diagnostics_message_count (
) ; if ( tmp == 0 ) { msg = rtw_diagnostics_msg ( diagnosticTree ) ;
ssSetErrorStatus ( rtS , msg ) ; } } simulator = nesl_lease_simulator (
"Ensayos_Friccion/DeltaSM/Solver Configuration1" , 3 , 0 ) ; rtDW .
ko5bzgm54o = ( void * ) simulator ; modelParameters_mVariableStepSolver =
pointer_is_null ( rtDW . ko5bzgm54o ) ; if (
modelParameters_mVariableStepSolver ) { Ensayos_Friccion_fe93f61_gateway ( )
; simulator = nesl_lease_simulator (
"Ensayos_Friccion/DeltaSM/Solver Configuration1" , 3 , 0 ) ; rtDW .
ko5bzgm54o = ( void * ) simulator ; } simulationData =
nesl_create_simulation_data ( ) ; rtDW . hlaipun4ez = ( void * )
simulationData ; diagnosticManager = rtw_create_diagnostics ( ) ; rtDW .
amndknbiec = ( void * ) diagnosticManager ; fimts_g [ 0U ] = false ; fimts_g
[ 1U ] = false ; fimts_g [ 2U ] = false ; fimtsVector_g . mN = 3 ;
fimtsVector_g . mX = & fimts_g [ 0U ] ; modelParameters_mSolverTolerance =
0.001 ; modelParameters_mFixedStepSize = 0.0 ;
modelParameters_mVariableStepSolver = true ; simulator = ( NeslSimulator * )
rtDW . ko5bzgm54o ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW .
amndknbiec ; diagnosticTree = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; expl_temp_g . mVariableStepSolver =
modelParameters_mVariableStepSolver ; expl_temp_g . mUseSimState = false ;
expl_temp_g . mStartTime = 0.0 ; expl_temp_g . mSolverType =
NE_SOLVER_TYPE_DAE ; expl_temp_g . mSolverTolerance =
modelParameters_mSolverTolerance ; expl_temp_g . mLoggingMode =
SSC_LOGGING_NONE ; expl_temp_g . mLoadInitialState = false ; expl_temp_g .
mLinTrimCompile = false ; expl_temp_g . mFixedStepSize =
modelParameters_mFixedStepSize ; tmp = nesl_initialize_simulator ( simulator
, expl_temp_g , & fimtsVector_g , diagnosticManager ) ; if ( tmp != 0 ) { tmp
= rtw_diagnostics_message_count ( ) ; if ( tmp == 0 ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
simulationData = ( NeslSimulationData * ) rtDW . hlaipun4ez ; time_g = ssGetT
( rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time_g ; simulationData -> mData -> mContStates . mN = 0 ;
simulationData -> mData -> mContStates . mX = NULL ; simulationData -> mData
-> mDiscStates . mN = 0 ; simulationData -> mData -> mDiscStates . mX = NULL
; simulationData -> mData -> mModeVector . mN = 0 ; simulationData -> mData
-> mModeVector . mX = NULL ; modelParameters_mVariableStepSolver = (
ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents
) ; simulationData -> mData -> mFoundZcEvents =
modelParameters_mVariableStepSolver ; simulationData -> mData ->
mIsMajorTimeStep = true ; modelParameters_mVariableStepSolver = (
ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck =
modelParameters_mVariableStepSolver ; modelParameters_mVariableStepSolver =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = modelParameters_mVariableStepSolver ; simulationData
-> mData -> mIsComputingJacobian = false ;
modelParameters_mVariableStepSolver = ssIsSolverRequestingReset ( rtS ) ;
simulationData -> mData -> mIsSolverRequestingReset =
modelParameters_mVariableStepSolver ; simulator = ( NeslSimulator * ) rtDW .
ko5bzgm54o ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW . amndknbiec
; diagnosticTree = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp = ne_simulator_method ( simulator , NESL_SIM_START
, simulationData , diagnosticManager ) ; if ( tmp != 0 ) { tmp =
rtw_diagnostics_message_count ( ) ; if ( tmp == 0 ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
simulator = nesl_lease_simulator (
"Ensayos_Friccion/DeltaSM/Solver Configuration1" , 1 , 0 ) ; rtDW .
jm0fzi1blb = ( void * ) simulator ; modelParameters_mVariableStepSolver =
pointer_is_null ( rtDW . jm0fzi1blb ) ; if (
modelParameters_mVariableStepSolver ) { Ensayos_Friccion_fe93f61_gateway ( )
; simulator = nesl_lease_simulator (
"Ensayos_Friccion/DeltaSM/Solver Configuration1" , 1 , 0 ) ; rtDW .
jm0fzi1blb = ( void * ) simulator ; } simulationData =
nesl_create_simulation_data ( ) ; rtDW . op23awaojj = ( void * )
simulationData ; diagnosticManager = rtw_create_diagnostics ( ) ; rtDW .
ioyxzcapgj = ( void * ) diagnosticManager ; fimts_j [ 0U ] = false ; fimts_j
[ 1U ] = false ; fimts_j [ 2U ] = false ; fimtsVector_j . mN = 3 ;
fimtsVector_j . mX = & fimts_j [ 0U ] ; modelParameters_mSolverTolerance =
0.001 ; modelParameters_mFixedStepSize = 0.0 ;
modelParameters_mVariableStepSolver = true ; simulator = ( NeslSimulator * )
rtDW . jm0fzi1blb ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW .
ioyxzcapgj ; diagnosticTree = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; expl_temp_j . mVariableStepSolver =
modelParameters_mVariableStepSolver ; expl_temp_j . mUseSimState = false ;
expl_temp_j . mStartTime = 0.0 ; expl_temp_j . mSolverType =
NE_SOLVER_TYPE_DAE ; expl_temp_j . mSolverTolerance =
modelParameters_mSolverTolerance ; expl_temp_j . mLoggingMode =
SSC_LOGGING_NONE ; expl_temp_j . mLoadInitialState = false ; expl_temp_j .
mLinTrimCompile = false ; expl_temp_j . mFixedStepSize =
modelParameters_mFixedStepSize ; tmp = nesl_initialize_simulator ( simulator
, expl_temp_j , & fimtsVector_j , diagnosticManager ) ; if ( tmp != 0 ) { tmp
= rtw_diagnostics_message_count ( ) ; if ( tmp == 0 ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
simulationData = ( NeslSimulationData * ) rtDW . op23awaojj ; time_j = ssGetT
( rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time_j ; simulationData -> mData -> mContStates . mN = 0 ;
simulationData -> mData -> mContStates . mX = NULL ; simulationData -> mData
-> mDiscStates . mN = 0 ; simulationData -> mData -> mDiscStates . mX = NULL
; simulationData -> mData -> mModeVector . mN = 0 ; simulationData -> mData
-> mModeVector . mX = NULL ; modelParameters_mVariableStepSolver = (
ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents
) ; simulationData -> mData -> mFoundZcEvents =
modelParameters_mVariableStepSolver ; simulationData -> mData ->
mIsMajorTimeStep = true ; modelParameters_mVariableStepSolver = (
ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck =
modelParameters_mVariableStepSolver ; modelParameters_mVariableStepSolver =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = modelParameters_mVariableStepSolver ; simulationData
-> mData -> mIsComputingJacobian = false ;
modelParameters_mVariableStepSolver = ssIsSolverRequestingReset ( rtS ) ;
simulationData -> mData -> mIsSolverRequestingReset =
modelParameters_mVariableStepSolver ; simulator = ( NeslSimulator * ) rtDW .
jm0fzi1blb ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW . ioyxzcapgj
; diagnosticTree = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp = ne_simulator_method ( simulator , NESL_SIM_START
, simulationData , diagnosticManager ) ; if ( tmp != 0 ) { tmp =
rtw_diagnostics_message_count ( ) ; if ( tmp == 0 ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
simulator = nesl_lease_simulator (
"Ensayos_Friccion/DeltaSM/Solver Configuration1" , 2 , 2 ) ; rtDW .
aou51eikro = ( void * ) simulator ; modelParameters_mVariableStepSolver =
pointer_is_null ( rtDW . aou51eikro ) ; if (
modelParameters_mVariableStepSolver ) { Ensayos_Friccion_fe93f61_gateway ( )
; simulator = nesl_lease_simulator (
"Ensayos_Friccion/DeltaSM/Solver Configuration1" , 2 , 2 ) ; rtDW .
aou51eikro = ( void * ) simulator ; } simulationData =
nesl_create_simulation_data ( ) ; rtDW . eufaiemnot = ( void * )
simulationData ; diagnosticManager = rtw_create_diagnostics ( ) ; rtDW .
ewleodkp1x = ( void * ) diagnosticManager ; fimts_f [ 0U ] = false ; fimts_f
[ 1U ] = false ; fimts_f [ 2U ] = false ; fimtsVector_f . mN = 3 ;
fimtsVector_f . mX = & fimts_f [ 0U ] ; modelParameters_mSolverTolerance =
0.001 ; modelParameters_mFixedStepSize = 0.0 ;
modelParameters_mVariableStepSolver = true ; simulator = ( NeslSimulator * )
rtDW . aou51eikro ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW .
ewleodkp1x ; diagnosticTree = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; expl_temp_f . mVariableStepSolver =
modelParameters_mVariableStepSolver ; expl_temp_f . mUseSimState = false ;
expl_temp_f . mStartTime = 0.0 ; expl_temp_f . mSolverType =
NE_SOLVER_TYPE_DAE ; expl_temp_f . mSolverTolerance =
modelParameters_mSolverTolerance ; expl_temp_f . mLoggingMode =
SSC_LOGGING_NONE ; expl_temp_f . mLoadInitialState = false ; expl_temp_f .
mLinTrimCompile = false ; expl_temp_f . mFixedStepSize =
modelParameters_mFixedStepSize ; tmp = nesl_initialize_simulator ( simulator
, expl_temp_f , & fimtsVector_f , diagnosticManager ) ; if ( tmp != 0 ) { tmp
= rtw_diagnostics_message_count ( ) ; if ( tmp == 0 ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
simulationData = ( NeslSimulationData * ) rtDW . eufaiemnot ; time_f = ssGetT
( rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time_f ; simulationData -> mData -> mContStates . mN = 0 ;
simulationData -> mData -> mContStates . mX = NULL ; simulationData -> mData
-> mDiscStates . mN = 1 ; simulationData -> mData -> mDiscStates . mX = &
rtDW . j0qqzzt21t ; simulationData -> mData -> mModeVector . mN = 0 ;
simulationData -> mData -> mModeVector . mX = NULL ;
modelParameters_mVariableStepSolver = ( ssIsMajorTimeStep ( rtS ) &&
ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents ) ; simulationData -> mData
-> mFoundZcEvents = modelParameters_mVariableStepSolver ; simulationData ->
mData -> mIsMajorTimeStep = true ; modelParameters_mVariableStepSolver = (
ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck =
modelParameters_mVariableStepSolver ; modelParameters_mVariableStepSolver =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = modelParameters_mVariableStepSolver ; simulationData
-> mData -> mIsComputingJacobian = false ;
modelParameters_mVariableStepSolver = ssIsSolverRequestingReset ( rtS ) ;
simulationData -> mData -> mIsSolverRequestingReset =
modelParameters_mVariableStepSolver ; simulator = ( NeslSimulator * ) rtDW .
aou51eikro ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW . ewleodkp1x
; diagnosticTree = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp = ne_simulator_method ( simulator , NESL_SIM_START
, simulationData , diagnosticManager ) ; if ( tmp != 0 ) { tmp =
rtw_diagnostics_message_count ( ) ; if ( tmp == 0 ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
simulator = nesl_lease_simulator (
"Ensayos_Friccion/DeltaSM/Solver Configuration1" , 1 , 1 ) ; rtDW .
nfcjhvjxuy = ( void * ) simulator ; modelParameters_mVariableStepSolver =
pointer_is_null ( rtDW . nfcjhvjxuy ) ; if (
modelParameters_mVariableStepSolver ) { Ensayos_Friccion_fe93f61_gateway ( )
; simulator = nesl_lease_simulator (
"Ensayos_Friccion/DeltaSM/Solver Configuration1" , 1 , 1 ) ; rtDW .
nfcjhvjxuy = ( void * ) simulator ; } simulationData =
nesl_create_simulation_data ( ) ; rtDW . osydjefyeb = ( void * )
simulationData ; diagnosticManager = rtw_create_diagnostics ( ) ; rtDW .
alt2ulitdc = ( void * ) diagnosticManager ; fimts_c [ 0U ] = false ; fimts_c
[ 1U ] = false ; fimtsVector_c . mN = 2 ; fimtsVector_c . mX = & fimts_c [ 0U
] ; modelParameters_mSolverTolerance = 0.001 ; modelParameters_mFixedStepSize
= 0.0 ; modelParameters_mVariableStepSolver = true ; simulator = (
NeslSimulator * ) rtDW . nfcjhvjxuy ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . alt2ulitdc ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; expl_temp_c .
mVariableStepSolver = modelParameters_mVariableStepSolver ; expl_temp_c .
mUseSimState = false ; expl_temp_c . mStartTime = 0.0 ; expl_temp_c .
mSolverType = NE_SOLVER_TYPE_DAE ; expl_temp_c . mSolverTolerance =
modelParameters_mSolverTolerance ; expl_temp_c . mLoggingMode =
SSC_LOGGING_NONE ; expl_temp_c . mLoadInitialState = false ; expl_temp_c .
mLinTrimCompile = false ; expl_temp_c . mFixedStepSize =
modelParameters_mFixedStepSize ; tmp = nesl_initialize_simulator ( simulator
, expl_temp_c , & fimtsVector_c , diagnosticManager ) ; if ( tmp != 0 ) { tmp
= rtw_diagnostics_message_count ( ) ; if ( tmp == 0 ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
simulationData = ( NeslSimulationData * ) rtDW . osydjefyeb ; time_c = ssGetT
( rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time_c ; simulationData -> mData -> mContStates . mN = 0 ;
simulationData -> mData -> mContStates . mX = NULL ; simulationData -> mData
-> mDiscStates . mN = 0 ; simulationData -> mData -> mDiscStates . mX = NULL
; simulationData -> mData -> mModeVector . mN = 0 ; simulationData -> mData
-> mModeVector . mX = NULL ; modelParameters_mVariableStepSolver = (
ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents
) ; simulationData -> mData -> mFoundZcEvents =
modelParameters_mVariableStepSolver ; simulationData -> mData ->
mIsMajorTimeStep = true ; modelParameters_mVariableStepSolver = (
ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck =
modelParameters_mVariableStepSolver ; modelParameters_mVariableStepSolver =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = modelParameters_mVariableStepSolver ; simulationData
-> mData -> mIsComputingJacobian = false ;
modelParameters_mVariableStepSolver = ssIsSolverRequestingReset ( rtS ) ;
simulationData -> mData -> mIsSolverRequestingReset =
modelParameters_mVariableStepSolver ; simulator = ( NeslSimulator * ) rtDW .
nfcjhvjxuy ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW . alt2ulitdc
; diagnosticTree = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp = ne_simulator_method ( simulator , NESL_SIM_START
, simulationData , diagnosticManager ) ; if ( tmp != 0 ) { tmp =
rtw_diagnostics_message_count ( ) ; if ( tmp == 0 ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) { NeslSimulationData *
simulationData ; real_T time ; boolean_T tmp ; real_T tmp_p [ 4 ] ; int_T
tmp_e [ 2 ] ; NeslSimulator * simulator ; NeuDiagnosticManager *
diagnosticManager ; NeuDiagnosticTree * diagnosticTree ; int32_T tmp_i ; char
* msg ; real_T time_p ; real_T tmp_m [ 6 ] ; int_T tmp_g [ 3 ] ; real_T
time_e ; real_T tmp_j [ 3 ] ; int_T tmp_f [ 4 ] ; real_T time_i ; real_T
tmp_c [ 3 ] ; int_T tmp_k [ 4 ] ; real_T time_m ; real_T tmp_b [ 8 ] ; int_T
tmp_n [ 3 ] ; real_T time_g ; real_T tmp_l [ 9 ] ; int_T tmp_d [ 4 ] ; real_T
time_j ; real_T tmp_o [ 9 ] ; int_T tmp_dz [ 4 ] ; real_T time_f ; real_T
tmp_fs [ 3 ] ; int_T tmp_ck [ 4 ] ; real_T time_c ; real_T tmp_f2 [ 6 ] ;
int_T tmp_kt [ 3 ] ; real_T nqlygpcuz5 ; simulationData = (
NeslSimulationData * ) rtDW . is0xydhs4l ; time = ssGetT ( rtS ) ;
simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData -> mTime
. mX = & time ; simulationData -> mData -> mContStates . mN = 2 ;
simulationData -> mData -> mContStates . mX = ( real_T * ) & rtX . hdzhv0kuvm
; simulationData -> mData -> mDiscStates . mN = 0 ; simulationData -> mData
-> mDiscStates . mX = NULL ; simulationData -> mData -> mModeVector . mN = 0
; simulationData -> mData -> mModeVector . mX = NULL ; tmp = (
ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents
) ; simulationData -> mData -> mFoundZcEvents = tmp ; simulationData -> mData
-> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ; tmp = ( ssGetMdlInfoPtr (
rtS ) -> mdlFlags . solverAssertCheck == 1U ) ; simulationData -> mData ->
mIsSolverAssertCheck = tmp ; tmp = ssIsSolverCheckingCIC ( rtS ) ;
simulationData -> mData -> mIsSolverCheckingCIC = tmp ; tmp =
ssIsSolverComputingJacobian ( rtS ) ; simulationData -> mData ->
mIsComputingJacobian = tmp ; tmp = ssIsSolverRequestingReset ( rtS ) ;
simulationData -> mData -> mIsSolverRequestingReset = tmp ; tmp_e [ 0U ] = 0
; tmp_p [ 0U ] = rtB . ptrzoxc51k [ 0 ] ; tmp_p [ 1U ] = rtB . ptrzoxc51k [ 1
] ; tmp_p [ 2U ] = rtB . ptrzoxc51k [ 2 ] ; tmp_p [ 3U ] = rtB . ptrzoxc51k [
3 ] ; tmp_e [ 1U ] = 4 ; simulationData -> mData -> mInputValues . mN = 4 ;
simulationData -> mData -> mInputValues . mX = & tmp_p [ 0U ] ;
simulationData -> mData -> mInputOffsets . mN = 2 ; simulationData -> mData
-> mInputOffsets . mX = & tmp_e [ 0U ] ; simulationData -> mData -> mOutputs
. mN = 2 ; simulationData -> mData -> mOutputs . mX = & rtB . mb32kofeaj [ 0U
] ; simulationData -> mData -> mSampleHits . mN = 0 ; simulationData -> mData
-> mSampleHits . mX = NULL ; simulationData -> mData ->
mIsFundamentalSampleHit = false ; simulator = ( NeslSimulator * ) rtDW .
gk0htlbrma ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW . ka0rn1jqlo
; diagnosticTree = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp_i = ne_simulator_method ( simulator ,
NESL_SIM_OUTPUTS , simulationData , diagnosticManager ) ; if ( tmp_i != 0 ) {
tmp_i = rtw_diagnostics_message_count ( ) ; if ( tmp_i == 0 ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
simulationData = ( NeslSimulationData * ) rtDW . b2mtd04ww2 ; time_p = ssGetT
( rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time_p ; simulationData -> mData -> mContStates . mN = 0 ;
simulationData -> mData -> mContStates . mX = NULL ; simulationData -> mData
-> mDiscStates . mN = 0 ; simulationData -> mData -> mDiscStates . mX = NULL
; simulationData -> mData -> mModeVector . mN = 0 ; simulationData -> mData
-> mModeVector . mX = NULL ; tmp = ( ssIsMajorTimeStep ( rtS ) &&
ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents ) ; simulationData -> mData
-> mFoundZcEvents = tmp ; simulationData -> mData -> mIsMajorTimeStep = true
; tmp = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = tmp ; tmp =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = tmp ; simulationData -> mData -> mIsComputingJacobian
= false ; tmp = ssIsSolverRequestingReset ( rtS ) ; simulationData -> mData
-> mIsSolverRequestingReset = tmp ; tmp_g [ 0U ] = 0 ; tmp_m [ 0U ] = rtB .
ptrzoxc51k [ 0 ] ; tmp_m [ 1U ] = rtB . ptrzoxc51k [ 1 ] ; tmp_m [ 2U ] = rtB
. ptrzoxc51k [ 2 ] ; tmp_m [ 3U ] = rtB . ptrzoxc51k [ 3 ] ; tmp_g [ 1U ] = 4
; tmp_m [ 4U ] = rtB . mb32kofeaj [ 0 ] ; tmp_m [ 5U ] = rtB . mb32kofeaj [ 1
] ; tmp_g [ 2U ] = 6 ; simulationData -> mData -> mInputValues . mN = 6 ;
simulationData -> mData -> mInputValues . mX = & tmp_m [ 0U ] ;
simulationData -> mData -> mInputOffsets . mN = 3 ; simulationData -> mData
-> mInputOffsets . mX = & tmp_g [ 0U ] ; simulationData -> mData -> mOutputs
. mN = 2 ; simulationData -> mData -> mOutputs . mX = & rtB . jygob3b3q4 [ 0U
] ; simulationData -> mData -> mSampleHits . mN = 0 ; simulationData -> mData
-> mSampleHits . mX = NULL ; simulationData -> mData ->
mIsFundamentalSampleHit = false ; simulator = ( NeslSimulator * ) rtDW .
akflnq5gjx ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW . mxmjsp3mlq
; diagnosticTree = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp_i = ne_simulator_method ( simulator ,
NESL_SIM_OUTPUTS , simulationData , diagnosticManager ) ; if ( tmp_i != 0 ) {
tmp_i = rtw_diagnostics_message_count ( ) ; if ( tmp_i == 0 ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
rtB . og0vqabzz1 = rtB . jygob3b3q4 [ 1 ] ; rtB . jrcr0hqppv = rtP .
Gain_Gain * rtB . jygob3b3q4 [ 1 ] ; nqlygpcuz5 = muDoubleScalarTanh ( rtB .
jrcr0hqppv ) ; rtB . jsceoxumdg = rtP . Fs_Gain * nqlygpcuz5 ; rtB .
bbrhi2aa4o = rtP . Fc_Gain * rtB . jygob3b3q4 [ 1 ] ; if ( ssIsMajorTimeStep
( rtS ) ) { rtDW . nujczoxr2h = rtB . jygob3b3q4 [ 1 ] >= 0.0 ? 1 : 0 ; } rtB
. n3sk3m5mid = rtDW . nujczoxr2h > 0 ? rtB . jygob3b3q4 [ 1 ] : - rtB .
jygob3b3q4 [ 1 ] ; rtB . kxibtkeec5 = rtP . To_Gain * rtB . n3sk3m5mid ; rtB
. enw5bh50ec = rtP . Constant_Value - muDoubleScalarExp ( rtB . kxibtkeec5 )
; rtB . kq2v02wqsv = rtP . Gain3_Gain * rtB . enw5bh50ec ; rtB . csph14lqqx =
nqlygpcuz5 * rtB . kq2v02wqsv ; rtB . jvbzfyxc03 = ( rtB . jsceoxumdg + rtB .
bbrhi2aa4o ) - rtB . csph14lqqx ; simulationData = ( NeslSimulationData * )
rtDW . bjxpzefqp3 ; time_e = ssGetT ( rtS ) ; simulationData -> mData ->
mTime . mN = 1 ; simulationData -> mData -> mTime . mX = & time_e ;
simulationData -> mData -> mContStates . mN = 0 ; simulationData -> mData ->
mContStates . mX = NULL ; simulationData -> mData -> mDiscStates . mN = 1 ;
simulationData -> mData -> mDiscStates . mX = & rtDW . px2h4fxqvc ;
simulationData -> mData -> mModeVector . mN = 0 ; simulationData -> mData ->
mModeVector . mX = NULL ; tmp = ( ssIsMajorTimeStep ( rtS ) &&
ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents ) ; simulationData -> mData
-> mFoundZcEvents = tmp ; simulationData -> mData -> mIsMajorTimeStep = true
; tmp = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = tmp ; tmp =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = tmp ; simulationData -> mData -> mIsComputingJacobian
= false ; tmp = ssIsSolverRequestingReset ( rtS ) ; simulationData -> mData
-> mIsSolverRequestingReset = tmp ; tmp_f [ 0U ] = 0 ; tmp_j [ 0U ] = rtB .
jvbzfyxc03 ; tmp_f [ 1U ] = 1 ; tmp_j [ 1U ] = 0.0 ; tmp_f [ 2U ] = 2 ; tmp_j
[ 2U ] = 0.0 ; tmp_f [ 3U ] = 3 ; simulationData -> mData -> mInputValues .
mN = 3 ; simulationData -> mData -> mInputValues . mX = & tmp_j [ 0U ] ;
simulationData -> mData -> mInputOffsets . mN = 4 ; simulationData -> mData
-> mInputOffsets . mX = & tmp_f [ 0U ] ; simulationData -> mData -> mOutputs
. mN = 4 ; simulationData -> mData -> mOutputs . mX = & rtB . ijqtrjxdsh [ 0U
] ; simulationData -> mData -> mSampleHits . mN = 0 ; simulationData -> mData
-> mSampleHits . mX = NULL ; simulationData -> mData ->
mIsFundamentalSampleHit = false ; simulator = ( NeslSimulator * ) rtDW .
depbo03vrk ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW . g5mb0p1qhu
; diagnosticTree = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp_i = ne_simulator_method ( simulator ,
NESL_SIM_OUTPUTS , simulationData , diagnosticManager ) ; if ( tmp_i != 0 ) {
tmp_i = rtw_diagnostics_message_count ( ) ; if ( tmp_i == 0 ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
rtB . bztakntxrl = rtP . Gain_Gain_b1oehh4m53 * rtB . jygob3b3q4 [ 1 ] ;
nqlygpcuz5 = muDoubleScalarTanh ( rtB . bztakntxrl ) ; rtB . p2zhwbrpql = rtP
. Fs_Gain_gejxjpa1bz * nqlygpcuz5 ; rtB . enns31nw1s = rtP .
Fc_Gain_ncx454w25g * rtB . jygob3b3q4 [ 1 ] ; if ( ssIsMajorTimeStep ( rtS )
) { rtDW . mkghkkvf3s = rtB . jygob3b3q4 [ 1 ] >= 0.0 ? 1 : 0 ; } rtB .
jejwlkbmc2 = rtDW . mkghkkvf3s > 0 ? rtB . jygob3b3q4 [ 1 ] : - rtB .
jygob3b3q4 [ 1 ] ; rtB . dessyx1zav = rtP . To_Gain_oixd02jkdm * rtB .
jejwlkbmc2 ; rtB . ctssu21gdv = rtP . Constant_Value_nicvna5tcb -
muDoubleScalarExp ( rtB . dessyx1zav ) ; rtB . orlilvcezk = rtP .
Gain3_Gain_oxdnjjsq1e * rtB . ctssu21gdv ; rtB . dbi3o4yn43 = nqlygpcuz5 *
rtB . orlilvcezk ; rtB . kcfeei3ce0 = ( rtB . p2zhwbrpql + rtB . enns31nw1s )
- rtB . dbi3o4yn43 ; simulationData = ( NeslSimulationData * ) rtDW .
khywewrhhg ; time_i = ssGetT ( rtS ) ; simulationData -> mData -> mTime . mN
= 1 ; simulationData -> mData -> mTime . mX = & time_i ; simulationData ->
mData -> mContStates . mN = 0 ; simulationData -> mData -> mContStates . mX =
NULL ; simulationData -> mData -> mDiscStates . mN = 1 ; simulationData ->
mData -> mDiscStates . mX = & rtDW . gt0elxwjeb ; simulationData -> mData ->
mModeVector . mN = 0 ; simulationData -> mData -> mModeVector . mX = NULL ;
tmp = ( ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo ( rtS ) ->
foundContZcEvents ) ; simulationData -> mData -> mFoundZcEvents = tmp ;
simulationData -> mData -> mIsMajorTimeStep = true ; tmp = ( ssGetMdlInfoPtr
( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ; simulationData -> mData ->
mIsSolverAssertCheck = tmp ; tmp = ssIsSolverCheckingCIC ( rtS ) ;
simulationData -> mData -> mIsSolverCheckingCIC = tmp ; simulationData ->
mData -> mIsComputingJacobian = false ; tmp = ssIsSolverRequestingReset ( rtS
) ; simulationData -> mData -> mIsSolverRequestingReset = tmp ; tmp_k [ 0U ]
= 0 ; tmp_c [ 0U ] = rtB . kcfeei3ce0 ; tmp_k [ 1U ] = 1 ; tmp_c [ 1U ] = 0.0
; tmp_k [ 2U ] = 2 ; tmp_c [ 2U ] = 0.0 ; tmp_k [ 3U ] = 3 ; simulationData
-> mData -> mInputValues . mN = 3 ; simulationData -> mData -> mInputValues .
mX = & tmp_c [ 0U ] ; simulationData -> mData -> mInputOffsets . mN = 4 ;
simulationData -> mData -> mInputOffsets . mX = & tmp_k [ 0U ] ;
simulationData -> mData -> mOutputs . mN = 4 ; simulationData -> mData ->
mOutputs . mX = & rtB . apvpvqneyh [ 0U ] ; simulationData -> mData ->
mSampleHits . mN = 0 ; simulationData -> mData -> mSampleHits . mX = NULL ;
simulationData -> mData -> mIsFundamentalSampleHit = false ; simulator = (
NeslSimulator * ) rtDW . eioh2xr3aq ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . gr25vq2fuc ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; tmp_i =
ne_simulator_method ( simulator , NESL_SIM_OUTPUTS , simulationData ,
diagnosticManager ) ; if ( tmp_i != 0 ) { tmp_i =
rtw_diagnostics_message_count ( ) ; if ( tmp_i == 0 ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
simulationData = ( NeslSimulationData * ) rtDW . j1rpvtehmk ; time_m = ssGetT
( rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time_m ; simulationData -> mData -> mContStates . mN = 1 ;
simulationData -> mData -> mContStates . mX = & rtX . axhrigh31z ;
simulationData -> mData -> mDiscStates . mN = 0 ; simulationData -> mData ->
mDiscStates . mX = NULL ; simulationData -> mData -> mModeVector . mN = 0 ;
simulationData -> mData -> mModeVector . mX = NULL ; tmp = (
ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents
) ; simulationData -> mData -> mFoundZcEvents = tmp ; simulationData -> mData
-> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ; tmp = ( ssGetMdlInfoPtr (
rtS ) -> mdlFlags . solverAssertCheck == 1U ) ; simulationData -> mData ->
mIsSolverAssertCheck = tmp ; tmp = ssIsSolverCheckingCIC ( rtS ) ;
simulationData -> mData -> mIsSolverCheckingCIC = tmp ; tmp =
ssIsSolverComputingJacobian ( rtS ) ; simulationData -> mData ->
mIsComputingJacobian = tmp ; tmp = ssIsSolverRequestingReset ( rtS ) ;
simulationData -> mData -> mIsSolverRequestingReset = tmp ; tmp_n [ 0U ] = 0
; tmp_b [ 0U ] = rtB . ijqtrjxdsh [ 0 ] ; tmp_b [ 1U ] = rtB . ijqtrjxdsh [ 1
] ; tmp_b [ 2U ] = rtB . ijqtrjxdsh [ 2 ] ; tmp_b [ 3U ] = rtB . ijqtrjxdsh [
3 ] ; tmp_n [ 1U ] = 4 ; tmp_b [ 4U ] = rtB . apvpvqneyh [ 0 ] ; tmp_b [ 5U ]
= rtB . apvpvqneyh [ 1 ] ; tmp_b [ 6U ] = rtB . apvpvqneyh [ 2 ] ; tmp_b [ 7U
] = rtB . apvpvqneyh [ 3 ] ; tmp_n [ 2U ] = 8 ; simulationData -> mData ->
mInputValues . mN = 8 ; simulationData -> mData -> mInputValues . mX = &
tmp_b [ 0U ] ; simulationData -> mData -> mInputOffsets . mN = 3 ;
simulationData -> mData -> mInputOffsets . mX = & tmp_n [ 0U ] ;
simulationData -> mData -> mOutputs . mN = 1 ; simulationData -> mData ->
mOutputs . mX = & rtB . bzizsky3i2 ; simulationData -> mData -> mSampleHits .
mN = 0 ; simulationData -> mData -> mSampleHits . mX = NULL ; simulationData
-> mData -> mIsFundamentalSampleHit = false ; simulator = ( NeslSimulator * )
rtDW . lwg50jsxft ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW .
lidhiurvks ; diagnosticTree = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp_i = ne_simulator_method ( simulator ,
NESL_SIM_OUTPUTS , simulationData , diagnosticManager ) ; if ( tmp_i != 0 ) {
tmp_i = rtw_diagnostics_message_count ( ) ; if ( tmp_i == 0 ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
simulationData = ( NeslSimulationData * ) rtDW . hlaipun4ez ; time_g = ssGetT
( rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time_g ; simulationData -> mData -> mContStates . mN = 0 ;
simulationData -> mData -> mContStates . mX = NULL ; simulationData -> mData
-> mDiscStates . mN = 0 ; simulationData -> mData -> mDiscStates . mX = NULL
; simulationData -> mData -> mModeVector . mN = 0 ; simulationData -> mData
-> mModeVector . mX = NULL ; tmp = ( ssIsMajorTimeStep ( rtS ) &&
ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents ) ; simulationData -> mData
-> mFoundZcEvents = tmp ; simulationData -> mData -> mIsMajorTimeStep = true
; tmp = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = tmp ; tmp =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = tmp ; simulationData -> mData -> mIsComputingJacobian
= false ; tmp = ssIsSolverRequestingReset ( rtS ) ; simulationData -> mData
-> mIsSolverRequestingReset = tmp ; tmp_d [ 0U ] = 0 ; tmp_l [ 0U ] = rtB .
ijqtrjxdsh [ 0 ] ; tmp_l [ 1U ] = rtB . ijqtrjxdsh [ 1 ] ; tmp_l [ 2U ] = rtB
. ijqtrjxdsh [ 2 ] ; tmp_l [ 3U ] = rtB . ijqtrjxdsh [ 3 ] ; tmp_d [ 1U ] = 4
; tmp_l [ 4U ] = rtB . apvpvqneyh [ 0 ] ; tmp_l [ 5U ] = rtB . apvpvqneyh [ 1
] ; tmp_l [ 6U ] = rtB . apvpvqneyh [ 2 ] ; tmp_l [ 7U ] = rtB . apvpvqneyh [
3 ] ; tmp_d [ 2U ] = 8 ; tmp_l [ 8U ] = rtB . bzizsky3i2 ; tmp_d [ 3U ] = 9 ;
simulationData -> mData -> mInputValues . mN = 9 ; simulationData -> mData ->
mInputValues . mX = & tmp_l [ 0U ] ; simulationData -> mData -> mInputOffsets
. mN = 4 ; simulationData -> mData -> mInputOffsets . mX = & tmp_d [ 0U ] ;
simulationData -> mData -> mOutputs . mN = 1 ; simulationData -> mData ->
mOutputs . mX = & rtB . flitgoamze ; simulationData -> mData -> mSampleHits .
mN = 0 ; simulationData -> mData -> mSampleHits . mX = NULL ; simulationData
-> mData -> mIsFundamentalSampleHit = false ; simulator = ( NeslSimulator * )
rtDW . ko5bzgm54o ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW .
amndknbiec ; diagnosticTree = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp_i = ne_simulator_method ( simulator ,
NESL_SIM_OUTPUTS , simulationData , diagnosticManager ) ; if ( tmp_i != 0 ) {
tmp_i = rtw_diagnostics_message_count ( ) ; if ( tmp_i == 0 ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
rtB . ow1luaqdsv = rtB . flitgoamze ; simulationData = ( NeslSimulationData *
) rtDW . op23awaojj ; time_j = ssGetT ( rtS ) ; simulationData -> mData ->
mTime . mN = 1 ; simulationData -> mData -> mTime . mX = & time_j ;
simulationData -> mData -> mContStates . mN = 0 ; simulationData -> mData ->
mContStates . mX = NULL ; simulationData -> mData -> mDiscStates . mN = 0 ;
simulationData -> mData -> mDiscStates . mX = NULL ; simulationData -> mData
-> mModeVector . mN = 0 ; simulationData -> mData -> mModeVector . mX = NULL
; tmp = ( ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo ( rtS ) ->
foundContZcEvents ) ; simulationData -> mData -> mFoundZcEvents = tmp ;
simulationData -> mData -> mIsMajorTimeStep = true ; tmp = ( ssGetMdlInfoPtr
( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ; simulationData -> mData ->
mIsSolverAssertCheck = tmp ; tmp = ssIsSolverCheckingCIC ( rtS ) ;
simulationData -> mData -> mIsSolverCheckingCIC = tmp ; simulationData ->
mData -> mIsComputingJacobian = false ; tmp = ssIsSolverRequestingReset ( rtS
) ; simulationData -> mData -> mIsSolverRequestingReset = tmp ; tmp_dz [ 0U ]
= 0 ; tmp_o [ 0U ] = rtB . ijqtrjxdsh [ 0 ] ; tmp_o [ 1U ] = rtB . ijqtrjxdsh
[ 1 ] ; tmp_o [ 2U ] = rtB . ijqtrjxdsh [ 2 ] ; tmp_o [ 3U ] = rtB .
ijqtrjxdsh [ 3 ] ; tmp_dz [ 1U ] = 4 ; tmp_o [ 4U ] = rtB . apvpvqneyh [ 0 ]
; tmp_o [ 5U ] = rtB . apvpvqneyh [ 1 ] ; tmp_o [ 6U ] = rtB . apvpvqneyh [ 2
] ; tmp_o [ 7U ] = rtB . apvpvqneyh [ 3 ] ; tmp_dz [ 2U ] = 8 ; tmp_o [ 8U ]
= rtB . bzizsky3i2 ; tmp_dz [ 3U ] = 9 ; simulationData -> mData ->
mInputValues . mN = 9 ; simulationData -> mData -> mInputValues . mX = &
tmp_o [ 0U ] ; simulationData -> mData -> mInputOffsets . mN = 4 ;
simulationData -> mData -> mInputOffsets . mX = & tmp_dz [ 0U ] ;
simulationData -> mData -> mOutputs . mN = 0 ; simulationData -> mData ->
mOutputs . mX = NULL ; simulationData -> mData -> mSampleHits . mN = 0 ;
simulationData -> mData -> mSampleHits . mX = NULL ; simulationData -> mData
-> mIsFundamentalSampleHit = false ; simulator = ( NeslSimulator * ) rtDW .
jm0fzi1blb ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW . ioyxzcapgj
; diagnosticTree = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp_i = ne_simulator_method ( simulator ,
NESL_SIM_OUTPUTS , simulationData , diagnosticManager ) ; if ( tmp_i != 0 ) {
tmp_i = rtw_diagnostics_message_count ( ) ; if ( tmp_i == 0 ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
simulationData = ( NeslSimulationData * ) rtDW . eufaiemnot ; time_f = ssGetT
( rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time_f ; simulationData -> mData -> mContStates . mN = 0 ;
simulationData -> mData -> mContStates . mX = NULL ; simulationData -> mData
-> mDiscStates . mN = 1 ; simulationData -> mData -> mDiscStates . mX = &
rtDW . j0qqzzt21t ; simulationData -> mData -> mModeVector . mN = 0 ;
simulationData -> mData -> mModeVector . mX = NULL ; tmp = (
ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents
) ; simulationData -> mData -> mFoundZcEvents = tmp ; simulationData -> mData
-> mIsMajorTimeStep = true ; tmp = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags .
solverAssertCheck == 1U ) ; simulationData -> mData -> mIsSolverAssertCheck =
tmp ; tmp = ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = tmp ; simulationData -> mData -> mIsComputingJacobian
= false ; tmp = ssIsSolverRequestingReset ( rtS ) ; simulationData -> mData
-> mIsSolverRequestingReset = tmp ; tmp_ck [ 0U ] = 0 ; tmp_fs [ 0U ] = rtB .
flitgoamze ; tmp_ck [ 1U ] = 1 ; tmp_fs [ 1U ] = 0.0 ; tmp_ck [ 2U ] = 2 ;
tmp_fs [ 2U ] = 0.0 ; tmp_ck [ 3U ] = 3 ; simulationData -> mData ->
mInputValues . mN = 3 ; simulationData -> mData -> mInputValues . mX = &
tmp_fs [ 0U ] ; simulationData -> mData -> mInputOffsets . mN = 4 ;
simulationData -> mData -> mInputOffsets . mX = & tmp_ck [ 0U ] ;
simulationData -> mData -> mOutputs . mN = 4 ; simulationData -> mData ->
mOutputs . mX = & rtB . ptrzoxc51k [ 0U ] ; simulationData -> mData ->
mSampleHits . mN = 0 ; simulationData -> mData -> mSampleHits . mX = NULL ;
simulationData -> mData -> mIsFundamentalSampleHit = false ; simulator = (
NeslSimulator * ) rtDW . aou51eikro ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . ewleodkp1x ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; tmp_i =
ne_simulator_method ( simulator , NESL_SIM_OUTPUTS , simulationData ,
diagnosticManager ) ; if ( tmp_i != 0 ) { tmp_i =
rtw_diagnostics_message_count ( ) ; if ( tmp_i == 0 ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
simulationData = ( NeslSimulationData * ) rtDW . osydjefyeb ; time_c = ssGetT
( rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time_c ; simulationData -> mData -> mContStates . mN = 0 ;
simulationData -> mData -> mContStates . mX = NULL ; simulationData -> mData
-> mDiscStates . mN = 0 ; simulationData -> mData -> mDiscStates . mX = NULL
; simulationData -> mData -> mModeVector . mN = 0 ; simulationData -> mData
-> mModeVector . mX = NULL ; tmp = ( ssIsMajorTimeStep ( rtS ) &&
ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents ) ; simulationData -> mData
-> mFoundZcEvents = tmp ; simulationData -> mData -> mIsMajorTimeStep = true
; tmp = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = tmp ; tmp =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = tmp ; simulationData -> mData -> mIsComputingJacobian
= false ; tmp = ssIsSolverRequestingReset ( rtS ) ; simulationData -> mData
-> mIsSolverRequestingReset = tmp ; tmp_kt [ 0U ] = 0 ; tmp_f2 [ 0U ] = rtB .
ptrzoxc51k [ 0 ] ; tmp_f2 [ 1U ] = rtB . ptrzoxc51k [ 1 ] ; tmp_f2 [ 2U ] =
rtB . ptrzoxc51k [ 2 ] ; tmp_f2 [ 3U ] = rtB . ptrzoxc51k [ 3 ] ; tmp_kt [ 1U
] = 4 ; tmp_f2 [ 4U ] = rtB . mb32kofeaj [ 0 ] ; tmp_f2 [ 5U ] = rtB .
mb32kofeaj [ 1 ] ; tmp_kt [ 2U ] = 6 ; simulationData -> mData ->
mInputValues . mN = 6 ; simulationData -> mData -> mInputValues . mX = &
tmp_f2 [ 0U ] ; simulationData -> mData -> mInputOffsets . mN = 3 ;
simulationData -> mData -> mInputOffsets . mX = & tmp_kt [ 0U ] ;
simulationData -> mData -> mOutputs . mN = 0 ; simulationData -> mData ->
mOutputs . mX = NULL ; simulationData -> mData -> mSampleHits . mN = 0 ;
simulationData -> mData -> mSampleHits . mX = NULL ; simulationData -> mData
-> mIsFundamentalSampleHit = false ; simulator = ( NeslSimulator * ) rtDW .
nfcjhvjxuy ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW . alt2ulitdc
; diagnosticTree = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp_i = ne_simulator_method ( simulator ,
NESL_SIM_OUTPUTS , simulationData , diagnosticManager ) ; if ( tmp_i != 0 ) {
tmp_i = rtw_diagnostics_message_count ( ) ; if ( tmp_i == 0 ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) { UNUSED_PARAMETER
( tid ) ; } void MdlDerivatives ( void ) { NeslSimulationData *
simulationData ; real_T time ; boolean_T tmp ; real_T tmp_p [ 4 ] ; int_T
tmp_e [ 2 ] ; NeslSimulator * simulator ; NeuDiagnosticManager *
diagnosticManager ; NeuDiagnosticTree * diagnosticTree ; int32_T tmp_i ; char
* msg ; NeslSimulationData * simulationData_p ; real_T time_p ; real_T tmp_m
[ 8 ] ; int_T tmp_g [ 3 ] ; NeslSimulator * simulator_p ;
NeuDiagnosticManager * diagnosticManager_p ; NeuDiagnosticTree *
diagnosticTree_p ; char * msg_p ; XDot * _rtXdot ; _rtXdot = ( ( XDot * )
ssGetdX ( rtS ) ) ; simulationData = ( NeslSimulationData * ) rtDW .
is0xydhs4l ; time = ssGetT ( rtS ) ; simulationData -> mData -> mTime . mN =
1 ; simulationData -> mData -> mTime . mX = & time ; simulationData -> mData
-> mContStates . mN = 2 ; simulationData -> mData -> mContStates . mX = (
real_T * ) & rtX . hdzhv0kuvm ; simulationData -> mData -> mDiscStates . mN =
0 ; simulationData -> mData -> mDiscStates . mX = NULL ; simulationData ->
mData -> mModeVector . mN = 0 ; simulationData -> mData -> mModeVector . mX =
NULL ; tmp = ( ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo ( rtS ) ->
foundContZcEvents ) ; simulationData -> mData -> mFoundZcEvents = tmp ;
simulationData -> mData -> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ; tmp
= ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = tmp ; tmp =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = tmp ; tmp = ssIsSolverComputingJacobian ( rtS ) ;
simulationData -> mData -> mIsComputingJacobian = tmp ; tmp =
ssIsSolverRequestingReset ( rtS ) ; simulationData -> mData ->
mIsSolverRequestingReset = tmp ; tmp_e [ 0U ] = 0 ; tmp_p [ 0U ] = rtB .
ptrzoxc51k [ 0 ] ; tmp_p [ 1U ] = rtB . ptrzoxc51k [ 1 ] ; tmp_p [ 2U ] = rtB
. ptrzoxc51k [ 2 ] ; tmp_p [ 3U ] = rtB . ptrzoxc51k [ 3 ] ; tmp_e [ 1U ] = 4
; simulationData -> mData -> mInputValues . mN = 4 ; simulationData -> mData
-> mInputValues . mX = & tmp_p [ 0U ] ; simulationData -> mData ->
mInputOffsets . mN = 2 ; simulationData -> mData -> mInputOffsets . mX = &
tmp_e [ 0U ] ; simulationData -> mData -> mDx . mN = 2 ; simulationData ->
mData -> mDx . mX = ( real_T * ) & _rtXdot -> hdzhv0kuvm ; simulator = (
NeslSimulator * ) rtDW . gk0htlbrma ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . ka0rn1jqlo ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; tmp_i =
ne_simulator_method ( simulator , NESL_SIM_DERIVATIVES , simulationData ,
diagnosticManager ) ; if ( tmp_i != 0 ) { tmp_i =
rtw_diagnostics_message_count ( ) ; if ( tmp_i == 0 ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
simulationData_p = ( NeslSimulationData * ) rtDW . j1rpvtehmk ; time_p =
ssGetT ( rtS ) ; simulationData_p -> mData -> mTime . mN = 1 ;
simulationData_p -> mData -> mTime . mX = & time_p ; simulationData_p ->
mData -> mContStates . mN = 1 ; simulationData_p -> mData -> mContStates . mX
= & rtX . axhrigh31z ; simulationData_p -> mData -> mDiscStates . mN = 0 ;
simulationData_p -> mData -> mDiscStates . mX = NULL ; simulationData_p ->
mData -> mModeVector . mN = 0 ; simulationData_p -> mData -> mModeVector . mX
= NULL ; tmp = ( ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo ( rtS ) ->
foundContZcEvents ) ; simulationData_p -> mData -> mFoundZcEvents = tmp ;
simulationData_p -> mData -> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ;
tmp = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData_p -> mData -> mIsSolverAssertCheck = tmp ; tmp =
ssIsSolverCheckingCIC ( rtS ) ; simulationData_p -> mData ->
mIsSolverCheckingCIC = tmp ; tmp = ssIsSolverComputingJacobian ( rtS ) ;
simulationData_p -> mData -> mIsComputingJacobian = tmp ; tmp =
ssIsSolverRequestingReset ( rtS ) ; simulationData_p -> mData ->
mIsSolverRequestingReset = tmp ; tmp_g [ 0U ] = 0 ; tmp_m [ 0U ] = rtB .
ijqtrjxdsh [ 0 ] ; tmp_m [ 1U ] = rtB . ijqtrjxdsh [ 1 ] ; tmp_m [ 2U ] = rtB
. ijqtrjxdsh [ 2 ] ; tmp_m [ 3U ] = rtB . ijqtrjxdsh [ 3 ] ; tmp_g [ 1U ] = 4
; tmp_m [ 4U ] = rtB . apvpvqneyh [ 0 ] ; tmp_m [ 5U ] = rtB . apvpvqneyh [ 1
] ; tmp_m [ 6U ] = rtB . apvpvqneyh [ 2 ] ; tmp_m [ 7U ] = rtB . apvpvqneyh [
3 ] ; tmp_g [ 2U ] = 8 ; simulationData_p -> mData -> mInputValues . mN = 8 ;
simulationData_p -> mData -> mInputValues . mX = & tmp_m [ 0U ] ;
simulationData_p -> mData -> mInputOffsets . mN = 3 ; simulationData_p ->
mData -> mInputOffsets . mX = & tmp_g [ 0U ] ; simulationData_p -> mData ->
mDx . mN = 1 ; simulationData_p -> mData -> mDx . mX = & _rtXdot ->
axhrigh31z ; simulator_p = ( NeslSimulator * ) rtDW . lwg50jsxft ;
diagnosticManager_p = ( NeuDiagnosticManager * ) rtDW . lidhiurvks ;
diagnosticTree_p = neu_diagnostic_manager_get_initial_tree (
diagnosticManager_p ) ; tmp_i = ne_simulator_method ( simulator_p ,
NESL_SIM_DERIVATIVES , simulationData_p , diagnosticManager_p ) ; if ( tmp_i
!= 0 ) { tmp_i = rtw_diagnostics_message_count ( ) ; if ( tmp_i == 0 ) {
msg_p = rtw_diagnostics_msg ( diagnosticTree_p ) ; ssSetErrorStatus ( rtS ,
msg_p ) ; } } } void MdlProjection ( void ) { NeslSimulationData *
simulationData ; real_T time ; boolean_T tmp ; real_T tmp_p [ 4 ] ; int_T
tmp_e [ 2 ] ; NeslSimulator * simulator ; NeuDiagnosticManager *
diagnosticManager ; NeuDiagnosticTree * diagnosticTree ; int32_T tmp_i ; char
* msg ; simulationData = ( NeslSimulationData * ) rtDW . is0xydhs4l ; time =
ssGetT ( rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData
-> mData -> mTime . mX = & time ; simulationData -> mData -> mContStates . mN
= 2 ; simulationData -> mData -> mContStates . mX = ( real_T * ) & rtX .
hdzhv0kuvm ; simulationData -> mData -> mDiscStates . mN = 0 ; simulationData
-> mData -> mDiscStates . mX = NULL ; simulationData -> mData -> mModeVector
. mN = 0 ; simulationData -> mData -> mModeVector . mX = NULL ; tmp = (
ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents
) ; simulationData -> mData -> mFoundZcEvents = tmp ; simulationData -> mData
-> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ; tmp = ( ssGetMdlInfoPtr (
rtS ) -> mdlFlags . solverAssertCheck == 1U ) ; simulationData -> mData ->
mIsSolverAssertCheck = tmp ; tmp = ssIsSolverCheckingCIC ( rtS ) ;
simulationData -> mData -> mIsSolverCheckingCIC = tmp ; tmp =
ssIsSolverComputingJacobian ( rtS ) ; simulationData -> mData ->
mIsComputingJacobian = tmp ; tmp = ssIsSolverRequestingReset ( rtS ) ;
simulationData -> mData -> mIsSolverRequestingReset = tmp ; tmp_e [ 0U ] = 0
; tmp_p [ 0U ] = rtB . ptrzoxc51k [ 0 ] ; tmp_p [ 1U ] = rtB . ptrzoxc51k [ 1
] ; tmp_p [ 2U ] = rtB . ptrzoxc51k [ 2 ] ; tmp_p [ 3U ] = rtB . ptrzoxc51k [
3 ] ; tmp_e [ 1U ] = 4 ; simulationData -> mData -> mInputValues . mN = 4 ;
simulationData -> mData -> mInputValues . mX = & tmp_p [ 0U ] ;
simulationData -> mData -> mInputOffsets . mN = 2 ; simulationData -> mData
-> mInputOffsets . mX = & tmp_e [ 0U ] ; simulator = ( NeslSimulator * ) rtDW
. gk0htlbrma ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW .
ka0rn1jqlo ; diagnosticTree = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp_i = ne_simulator_method ( simulator ,
NESL_SIM_PROJECTION , simulationData , diagnosticManager ) ; if ( tmp_i != 0
) { tmp_i = rtw_diagnostics_message_count ( ) ; if ( tmp_i == 0 ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
} void MdlForcingFunction ( void ) { NeslSimulationData * simulationData ;
real_T time ; boolean_T tmp ; real_T tmp_p [ 4 ] ; int_T tmp_e [ 2 ] ;
NeslSimulator * simulator ; NeuDiagnosticManager * diagnosticManager ;
NeuDiagnosticTree * diagnosticTree ; int32_T tmp_i ; char * msg ;
NeslSimulationData * simulationData_p ; real_T time_p ; real_T tmp_m [ 8 ] ;
int_T tmp_g [ 3 ] ; NeslSimulator * simulator_p ; NeuDiagnosticManager *
diagnosticManager_p ; NeuDiagnosticTree * diagnosticTree_p ; char * msg_p ;
XDot * _rtXdot ; _rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; simulationData =
( NeslSimulationData * ) rtDW . is0xydhs4l ; time = ssGetT ( rtS ) ;
simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData -> mTime
. mX = & time ; simulationData -> mData -> mContStates . mN = 2 ;
simulationData -> mData -> mContStates . mX = ( real_T * ) & rtX . hdzhv0kuvm
; simulationData -> mData -> mDiscStates . mN = 0 ; simulationData -> mData
-> mDiscStates . mX = NULL ; simulationData -> mData -> mModeVector . mN = 0
; simulationData -> mData -> mModeVector . mX = NULL ; tmp = (
ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents
) ; simulationData -> mData -> mFoundZcEvents = tmp ; simulationData -> mData
-> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ; tmp = ( ssGetMdlInfoPtr (
rtS ) -> mdlFlags . solverAssertCheck == 1U ) ; simulationData -> mData ->
mIsSolverAssertCheck = tmp ; tmp = ssIsSolverCheckingCIC ( rtS ) ;
simulationData -> mData -> mIsSolverCheckingCIC = tmp ; tmp =
ssIsSolverComputingJacobian ( rtS ) ; simulationData -> mData ->
mIsComputingJacobian = tmp ; tmp = ssIsSolverRequestingReset ( rtS ) ;
simulationData -> mData -> mIsSolverRequestingReset = tmp ; tmp_e [ 0U ] = 0
; tmp_p [ 0U ] = rtB . ptrzoxc51k [ 0 ] ; tmp_p [ 1U ] = rtB . ptrzoxc51k [ 1
] ; tmp_p [ 2U ] = rtB . ptrzoxc51k [ 2 ] ; tmp_p [ 3U ] = rtB . ptrzoxc51k [
3 ] ; tmp_e [ 1U ] = 4 ; simulationData -> mData -> mInputValues . mN = 4 ;
simulationData -> mData -> mInputValues . mX = & tmp_p [ 0U ] ;
simulationData -> mData -> mInputOffsets . mN = 2 ; simulationData -> mData
-> mInputOffsets . mX = & tmp_e [ 0U ] ; simulationData -> mData -> mDx . mN
= 2 ; simulationData -> mData -> mDx . mX = ( real_T * ) & _rtXdot ->
hdzhv0kuvm ; simulator = ( NeslSimulator * ) rtDW . gk0htlbrma ;
diagnosticManager = ( NeuDiagnosticManager * ) rtDW . ka0rn1jqlo ;
diagnosticTree = neu_diagnostic_manager_get_initial_tree ( diagnosticManager
) ; tmp_i = ne_simulator_method ( simulator , NESL_SIM_DERIVATIVES ,
simulationData , diagnosticManager ) ; if ( tmp_i != 0 ) { tmp_i =
rtw_diagnostics_message_count ( ) ; if ( tmp_i == 0 ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
simulationData_p = ( NeslSimulationData * ) rtDW . j1rpvtehmk ; time_p =
ssGetT ( rtS ) ; simulationData_p -> mData -> mTime . mN = 1 ;
simulationData_p -> mData -> mTime . mX = & time_p ; simulationData_p ->
mData -> mContStates . mN = 1 ; simulationData_p -> mData -> mContStates . mX
= & rtX . axhrigh31z ; simulationData_p -> mData -> mDiscStates . mN = 0 ;
simulationData_p -> mData -> mDiscStates . mX = NULL ; simulationData_p ->
mData -> mModeVector . mN = 0 ; simulationData_p -> mData -> mModeVector . mX
= NULL ; tmp = ( ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo ( rtS ) ->
foundContZcEvents ) ; simulationData_p -> mData -> mFoundZcEvents = tmp ;
simulationData_p -> mData -> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ;
tmp = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData_p -> mData -> mIsSolverAssertCheck = tmp ; tmp =
ssIsSolverCheckingCIC ( rtS ) ; simulationData_p -> mData ->
mIsSolverCheckingCIC = tmp ; tmp = ssIsSolverComputingJacobian ( rtS ) ;
simulationData_p -> mData -> mIsComputingJacobian = tmp ; tmp =
ssIsSolverRequestingReset ( rtS ) ; simulationData_p -> mData ->
mIsSolverRequestingReset = tmp ; tmp_g [ 0U ] = 0 ; tmp_m [ 0U ] = rtB .
ijqtrjxdsh [ 0 ] ; tmp_m [ 1U ] = rtB . ijqtrjxdsh [ 1 ] ; tmp_m [ 2U ] = rtB
. ijqtrjxdsh [ 2 ] ; tmp_m [ 3U ] = rtB . ijqtrjxdsh [ 3 ] ; tmp_g [ 1U ] = 4
; tmp_m [ 4U ] = rtB . apvpvqneyh [ 0 ] ; tmp_m [ 5U ] = rtB . apvpvqneyh [ 1
] ; tmp_m [ 6U ] = rtB . apvpvqneyh [ 2 ] ; tmp_m [ 7U ] = rtB . apvpvqneyh [
3 ] ; tmp_g [ 2U ] = 8 ; simulationData_p -> mData -> mInputValues . mN = 8 ;
simulationData_p -> mData -> mInputValues . mX = & tmp_m [ 0U ] ;
simulationData_p -> mData -> mInputOffsets . mN = 3 ; simulationData_p ->
mData -> mInputOffsets . mX = & tmp_g [ 0U ] ; simulationData_p -> mData ->
mDx . mN = 1 ; simulationData_p -> mData -> mDx . mX = & _rtXdot ->
axhrigh31z ; simulator_p = ( NeslSimulator * ) rtDW . lwg50jsxft ;
diagnosticManager_p = ( NeuDiagnosticManager * ) rtDW . lidhiurvks ;
diagnosticTree_p = neu_diagnostic_manager_get_initial_tree (
diagnosticManager_p ) ; tmp_i = ne_simulator_method ( simulator_p ,
NESL_SIM_FORCINGFUNCTION , simulationData_p , diagnosticManager_p ) ; if (
tmp_i != 0 ) { tmp_i = rtw_diagnostics_message_count ( ) ; if ( tmp_i == 0 )
{ msg_p = rtw_diagnostics_msg ( diagnosticTree_p ) ; ssSetErrorStatus ( rtS ,
msg_p ) ; } } } void MdlMassMatrix ( void ) { NeslSimulationData *
simulationData ; real_T time ; boolean_T tmp ; real_T tmp_p [ 8 ] ; int_T
tmp_e [ 3 ] ; real_T * tmp_i ; real_T * tmp_m ; NeslSimulator * simulator ;
NeuDiagnosticManager * diagnosticManager ; NeuDiagnosticTree * diagnosticTree
; int32_T tmp_g ; char * msg ; simulationData = ( NeslSimulationData * ) rtDW
. j1rpvtehmk ; time = ssGetT ( rtS ) ; simulationData -> mData -> mTime . mN
= 1 ; simulationData -> mData -> mTime . mX = & time ; simulationData ->
mData -> mContStates . mN = 1 ; simulationData -> mData -> mContStates . mX =
& rtX . axhrigh31z ; simulationData -> mData -> mDiscStates . mN = 0 ;
simulationData -> mData -> mDiscStates . mX = NULL ; simulationData -> mData
-> mModeVector . mN = 0 ; simulationData -> mData -> mModeVector . mX = NULL
; tmp = ( ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo ( rtS ) ->
foundContZcEvents ) ; simulationData -> mData -> mFoundZcEvents = tmp ;
simulationData -> mData -> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ; tmp
= ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = tmp ; tmp =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = tmp ; tmp = ssIsSolverComputingJacobian ( rtS ) ;
simulationData -> mData -> mIsComputingJacobian = tmp ; tmp =
ssIsSolverRequestingReset ( rtS ) ; simulationData -> mData ->
mIsSolverRequestingReset = tmp ; tmp_e [ 0U ] = 0 ; tmp_p [ 0U ] = rtB .
ijqtrjxdsh [ 0 ] ; tmp_p [ 1U ] = rtB . ijqtrjxdsh [ 1 ] ; tmp_p [ 2U ] = rtB
. ijqtrjxdsh [ 2 ] ; tmp_p [ 3U ] = rtB . ijqtrjxdsh [ 3 ] ; tmp_e [ 1U ] = 4
; tmp_p [ 4U ] = rtB . apvpvqneyh [ 0 ] ; tmp_p [ 5U ] = rtB . apvpvqneyh [ 1
] ; tmp_p [ 6U ] = rtB . apvpvqneyh [ 2 ] ; tmp_p [ 7U ] = rtB . apvpvqneyh [
3 ] ; tmp_e [ 2U ] = 8 ; simulationData -> mData -> mInputValues . mN = 8 ;
simulationData -> mData -> mInputValues . mX = & tmp_p [ 0U ] ;
simulationData -> mData -> mInputOffsets . mN = 3 ; simulationData -> mData
-> mInputOffsets . mX = & tmp_e [ 0U ] ; tmp_i = rtMassMatrix . pr ; tmp_m =
double_pointer_shift ( tmp_i , rtDW . bcjys3m3es ) ; simulationData -> mData
-> mMassMatrixPr . mN = 1 ; simulationData -> mData -> mMassMatrixPr . mX =
tmp_m ; simulator = ( NeslSimulator * ) rtDW . lwg50jsxft ; diagnosticManager
= ( NeuDiagnosticManager * ) rtDW . lidhiurvks ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; tmp_g =
ne_simulator_method ( simulator , NESL_SIM_MASSMATRIX , simulationData ,
diagnosticManager ) ; if ( tmp_g != 0 ) { tmp_g =
rtw_diagnostics_message_count ( ) ; if ( tmp_g == 0 ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
} void MdlZeroCrossings ( void ) { ZCV * _rtZCSV ; _rtZCSV = ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) ; _rtZCSV -> hhdi32quq3 = rtB .
jygob3b3q4 [ 1 ] ; _rtZCSV -> ke0y3dgz5x = rtB . jygob3b3q4 [ 1 ] ; } void
MdlTerminate ( void ) { neu_destroy_diagnostic_manager ( (
NeuDiagnosticManager * ) rtDW . ka0rn1jqlo ) ; nesl_destroy_simulation_data (
( NeslSimulationData * ) rtDW . is0xydhs4l ) ; nesl_erase_simulator (
"Ensayos_Friccion/DeltaSM/Solver Configuration1" ) ;
neu_destroy_diagnostic_manager ( ( NeuDiagnosticManager * ) rtDW . mxmjsp3mlq
) ; nesl_destroy_simulation_data ( ( NeslSimulationData * ) rtDW . b2mtd04ww2
) ; nesl_erase_simulator ( "Ensayos_Friccion/DeltaSM/Solver Configuration1" )
; neu_destroy_diagnostic_manager ( ( NeuDiagnosticManager * ) rtDW .
g5mb0p1qhu ) ; nesl_destroy_simulation_data ( ( NeslSimulationData * ) rtDW .
bjxpzefqp3 ) ; nesl_erase_simulator (
"Ensayos_Friccion/DeltaSM/Solver Configuration1" ) ;
neu_destroy_diagnostic_manager ( ( NeuDiagnosticManager * ) rtDW . gr25vq2fuc
) ; nesl_destroy_simulation_data ( ( NeslSimulationData * ) rtDW . khywewrhhg
) ; nesl_erase_simulator ( "Ensayos_Friccion/DeltaSM/Solver Configuration1" )
; neu_destroy_diagnostic_manager ( ( NeuDiagnosticManager * ) rtDW .
lidhiurvks ) ; nesl_destroy_simulation_data ( ( NeslSimulationData * ) rtDW .
j1rpvtehmk ) ; nesl_erase_simulator (
"Ensayos_Friccion/DeltaSM/Solver Configuration1" ) ;
neu_destroy_diagnostic_manager ( ( NeuDiagnosticManager * ) rtDW . amndknbiec
) ; nesl_destroy_simulation_data ( ( NeslSimulationData * ) rtDW . hlaipun4ez
) ; nesl_erase_simulator ( "Ensayos_Friccion/DeltaSM/Solver Configuration1" )
; neu_destroy_diagnostic_manager ( ( NeuDiagnosticManager * ) rtDW .
ioyxzcapgj ) ; nesl_destroy_simulation_data ( ( NeslSimulationData * ) rtDW .
op23awaojj ) ; nesl_erase_simulator (
"Ensayos_Friccion/DeltaSM/Solver Configuration1" ) ;
neu_destroy_diagnostic_manager ( ( NeuDiagnosticManager * ) rtDW . ewleodkp1x
) ; nesl_destroy_simulation_data ( ( NeslSimulationData * ) rtDW . eufaiemnot
) ; nesl_erase_simulator ( "Ensayos_Friccion/DeltaSM/Solver Configuration1" )
; neu_destroy_diagnostic_manager ( ( NeuDiagnosticManager * ) rtDW .
alt2ulitdc ) ; nesl_destroy_simulation_data ( ( NeslSimulationData * ) rtDW .
osydjefyeb ) ; nesl_erase_simulator (
"Ensayos_Friccion/DeltaSM/Solver Configuration1" ) ; } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 3 ) ; ssSetNumY (
rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ;
ssSetNumSampleTimes ( rtS , 2 ) ; ssSetNumBlocks ( rtS , 102 ) ;
ssSetNumBlockIO ( rtS , 27 ) ; ssSetNumBlockParams ( rtS , 12 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 0.0 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 1.0 ) ; } void raccel_set_checksum ( SimStruct *
rtS ) { ssSetChecksumVal ( rtS , 0 , 1897557679U ) ; ssSetChecksumVal ( rtS ,
1 , 4222067273U ) ; ssSetChecksumVal ( rtS , 2 , 380769674U ) ;
ssSetChecksumVal ( rtS , 3 , 563028228U ) ; } SimStruct *
raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo ; ( void )
memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void ) memset ( (
char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ; ssSetMdlInfoPtr (
rtS , & mdlInfo ) ; { static time_T mdlPeriod [ NSAMPLE_TIMES ] ; static
time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T mdlTaskTimes [
NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ; static int_T
mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T mdlTNextWasAdjustedPtr [
NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits [ NSAMPLE_TIMES *
NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [ NSAMPLE_TIMES ] ; {
int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) { mdlPeriod [ i ] = 0.0 ;
mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ; mdlTsMap [ i ] = i ;
mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS , & mdlPeriod [ 0 ] )
; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr (
rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , & mdlTaskTimes [ 0 ] ) ;
ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ; ssSetTNextWasAdjustedPtr
( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ; ssSetPerTaskSampleHitsPtr ( rtS ,
& mdlPerTaskSampleHits [ 0 ] ) ; ssSetTimeOfNextSampleHitPtr ( rtS , &
mdlTimeOfNextSampleHit [ 0 ] ) ; } ssSetSolverMode ( rtS ,
SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS , ( ( void * ) & rtB ) ) ;
( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof ( B ) ) ; }
ssSetDefaultParam ( rtS , ( real_T * ) & rtP ) ; { real_T * x = ( real_T * )
& rtX ; ssSetContStates ( rtS , x ) ; ( void ) memset ( ( void * ) x , 0 ,
sizeof ( X ) ) ; } { void * dwork = ( void * ) & rtDW ; ssSetRootDWork ( rtS
, dwork ) ; ( void ) memset ( dwork , 0 , sizeof ( DW ) ) ; } { rtDW .
bcjys3m3es = 2 ; } { static DataTypeTransInfo dtInfo ; ( void ) memset ( (
char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS ,
& dtInfo ) ; dtInfo . numDataTypes = 14 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . B = & rtBTransTable ; dtInfo . P = & rtPTransTable ; }
Ensayos_Friccion_InitializeDataMapInfo ( rtS ) ;
ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"Ensayos_Friccion" ) ; ssSetPath ( rtS , "Ensayos_Friccion" ) ; ssSetTStart (
rtS , 0.0 ) ; ssSetTFinal ( rtS , 10.0 ) ; { static RTWLogInfo
rt_DataLoggingInfo ; ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } { {
static int_T rt_LoggedStateWidths [ ] = { 1 , 1 , 1 , 1 , 1 , 1 } ; static
int_T rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 , 1 , 1 , 1 } ; static
int_T rt_LoggedStateDimensions [ ] = { 1 , 1 , 1 , 1 , 1 , 1 } ; static
boolean_T rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 , 0 , 0 } ; static
BuiltInDTypeId rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0 , 0 , 0 } ; static const
char_T * rt_LoggedStateLabels [ ] = { "CSTATE" , "CSTATE" , "CSTATE" ,
"DiscStates" , "DiscStates" , "DiscStates" } ; static const char_T *
rt_LoggedStateBlockNames [ ] = { "Ensayos_Friccion/DeltaSM/Revolute1" ,
"Ensayos_Friccion/DeltaSM/Revolute1" , "Ensayos_Friccion/DeltaSM/PS Constant"
,
 "Ensayos_Friccion/DeltaSM/Friccion \nCoulomb\nR/Expandido/Simulink-PS\nConverter/EVAL_KEY/EXEC_INPUT_1"
,
 "Ensayos_Friccion/DeltaSM/Friccion \nCoulomb\nR2/Expandido/Simulink-PS\nConverter/EVAL_KEY/EXEC_INPUT_1"
, "Ensayos_Friccion/DeltaSM/Solver\nConfiguration1/EVAL_KEY/EXEC_INPUT_9" } ;
static const char_T * rt_LoggedStateNames [ ] = { "DeltaSM.Revolute1.Rz.q" ,
"DeltaSM.Revolute1.Rz.w" , "Ensayos_Friccion.DeltaSM.PS_Constant.O" , "" , ""
, "" } ; static boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 , 0
, 0 } ; static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static
RTWLogSignalInfo rt_LoggedStateSignalInfo = { 6 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , { rt_LoggedStateLabels } , ( NULL )
, ( NULL ) , ( NULL ) , { rt_LoggedStateBlockNames } , { rt_LoggedStateNames
} , rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert } ; static void *
rt_LoggedStateSignalPtrs [ 6 ] ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo (
rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . hdzhv0kuvm [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . hdzhv0kuvm [ 1 ] ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . axhrigh31z ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtDW . px2h4fxqvc ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtDW . gt0elxwjeb ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtDW . j0qqzzt21t ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "tmp_raccel_xout" ) ; rtliSetLogXFinal (
ssGetRTWLogInfo ( rtS ) , "xFinal" ) ; rtliSetLogVarNameModifier (
ssGetRTWLogInfo ( rtS ) , "none" ) ; rtliSetLogFormat ( ssGetRTWLogInfo ( rtS
) , 2 ) ; rtliSetLogMaxRows ( ssGetRTWLogInfo ( rtS ) , 1000 ) ;
rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS ) , 1 ) ; rtliSetLogY (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogYSignalInfo ( ssGetRTWLogInfo (
rtS ) , ( NULL ) ) ; rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL
) ) ; } { static struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS ,
& statesInfo2 ) ; } { static ssSolverInfo slvrInfo ; static struct
_ssSFcnModelMethods3 mdlMethods3 ; static struct _ssSFcnModelMethods2
mdlMethods2 ; static boolean_T contStatesDisabled [ 3 ] ; static real_T
absTol [ 3 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 } ; static uint8_T absTolControl [
3 ] = { 0U , 0U , 0U } ; static uint8_T zcAttributes [ 2 ] = { ( ZC_EVENT_ALL
) , ( ZC_EVENT_ALL ) } ; ssSetSolverRelTol ( rtS , 0.001 ) ; ssSetStepSize (
rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , -
1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS , 0.001
) ; ssSetSolverMaxOrder ( rtS , - 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ;
ssSetOutputTimes ( rtS , ( NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ;
ssSetOutputTimesOnly ( rtS , 0 ) ; ssSetOutputTimesIndex ( rtS , 0 ) ;
ssSetZCCacheNeedsReset ( rtS , 0 ) ; ssSetDerivCacheNeedsReset ( rtS , 0 ) ;
ssSetNumNonContDerivSigInfos ( rtS , 0 ) ; ssSetNonContDerivSigInfos ( rtS ,
( NULL ) ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS ,
"ode23t" ) ; ssSetVariableStepSolver ( rtS , 1 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 0 ) ; ssSetSolverRobustResetMethod ( rtS , 0 ) ;
_ssSetSolverUpdateJacobianAtReset ( rtS , true ) ; ssSetAbsTolVector ( rtS ,
absTol ) ; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetSolverStateProjection ( rtS , 1 ) ; ( void ) memset ( ( void * ) &
mdlMethods2 , 0 , sizeof ( mdlMethods2 ) ) ; ssSetModelMethods2 ( rtS , &
mdlMethods2 ) ; ( void ) memset ( ( void * ) & mdlMethods3 , 0 , sizeof (
mdlMethods3 ) ) ; ssSetModelMethods3 ( rtS , & mdlMethods3 ) ;
ssSetModelProjection ( rtS , MdlProjection ) ; ssSetMassMatrixType ( rtS , (
ssMatrixType ) 1 ) ; ssSetMassMatrixNzMax ( rtS , 3 ) ; ssSetModelMassMatrix
( rtS , MdlMassMatrix ) ; ssSetModelForcingFunction ( rtS ,
MdlForcingFunction ) ; ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 1 )
; ssSetSolverMassMatrixNzMax ( rtS , 3 ) ; ssSetModelOutputs ( rtS ,
MdlOutputs ) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetSolverZcSignalAttrib ( rtS , zcAttributes ) ;
ssSetSolverNumZcSignals ( rtS , 2 ) ; ssSetModelZeroCrossings ( rtS ,
MdlZeroCrossings ) ; ssSetSolverConsecutiveZCsStepRelTol ( rtS ,
2.8421709430404007E-13 ) ; ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ;
ssSetSolverConsecutiveZCsError ( rtS , 0 ) ; ssSetSolverMaskedZcDiagnostic (
rtS , 1 ) ; ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ;
ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 2 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; { int_T
* ir = rtMassMatrix . ir ; int_T * jc = rtMassMatrix . jc ; real_T * pr =
rtMassMatrix . pr ; ssSetMassMatrixIr ( rtS , ir ) ; ssSetMassMatrixJc ( rtS
, jc ) ; ssSetMassMatrixPr ( rtS , pr ) ; ( void ) memset ( ( void * ) ir , 0
, 3 * sizeof ( int_T ) ) ; ( void ) memset ( ( void * ) jc , 0 , ( 3 + 1 ) *
sizeof ( int_T ) ) ; ( void ) memset ( ( void * ) pr , 0 , 3 * sizeof (
real_T ) ) ; } } ssSetChecksumVal ( rtS , 0 , 1897557679U ) ;
ssSetChecksumVal ( rtS , 1 , 4222067273U ) ; ssSetChecksumVal ( rtS , 2 ,
380769674U ) ; ssSetChecksumVal ( rtS , 3 , 563028228U ) ; { static const
sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo
rt_ExtModeInfo ; static const sysRanDType * systemRan [ 1 ] ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; } return
rtS ; }
