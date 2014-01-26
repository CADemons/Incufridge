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

class LEDReader{
public:
  LEDReader(SevenSegments SevenSegment, const int TensTransitionPin,
  const int OnesTransitionPin, const int DecimalTransitionPin);
  void Initialize();
  String ReadDisplay();
private:
  SevenSegments m_SevenSegment;
  int m_TensTransitionPin, m_OnesTransitionPin, m_DecimalTransitionPin;
  String TensDigit, OnesDigit, DecimalDigit, TensNumber, OnesNumber, DecimalNumber, FinalResult;
  int Listening(int TransitionPin);
  String ReadDigits(int TransitionPin);
  String BinaryToNumber(String Digits1, String Digits2, String Digits3);
};
#endif
