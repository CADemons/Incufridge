//**************************************************************************
//
//				COPYRIGHT NOTICE
//			Copyright 2013 CONCORD ACADEMY
//		This program is the property of CONCORD ACADEMY
//		Any unauthorized use or duplication is prohibited
//
//**************************************************************************
//
//  Title		Read LED Display
//  Filename		readleddisplay.cpp
//  Originator  	Kiyun Kim  
//  Archive Location	(wherever this is on github)
//
//  Overview		Reads off which LEDs are on at any given point in time
//                      and sends the user a decimal number matching the display.
//**************************************************************************

#include "project.h"


/* digit1, 2, and 3 is the entire byte of data for a number, constructed from 
 the sequence fo read1 to read8. digit1 is the first digit, digit2 the second,
 digit3 the third.
 number1, 2, and 3 are used to convert each digit from its binary state to 
 user-friendly decimal integers. 
 number is the final number, in the form of nn.n
 */
int reading1, reading2, reading3, reading4, reading5, reading6, reading7, reading8;
String digit1, digit2, digit3, number1, number2, number3, number;
String NumberPatterns13[10] = {
  "11001111", "00000110", "10101011", "00101111", "01100110", 
  "01101101", "11101101", "00000111", "11101111", "01100111"};
String NumberPatterns2[10] = {
  "11011111", "00010110", "10111011", "00111111", "01110110", 
  "01111101", "11101101", "00010111", "11111111", "01110111"};
String Numbers13[10] = {
  "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
String Numbers2[10] = {
  "0.", "1.", "2.", "3.", "4.", "5.", "6.", "7.", "8.", "9."};


/* This method returns the state (HIGH or LOW) of a particular transition pin. */
int Listening(int TransitionPin){
  int state = digitalRead(TransitionPin);
  return state;
}


/* This method reads bits from the portion of the LED display designated by
 the transition pin, and converts the bits into a byte, which is a string that
 lists which individual LED lights are on at a given point in time. */
String ReadDigits(int TransitionPin) {
  int reading1 = digitalRead(c_ReadDigitPin37);
  int reading2 = digitalRead(c_ReadDigitPin36);
  int reading3 = digitalRead(c_ReadDigitPin35);
  int reading4 = digitalRead(c_ReadDigitPin34);
  int reading5 = digitalRead(c_ReadDigitPin33);
  int reading6 = digitalRead(c_ReadDigitPin32);
  int reading7 = digitalRead(c_ReadDigitPin31);
  int reading8 = digitalRead(c_ReadDigitPin30);
  if(TransitionPin == c_Digit1TransitionPin){ 
    digit1.concat(reading1);
    digit1.concat(reading2);
    digit1.concat(reading3);
    digit1.concat(reading4);
    digit1.concat(reading5);
    digit1.concat(reading6);
    digit1.concat(reading7);
    digit1.concat(reading8);
    delayMicroseconds(500);
    return digit1;
  }
  else if(TransitionPin == c_Digit2TransitionPin){
    digit2.concat(reading1);
    digit2.concat(reading2);
    digit2.concat(reading3);
    digit2.concat(reading4);
    digit2.concat(reading5);
    digit2.concat(reading6);
    digit2.concat(reading7);
    digit2.concat(reading8);
    delayMicroseconds(500);
    return digit2;
  }
  else if(TransitionPin == c_Digit3TransitionPin){
    digit3.concat(reading1);
    digit3.concat(reading2);
    digit3.concat(reading3);
    digit3.concat(reading4);
    digit3.concat(reading5);
    digit3.concat(reading6);
    digit3.concat(reading7);
    digit3.concat(reading8);
    delayMicroseconds(500);
    return digit3;
  }
}


/* This method converts the binary bytes into a decimal number
 by matching the binary byte to patterns that are known to produce 
 particular numbers. Then it combines the three digits into one decimal
 number. It takes digit1, digit2, and digit3 as inputs. */
String BinToNumber(String Digits1, String Digits2, String Digits3){ //digit1, digit2, digit3 respectively
  Digits1 = Digits1.substring(0, 8);
  Digits2 = Digits2.substring(0, 8);
  Digits3 = Digits3.substring(0, 8);
  int i, j, k;
  for(i = 0; i < 9; i = i + 1){
    if(Digits1.equals(NumberPatterns13[i])){
      number1 = Numbers13[i];
    }
  }
  for(j = 0; j < 9; j = j + 1){
    if(Digits2.equals(NumberPatterns2[j])){
      number2 = Numbers2[j];
    }
  }
  for(k = 0; k < 9; k = k + 1){
    if(Digits3.equals(NumberPatterns13[k])){
      number3 = Numbers13[k];
    }
  }

  number.concat(number1);
  number.concat(number2);
  number.concat(number3);
  return number;
}


/* This method pulls all the previous methods together. It uses Listening()
 to watch the transition pins for a transition, then it pulls the bits and
 converts the bits to a byte, and then matches the byte with its corresponding
 integer, and then returns the number on the LED display. */
String ReadDisplay(){
  digit1 = "";
  digit2 = "";
  digit3 = "";
  number = "";
  // Add delay to put read into middle of transition
  while (digitalRead(c_Digit1TransitionPin) == HIGH){
    Listening(c_Digit1TransitionPin);
  }
  readDigits(c_Digit1TransitionPin);
  while (digitalRead(c_Digit2TransitionPin) == HIGH){ 
    Listening(c_Digit2TransitionPin);
  }
  readDigits(c_Digit2TransitionPin);
  while (digitalRead(c_Digit3TransitionPin) == HIGH){
    Listening(c_Digit3TransitionPin);
  }
  ReadDigits(c_Digit3TransitionPin);
  return BinToNumber(digit1, digit2, digit3);

}

//**************************************************************************
//
//  REVISION HISTORY:
//
//
//
//**************************************************************************



