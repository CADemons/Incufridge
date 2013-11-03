#include "project.h"

int time::getTimeInMinutes(){
  int t = millis();
  t = t*1000*60;
}
int time::addTime(int t1, int t2){
  return (t1 + t2);
}

int time::getTimeInSeconds(){
  int t = millis();
  t = t*1000;
}
