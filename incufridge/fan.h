class Fan{
  public:
  Fan(int pin, PwmState state);
  void FanOn();
  void FanOff();
  void FanSpeed();
  private:
  int myPin;
  int myState;  
};
