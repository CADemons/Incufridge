//**************************************************************************
//
//				COPYRIGHT NOTICE
//			Copyright 2013 CONCORD ACADEMY
//		This program is the property of CONCORD ACADEMY
//		Any unauthorized use or duplication is prohibited
//
//**************************************************************************
//
//  Title		Light
//  Filename		light.cpp
//  Originator  	Kiyun Kim  
//  Archive Location	https://github.com/CADemons/Incufridge/blob/master/incufridge/light.cpp
//  Version		-
//
//  Overview		Allows a light to be toggled on and off and to be dimmed.
//                      
//**************************************************************************

#include "project.h"

 int Light::m_Pin = 13;
 PwmState Light::m_PwmState = PWM_LOW;

/* Constructor */
Light::Light(int pin, PwmState state)
{
  m_Pin = pin;
  m_PwmState = state;
  pinMode(40, OUTPUT);
  digitalWrite(40, HIGH);
}

/* Turns on the light. */
void Light::LightOn(String* commandIn) {
  Serial.println("Light On");
  digitalWrite(40, LOW);
  delay(100);
  digitalWrite(40, HIGH);
}
/* Turns the light off. */
void Light::LightOff(String* commandIn) {
  Serial.println("Light Off");
  digitalWrite(40, LOW);
  delay(100);
  digitalWrite(40, HIGH);
}

/* Dims the light to a particular level. */
void Light::DimToLevel(int level) {
  if (level > 0 && level < 255) {
    analogWrite(m_Pin, level);
  } else {
    Serial.println("Level must be between 0 and 255. Level = " + level);
  }
}

/* Dims the light from one level to another over time. */
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

/* Allows the light to blink on and off. */
void Light::LightFlash(int rate) {
  LightOn(new String);
  delay(rate);
  LightOff(new String);
  delay(rate);
}


//**************************************************************************
//
//  REVISION HISTORY:
//
//
//
//**************************************************************************


