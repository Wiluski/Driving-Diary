#include "pch.h"
#include "Odometer.h"
#include <iostream>
using namespace std;


void Odometer::resetOdometer()
{
	startKm = 0;
	endKm = 0;
}

void Odometer::setStartKm() {
	int option1 = 0;
	do {
		cout << "Choose" << endl;
		cout << "1. Use the previous recording of odometer" << endl;
		cout << "2. Give the (full) kilometers driven" << endl;
		cin >> option1;
		if (option1 == 1) {
			cout << "ok" << endl;
			startKm = startValue();
		}
		else if (option1 == 2) {
			do {
				resetOdometer();
				cout << "give kilometers in format *****km" << endl;
				cout << "give kilometers: ";
				cin >> startKm;
				if (cin.get() != 'km') {
					cout << "\n expected 'km'" << endl;
					startKm = 0;
				}
			} while (cin.get() != 'km');
		}
	} while (option1 != 1);
}

void Odometer::setEndKm()
{
	do {
		cout << "Give kilometers in format ******km" << endl;
		cout << "Give the kilometers: ";
		cin >> endKm;
		if (cin.get() != 'km') {
			cout << "\nexpected 'km'" << endl;
			endKm = 0;
		}
	} while (cin.get() != 'km');
}

int Odometer::startValue() {

	return 0;
}

int Odometer::getDistance() const
{
	return getEndKm() - getStartKm();
}

