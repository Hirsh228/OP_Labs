#include "Classes.h"

//Returns hours
int Time::getHour() {
	return hours;
}
//Returns minutes
int Time::getMinute() {
	return minutes;
}
//Set hours and minutes in hh:mm format
int Time::setTime(int hour, int minute) {
	if (hour < 0 || hour > 23) {
		std::cout << "Hour must between 0 and 23.\n";
		return EXIT_FAILURE;
	}

	if (minute < 0 || minute > 59) {
		std::cout << "Minutes must between 0 and 59.\n";
		return EXIT_FAILURE;
	}
	hours = hour;
	minutes = minute;
	return EXIT_SUCCESS;
}
//Returns the minutes of the certain time
int Time::timeToMin() {
	int sum{ 0 };
	sum += minutes;
	sum += hours*60;
	return sum;
}
//Show time in hh:mm format
void Time::showTime() {
	std::cout.fill('0');
	std::cout << std::setw(2) << hours << std::setw(1) << ":" << std::setw(2) << minutes;
}

//Returns the start time of the day
Time WorkDayTerm::getDayBegin() {
	return dayBegin;
}
//Returns the end time of the day
Time WorkDayTerm::getDayEnd() {
	return dayEnd;
}
//Sets the start time of the day
void WorkDayTerm::setDayBegin() {
	int min{}, hor{};
	char colon = '\0';
	do {
		std::cout << "Enter work day start time in hh:mm format: ";
		std::cin >> hor >> colon >> min;
		if (static_cast<int>(colon) != 58) {
			std::cout << "Semicolon please!\n";
		}
	} while (static_cast<int>(colon) != 58 || dayBegin.setTime(hor, min));
}
//Sets the end of day time
void WorkDayTerm::setDayEnd() {
	Time end;
	int min{}, hor{};
	char colon = '\0';
	do {
		do {
			std::cout << "Enter work day end time in hh:mm format: ";
			std::cin >> hor >> colon >> min;
			if (static_cast<int>(colon) != 58) {
				std::cout << "Semicolon please!\n";
			}
		} while (static_cast<int>(colon) != 58 || end.setTime(hor, min));
		dayEnd = end;
		if (dayBegin.timeToMin() > dayEnd.timeToMin()) {
			std::cout << "The end must be after the beginning!\n";
		}
	} while (dayBegin.timeToMin() > dayEnd.timeToMin());
}
//Sets end and start of the day
void WorkDayTerm::setDayTerm() {
	cyanColor();
	setDayBegin();
	setDayEnd();
	resetColor();
	system("pause");
}

//Returns the time of break begin 
Time Break::getBreakBegin() { return breakBegin; }
//Returns the time of break end
Time Break::getBreakEnd() { return breakEnd; }
//Sets the time of break begin 
void Break::setBreakBegin() {
	int min{}, hor{};
	char colon{ '\0' };
	do {
		std::cout << "Enter break start time in hh:mm format: ";
		std::cin >> hor >> colon >> min;
		if (static_cast<int>(colon) != 58) {
			std::cout << "Semicolon please!\n";
		}
	} while (static_cast<int>(colon) != 58 || breakBegin.setTime(hor, min));
}
//Sets the time of break end
void Break::setBreakEnd() {
	int min{}, hor{};
	char colon{ '\0' };
	do{
		do {
			std::cout << "Enter break end time in hh:mm format: ";
			std::cin >> hor >> colon >> min;
			if (static_cast<int>(colon) != 58) {
				std::cout << "Semicolon please!\n";
			}
		} while (static_cast<int>(colon) != 58 || breakEnd.setTime(hor, min));
		if (breakBegin.timeToMin() > breakEnd.timeToMin()) {
			std::cout << "The end must be after the beginning!\n";
		}
	}while (breakBegin.timeToMin() > breakEnd.timeToMin());
}
//Sets the time of break begin 
void Break::setBreakBegin(int hour, int min) {
	breakBegin.setTime(hour, min);
}
//Sets the time of break end
void Break::setBreakEnd(int hour, int min) {
	breakEnd.setTime(hour, min);
}