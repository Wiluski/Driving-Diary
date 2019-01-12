#pragma once
#ifndef DATE_H
#define DATE_H
#include <iostream>

class Date {
public:
	Date(int day0 = 0, int month0 = 0, int year0 = 0) : day(day0), month(month0), year(year0) {

	}
	void setDate();
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void resetDate();
private:
	int day;
	int month;
	int year;
};

ostream &operator<<(ostream &out, const Date &date0);

#endif