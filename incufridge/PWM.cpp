#include "project.h"

Pwm::Pwm(int pin, int periodSecs, double percentOn, double percentOff, PwmState state)
{
  m_myPin = pin;
  m_myPeriodSecs = periodSecs;
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
  m_startTime = time.getTimeInSeconds();
  m_firstTransitionTime = time.addTime(m_startTime, (m_myPercentOff*m_myPeriodSecs));
  m_secondTransitionTime = time.addTime(m_startTime, m_myPeriodSecs);
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

//Run in loop
void Pwm::Update(){
   m_currentTime = time.getTimeInSeconds();
   //If between transitions
   if(m_currentTime < m_secondTransitionTime && m_currentTime >= m_firstTransitionTime){
     if(m_foundFirst){
     m_ChangePolarity();
     m_foundFirst = false;
     Serial.println("changed once");
     }
   }
   //If after transitions
   else if(m_currentTime >= m_secondTransitionTime){
     ChangePolarity();
     ComputeTransitions();
     Serial.println("changed twice");
   }
}


