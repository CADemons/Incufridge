//**************************************************************************
//
//				COPYRIGHT NOTICE
//			Copyright 2013 CONCORD ACADEMY
//		This program is the property of CONCORD ACADEMY
//		Any unauthorized use or duplication is prohibited
//
//**************************************************************************
//
//  Title		Fan class
//  Filename		fan.cpp
//  Originator  	Kiyun Kim 
//  Archive Location	https://github.com/CADemons/Incufridge/blob/master/incufridge/fan.cpp
//  Version		-
//  Version		-
//
//  Overview		Provides ability to turn fan on and off
//
//**************************************************************************

#include "project.h"

/* Constructor */
Fan::Fan(int pin, PwmState state) {
  m_pin = pin;
  m_state = state;
}

/* Turn the fan on. */
void Fan::FanOn(String* commandIn) {
  Serial.println("Fan On");
}

/* Turn the fan off. */
void Fan::FanOff(String* commandIn) {
  Serial.println("Fan Off");
}

/* Sets the speed of the fan. */
void Fan::FanSpeed() {
  
}

//**************************************************************************
//
//  REVISION HISTORY:
//
//
//
//**************************************************************************
