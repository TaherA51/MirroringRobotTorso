# Mirroring Robot Torso- WORK IN PROGRESS

This project focuses on creating a robot torso that mirrors human movements in real-time. The code provided is specifically for the microcontroller, which interfaces with proprietary Meccano motors designed for educational and hobbyist robotics.

## Key Components

### MotorTest.ino

This Arduino sketch tests basic robot movements, including:
- Moving forward and backward
- Turning left and right
- Stopping (fast and slow)

It uses the Arduino Robot library to control motor functions

### MirrorRobotArm_BetaV1.ino

This is the core functionality for mirroring human movements. It:
- Uses the Chain library to control Meccano servo motors
- Establishes serial communication with a computer
- Receives pose data and translates it into motor angles
- Controls shoulder pitch, shoulder roll, and elbow movements

The code ensures received angles are constrained within the operational range of 0 to 180 degrees.

## Setup

It is essential to create a pull-up resistor circuit when interfacing with the Smart modules. This circuit is necessary to ensure that the data communication line maintains a defined state when no active signal is present, preventing it from floating and potentially causing erratic behavior. The pull-up resistor connects the data line to a high voltage (typically 5V), ensuring that the line reads high when not actively driven low by a connected module. Read the SmartModulesProtocol file for more information on how to do this. Each Smart Module operates at 5 volts, when designing the system, ensure that the power supply can adequately provide for all connected modules without exceeding their current limits. A 9V battery with the power line connected to Arduino's VIM pin hole seemed to suffice for our daisy chained 3 motor system. Finally:

1. Connect the chainPin to digital pin 3 on the Arduino
2. Assign motor IDs:
   - 0: Shoulder pitch
   - 1: Shoulder roll
   - 2: Elbow

## Usage

1. Upload the sketch to your Arduino board
2. Open serial monitor at 9600 baud
3. Send angle data in the format: "shoulder_pitch,shoulder_roll,elbow"
4. The robot arm will mirror the movements based on the received angles

## Dependencies

- Arduino Robot library
- Meccano Smart Motor interfacing library: https://github.com/alexfrederiksen/MeccanoidForArduino
