//**************************************************************************
//
//				COPYRIGHT NOTICE
//			Copyright 2013 CONCORD ACADEMY
//		This program is the property of CONCORD ACADEMY
//		Any unauthorized use or duplication is prohibited
//
//**************************************************************************
//
//  Title		- Thermistor class
//  Filename		- Thermistor.h
//  Originator  	- 
//  Archive Location	- 
//  Version		- 
//
//  Overview		- Provides ability to read temperature in Farenheit or Celsius
//
//**************************************************************************
#ifndef  THERMISTOR_H
#define	 THERMISTOR_H

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
