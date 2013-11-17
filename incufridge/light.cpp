#include "project.h"

Light::Light(int pin, PwmState state)
{
  myPin = pin;
  myPwmState = state;
  pinMode(pin, OUTPUT);
}

void Light::LightOn(){
  digitalWrite(myPin, HIGH);
};

void Light::LightOff() {
  digitalWrite(myPin, LOW);
}

void Light::DimToLevel(int level) {
  if (level > 0 && level < 255) {
    analogWrite(myPin, level);
  } else {
    Serial.println("Level must be between 0 and 255. Level = " + level);
  }
}

void Light::DimOverTime(int startLevel, int endLevel) {
  DimToLevel(startLevel);
  
  if (startLevel < endLevel) {
    for (int i = startLevel; i < endLevel; i++) {
      DimToLevel(i);
    } 
  } else {
    for (int i = startLevel; i > endLevel; i--) {
      DimToLevel(i);
    } 
  }
}






