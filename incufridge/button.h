class Button{
  public: 
  Button(int pin, int level = HIGH);
  void Press();
  void HoldUntilTime(int holdtime);
  void HoldUntilTemp(String temperature);
  void Release();
  private:
  int myPin;
  int pressLevel;
  int releaseLevel;
//  void myPress(int holdtime);
};
