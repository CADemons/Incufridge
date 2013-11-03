#include "project.h"

Pwm::Pwm(int pin, int period, double percentOn, double percentOff, PwmState state)
{
  m_myPin = pin;
  m_myPeriod = period; // in minutes
  m_myPercentOn = percentOn;
  m_myPercentOff = percentOff;
  m_myStartState = state;
}

void Pwm::Start(){
  pinMode(m_myPin, OUTPUT);
  digitalWrite(m_myPin, m_myStartState);
  m_currentState = m_myStartState;
  ComputeTransitions();
}

void Pwm::ComputeTransitions(){
  //startTime = getTimeInMinutes();
  m_startTime = getTimeInSeconds();
  m_firstTransitionTime = addTime(m_startTime, (m_myPercentOff*m_myPeriod*60));
  m_secondTransitionTime = addTime(m_startTime, m_myPeriod*60);
  m_foundFirst = true;
}

void Pwm::Stop(){
  m_currentState = m_myStartState;
  ChangePolarity();  
}


void Pwm::ChangePolarity(){
  if(m_currentState == PWM_LOW){
    m_currentState = PWM_HIGH;
  }
  else{
    m_currentState = PWM_LOW;
  }  
}

void Pwm::Update(){
   m_currentTime = millis();
   if(m_currentTime < m_secondTransitionTime && m_currentTime >= m_firstTransitionTime){
     if(m_foundFirst){
     m_ChangePolarity();
     m_foundFirst = false;
     Serial.println("changed once");
     }
   }
   else if(m_currentTime >= m_secondTransitionTime){
     ChangePolarity();
     ComputeTransitions();
     Serial.println("changed twice");
   }
}


