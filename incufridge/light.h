class Light{
  public:
  Light(int pin, PwmState state = PWM_LOW);
  void LightOff();
  void LightOn();
  void LightDim(int level);
  void LightFlash(int rate);
  private:
  int myPin;
  int myPwmState;
};
