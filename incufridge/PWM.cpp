//**************************************************************************
//
//				COPYRIGHT NOTICE
//			Copyright 2013 CONCORD ACADEMY
//		This program is the property of CONCORD ACADEMY
//		Any unauthorized use or duplication is prohibited
//
//**************************************************************************
//
//  Title		PWM
//  Filename		PWM.cpp
//  Originator  	Kiyun Kim  
//  Archive Location	https://github.com/CADemons/Incufridge/blob/master/incufridge/PWM.cpp
//
//  Overview		Runs a PWM (can be used to toggle something on and off
//                      over some period of time).
//**************************************************************************

#include "project.h"

int Pwm::numPwms = 0;
Pwm* Pwm::pwms[20];

/* Constructor */
Pwm::Pwm(int pin, float periodSecs, float percentOn,
float percentOff, PwmState state) {
  m_myPin = pin;
  m_myPeriodSecs = periodSecs;
  m_myPercentOn = percentOn;
  m_myPercentOff = percentOff;
  m_myStartState = state;
  m_time = Time();
  pinMode(m_myPin, OUTPUT);
  m_active = true;
}

/* Translates a String command into the constructor call variables. */
void Pwm::PwmCommand(String* args) {
  Serial.println("PWM:");
  PwmState state;
  if(args[4].equals("PWM_HIGH")) {
    state = PWM_HIGH;
  } 
  else {
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
  Pwm myPwm = Pwm(atoi(arg0), atof(arg1), atof(arg2), atof(arg3), state);
  myPwm.Start();
  pwms[numPwms] = &myPwm;
  numPwms++;
}

/* Updates all PWMs. */
void Pwm::updateAll() {
  for(int i=0; i<numPwms; i++) {
    pwms[i]->Update();
    Serial.println("Updated PWM " + String(i));
  }
}

/* Initializes PWM. */
void Pwm::Start() {
  pinMode(m_myPin, OUTPUT);
  digitalWrite(m_myPin, m_myStartState);
  m_currentState = m_myStartState;
  ComputeTransitions();
}

/* Computes the transition times for the PWM. */
void Pwm::ComputeTransitions() {
  m_startTime = (float)m_time.getTimeInSeconds();
  Serial.println(m_startTime);
  Serial.println(m_myPeriodSecs);
  m_firstTransitionTime = m_startTime + (m_myPercentOff * m_myPeriodSecs);
  m_secondTransitionTime = m_startTime + m_myPeriodSecs;
  Serial.println(m_firstTransitionTime);
  Serial.println(m_secondTransitionTime);
  m_foundFirst = true;
}

/* Stops the PWM. */
void Pwm::Stop() {
  m_currentState = m_myStartState;
  ChangePolarity();
  m_active = false;
  Serial.println("Stopped");  
}

/* Changes the state of the PWM from HIGH to LOW or vice-versa. */
void Pwm::ChangePolarity() {
  if(m_currentState == PWM_LOW){
    m_currentState = PWM_HIGH;
  } 
  else {
    m_currentState = PWM_LOW;
  }
  digitalWrite(m_myPin, m_currentState);
  Serial.println(m_currentState); 
}

/* Updates a PWM--checks for transition points and changes the PWM state. */
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
    } 
    else if (m_currentTime >= m_secondTransitionTime) {
      ChangePolarity();
      ComputeTransitions();
      Serial.println("changed twice");
    }
  }
}
//**************************************************************************
//
//  REVISION HISTORY:
//
//
//
//**************************************************************************
