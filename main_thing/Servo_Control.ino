// Servo controls
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

