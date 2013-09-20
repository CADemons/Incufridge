#include "project.h"

Pwm::Pwm(int pin, int period, double percentOn, double percentOff, PwmState state)
{
  myPin = pin;
  myPeriod = period; // in minutes
  myPercentOn = percentOn;
  myPercentOff = percentOff;
  myStartState = state;
}

void Pwm::Start(){
  pinMode(myPin, OUTPUT);
  digitalWrite(myPin, myStartState);
  currentState = myStartState;
  ComputeTransitions();
}

void Pwm::ComputeTransitions(){
  //startTime = getTimeInMinutes();
  startTime = getTimeInSeconds();
  firstTransitionTime = addTime(startTime, (myPercentOff*myPeriod*60));
  secondTransitionTime = addTime(startTime, myPeriod*60);
  foundFirst = true;
}

void Pwm::Stop(){
  currentState = myStartState;
  ChangePolarity();  
}


void Pwm::ChangePolarity(){
  if(currentState == PWM_LOW){
    currentState = PWM_HIGH;
  }
  else{
    currentState = PWM_LOW;
  }  
}

void Pwm::Update(){
   currentTime = millis();
   if(currentTime < secondTransitionTime && currentTime >= firstTransitionTime){
     if(foundFirst){
     ChangePolarity();
     foundFirst = false;
     Serial.println("changed once");
     }
   }
   else if(currentTime >= secondTransitionTime){
     ChangePolarity();
     ComputeTransitions();
     Serial.println("changed twice");
   }
}


