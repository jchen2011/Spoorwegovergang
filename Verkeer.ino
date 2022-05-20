const int NOORD_ROOD_PIN = 13;
const int NOORD_GEEL_PIN = 12;
const int NOORD_GROEN_PIN = 11;

const int ZUID_ROOD_PIN = 5;
const int ZUID_GEEL_PIN = 4;
const int ZUID_GROEN_PIN = 3;

const int GEEL_KNIPPEREN_INTERVAL = 1000;

void verkeerslichtNoordRoodOn() {
  ledOn(NOORD_ROOD_PIN);
}

void verkeerslichtNoordRoodOff() {
  ledOff(NOORD_ROOD_PIN);
}

void verkeerslichtNoordGeelOn() {
  ledOn(NOORD_GEEL_PIN);
}

void verkeerslichtNoordGeelOff() {
  ledOff(NOORD_GEEL_PIN);
}

void verkeerslichtNoordGroenOn() {
  ledOn(NOORD_GROEN_PIN);
}


void verkeerslichtNoordGroenOff() {
  ledOff(NOORD_GROEN_PIN);
}


void verkeerslichtZuidRoodOn() {
  ledOn(ZUID_ROOD_PIN);
}

void verkeerslichtZuidRoodOff() {
  ledOff(ZUID_ROOD_PIN);
}

void verkeerslichtZuidGeelOn() {
  ledOn(ZUID_GEEL_PIN);
}


void verkeerslichtZuidGeelOff() {
  ledOff(ZUID_GEEL_PIN);
}

void verkeerslichtZuidGroenOn() {
  ledOn(ZUID_GROEN_PIN);
}


void verkeerslichtZuidGroenOff() {
  ledOff(ZUID_GROEN_PIN);
}

void verkeerslichtNoordEnZuidGeelKnipperen() {
  ledBlink(NOORD_GEEL_PIN, ZUID_GEEL_PIN, GEEL_KNIPPEREN_INTERVAL);
}
