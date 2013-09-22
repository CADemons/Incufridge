/*class Temperature{
  public:
  Temperature(int decisionpin, int pin1, int pin2, int pin3, int pin4, int pin5, int pin6, int pin7, int pin8);
  int readDigit(int pins[8]);
  float getTemperature(int digit1, int digit2, int digit3);
  private:
  int mydecisionpin, mypin1, mypin2, mypin3, mypin4, mypin5, mypin6, mypinn7, mypin8;
  float myTemperature;
  int myDigit1, myDigit2, myDigit3;
  int myPins[8];
};*/

#include "project.h"

Temperature::Temperature(int decisionpin, int pin1, int pin2, int pin3, int pin4, int pin5, int pin6, int pin7, int pin8){
  int mydecisionpin = decisionpin;
  int mypin1 = pin1;
  int mypin2 = pin2;
  int mypin3 = pin3;
  int mypin4 = pin4;
  int mypin5 = pin5;
  int mypin6 = pin6;
  int mypin7 = pin7;
  int mypin8 = pin8;
  int mypins[] = {decisionpin, pin1, pin2, pin3, pin4, pin5, pin6, pin7, pin8};
}

int Temperature::readDigit(int pins[8]){
}

float Temperature::getTemperature(int digit1, int digit2, int digit3){
  myTemperature = float(digit1*10) + float(digit2) + digit3*0.1;
}

