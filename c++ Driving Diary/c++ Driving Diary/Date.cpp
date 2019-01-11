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

int Date::getDate() const
{
	return 0;
}

void Date::resetDate()
{
	day = 0;
	month = 0;
	year = 0;
}
