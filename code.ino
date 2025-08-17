#include <Stepper.h>
#include "SR04.h"
#include "pitches.h"
#include <Servo.h>

#define TRIG_PIN 12
#define ECHO_PIN 13
#define BUZZ_PIN 7

int distance;
int pos = 0;
const int stepsPerRevolution = 64*32;  // For 28BYJ-48 Stepper

Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);  // N1 - N3 - N2 - N4
SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);  // Your style
Servo myservo;

void setup() {
  myStepper.setSpeed(80);  // Set stepper speed to 80 RPM
  myservo.attach(6);       // Attach servo to pin 6
  pinMode(BUZZ_PIN, OUTPUT);
  Serial.begin(9600); // initialize the serial port:

  myservo.write(0);  // Start with servo in forward position
}

void loop() {
  distance = sr04.Distance();  // Get distance in cm

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  /*unsigned long currentMillis = millis();*/

  if (distance > 5) {
    noTone(BUZZ_PIN);                     // Turn off buzzer
    myservo.write(0);                     // Indicate forward with servo
    Serial.println("Clockwise");
    myStepper.step(1);   // Move stepper motor clockwise
  }
  if (distance <= 5) {
    tone(BUZZ_PIN, NOTE_C6);              // Play a tone when object is close
    myservo.write(180);                  // Indicate reverse with servo
    Serial.println("Counterclockwise");
    myStepper.step(-1);  // Move stepper motor counterclockwise
  } 
}
