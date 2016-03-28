#include "__cf_Ensayos_Friccion.h"
#include "ne_ds.h"
#include "Ensayos_Friccion_fe93f61_1_ds.h"
#ifndef struct__NeDynamicSystemTag
#define struct__NeDynamicSystemTag
typedef struct _NeDynamicSystemTag { NeDynamicSystem mBase ; int32_T mRefCnt
; NeAllocator mAlloc ; } _NeDynamicSystem ;
#else
typedef struct _NeDynamicSystemTag _NeDynamicSystem ;
#endif
static int32_T ds_s ( const NeDynamicSystem * ds , const NeDynamicSystemInput
* in , NeDsMethodOutput * out ) ; static int32_T ds_m_p ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , NeDsMethodOutput *
out ) ; static int32_T ds_a_p ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T ds_a (
const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_b_p ( const NeDynamicSystem * ds
, const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_b ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_c_p ( const NeDynamicSystem * ds
, const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_f ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_vmf ( const NeDynamicSystem * ds
, const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_slf ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_dxf_p ( const NeDynamicSystem *
ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_dxf ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in
, NeDsMethodOutput * out ) ; static int32_T ds_duf_p ( const NeDynamicSystem
* ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_dtf_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput *
in , NeDsMethodOutput * out ) ; static int32_T ds_ddf_p ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , NeDsMethodOutput *
out ) ; static int32_T ds_tduf_p ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_tdxf_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_y ( const NeDynamicSystem * ds ,
const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_dxy_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_dxy ( const NeDynamicSystem * ds
, const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static int32_T
ds_duy_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T ds_dty_p ( const NeDynamicSystem *
ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
int32_T ds_r ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out ) ; static int32_T stub_method ( const NeDynamicSystem
* ds , const NeDynamicSystemInput * in , NeDsMethodOutput * out ) ; static
NeDsMethodOutput * ds_output_s ( const NeDynamicSystem * ds , NeAllocator *
allocator ) ; static NeDsMethodOutput * ds_output_m_p ( const NeDynamicSystem
* ds , NeAllocator * allocator ) ; static NeDsMethodOutput * ds_output_m (
const NeDynamicSystem * ds , NeAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_vmm ( const NeDynamicSystem * ds , NeAllocator *
allocator ) ; static NeDsMethodOutput * ds_output_dxm_p ( const
NeDynamicSystem * ds , NeAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_dxm ( const NeDynamicSystem * ds , NeAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_dum_p ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) ; static NeDsMethodOutput * ds_output_dum ( const
NeDynamicSystem * ds , NeAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_dtm_p ( const NeDynamicSystem * ds , NeAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_dtm ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) ; static NeDsMethodOutput * ds_output_a_p ( const
NeDynamicSystem * ds , NeAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_a ( const NeDynamicSystem * ds , NeAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_b_p ( const NeDynamicSystem * ds , NeAllocator *
allocator ) ; static NeDsMethodOutput * ds_output_b ( const NeDynamicSystem *
ds , NeAllocator * allocator ) ; static NeDsMethodOutput * ds_output_c_p (
const NeDynamicSystem * ds , NeAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_c ( const NeDynamicSystem * ds , NeAllocator *
allocator ) ; static NeDsMethodOutput * ds_output_f ( const NeDynamicSystem *
ds , NeAllocator * allocator ) ; static NeDsMethodOutput * ds_output_vmf (
const NeDynamicSystem * ds , NeAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_slf ( const NeDynamicSystem * ds , NeAllocator *
allocator ) ; static NeDsMethodOutput * ds_output_dxf_p ( const
NeDynamicSystem * ds , NeAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_dxf ( const NeDynamicSystem * ds , NeAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_duf_p ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) ; static NeDsMethodOutput * ds_output_duf ( const
NeDynamicSystem * ds , NeAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_dtf_p ( const NeDynamicSystem * ds , NeAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_dtf ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) ; static NeDsMethodOutput * ds_output_ddf_p ( const
NeDynamicSystem * ds , NeAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_ddf ( const NeDynamicSystem * ds , NeAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_tduf_p ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) ; static NeDsMethodOutput * ds_output_tdxf_p (
const NeDynamicSystem * ds , NeAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_y ( const NeDynamicSystem * ds , NeAllocator *
allocator ) ; static NeDsMethodOutput * ds_output_dxy_p ( const
NeDynamicSystem * ds , NeAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_dxy ( const NeDynamicSystem * ds , NeAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_duy_p ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) ; static NeDsMethodOutput * ds_output_duy ( const
NeDynamicSystem * ds , NeAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_dty_p ( const NeDynamicSystem * ds , NeAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_dty ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) ; static NeDsMethodOutput * ds_output_mode ( const
NeDynamicSystem * ds , NeAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_zc ( const NeDynamicSystem * ds , NeAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_cache ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) ; static NeDsMethodOutput * ds_output_update_r (
const NeDynamicSystem * ds , NeAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_update_i ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) ; static NeDsMethodOutput * ds_output_sfo ( const
NeDynamicSystem * ds , NeAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_sfp ( const NeDynamicSystem * ds , NeAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_init_r ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) ; static NeDsMethodOutput * ds_output_init_i (
const NeDynamicSystem * ds , NeAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_r ( const NeDynamicSystem * ds , NeAllocator *
allocator ) ; static NeDsMethodOutput * ds_output_log ( const NeDynamicSystem
* ds , NeAllocator * allocator ) ; static NeDsMethodOutput * ds_output_assert
( const NeDynamicSystem * ds , NeAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_del_t ( const NeDynamicSystem * ds , NeAllocator
* allocator ) ; static NeDsMethodOutput * ds_output_del_v ( const
NeDynamicSystem * ds , NeAllocator * allocator ) ; static NeDsMethodOutput *
ds_output_del_v0 ( const NeDynamicSystem * ds , NeAllocator * allocator ) ;
static NeDsMethodOutput * ds_output_del_tmax ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) ; static NeDsMethodOutput * ds_output_dxdelt_p (
const NeDynamicSystem * ds , NeAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_dxdelt ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) ; static NeDsMethodOutput * ds_output_dudelt_p (
const NeDynamicSystem * ds , NeAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_dudelt ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) ; static NeDsMethodOutput * ds_output_dtdelt_p (
const NeDynamicSystem * ds , NeAllocator * allocator ) ; static
NeDsMethodOutput * ds_output_dtdelt ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) ; static void release_reference ( NeDynamicSystem *
ds ) ; static void get_reference ( NeDynamicSystem * ds ) ; static
NeEquationData s_equation_data [ 3 ] = { {
"Ensayos_Friccion.DeltaSM.Friccion_Coulomb_R2.PS_Subtract" , 0U , 8 ,
NE_EQUATION_DOMAIN_TIME ,
"Ensayos_Friccion/DeltaSM/Friccion  Coulomb R2/PS Subtract" , 1U , 0U , TRUE
, 1.0 } , { "Ensayos_Friccion.DeltaSM.Friccion_Coulomb_R.PS_Subtract" , 0U ,
8 , NE_EQUATION_DOMAIN_TIME ,
"Ensayos_Friccion/DeltaSM/Friccion  Coulomb R/PS Subtract" , 1U , 1U , TRUE ,
1.0 } , { "Ensayos_Friccion.DeltaSM.PS_Constant" , 0U , 8 ,
NE_EQUATION_DOMAIN_TIME , "Ensayos_Friccion/DeltaSM/PS Constant" , 1U , 2U ,
TRUE , 1.0 } } ; static NeVariableData s_variable_data [ 3 ] = { {
"Ensayos_Friccion.DeltaSM.Friccion_Coulomb_R.PS_Subtract.O" , 0U , 2 ,
"Ensayos_Friccion/DeltaSM/Friccion  Coulomb R/PS Subtract" , 1.0 , "1" , 0.0
, FALSE , FALSE , 1U , 1U , NE_INIT_MODE_NONE , "O" } , {
"Ensayos_Friccion.DeltaSM.PS_Constant.O" , 0U , 2 ,
"Ensayos_Friccion/DeltaSM/PS Constant" , 1.0 , "1" , 0.0 , FALSE , FALSE , 1U
, 1U , NE_INIT_MODE_NONE , "O" } , {
"Ensayos_Friccion.DeltaSM.Friccion_Coulomb_R2.PS_Subtract.O" , 0U , 2 ,
"Ensayos_Friccion/DeltaSM/Friccion \nCoulomb\nR2/PS Subtract" , 1.0 , "1" ,
0.0 , FALSE , FALSE , 1U , 1U , NE_INIT_MODE_NONE , "O" } } ; static
NeVariableData * s_discrete_data = NULL ; static NeModeData *
s_major_mode_data = NULL ; static NeZCData * s_zc_data = NULL ; static
NeRange * s_range = NULL ; static NeAssertData * s_assert_data = NULL ;
static NeRange * s_assert_range = NULL ; static NeRange s_equation_range [ 3
] = { {
 "C:/Program Files/MATLAB/R2014a/toolbox/physmod/simscape/library/m/+foundation/+physical_signal/+functions/subtract.ssc"
, 21U , 5U , 21U , 17U , NE_RANGE_TYPE_NORMAL } , {
 "C:/Program Files/MATLAB/R2014a/toolbox/physmod/simscape/library/m/+foundation/+physical_signal/+functions/subtract.ssc"
, 21U , 5U , 21U , 17U , NE_RANGE_TYPE_NORMAL } , {
 "C:/Program Files/MATLAB/R2014a/toolbox/physmod/simscape/library/m/+foundation/+physical_signal/+sources/constant.ssc"
, 21U , 5U , 21U , 18U , NE_RANGE_TYPE_NORMAL } } ; static int32_T ds_s (
const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out1 ) { NeIntVector local0 ; ( void ) in ; local0 = out1
-> mS ; local0 . mX [ 0ULL ] = 0 ; local0 . mX [ 1ULL ] = 0 ; local0 . mX [
2ULL ] = 0 ; ( void ) ds ; ( void ) in ; return 0 ; } static int32_T ds_m_p (
const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out1 ) { NeSparsityPattern local0 ; ( void ) in ; local0 =
out1 -> mM_P ; local0 . mJc [ 0ULL ] = 0 ; local0 . mJc [ 1ULL ] = 0 ; local0
. mJc [ 2ULL ] = 0 ; local0 . mJc [ 3ULL ] = 0 ; ( void ) ds ; ( void ) in ;
return 0 ; } static int32_T ds_a_p ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out1 ) { NeSparsityPattern
local0 ; ( void ) in ; local0 = out1 -> mA_P ; local0 . mJc [ 0ULL ] = 0 ;
local0 . mJc [ 1ULL ] = 2 ; local0 . mJc [ 2ULL ] = 3 ; local0 . mJc [ 3ULL ]
= 4 ; local0 . mIr [ 0ULL ] = 0 ; local0 . mIr [ 1ULL ] = 1 ; local0 . mIr [
2ULL ] = 1 ; local0 . mIr [ 3ULL ] = 0 ; ( void ) ds ; ( void ) in ; return 0
; } static int32_T ds_a ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out1 ) { NeRealVector local0 ;
( void ) in ; local0 = out1 -> mA ; local0 . mX [ 0ULL ] = - 1.0 ; local0 .
mX [ 1ULL ] = 1.0 ; local0 . mX [ 2ULL ] = - 1.0 ; local0 . mX [ 3ULL ] = 1.0
; ( void ) ds ; ( void ) in ; return 0 ; } static int32_T ds_b_p ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , NeDsMethodOutput *
out1 ) { NeSparsityPattern local0 ; ( void ) in ; local0 = out1 -> mB_P ;
local0 . mJc [ 0ULL ] = 0 ; local0 . mJc [ 1ULL ] = 1 ; local0 . mJc [ 2ULL ]
= 2 ; local0 . mIr [ 0ULL ] = 1 ; local0 . mIr [ 1ULL ] = 0 ; ( void ) ds ; (
void ) in ; return 0 ; } static int32_T ds_b ( const NeDynamicSystem * ds ,
const NeDynamicSystemInput * in , NeDsMethodOutput * out1 ) { NeRealVector
local0 ; ( void ) in ; local0 = out1 -> mB ; local0 . mX [ 0ULL ] = 1.0 ;
local0 . mX [ 1ULL ] = 1.0 ; ( void ) ds ; ( void ) in ; return 0 ; } static
int32_T ds_c_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in
, NeDsMethodOutput * out1 ) { NeSparsityPattern local0 ; ( void ) in ; local0
= out1 -> mC_P ; local0 . mJc [ 0ULL ] = 0 ; local0 . mJc [ 1ULL ] = 0 ; (
void ) ds ; ( void ) in ; return 0 ; } static int32_T ds_f ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , NeDsMethodOutput *
out1 ) { NeRealVector local0 ; real_T X_idx_1 ; X_idx_1 = in -> mX . mX [ 1 ]
; local0 = out1 -> mF ; local0 . mX [ 0ULL ] = 0.0 ; local0 . mX [ 1ULL ] =
0.0 ; local0 . mX [ 2ULL ] = 0.0 - X_idx_1 ; ( void ) ds ; ( void ) in ;
return 0 ; } static int32_T ds_vmf ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out1 ) { NeBoolVector local0 ;
( void ) in ; local0 = out1 -> mVMF ; local0 . mX [ 0 ] = false ; local0 . mX
[ 1 ] = false ; local0 . mX [ 2 ] = true ; ( void ) ds ; ( void ) in ; return
0 ; } static int32_T ds_slf ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out1 ) { NeBoolVector local0 ;
( void ) in ; local0 = out1 -> mSLF ; local0 . mX [ 0 ] = false ; local0 . mX
[ 1 ] = false ; local0 . mX [ 2 ] = false ; ( void ) ds ; ( void ) in ;
return 0 ; } static int32_T ds_dxf_p ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out1 ) { NeSparsityPattern
local0 ; ( void ) in ; local0 = out1 -> mDXF_P ; local0 . mJc [ 0ULL ] = 0 ;
local0 . mJc [ 1ULL ] = 0 ; local0 . mJc [ 2ULL ] = 1 ; local0 . mJc [ 3ULL ]
= 1 ; local0 . mIr [ 0ULL ] = 2 ; ( void ) ds ; ( void ) in ; return 0 ; }
static int32_T ds_dxf ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out1 ) { NeRealVector local0 ;
( void ) in ; local0 = out1 -> mDXF ; local0 . mX [ 0ULL ] = - 1.0 ; ( void )
ds ; ( void ) in ; return 0 ; } static int32_T ds_duf_p ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , NeDsMethodOutput *
out1 ) { NeSparsityPattern local0 ; ( void ) in ; local0 = out1 -> mDUF_P ;
local0 . mJc [ 0ULL ] = 0 ; local0 . mJc [ 1ULL ] = 0 ; local0 . mJc [ 2ULL ]
= 0 ; ( void ) ds ; ( void ) in ; return 0 ; } static int32_T ds_dtf_p (
const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out1 ) { NeSparsityPattern local0 ; ( void ) in ; local0 =
out1 -> mDTF_P ; local0 . mJc [ 0ULL ] = 0 ; local0 . mJc [ 1ULL ] = 0 ; (
void ) ds ; ( void ) in ; return 0 ; } static int32_T ds_ddf_p ( const
NeDynamicSystem * ds , const NeDynamicSystemInput * in , NeDsMethodOutput *
out1 ) { NeSparsityPattern local0 ; ( void ) in ; local0 = out1 -> mDDF_P ;
local0 . mJc [ 0ULL ] = 0 ; ( void ) ds ; ( void ) in ; return 0 ; } static
int32_T ds_tduf_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput *
in , NeDsMethodOutput * out1 ) { NeSparsityPattern local0 ; ( void ) in ;
local0 = out1 -> mTDUF_P ; local0 . mJc [ 0ULL ] = 0 ; local0 . mJc [ 1ULL ]
= 1 ; local0 . mJc [ 2ULL ] = 2 ; local0 . mIr [ 0ULL ] = 1 ; local0 . mIr [
1ULL ] = 0 ; ( void ) ds ; ( void ) in ; return 0 ; } static int32_T
ds_tdxf_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out1 ) { NeSparsityPattern local0 ; ( void ) in ; local0 =
out1 -> mTDXF_P ; local0 . mJc [ 0ULL ] = 0 ; local0 . mJc [ 1ULL ] = 2 ;
local0 . mJc [ 2ULL ] = 4 ; local0 . mJc [ 3ULL ] = 5 ; local0 . mIr [ 0ULL ]
= 0 ; local0 . mIr [ 1ULL ] = 1 ; local0 . mIr [ 2ULL ] = 1 ; local0 . mIr [
3ULL ] = 2 ; local0 . mIr [ 4ULL ] = 0 ; ( void ) ds ; ( void ) in ; return 0
; } static int32_T ds_y ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out1 ) { NeRealVector local0 ;
real_T X_idx_2 ; X_idx_2 = in -> mX . mX [ 2 ] ; local0 = out1 -> mY ; local0
. mX [ 0ULL ] = X_idx_2 ; ( void ) ds ; ( void ) in ; return 0 ; } static
int32_T ds_dxy_p ( const NeDynamicSystem * ds , const NeDynamicSystemInput *
in , NeDsMethodOutput * out1 ) { NeSparsityPattern local0 ; ( void ) in ;
local0 = out1 -> mDXY_P ; local0 . mJc [ 0ULL ] = 0 ; local0 . mJc [ 1ULL ] =
0 ; local0 . mJc [ 2ULL ] = 0 ; local0 . mJc [ 3ULL ] = 1 ; local0 . mIr [
0ULL ] = 0 ; ( void ) ds ; ( void ) in ; return 0 ; } static int32_T ds_dxy (
const NeDynamicSystem * ds , const NeDynamicSystemInput * in ,
NeDsMethodOutput * out1 ) { NeRealVector local0 ; ( void ) in ; local0 = out1
-> mDXY ; local0 . mX [ 0ULL ] = 1.0 ; ( void ) ds ; ( void ) in ; return 0 ;
} static int32_T ds_duy_p ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out1 ) { NeSparsityPattern
local0 ; ( void ) in ; local0 = out1 -> mDUY_P ; local0 . mJc [ 0ULL ] = 0 ;
local0 . mJc [ 1ULL ] = 0 ; local0 . mJc [ 2ULL ] = 0 ; ( void ) ds ; ( void
) in ; return 0 ; } static int32_T ds_dty_p ( const NeDynamicSystem * ds ,
const NeDynamicSystemInput * in , NeDsMethodOutput * out1 ) {
NeSparsityPattern local0 ; ( void ) in ; local0 = out1 -> mDTY_P ; local0 .
mJc [ 0ULL ] = 0 ; local0 . mJc [ 1ULL ] = 0 ; ( void ) ds ; ( void ) in ;
return 0 ; } static int32_T ds_r ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out1 ) { NeRealVector local0 ;
( void ) in ; local0 = out1 -> mR ; local0 . mX [ 0ULL ] = 0.0 ; local0 . mX
[ 1ULL ] = 0.0 ; local0 . mX [ 2ULL ] = 0.0 ; ( void ) ds ; ( void ) in ;
return 0 ; } static int32_T stub_method ( const NeDynamicSystem * ds , const
NeDynamicSystemInput * in , NeDsMethodOutput * out ) { ( void ) ds ; ( void )
in ; ( void ) out ; return 0 ; } static NeDsMethodOutput * ds_output_s (
const NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mS . mN = 3 ; out ->
mS . mX = ( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof (
int32_T ) , 3 ) ; return out ; } static NeDsMethodOutput * ds_output_m_p (
const NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mM_P . mNumCol = 3 ;
out -> mM_P . mNumRow = 3 ; out -> mM_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 4 ) ; out -> mM_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_m ( const NeDynamicSystem
* ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out
= ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mM . mN = 0 ; out -> mM . mX = ( real_T * )
allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 ) ; return out ;
} static NeDsMethodOutput * ds_output_vmm ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mVMM . mN = 0 ; out -> mVMM . mX = (
boolean_T * ) allocator -> mCallocFcn ( allocator , sizeof ( boolean_T ) , 0
) ; return out ; } static NeDsMethodOutput * ds_output_dxm_p ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDXM_P . mNumCol = 3 ; out ->
mDXM_P . mNumRow = 0 ; out -> mDXM_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 4 ) ; out -> mDXM_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_dxm ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDXM . mN = 0 ; out -> mDXM . mX
= ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 )
; return out ; } static NeDsMethodOutput * ds_output_dum_p ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDUM_P . mNumCol = 2 ; out ->
mDUM_P . mNumRow = 0 ; out -> mDUM_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 3 ) ; out -> mDUM_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_dum ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDUM . mN = 0 ; out -> mDUM . mX
= ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 )
; return out ; } static NeDsMethodOutput * ds_output_dtm_p ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDTM_P . mNumCol = 1 ; out ->
mDTM_P . mNumRow = 0 ; out -> mDTM_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 2 ) ; out -> mDTM_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_dtm ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDTM . mN = 0 ; out -> mDTM . mX
= ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 )
; return out ; } static NeDsMethodOutput * ds_output_a_p ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mA_P . mNumCol = 3 ; out -> mA_P
. mNumRow = 3 ; out -> mA_P . mJc = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 4 ) ; out -> mA_P . mIr = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 4 ) ; return out ;
} static NeDsMethodOutput * ds_output_a ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mA . mN = 4 ; out -> mA . mX = ( real_T * )
allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 4 ) ; return out ;
} static NeDsMethodOutput * ds_output_b_p ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mB_P . mNumCol = 2 ; out -> mB_P . mNumRow
= 3 ; out -> mB_P . mJc = ( int32_T * ) allocator -> mCallocFcn ( allocator ,
sizeof ( int32_T ) , 3 ) ; out -> mB_P . mIr = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 2 ) ; return out ; } static
NeDsMethodOutput * ds_output_b ( const NeDynamicSystem * ds , NeAllocator *
allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput
* ) allocator -> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ;
out -> mB . mN = 2 ; out -> mB . mX = ( real_T * ) allocator -> mCallocFcn (
allocator , sizeof ( real_T ) , 2 ) ; return out ; } static NeDsMethodOutput
* ds_output_c_p ( const NeDynamicSystem * ds , NeAllocator * allocator ) {
NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator
-> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mC_P .
mNumCol = 1 ; out -> mC_P . mNumRow = 3 ; out -> mC_P . mJc = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 2 ) ; out -> mC_P
. mIr = ( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T
) , 0 ) ; return out ; } static NeDsMethodOutput * ds_output_c ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mC . mN = 0 ; out -> mC . mX = (
real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_f ( const NeDynamicSystem
* ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out
= ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mF . mN = 3 ; out -> mF . mX = ( real_T * )
allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 3 ) ; return out ;
} static NeDsMethodOutput * ds_output_vmf ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mVMF . mN = 3 ; out -> mVMF . mX = (
boolean_T * ) allocator -> mCallocFcn ( allocator , sizeof ( boolean_T ) , 3
) ; return out ; } static NeDsMethodOutput * ds_output_slf ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mSLF . mN = 3 ; out -> mSLF . mX
= ( boolean_T * ) allocator -> mCallocFcn ( allocator , sizeof ( boolean_T )
, 3 ) ; return out ; } static NeDsMethodOutput * ds_output_dxf_p ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDXF_P . mNumCol = 3 ; out ->
mDXF_P . mNumRow = 3 ; out -> mDXF_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 4 ) ; out -> mDXF_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 1 ) ;
return out ; } static NeDsMethodOutput * ds_output_dxf ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDXF . mN = 1 ; out -> mDXF . mX
= ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 1 )
; return out ; } static NeDsMethodOutput * ds_output_duf_p ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDUF_P . mNumCol = 2 ; out ->
mDUF_P . mNumRow = 3 ; out -> mDUF_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 3 ) ; out -> mDUF_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_duf ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDUF . mN = 0 ; out -> mDUF . mX
= ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 )
; return out ; } static NeDsMethodOutput * ds_output_dtf_p ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDTF_P . mNumCol = 1 ; out ->
mDTF_P . mNumRow = 3 ; out -> mDTF_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 2 ) ; out -> mDTF_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_dtf ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDTF . mN = 0 ; out -> mDTF . mX
= ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 )
; return out ; } static NeDsMethodOutput * ds_output_ddf_p ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDDF_P . mNumCol = 0 ; out ->
mDDF_P . mNumRow = 3 ; out -> mDDF_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 1 ) ; out -> mDDF_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_ddf ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDDF . mN = 0 ; out -> mDDF . mX
= ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 )
; return out ; } static NeDsMethodOutput * ds_output_tduf_p ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mTDUF_P . mNumCol = 2 ; out ->
mTDUF_P . mNumRow = 3 ; out -> mTDUF_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 3 ) ; out -> mTDUF_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 2 ) ;
return out ; } static NeDsMethodOutput * ds_output_tdxf_p ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mTDXF_P . mNumCol = 3 ; out ->
mTDXF_P . mNumRow = 3 ; out -> mTDXF_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 4 ) ; out -> mTDXF_P . mIr = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 5 ) ;
return out ; } static NeDsMethodOutput * ds_output_y ( const NeDynamicSystem
* ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out
= ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mY . mN = 1 ; out -> mY . mX = ( real_T * )
allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 1 ) ; return out ;
} static NeDsMethodOutput * ds_output_dxy_p ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mDXY_P . mNumCol = 3 ; out -> mDXY_P .
mNumRow = 1 ; out -> mDXY_P . mJc = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 4 ) ; out -> mDXY_P . mIr = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 1 ) ; return out ;
} static NeDsMethodOutput * ds_output_dxy ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mDXY . mN = 1 ; out -> mDXY . mX = ( real_T
* ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 1 ) ; return
out ; } static NeDsMethodOutput * ds_output_duy_p ( const NeDynamicSystem *
ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out =
( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mDUY_P . mNumCol = 2 ; out -> mDUY_P .
mNumRow = 1 ; out -> mDUY_P . mJc = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 3 ) ; out -> mDUY_P . mIr = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ; return out ;
} static NeDsMethodOutput * ds_output_duy ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mDUY . mN = 0 ; out -> mDUY . mX = ( real_T
* ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 ) ; return
out ; } static NeDsMethodOutput * ds_output_dty_p ( const NeDynamicSystem *
ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out =
( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mDTY_P . mNumCol = 1 ; out -> mDTY_P .
mNumRow = 1 ; out -> mDTY_P . mJc = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 2 ) ; out -> mDTY_P . mIr = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ; return out ;
} static NeDsMethodOutput * ds_output_dty ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mDTY . mN = 0 ; out -> mDTY . mX = ( real_T
* ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 ) ; return
out ; } static NeDsMethodOutput * ds_output_mode ( const NeDynamicSystem * ds
, NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mMODE . mN = 0 ; out -> mMODE . mX = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_zc ( const NeDynamicSystem
* ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out
= ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mZC . mN = 0 ; out -> mZC . mX = ( real_T *
) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 ) ; return out
; } static NeDsMethodOutput * ds_output_cache ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mCACHE . mN = 0 ; out -> mCACHE . mX = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_update_r ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mUPDATE_R . mN = 0 ; out ->
mUPDATE_R . mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof (
real_T ) , 0 ) ; return out ; } static NeDsMethodOutput * ds_output_update_i
( const NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mUPDATE_I . mN = 0 ;
out -> mUPDATE_I . mX = ( int32_T * ) allocator -> mCallocFcn ( allocator ,
sizeof ( int32_T ) , 0 ) ; return out ; } static NeDsMethodOutput *
ds_output_sfo ( const NeDynamicSystem * ds , NeAllocator * allocator ) {
NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator
-> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mSFO .
mN = 0 ; out -> mSFO . mX = ( real_T * ) allocator -> mCallocFcn ( allocator
, sizeof ( real_T ) , 0 ) ; return out ; } static NeDsMethodOutput *
ds_output_sfp ( const NeDynamicSystem * ds , NeAllocator * allocator ) {
NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator
-> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mSFP .
mN = 0 ; out -> mSFP . mX = ( real_T * ) allocator -> mCallocFcn ( allocator
, sizeof ( real_T ) , 0 ) ; return out ; } static NeDsMethodOutput *
ds_output_init_r ( const NeDynamicSystem * ds , NeAllocator * allocator ) {
NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator
-> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out ->
mINIT_R . mN = 0 ; out -> mINIT_R . mX = ( real_T * ) allocator -> mCallocFcn
( allocator , sizeof ( real_T ) , 0 ) ; return out ; } static
NeDsMethodOutput * ds_output_init_i ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mINIT_I . mN = 0 ; out -> mINIT_I . mX = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_r ( const NeDynamicSystem
* ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out
= ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mR . mN = 3 ; out -> mR . mX = ( real_T * )
allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 3 ) ; return out ;
} static NeDsMethodOutput * ds_output_log ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mLOG . mN = 0 ; out -> mLOG . mX = ( real_T
* ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) , 0 ) ; return
out ; } static NeDsMethodOutput * ds_output_assert ( const NeDynamicSystem *
ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out =
( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mASSERT . mN = 0 ; out -> mASSERT . mX = (
int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 ) ;
return out ; } static NeDsMethodOutput * ds_output_del_t ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDEL_T . mN = 0 ; out -> mDEL_T
. mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) ,
0 ) ; return out ; } static NeDsMethodOutput * ds_output_del_v ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDEL_V . mN = 0 ; out -> mDEL_V
. mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof ( real_T ) ,
0 ) ; return out ; } static NeDsMethodOutput * ds_output_del_v0 ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDEL_V0 . mN = 0 ; out ->
mDEL_V0 . mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof (
real_T ) , 0 ) ; return out ; } static NeDsMethodOutput * ds_output_del_tmax
( const NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDEL_TMAX . mN = 0 ;
out -> mDEL_TMAX . mX = ( real_T * ) allocator -> mCallocFcn ( allocator ,
sizeof ( real_T ) , 0 ) ; return out ; } static NeDsMethodOutput *
ds_output_dxdelt_p ( const NeDynamicSystem * ds , NeAllocator * allocator ) {
NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator
-> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out ->
mDXDELT_P . mNumCol = 3 ; out -> mDXDELT_P . mNumRow = 0 ; out -> mDXDELT_P .
mJc = ( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T )
, 4 ) ; out -> mDXDELT_P . mIr = ( int32_T * ) allocator -> mCallocFcn (
allocator , sizeof ( int32_T ) , 0 ) ; return out ; } static NeDsMethodOutput
* ds_output_dxdelt ( const NeDynamicSystem * ds , NeAllocator * allocator ) {
NeDsMethodOutput * out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator
-> mCallocFcn ( allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out ->
mDXDELT . mN = 0 ; out -> mDXDELT . mX = ( real_T * ) allocator -> mCallocFcn
( allocator , sizeof ( real_T ) , 0 ) ; return out ; } static
NeDsMethodOutput * ds_output_dudelt_p ( const NeDynamicSystem * ds ,
NeAllocator * allocator ) { NeDsMethodOutput * out ; ( void ) ds ; out = (
NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator , sizeof (
NeDsMethodOutput ) , 1 ) ; out -> mDUDELT_P . mNumCol = 2 ; out -> mDUDELT_P
. mNumRow = 0 ; out -> mDUDELT_P . mJc = ( int32_T * ) allocator ->
mCallocFcn ( allocator , sizeof ( int32_T ) , 3 ) ; out -> mDUDELT_P . mIr =
( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 0 )
; return out ; } static NeDsMethodOutput * ds_output_dudelt ( const
NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput * out ; (
void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn ( allocator
, sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDUDELT . mN = 0 ; out ->
mDUDELT . mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof (
real_T ) , 0 ) ; return out ; } static NeDsMethodOutput * ds_output_dtdelt_p
( const NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDTDELT_P . mNumCol =
1 ; out -> mDTDELT_P . mNumRow = 0 ; out -> mDTDELT_P . mJc = ( int32_T * )
allocator -> mCallocFcn ( allocator , sizeof ( int32_T ) , 2 ) ; out ->
mDTDELT_P . mIr = ( int32_T * ) allocator -> mCallocFcn ( allocator , sizeof
( int32_T ) , 0 ) ; return out ; } static NeDsMethodOutput * ds_output_dtdelt
( const NeDynamicSystem * ds , NeAllocator * allocator ) { NeDsMethodOutput *
out ; ( void ) ds ; out = ( NeDsMethodOutput * ) allocator -> mCallocFcn (
allocator , sizeof ( NeDsMethodOutput ) , 1 ) ; out -> mDTDELT . mN = 0 ; out
-> mDTDELT . mX = ( real_T * ) allocator -> mCallocFcn ( allocator , sizeof (
real_T ) , 0 ) ; return out ; } static void release_reference (
NeDynamicSystem * ds ) { _NeDynamicSystem * _ds ; _ds = ( _NeDynamicSystem *
) ds ; if ( -- _ds -> mRefCnt == 0 ) { _ds -> mAlloc . mFreeFcn ( & _ds ->
mAlloc , _ds ) ; } } static void get_reference ( NeDynamicSystem * ds ) {
_NeDynamicSystem * _ds ; _ds = ( _NeDynamicSystem * ) ds ; ++ _ds -> mRefCnt
; } NeDynamicSystem * Ensayos_Friccion_fe93f61_1_dae_ds ( NeAllocator *
allocator , const void * params ) { NeDynamicSystem * ds ; _NeDynamicSystem *
_ds ; static NeDsIoInfo input_info [ 2 ] ; static NeDsIoInfo output_info [ 1
] ; ( void ) params ; _ds = ( _NeDynamicSystem * ) allocator -> mCallocFcn (
allocator , sizeof ( _NeDynamicSystem ) , 1 ) ; _ds -> mAlloc = * allocator ;
_ds -> mRefCnt = 1 ; ds = & _ds -> mBase ; ds -> mNumVariables = 3 ; ds ->
mNumDiscreteRealVariables = 0 ; ds -> mNumDifferentialVariables = 0 ; ds ->
mNumEquations = 3 ; ds -> mNumModes = 0 ; ds -> mNumMajorModes = 0 ; ds ->
mNumCache = 0 ; ds -> mNumZcs = 0 ; ds -> mNumAsserts = 0 ; ds ->
mNumAssertRanges = 0 ; ds -> mNumRanges = 0 ; ds -> mNumEquationRanges = 3 ;
ds -> mNumFundamentalSamples = 0 ; ds -> mNumDelays = 0 ; ds ->
mIsOutputLinear = 1 ; ds -> mNumIo [ NE_INPUT_IO_TYPE ] = 2 ; input_info [ 0
] . mIdentifier =
"Ensayos_Friccion/DeltaSM/Friccion \nCoulomb\nR/PS Subtract_" ; input_info [
0 ] . mM = 1 ; input_info [ 0 ] . mN = 1 ; input_info [ 0 ] . mName =
"DeltaSM.Friccion_Coulomb_R.PS_Subtract.I2" ; input_info [ 0 ] . mUnit = "1"
; input_info [ 1 ] . mIdentifier =
"Ensayos_Friccion/DeltaSM/Friccion \nCoulomb\nR2/PS Subtract_" ; input_info [
1 ] . mM = 1 ; input_info [ 1 ] . mN = 1 ; input_info [ 1 ] . mName =
"DeltaSM.Friccion_Coulomb_R2.PS_Subtract.I2" ; input_info [ 1 ] . mUnit = "1"
; ds -> mIo [ NE_INPUT_IO_TYPE ] = input_info ; ds -> mNumIo [
NE_OUTPUT_IO_TYPE ] = 1 ; output_info [ 0 ] . mIdentifier =
"Ensayos_Friccion/DeltaSM/Friccion \nCoulomb\nR2/PS Subtract_" ; output_info
[ 0 ] . mM = 1 ; output_info [ 0 ] . mN = 1 ; output_info [ 0 ] . mName =
"DeltaSM.Friccion_Coulomb_R2.PS_Subtract.O" ; output_info [ 0 ] . mUnit = "1"
; ds -> mIo [ NE_OUTPUT_IO_TYPE ] = output_info ; ds -> mReleaseReference =
release_reference ; ds -> mGetReference = get_reference ; ds -> mMethods [
NE_DS_METHOD_S ] = ds_s ; ds -> mMakeOutput [ NE_DS_METHOD_S ] = ds_output_s
; ds -> mMethods [ NE_DS_METHOD_M_P ] = ds_m_p ; ds -> mMakeOutput [
NE_DS_METHOD_M_P ] = ds_output_m_p ; ds -> mMethods [ NE_DS_METHOD_M ] =
stub_method ; ds -> mMakeOutput [ NE_DS_METHOD_M ] = ds_output_m ; ds ->
mMethods [ NE_DS_METHOD_VMM ] = stub_method ; ds -> mMakeOutput [
NE_DS_METHOD_VMM ] = ds_output_vmm ; ds -> mMethods [ NE_DS_METHOD_DXM_P ] =
stub_method ; ds -> mMakeOutput [ NE_DS_METHOD_DXM_P ] = ds_output_dxm_p ; ds
-> mMethods [ NE_DS_METHOD_DXM ] = stub_method ; ds -> mMakeOutput [
NE_DS_METHOD_DXM ] = ds_output_dxm ; ds -> mMethods [ NE_DS_METHOD_DUM_P ] =
stub_method ; ds -> mMakeOutput [ NE_DS_METHOD_DUM_P ] = ds_output_dum_p ; ds
-> mMethods [ NE_DS_METHOD_DUM ] = stub_method ; ds -> mMakeOutput [
NE_DS_METHOD_DUM ] = ds_output_dum ; ds -> mMethods [ NE_DS_METHOD_DTM_P ] =
stub_method ; ds -> mMakeOutput [ NE_DS_METHOD_DTM_P ] = ds_output_dtm_p ; ds
-> mMethods [ NE_DS_METHOD_DTM ] = stub_method ; ds -> mMakeOutput [
NE_DS_METHOD_DTM ] = ds_output_dtm ; ds -> mMethods [ NE_DS_METHOD_A_P ] =
ds_a_p ; ds -> mMakeOutput [ NE_DS_METHOD_A_P ] = ds_output_a_p ; ds ->
mMethods [ NE_DS_METHOD_A ] = ds_a ; ds -> mMakeOutput [ NE_DS_METHOD_A ] =
ds_output_a ; ds -> mMethods [ NE_DS_METHOD_B_P ] = ds_b_p ; ds ->
mMakeOutput [ NE_DS_METHOD_B_P ] = ds_output_b_p ; ds -> mMethods [
NE_DS_METHOD_B ] = ds_b ; ds -> mMakeOutput [ NE_DS_METHOD_B ] = ds_output_b
; ds -> mMethods [ NE_DS_METHOD_C_P ] = ds_c_p ; ds -> mMakeOutput [
NE_DS_METHOD_C_P ] = ds_output_c_p ; ds -> mMethods [ NE_DS_METHOD_C ] =
stub_method ; ds -> mMakeOutput [ NE_DS_METHOD_C ] = ds_output_c ; ds ->
mMethods [ NE_DS_METHOD_F ] = ds_f ; ds -> mMakeOutput [ NE_DS_METHOD_F ] =
ds_output_f ; ds -> mMethods [ NE_DS_METHOD_VMF ] = ds_vmf ; ds ->
mMakeOutput [ NE_DS_METHOD_VMF ] = ds_output_vmf ; ds -> mMethods [
NE_DS_METHOD_SLF ] = ds_slf ; ds -> mMakeOutput [ NE_DS_METHOD_SLF ] =
ds_output_slf ; ds -> mMethods [ NE_DS_METHOD_DXF_P ] = ds_dxf_p ; ds ->
mMakeOutput [ NE_DS_METHOD_DXF_P ] = ds_output_dxf_p ; ds -> mMethods [
NE_DS_METHOD_DXF ] = ds_dxf ; ds -> mMakeOutput [ NE_DS_METHOD_DXF ] =
ds_output_dxf ; ds -> mMethods [ NE_DS_METHOD_DUF_P ] = ds_duf_p ; ds ->
mMakeOutput [ NE_DS_METHOD_DUF_P ] = ds_output_duf_p ; ds -> mMethods [
NE_DS_METHOD_DUF ] = stub_method ; ds -> mMakeOutput [ NE_DS_METHOD_DUF ] =
ds_output_duf ; ds -> mMethods [ NE_DS_METHOD_DTF_P ] = ds_dtf_p ; ds ->
mMakeOutput [ NE_DS_METHOD_DTF_P ] = ds_output_dtf_p ; ds -> mMethods [
NE_DS_METHOD_DTF ] = stub_method ; ds -> mMakeOutput [ NE_DS_METHOD_DTF ] =
ds_output_dtf ; ds -> mMethods [ NE_DS_METHOD_DDF_P ] = ds_ddf_p ; ds ->
mMakeOutput [ NE_DS_METHOD_DDF_P ] = ds_output_ddf_p ; ds -> mMethods [
NE_DS_METHOD_DDF ] = stub_method ; ds -> mMakeOutput [ NE_DS_METHOD_DDF ] =
ds_output_ddf ; ds -> mMethods [ NE_DS_METHOD_TDUF_P ] = ds_tduf_p ; ds ->
mMakeOutput [ NE_DS_METHOD_TDUF_P ] = ds_output_tduf_p ; ds -> mMethods [
NE_DS_METHOD_TDXF_P ] = ds_tdxf_p ; ds -> mMakeOutput [ NE_DS_METHOD_TDXF_P ]
= ds_output_tdxf_p ; ds -> mMethods [ NE_DS_METHOD_Y ] = ds_y ; ds ->
mMakeOutput [ NE_DS_METHOD_Y ] = ds_output_y ; ds -> mMethods [
NE_DS_METHOD_DXY_P ] = ds_dxy_p ; ds -> mMakeOutput [ NE_DS_METHOD_DXY_P ] =
ds_output_dxy_p ; ds -> mMethods [ NE_DS_METHOD_DXY ] = ds_dxy ; ds ->
mMakeOutput [ NE_DS_METHOD_DXY ] = ds_output_dxy ; ds -> mMethods [
NE_DS_METHOD_DUY_P ] = ds_duy_p ; ds -> mMakeOutput [ NE_DS_METHOD_DUY_P ] =
ds_output_duy_p ; ds -> mMethods [ NE_DS_METHOD_DUY ] = stub_method ; ds ->
mMakeOutput [ NE_DS_METHOD_DUY ] = ds_output_duy ; ds -> mMethods [
NE_DS_METHOD_DTY_P ] = ds_dty_p ; ds -> mMakeOutput [ NE_DS_METHOD_DTY_P ] =
ds_output_dty_p ; ds -> mMethods [ NE_DS_METHOD_DTY ] = stub_method ; ds ->
mMakeOutput [ NE_DS_METHOD_DTY ] = ds_output_dty ; ds -> mMethods [
NE_DS_METHOD_MODE ] = stub_method ; ds -> mMakeOutput [ NE_DS_METHOD_MODE ] =
ds_output_mode ; ds -> mMethods [ NE_DS_METHOD_ZC ] = stub_method ; ds ->
mMakeOutput [ NE_DS_METHOD_ZC ] = ds_output_zc ; ds -> mMethods [
NE_DS_METHOD_CACHE ] = stub_method ; ds -> mMakeOutput [ NE_DS_METHOD_CACHE ]
= ds_output_cache ; ds -> mMethods [ NE_DS_METHOD_UPDATE_R ] = stub_method ;
ds -> mMakeOutput [ NE_DS_METHOD_UPDATE_R ] = ds_output_update_r ; ds ->
mMethods [ NE_DS_METHOD_UPDATE_I ] = stub_method ; ds -> mMakeOutput [
NE_DS_METHOD_UPDATE_I ] = ds_output_update_i ; ds -> mMethods [
NE_DS_METHOD_SFO ] = stub_method ; ds -> mMakeOutput [ NE_DS_METHOD_SFO ] =
ds_output_sfo ; ds -> mMethods [ NE_DS_METHOD_SFP ] = stub_method ; ds ->
mMakeOutput [ NE_DS_METHOD_SFP ] = ds_output_sfp ; ds -> mMethods [
NE_DS_METHOD_INIT_R ] = stub_method ; ds -> mMakeOutput [ NE_DS_METHOD_INIT_R
] = ds_output_init_r ; ds -> mMethods [ NE_DS_METHOD_INIT_I ] = stub_method ;
ds -> mMakeOutput [ NE_DS_METHOD_INIT_I ] = ds_output_init_i ; ds -> mMethods
[ NE_DS_METHOD_R ] = ds_r ; ds -> mMakeOutput [ NE_DS_METHOD_R ] =
ds_output_r ; ds -> mMethods [ NE_DS_METHOD_LOG ] = stub_method ; ds ->
mMakeOutput [ NE_DS_METHOD_LOG ] = ds_output_log ; ds -> mMethods [
NE_DS_METHOD_ASSERT ] = stub_method ; ds -> mMakeOutput [ NE_DS_METHOD_ASSERT
] = ds_output_assert ; ds -> mMethods [ NE_DS_METHOD_DEL_T ] = stub_method ;
ds -> mMakeOutput [ NE_DS_METHOD_DEL_T ] = ds_output_del_t ; ds -> mMethods [
NE_DS_METHOD_DEL_V ] = stub_method ; ds -> mMakeOutput [ NE_DS_METHOD_DEL_V ]
= ds_output_del_v ; ds -> mMethods [ NE_DS_METHOD_DEL_V0 ] = stub_method ; ds
-> mMakeOutput [ NE_DS_METHOD_DEL_V0 ] = ds_output_del_v0 ; ds -> mMethods [
NE_DS_METHOD_DEL_TMAX ] = stub_method ; ds -> mMakeOutput [
NE_DS_METHOD_DEL_TMAX ] = ds_output_del_tmax ; ds -> mMethods [
NE_DS_METHOD_DXDELT_P ] = stub_method ; ds -> mMakeOutput [
NE_DS_METHOD_DXDELT_P ] = ds_output_dxdelt_p ; ds -> mMethods [
NE_DS_METHOD_DXDELT ] = stub_method ; ds -> mMakeOutput [ NE_DS_METHOD_DXDELT
] = ds_output_dxdelt ; ds -> mMethods [ NE_DS_METHOD_DUDELT_P ] = stub_method
; ds -> mMakeOutput [ NE_DS_METHOD_DUDELT_P ] = ds_output_dudelt_p ; ds ->
mMethods [ NE_DS_METHOD_DUDELT ] = stub_method ; ds -> mMakeOutput [
NE_DS_METHOD_DUDELT ] = ds_output_dudelt ; ds -> mMethods [
NE_DS_METHOD_DTDELT_P ] = stub_method ; ds -> mMakeOutput [
NE_DS_METHOD_DTDELT_P ] = ds_output_dtdelt_p ; ds -> mMethods [
NE_DS_METHOD_DTDELT ] = stub_method ; ds -> mMakeOutput [ NE_DS_METHOD_DTDELT
] = ds_output_dtdelt ; ds -> mEquationData = s_equation_data ; ds ->
mVariableData = s_variable_data ; ds -> mDiscreteData = s_discrete_data ; ds
-> mMajorModeData = s_major_mode_data ; ds -> mZCData = s_zc_data ; ds ->
mRanges = s_range ; ds -> mAssertData = s_assert_data ; ds -> mAssertRanges =
s_assert_range ; ds -> mEquationRanges = s_equation_range ; return (
NeDynamicSystem * ) _ds ; }
