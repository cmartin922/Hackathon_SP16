// Servo controls

#include <Servo.h> 
 
Servo door1, door2;  // create servo object to control a servo 

const int door1Pin = 9;
const int door2Pin = 10;

void setup() 
{ 
  door1.attach(door1Pin);  // attaches the servo on pin 9 to the servo object 
  door2.attach(door2Pin);  // attaches the servo on pin 10 to the servo object 
  door1.write(90);
  door2.write(90);
} 
 
void loop() 
{ 
 
} 

void openDoor1() {
  door1.write(0);
  delay(100);
}

void closeDoor1() {
  door1.write(90);
  delay(100);
}

void openDoor2() {
  door2.write(0);
  delay(100);
}

void closeDoor2() {
  door2.write(90);
  delay(100);
}

