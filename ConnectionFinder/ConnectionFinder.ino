// constants won't change. They're used here to
// set pin numbers:
const int buttonPin0 = 8;     // the number of the pushbutton pin
const int buttonPin1 = 9;     // the number of the pushbutton pin
const int buttonPin2 = 10;     // the number of the pushbutton pin
const int buttonPin3 = 11;     // the number of the pushbutton pin
const int ledPin0 =  0;      // the number of the LED pin
const int ledPin1 =  1;      // the number of the LED pin
const int ledPin2 =  2;      // the number of the LED pin
const int ledPin3 =  3;      // the number of the LED pin

// variables will change:
int buttonState0 = 0;         // variable for reading the pushbutton status
int buttonState1 = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;         // variable for reading the pushbutton status
int buttonState3 = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin0, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin0, INPUT_PULLUP);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  digitalWrite(ledPin0, LOW);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState0 = digitalRead(buttonPin0);
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  // first check
  if (buttonState0 == LOW) {
    // turn LED on:
    digitalWrite(ledPin0, HIGH);
  }
  else {
    // turn LED off:
    digitalWrite(ledPin0, LOW);
  }

  // second check
    if (buttonState1 == LOW) {
    // turn LED on:
    digitalWrite(ledPin1, HIGH);
  }
  else {
    // turn LED off:
    digitalWrite(ledPin1, LOW);
  }

   // third check
    if (buttonState2 == LOW) {
    // turn LED on:
    digitalWrite(ledPin2, HIGH);
  }
  else {
    // turn LED off:
    digitalWrite(ledPin2, LOW);
  }

  // fourth check
    if (buttonState3 == LOW) {
    // turn LED on:
    digitalWrite(ledPin3, HIGH);
  }
  else {
    // turn LED off:
    digitalWrite(ledPin3, LOW);
  }
}
