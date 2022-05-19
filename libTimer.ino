unsigned long timerSet(unsigned long interval) {
  return millis() + interval;
}

boolean timerIsPassed(unsigned long timer, unsigned long interval) 
{
  unsigned long currentMillis  = millis();
  if (currentMillis - timer >= interval) {
    return true;
  }
  
  return false;
}
