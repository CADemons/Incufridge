#include "project.h"
Time::Time(){ 
}
int Time::getTimeInMinutes(){
  int t = millis();
  return(floor(t/60000));
}
int Time::addTime(int t1, int t2){
  return (t1 + t2);
}

int Time::getTimeInSeconds(){
  int t = millis();
  return(floor(t/1000));
}

