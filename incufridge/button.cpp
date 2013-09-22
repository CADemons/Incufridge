#include "project.h"

Button::Button(int pin, int holdtime, int level)
{ 

  myPin = pin;
  pinMode(myPin, OUTPUT);
  myHoldTime = holdtime; // at least 2.5 seconds
  pressLevel = level;
  if(pressLevel == HIGH){
    releaseLevel = LOW;
  }
  else{
    releaseLevel = HIGH;
  }
}
void Button::myPress(int holdtime)
{
  digitalWrite(myPin, pressLevel);
  delay(holdtime);
  digitalWrite(myPin, releaseLevel);
  delay(holdtime);
}
void Button::Press()
{
  myPress(myHoldTime);
}
void Button::Hold(int holdtime)
{
  myPress(holdtime);
}
