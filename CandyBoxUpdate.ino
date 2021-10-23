#include <Servo.h>
Servo myServo;

//lasor int:
const int PhotoIn = 2; //input pin for Photomicrosensor
const int LED = 13; //output pin for LED
int State = 0; //a variable to read the encoder state

void setup() {
//Servo set up:
myServo.attach(9); //attack servo's pin
myServo.write(0); //that's a starting angle
delay(1000);

//LasorSetUp:
pinMode(PhotoIn, INPUT); //set pin 2 as input
pinMode(LED, OUTPUT); //set pin 13 as output 
Serial.begin(9600);
}

void loop() {
  
State = digitalRead(PhotoIn);

if (State == HIGH) {  //if the encoder output is in a high logical state
digitalWrite(LED, HIGH); //turn the LED on
Serial.println("Broken");
myServo.write(120); //angle 180
delay(1000);
myServo.write(0);
delay(1000);
}

else {
digitalWrite(LED, LOW); //turn the LED off
Serial.println("rokenB");
}
