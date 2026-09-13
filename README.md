# STM32F407 Firmware Framework

Reusable embedded firmware framework based on STM32F407VGT6.

## Current Features

- STM32F407 HAL
- BSP abstraction
- LED driver
- Button driver
- Non-blocking button debounce
- Button event detection
- System service abstraction

## Architecture

Application
    ↓
BSP
    ↓
STM32 HAL
    ↓
STM32F407

## Hardware

- STM32F407G-DISC1
- Green LED: PD12
- User Button: PA0
