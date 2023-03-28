#ifndef CLASSES
#define CLASSES

#include <iostream>
#include <iomanip>
#include "Colors.h"


class Time
{
	int hours,
		minutes;
public:
	int getHour();
	int getMinute();
	void showTime();
	int setTime(int hour, int minute);
	int timeToMin();
};

class WorkDayTerm
{
	Time dayBegin;
	Time dayEnd;
public:
	Time getDayBegin();
	Time getDayEnd();
	void setDayBegin();
	void setDayEnd();
	void setDayTerm();
};

class Break
{
	Time breakBegin;
	Time breakEnd;
public:
	Time getBreakBegin();
	Time getBreakEnd();
	void setBreakBegin();
	void setBreakBegin(int hour, int min);
	void setBreakEnd();
	void setBreakEnd(int hour, int min);
};

#endif 
