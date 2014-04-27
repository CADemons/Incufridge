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
