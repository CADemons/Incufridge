#include "project.h"
const int ButtonHoldTime = 250;
Button tempminus(TemperatureMinusPin, ButtonHoldTime);

 Pwm myPwm = Pwm(3, 5, 0.8, 0.2, PWM_LOW);
void setup(){
  pinMode(3, OUTPUT);
  myPwm.Start();
  Serial.begin(9600);
  

}
void loop(){
  myPwm.Update();
 // digitalWrite(3, HIGH);
  //delay(1000);
 // digitalWrite(3, LOW);
  //delay(1000);
}

