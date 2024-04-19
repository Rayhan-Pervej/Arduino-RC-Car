//By tech with harsh 
//It takes a lot of effort and time to develop such code so please subscribe my channel and share it.
#include <AFMotor.h>
#include <Servo.h>   
#define light A0
#define back_light A1
#define buzz A2
#define ex A3
Servo name_servo;               // Define any servo name

int servo_position = 0 ;
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor4(4, MOTOR34_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ); 
AF_DCMotor motor3(3, MOTOR34_1KHZ);

int Speed = 230;

char value;
void setup() {
  name_servo.attach (10); 
  Serial.begin(9600);
  motor1.setSpeed(240);
  motor4.setSpeed(240);
  motor2.setSpeed(240);
  motor3.setSpeed(240);
  pinMode(light, OUTPUT);
  pinMode(back_light , OUTPUT);
  pinMode(buzz, OUTPUT);
  pinMode(ex, OUTPUT);

}
 
void loop() {
  if (Serial.available() > 0) {
    value = Serial.read();
  }
  if (value == 'W') {
    digitalWrite(light,HIGH);
  }
  else if (value == 'w'){
   digitalWrite(light,LOW);
  }
if (value == 'U') {
    digitalWrite(back_light,HIGH);
  }
  else if (value == 'u'){
   digitalWrite(back_light,LOW);
  }

 if (value == 'V') {
    digitalWrite(buzz,HIGH);
  }
  else if (value == 'v'){
   digitalWrite(buzz,LOW);
  }

 if (value == 'X') {
    digitalWrite(ex,HIGH);
  }
  else if (value == 'x'){
   digitalWrite(ex,LOW);
  }
  if (value == 'F') {
    motor4.run(FORWARD);
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
  } else if (value == 'B') {
    motor4.run(BACKWARD);
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
  } else if (value == 'R') {
    name_servo.write(60);
  } else if (value == 'L') {
    name_servo.write(160);
  }
  else if (value == 'I') {
    name_servo.write(60);
    motor4.run(FORWARD);
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    delay(5);
    name_servo.write(110);
  } 
  else if (value == 'G') {
    name_servo.write(160);
    motor4.run(FORWARD);
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    delay(5);
    name_servo.write(110);
  } 
  else if (value == 'J') {
    name_servo.write(60);
    motor4.run(BACKWARD);
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    delay(5);
    name_servo.write(110);
  } 
  else if (value == 'H') {
    name_servo.write(160);
    motor4.run(BACKWARD);
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    delay(5);
    name_servo.write(110);
  }
     

   else{
    name_servo.write(110);
    motor4.run(RELEASE);
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);

    
   }

}
//All rights reserved.
