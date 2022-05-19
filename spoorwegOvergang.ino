void setup() {
  buttonSetup();
  buzzerSetup();
  displaySetup();
  ledControlSetup();
  serialSetup(9600);
  servoSetup();
  setupShiftRegister();
  spoorwegOvergang_Setup();
}

void loop() {
  spoorwegOvergang_Loop(); 
  buttonLoop();
  controleerInput();
}
