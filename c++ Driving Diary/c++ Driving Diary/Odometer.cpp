#include "pch.h"
#include "Odometer.h"
//#include "TripHandling.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//resets the values for starting and end kilometers
void Odometer::resetOdometer()
{
	startKm = 0;
	endKm = 0;
}

//function to determine the starting value of odometer
void Odometer::setStartKm() {
		//help integers to check user input
		int optionSK = 0;
		int optionLeave = 0;
		//options to use previous kilometers from trips or to input their own
		cout << "Choose" << endl;
		cout << "1. Use the previous recording of odometer, if there are none, kilometers will be at 0" << endl;
		cout << "2. Give the (full) kilometers driven" << endl;
		cout << "choose: " << endl;
		cin >> optionSK;
		if (optionSK == 1) {
			//uses a help function to determine the value
			startKm = startValue();
		}else if (optionSK == 2) {
			//loops the question of the amount of kilometers at start until correct input is received
			while(true){
			startKm = 0;
			cout << "give kilometers in format *****" << endl;
			cout << "give kilometers: ";
			//reads the value for kilometers at start
			cin >> startKm;
			cout << "You wrote: " << startKm << endl;
			cout << "press 1. to continue anything else to try again:";
			cin >> optionLeave;
			//breaks the loop if correct input is received
			if (optionLeave == 1)
				break;
			}
		}
}

//same as setting the starting value but simpler
void Odometer::setEndKm()
{
	int optionEK = 0;
	while (true) {
		endKm = 0;
		cout << "Give end kilometers in format ******" << endl;
		cout << "Give the kilometers: ";
		//gets the kilometers at the end
		cin >> endKm;
		cout << "your kilometers: ";
		cout << endKm << "km" << endl;
		cout << "press 1. to continue anything else to try again:";
		cin >> optionEK;
		if (optionEK == 1)
			break;
	}
}

//helping function to determine the value at start of the trip
int Odometer::startValue() {
	//opens a file where kilometers from last trips are saved
	ifstream getStartValue("kilometers.txt");
	//help strings and an integer for reading the file 
	string tmp, file;
	int pos;
	//checks if the file is empty and if it exists
	if (!getStartValue.is_open() || getStartValue.peek() == ifstream::traits_type::eof()) {
		//if it doesn't value is returned as 0
		getStartValue.close();
		return 0;
	}
	else {
		//copies the file to a string for easier handling
		while (getline(getStartValue, tmp)) {
			file.append(tmp);
			tmp.erase();
		}
		//gets the position in file where the kilometers are with a search
		//of an sentence which is used to save the kilometers for each trip
		pos = file.find_last_of("last trip:");
		//reads the file from that position to the next letter which is used
		//and saves them to a temporary string
		while (file[pos] != 'k') {
			pos++;
			tmp += file[pos];
		}
		//closes the file and copies the value to starting kilometers
		getStartValue.close();
		return stoi(tmp);
	}
}

//calculates the distance driven and returns the value
int Odometer::getDistance() const
{
	return getEndKm() - getStartKm();
}

