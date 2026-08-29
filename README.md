# Fire Response Rescue Robot — IoT & Embedded Systems

## Project Overview

The Fire Response Rescue Robot is an IoT-enabled mobile robotic system designed to assist in the assessment of indoor fire emergencies.

The robot is designed to enter a potentially hazardous environment and collect information about its surroundings before human responders enter the area. It uses multiple sensors, wireless communication, embedded control, and a virtual grid-based map to provide real-time environmental information.

The system is designed as a modular platform, allowing the computational unit to be upgraded in the future without redesigning the complete robot.

---

## Problem Statement

During indoor fire emergencies, entering an unknown environment can expose rescue personnel to hazards such as fire, smoke, toxic gases, obstacles, and unstable surroundings.

Our project aims to develop a low-cost mobile robotic platform capable of:

- Detecting environmental hazards
- Detecting obstacles
- Monitoring the robot's stability
- Tracking its movement
- Communicating sensor information wirelessly
- Building a virtual representation of the explored environment
- Supporting remote monitoring and autonomous operation

The prototype is intended for controlled environments and demonstrates the underlying technology required for a fire-response robotic system.

---

## Objectives

1. Develop a mobile robotic platform using an ESP32-based embedded system.
2. Integrate multiple sensors for environmental and robot-state monitoring.
3. Implement wireless communication between the robot and a computational system.
4. Implement real-time motor control and encoder-based movement tracking.
5. Develop a grid-based virtual map of the explored environment.
6. Detect and record fire, smoke/gas, obstacles, and robot-state information.
7. Design the system in a modular way so that the computational platform can be upgraded in the future.
8. Provide a foundation for integration with the project's separate AI system.

---

## System Architecture

```text
                    ┌─────────────────────┐
                    │      Sensors        │
                    │                     │
                    │ HC-SR04 ×3          │
                    │ MQ-2                │
                    │ Flame Sensor        │
                    │ MPU6050             │
                    │ Wheel Encoders      │
                    └──────────┬──────────┘
                               │
                               ▼
                    ┌─────────────────────┐
                    │        ESP32        │
                    │                     │
                    │ Sensor Acquisition  │
                    │ Motor Control       │
                    │ Encoder Processing  │
                    │ Local Control       │
                    └──────────┬──────────┘
                               │
                              Wi-Fi
                               │
                               ▼
                    ┌─────────────────────┐
                    │      Computer       │
                    │                     │
                    │ Mapping             │
                    │ Data Processing     │
                    │ Dashboard           │
                    │ AI Interface        │
                    └─────────────────────┘
                               │
                               ▼
                    ┌─────────────────────┐
                    │   Robot Commands    │
                    └──────────┬──────────┘
                               │
                               ▼
                    ┌─────────────────────┐
                    │    Motor Driver     │
                    └──────────┬──────────┘
                               │
                               ▼
                    ┌─────────────────────┐
                    │    4 DC Motors      │
                    └─────────────────────┘