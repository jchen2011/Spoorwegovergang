int slagboomTeller = 0;

boolean slagboomGesloten() {
  return posIsMaximum();
}

boolean slagboomGeopend() {
  return posIsMinimum();
}

void slagboomTellerVerhogen() {
  slagboomTeller++;
}

void resetSlagboomTeller() {
  slagboomTeller = 0;
  Serial.println("Slagboom teller reset");
}

int getSlagboomTeller() {
  return slagboomTeller;
}
