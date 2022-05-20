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
