#ifndef LIGHT_H
#define LIGHT_H

class Light{
  public:
    Light(int pin, PwmState state = PWM_LOW);
    static void LightOff(String* commandIn);
    static void LightOn(String* commandIn);
    void DimToLevel(int level);
    void LightFlash(int rate);
    void DimOverTime(int startLevel, int endLevel);
  private:
    static int m_Pin;
    static PwmState m_PwmState;
};

#endif
