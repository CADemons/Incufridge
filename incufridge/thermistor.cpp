#include "project.h"

Thermistor::Thermistor(int pin, TemperatureUnits units)
{
  myPin = pin;
  pinMode(myPin, INPUT);
  myUnits = units;
}
void Thermistor::Read()
{
  myCount = analogRead(myPin);
}
float Thermistor::CountsToMilliVolts(int counts)
{
  float millivolts;
  millivolts = myCount*mySlope + myOffSet;
  return millivolts;
}
float Thermistor::MilliVoltsToCelsius(float millivolts)
{
  float celsius; 
  celsius = millivolts;
  return celsius;
 
 // figure out which thermistors will be used- see data sheet 
}
float Thermistor::CelsiusToFarenheit(float celsius)
{
  float farenheit;
  farenheit = celsius*9/5 + 32;
  return farenheit;
}
float Thermistor::FarenheitToCelsius(float farenheit)
{
  float celsius;
  celsius = (farenheit - 32)*5/9;
  return celsius;
}
float Thermistor::ReadTempCelsius()
{
  float millivolts;
  float temperature;
  Read();
  millivolts = CountsToMilliVolts(myCount);
  temperature = MilliVoltsToCelsius(millivolts);
  return temperature;
}
float Thermistor::ReadMilliVolts(){
  float millivolts;
  Read();
  millivolts = CountsToMilliVolts(myCount);
  return millivolts;
}
float Thermistor:: ReadTemperature(){
  float temperature;
  temperature = ReadTempCelsius();
  if(myUnits == FARENHEIT){
    temperature = CelsiusToFarenheit(temperature);
  }
  return temperature;
}
float Thermistor::ReadCelsius()
{
  float celsius;
  celsius = ReadTempCelsius();
  return celsius;
}
float Thermistor::ReadFarenheit()
{
  float farenheit;
  float celsius;
  celsius = ReadTempCelsius();
  farenheit = CelsiusToFarenheit(celsius);
  return farenheit;
}

  

