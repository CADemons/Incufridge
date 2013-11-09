enum TemperatureUnits {
  CELSIUS, FARENHEIT
};

class Thermistor{
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
  int myPin;
  TemperatureUnits myUnits;
  int myCount;
  int mySlope;
  int myOffSet;
  float CountsToMilliVolts(int counts);
  void Read();
  float ReadTempCelsius();
};

