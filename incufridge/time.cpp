#include "project.h"
Time::Time(){ 
}
long Time::getTimeInMinutes(){
  long t = millis();
  return(long(t/60000));
}
long Time::addTime(long t1, long t2){
  return (t1 + t2);
}

long Time::getTimeInSeconds(){
  long t = millis();
  Serial.println("Time: " + String(long(t/1000)));
  return(long(t/1000));
}

