const int DS_PIN = 8;
const int ST_CP_PIN = 9;
const int SH_CP_PIN = 10;

void setupShiftRegister() {
  pinMode(DS_PIN, OUTPUT);
  pinMode(ST_CP_PIN, OUTPUT);
  pinMode(SH_CP_PIN, OUTPUT);
}

byte clearShiftRegister(byte value) {
  for (int i = 0; i < 8; i++) {
    value &= ~(1 << i);
  }
  return value;
}

byte AllOnShiftRegister(byte value) {
  for (int i = 0; i < 8; i++) {
    value |= (1 << i);
  }
  return value;
}

byte setShiftRegister(byte pattern) {
  digitalWrite(ST_CP_PIN, LOW);

  for (int i = 0; i < 8; i++)
  {
    digitalWrite(DS_PIN, pattern & (1 << i));
    digitalWrite(SH_CP_PIN, HIGH);
    digitalWrite(SH_CP_PIN, LOW);
  }

  digitalWrite(ST_CP_PIN, HIGH);
  
} 
