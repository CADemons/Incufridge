class Temperature{
  public:
  Temperature(decisionpin, pin1, pin2, pin3, pin4, pin5, pin6, pin7, pin8);
  int readDigit(int pins[8]);
  float getTemperature(int digit1, int digit2, int digit3);
  private:
  int mydecisionpin, mypin1, mypin2, mypin3, mypin4, mypin5, mypin6, mypinn7, mypin8;
  float myTemperature;
  int myDigit1, myDigit2, myDigit3;
  int myPins[8];
};

#include "project.h"

Temperature::Temperature(decisionpin, pin1, pin2, pin3, pin4, pin5, pin6, pin7, pin8){
  mydecisionpin = decisionpin;
  mypin1 = pin1;
  mypin2 = pin2;
  mypin3 = pin3;
  mypin4 = pin4;
  mypin5 = pin5;
  mypin6 = pin6;
  mypin7 = pin7;
  mypin8 = pin8;
  mypins[] = {decisionpin, pin1, pin2, pin3, pin4, pin5, pin6, pin7, pin8};
}

int Temperature::readDigit(int pins[8]){
}

float Temperature::getTemperature(int digit1, int digit2, int digit3){
  myTemperature = float(digit1*10) + float(digit2) + digit3*0.1
}

