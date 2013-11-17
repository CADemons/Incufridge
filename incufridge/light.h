#ifndef LIGHT_H
#define LIGHT_H

class Light{
  public:
    Light(int pin, PwmState state = PWM_LOW);
    void LightOff();
    void LightOn();
    void DimToLevel(int level);
    void LightFlash(int rate);
    void DimOverTime(int startLevel, int endLevel);
  private:
    int myPin;
    int myPwmState;
};

#endif
