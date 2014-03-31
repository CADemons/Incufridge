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
//  Filename		- Thermistor.cpp
//  Originator  	-  
//  Archive Location	-
//  Version		-
//
//  Overview		- Provides ability to read temperature in Celsius or Farenheit
//
//**************************************************************************

#include "project.h"

Thermistor::Thermistor(int pin, TemperatureUnits units)
{
  m_Pin = pin;
  pinMode(m_Pin, INPUT);
  m_Units = units;
}

//Read the counts
void Thermistor::m_Read()
{
  m_Count = analogRead(m_Pin);
}

//Convert counts to millivolts
float Thermistor::m_CountsToMilliVolts(int counts)
{
  float millivolts;
  millivolts = m_Count*m_Slope + m_OffSet;
  return millivolts;
}

//Convert millivolts to Celsius
float Thermistor::MilliVoltsToCelsius(float millivolts)
{
  float celsius; 
  celsius = (millivolts + 0.872)/(-0.0024);
  return celsius;
 
 // figure out which thermistors will be used- see data sheet 
}

//Convert Celsius to Farenheit
float Thermistor::CelsiusToFarenheit(float celsius)
{
  float farenheit;
  farenheit = celsius*9/5 + 32;
  return farenheit;
}

//Convert Farenheit to Celsius
float Thermistor::FarenheitToCelsius(float farenheit)
{
  float celsius;
  celsius = (farenheit - 32)*5/9;
  return celsius;
}

//Read the temperature in Celsius
float Thermistor::m_ReadTempCelsius()
{
  float millivolts;
  float temperature;
  m_Read();
  millivolts = m_CountsToMilliVolts(m_Count);
  temperature = MilliVoltsToCelsius(millivolts);
  return temperature;
}

//Read the temperature in millivolts
float Thermistor::ReadMilliVolts() 
{
  float millivolts;
  m_Read();
  millivolts = m_CountsToMilliVolts(m_Count);
  return millivolts;
}

//Read the temperature based on m_Units
float Thermistor:: ReadTemperature() 
{
  float temperature;
  temperature = m_ReadTempCelsius();
  if(m_Units == FARENHEIT) {
    temperature = CelsiusToFarenheit(temperature);
  }
  return temperature;
}

//Read the temperature in Celsius
float Thermistor::ReadCelsius()
{
  float celsius;
  celsius = m_ReadTempCelsius();
  return celsius;
}

//Read the temperature in Farenheit
float Thermistor::ReadFarenheit()
{
  float farenheit;
  float celsius;
  celsius = m_ReadTempCelsius();
  farenheit = CelsiusToFarenheit(celsius);
  return farenheit;
}

//**************************************************************************
//
//  REVISION HISTORY:
//
//
//
//**************************************************************************  
