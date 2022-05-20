const int BUZZER_PIN = 7;
const int BUZZER_FREQUENTIE = 1000;

boolean buzzerStatus;

unsigned long buzzerPreviousMillis;
unsigned long buzzerPreviousMillisTikken;
unsigned long buzzerPreviousMillisTikkenFreeze;
int aantalTikken = 1;

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

void buzzer_Drie_Tikken(int interval, int tikkenInterval) {
   if (timerIsPassed(buzzerPreviousMillisTikken, interval)) {
    buzzerPreviousMillisTikken = millis();
    buzzerOff();
    if(aantalTikken <= 0){
      if (timerIsPassed(buzzerPreviousMillisTikkenFreeze, tikkenInterval)) {
        buzzerPreviousMillisTikkenFreeze = millis();
        digitalWrite(BUZZER_PIN, HIGH);
        aantalTikken = 1;
      }
    } else {
      aantalTikken--;
      
      if (digitalRead(BUZZER_PIN) == HIGH) {
        buzzerOff();
      } else {
        digitalWrite(BUZZER_PIN,HIGH);
      }
    }
  }
}
