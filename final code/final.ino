#include <SoftwareSerial.h>
#include <Servo.h>

// Motor control pins
#define IN3 12
#define IN4 11
#define ENA 3
#define IN1 9
#define IN2 10
#define ENB 5

// Bluetooth module pins
#define BT_TX 1 // Connect to the RX pin of the Bluetooth module
#define BT_RX 0 // Connect to the TX pin of the Bluetooth module

// Define Bluetooth commands for motor control
#define FORWARD 'F'
#define BACKWARD 'B'
#define STOP 'S'

// Create a SoftwareSerial object to communicate with the Bluetooth module
SoftwareSerial bluetooth(BT_RX, BT_TX);

// Create a Servo object
Servo name_servo;

void setup()
{
  // Motor setup
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Servo setup
  name_servo.attach(6); // Attaching the servo to pin 6

  // Initialize serial communication with a baud rate of 9600
  Serial.begin(9600);

  // Initialize SoftwareSerial communication with a baud rate of 9600
  bluetooth.begin(9600);
}

void loop()
{
  // Motor control based on Bluetooth commands
  if (bluetooth.available() > 0)
  {
    char command = bluetooth.read();
    // Interpret Bluetooth commands
    switch (command)
    {
    case FORWARD:
      motor1Forward();
      motor2Forward();
      break;
    case BACKWARD:
      motor1Backward();
      motor2Backward();
      break;
    case STOP:
      motor1Stop();
      motor2Stop();
      break;
    default:
      break;
    }
  }

  // Servo control based on serial commands
  if (Serial.available() > 0)
  {
    char value = Serial.read();
    if (value == 'R')
    {
      for (int angle = 90; angle <= 115; angle++)
      { // Increasing angle from 90 to 115 (total 25 degree)
        name_servo.write(angle);
        delay(5); // Reduced delay for faster movement
      }
    }
    else if (value == 'L')
    {
      for (int angle = 90; angle >= 65; angle--)
      { // Decreasing angle from 90 to 65 (total 25 degree)
        name_servo.write(angle);
        delay(5); // Reduced delay for faster movement
      }
    }
    else
    {
      int currentAngle = name_servo.read(); // Read current angle
      if (currentAngle > 90)
      { // If servo is at right position
        for (int angle = currentAngle; angle >= 90; angle--)
        { // Decrease angle to 90
          name_servo.write(angle);
          delay(5); // Reduced delay for faster movement
        }
      }
      else if (currentAngle < 90)
      { // If servo is at left position
        for (int angle = currentAngle; angle <= 90; angle++)
        { // Increase angle to 90
          name_servo.write(angle);
          delay(5); // Reduced delay for faster movement
        }
      }
    }
  }
}

// Motor 1 functions
void motor1Forward()
{
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 255); // Full speed forward for motor 1
}

void motor1Backward()
{
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 255); // Full speed backward for motor 1
}

void motor1Stop()
{
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0); // Stop motor 1
}

// Motor 2 functions
void motor2Forward()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENB, 255); // Full speed forward for motor 2
}

void motor2Backward()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENB, 255); // Full speed backward for motor 2
}

void motor2Stop()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENB, 0); // Stop motor 2
}
