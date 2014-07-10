//**************************************************************************
//
//				COPYRIGHT NOTICE
//			Copyright 2013 CONCORD ACADEMY
//		This program is the property of CONCORD ACADEMY
//		Any unauthorized use or duplication is prohibited
//
//**************************************************************************
//
//  Title		Time
//  Filename		time.cpp
//  Originator  	Kiyun Kim  
//  Archive Location	https://github.com/CADemons/Incufridge/blob/master/incufridge/time.cpp
//  Version		-
//
//  Overview		Allows for various time-related functions, which can 
//                      then be used in other classes.
//**************************************************************************

#include "project.h"

/* Constructor. */
Time::Time(){ 
}

/* Obtains time elapsed in minutes. */
long Time::getTimeInMinutes(){
  long t = millis();
  return(long(t/60000));
}

/* Adds two lengths of time together. */
long Time::addTime(long t1, long t2){
  return (t1 + t2);
}

/* Obtains time elapsed in seconds. */
long Time::getTimeInSeconds(){
  long t = millis();
  Serial.println("Time: " + String(long(t/1000)));
  return(long(t/1000));
}

//**************************************************************************
//
//  REVISION HISTORY:
//
//
//
//**************************************************************************
