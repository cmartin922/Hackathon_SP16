void connection_finder_setup() {
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin0, INPUT_PULLUP);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
}

void firstDoor() {
  buttonState0 = digitalRead(buttonPin0);
  while (buttonState0 != LOW) {
    // turn motor on:
    analogWrite(motorPin, velocity);
    delay(10);
    buttonState0 = digitalRead(buttonPin0);
  }
  // turn motor off:
  analogWrite(motorPin, 0);
  delay(100);
}

void secondDoor() {
  buttonState1 = digitalRead(buttonPin1);
  while (buttonState1 != LOW) {
    // turn motor on:
    analogWrite(motorPin, velocity);
    delay(10);
    buttonState1 = digitalRead(buttonPin1);
  }
  // turn motor off:
  analogWrite(motorPin, 0);
  delay(100);
}

void thirdDoor() {
  buttonState2 = digitalRead(buttonPin2);
  while (buttonState2 != LOW) {
    // turn motor on:
    analogWrite(motorPin, velocity);
    delay(10);
    buttonState2 = digitalRead(buttonPin2);
  }
  // turn motor off:
  analogWrite(motorPin, 0);
  delay(100);
}

void fourthDoor() {
  buttonState3 = digitalRead(buttonPin3);
  while (buttonState3 != LOW) {
    // turn motor on:
    analogWrite(motorPin, velocity);
    delay(10);
    buttonState3 = digitalRead(buttonPin3);
  }
  // turn motor off:
  analogWrite(motorPin, 0);
  delay(100);
}
