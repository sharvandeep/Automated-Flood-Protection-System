/*
Automated Flood Protection System
Author: Sharvandeep Bhardwaj Kancharana

Description:
This system detects rainfall and rising water levels using sensors
and automatically activates a protective barrier using a stepper motor.
Designed as a low-cost flood mitigation solution for agricultural
and riverside environments.

Key Features:
- Rain detection alert using buzzer
- Flood detection using water level sensor
- Automated barrier activation
- Automatic reset after water level decreases

Concepts Demonstrated:
Embedded Systems, Sensor Integration, Automation Logic
*/
code:
#include <Stepper.h>

// Define the number of steps per revolution for the 28BYJ-48 stepper motor
const int stepsPerRevolution = 2048; // Full revolution steps
const int stepsPer360Degrees = stepsPerRevolution * 3; // Steps for 720 degrees (2 full revolutions)

const int floodThreshold =350 ; // Water level threshold to detect flood
const int resetThreshold = 300; // Water level threshold to reset the barrier

// Define pin numbers
const int rainSensorPin = A0; // Analog pin connected to the rain sensor
const int waterLevelSensorPin = A1; // Pin for the water level sensor (analog)
const int buzzerPin = 7; // Pin connected to the buzzer
const int motorPins[] = {8, 10, 9, 11}; // Pins for the stepper motor

// Create an instance of the Stepper class
Stepper myStepper(stepsPerRevolution, motorPins[0], motorPins[1], motorPins[2], motorPins[3]);

// State variables
bool floodDetected = false; // To track if flood is detected
bool rainDetected = false; // To track if rain is detected

void setup() {
  Serial.begin(9600); // Start serial communication for debugging
  pinMode(buzzerPin, OUTPUT); // Set the buzzer pin as an output
  pinMode(waterLevelSensorPin, INPUT); // Set water level sensor pin as input
  myStepper.setSpeed(15); // Set speed to 15 RPM
}

void loop() {
  // Read the rain sensor value
  int rainSensorValue = analogRead(rainSensorPin);
  Serial.print("Rain Sensor Value: ");
  Serial.println(rainSensorValue);

  // Check if rain is detected
  if (rainSensorValue < 350) { // Adjust this threshold based on your sensor
    digitalWrite(buzzerPin, HIGH); // Activate the buzzer when rain is detected
    rainDetected = true; // Mark rain as detected
    Serial.println("Rain detected! Buzzer ON");
  } else {
    digitalWrite(buzzerPin, LOW); // Turn off the buzzer when no rain is detected
    rainDetected = false; // Mark rain as not detected
    Serial.println("No rain detected. Buzzer OFF");
  }

  // Read the water level sensor
  int waterLevelValue = analogRead(waterLevelSensorPin);
  Serial.print("Water Level: ");
  Serial.println(waterLevelValue);

  // Check if the water level exceeds a certain threshold
  if (waterLevelValue > floodThreshold && !floodDetected) { // Adjust this threshold based on your sensor
    Serial.println("Flood detected! Activating motor to rotate 720 degrees.");
    myStepper.step(stepsPer360Degrees); // Rotate motor to 720 degrees (2 full revolutions)
    floodDetected = true; // Mark flood as detected
    delay(1000); // Wait for a second to allow the motor to complete the action
  }

  // Check if the water level has receded
  if (waterLevelValue < resetThreshold && floodDetected) { // Adjust this threshold based on your sensor
    Serial.println("Flood no longer detected! Returning motor to original position.");
    myStepper.step(-stepsPer360Degrees); // Rotate motor back to original position
    floodDetected = false; // Mark flood as not detected
    delay(1000); // Wait for a second to allow the motor to complete the action
  }

  delay(1000); // Delay before the next loop iteration
} 
