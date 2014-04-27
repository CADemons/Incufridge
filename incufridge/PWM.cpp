#include "project.h"

int Pwm::numPwms = 0;
Pwm* Pwm::pwms[20];

Pwm::Pwm(int pin, float periodSecs, float percentOn,
    float percentOff, PwmState state) {
  m_myPin = pin;
  m_myPeriodSecs = periodSecs;
  Serial.println(m_myPeriodSecs);
  Serial.println();
  m_myPercentOn = percentOn;
  m_myPercentOff = percentOff;
  m_myStartState = state;
  m_time = Time();
  pinMode(m_myPin, OUTPUT);
  pwms[numPwms] = this;
  numPwms++;
  m_active = true;
}

void Pwm::PwmCommand(String* args) {
  Serial.println("PWM:");
  PwmState state;
  if(args[4].equals("PWM_HIGH")) {
    state = PWM_HIGH;
  } else {
    state = PWM_LOW;
  }
  char arg0[10], arg1[10], arg2[10], arg3[10];
  args[0].toCharArray(arg0, 10);
  args[1].toCharArray(arg1, 10);
  args[2].toCharArray(arg2, 10);
  args[3].toCharArray(arg3, 10);
  Serial.println(atoi(arg0));
  Serial.println(atof(arg1));
  Serial.println(atof(arg2));
  Serial.println(atof(arg3));
  Serial.println(state);
  Serial.println();
  Pwm(atoi(arg0), atof(arg1), atof(arg2), atof(arg3), state);
}

void Pwm::updateAll() {
  for(int i=0; i<numPwms; i++) {
    pwms[i] -> Update();
  }
}

void Pwm::Start() {
  pinMode(m_myPin, OUTPUT);
  digitalWrite(m_myPin, m_myStartState);
  m_currentState = m_myStartState;
  ComputeTransitions();
}

void Pwm::ComputeTransitions() {
  //startTime = getTimeInMinutes();
  m_startTime = (float)m_time.getTimeInSeconds();
  Serial.println(m_startTime);
  Serial.println(m_myPeriodSecs);
  m_firstTransitionTime = m_startTime + (m_myPercentOff * m_myPeriodSecs);
  m_secondTransitionTime = m_startTime + m_myPeriodSecs;
  Serial.println(m_firstTransitionTime);
  Serial.println(m_secondTransitionTime);
  m_foundFirst = true;
}

void Pwm::Stop() {
  m_currentState = m_myStartState;
  ChangePolarity();
  m_active = false;
  Serial.println("Stopped");  
}


void Pwm::ChangePolarity() {
  if(m_currentState == PWM_LOW){
    m_currentState = PWM_HIGH;
  } else {
    m_currentState = PWM_LOW;
  }
  digitalWrite(m_myPin, m_currentState);
  Serial.println(m_currentState); 
}

//Run in loop
void Pwm::Update() {
  if(m_active) {
   m_currentTime = m_time.getTimeInSeconds();
   //If between transitions
   if(m_currentTime < m_secondTransitionTime && m_currentTime >= m_firstTransitionTime){
     if(m_foundFirst) {
       ChangePolarity();
       m_foundFirst = false;
       Serial.println("changed once");
     }
   } else if (m_currentTime >= m_secondTransitionTime) {
     ChangePolarity();
     ComputeTransitions();
     Serial.println("changed twice");
   }
 }
}
