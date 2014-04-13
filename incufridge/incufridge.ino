#include "project.h"

//Change display mode without changing temperature
const int ButtonHoldTime = 2200;
//Button light(SimpleLight, ButtonHoldTime, 1);
//Pwm myPwm = Pwm(13, 20, 0.8, 0.2, PWM_LOW);
CommandProcessor processor (';',60,0);
boolean recieving=false;
int temps[12];

SevenSegments Display = { 
  c_ReadDigitPin37,  c_ReadDigitPin36,  c_ReadDigitPin35, 
  c_ReadDigitPin34, c_ReadDigitPin33,  c_ReadDigitPin32,  
  c_ReadDigitPin31,  c_ReadDigitPin30};

ConversionPattern ConversionPatternTens[10] = {
{"11001111", "0"}, {"00000110", "1"}, {"10101011", "2"}, {"00101111", "3"}, 
{"01100110", "4"}, {"01101101", "5"}, {"11101101", "6"}, {"00000111", "7"},
{"11101111", "8"}, {"01100111", "9"}};

  
ConversionPattern ConversionPatternOnes[10] = {
{"11011111", "0."}, {"00010110", "1."}, {"10111011", "2."}, {"00111111", "3."}, 
{"01110110", "4."}, {"01111101", "5."}, {"11111101", "6."}, {"00010111", "7."},
{"11111111", "8."}, {"01110111", "9."}};
  
ConversionPattern ConversionPatternDecimals[10] = {
 {"11001111", "0"}, {"00000110", "1"}, {"10101011", "2"}, {"00101111", "3"}, 
{"01100110", "4"}, {"01101101", "5"}, {"11101101", "6"}, {"00000111", "7"},
{"11101111", "8"}, {"01100111", "9"}};



LEDReader Reader = LEDReader(Display, c_Digit1TransitionPin, c_Digit2TransitionPin, 
c_Digit3TransitionPin, ConversionPatternTens, ConversionPatternOnes, ConversionPatternDecimals);

int PreviousTime, CurrentTime, TimeElapsed;
boolean EnoughTimeElapsed = false;



void setup() {
//  pinMode(3, OUTPUT);
//  myPwm.Start();
  Serial.begin(9600);
  
  Light m_Light(c_SimpleLight);
  
  processor.AddCommand(&go,"GO");
  processor.AddCommand(&Pwm::PwmCommand,"PWM");
  processor.AddCommand(&Fan::FanOn, "FAN_ON");
  processor.AddCommand(&Fan::FanOff, "FAN_OFF");
  processor.AddCommand(&Light::LightOn, "LIGHT_ON");
  processor.AddCommand(&Light::LightOff, "LIGHT_OFF");
  processor.AddCommand(&ReadDisplay, "READ_DISPLAY");
  processor.AddCommand(&PressButton, "PRESS_BUTTON");
  processor.AddCommand(&SetTemp, "SET_TEMP");
  
//  pinMode(SimpleLight, OUTPUT);
  Reader.Initialize();
  PreviousTime = 0;
}
void loop() {


  /*CurrentTime = millis();
  TimeElapsed = CurrentTime - PreviousTime;
  if(TimeElapsed > 5000){
    EnoughTimeElapsed = true;
  }
  if(EnoughTimeElapsed){
    Serial.println(Reader.ShowDisplay());
    EnoughTimeElapsed = false;
    PreviousTime = CurrentTime;
  }*/
  
  
//  light.Press();
  //Pwm::updateAll();
 // digitalWrite(3, HIGH);
 if(!recieving){
  Serial.println('A');
    delay(1000);
  }
 // digitalWrite(3, LOW);
}

void serialEvent() {
 if(!recieving){
  int checks = 0;
  char inbytes[30];
  recieving = true;
  Serial.flush();
  char readChar = Serial.read();
  if(readChar == '~'){
    delay(2000);
    Serial.readBytesUntil('D',inbytes,30);
    for(int a = 0; a != 12; a++) {
      temps[a] = inbytes[a];
      checks += temps[a];
    }
    Serial.println(checks);
    Serial.println('R');
  } else {
    Serial.println("Processing command");
     delay(100);
     int count = Serial.readBytesUntil('\0', inbytes, 30);
     processor.ProcessCharacter(readChar);
     //Serial.print(readChar);
     for(int i = 0; i < count; i++) {
       //Serial.print(inbytes[i]);
       processor.ProcessCharacter(inbytes[i]);
     }
     //Serial.println();
  }
  recieving=false;
 }
}

void go(String* args) {
  Serial.println("gone");
  for(int i = 0; i < 10; i++) {
    if(!args[i].equals("")) {
     Serial.println(args[i]);
    }
  }
}

void ReadDisplay(String* args) {
  Serial.println(Reader.ShowDisplay());
}

void PressButton(String* args) {
  char arg0[10];
  char arg1[10];
  args[0].toCharArray(arg0, 10);
  args[1].toCharArray(arg1, 10);
  int pin = atoi(arg0);
  int hold = atoi(arg1);
  PressButton(pin, hold);
}

void PressButton(int pin, int time) {
  Serial.println(time);
  Button button(pin, time, c_LEVEL_LOW);
  button.Initialize();
  button.HoldFor(time);
}

void SetTemp(String* args) {
  char arg0[10];
  args[0].toCharArray(arg0, 10);
  float target = atof(arg0);
  Button button(44, 0, c_LEVEL_LOW);
  button.Initialize();
  button.HoldFor(ButtonHoldTime);
  if(target < GetDisplayFloat()) {
    delay(200);
    Button button(44, 0, c_LEVEL_LOW);
    button.Initialize();
    button.HoldFor(ButtonHoldTime);
    while(target < GetDisplayFloat()) {
      button.HoldFor(500);
      delay(500);
    }
    button.Release();
  } else {
    delay(200);
    Button button(45, 0, c_LEVEL_LOW);
    button.Initialize();
    button.HoldFor(ButtonHoldTime);
    while(target > GetDisplayFloat()) {
      button.HoldFor(500);
      delay(500);
    }
    button.Release();
  }
}

float GetDisplayFloat() {
  char buf[10];
  Reader.ShowDisplay().toCharArray(buf, 10);
  return atof(buf);
}
/* for integration with GUI
#include "project.h"
const int ButtonHoldTime = 250;
int temps[12];
boolean recieving=false;
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
  if(!recieving){
  Serial.println('A');
  }
 // digitalWrite(3, HIGH);
  //delay(1000);
 // digitalWrite(3, LOW);
  //delay(1000);
}

//Do not rename this function!
void serialEvent(){
  int checks=0;
  char inbytes[30];
  recieving=true;
  Serial.flush();
  if(Serial.read() == 'B'){
    delay(2000);
    Serial.readBytesUntil('D',inbytes,30);
    for(int a=0; a!=12; a++){
      temps[a] = inbytes[a];
      checks += temps[a];
    }
    Serial.println(checks);
    Serial.println('R');
    recieving=false;
  }
}*/
