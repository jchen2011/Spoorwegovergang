byte nummers[] {
   0b11111100,  //0 
   0b01100000,  //1
   0b11011010,  //2
   0b11110010,  //3 
   0b01100110,  //4
   0b10110110,  //5 
};

int countdown = 5;
boolean countdownReset = false;

unsigned long displayPreviousMillis;

void displaySetup() {
  setupShiftRegister();
  displayPreviousMillis = 0;
}

void displayNumber(byte number) {
  setShiftRegister(number);
}

void displayCountdown(int interval) {
  unsigned long currentMillis = millis();
  countdownReset = false;
  if (currentMillis >= displayPreviousMillis + interval) {
    displayPreviousMillis = millis();
    displayNumber(nummers[countdown--]);

    if (countdown < 0) {
      countdown = 5;
      countdownReset = true;
    }
  }
}

boolean vrijGegeven() {
  return countdownReset;
}
