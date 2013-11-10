#ifndef FAN_H
#define FAN_H

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

#endif
