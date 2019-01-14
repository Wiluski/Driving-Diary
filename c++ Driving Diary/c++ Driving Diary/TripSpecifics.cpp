#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
#include "TripSpecifics.h"

//sets the location where are left
void TripSpecifics::setStartLocation()
{
	//helping integer to check the if the user wants to change their input
	int optionSL = 0;
	do {
		//asks the user input for where you are leaving from
		cout << "where are you leaving from?: ";
		cin >> startLocation;
		cout << "You're leaving from: " << startLocation << endl;
		cout << "Press 1: to continue and anything else to try again." << endl;
		cin >> optionSL;
		if (optionSL != 1)
			//clears the input if the user changes their mind
			startLocation.clear();
	} while (optionSL != 1);
}

//same as the leaving location but for destination
void TripSpecifics::setDestination()
{
	int optionSD = 0;
	do {
		cout << "where are you going to?: ";
		cin >> endLocation;
		cout << "You're going to: " << endLocation << endl;
		cout << "Press 1: to continue and anything else to try again." << endl;
		cin >> optionSD;
		if (optionSD != 1)
			endLocation.clear();
	} while (optionSD != 1);
}

//resets the locations 
void TripSpecifics::resetTripSpecifics()
{
	startLocation.clear();
	endLocation.clear();
}

//returns the starting location
string TripSpecifics::getStartLocation() const
{
	return startLocation;
}

//returns the destination
string TripSpecifics::getDestination() const
{
	return endLocation;
}