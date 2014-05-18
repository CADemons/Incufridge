//**************************************************************************
//
//				COPYRIGHT NOTICE
//			Copyright 2013 CONCORD ACADEMY
//		This program is the property of CONCORD ACADEMY
//		Any unauthorized use or duplication is prohibited
//
//**************************************************************************
//
//  Title		PWM Class
//  Filename		PWM.h
//  Originator  	Kiyun Kim  
//  Archive Location	https://github.com/CADemons/Incufridge/blob/master/incufridge/PWM.h
//  Version		-
//
//  Overview		Provides framework for the PWM class, which allows the
//                      user to toggle something on and off over a period of time.
//**************************************************************************

#ifndef PWM_H
#define PWM_H

enum PwmState{
  PWM_LOW, PWM_HIGH
};

class Pwm{
public:
  Pwm(int pin, float periodSecs, float percentOn, float percentOff, PwmState state);
  static void PwmCommand(String* args);
  void Start();
  void Stop();
  void Update();
  void ComputeTransitions();
  static void updateAll();
  static Pwm* pwms[20];
  static int numPwms;
private:
  void ChangePolarity();
  int m_myPin;
  float m_myPeriodSecs;
  float m_myPercentOn;
  float m_myPercentOff;
  PwmState m_myStartState;
  float m_startTime;
  float m_firstTransitionTime;
  float m_secondTransitionTime;
  long m_currentTime;
  PwmState m_currentState;
  boolean m_foundFirst;
  boolean m_active;
  Time m_time;
};

#endif
//**************************************************************************
//
//  REVISION HISTORY:
//
//
//
//**************************************************************************
