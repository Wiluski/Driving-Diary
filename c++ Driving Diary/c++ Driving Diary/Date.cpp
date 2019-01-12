#include "pch.h"
#include "Date.h"
#include <iostream>
using namespace std;

void Date::setDate()
{
	int optionSD = 0;
	do {
		cout << "give date xx/xx/xxxx: " << endl;
		cin >> day;
		cin.get();
		cin >> month;
		cin.get();
		cin >> year;
		cout << "your date: " << day << "/" << month << "/" << year << endl;
		cout << "is this correct?" << endl;
		cout << "Press 1 to continue and anything else to try again: " << endl;
		cin >> optionSD;
		if (optionSD != 0) {
			resetDate();
		}
	} while (optionSD != 1);
}

int Date::getDay() const
{
	return day;
}

int Date::getMonth() const
{
	return month;
}

int Date::getYear() const
{
	return year;
}

void Date::resetDate()
{
	day = 0;
	month = 0;
	year = 0;
}

ostream & operator<<(ostream & out, const Date & date0)
{
	out << date0.getDay << "/" << date0.getMonth << "/" << date0.getYear << endl;
	return out;
}
