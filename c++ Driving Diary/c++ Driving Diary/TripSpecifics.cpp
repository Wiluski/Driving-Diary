#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
#include "TripSpecifics.h"

/*ostream & operator<<(ostream & out, const TripSpecifics & r)
{
	out << "Start location: " << r.startLocation << endl;
	out << "Start time: " << r.startTime << endl;
	out << "End location: " << r.endLocation << endl;
	out << "End time: " << r.endTime << endl;
	return out;
}*/

void TripSpecifics::setStartLocation()
{
	int optionSL = 0;
	do {
		cout << "where are you leaving from?: ";
		cin >> startLocation;
		cout << "You're leaving from: " << startLocation << endl;
		cout << "Press 1: to continue and anything else to try again." << endl;
		cin >> optionSL;
	} while (optionSL != 1);
}

void TripSpecifics::setDestination()
{
	int optionSD = 0;
	do {
		cout << "where are you going to?: ";
		cin >> endLocation;
		cout << "You're going to: " << endLocation << endl;
		cout << "Press 1: to continue and anything else to try again." << endl;
		cin >> optionSD;
	} while (optionSD != 1);
}

void TripSpecifics::resetTripSpecifics()
{
	startLocation.clear();
	endLocation.clear();
}


string TripSpecifics::getStartLocation() const
{
	return startLocation;
}

string TripSpecifics::getDestination() const
{
	return endLocation;
}