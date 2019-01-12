#include "pch.h"
#include "Odometer.h"
#include <iostream>
using namespace std;

int Odometer::countO = 0;
int Odometer::endLenght = 0;

void Odometer::resetOdometer()
{
	startKm = 0;
	endKm = 0;
}

void Odometer::setStartKm() {
	int option1 = 0;
	int option2 = 0;
	do {
		cout << "Choose" << endl;
		cout << "1. Use the previous recording of odometer" << endl;
		cout << "2. Give the (full) kilometers driven: ";
		cin >> option1;
		if (option1 == 1) {
			cout << "ok" << endl;
			startKm = startValue();
		}
		else if (option1 == 2) {
			do {
				resetOdometer();
				cout << "give kilometers: ";
				cin >> startKm;
				cout << "is " << startKm << " Correct input?" << endl;
				cout << "Press 1: to continue and anything else to try again." << endl;
				cin >> option2;
			} while (option2 != 1 || startKm < 0);
		}
	} while (option1 != 1 || option1 != 2);
}

void Odometer::setEndKm()
{
	int kilometersInDestination = 0;
	int optionEd = 0;
	do {
		cout << "Give the kilometers: ";
		cin >> endKm;
		cout << "is " << endKm << " Correct input?" << endl;
		cout << "Press 1: to continue and anything else to try again." << endl;
	} while (optionEd != 1);
}

int Odometer::startValue() {

	return 0;
}

ostream & operator<<(ostream out, const Odometer & o)
{
	out << "Kilometers at the start of the trip: " << o.getStartKm << "km" << endl;
	out << "Kilometers at the end of the trip: " << o.getEndKm << "km" << endl;
}
