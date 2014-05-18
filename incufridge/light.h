//**************************************************************************
//
//				COPYRIGHT NOTICE
//			Copyright 2013 CONCORD ACADEMY
//		This program is the property of CONCORD ACADEMY
//		Any unauthorized use or duplication is prohibited
//
//**************************************************************************
//
//  Title		Light Class
//  Filename		light.h
//  Originator  	Kiyun Kim  
//  Archive Location	https://github.com/CADemons/Incufridge/blob/master/incufridge/light.h
//  Version		-
//
//  Overview		Provides framework for the Light class, which allows
//                      the user to control light(s) in the incufridge.
//**************************************************************************

#ifndef LIGHT_H
#define LIGHT_H

class Light{
  public:
    Light(int pin, PwmState state = PWM_LOW);
    static void LightOff(String* commandIn);
    static void LightOn(String* commandIn);
    void DimToLevel(int level);
    void LightFlash(int rate);
    void DimOverTime(int startLevel, int endLevel);
  private:
    static int m_Pin;
    static PwmState m_PwmState;
};

#endif

//**************************************************************************
//
//  REVISION HISTORY:
//
//
//
//**************************************************************************
