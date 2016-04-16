#include <EEPROM.h>

char inChar = -1; //where to store the character read
byte index = 0; //index into array, where to store character

int currentCubby = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, OUTPUT);

  digitalWrite(2,LOW);
}

char Comp(char* This) {
    char inData[2];
    char inChar=-1;
    byte index=0;
    while (Serial.available() > 0) // Don't read unless
                                   // there you know there is data
    {
        if(index < 2) // One less than the size of the array
        {
            inChar = Serial.read(); // Read a character
            inData[index] = inChar; // Store it
            index++; // Increment where to write next
            inData[index] = '\0'; // Null terminate the string
        }
    }

    if (strcmp(inData,This)  == 0) {
        for (int i=0;i<1;i++) {
            inData[i]=0;
        }
        index=0;
        return(0);
    }
    else {
        return(1);
    }
}


void enterPassword(char* pass) {
  char password[5];
  while (Serial.available() > 0) {
    if (index < 3) {
      inChar = Serial.read(); //read a character
      password[index] = inChar;
      index++;
      password[index] = '\0'; //null terminate the string
    }
    pass = password;
  }
}

int checkPassword(){
/*  check if data has been sent from the computer: */
  char* password;
  enterPassword(password);
  int index = 0;
  for (int i = currentCubby; i < currentCubby+4; i++) {
    if (password[index] == EEPROM.read(currentCubby+index) == 0) { //if password same, clear
   
      EEPROM.write(i,0);
    }
    index=0;
    return(0); //returns 0 if password same
  }
  else {
    return(1); //return 1 if password different
  }
}

void recoverFood() {
  char* cubby; 
  enterPassword(cubby);
  switch(cubby[0]) {
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
  
  int password_right = checkPassword(EEPROM.read(currentCubby));
  if(password_right == 0) {
    //rotate to cubby
    digitalWrite(2,HIGH);
  }
}

void savePassword() {
  char* pass;
  enterPassword(pass);
  for(int i = 0; i < 4; i++) {
   EEPROM.write(currentCubby, pass[i]);
  }
}

void loop()
{
  if (Comp("#") == 0) {
    savePassword();
  }
  else if (Comp("@") == 0) {
    recoverFood();
  }
}
