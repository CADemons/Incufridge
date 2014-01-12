#include "project.h"

Light::Light(int pin, PwmState state)
{
  m_Pin = pin;
  m_PwmState = state;
  pinMode(m_Pin, OUTPUT);
}

void Light::LightOn() {
  digitalWrite(m_Pin, HIGH);
};

void Light::LightOff() {
  digitalWrite(m_Pin, LOW);
}

void Light::DimToLevel(int level) {
  if (level > 0 && level < 255) {
    analogWrite(m_Pin, level);
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

void Light::LightFlash(int rate) {
  LightOn();
  delay(rate);
  LightOff();
  delay(rate);
}






