const int AANTALLEDS = 6;
const int PINARRAY[] = {
  13, 12, 11, 5, 4, 3
}; 
unsigned long ledPreviousMillis;
boolean ledStatus;

void ledControlSetup() {
  for (int i = 0; i < AANTALLEDS; i++) {
      pinMode(PINARRAY[i], OUTPUT);
    }
    ledPreviousMillis = 0;
    ledStatus = false;
}

void ledControlSetLedOn(int ledNumber) {
  digitalWrite(ledNumber, HIGH);
}

void ledControlSetLedOff(int ledNumber) {
  digitalWrite(ledNumber, LOW);
}

void ledAllLedsOn() {
  for (int i = 0; i < AANTALLEDS; i++) {
      ledControlSetLedOn(PINARRAY[i]);
    }
}

void ledAllLedsOff() {
  for (int i = 0; i < AANTALLEDS; i++) {
      ledControlSetLedOff(PINARRAY[i]);
    }
}

void ledOn(int ledNr) {
  digitalWrite(ledNr, HIGH);
}

void ledOff(int ledNr) {
  digitalWrite(ledNr, LOW);
}

void ledBlink(int led1, int led2, int interval) {
  unsigned long currentMillis = millis();
  if (currentMillis >= ledPreviousMillis + interval) {
    ledPreviousMillis = currentMillis;
    if (ledStatus) {
      ledOff(led1);
      ledOff(led2);
    } else {
      ledOn(led1);
      ledOn(led2);
    }
    ledStatus = !ledStatus;
  }
} 
