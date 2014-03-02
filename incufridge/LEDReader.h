#ifndef LEDREADER_H
#define LEDREADER_H

typedef struct{
  int BottomLeft;
  int TopLeft;
  int MiddleBar;
  int DecimalPoint;
  int BottomBar;
  int BottomRight;
  int TopRight;
  int TopBar;
} 
SevenSegments;

typedef struct{
  String Pattern;
  String Digit;
}
ConversionPattern;

class LEDReader{
public:
  LEDReader(SevenSegments Display, const int TransitionPinTens,
  const int TransitionPinOnes, const int TransitionPinDecimals, 
  ConversionPattern Tens[10], ConversionPattern Ones[10], ConversionPattern Decimals[10]);
  void Initialize();
  String ShowDisplay();
private:
  SevenSegments m_Display;
  int m_TransitionPinTens, m_TransitionPinOnes, m_TransitionPinDecimals;
  String BinaryStringTens, BinaryStringOnes, BinaryStringDecimals, OutputNumbeTens, OutputNumberOnes, OutputNumberDecimals, FinalResult;
  int Listening(int TransitionPin);
  String ReadDigits(int TransitionPin);
  String Convert(String DigitTens, String DigitOnes, String DigitDecimals);
  String Read(int TransitionPin);
};
#endif
