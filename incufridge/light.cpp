#include "project.h"

 int Light::m_Pin = 13;
 PwmState Light::m_PwmState = PWM_LOW;

Light::Light(int pin, PwmState state)
{
  m_Pin = pin;
  m_PwmState = state;
  pinMode(13, OUTPUT);
}

void Light::LightOn(String* commandIn) {
  Serial.println("Light On");
  //digitalWrite(m_Pin, HIGH);
  digitalWrite(13, HIGH);
}

void Light::LightOff(String* commandIn) {
  Serial.println("Light Off");
  digitalWrite(13, LOW);
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
  LightOn(new String);
  delay(rate);
  LightOff(new String);
  delay(rate);
}






