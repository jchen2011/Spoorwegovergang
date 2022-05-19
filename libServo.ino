#include <Servo.h>

const int SERVOPIN = 6;
const int SERVO_INTERVAL = 80;

int servoMinimum = 0;
int servoMaximum = 90;
int positie = 0;
unsigned long servoPreviousMillis;

int richting = 1; 
Servo servo;  

void servoSetup() {
  servo.write(servoMinimum);
  servoPreviousMillis = 0 - SERVO_INTERVAL;
  servo.attach(SERVOPIN);
  slagboomTeller = 0;
}

void servoOpen() {
  if (millis() >= servoPreviousMillis + SERVO_INTERVAL) {
    servoPreviousMillis = millis();
    if (positie <= servoMaximum) {
        servo.write(positie + richting);
        updateServoPositie();
      }
  }
}

void servoSluiten() {
  if (millis() >= servoPreviousMillis + SERVO_INTERVAL) {
    servoPreviousMillis = millis();
    if (positie >= servoMinimum) {
        servo.write(positie - richting);
        updateServoPositie();
      }
  }
}

void updateServoPositie() {
  positie = servo.read();
}

boolean posIsMaximum() {
  return positie == getServoMaximum();
}

boolean posIsMinimum() {
  return positie == getServoMinimum();
}

int getServoMinimum() {
  return servoMinimum;
}

int getServoMaximum() {
  return servoMaximum;
} 
