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
//  Title		Fan Class
//  Filename		fan.h
//  Originator  	Kiyun Kim 
//  Archive Location	https://github.com/CADemons/Incufridge/blob/master/incufridge/fan.h
//  Version		-
//
//  Overview		Provides framework for the Fan class, which allows the 
//                      user to control an external fan.
//**************************************************************************

class Fan {
  
  public:
    Fan(int pin, PwmState state);
    static void FanOn(String* commandIn);
    static void FanOff(String* commandIn);
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
