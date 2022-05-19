// --- States -----------
const int SPOORWEG_STATE_IDLE = 1;
const int SPOORWEG_STATE_OVERSTEKEN_ZUID = 2;
const int SPOORWEG_STATE_WAARSCHUWING_ZUID = 3;
const int SPOORWEG_STATE_OVERSTEKEN_NOORD = 4;
const int SPOORWEG_STATE_WAARSCHUWING_NOORD = 5;
const int SPOORWEG_STATE_SLUITEN = 6;
const int SPOORWEG_STATE_PASSEREN = 7;
const int SPOORWEG_STATE_OPENEN = 8;
const int SPOORWEG_STATE_VRIJGEVEN = 9;

// Current state
int spoorwegState;

// Timer variables
const int SPOORWEG_OVERSTEKEN_NOORD_INTERVAL = 4000;
const int SPOORWEG_WAARSCHUWING_NOORD_INTERVAL = 4000; // NS
const int SPOORWEG_IDLE_INTERVAL = 3000;
const int SPOORWEG_OVERSTEKEN_ZUID_INTERVAL = 4000; //NS
const int SPOORWEG_WAARSCHUWING_ZUID_INTERVAL = 4000;
unsigned long previousMillis;

const int BUZZER_FREQUENTIE = 1000;
const int BUZZER_INTERVAL = 1000;

void spoorwegOvergang_Setup() {
  previousMillis = 0;
  spoorwegState = SPOORWEG_STATE_IDLE;
  spoorweg_Idle_Entry();
}

void spoorwegOvergang_Loop() {
  switch (spoorwegState) {
    case SPOORWEG_STATE_IDLE:
      spoorweg_Idle_Do();
      if (treinGedetecteerd()) {
        spoorweg_Idle_Exit();
        spoorwegState = SPOORWEG_STATE_SLUITEN;
        spoorweg_Sluiten_Entry();
      } else if (ontruimingstijdVerlopen(previousMillis, SPOORWEG_IDLE_INTERVAL)) {
        if (isClicked(N))  {
          spoorweg_Idle_Exit();
          spoorwegState = SPOORWEG_STATE_OVERSTEKEN_NOORD;
          spoorweg_Oversteken_Noord_Entry();
        } else if (isClicked(Z)) {
          spoorweg_Idle_Exit();
          spoorwegState = SPOORWEG_STATE_OVERSTEKEN_ZUID;
          spoorweg_Oversteken_Zuid_Entry();
        }
      }
      break;

    case SPOORWEG_STATE_OVERSTEKEN_ZUID:
        spoorweg_Oversteken_Zuid_Do();
        if (treinGedetecteerdOversteken() || timerIsPassed(previousMillis, SPOORWEG_OVERSTEKEN_ZUID_INTERVAL)) {
        spoorweg_Oversteken_Zuid_Exit();
          spoorwegState = SPOORWEG_STATE_WAARSCHUWING_ZUID;
          spoorweg_Waarschuwing_Zuid_Entry();
        }
      break;
     

    case SPOORWEG_STATE_WAARSCHUWING_ZUID:
        spoorweg_Waarschuwing_Zuid_Do();
        if (timerIsPassed(previousMillis, SPOORWEG_WAARSCHUWING_ZUID_INTERVAL)) {
        spoorweg_Waarschuwing_Zuid_Exit();
          spoorwegState = SPOORWEG_STATE_IDLE;
          spoorweg_Idle_Entry();
        }
      break;

    case SPOORWEG_STATE_OVERSTEKEN_NOORD:
        spoorweg_Oversteken_Noord_Do();
        if (treinGedetecteerdOversteken() || timerIsPassed(previousMillis, SPOORWEG_OVERSTEKEN_NOORD_INTERVAL)) {
        spoorweg_Oversteken_Noord_Exit();
          spoorwegState = SPOORWEG_STATE_WAARSCHUWING_NOORD;
          spoorweg_Waarschuwing_Noord_Entry();
        }
      break;

    case SPOORWEG_STATE_WAARSCHUWING_NOORD:
        spoorweg_Waarschuwing_Noord_Do();
        if (timerIsPassed(previousMillis, SPOORWEG_WAARSCHUWING_NOORD_INTERVAL)) {
        spoorweg_Waarschuwing_Noord_Exit();
          spoorwegState = SPOORWEG_STATE_IDLE;
          spoorweg_Idle_Entry();
        }
      break;


    case SPOORWEG_STATE_SLUITEN:
        spoorweg_Sluiten_Do();
        if (slagboomGesloten()) {
        spoorweg_Sluiten_Exit();
          spoorwegState = SPOORWEG_STATE_PASSEREN;
          spoorweg_Passeren_Entry();
        }
      break;

    case SPOORWEG_STATE_PASSEREN:
        spoorweg_Passeren_Do();
        if (treinGepasseerd()) {
        spoorweg_Passeren_Exit();
          spoorwegState = SPOORWEG_STATE_OPENEN;
          spoorweg_Openen_Entry();
        }
      break;

    case SPOORWEG_STATE_OPENEN:
        spoorweg_Openen_Do();
        if (slagboomGeopend()) {
        spoorweg_Openen_Exit();
          spoorwegState = SPOORWEG_STATE_VRIJGEVEN;
          spoorweg_Vrijgeven_Entry();
        }
      break;

    case SPOORWEG_STATE_VRIJGEVEN:
        spoorweg_Vrijgeven_Do();
        if (vrijGegeven()) {
        spoorweg_Vrijgeven_Exit();
          spoorwegState = SPOORWEG_STATE_IDLE;
          spoorweg_Idle_Entry();
        }
      break;
  }
}

// --- SPOORWEG_STATE_IDLE  -----------
void spoorweg_Idle_Entry() {
  Serial.println("State: IDLE");
  previousMillis = millis();
  verkeerslichtNoordRoodOn();
  verkeerslichtZuidRoodOn();
//  Serial.println("WEST: ");
//  Serial.print(button_West_Click);
//  Serial.println("OOST: ");
//  Serial.print(button_Oost_Click);
}

void spoorweg_Idle_Do() {
}

void spoorweg_Idle_Exit() {

}

// --- SPOORWEG_STATE_OVERSTEKEN_NOORD  -----------
void spoorweg_Oversteken_Noord_Entry() {
  Serial.println("State: OVERSTEKEN NOORD");
  previousMillis = millis();
  verkeerslichtNoordGroenOn();
  verkeerslichtNoordRoodOff();
}

void spoorweg_Oversteken_Noord_Do() {

}

void spoorweg_Oversteken_Noord_Exit() {
  verkeerslichtNoordGroenOff();
}

// --- SPOORWEG_STATE_WAARSCHUWING_NOORD  -----------
void spoorweg_Waarschuwing_Noord_Entry() {
  Serial.println("State: WAARSCHUWING NOORD");
  previousMillis = millis();
  verkeerslichtNoordGeelOn();
}

void spoorweg_Waarschuwing_Noord_Do() {

}

void spoorweg_Waarschuwing_Noord_Exit() {
  verkeerslichtNoordGeelOff();
}

// --- SPOORWEG_STATE_OVERSTEKEN_ZUID  -----------
void spoorweg_Oversteken_Zuid_Entry() {
  Serial.println("State: OVERSTEKEN ZUID");
  previousMillis = millis();
  verkeerslichtZuidGroenOn();
  verkeerslichtZuidRoodOff();
}

void spoorweg_Oversteken_Zuid_Do() {

}

void spoorweg_Oversteken_Zuid_Exit() {
  verkeerslichtZuidGroenOff();
}

// --- SPOORWEG_STATE_WAARSCHUWING_ZUID  -----------
void spoorweg_Waarschuwing_Zuid_Entry() {
  Serial.println("State: WAARSCHUWING ZUID");
  previousMillis = millis();
  verkeerslichtZuidGeelOn();
}

void spoorweg_Waarschuwing_Zuid_Do() {

}

void spoorweg_Waarschuwing_Zuid_Exit() {
  verkeerslichtZuidGeelOff();
}

// --- SPOORWEG_STATE_SLUITEN  -----------
void spoorweg_Sluiten_Entry() {
  Serial.println("State: SLUITEN");
  verkeerslichtNoordRoodOn();
  verkeerslichtZuidRoodOn();
}

void spoorweg_Sluiten_Do() {
  verkeerslichtNoordEnZuidGeelKnipperen();
  buzzerBeep(BUZZER_FREQUENTIE, BUZZER_INTERVAL);
  servoOpen();
}

void spoorweg_Sluiten_Exit() {
  verkeerslichtNoordGeelOff();
  verkeerslichtZuidGeelOff();
  buzzerOff();
}

// --- SPOORWEG_STATE_PASSEREN  -----------
void spoorweg_Passeren_Entry() {
  Serial.println("State: PASSEREN");
}

void spoorweg_Passeren_Do() {
  verkeerslichtNoordEnZuidGeelKnipperen();
}

void spoorweg_Passeren_Exit() {

}

// --- SPOORWEG_STATE_OPENEN  -----------
void spoorweg_Openen_Entry() {
  Serial.println("State: OPENEN");
  slagboomTellerVerhogen();
}

void spoorweg_Openen_Do() {
  verkeerslichtNoordEnZuidGeelKnipperen();
  servoSluiten();
  buzzerBeep(BUZZER_FREQUENTIE, BUZZER_INTERVAL);
}

void spoorweg_Openen_Exit() {
  buzzerOff();
}

// --- SPOORWEG_STATE_VRIJGEVEN  -----------
void spoorweg_Vrijgeven_Entry() {
  Serial.println("State: VRIJGEGEVEN");
  Serial.println((String)"De slagboom is nu " + slagboomTeller + " keer open en dicht gegaan");
  displayNumber(5);
}

void spoorweg_Vrijgeven_Do() {
  //  buzzerBeep(1000, 2000);
  verkeerslichtNoordEnZuidGeelKnipperen();
}

void spoorweg_Vrijgeven_Exit() {
  verkeerslichtNoordGeelOff();
  verkeerslichtZuidGeelOff();
  buzzerOff();
}
