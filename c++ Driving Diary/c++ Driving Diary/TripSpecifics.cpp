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
	cout << "where are you leaving from?: ";
	cin >> startLocation;
	cout << "You're leaving from: " << startLocation << endl;
	cout << "Press 1: to continue and anything else to try again." << endl;
}

void TripSpecifics::setDestination()
{
	cout << "where are you going to?: ";
	cin >> endLocation;
	cout << "You're going to: " << endLocation << endl;
	cout << "Press 1: to continue and anything else to try again." << endl;
}

void TripSpecifics::setStartTime()
{
	cout << "Give the leaving time in format XXXX" << endl;
	cin >> startTime;
	cout << "Leaving time is: " << startTime << endl;
	cout << "Press 1: to continue and anything else to try again." << endl;
}

void TripSpecifics::setEndTime()
{
	cout << "Give the leaving time in format XXXX" << endl;
	cin >> endTime;
	cout << "Leaving time is: " << endTime << endl;
	cout << "Press 1: to continue and anything else to try again." << endl;
}

string TripSpecifics::getStartLocation() const
{
	return startLocation;
}

string TripSpecifics::getDestination() const
{
	return endLocation;
}

int TripSpecifics::getStartTime() const
{
	return startTime;
}

int TripSpecifics::getEndTime() const
{
	return endTime;
}
