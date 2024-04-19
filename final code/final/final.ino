#include <Servo.h>

// Define pins
#define ENA 3
#define IN1 12
#define IN2 11
#define IN3 9
#define IN4 19
#define ENB 5

Servo servoMotor; // Define servo object

// Variables to store motor speeds
int speed = 0;
char command;

void setup() {
  // Set pins as outputs
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Attach servo to pin 6
  servoMotor.attach(6);
  
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Read serial input
  if (Serial.available() > 0) {
    command = Serial.read();
    
    if (command >= '0' && command <= '9') { // Set speed
      speed = map(command, '0', '9', 20, 255);
      analogWrite(ENA, speed);
      analogWrite(ENB, speed);
    } else {
      // Reset servo angle
      
      
      // Handle motor commands
      switch (command) {
        case 'F': // Move forward
        servoMotor.write(90);
          digitalWrite(IN1, HIGH);
          digitalWrite(IN2, LOW);
          digitalWrite(IN3, HIGH);
          digitalWrite(IN4, LOW);
          break;
        case 'B': // Move backward
        servoMotor.write(90);
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, HIGH);
          digitalWrite(IN3, LOW);
          digitalWrite(IN4, HIGH);
          break;
        case 'L': // Turn left
          servoMotor.write(75);
          digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
          break;
        case 'R': // Turn right
          servoMotor.write(105);
          digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
          break;
        case 'G': // Forward left
          servoMotor.write(75);
          digitalWrite(IN1, HIGH);
          digitalWrite(IN2, LOW);
          digitalWrite(IN3, HIGH);
          digitalWrite(IN4, LOW);
          break;
        case 'I': // Forward right
          servoMotor.write(105);
          digitalWrite(IN1, HIGH);
          digitalWrite(IN2, LOW);
          digitalWrite(IN3, HIGH);
          digitalWrite(IN4, LOW);
          break;
        case 'H': // Backward left
          servoMotor.write(75);
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, HIGH);
          digitalWrite(IN3, LOW);
          digitalWrite(IN4, HIGH);
          break;
        case 'J': // Backward right
          servoMotor.write(105);
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, HIGH);
          digitalWrite(IN3, LOW);
          digitalWrite(IN4, HIGH);
          break;
        case 'S': // Stop
          servoMotor.write(90);
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, LOW);
          digitalWrite(IN3, LOW);
          digitalWrite(IN4, LOW);
          break;
        default:
          break;
      }
    }
  }
}
