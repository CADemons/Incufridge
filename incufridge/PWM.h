enum PwmState{
  PWM_LOW, PWM_HIGH
};

#include "time.h"
class Pwm{
  public:
  Pwm(int pin, double periodSecs, double percentOn, double percentOff, PwmState state);
  void Start();
  void Stop();
  void Update();
  void ComputeTransitions();
  private:
  void ChangePolarity();
  int m_myPin;
  double m_myPeriodSecs;
  double m_myPercentOn;
  double m_myPercentOff;
  PwmState m_myStartState;
  int m_startTime;
  int m_firstTransitionTime;
  int m_secondTransitionTime;
  int m_currentTime;
  PwmState m_currentState;
  boolean m_foundFirst;
  Time m_time;
};
