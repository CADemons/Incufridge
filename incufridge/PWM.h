enum PwmState{
  PWM_HIGH, PWM_LOW
};

class Pwm{
  public:
  Pwm(int pin, int period, double percentOn, double percentOff, PwmState state);
  void Start();
  void Stop();
  void Update();
  void ComputeTransitions();
  private:
  void ChangePolarity();
  int myPin;
  double myPeriod;
  double myPercentOn;
  double myPercentOff;
  PwmState myStartState;
  int startTime;
  int firstTransitionTime;
  int secondTransitionTime;
  int currentTime;
  PwmState currentState;
  boolean foundFirst;
};
