#ifndef PWM_H
#define PWM_H

enum PwmState{
  PWM_LOW, PWM_HIGH
};

class Pwm{
  public:
  Pwm(int pin, double periodSecs, double percentOn, double percentOff, PwmState state);
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

#endif
