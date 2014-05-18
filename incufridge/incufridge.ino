//**************************************************************************
//
//				COPYRIGHT NOTICE
//			Copyright 2013 CONCORD ACADEMY
//		This program is the property of CONCORD ACADEMY
//		Any unauthorized use or duplication is prohibited
//
//**************************************************************************
//
//  Title		Incufridge
//  Filename		incufridge.ino
//  Originator  	Kiyun Kim
//  Archive Location	https://github.com/CADemons/Incufridge/blob/master/incufridge/incufridge.ino
//  Version		-
//
//  Overview		Pulls everything together to run the incufridge.
//                      
//**************************************************************************

#include "project.h"

/* ButtonHoldTime is the time to change display mode without changing temperature */
const int ButtonHoldTime = 2200;
Pwm myPwm = Pwm(7, 6, 0.5, 0.5, PWM_LOW);
CommandProcessor processor (';', 60, 0);
boolean recieving = false;
int temps[12];

SevenSegments Display = {
  c_ReadDigitPin37,  c_ReadDigitPin36,  c_ReadDigitPin35,
  c_ReadDigitPin34, c_ReadDigitPin33,  c_ReadDigitPin32,
  c_ReadDigitPin31,  c_ReadDigitPin30
};

ConversionPattern ConversionPatternTens[10] = {
  {"11001111", "0"}
  , {"00000110", "1"}
  , {"10101011", "2"}
  , {"00101111", "3"}
  , {"01100110", "4"}
  , {"01101101", "5"}
  , {"11101101", "6"}
  , {"00000111", "7"}
  , {"11101111", "8"}
  , {"01100111", "9"}
};


ConversionPattern ConversionPatternOnes[10] = {
  {"11011111", "0."}
  , {"00010110", "1."}
  , {"10111011", "2."}
  , {"00111111", "3."}
  , {"01110110", "4."}
  , {"01111101", "5."}
  , {"11111101", "6."}
  , {"00010111", "7."}
  , {"11111111", "8."}
  , {"01110111", "9."}
};

ConversionPattern ConversionPatternDecimals[10] = {
  {"11001111", "0"}
  , {"00000110", "1"}
  , {"10101011", "2"}
  , {"00101111", "3"}
  , {"01100110", "4"}
  , {"01101101", "5"}
  , {"11101101", "6"}
  , {"00000111", "7"}
  , {"11101111", "8"}
  , { "01100111", "9"}
};



LEDReader Reader = LEDReader(Display, c_Digit1TransitionPin, c_Digit2TransitionPin,
c_Digit3TransitionPin, ConversionPatternTens, ConversionPatternOnes, ConversionPatternDecimals);

int PreviousTime, CurrentTime, TimeElapsed;
boolean EnoughTimeElapsed = false;


/* Sets up various functions--PWM characteristics and the LED Display Reader 
 initialized, the Command Processer is given a list of commands, and Pins are set. */
void setup() {
  myPwm.Start();
  Serial.begin(9600);

  Light m_Light(c_SimpleLight);

  processor.AddCommand(&Pwm::PwmCommand, "PWM");
  processor.AddCommand(&Fan::FanOn, "FAN_ON");
  processor.AddCommand(&Fan::FanOff, "FAN_OFF");
  processor.AddCommand(&Light::LightOn, "LIGHT_ON");
  processor.AddCommand(&Light::LightOff, "LIGHT_OFF");
  processor.AddCommand(&ReadDisplay, "READ_DISPLAY");
  processor.AddCommand(&PressButton, "PRESS_BUTTON");
  processor.AddCommand(&SetTemp, "SET_TEMP");

  Reader.Initialize();
  PreviousTime = 0;
}

/* Runs the program. */
void loop() {
  if (!recieving) {
    Serial.println('A');
    delay(1000);
  }
  myPwm.Update();
  delay(100);

}

/* Processes a command input by the user. */
void serialEvent() {
  if (!recieving) {
    int checks = 0;
    char inbytes[30];
    recieving = true;
    Serial.flush();
    char readChar = Serial.read();
    if (readChar == '~') {
      delay(2000);
      Serial.readBytesUntil('D', inbytes, 30);
      for (int a = 0; a != 12; a++) {
        temps[a] = inbytes[a];
        checks += temps[a];
      }
      Serial.println(checks);
      Serial.println('R');
    } 
    else {
      Serial.println("Processing command");
      delay(100);
      int count = Serial.readBytesUntil('\0', inbytes, 30);
      processor.ProcessCharacter(readChar);
      for (int i = 0; i < count; i++) {
        processor.ProcessCharacter(inbytes[i]);
      }
    }
    recieving = false;
  }
}

/* Reads the LED Display as a string. */
void ReadDisplay(String* args) {
  Serial.println(Reader.ShowDisplay());
}

/* Presses a button. */
void PressButton(String* args) {
  char arg0[10];
  char arg1[10];
  args[0].toCharArray(arg0, 10);
  args[1].toCharArray(arg1, 10);
  int pin = atoi(arg0);
  int hold = atoi(arg1);
  PressButton(pin, hold);
}

/* Presses a button for a set amount of time. */
void PressButton(int pin, int time) {
  Serial.println(time);
  Button button(pin, time, c_LEVEL_LOW);
  button.Initialize();
  button.HoldFor(time);
}

/* Sets the target temperature to the user-input temperature. */
void SetTemp(String* args) {
  char arg0[10];
  args[0].toCharArray(arg0, 10);
  float target = atof(arg0);
  target = round(target * 2) / 2;
  Serial.println("Setting temp: " + String(target));
  Button button(44, 0, c_LEVEL_LOW);
  button.Initialize();
  button.HoldFor(ButtonHoldTime);
  while (target != GetDisplayFloat()) {
    if (target < GetDisplayFloat()) {
      delay(200);
      Button button(44, 0, c_LEVEL_LOW);
      button.Initialize();
      while (target < GetDisplayFloat()) {
        button.HoldFor(100);
        delay(100);
      }
      button.Release();
    } 
    else {
      delay(200);
      Button button(45, 0, c_LEVEL_LOW);
      button.Initialize();
      while (target > GetDisplayFloat()) {
        button.HoldFor(100);
        delay(100);
      }
      button.Release();
    }
  }
}

/* Gets the number on the display as a float. */
float GetDisplayFloat() {
  char buf[10];
  Reader.ShowDisplay().toCharArray(buf, 10);
  return atof(buf);
}


//**************************************************************************
//
//  REVISION HISTORY:
//
//
//
//**************************************************************************




