/*
 * WiperSystemControl.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "WiperSystemControl".
 *
 * Model version              : 1.5
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Wed Apr 16 17:35:41 2025
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Execution efficiency
 * Validation result: All passed
 */

#ifndef WiperSystemControl_h_
#define WiperSystemControl_h_
#ifndef WiperSystemControl_COMMON_INCLUDES_
#define WiperSystemControl_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* WiperSystemControl_COMMON_INCLUDES_ */

#include "WiperSystemControl_types.h"
#include <stddef.h>
#include <string.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real32_T WiprMotPwmDutyCyc;          /* '<Root>/Merge' */
} B_WiperSystemControl_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S1>/Unit Delay' */
} DW_WiperSystemControl_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: uDLookupTable_tableData
   * Referenced by: '<S1>/1-D Lookup Table'
   */
  real32_T uDLookupTable_tableData[8];

  /* Computed Parameter: uDLookupTable_bp01Data
   * Referenced by: '<S1>/1-D Lookup Table'
   */
  real32_T uDLookupTable_bp01Data[8];
} ConstP_WiperSystemControl_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  uint8_T WiprMod;                     /* '<Root>/WiprMod' */
  real32_T WiprSpdReq;                 /* '<Root>/WiprSpdReq' */
  boolean_T RainSnsrErr;               /* '<Root>/RainSnsrErr' */
} ExtU_WiperSystemControl_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T WiprMotPwmDutyCyc;          /* '<Root>/WiprMotPwmDutyCyc' */
} ExtY_WiperSystemControl_T;

/* Real-time Model Data Structure */
struct tag_RTM_WiperSystemControl_T {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_WiperSystemControl_T WiperSystemControl_B;

/* Block states (default storage) */
extern DW_WiperSystemControl_T WiperSystemControl_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_WiperSystemControl_T WiperSystemControl_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_WiperSystemControl_T WiperSystemControl_Y;

/* Constant parameters (default storage) */
extern const ConstP_WiperSystemControl_T WiperSystemControl_ConstP;

/* Model entry point functions */
extern void WiperSystemControl_initialize(void);
extern void WiperSystemControl_step(void);
extern void WiperSystemControl_terminate(void);

/* Real-time Model object */
extern RT_MODEL_WiperSystemControl_T *const WiperSystemControl_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'WiperSystemControl'
 * '<S1>'   : 'WiperSystemControl/AutomaticMode'
 * '<S2>'   : 'WiperSystemControl/HiSpdMode'
 * '<S3>'   : 'WiperSystemControl/LoSpdMode'
 * '<S4>'   : 'WiperSystemControl/OffMode'
 * '<S5>'   : 'WiperSystemControl/AutomaticMode/LowPassFilter'
 */
#endif                                 /* WiperSystemControl_h_ */
