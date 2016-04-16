/* Simple Serial ECHO script : Written by ScottC 03/07/2012 */

/* Use a variable called byteRead to temporarily store
   the data coming from the computer */
byte byteRead;

void setup() {                
// Turn the Serial Protocol ON
  Serial.begin(9600);
  pinMode(2, OUTPUT);

  digitalWrite(2,LOW);
}

void loop() {
   /*  check if data has been sent from the computer: */
  if (Serial.available()) {
    /* read the most recent byte */
    byteRead = Serial.read();
    /*ECHO the value that was read, back to the serial port. */
    if(byteRead==52) {
      lightLED();
    }
    else if(byteRead==53) {
      offLED();
    }
  }
}

void lightLED() {
  digitalWrite(2,HIGH);
}

void offLED() {
  digitalWrite(2,LOW);
}

