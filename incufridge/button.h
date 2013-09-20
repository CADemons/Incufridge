class Button{
  public: 
  Button(int pin, int holdtime, int level = HIGH);
  void Press();
  void Hold(int holdtime);
  private:
  int myPin;
  int myHoldTime;
  int pressLevel;
  int releaseLevel;
  void myPress(int holdtime);
};

