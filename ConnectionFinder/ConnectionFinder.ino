// constants won't change. They're used here to
// set pin numbers:
const int buttonPin0 = 1;     // the number of the connection pin
const int buttonPin1 = 2;     // the number of the connection pin
const int buttonPin2 = 3;     // the number of the connection pin
const int buttonPin3 = 4;     // the number of the connection pin
const int motorPin = 6;      // the number of the motor pin
int velocity = 200;          // the speed of the motor (0-255)

// variables will change:
int buttonState0 = 0;         // variable for reading the connection status
int buttonState1 = 0;         // variable for reading the connection status
int buttonState2 = 0;         // variable for reading the connection status
int buttonState3 = 0;         // variable for reading the connection status

void setup() {
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin0, INPUT_PULLUP);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState0 = digitalRead(buttonPin0);
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
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
