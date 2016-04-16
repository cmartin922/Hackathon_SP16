

void motorGo() {
    // turn motor on:
    analogWrite(motorPin, velocity);
    delay(10);
  }

void motorStop() {
  // turn motor off:
  analogWrite(motorPin, 0);
  delay(100);
}

void rotateTo(int n) {
  for (int i = n; i > 0; i--) {
        motorGo();
        delay(780);
        motorStop();
        delay(500);
  }
  
}

