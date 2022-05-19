const int BUZZER_PIN = 7;
const int BUZZER_FREQUENTIE = 1000;

boolean buzzerStatus;

unsigned long buzzerPreviousMillis;

void buzzerSetup() {
  pinMode(BUZZER_PIN, OUTPUT);
  buzzerPreviousMillis = 0;
  buzzerStatus = false;
}

void buzzerOn(int frequentie) {
  tone(BUZZER_PIN, frequentie);
}

void buzzerOff() {
  noTone(BUZZER_PIN);
}

void buzzerBeep(int frequentie, int interval) {
  unsigned long currentMillis = millis();
  if (currentMillis >=buzzerPreviousMillis + interval) {
    buzzerPreviousMillis = millis();
    if (buzzerStatus) {
      buzzerOn(BUZZER_FREQUENTIE);
    } else {
      buzzerOff();
    }
    buzzerStatus = !buzzerStatus;
  }
} 

void buzzer_Drie_Tikken() {
  //TODO
}
