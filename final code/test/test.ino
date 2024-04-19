
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
int speed = 100;
char command;


void setup() {
  // Set pins as outputs
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Attach servo to pin 11
  servoMotor.attach(6);
  
  // Initialize serial communication
  Serial.begin(9600);
  int aciDegeri=90;
}

void loop() {// Read serial input
  if (Serial.available() > 0) {
     command = Serial.read();
    servoMotor.write(90);
    if (command >= '0' && command <= '9') { // Set speed
       int speed = map(command, '0', '9', 20, 255);
      analogWrite(ENA, speed);
  analogWrite(ENB, speed);
    }
    
 else if (command == 'F') { // Move forward
      digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
    } else if (command == 'B') { // Move backward
      digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
    } else if (command == 'L') { // Turn left
      servoMotor.write(75);
      digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
    } else if (command == 'R') { // Turn right
      servoMotor.write(105);
      digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
    } else if (command == 'G') { // Forward left
     servoMotor.write(75);
      digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
    } else if (command == 'I') { // Forward right
      servoMotor.write(105);
       digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
    } else if (command == 'H') { // Backward left
    servoMotor.write(75);
     digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
      
    } else if (command == 'J') { // Backward right
     servoMotor.write(105);
      digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
    } else if (command == 'S') { // Stop
      servoMotor.write(90); // Reset servo angle
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
    }
    //  else 
  }

}
