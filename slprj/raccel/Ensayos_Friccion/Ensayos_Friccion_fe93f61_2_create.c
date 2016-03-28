#include "__cf_Ensayos_Friccion.h"
#include "pm_std.h"
#include "ne_std.h"
#include "ne_dae.h"
#include "ne_default_allocator.h"
#include "sm_ssci_NeDaePrivateData.h"
#include "sm_CTarget.h"
PmfMessageId sm_ssci_recordRunTimeError ( const char * errorId , const char *
errorMsg , NeuDiagnosticManager * mgr ) ;
#define ne_allocator_alloc(_allocator, _m, _n) ((_allocator)->mCallocFcn((_allocator), (_m), (_n)))
#define NE_ALLOCATE_ARRAY(_name, _type, _size, _allocator)\
 _name = (_type *) ne_allocator_alloc(_allocator, sizeof(_type), _size)
#define ne_size_to_int(_size)          ((int32_T) (_size))
NeIntVector * neu_create_int_vector ( size_t , NeAllocator * ) ; int_T
neu_create_int_vector_fields ( NeIntVector * , size_t , NeAllocator * ) ;
int_T neu_create_real_vector_fields ( NeRealVector * , size_t , NeAllocator *
) ; int_T neu_create_char_vector_fields ( NeCharVector * , size_t ,
NeAllocator * ) ; int_T neu_create_bool_vector_fields ( NeBoolVector * ,
size_t , NeAllocator * ) ; void neu_rv_equals_rv ( const NeRealVector * ,
const NeRealVector * ) ; void sm_ssci_setupLoggerFcn_codeGen ( const NeDae *
dae , NeLoggerBuilder * neLoggerBuilder ) ; int32_T sm_ssci_logFcn_codeGen (
const NeDae * dae , const NeSystemInput * systemInput , NeRealVector * output
) ; PmfMessageId Ensayos_Friccion_fe93f61_2_deriv ( const double * , const
double * , const double * , const double * , const double * , double * ,
NeuDiagnosticManager * neDiagMgr ) ; PmfMessageId
Ensayos_Friccion_fe93f61_2_outputDyn ( const double * , const double * ,
const double * , const double * , const double * , double * , double * , int
* , NeuDiagnosticManager * neDiagMgr ) ; PmfMessageId
Ensayos_Friccion_fe93f61_2_outputKin ( const double * , const double * ,
const double * , const double * , const double * , double * ,
NeuDiagnosticManager * neDiagMgr ) ; PmfMessageId
Ensayos_Friccion_fe93f61_2_output ( const double * , const double * , const
double * , const double * , const double * , double * , NeuDiagnosticManager
* neDiagMgr ) ; PmfMessageId Ensayos_Friccion_fe93f61_2_project ( const
double * , const double * , const double * , double * , double * ,
NeuDiagnosticManager * neDiagMgr ) ; void
Ensayos_Friccion_fe93f61_2_resetStateVector ( const void * mech , double *
stateVector ) ; PmfMessageId
Ensayos_Friccion_fe93f61_2_initializeTrackedAngleState ( const void * mech ,
double * stateVector , void * neDiagMgr ) ; void
Ensayos_Friccion_fe93f61_2_computeDiscreteState ( const void * mech , double
* stateVector ) ; void Ensayos_Friccion_fe93f61_2_adjustPosition ( const void
* mech , const double * dofDeltas , double * stateVector ) ; void
Ensayos_Friccion_fe93f61_2_perturbState ( const void * mech , size_t stageIdx
, size_t primitiveIdx , double magnitude , boolean_T doPerturbVelocity ,
double * stateVector ) ; void Ensayos_Friccion_fe93f61_2_propagateMotion (
const void * mech , const double * stateVector , double * motionData ) ;
size_t Ensayos_Friccion_fe93f61_2_computeAssemblyError ( const void * mech ,
size_t constraintIdx , const double * stateVector , const double * motionData
, double * error ) ; size_t
Ensayos_Friccion_fe93f61_2_computeAssemblyJacobian ( const void * mech ,
size_t constraintIdx , boolean_T forVelocitySatisfaction , const double *
stateVector , const double * motionData , double * J ) ; size_t
Ensayos_Friccion_fe93f61_2_computeFullAssemblyJacobian ( const void * mech ,
const double * stateVector , const double * motionData , double * J ) ;
PmfMessageId Ensayos_Friccion_fe93f61_2_convertStateVector ( const void *
asmMech , const void * simMech , const double * asmStateVector , double *
simStateVector , void * neDiagMgr ) ; PmfMessageId
Ensayos_Friccion_fe93f61_2_assemble ( const double * u , double * udot ,
double * x , NeuDiagnosticManager * neDiagMgr ) { ( void ) x ; ( void ) u ; (
void ) udot ; return NULL ; } static PmfMessageId dae_deriv_method ( const
NeDae * dae , const NeSystemInput * systemInput , NeDaeMethodOutput *
daeMethodOutput , NeuDiagnosticManager * neDiagMgr ) { const NeDaePrivateData
* smData = dae -> mPrivateData ; PmfMessageId errorId = NULL ; if ( smData ->
mCachedDerivativesAvailable ) memcpy ( daeMethodOutput -> mXP0 . mX , smData
-> mCachedDerivatives . mX , 2 * sizeof ( real_T ) ) ; else errorId =
Ensayos_Friccion_fe93f61_2_deriv ( systemInput -> mX . mX , systemInput -> mU
. mX , systemInput -> mU . mX + 1 , systemInput -> mV . mX + 1 , systemInput
-> mD . mX , daeMethodOutput -> mXP0 . mX , neDiagMgr ) ; return errorId ; }
static PmfMessageId dae_output_method ( const NeDae * dae , const
NeSystemInput * systemInput , NeDaeMethodOutput * daeMethodOutput ,
NeuDiagnosticManager * neDiagMgr ) { PmfMessageId errorId = NULL ; ( void )
dae ; errorId = Ensayos_Friccion_fe93f61_2_output ( systemInput -> mX . mX ,
systemInput -> mU . mX , systemInput -> mU . mX + 1 , systemInput -> mV . mX
+ 1 , systemInput -> mD . mX , daeMethodOutput -> mY . mX , neDiagMgr ) ;
return errorId ; } static PmfMessageId dae_project_solve ( const NeDae * dae
, const NeSystemInput * systemInput , NeuDiagnosticManager * neDiagMgr ) {
double fullStateVal = 0.0 ; ( void ) dae ; return
Ensayos_Friccion_fe93f61_2_project ( systemInput -> mU . mX , systemInput ->
mU . mX + 1 , systemInput -> mD . mX , systemInput -> mX . mX , &
fullStateVal , neDiagMgr ) ; } static PmfMessageId dae_assemble_solve ( const
NeDae * dae , const NeSystemInput * systemInput , NeuDiagnosticManager *
neDiagMgr ) { NeDaePrivateData * smData = dae -> mPrivateData ; PmfMessageId
errorId = NULL ; if ( smData -> mNumInputMotionPrimitives == 0 ) {
neu_rv_equals_rv ( & systemInput -> mX , & dae -> mPrivateData ->
mInitialStateVector ) ; neu_rv_equals_rv ( & systemInput -> mD , & dae ->
mPrivateData -> mDiscreteStateVector ) ; } else { size_t i ; const size_t
numTargets = 2 ; unsigned int asmStatus = 0 ; double *
assemblyFullStateVector = smData -> mAssemblyFullStateVector . mX ; double *
simulationFullStateVector = smData -> mSimulationFullStateVector . mX ; const
double * u = systemInput -> mU . mX ; const double * uDot = u + smData ->
mInputVectorSize ; CTarget * target = smData -> mTargets + smData ->
mNumInternalTargets ; for ( i = 0 ; i < smData -> mNumInputMotionPrimitives ;
++ i ) { const size_t inputOffset = smData -> mMotionInputOffsets . mX [ i ]
; ( target ++ ) -> mValue [ 0 ] = u [ inputOffset ] ; ( target ++ ) -> mValue
[ 0 ] = uDot [ inputOffset ] ; } errorId = sm_core_computeStateVector ( &
smData -> mAssemblyDelegate , numTargets , smData -> mTargets ,
assemblyFullStateVector , neDiagMgr ) ; if ( errorId != NULL ) return errorId
; asmStatus = sm_core_checkAssembly ( & smData -> mAssemblyDelegate ,
numTargets , smData -> mTargets , assemblyFullStateVector , NULL , NULL ) ;
if ( asmStatus != 1 ) { return sm_ssci_recordRunTimeError (
"sm:compiler:messages:simulationErrors:AssemblyFailure" , asmStatus == 2 ?
 "Model not assembled due to a position violation. The failure occurred during the attempt to assemble all joints in the system and satisfy any motion inputs. If an Update Diagram operation completes successfully, the failure is likely caused by motion inputs. Consider adjusting the motion inputs to specify a different starting configuration. Also consider adjusting or adding joint targets to better guide the assembly."
:
 "Model not assembled due to a velocity violation. The failure occurred during the attempt to assemble all joints in the system and satisfy any motion inputs. If an Update Diagram operation completes successfully, the failure is likely caused by motion inputs. Consider adjusting the motion inputs to specify a different starting configuration. Also consider adjusting or adding joint targets to better guide the assembly."
, neDiagMgr ) ; } errorId = ( * smData -> mAssemblyDelegate .
mConvertStateVector ) ( NULL , NULL , assemblyFullStateVector ,
simulationFullStateVector , neDiagMgr ) ; for ( i = 0 ; i < smData ->
mStateVectorSize ; ++ i ) systemInput -> mX . mX [ i ] =
simulationFullStateVector [ smData -> mStateVectorMap . mX [ i ] ] ; memcpy (
systemInput -> mD . mX , simulationFullStateVector + smData ->
mFullStateVectorSize - smData -> mDiscreteStateSize , smData ->
mDiscreteStateSize * sizeof ( double ) ) ; } return errorId ; } typedef
struct { size_t first ; size_t second ; } SizePair ; static void
checkMemAllocStatus ( int_T status ) { ( void ) status ; } static
NeCharVector cStringToCharVector ( const char * src ) { const size_t n =
strlen ( src ) ; NeCharVector charVect ; const int_T status =
neu_create_char_vector_fields ( & charVect , n + 1 , ne_default_allocator ( )
) ; checkMemAllocStatus ( status ) ; strcpy ( charVect . mX , src ) ; return
charVect ; } static void initBasicAttributes ( NeDaePrivateData * smData ) {
size_t i ; smData -> mStateVectorSize = 2 ; smData -> mFullStateVectorSize =
2 ; smData -> mDiscreteStateSize = 0 ; smData -> mInputVectorSize = 1 ;
smData -> mOutputVectorSize = 2 ; smData -> mNumConstraintEqns = 0 ; for ( i
= 0 ; i < 4 ; ++ i ) smData -> mChecksum [ i ] = 0 ; } static void
initStateVector ( NeDaePrivateData * smData ) { NeAllocator * alloc =
ne_default_allocator ( ) ; const double initialStateVector [ 2 ] = { +
1.570796326794896600e+00 , + 0.000000000000000000e+00 } ; const double *
discreteStateVector = NULL ; const int32_T stateVectorMap [ 2 ] = { 0 , 1 } ;
const CTarget targets [ 2 ] = { { 0 , 69 , 0 , 2 , "deg" , false , true ,
true , 1 , { + 1.570796326794896600e+00 , + 0.000000000000000000e+00 , +
0.000000000000000000e+00 , + 0.000000000000000000e+00 } } , { 0 , 69 , 0 , 0
, "1" , true , true , true , 1 , { + 0.000000000000000000e+00 , +
0.000000000000000000e+00 , + 0.000000000000000000e+00 , +
0.000000000000000000e+00 } } } ; const size_t numTargets = 2 ; int_T status ;
size_t i ; status = neu_create_real_vector_fields ( & smData ->
mAssemblyFullStateVector , 2 , alloc ) ; checkMemAllocStatus ( status ) ;
status = neu_create_real_vector_fields ( & smData ->
mSimulationFullStateVector , 2 , alloc ) ; checkMemAllocStatus ( status ) ;
status = neu_create_real_vector_fields ( & smData -> mInitialStateVector , 2
, alloc ) ; checkMemAllocStatus ( status ) ; memcpy ( smData ->
mInitialStateVector . mX , initialStateVector , 2 * sizeof ( real_T ) ) ;
status = neu_create_real_vector_fields ( & smData -> mDiscreteStateVector , 0
, alloc ) ; checkMemAllocStatus ( status ) ; memcpy ( smData ->
mDiscreteStateVector . mX , discreteStateVector , 0 * sizeof ( real_T ) ) ;
status = neu_create_int_vector_fields ( & smData -> mStateVectorMap , smData
-> mStateVectorSize , alloc ) ; checkMemAllocStatus ( status ) ; memcpy (
smData -> mStateVectorMap . mX , stateVectorMap , smData -> mStateVectorSize
* sizeof ( int32_T ) ) ; smData -> mNumInternalTargets = 2 ; smData ->
mNumInputMotionPrimitives = 0 ; NE_ALLOCATE_ARRAY ( smData -> mTargets ,
CTarget , numTargets , alloc ) ; for ( i = 0 ; i < numTargets ; ++ i )
sm_compiler_CTarget_copy ( targets + i , smData -> mTargets + i ) ; } static
void initVariables ( NeDaePrivateData * smData ) { const char * varFullPaths
[ 2 ] = { "DeltaSM.Revolute1.Rz.q" , "DeltaSM.Revolute1.Rz.w" } ; const char
* varObjects [ 2 ] = { "Ensayos_Friccion/DeltaSM/Revolute1" ,
"Ensayos_Friccion/DeltaSM/Revolute1" } ; smData -> mNumVarScalars = 2 ;
smData -> mVarFullPaths = NULL ; smData -> mVarObjects = NULL ; if ( smData
-> mNumVarScalars > 0 ) { size_t s ; NeAllocator * alloc =
ne_default_allocator ( ) ; NE_ALLOCATE_ARRAY ( smData -> mVarFullPaths ,
NeCharVector , 2 , alloc ) ; NE_ALLOCATE_ARRAY ( smData -> mVarObjects ,
NeCharVector , 2 , alloc ) ; for ( s = 0 ; s < smData -> mNumVarScalars ; ++
s ) { smData -> mVarFullPaths [ s ] = cStringToCharVector ( varFullPaths [ s
] ) ; smData -> mVarObjects [ s ] = cStringToCharVector ( varObjects [ s ] )
; } } } static void initIoInfoHelper ( size_t n , const char *
portPathsSource [ ] , const char * unitsSource [ ] , const SizePair
dimensions [ ] , bool doInputs , NeDaePrivateData * smData ) { NeCharVector *
portPaths = NULL ; NeCharVector * units = NULL ; NeDsIoInfo * infos = NULL ;
if ( n > 0 ) { size_t s ; NeAllocator * alloc = ne_default_allocator ( ) ;
NE_ALLOCATE_ARRAY ( portPaths , NeCharVector , n , alloc ) ;
NE_ALLOCATE_ARRAY ( units , NeCharVector , n , alloc ) ; NE_ALLOCATE_ARRAY (
infos , NeDsIoInfo , n , alloc ) ; for ( s = 0 ; s < n ; ++ s ) { portPaths [
s ] = cStringToCharVector ( portPathsSource [ s ] ) ; units [ s ] =
cStringToCharVector ( unitsSource [ s ] ) ; { NeDsIoInfo * info = infos + s ;
info -> mName = info -> mIdentifier = portPaths [ s ] . mX ; info -> mM =
dimensions [ s ] . first ; info -> mN = dimensions [ s ] . second ; info ->
mUnit = units [ s ] . mX ; } } } if ( doInputs ) { smData -> mNumInputs = n ;
smData -> mInputPortPaths = portPaths ; smData -> mInputUnits = units ;
smData -> mInputInfos = infos ; } else { smData -> mNumOutputs = n ; smData
-> mOutputPortPaths = portPaths ; smData -> mOutputUnits = units ; smData ->
mOutputInfos = infos ; } } static void initIoInfo ( NeDaePrivateData * smData
) { const char * inputPortPaths [ 1 ] = { "DeltaSM.Revolute1.ti" } ; const
char * inputUnits [ 1 ] = { "m^2*kg/s^2" } ; const SizePair inputDimensions [
1 ] = { { 1 , 1 } } ; const char * outputPortPaths [ 2 ] = {
"DeltaSM.Revolute1.q" , "DeltaSM.Revolute1.w" } ; const char * outputUnits [
2 ] = { "rad" , "rad/s" } ; const SizePair outputDimensions [ 2 ] = { { 1 , 1
} , { 1 , 1 } } ; initIoInfoHelper ( 1 , inputPortPaths , inputUnits ,
inputDimensions , true , smData ) ; initIoInfoHelper ( 2 , outputPortPaths ,
outputUnits , outputDimensions , false , smData ) ; } static void
initInputDerivs ( NeDaePrivateData * smData ) { const int32_T numInputDerivs
[ 1 ] = { 0 } ; NeAllocator * alloc = ne_default_allocator ( ) ; const int_T
status = neu_create_int_vector_fields ( & smData -> mNumInputDerivs , smData
-> mInputVectorSize , alloc ) ; checkMemAllocStatus ( status ) ; memcpy (
smData -> mNumInputDerivs . mX , numInputDerivs , 1 * sizeof ( int32_T ) ) ;
smData -> mInputOrder = 1 ; } static void initDirectFeedthrough (
NeDaePrivateData * smData ) { const boolean_T directFeedthroughVector [ 1 ] =
{ false } ; const boolean_T directFeedthroughMatrix [ 2 ] = { false , false }
; NeAllocator * alloc = ne_default_allocator ( ) ; { const int_T status =
neu_create_bool_vector_fields ( & smData -> mDirectFeedthroughVector , 1 ,
alloc ) ; checkMemAllocStatus ( status ) ; memcpy ( smData ->
mDirectFeedthroughVector . mX , directFeedthroughVector , 1 * sizeof (
boolean_T ) ) ; } { const int_T status = neu_create_bool_vector_fields ( &
smData -> mDirectFeedthroughMatrix , 2 , alloc ) ; checkMemAllocStatus (
status ) ; memcpy ( smData -> mDirectFeedthroughMatrix . mX ,
directFeedthroughMatrix , 2 * sizeof ( boolean_T ) ) ; } } static void
initOutputDerivProc ( NeDaePrivateData * smData ) { NeAllocator * alloc =
ne_default_allocator ( ) ; const int32_T outputFunctionMap [ 2 ] = { 0 , 0 }
; smData -> mOutputFunctionMap = neu_create_int_vector ( 2 , alloc ) ; memcpy
( smData -> mOutputFunctionMap -> mX , outputFunctionMap , 2 * sizeof (
int32_T ) ) ; smData -> mNumOutputClasses = 1 ; smData ->
mHasKinematicOutputs = true ; smData -> mHasDynamicOutputs = false ; smData
-> mIsOutputClass0Dynamic = false ; smData -> mDoComputeDynamicOutputs =
false ; smData -> mCachedDerivativesAvailable = false ; { size_t i = 0 ;
const int_T status = neu_create_real_vector_fields ( & smData ->
mCachedDerivatives , 0 , ne_default_allocator ( ) ) ; checkMemAllocStatus (
status ) ; for ( i = 0 ; i < smData -> mCachedDerivatives . mN ; ++ i )
smData -> mCachedDerivatives . mX [ i ] = 0.0 ; } }
#if 0
static void initializeSizePairVector ( const SmSizePair * data ,
SmSizePairVector * vector ) { const size_t n = sm_core_SmSizePairVector_size
( vector ) ; size_t i ; for ( i = 0 ; i < n ; ++ i , ++ data )
sm_core_SmSizePairVector_setValue ( vector , i , data ++ ) ; }
#endif
static void initAssemblyDelegate ( SmAssemblyDelegate * asmDelegate ) {
NeAllocator * alloc = ne_default_allocator ( ) ; const SmSizePair
jointToStageIdx [ 1 ] = { { 69 , 0 } } ; const size_t primitiveIndices [ 1 +
1 ] = { 0 , 1 } ; const SmSizePair stateOffsets [ 1 ] = { { 0 , 1 } } ; const
SmSizePair dofOffsets [ 1 ] = { { 0 , 1 } } ; const size_t remodIndices [ 1 ]
= { 0 } ; const size_t * equationsPerConstraint = NULL ; const size_t
dofToVelSlot [ 1 ] = { 1 } ; const size_t * constraintDofs = NULL ; const
size_t constraintDofOffsets [ 0 + 1 ] = { 0 } ; const size_t Jm = 0 ; const
size_t Jn = 1 ; SmSizePair zeroSizePair ; zeroSizePair . mFirst =
zeroSizePair . mSecond = 0 ; asmDelegate -> mTargetStrengthFree = 0 ;
asmDelegate -> mTargetStrengthSuggested = 1 ; asmDelegate ->
mTargetStrengthDesired = 2 ; asmDelegate -> mTargetStrengthRequired = 3 ;
asmDelegate -> mConsistencyTol = + 1.000000000000000100e-09 ; asmDelegate ->
mDof = 1 ; asmDelegate -> mStateSize = 2 ; asmDelegate -> mNumStages = 1 ;
asmDelegate -> mNumConstraints = 0 ; asmDelegate ->
mNumAllConstraintEquations = 0 ; sm_core_SmSizePairVector_create ( &
asmDelegate -> mJointToStageIdx , asmDelegate -> mNumStages , & zeroSizePair
) ; memcpy ( sm_core_SmSizePairVector_nonConstValues ( & asmDelegate ->
mJointToStageIdx ) , jointToStageIdx , asmDelegate -> mNumStages * sizeof (
SmSizePair ) ) ; sm_core_SmSizeTVector_create ( & asmDelegate ->
mPrimitiveIndices , asmDelegate -> mNumStages + 1 , 0 ) ; memcpy (
sm_core_SmSizeTVector_nonConstValues ( & asmDelegate -> mPrimitiveIndices ) ,
primitiveIndices , ( asmDelegate -> mNumStages + 1 ) * sizeof ( size_t ) ) ;
sm_core_SmSizePairVector_create ( & asmDelegate -> mStateOffsets , 1 , &
zeroSizePair ) ; memcpy ( sm_core_SmSizePairVector_nonConstValues ( &
asmDelegate -> mStateOffsets ) , stateOffsets , 1 * sizeof ( SmSizePair ) ) ;
sm_core_SmSizePairVector_create ( & asmDelegate -> mDofOffsets , 1 , &
zeroSizePair ) ; memcpy ( sm_core_SmSizePairVector_nonConstValues ( &
asmDelegate -> mDofOffsets ) , dofOffsets , 1 * sizeof ( SmSizePair ) ) ;
sm_core_SmSizeTVector_create ( & asmDelegate -> mRemodIndices , 1 , 0 ) ;
memcpy ( sm_core_SmSizeTVector_nonConstValues ( & asmDelegate ->
mRemodIndices ) , remodIndices , 1 * sizeof ( size_t ) ) ;
sm_core_SmSizeTVector_create ( & asmDelegate -> mEquationsPerConstraint ,
asmDelegate -> mNumConstraints , 0 ) ; memcpy (
sm_core_SmSizeTVector_nonConstValues ( & asmDelegate ->
mEquationsPerConstraint ) , equationsPerConstraint , asmDelegate ->
mNumConstraints * sizeof ( size_t ) ) ; sm_core_SmSizeTVector_create ( &
asmDelegate -> mDofToVelSlot , asmDelegate -> mDof , 0 ) ; memcpy (
sm_core_SmSizeTVector_nonConstValues ( & asmDelegate -> mDofToVelSlot ) ,
dofToVelSlot , asmDelegate -> mDof * sizeof ( size_t ) ) ;
sm_core_SmSizeTVector_create ( & asmDelegate -> mConstraintDofs , 0 , 0 ) ;
memcpy ( sm_core_SmSizeTVector_nonConstValues ( & asmDelegate ->
mConstraintDofs ) , constraintDofs , 0 * sizeof ( size_t ) ) ;
sm_core_SmSizeTVector_create ( & asmDelegate -> mConstraintDofOffsets ,
asmDelegate -> mNumConstraints + 1 , 0 ) ; memcpy (
sm_core_SmSizeTVector_nonConstValues ( & asmDelegate -> mConstraintDofOffsets
) , constraintDofOffsets , ( asmDelegate -> mNumConstraints + 1 ) * sizeof (
size_t ) ) ; sm_core_SmBoundedSet_create ( & asmDelegate -> mPosRequired , 1
) ; sm_core_SmBoundedSet_create ( & asmDelegate -> mPosDesired , 1 ) ;
sm_core_SmBoundedSet_create ( & asmDelegate -> mPosSuggested , 1 ) ;
sm_core_SmBoundedSet_create ( & asmDelegate -> mPosFree , 1 ) ;
sm_core_SmBoundedSet_create ( & asmDelegate -> mPosNonRequired , 1 ) ;
sm_core_SmBoundedSet_create ( & asmDelegate -> mPosSuggAndFree , 1 ) ;
sm_core_SmBoundedSet_create ( & asmDelegate -> mVelRequired , 1 ) ;
sm_core_SmBoundedSet_create ( & asmDelegate -> mVelDesired , 1 ) ;
sm_core_SmBoundedSet_create ( & asmDelegate -> mVelSuggested , 1 ) ;
sm_core_SmBoundedSet_create ( & asmDelegate -> mVelFree , 1 ) ;
sm_core_SmBoundedSet_create ( & asmDelegate -> mVelNonRequired , 1 ) ;
sm_core_SmBoundedSet_create ( & asmDelegate -> mVelSuggAndFree , 1 ) ;
sm_core_SmBoundedSet_create ( & asmDelegate -> mConstraintFilter , 0 ) ;
sm_core_SmBoundedSet_create ( & asmDelegate -> mActiveConstraints , 0 ) ;
sm_core_SmBoundedSet_create ( & asmDelegate -> mActiveDofs , 1 ) ;
sm_core_SmBoundedSet_create ( & asmDelegate -> mNewConstraints , 0 ) ;
sm_core_SmBoundedSet_create ( & asmDelegate -> mNewDofs , 1 ) ;
sm_core_SmBoundedSet_create ( & asmDelegate -> mUnsatisfiedConstraints , 0 )
; sm_core_SmSizeTVector_create ( & asmDelegate -> mActiveConstraintsVect , 0
, 0 ) ; sm_core_SmSizeTVector_create ( & asmDelegate -> mActiveDofsVect , 1 ,
0 ) ; sm_core_SmSizePairVector_create ( & asmDelegate -> mBaseFrameVelOffsets
, 0 , & zeroSizePair ) ; sm_core_SmRealVector_create ( & asmDelegate ->
mInitialState , 2 , 0.0 ) ; sm_core_SmRealVector_create ( & asmDelegate ->
mStartState , 2 , 0.0 ) ; sm_core_SmRealVector_create ( & asmDelegate ->
mTestState , 2 , 0.0 ) ; sm_core_SmRealVector_create ( & asmDelegate ->
mJacobian , Jm * Jn , 0.0 ) ; sm_core_SmRealVector_create ( & asmDelegate ->
mJacobianColMaj , Jm * Jn , 0.0 ) ; sm_core_SmRealVector_create ( &
asmDelegate -> mConstraintNonhomoTerms , Jm , 0.0 ) ;
sm_core_SmRealVector_create ( & asmDelegate -> mConstraintError , Jm , 0.0 )
; sm_core_SmRealVector_create ( & asmDelegate -> mBestConstraintError , Jm ,
0.0 ) ; sm_core_SmRealVector_create ( & asmDelegate -> mDeltas , Jn * ( Jm <=
Jn ? Jm : Jn ) , 0.0 ) ; sm_core_SmRealVector_create ( & asmDelegate ->
mSvdWork , 4 , 0.0 ) ; sm_core_SmRealVector_create ( & asmDelegate ->
mLineSearchScaledDeltaVect , 1 , 0.0 ) ; sm_core_SmRealVector_create ( &
asmDelegate -> mLineSearchTestStateVect , 2 , 0.0 ) ;
sm_core_SmRealVector_create ( & asmDelegate -> mLineSearchErrorVect , Jm ,
0.0 ) ; sm_core_SmRealVector_create ( & asmDelegate ->
mActiveDofDeltaVelsVect , 1 , 0.0 ) ; sm_core_SmRealVector_create ( &
asmDelegate -> mVelSystemRhs , Jm , 0.0 ) ; sm_core_SmRealVector_create ( &
asmDelegate -> mMotionData , 13 , 0.0 ) ; asmDelegate -> mResetStateVector =
Ensayos_Friccion_fe93f61_2_resetStateVector ; asmDelegate ->
mInitializeTrackedAngleState =
Ensayos_Friccion_fe93f61_2_initializeTrackedAngleState ; asmDelegate ->
mComputeDiscreteState = Ensayos_Friccion_fe93f61_2_computeDiscreteState ;
asmDelegate -> mAdjustPosition = Ensayos_Friccion_fe93f61_2_adjustPosition ;
asmDelegate -> mPerturbState = Ensayos_Friccion_fe93f61_2_perturbState ;
asmDelegate -> mPropagateMotion = Ensayos_Friccion_fe93f61_2_propagateMotion
; asmDelegate -> mComputeAssemblyError =
Ensayos_Friccion_fe93f61_2_computeAssemblyError ; asmDelegate ->
mComputeAssemblyJacobian = Ensayos_Friccion_fe93f61_2_computeAssemblyJacobian
; asmDelegate -> mComputeFullAssemblyJacobian =
Ensayos_Friccion_fe93f61_2_computeFullAssemblyJacobian ; asmDelegate ->
mConvertStateVector = Ensayos_Friccion_fe93f61_2_convertStateVector ;
asmDelegate -> mMech = NULL ; } static void initAssemblyStructures (
NeDaePrivateData * smData ) { NeAllocator * alloc = ne_default_allocator ( )
; const int32_T * motionInputOffsets = NULL ; int_T status = 0 ;
initAssemblyDelegate ( & smData -> mAssemblyDelegate ) ; status =
neu_create_int_vector_fields ( & smData -> mMotionInputOffsets , smData ->
mNumInputMotionPrimitives , alloc ) ; checkMemAllocStatus ( status ) ; memcpy
( smData -> mMotionInputOffsets . mX , motionInputOffsets , 0 * sizeof (
int32_T ) ) ; } static void initComputationFcnPtrs ( NeDaePrivateData *
smData ) { smData -> mDerivativeFcn = dae_deriv_method ; smData -> mOutputFcn
= dae_output_method ; smData -> mProjectionFcn = dae_project_solve ; smData
-> mCheckFcn = ( smData -> mStateVectorSize == 0 && smData ->
mNumConstraintEqns > 0 ) ? dae_project_solve : NULL ; smData -> mAssemblyFcn
= dae_assemble_solve ; smData -> mSetupLoggerFcn =
sm_ssci_setupLoggerFcn_codeGen ; smData -> mLogFcn = sm_ssci_logFcn_codeGen ;
smData -> mResidualsFcn = NULL ; smData -> mLinearizeFcn = NULL ; smData ->
mGenerateFcn = NULL ; } static void initLiveLinkToSm ( NeDaePrivateData *
smData ) { smData -> mLiveSmLink = NULL ; smData -> mLiveSmLink_destroy =
NULL ; smData -> mLiveSmLink_copy = NULL ; } void
Ensayos_Friccion_fe93f61_2_NeDaePrivateData_create ( NeDaePrivateData *
smData ) { initBasicAttributes ( smData ) ; initStateVector ( smData ) ;
initVariables ( smData ) ; initIoInfo ( smData ) ; initInputDerivs ( smData )
; initDirectFeedthrough ( smData ) ; initOutputDerivProc ( smData ) ;
initAssemblyStructures ( smData ) ; initComputationFcnPtrs ( smData ) ;
initLiveLinkToSm ( smData ) ; }
