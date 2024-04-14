#include <SoftwareSerial.h>
#include <Servo.h>

// Motor control pins
#define motorA1 12
#define motorA2 11
#define ENA 3
#define motorB1 9
#define motorB2 10
#define ENB 5

// Bluetooth module pins
#define BT_TX 1 // Connect to the RX pin of the Bluetooth module
#define BT_RX 0 // Connect to the TX pin of the Bluetooth module

// Define Bluetooth commands for motor control
// #define FORWARD 'F'
// #define BACKWARD 'B'
// #define STOP 'S'

// Create a SoftwareSerial object to communicate with the Bluetooth module
SoftwareSerial bluetooth(BT_RX, BT_TX);

// Create a Servo object
Servo servo;
int signal; 
int speed = 255;

void setup()
{
  // Motor setup
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2 , OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Servo setup
  servo.attach(6); // Attaching the servo to pin 6

  // Initialize serial communication with a baud rate of 9600
  Serial.begin(9600);
   int aciDegeri=90;

  // Initialize SoftwareSerial communication with a baud rate of 9600
 // bluetooth.begin(9600);
}

  // Servo control based on serial commands
 
 void loop() {
    if(Serial.available() > 0){     
      signal = Serial.read();   
      servo.write(90);
    }
  
  // Uygulamadan ayarlanabilen 3 hız seviyesi.(Değerler 0-255 arası)
 if (signal == '1'){
    speed=20;
}
else if (signal == '2'){
    speed=50;
}
else if (signal == '3'){
    speed=70;
}
else if (signal == '4'){
    speed=100;
}
else if (signal == '5'){
    speed=150;
}
else if (signal == '6'){
    speed=170;
}
else if (signal == '7'){
    speed=200;
}
else if (signal == '8'){
    speed=230;
}
else if (signal == '9'){
    speed=255;
}


  /******************** Forward *************************/
    if (signal == 'F') {
      analogWrite(motorA1, speed); analogWrite(motorA2, 0);
        analogWrite(motorB1, speed);      analogWrite(motorB2, 0); 
    }
  /****************** Forward Right *********************/
    else if (signal == 'I') {
      analogWrite(motorA1,speed ); analogWrite(motorA2, 0);  
        analogWrite(motorB1,speed);    analogWrite(motorB2, 0); 
          servo.write(125);
    }
  /****************** Forward Left ********************/
    else if (signal == 'G') {
        analogWrite(motorA1, speed); analogWrite(motorA2, 0); 
        analogWrite(motorB1, speed);      analogWrite(motorB2, 0); 
          servo.write(55);
    }
  /****************** Backward ****************************/
    else if (signal == 'B') {
      analogWrite(motorA1, 0);   analogWrite(motorA2, speed); 
        analogWrite(motorB1, 0);   analogWrite(motorB2, speed); 
    }
  /******************* Backward Right **********************/
    else if (signal == 'J') {
      analogWrite(motorA1, 0);   analogWrite(motorA2, speed); 
        analogWrite(motorB1, 0); analogWrite(motorB2, speed);
         servo.write(125);
    }
  /******************* Backward Left *********************/
    else if (signal == 'H') {
      analogWrite(motorA1, 0);   analogWrite(motorA2, speed); 
        analogWrite(motorB1, 0);   analogWrite(motorB2, speed); 
        servo.write(55);
    }
  /********************** Right *************************/
    else if (signal == 'R') {
      analogWrite(motorA1, 0);   analogWrite(motorA2, 0); 
        analogWrite(motorB1, 0); analogWrite(motorB2, 0);
        servo.write(125); 
    }
  /*********************** Left *************************/
    else if (signal == 'L') {
      analogWrite(motorA1, 0);   analogWrite(motorA2, 0); 
        analogWrite(motorB1, 0);   analogWrite(motorB2, 0); 
        servo.write(55);    
    }
  /********************* Stop ************************/
    else if (signal == 'S'){
        analogWrite(motorA1, 0);  analogWrite(motorA2, 0); 
        analogWrite(motorB1, 0);  analogWrite(motorB2, 0);
    }  
}
 
