#include <EEPROM.h>

int currentCubby = -1;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  digitalWrite(2,LOW);

  for (int i = 33; i < 41; i++) { //0 means empty
    EEPROM.write(i, 0);
  }

  currentCubby = 0;
  Serial.println(F("Enter \"# enter\" to store food."));
  Serial.println(F("Enter \"@ enter\" then your cubby number to recover food."));

}

void recoverFood() {
  delay(3000);
  char cubby = Serial.read();
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
  
  int password_right = checkPassword();
  if(password_right == 0) {
    //rotate to cubby
    digitalWrite(2,HIGH);
  }
}

void pickCubby() {
  for (int i = 33; i < 41; i++){
    Serial.println(EEPROM.read(i));
    if (EEPROM.read(i) == 0) {
      currentCubby = (i-33)*4;
      Serial.print(F("Available cubby: "));
      Serial.println((currentCubby/4)+1, DEC);
      return;
    }
  }
  Serial.println(F("All cubbies are full. Sorry. Come again."));
}

void reset() {
  //for(int i = 0; i < 30; i++) {
  //  Serial.println();
 // }
 Serial.write(12);
  digitalWrite(2,LOW);
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
      else if (key == 'l') {
        digitalWrite(2,LOW);
      }
  }
}

