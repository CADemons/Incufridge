#ifndef PWM_H
#define PWM_H

enum PwmState{
  PWM_LOW, PWM_HIGH
};

class Pwm{
  public:
  Pwm();
  Pwm(int pin, float periodSecs, float percentOn, float percentOff, PwmState state);
  static void PwmCommand(String* args);
  void Start();
  void Stop();
  void Update();
  void ComputeTransitions();
  static void updateAll();
  static AList<Pwm> pwms;
  static int numPwms;
  private:
  void ChangePolarity();
  int m_id;
  int m_myPin;
  float m_myPeriodSecs;
  float m_myPercentOn;
  float m_myPercentOff;
  PwmState m_myStartState;
  float m_startTime;
  float m_firstTransitionTime;
  float m_secondTransitionTime;
  int m_currentTime;
  PwmState m_currentState;
  boolean m_foundFirst;
  boolean m_active;
  Time m_time;
};

#endif
