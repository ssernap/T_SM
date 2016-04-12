/* Include files */

#include "Arti_DeltaSM_Control_Fricc_sfun.h"
#include "Arti_DeltaSM_Control_Fricc_sfun_debug_macros.h"
#include "c1_Arti_DeltaSM_Control_Fricc.h"
#include "c2_Arti_DeltaSM_Control_Fricc.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _Arti_DeltaSM_Control_FriccMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void Arti_DeltaSM_Control_Fricc_initializer(void)
{
}

void Arti_DeltaSM_Control_Fricc_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_Arti_DeltaSM_Control_Fricc_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==1) {
    c1_Arti_DeltaSM_Control_Fricc_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_Arti_DeltaSM_Control_Fricc_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_Arti_DeltaSM_Control_Fricc_process_check_sum_call( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2911388541U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3142610597U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2254531172U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2758795141U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1988951430U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1290412853U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1589971048U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2800716222U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_Arti_DeltaSM_Control_Fricc_get_check_sum(mxArray
            *plhs[]);
          sf_c1_Arti_DeltaSM_Control_Fricc_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_Arti_DeltaSM_Control_Fricc_get_check_sum(mxArray
            *plhs[]);
          sf_c2_Arti_DeltaSM_Control_Fricc_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3031367619U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4001028638U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3978939492U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(838979348U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1068211307U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4134632764U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2374024225U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3106581179U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Arti_DeltaSM_Control_Fricc_autoinheritance_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "003BIvH1K6kmlG2duNyx3") == 0) {
          extern mxArray
            *sf_c1_Arti_DeltaSM_Control_Fricc_get_autoinheritance_info(void);
          plhs[0] = sf_c1_Arti_DeltaSM_Control_Fricc_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "jGHlu53ofGRqjP9uZH5NOB") == 0) {
          extern mxArray
            *sf_c2_Arti_DeltaSM_Control_Fricc_get_autoinheritance_info(void);
          plhs[0] = sf_c2_Arti_DeltaSM_Control_Fricc_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Arti_DeltaSM_Control_Fricc_get_eml_resolved_functions_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_Arti_DeltaSM_Control_Fricc_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_Arti_DeltaSM_Control_Fricc_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_Arti_DeltaSM_Control_Fricc_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_Arti_DeltaSM_Control_Fricc_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Arti_DeltaSM_Control_Fricc_third_party_uses_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "fhJHucQKlZgqglAp9VdqPG") == 0) {
          extern mxArray *sf_c1_Arti_DeltaSM_Control_Fricc_third_party_uses_info
            (void);
          plhs[0] = sf_c1_Arti_DeltaSM_Control_Fricc_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "TpKLPPhNzpaaEtDdSpjnWG") == 0) {
          extern mxArray *sf_c2_Arti_DeltaSM_Control_Fricc_third_party_uses_info
            (void);
          plhs[0] = sf_c2_Arti_DeltaSM_Control_Fricc_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_Arti_DeltaSM_Control_Fricc_updateBuildInfo_args_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "fhJHucQKlZgqglAp9VdqPG") == 0) {
          extern mxArray
            *sf_c1_Arti_DeltaSM_Control_Fricc_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_Arti_DeltaSM_Control_Fricc_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "TpKLPPhNzpaaEtDdSpjnWG") == 0) {
          extern mxArray
            *sf_c2_Arti_DeltaSM_Control_Fricc_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_Arti_DeltaSM_Control_Fricc_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void Arti_DeltaSM_Control_Fricc_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _Arti_DeltaSM_Control_FriccMachineNumber_ = sf_debug_initialize_machine
    (debugInstance,"Arti_DeltaSM_Control_Fricc","sfun",0,2,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _Arti_DeltaSM_Control_FriccMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _Arti_DeltaSM_Control_FriccMachineNumber_,0);
}

void Arti_DeltaSM_Control_Fricc_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_Arti_DeltaSM_Control_Fricc_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "Arti_DeltaSM_Control_Fricc", "Arti_DeltaSM_Control_Fricc");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_Arti_DeltaSM_Control_Fricc_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
