#include <Servo.h>

Servo name_servo;

void setup()
{
  name_servo.attach(6); // Attaching the servo to pin 6
  Serial.begin(9600);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
}

void loop()
{
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