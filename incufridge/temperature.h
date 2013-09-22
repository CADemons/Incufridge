class Temperature{
  public:
  //Made all pin args ints, not sure what they should be -Linc
  Temperature(int decisionpin, int pin1, int pin2, int pin3, int pin4, int pin5, int pin6, int pin7, int pin8);
  int readDigit(int pins[8]);
  float getTemperature(int digit1, int digit2, int digit3);
  private:
  int mydecisionpin, mypin1, mypin2, mypin3, mypin4, mypin5, mypin6, mypinn7, mypin8;
  float myTemperature;
  int myDigit1, myDigit2, myDigit3;
  int myPins[8];
};
