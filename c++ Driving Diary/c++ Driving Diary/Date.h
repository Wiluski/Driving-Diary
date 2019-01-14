#pragma once
#ifndef DATE_H
#define DATE_H
#include <iostream>
//class where date is saved
class Date {
public:
	Date(int day0 = 0, int month0 = 0, int year0 = 0) : day(day0), month(month0), year(year0) {

	}
	//function for setting the date
	void setDate();
	//functions for using day, month and year
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	//resets the values of day, month and year
	void resetDate();
private:
	//data members for date
	int day;
	int month;
	int year;
};


#endif