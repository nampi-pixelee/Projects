# Projects
🚗 Collision Avoidance System (CAS)
📌 Introduction

The Collision Avoidance System (CAS) is an Arduino-based project that enhances road safety by detecting obstacles and responding in real time. It alerts the driver and automatically adjusts movement to avoid potential collisions.

This project demonstrates how sensors, motors, and microcontrollers can be integrated to create safety systems similar to those in modern vehicles.

🎯 Features

🚧 Detects obstacles using an ultrasonic sensor

🔊 Alerts the driver with a buzzer

🔄 Controls a servo motor for steering adjustments

⚙️ Moves forward or reverses using a stepper motor

🛠️ Demonstrates real-world safety automation principles

🛠️ Hardware Required

Arduino Board

Ultrasonic Distance Sensor (HC-SR04)

Stepper Motor + Driver (28BYJ-48 with ULN2003)

Servo Motor

Passive Buzzer

Breadboard & Jumper Wires

External Power Source (e.g., 9V battery)

📦 Required Libraries

Make sure you install these libraries in your Arduino IDE before uploading the code:

Servo (for controlling the servo motor)

Stepper (for controlling the stepper motor)

SR04 (for HC-SR04 ultrasonic sensor)

pitches.h (for buzzer tones; can be copied from Arduino examples if not included)

⚙️ How It Works

Normal Mode – If no obstacle is detected (>5 cm), the vehicle moves forward.

Collision Detected – If an obstacle is ≤5 cm away:

The buzzer sounds.

The servo motor turns the wheels (reverse direction).

The stepper motor reverses to move the vehicle away.
