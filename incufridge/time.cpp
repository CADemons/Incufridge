#include "project.h"

int getTimeInMinutes(){
  int t = millis();
  t = t*1000*60;
}
int addTime(int t1, int t2){
  return (t1 + t2);
}

int getTimeInSeconds(){
  int t = millis();
  t = t*1000;
}
