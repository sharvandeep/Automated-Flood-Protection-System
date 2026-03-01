# Automated Flood Protection System

## Overview
An IoT-based automated flood protection system designed to protect agricultural fields and riverside areas from sudden flooding using sensor-driven automation.

## Problem
Flooding causes major damage to agricultural lands and low-lying areas. Manual monitoring is inefficient and delayed.

## Solution
The system detects rising water levels using sensors and automatically activates a protective boundary mechanism using stepper motors.

## Components
- Arduino Uno
- Water Level Sensor
- Stepper Motor
- Buzzer Alert System

## Control Logic

1. Rain sensor activates early warning buzzer.
2. Water level crossing threshold triggers barrier deployment.
3. Stepper motor rotates 720° to raise boundary.
4. When water recedes, barrier automatically resets.
5. // Flood detection thresholds (experimentally calibrated)

## 🎥 Project Demonstration

A working prototype demonstration of the Automated Flood Protection System:

👉 [Watch Demo Video](https://drive.google.com/file/d/1TWMDjH8uo6LwQ5Ho7vlkrrYsrqo741Hk/view?usp=sharing)

The video shows:
- Rain detection buzzer activation
- Rising water level sensing
- Automatic barrier deployment using stepper motor
- System reset after water level reduction

## Features
- Automatic flood detection
- Real-time response
- Low-cost rural deployment design

## Future Improvements
- AI-based flood prediction
- Remote monitoring dashboard
