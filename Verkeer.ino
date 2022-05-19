const int NOORD_ROOD_PIN = 13;
const int NOORD_GEEL_PIN = 12;
const int NOORD_GROEN_PIN = 11;

const int ZUID_ROOD_PIN = 5;
const int ZUID_GEEL_PIN = 4;
const int ZUID_GROEN_PIN = 3;

const int GEEL_KNIPPEREN_INTERVAL = 1000;

void verkeerslichtNoordRoodOn() {
  digitalWrite(NOORD_ROOD_PIN, HIGH);
}

void verkeerslichtNoordRoodOff() {
  digitalWrite(NOORD_ROOD_PIN, LOW);
}

void verkeerslichtNoordGeelOn() {
  digitalWrite(NOORD_GEEL_PIN, HIGH);
}

void verkeerslichtNoordGeelOff() {
  digitalWrite(NOORD_GEEL_PIN, LOW);
}

void verkeerslichtNoordGroenOn() {
  digitalWrite(NOORD_GROEN_PIN, HIGH);
}


void verkeerslichtNoordGroenOff() {
  digitalWrite(NOORD_GROEN_PIN, LOW);
}


void verkeerslichtZuidRoodOn() {
  digitalWrite(ZUID_ROOD_PIN, HIGH);
}

void verkeerslichtZuidRoodOff() {
  digitalWrite(ZUID_ROOD_PIN, LOW);
}

void verkeerslichtZuidGeelOn() {
  digitalWrite(ZUID_GEEL_PIN, HIGH);
}


void verkeerslichtZuidGeelOff() {
  digitalWrite(ZUID_GEEL_PIN, LOW);
}

void verkeerslichtZuidGroenOn() {
  digitalWrite(ZUID_GROEN_PIN, HIGH);
}


void verkeerslichtZuidGroenOff() {
  digitalWrite(ZUID_GROEN_PIN, LOW);
}

void verkeerslichtNoordEnZuidGeelKnipperen() {
  ledBlink(NOORD_GEEL_PIN, ZUID_GEEL_PIN, GEEL_KNIPPEREN_INTERVAL);
}
