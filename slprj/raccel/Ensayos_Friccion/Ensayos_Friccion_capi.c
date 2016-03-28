#include "__cf_Ensayos_Friccion.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "Ensayos_Friccion_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "Ensayos_Friccion.h"
#include "Ensayos_Friccion_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"Ensayos_Friccion/DeltaSM/Friccion  Coulomb R/Expandido/Abs" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1 , 0 , TARGET_STRING (
"Ensayos_Friccion/DeltaSM/Friccion  Coulomb R/Expandido/-To" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 2 , 0 , TARGET_STRING (
"Ensayos_Friccion/DeltaSM/Friccion  Coulomb R/Expandido/Fc" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 3 , 0 , TARGET_STRING (
"Ensayos_Friccion/DeltaSM/Friccion  Coulomb R/Expandido/Fs" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 4 , 0 , TARGET_STRING (
"Ensayos_Friccion/DeltaSM/Friccion  Coulomb R/Expandido/Gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 5 , 0 , TARGET_STRING (
"Ensayos_Friccion/DeltaSM/Friccion  Coulomb R/Expandido/Gain3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 6 , 0 , TARGET_STRING (
"Ensayos_Friccion/DeltaSM/Friccion  Coulomb R/Expandido/Product" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 7 , 0 , TARGET_STRING (
"Ensayos_Friccion/DeltaSM/Friccion  Coulomb R/Expandido/Sum" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 8 , 0 , TARGET_STRING (
"Ensayos_Friccion/DeltaSM/Friccion  Coulomb R/Expandido/Sum1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 9 , 0 , TARGET_STRING (
"Ensayos_Friccion/DeltaSM/Friccion  Coulomb R2/Expandido/Abs" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 10 , 0 , TARGET_STRING (
"Ensayos_Friccion/DeltaSM/Friccion  Coulomb R2/Expandido/-To" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 11 , 0 , TARGET_STRING (
"Ensayos_Friccion/DeltaSM/Friccion  Coulomb R2/Expandido/Fc" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 12 , 0 , TARGET_STRING (
"Ensayos_Friccion/DeltaSM/Friccion  Coulomb R2/Expandido/Fs" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 13 , 0 , TARGET_STRING (
"Ensayos_Friccion/DeltaSM/Friccion  Coulomb R2/Expandido/Gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 14 , 0 , TARGET_STRING (
"Ensayos_Friccion/DeltaSM/Friccion  Coulomb R2/Expandido/Gain3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 15 , 0 , TARGET_STRING (
"Ensayos_Friccion/DeltaSM/Friccion  Coulomb R2/Expandido/Product" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 16 , 0 , TARGET_STRING (
"Ensayos_Friccion/DeltaSM/Friccion  Coulomb R2/Expandido/Sum" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 17 , 0 , TARGET_STRING (
"Ensayos_Friccion/DeltaSM/Friccion  Coulomb R2/Expandido/Sum1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 18 , 0 , TARGET_STRING (
"Ensayos_Friccion/DeltaSM/PS-Simulink Converter/EVAL_KEY/reshape" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 19 , 0 , TARGET_STRING (
"Ensayos_Friccion/DeltaSM/PS-Simulink Converter1/EVAL_KEY/reshape" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 20 , 0 , TARGET_STRING (
"Ensayos_Friccion/DeltaSM/Solver Configuration1/EVAL_KEY/EXEC_INPUT_9" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 21 , 0 , TARGET_STRING (
"Ensayos_Friccion/DeltaSM/Solver Configuration1/EVAL_KEY/EXEC_OUTPUT_5" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 22 , 0 , TARGET_STRING (
"Ensayos_Friccion/DeltaSM/Solver Configuration1/EVAL_KEY/EXEC_OUTPUT_7" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 23 , 0 , TARGET_STRING (
"Ensayos_Friccion/DeltaSM/Solver Configuration1/EVAL_KEY/EXEC_STATE_1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 24 , 0 , TARGET_STRING (
"Ensayos_Friccion/DeltaSM/Solver Configuration1/EVAL_KEY/EXEC_STATE_2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 25 , 0 , TARGET_STRING (
 "Ensayos_Friccion/DeltaSM/Friccion  Coulomb R/Expandido/Simulink-PS Converter/EVAL_KEY/EXEC_INPUT_1"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 26 , 0 , TARGET_STRING (
 "Ensayos_Friccion/DeltaSM/Friccion  Coulomb R2/Expandido/Simulink-PS Converter/EVAL_KEY/EXEC_INPUT_1"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL
) , 0 , 0 , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . n3sk3m5mid , & rtB . kxibtkeec5 ,
& rtB . bbrhi2aa4o , & rtB . jsceoxumdg , & rtB . jrcr0hqppv , & rtB .
kq2v02wqsv , & rtB . csph14lqqx , & rtB . jvbzfyxc03 , & rtB . enw5bh50ec , &
rtB . jejwlkbmc2 , & rtB . dessyx1zav , & rtB . enns31nw1s , & rtB .
p2zhwbrpql , & rtB . bztakntxrl , & rtB . orlilvcezk , & rtB . dbi3o4yn43 , &
rtB . kcfeei3ce0 , & rtB . ctssu21gdv , & rtB . og0vqabzz1 , & rtB .
ow1luaqdsv , & rtB . ptrzoxc51k [ 0 ] , & rtB . flitgoamze , & rtB .
jygob3b3q4 [ 0 ] , & rtB . bzizsky3i2 , & rtB . mb32kofeaj [ 0 ] , & rtB .
ijqtrjxdsh [ 0 ] , & rtB . apvpvqneyh [ 0 ] , } ; static int32_T *
rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] = {
1 , 1 , 4 , 1 , 2 , 1 } ; static const real_T rtcapiStoredFloats [ ] = { 0.0
} ; static const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 0 ] , 0 , 0 } } ; static
rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 27 , ( NULL )
, 0 , ( NULL ) , 0 } , { ( NULL ) , 0 , ( NULL ) , 0 } , { ( NULL ) , 0 } , {
rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap
, rtDimensionArray } , "float" , { 1897557679U , 4222067273U , 380769674U ,
563028228U } , ( NULL ) , 0 } ; const rtwCAPI_ModelMappingStaticInfo *
Ensayos_Friccion_GetCAPIStaticMap ( ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void Ensayos_Friccion_InitializeDataMapInfo ( SimStruct * const rtS ) {
rtwCAPI_SetVersion ( ( * rt_dataMapInfoPtr ) . mmi , 1 ) ;
rtwCAPI_SetStaticMap ( ( * rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ;
rtwCAPI_SetLoggingStaticMap ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetDataAddressMap ( ( * rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ;
rtwCAPI_SetVarDimsAddressMap ( ( * rt_dataMapInfoPtr ) . mmi ,
rtVarDimsAddrMap ) ; rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr )
. mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi
, ( NULL ) ) ; rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi ,
0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void Ensayos_Friccion_host_InitializeDataMapInfo (
Ensayos_Friccion_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
