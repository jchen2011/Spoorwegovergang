void serialSetup(int baud) {
  Serial.begin(baud);
}

char serialRead() {
  char c;
  if (Serial.available() > 0) {
    c = Serial.read();
  }
  return c;   
}

void controleerInput() {
  char input = serialRead();

  switch (input) {
    case 'R': 
      resetSlagboomTeller();
  }
}
