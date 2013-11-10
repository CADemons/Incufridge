//**************************************************************************
//
//				COPYRIGHT NOTICE
//			Copyright 2013 CONCORD ACADEMY
//		This program is the property of CONCORD ACADEMY
//		Any unauthorized use or duplication is prohibited
//
//**************************************************************************
//
//  Title		-
//  Filename		-
//  Originator  	-  
//  Archive Location	-
//  Version		-
//
//  Overview		-
//
//***************************************************************************
#ifndef  THERMISTOR_H
#define	 THERMISTOR_H

// Include Files

#include "project.h"


enum TemperatureUnits {
  CELSIUS, FARENHEIT
};

class Thermistor {
  
  public:
    Thermistor(int pin, TemperatureUnits units = CELSIUS);
    float ReadTemperature();
    float ReadMilliVolts();
    float ReadCelsius();
    float ReadFarenheit();
    float CelsiusToFarenheit(float celsius);
    float FarenheitToCelsius(float farenheit);
    float MilliVoltsToCelsius(float millivolts);  
    //add calibration
    
  private:
    int m_Pin;
    TemperatureUnits m_Units;
    int m_Count;
    int m_Slope;
    int m_OffSet;
    float m_CountsToMilliVolts(int counts);
    void m_Read();
    float m_ReadTempCelsius();
};

//**************************************************************************
//
//  REVISION HISTORY:
//
//
//
//**************************************************************************

#endif
