#include <Servo.h>  // Include the Servo motor library, which provides control over servo motors.

// Define pins for controlling the L298N motor driver.
const int LeftMotorForward = 5;    // Pin to control left motor forward.
const int LeftMotorBackward = 4;   // Pin to control left motor backward.
const int RightMotorForward = 7;   // Pin to control right motor forward.
const int RightMotorBackward = 6;  // Pin to control right motor backward.
#define enable_pin 3               // Pin to control motor speed via PWM.
const int servo_pin = 10;          // Pin to control the servo motor.

int max_speed = 100;  // Define the maximum speed for motors (PWM value).

// Define pins for the ultrasonic sensor.
#define trig_pin A4  // Pin for the ultrasonic sensor's trigger.
#define echo_pin A6  // Pin for the ultrasonic sensor's echo.

#define maximum_distance 200  // Maximum distance that the ultrasonic sensor can measure (in cm).
boolean goesForward = false;  // Boolean flag to track the robot's forward movement status.
int distance = 100;           // Variable to store the measured distance from the ultrasonic sensor.

Servo servo_motor;  // Create a Servo motor object.

// Function prototypes
int lookRight();
int lookLeft();
int measureDistance();
void stopCar();
void moveForward();
void moveBackward();
void turnRight();
void turnLeft();

void setup() {
  // Set motor control pins as outputs.
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  pinMode(enable_pin, OUTPUT);         // Set the enable pin for speed control as output.
  analogWrite(enable_pin, max_speed);  // Set the initial speed of the motors using PWM.

  servo_motor.attach(servo_pin);  // Attach the servo motor to its control pin.

  servo_motor.write(65);  // Set the initial position of the servo motor (centered).
  delay(1000);            // Wait for 1 second to let the servo move.
}

void loop() {
  int distanceRight = 0;  // Variable to store the distance measured on the right side.
  int distanceLeft = 0;   // Variable to store the distance measured on the left side.
  delay(50);              // Short delay for smoother sensor readings.

  if (distance <= 30) {           // If an obstacle is detected within 30 cm:
    stopCar();                    // Stop the robot.
    delay(300);                   // Wait for 300 ms.
    moveBackward();               // Move backward to avoid the obstacle.
    delay(400);                   // Move backward for 400 ms.
    stopCar();                    // Stop the robot again.
    delay(300);                   // Wait for 300 ms.
    distanceRight = lookRight();  // Look to the right and measure distance.
    delay(300);
    distanceLeft = lookLeft();  // Look to the left and measure distance.
    delay(300);

    if (distance >= distanceLeft) {  // If there's more space on the right:
      turnRight();                   // Turn right.
      stopCar();                     // Stop the robot after turning.
    } else {                         // Otherwise:
      turnLeft();                    // Turn left.
      stopCar();                     // Stop the robot after turning.
    }
  } else {          // If no obstacle is detected within 30 cm:
    moveForward();  // Move forward.
  }
  distance = measureDistance();  // Continuously measure distance.
}

int lookRight() {
  servo_motor.write(0);              // Turn the servo to the right.
  delay(500);                        // Wait for 500 ms to let the servo move.
  int distance = measureDistance();  // Measure the distance to the right.
  delay(100);
  servo_motor.write(65);  // Return the servo to the center position.
  return distance;        // Return the measured distance.
}

int lookLeft() {
  servo_motor.write(180);            // Turn the servo to the left.
  delay(500);                        // Wait for 500 ms to let the servo move.
  int distance = measureDistance();  // Measure the distance to the left.
  delay(100);
  servo_motor.write(65);  // Return the servo to the center position.
  return distance;        // Return the measured distance.
  delay(100);             // Additional delay (though unreachable due to return above).
}

int measureDistance() {
  delay(70);  // Small delay before taking a reading.

  return cm;  // Return the measured distance.
}

void stopCar() {
  // Stop all motor movements by setting motor pins to LOW.

}

void moveForward() {
  if (!goesForward) {    // If not already moving forward:
    goesForward = true;  // Set the flag to true (moving forward).

    // Move forward here
  }
}

void moveBackward() {
  goesForward = false;  // Set the flag to false (no longer moving forward).
}

void turnRight() {
  // Turn right by setting opposite motor directions.


  delay(500);  // Wait for 500 ms to complete the turn.

  // Move forward after turning.
}

void turnLeft() {
  // Turn left by setting opposite motor directions.


  delay(500);  // Wait for 500 ms to complete the turn.

  // Move forward after turning.
}
