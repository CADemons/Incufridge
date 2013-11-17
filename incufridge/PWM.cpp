#include "project.h"

int Pwm::numPwms = 0;
Pwm* Pwm::pwms[20];

Pwm::Pwm(int pin, double periodSecs, double percentOn, double percentOff, PwmState state)
{
  m_myPin = pin;
  m_myPeriodSecs = periodSecs;
  m_myPercentOn = percentOn;
  m_myPercentOff = percentOff;
  m_myStartState = state;
  m_time = Time();
  pinMode(m_myPin, OUTPUT);
  pwms[numPwms] = this;
  numPwms++;
}

void Pwm::PwmCommand(String* args){
  PwmState state;
  if(args[4].equals("PWM_HIGH")){
    state = PWM_LOW;
  }else{
    state = PWM_HIGH;
  }
  char arg0[10],arg1[10],arg2[10],arg3[10];
  args[0].toCharArray(arg0,10);
  args[1].toCharArray(arg1,10);
  args[2].toCharArray(arg2,10);
  args[3].toCharArray(arg3,10);
  Pwm(atoi(arg0),atof(arg1),atof(arg2),atof(arg3),state);
}

void Pwm::updateAll(){
  
}

void Pwm::Start(){
  pinMode(m_myPin, OUTPUT);
  digitalWrite(m_myPin, m_myStartState);
  m_currentState = m_myStartState;
  ComputeTransitions();
}

void Pwm::ComputeTransitions(){
  //startTime = getTimeInMinutes();
  m_startTime = m_time.getTimeInSeconds();
  Serial.println(m_startTime);
  m_firstTransitionTime = m_time.addTime(m_startTime, (m_myPercentOff*m_myPeriodSecs));
  m_secondTransitionTime = m_time.addTime(m_startTime, m_myPeriodSecs);
  Serial.println(m_firstTransitionTime);
    Serial.println(m_secondTransitionTime);
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
  digitalWrite(m_myPin, m_currentState);
 Serial.println(m_currentState); 
}

//Run in loop
void Pwm::Update(){
   m_currentTime = m_time.getTimeInSeconds();
   //If between transitions
   if(m_currentTime < m_secondTransitionTime && m_currentTime >= m_firstTransitionTime){
     if(m_foundFirst){
     ChangePolarity();
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


