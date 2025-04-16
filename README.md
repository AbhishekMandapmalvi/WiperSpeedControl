# Wiper System Control Processing

This project implements the control logic for an automotive wiper system. The system determines the PWM duty cycle for the wiper motor based on the selected mode and sensor inputs.

## Modes of Operation

- **Wiper Mode (`WiprMod`):**  
  The wiper system operates in one of the following modes:

  - **0: Off**
    - `WiprMotPwmDutyCyc = 0%`

  - **1: Automatic (Aut)**
    - If `RainSnsrErr` (Rain Sensor Error) is **true**, then the PWM duty cycle shall be zero.
    - Else:
      - **Wiper Speed Request (`WiprSpdReq`):**  
        Required speed level in case of automatic mode: `[0 1 2 3 4 5 6 7]`
      - **Rain Sensor to PWM Table:**  
        Maps speed request to duty cycle: `[0 40% 45% 50% 55% 60% 65% 70%]`
      - **Smoothing Requirement:**  
        It is required to have a smooth PWM command in automatic mode (avoid abrupt changes).

  - **2: Low Speed (LoSpd)**
    - `WiprMotPwmDutyCyc = 40%`

  - **3: High Speed (HiSpd)**
    - `WiprMotPwmDutyCyc = 70%`

---

## Summary

The wiper system must output the correct PWM duty cycle for the wiper motor based on the mode of operation, handle rain sensor errors, map automatic speed requests to the correct duty cycle, and ensure smooth transitions in automatic mode.
