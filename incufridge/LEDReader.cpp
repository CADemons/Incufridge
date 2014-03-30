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


/* BinaryStringTens, BinaryStringOnes, and BinaryStringDecimals are the entire 
 bytes of data for each number on the display. OutputNumberTens, OutputNumberOnes, 
 and OutputNumberDecimals are used to convert each digit from its binary state 
 to user-friendly decimal integers. FinalResult is the final number, in the form 
 of nn.n. */
SevenSegments m_Display;
ConversionPattern m_ConversionPatternsTens[10];
ConversionPattern m_ConversionPatternsOnes[10];
ConversionPattern m_ConversionPatternsDecimals[10];
int m_TransitionPinTens, m_TransitionPinOnes, m_TransitionPinDecimals;
String BinaryStringTens, BinaryStringOnes, BinaryStringDecimals, OutputNumberTens, OutputNumberOnes, OutputNumberDecimals, FinalResult;




/* Constructor */
LEDReader::LEDReader(SevenSegments Display, const int TensTransitionPin,
const int OnesTransitionPin, const int DecimalTransitionPin, 
ConversionPattern Tens[10], ConversionPattern Ones[10], ConversionPattern Decimals[10]){
  m_Display = Display;
  m_TransitionPinTens = TensTransitionPin;
  m_TransitionPinOnes = OnesTransitionPin;
  m_TransitionPinDecimals = DecimalTransitionPin;
  for(int i = 0; i < 10; i += 1){
    m_ConversionPatternsTens[i] = Tens[i];
    m_ConversionPatternsOnes[i] = Ones[i];
    m_ConversionPatternsDecimals[i] = Decimals[i];
  }
}

/*This method sets each pin used in by this class to its proper mode. In
 this case, all pins should be set to input.*/
void LEDReader::Initialize(){
  pinMode(m_Display.BottomLeft, INPUT);
  pinMode(m_Display.TopLeft, INPUT);
  pinMode(m_Display.MiddleBar, INPUT);
  pinMode(m_Display.DecimalPoint, INPUT);
  pinMode(m_Display.BottomBar, INPUT);
  pinMode(m_Display.BottomRight, INPUT);
  pinMode(m_Display.TopRight, INPUT);
  pinMode(m_Display.TopBar, INPUT);
  pinMode(m_TransitionPinTens, INPUT);
  pinMode(m_TransitionPinOnes, INPUT);
  pinMode(m_TransitionPinDecimals, INPUT);
  pinMode(38, OUTPUT);
}



/* This method returns the state (HIGH or LOW) of a particular transition pin. */
int LEDReader::Listening(int TransitionPin){
  int state = digitalRead(TransitionPin);
  return state;
}


/* This method reads bits from the portion of the LED display designated by
 the transition pin and creates a binary pattern, which lists which individual 
 LED lights are on at a given point in time. */
String LEDReader::ReadDigits(int TransitionPin) {
  int BottomLeft = digitalRead(m_Display.BottomLeft);
  int TopLeft = digitalRead(m_Display.TopLeft);
  int MiddleBar = digitalRead(m_Display.MiddleBar);
  int DecimalPoint = digitalRead(m_Display.DecimalPoint);
  int BottomBar = digitalRead(m_Display.BottomBar);
  int BottomRight = digitalRead(m_Display.BottomRight);
  int TopRight = digitalRead(m_Display.TopRight);
  int TopBar = digitalRead(m_Display.TopBar);
  if(TransitionPin == m_TransitionPinTens){ 
    BinaryStringTens.concat(BottomLeft);
    BinaryStringTens.concat(TopLeft);
    BinaryStringTens.concat(MiddleBar);
    BinaryStringTens.concat(DecimalPoint);
    BinaryStringTens.concat(BottomBar);
    BinaryStringTens.concat(BottomRight);
    BinaryStringTens.concat(TopRight);
    BinaryStringTens.concat(TopBar);
    return BinaryStringTens;
  }
  else if(TransitionPin == m_TransitionPinOnes){
    BinaryStringOnes.concat(BottomLeft);
    BinaryStringOnes.concat(TopLeft);
    BinaryStringOnes.concat(MiddleBar);
    BinaryStringOnes.concat(DecimalPoint);
    BinaryStringOnes.concat(BottomBar);
    BinaryStringOnes.concat(BottomRight);
    BinaryStringOnes.concat(TopRight); 
    BinaryStringOnes.concat(TopBar);
    return BinaryStringOnes;
  }
  else if(TransitionPin == m_TransitionPinDecimals){
    BinaryStringDecimals.concat(BottomLeft);
    BinaryStringDecimals.concat(TopLeft);
    BinaryStringDecimals.concat(MiddleBar);
    BinaryStringDecimals.concat(DecimalPoint);
    BinaryStringDecimals.concat(BottomBar);
    BinaryStringDecimals.concat(BottomRight);
    BinaryStringDecimals.concat(TopRight);
    BinaryStringDecimals.concat(TopBar);
    return BinaryStringDecimals;
  }
}

/*This method checks for a HIGH to LOW transition on a given Transition Pin.
 When it finds such a transition, it waits for 15 microseconds before pulling
 the binary data using ReadDigits().*/
String LEDReader::Read(int TransitionPin){
  //  Serial.println("Hello there");
  if(digitalRead(TransitionPin) == LOW){
    while(digitalRead(TransitionPin) == LOW){
      Listening(TransitionPin);
    }
  }
  if(digitalRead(TransitionPin) == HIGH){
    while (digitalRead(TransitionPin) == HIGH){
      Listening(TransitionPin);
    }
    delayMicroseconds(15);
    return ReadDigits(TransitionPin);
  }
}


/* This method converts the binary bytes into a decimal number
 by matching the read patterns to patterns that are known to produce 
 particular numbers. Then it combines the three digits into one decimal
 number.  */
String LEDReader::Convert(String PatternTens, String PatternOnes, String PatternDecimals){ 
  PatternTens = PatternTens.substring(0, 8);
  PatternOnes = PatternOnes.substring(0, 8);
  PatternDecimals = PatternDecimals.substring(0, 8);
  int i, j, k;
  for(i = 0; i < 10; i = i + 1){
    if(PatternTens.equals(m_ConversionPatternsTens[i].Pattern)){
      OutputNumberTens = m_ConversionPatternsTens[i].Digit;
    }
  }

  for(j = 0; j < 10; j += 1){
    if(PatternOnes.equals(m_ConversionPatternsOnes[j].Pattern)){
      OutputNumberOnes = m_ConversionPatternsOnes[j].Digit;
    }
  }

  for(k = 0; k < 10; k += 1){
    if(PatternDecimals.equals(m_ConversionPatternsDecimals[k].Pattern)){
      OutputNumberDecimals = m_ConversionPatternsDecimals[k].Digit;
    }
  }

  FinalResult.concat(OutputNumberTens);
  FinalResult.concat(OutputNumberOnes);
  FinalResult.concat(OutputNumberDecimals);
  return FinalResult;
}


/* This method pulls all the previous methods together. It calls Read() to 
 gather the binary patterns, and then calls Convert() to translate the patterns
 into decimal digits.*/
String LEDReader::ShowDisplay(){
  BinaryStringTens = "";
  BinaryStringOnes = "";
  BinaryStringDecimals = "";
  FinalResult = "";

  BinaryStringTens = Read(m_TransitionPinTens);
  BinaryStringOnes = Read(m_TransitionPinOnes);
  BinaryStringDecimals = Read(m_TransitionPinDecimals);

  return Convert(BinaryStringTens, BinaryStringOnes, BinaryStringDecimals);
//   return BinaryStringTens + " " + BinaryStringOnes + " " + BinaryStringDecimals + " " + Convert(BinaryStringTens, BinaryStringOnes, BinaryStringDecimals);
}

//**************************************************************************
//
//  REVISION HISTORY:
//
//
//
//**************************************************************************























