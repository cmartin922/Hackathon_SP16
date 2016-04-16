#include <EEPROM.h>
#include <Servo.h> 

int currentCubby = -1;

Servo door1, door2;  // create servo object to control a servo 

const int door1Pin = 9;
const int door2Pin = 10;

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin0 = 1;     // the number of the connection pin
const int buttonPin1 = 2;     // the number of the connection pin
const int buttonPin2 = 3;     // the number of the connection pin
const int buttonPin3 = 4;     // the number of the connection pin
const int motorPin = 6;      // the number of the motor pin
int velocity = 250;          // the speed of the motor (0-255)

void setup() {
  //initialize servos
  door1.attach(door1Pin);  // attaches the servo on pin 9 to the servo object 
  door2.attach(door2Pin);  // attaches the servo on pin 10 to the servo object 
  door1.write(90);
  door2.write(90);
 
  Serial.begin(9600);
  //clear EEPROM
  for (int i = 33; i < 41; i++) { //0 means empty
    EEPROM.write(i, 0);
  }
  
  currentCubby = 0;

  //print starting messages
  Serial.println(F("Enter \"# enter\" to store food."));
  Serial.println(F("Enter \"@ enter\" then your cubby number to recover food."));

}

void recoverFood() {
  delay(5000);
  char cubby = Serial.read();
  int priorCubby = currentCubby;
  switch(cubby) {
     case '1': currentCubby = 0;
      break;
     case '2': currentCubby = 4;
      break;
     case '3': currentCubby = 8;
      break;
     case '4': currentCubby = 12;
      break;
     case '5': currentCubby = 16;
      break;
     case '6': currentCubby = 20;
      break;
     case '7': currentCubby = 24;
      break;
     case '8': currentCubby = 28;
      break;
     default:
      break;
  }

  rotateTo(abs(currentCubby-priorCubby));
  
  int password_right = checkPassword();
  if(password_right == 0) {
    //rotate to cubby
    if(currentCubby < 5) {
      openDoor2();
    }
    else {
      openDoor1();
    }
  }
  delay(10000);
  reset();
}

void pickCubby() {
  for (int i = 33; i < 41; i++){
    if (EEPROM.read(i) == 0) {
      int priorCubby = currentCubby;
      currentCubby = (i-33)*4;
      Serial.print(F("Available cubby: "));
      Serial.println((currentCubby/4)+1, DEC);
      rotateTo(abs(currentCubby - priorCubby));
      return;
    }
  }
  Serial.println(F("All cubbies are full. Sorry. Come again."));
}

void reset() {
 for(int i = 0; i < 30; i++) {
   Serial.println();
 }
 Serial.write(12);
  closeDoor1();
  closeDoor2();
  pickCubby();
  Serial.println(F("Enter \"# enter\" to store food."));
  Serial.println(F("Enter \"@ enter\" then your cubby number to recover food."));
}

void loop()
{
  if(Serial.available()){
    char key = Serial.read();
      if (key == '#') {
        savePassword();
      }
      else if (key == '@') {
        recoverFood();
      }

      else if (key =='m') {
        motorGo();
        delay(780);
        motorStop();
      }
      else if(key == 'u') { // cheat open bottom
        openDoor1();
      }
      else if(key == 'v') { //cheat open top
        openDoor2();
      }
      else if(key == 'l') { //cheat close bottom
        closeDoor1();
      }
      else if(key == 'j') { //cheat close top
        closeDoor2();
      }
  }


}

