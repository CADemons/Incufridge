//**************************************************************************
//
//				COPYRIGHT NOTICE
//			Copyright 2013 CONCORD ACADEMY
//		This program is the property of CONCORD ACADEMY
//		Any unauthorized use or duplication is prohibited
//
//**************************************************************************
//
//  Title		Button Implementation
//  Filename		button.cpp
//  Originator  	Kiyun Kim  
//  Archive Location	https://github.com/CADemons/Incufridge/blob/master/incufridge/button.cpp
//  Version		-
//
//  Overview		Allows user to press and release a button. 
//
//**************************************************************************

#include "project.h"

/* Constructor */
Button::Button(const int Pin, int msPressTime, int PressLevel) { 
  m_Pin = Pin;
  m_PressLevel = PressLevel;
  if(m_PressLevel == c_LEVEL_HIGH) {
    m_ReleaseLevel = c_LEVEL_LOW;
  } else {
    m_ReleaseLevel = c_LEVEL_HIGH;
    m_PressLevel = c_LEVEL_LOW;
  }
}


/* This method initializes the pin associated with the button as an output. */
void Button::Initialize(){
  pinMode(m_Pin, OUTPUT);
}


/* This method will press a button until a function that releases
 the button is called. It will not block other functions.*/
void Button::Press(){
  if(IsUp()){
    digitalWrite(m_Pin, m_PressLevel); 
  } 
}


/* This method will press a button and hold for a given number of
 seconds (number of seconds must exceed 2.2 seconds). It will block 
 all other functions.*/
void Button::HoldFor(int sHoldTime){ 
  digitalWrite(m_Pin, m_PressLevel);
  delay(sHoldTime);
  digitalWrite(m_Pin, m_ReleaseLevel);
}


/* This method releases a pressed button. It is paired with the Hold
 method. */
void Button::Release(){
  if(IsDown()){
    digitalWrite(m_Pin, m_ReleaseLevel);
  }
}


/* This method checks to see if a given pin is in the unpressed state (LOW).*/ 
boolean Button::IsUp(){
  if(digitalRead(m_Pin) == m_ReleaseLevel){
    return true;
  }
  else{
    return false;
  }
}


/* This method checks to see if a given pin is in the state designated as the 'pressed' state (HIGH). */
boolean Button::IsDown(){
  if(digitalRead(m_Pin) == m_PressLevel){
    return true;
  }
  else{
    return false;
  }
}

//**************************************************************************
//
//  REVISION HISTORY:
//
//
//
//**************************************************************************
