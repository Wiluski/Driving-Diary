#include "pch.h"
#include "Date.h"
#include <iostream>
using namespace std;

const int Date::min = 0;
const int Date::maxDay = 31;
const int Date::maxMonth = 12;
//setting date
void Date::setDate()
{
	//option to verify user input
	int optionSD = 0;
	do {
		//takes user input for day month and year
		cout << "give date xx/xx/xxxx: " << endl;
		cin >> day;
		//checks the user input if it's in the correct format
		if (cin.get()!= '/') {
			cin.clear();
			cin.ignore();
			day = 0;
		}
		cin >> month;
		if (cin.get() != '/') {
			cin.clear();
			cin.ignore();
			month = 0;
		}
		cin >> year;
		if (day > min && day <= maxDay && month > min && month <= maxMonth && year > min)
		{
			//asks if user wants to change their input
			cout << "your date: " << day << "/" << month << "/" << year << endl;
			cout << "is this correct?" << endl;
			cout << "Press 1 to continue and anything else to try again: " << endl;
			cin >> optionSD;
			//if they do resets the values of day month and year
			if (optionSD != 1) {
				resetDate();
			}
		}else {
			cout << "incorrect input" << endl;
		}
		//loops until gets correct input
	} while (optionSD != 1);
}

//returns the value for day
int Date::getDay() const
{
	return day;
}

//returns the value for month
int Date::getMonth() const
{
	return month;
}

//return the value for year
int Date::getYear() const
{
	return year;
}

//resets the values
void Date::resetDate()
{
	day = 0;
	month = 0;
	year = 0;
}

