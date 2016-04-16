
/**
 * passwords.ino
 * Functions relating to password storage, comparison, and recovery
 * Chris Martin, Sara Gong, Andi Chen, William Lamb
 * 
 * Hackathon SP 2016
 */

/**
 * Interprets user 4 digit password
 */
void enterPassword(char* pass) {
  char password[5];
  int index = 0;
  int inChar = -1;

  Serial.println(F("Enter password"));
  
  delay(5000);
  while(Serial.available() > 0){
    inChar = Serial.read(); //read a character
    if(inChar!=-1){
        password[index] = inChar;
        index++;
        password[index] = '\0'; //null terminate the string
        inChar=-1;
    }
    
  }
  for(int i = 0; i < 4; i++){
    pass[i] = password[i];
  }
  pass[4]='\0';
}

/**
 * Checks if user password is correct
 */
int checkPassword(){
/*  check if data has been sent from the computer: */
  char pass[5];
  enterPassword(pass);
  int result = 0;
  for (int i = currentCubby; i < currentCubby+4; i++) {
    if(EEPROM.read(i) != pass[i-currentCubby]){
       result = 1;
    }
    if(result==0){ //clear old
        Serial.println(F("Password correct"));

        for (int i = currentCubby; i < currentCubby+4; i++) {
            EEPROM.write(i,0);
          }
        } 
     else {
              Serial.println(F("Password incorrect"));

     }
        return result;
    }
    
return -1;
}

/**
 * Saves a user password to non-volatile EEPROM
 */
void savePassword() {
  char pass[5];
  enterPassword(pass);
  Serial.println(F("Password saved"));
  Serial.print(F("Your cubby is: "));
  Serial.println((currentCubby/4)+1, DEC);

  EEPROM.write((currentCubby/4)+33, 1);
  
  for(int i = 0; i < 4; i++) {
   EEPROM.write(currentCubby+i, pass[i]);
  }

  delay(3000);
  reset();
}
