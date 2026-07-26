# Industrial Water Tank Controller using Finite State Machine (FSM)

An Embedded C project that simulates an industrial water tank controller using the Finite State Machine (FSM) concept. The project demonstrates state transitions based on user inputs and sensor conditions.

## Features

- Finite State Machine (FSM) implementation
- Industrial process simulation
- Start button control
- Water level sensor simulation
- Pump control
- Alarm indication
- Serial Monitor output

## Components Used

- Arduino Uno
- 2 LEDs
- 2 Push Buttons

## State Flow

IDLE → FILLING → FULL → DRAINING → IDLE

## Pin Configuration

| Component | Pin |
|----------|-----|
| Start Button | D2 |
| Water Level Sensor | D3 |
| Pump LED | D8 |
| Alarm LED | D9 |

## Software

- Wokwi Online Simulator
- Embedded C (Arduino)

## How to Run

1. Open the project in Wokwi.
2. Start the simulation.
3. Press the Start button.
4. Press the Water Level Sensor button.
5. Observe LED indications and Serial Monitor output.

## Learning Outcomes

- Finite State Machine (FSM)
- Embedded C Programming
- GPIO Control
- Industrial Automation Basics
- State Transition Logic

## Author

Molagamodi Kishore