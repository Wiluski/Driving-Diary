#include "pch.h"
#include "Odometer.h"
//#include "TripHandling.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//const string Odometer::searchKm = "start of the trip: ";

void Odometer::resetOdometer()
{
	startKm = 0;
	endKm = 0;
}

void Odometer::setStartKm() {
		int optionSK = 0;
		int optionLeave = 0;
		cout << "Choose" << endl;
		cout << "1. Use the previous recording of odometer" << endl;
		cout << "2. Give the (full) kilometers driven" << endl;
		cout << "choose: " << endl;
		cin >> optionSK;
		if (optionSK == 1) {

			cout << "ok" << endl;
		}else if (optionSK == 2) {
			while(true){
			startKm = 0;
			cout << "give kilometers in format *****" << endl;
			cout << "give kilometers: ";
			cin >> startKm;
			cout << "You wrote: " << startKm << endl;
			cout << "press 1. to continue anything else to try again:";
			cin >> optionLeave;
			if (optionLeave == 1)
				break;
			}
		}
}

void Odometer::setEndKm()
{
	int optionEK = 0;
	while (true) {

		cout << "Give end kilometers in format ******" << endl;
		cout << "Give the kilometers: ";
		cin >> endKm;
		cout << "your kilometers: ";
		cout << endKm << "km" << endl;
		cout << "press 1. to continue anything else to try again:";
		cin >> optionEK;
		if (optionEK == 1)
			break;
	}
}

int Odometer::startValue() {
	return 0;
	ifstream getStartValue("kilometers.txt");
	if (!getStartValue.is_open() || getStartValue.peek() == ifstream::traits_type::eof()) {
		getStartValue.close();
		return 0;
	}
	else {
		string tmp, file;
		while (getline(getStartValue, tmp)) {
			file.append(tmp);
			tmp.erase();
		}
		int pos = file.find_last_of("last trip:");
		while (file[pos] != 'k') {
			pos++;
			tmp += file[pos];
		}
		getStartValue.close();
		startKm = stoi(tmp);
	}
}

int Odometer::getDistance() const
{
	return getEndKm() - getStartKm();
}

