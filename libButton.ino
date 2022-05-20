const int NOORD = A1;
const int OOST = A3;
const int ZUID = A2;
const int WEST = A0;

int knoppen[] = {NOORD, OOST, ZUID, WEST};
const int AANTAL_BUTTONS = 4;

void buttonHardwareSetup() {
  for (int i = 0; i < AANTAL_BUTTONS; i++) {
    pinMode(knoppen[i], INPUT);
  }
}

boolean buttonHardwareDown(int buttonPin) {
  return (digitalRead(knoppen[buttonPin]) == LOW);
}

boolean buttonHardwareUp(int buttonPin) {
  return !buttonHardwareDown(buttonPin);
}
