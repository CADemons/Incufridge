//**************************************************************************
//
//				COPYRIGHT NOTICE
//			Copyright 2013 CONCORD ACADEMY
//		This program is the property of CONCORD ACADEMY
//		Any unauthorized use or duplication is prohibited
//
//**************************************************************************
//
//  Title		Time Class
//  Filename		time.cpp
//  Originator  	Kiyun Kim  
//  Archive Location	https://github.com/CADemons/Incufridge/blob/master/incufridge/time.h
//  Version		-
//
//  Overview		Procides framework for the Time class, which allows
//                      the user to carry out functions involving time.
//**************************************************************************

#ifndef TIME_H
#define TIME_H

class Time {
  public:
    Time();
    long addTime(long t1, long t2);
    long getTimeInMinutes();
    long getTimeInSeconds();
};
#endif

//**************************************************************************
//
//  REVISION HISTORY:
//
//
//
//**************************************************************************
