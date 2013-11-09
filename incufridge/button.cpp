#include "project.h"

Button::Button(int pin, int level)
{ 
  myPin = pin;
  pressLevel = level;
  if(pressLevel == HIGH){
    releaseLevel = LOW;
  }
  else{
    releaseLevel = HIGH;
  }
}

void Button::HoldUntilTime(int holdtime){ // at least 2.5 seconds
  digitalWrite(myPin, pressLevel);
  delay(holdtime);
  digitalWrite(myPin, releaseLevel);
}

void Button::HoldUntilTemp(String temperature){
  digitalWrite(myPin, pressLevel);
  String temp = 0;
  while(!temp.equals(temperature)){
    //temp = readDisplay();
  }
}
  
//void Button::myPress(int holdtime)
//{
//  digitalWrite(myPin, pressLevel);
//  delay(holdtime);
//  digitalWrite(myPin, releaseLevel);
//  delay(holdtime);
//}
//void Button::Press()
//{
//  myPress(myHoldTime);
//}
//void Button::Hold(int holdtime)
//{
//  myPress(holdtime);
//}
