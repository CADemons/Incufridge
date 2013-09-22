#include "project.h"
const int ButtonHoldTime = 250;
int temps[12];
Button tempminus(TemperatureMinusPin, ButtonHoldTime);

 Pwm myPwm = Pwm(3, 5, 0.8, 0.2, PWM_LOW);
void setup(){
  pinMode(3, OUTPUT);
  myPwm.Start();
  Serial.begin(9600);
  

}
void loop(){
  myPwm.Update();
  delay(1000);
  Serial.println('A');
 // digitalWrite(3, HIGH);
  //delay(1000);
 // digitalWrite(3, LOW);
  //delay(1000);
}

//Do not rename this function!
void serialEvent(){
  char inbytes[30];
  Serial.flush();
  if(Serial.read() == 'B'){
    delay(2000);
    Serial.readBytesUntil('D',inbytes,30);
    for(int a=0; a!=12; a++){
      temps[a] = inbytes[a];
      Serial.println(temps[a]);
    }
    Serial.println('R');
  }
}
