#include "__cf_Ensayos_Friccion.h"
#ifndef RTW_HEADER_Ensayos_Friccion_h_
#define RTW_HEADER_Ensayos_Friccion_h_
#include <string.h>
#include <stddef.h>
#include "rtw_modelmap.h"
#ifndef Ensayos_Friccion_COMMON_INCLUDES_
#define Ensayos_Friccion_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#include "nesl_rtw.h"
#include "Ensayos_Friccion_fe93f61_gateway.h"
#endif
#include "Ensayos_Friccion_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME Ensayos_Friccion
#define NSAMPLE_TIMES (2) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (27) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (3)   
#elif NCSTATES != 3
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
typedef struct { real_T mb32kofeaj [ 2 ] ; real_T jygob3b3q4 [ 2 ] ; real_T
og0vqabzz1 ; real_T jrcr0hqppv ; real_T jsceoxumdg ; real_T bbrhi2aa4o ;
real_T n3sk3m5mid ; real_T kxibtkeec5 ; real_T enw5bh50ec ; real_T kq2v02wqsv
; real_T csph14lqqx ; real_T jvbzfyxc03 ; real_T ijqtrjxdsh [ 4 ] ; real_T
bztakntxrl ; real_T p2zhwbrpql ; real_T enns31nw1s ; real_T jejwlkbmc2 ;
real_T dessyx1zav ; real_T ctssu21gdv ; real_T orlilvcezk ; real_T dbi3o4yn43
; real_T kcfeei3ce0 ; real_T apvpvqneyh [ 4 ] ; real_T bzizsky3i2 ; real_T
flitgoamze ; real_T ow1luaqdsv ; real_T ptrzoxc51k [ 4 ] ; } B ; typedef
struct { real_T px2h4fxqvc ; real_T gt0elxwjeb ; real_T j0qqzzt21t ; void *
gk0htlbrma ; void * is0xydhs4l ; void * ka0rn1jqlo ; void * ix1x41bo4v ; void
* aswm55dcsr ; void * akflnq5gjx ; void * b2mtd04ww2 ; void * mxmjsp3mlq ;
void * nhl3ynb1oz ; void * i4sxnucti0 ; struct { void * LoggedData ; }
hzmvsaoulo ; void * depbo03vrk ; void * bjxpzefqp3 ; void * g5mb0p1qhu ; void
* pcqktgmah0 ; void * nvguz3vz4c ; void * eioh2xr3aq ; void * khywewrhhg ;
void * gr25vq2fuc ; void * mt2eznmsv5 ; void * aegvhv5w45 ; void * lwg50jsxft
; void * j1rpvtehmk ; void * lidhiurvks ; void * kv4zbkviwj ; void *
d2gx0feb1q ; void * ko5bzgm54o ; void * hlaipun4ez ; void * amndknbiec ; void
* kssewaxdx3 ; void * pminz14afl ; struct { void * LoggedData ; } jjrd2czqdm
; void * jm0fzi1blb ; void * op23awaojj ; void * ioyxzcapgj ; void *
kahykihega ; void * aom3mirt2x ; void * aou51eikro ; void * eufaiemnot ; void
* ewleodkp1x ; void * m0fguvm2fm ; void * dxrjr0gy3k ; void * nfcjhvjxuy ;
void * osydjefyeb ; void * alt2ulitdc ; void * eerr0ropq4 ; void * gv4r4p2yf2
; int_T nujczoxr2h ; int_T mkghkkvf3s ; int32_T bcjys3m3es ; } DW ; typedef
struct { real_T hdzhv0kuvm [ 2 ] ; real_T axhrigh31z ; } X ; typedef struct {
real_T hdzhv0kuvm [ 2 ] ; real_T axhrigh31z ; } XDot ; typedef struct {
boolean_T hdzhv0kuvm [ 2 ] ; boolean_T axhrigh31z ; } XDis ; typedef struct {
real_T hdzhv0kuvm [ 2 ] ; real_T axhrigh31z ; } CStateAbsTol ; typedef struct
{ real_T hhdi32quq3 ; real_T ke0y3dgz5x ; } ZCV ; typedef struct { ZCSigState
c2cz3ngzkq ; ZCSigState gie2waax12 ; } PrevZCX ; typedef struct { int_T ir [
3 ] ; int_T jc [ 3 + 1 ] ; real_T pr [ 3 ] ; } MassMatrix ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T Gain_Gain ;
real_T Fs_Gain ; real_T Fc_Gain ; real_T To_Gain ; real_T Constant_Value ;
real_T Gain3_Gain ; real_T Gain_Gain_b1oehh4m53 ; real_T Fs_Gain_gejxjpa1bz ;
real_T Fc_Gain_ncx454w25g ; real_T To_Gain_oixd02jkdm ; real_T
Constant_Value_nicvna5tcb ; real_T Gain3_Gain_oxdnjjsq1e ; } ; extern P rtP ;
extern const char * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX
; extern DW rtDW ; extern PrevZCX rtPrevZCX ; extern MassMatrix rtMassMatrix
; extern const rtwCAPI_ModelMappingStaticInfo *
Ensayos_Friccion_GetCAPIStaticMap ( void ) ; extern SimStruct * const rtS ;
extern const int_T gblNumToFiles ; extern const int_T gblNumFrFiles ; extern
const int_T gblNumFrWksBlocks ; extern rtInportTUtable * gblInportTUtables ;
extern const char * gblInportFileName ; extern const int_T
gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern const
int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ;
#endif
