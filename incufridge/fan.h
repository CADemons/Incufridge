#ifndef FAN_H
#define FAN_H

//**************************************************************************
//
//				COPYRIGHT NOTICE
//			Copyright 2013 CONCORD ACADEMY
//		This program is the property of CONCORD ACADEMY
//		Any unauthorized use or duplication is prohibited
//
//**************************************************************************
//
//  Title		- Fan class
//  Filename		- fan.h
//  Originator  	-  
//  Archive Location	-
//  Version		-
//
//  Overview		- Provides ability to turn fan on and off
//
//**************************************************************************

class Fan {
  
  public:
    Fan(int pin, PwmState state);
    static void FanOn();
    static void FanOff();
    void FanSpeed();
    
  private:
    int m_pin;
    int m_state;
};

//**************************************************************************
//
//  REVISION HISTORY:
//
//
//
//**************************************************************************

#endif
