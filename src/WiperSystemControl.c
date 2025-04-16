/*
 * WiperSystemControl.c
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

#include "WiperSystemControl.h"
#include "rtwtypes.h"
#include <string.h>
#include "WiperSystemControl_private.h"

/* Block signals (default storage) */
B_WiperSystemControl_T WiperSystemControl_B;

/* Block states (default storage) */
DW_WiperSystemControl_T WiperSystemControl_DW;

/* External inputs (root inport signals with default storage) */
ExtU_WiperSystemControl_T WiperSystemControl_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_WiperSystemControl_T WiperSystemControl_Y;

/* Real-time model */
static RT_MODEL_WiperSystemControl_T WiperSystemControl_M_;
RT_MODEL_WiperSystemControl_T *const WiperSystemControl_M =
  &WiperSystemControl_M_;
real32_T look1_iflf_binlg(real32_T u0, const real32_T bp0[], const real32_T
  table[], uint32_T maxIndex)
{
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'on'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'on'
   */
  /* Binary Search */
  bpIdx = maxIndex >> 1U;
  iLeft = 0U;
  iRght = maxIndex;
  while (iRght - iLeft > 1U) {
    if (u0 < bp0[bpIdx]) {
      iRght = bpIdx;
    } else {
      iLeft = bpIdx;
    }

    bpIdx = (iRght + iLeft) >> 1U;
  }

  real32_T yL_0d0;

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'wrapping'
   */
  yL_0d0 = table[iLeft];
  return (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]) * (table[iLeft + 1U]
    - yL_0d0) + yL_0d0;
}

/* Model step function */
void WiperSystemControl_step(void)
{
  real32_T rtb_UnitDelay;

  /* SwitchCase: '<Root>/Switch Case1' incorporates:
   *  Inport: '<Root>/WiprMod'
   */
  switch (WiperSystemControl_U.WiprMod) {
   case 0:
    /* Outputs for IfAction SubSystem: '<Root>/OffMode' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* Merge: '<Root>/Merge' incorporates:
     *  Constant: '<S4>/Constant'
     *  SignalConversion generated from: '<S4>/WiprMotPwmDutyCyc'
     */
    WiperSystemControl_B.WiprMotPwmDutyCyc = 0.0F;

    /* End of Outputs for SubSystem: '<Root>/OffMode' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<Root>/AutomaticMode' incorporates:
     *  ActionPort: '<S1>/Action Port'
     */
    /* Switch: '<S1>/Switch' incorporates:
     *  Constant: '<S1>/DutyCycleIn'
     *  Inport: '<Root>/RainSnsrErr'
     *  Inport: '<Root>/WiprSpdReq'
     *  Lookup_n-D: '<S1>/1-D Lookup Table'
     */
    if (WiperSystemControl_U.RainSnsrErr) {
      rtb_UnitDelay = 0.0F;
    } else {
      rtb_UnitDelay = look1_iflf_binlg(WiperSystemControl_U.WiprSpdReq,
        WiperSystemControl_ConstP.uDLookupTable_bp01Data,
        WiperSystemControl_ConstP.uDLookupTable_tableData, 7U);
    }

    /* End of Switch: '<S1>/Switch' */

    /* Sum: '<S5>/Add1' incorporates:
     *  Gain: '<S5>/Gain'
     *  Gain: '<S5>/Gain1'
     *  UnitDelay: '<S1>/Unit Delay'
     */
    rtb_UnitDelay = 0.2F * rtb_UnitDelay + 0.8F *
      WiperSystemControl_DW.UnitDelay_DSTATE;

    /* Merge: '<Root>/Merge' incorporates:
     *  SignalConversion generated from: '<S1>/WiprMotPwmDutyCyc'
     */
    WiperSystemControl_B.WiprMotPwmDutyCyc = rtb_UnitDelay;

    /* Update for UnitDelay: '<S1>/Unit Delay' */
    WiperSystemControl_DW.UnitDelay_DSTATE = rtb_UnitDelay;

    /* End of Outputs for SubSystem: '<Root>/AutomaticMode' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<Root>/LoSpdMode' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* Merge: '<Root>/Merge' incorporates:
     *  Constant: '<S3>/Constant1'
     *  SignalConversion generated from: '<S3>/WiprMotPwmDutyCyc'
     */
    WiperSystemControl_B.WiprMotPwmDutyCyc = 0.4F;

    /* End of Outputs for SubSystem: '<Root>/LoSpdMode' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<Root>/HiSpdMode' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* Merge: '<Root>/Merge' incorporates:
     *  Constant: '<S2>/Constant2'
     *  SignalConversion generated from: '<S2>/WiprMotPwmDutyCyc'
     */
    WiperSystemControl_B.WiprMotPwmDutyCyc = 0.7F;

    /* End of Outputs for SubSystem: '<Root>/HiSpdMode' */
    break;
  }

  /* End of SwitchCase: '<Root>/Switch Case1' */

  /* Outport: '<Root>/WiprMotPwmDutyCyc' */
  WiperSystemControl_Y.WiprMotPwmDutyCyc =
    WiperSystemControl_B.WiprMotPwmDutyCyc;
}

/* Model initialize function */
void WiperSystemControl_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(WiperSystemControl_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &WiperSystemControl_B), 0,
                sizeof(B_WiperSystemControl_T));

  /* states (dwork) */
  (void) memset((void *)&WiperSystemControl_DW, 0,
                sizeof(DW_WiperSystemControl_T));

  /* external inputs */
  (void)memset(&WiperSystemControl_U, 0, sizeof(ExtU_WiperSystemControl_T));

  /* external outputs */
  WiperSystemControl_Y.WiprMotPwmDutyCyc = 0.0F;

  /* SystemInitialize for IfAction SubSystem: '<Root>/AutomaticMode' */
  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
  WiperSystemControl_DW.UnitDelay_DSTATE = 0.0F;

  /* End of SystemInitialize for SubSystem: '<Root>/AutomaticMode' */

  /* SystemInitialize for Merge: '<Root>/Merge' */
  WiperSystemControl_B.WiprMotPwmDutyCyc = 0.0F;
}

/* Model terminate function */
void WiperSystemControl_terminate(void)
{
  /* (no terminate code required) */
}
