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

#include "general.h"


/* TensDigit, OnesDigit, and DecimalDigit are the entire bytes of data for each 
 number on the display. TensNumber, OnesNumber, and DecimalNumber are used to 
 convert each digit from its binary state to user-friendly decimal integers. 
 FinalResult is the final number, in the form of nn.n. The arrays NumberPatterns13,
 NumberPatterns2, Numbers13, and Numbers2 are used for the conversion process,
 with the suffixes of 13 or 2 denoting which digit (1/first/tens, 2/second/ones, 
 or 3/third/decimal) the array is applicable to. */
SevenSegments m_SevenSegments;
int m_TensTransitionPin, m_OnesTransitionPin, m_DecimalTransitionPin;
String TensDigit, OnesDigit, DecimalDigit, TensNumber, OnesNumber, DecimalNumber, FinalResult;
String NumberPatterns13[10] = {
  "11001111", "00000110", "10101011", "00101111", "01100110", 
  "01101101", "11101101", "00000111", "11101111", "01100111"  };
String NumberPatterns2[10] = {
  "11011111", "00010110", "10111011", "00111111", "01110110", 
  "01111101", "11101101", "00010111", "11111111", "01110111"  };
String Numbers13[10] = {
  "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"  };
String Numbers2[10] = {
  "0.", "1.", "2.", "3.", "4.", "5.", "6.", "7.", "8.", "9."  };
String SevenSegmentValues[7];


/* Constructor */
LEDReader::LEDReader(SevenSegments SevenSegment, const int TensTransitionPin,
const int OnesTransitionPin, const int DecimalTransitionPin){
  m_SevenSegment = SevenSegment;
  m_TensTransitionPin = TensTransitionPin;
  m_OnesTransitionPin = OnesTransitionPin;
  m_DecimalTransitionPin = DecimalTransitionPin;
}

void LEDReader::Initialize(){
  pinMode(m_SevenSegment.BottomLeft, INPUT);
//  Serial.println("BottomLeft " + m_SevenSegment.BottomLeft);
  pinMode(m_SevenSegment.TopLeft, INPUT);
  pinMode(m_SevenSegment.MiddleBar, INPUT);
  pinMode(m_SevenSegment.DecimalPoint, INPUT);
  pinMode(m_SevenSegment.BottomBar, INPUT);
  pinMode(m_SevenSegment.BottomRight, INPUT);
  pinMode(m_SevenSegment.TopRight, INPUT);
  pinMode(m_SevenSegment.TopBar, INPUT);
  pinMode(m_TensTransitionPin, INPUT);
  pinMode(m_OnesTransitionPin, INPUT);
  pinMode(m_DecimalTransitionPin, INPUT);
  pinMode(38, INPUT);
}



/* This method returns the state (HIGH or LOW) of a particular transition pin. */
int LEDReader::Listening(int TransitionPin){
  int state = digitalRead(TransitionPin);
  return state;
}


/* This method reads bits from the portion of the LED display designated by
 the transition pin, and converts the bits into a byte, which is a string that
 lists which individual LED lights are on at a given point in time. */
String LEDReader::ReadDigits(int TransitionPin) {
//  SevenSegmentValues[7] = {
//    digitalRead(m_SevenSegment.BottomLeft),  
//    digitalRead(m_SevenSegment.TopLeft), 
//    digitalRead(m_SevenSegment.MiddleBar),
//    digitalRead(m_SevenSegment.DecimalPoint), 
//    digitalRead(m_SevenSegment.BottomBar),
//    digitalRead(m_SevenSegment.BottomRight),
//    digitalRead(m_SevenSegment.TopRight),
//    digitalRead(m_SevenSegment.TopBar)      };

    int BottomLeft = digitalRead(m_SevenSegment.BottomLeft);
    int TopLeft = digitalRead(m_SevenSegment.TopLeft);
    int MiddleBar = digitalRead(m_SevenSegment.MiddleBar);
    int DecimalPoint = digitalRead(m_SevenSegment.DecimalPoint);
    int BottomBar = digitalRead(m_SevenSegment.BottomBar);
    int BottomRight = digitalRead(m_SevenSegment.BottomRight);
    int TopRight = digitalRead(m_SevenSegment.TopRight);
    int TopBar = digitalRead(m_SevenSegment.TopBar);
  if(TransitionPin == m_TensTransitionPin){ 
        TensDigit.concat(BottomLeft);
        TensDigit.concat(TopLeft);
        TensDigit.concat(MiddleBar);
        TensDigit.concat(DecimalPoint);
        TensDigit.concat(BottomBar);
        TensDigit.concat(BottomRight);
        TensDigit.concat(TopRight);
        TensDigit.concat(TopBar);
//        Serial.println("Tens Digit");
//    for(int i = 0; i < 7; i = i + 1){
//      TensDigit.concat(SevenSegmentValues[i]);
//    }
    delayMicroseconds(600);
    return TensDigit;
  }
  else if(TransitionPin == m_OnesTransitionPin){
        OnesDigit.concat(BottomLeft);
        OnesDigit.concat(TopLeft);
        OnesDigit.concat(MiddleBar);
        OnesDigit.concat(DecimalPoint);
        OnesDigit.concat(BottomBar);
        OnesDigit.concat(BottomRight);
        OnesDigit.concat(TopRight); 
        OnesDigit.concat(TopBar);
//        Serial.println("Ones Digit");
//    for(int i = 0; i < 7; i = i + 1){
//      OnesDigit.concat(SevenSegmentValues[i]);
//    }
    delayMicroseconds(600);
    return OnesDigit;
  }
  else if(TransitionPin == m_DecimalTransitionPin){
        DecimalDigit.concat(BottomLeft);
        DecimalDigit.concat(TopLeft);
        DecimalDigit.concat(MiddleBar);
        DecimalDigit.concat(DecimalPoint);
        DecimalDigit.concat(BottomBar);
        DecimalDigit.concat(BottomRight);
        DecimalDigit.concat(TopRight);
        DecimalDigit.concat(TopBar);
//        Serial.println("Decimal Digit");
//    for(int i = 0; i < 7; i = i + 1){
//      DecimalDigit.concat(SevenSegmentValues[i]);
//    }
    delayMicroseconds(600);
    return DecimalDigit;
  }
}


/* This method converts the binary bytes into a decimal number
 by matching the binary byte to patterns that are known to produce 
 particular numbers. Then it combines the three digits into one decimal
 number. It takes TensDigit, OnesDigit, and DecimalDigit as inputs. */
String LEDReader::BinaryToNumber(String Digits1, String Digits2, String Digits3){ //digit1, digit2, digit3 respectively
  Digits1 = Digits1.substring(0, 8);
  Digits2 = Digits2.substring(0, 8);
  Digits3 = Digits3.substring(0, 8);
  int i, j, k;
  for(i = 0; i < 10; i = i + 1){
    if(Digits1.equals(NumberPatterns13[i])){
      TensNumber = Numbers13[i];
    }
  }
  for(j = 0; j < 10; j = j + 1){
    if(Digits2.equals(NumberPatterns2[j])){
      OnesNumber = Numbers2[j];
    }
  }
  for(k = 0; k < 10; k = k + 1){
    if(Digits3.equals(NumberPatterns13[k])){
      DecimalNumber = Numbers13[k];
    }
  }
  FinalResult.concat(TensNumber);
  FinalResult.concat(OnesNumber);
  FinalResult.concat(DecimalNumber);
  return FinalResult;
}


/* This method pulls all the previous methods together. It uses Listening()
 to watch the transition pins for a transition, then it pulls the bits and
 converts the bits to a byte, and then matches the byte with its corresponding
 integer, and then returns the number on the LED display. */
String LEDReader::ReadDisplay(){
  TensDigit = "";
  OnesDigit = "";
  DecimalDigit = "";
  FinalResult = "";
  // Add delay to put read into middle of transition
  digitalWrite(38, HIGH);
  while (digitalRead(m_TensTransitionPin) == HIGH){
    Listening(m_TensTransitionPin);
  }
//  delayMicroseconds(500);
  ReadDigits(m_TensTransitionPin);
  while (digitalRead(m_OnesTransitionPin) == HIGH){ 
    Listening(m_OnesTransitionPin);
  }
//  delayMicroseconds(500);
  ReadDigits(m_OnesTransitionPin);
  while (digitalRead(m_DecimalTransitionPin) == HIGH){
    Listening(m_DecimalTransitionPin);
  }
//  delayMicroseconds(500);
  ReadDigits(m_DecimalTransitionPin);
 digitalWrite(38, LOW);
//  return BinaryToNumber(TensDigit, OnesDigit, DecimalDigit);
  return TensDigit + " " + OnesDigit + " " + DecimalDigit;

}

//**************************************************************************
//
//  REVISION HISTORY:
//
//
//
//**************************************************************************











