//**************************************************************************
//
//				COPYRIGHT NOTICE
//			Copyright 2013 CONCORD ACADEMY
//		This program is the property of CONCORD ACADEMY
//		Any unauthorized use or duplication is prohibited
//
//**************************************************************************
//
//  Title		Button Class
//  Filename		button.h
//  Originator  	Kiyun Kim 
//  Archive Location	https://github.com/CADemons/Incufridge/blob/master/incufridge/button.h
//  Version		-
//
//  Overview		Provides framework for the Button class, which allows
//                      the user to press and release buttons.
//**************************************************************************

#ifndef  BUTTON_H
#define BUTTON_H

enum c_Level{
  c_LEVEL_LOW = LOW, c_LEVEL_HIGH = HIGH
};

class Button{
public: 
  Button(const int Pin, int msPressTime, const int PressLevel = c_LEVEL_HIGH);
  void Initialize();
  void Press();
  void HoldFor(int HoldTime);
  void Release();
  boolean IsUp();
  boolean IsDown();
private:
  int m_Pin;
  int m_PressLevel;
  int m_ReleaseLevel;
};
#endif
//**************************************************************************
//
//  REVISION HISTORY:
//
//
//
//**************************************************************************




