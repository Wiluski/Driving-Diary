#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <chrono>
using namespace std;
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK ,__FILE__, __LINE__)
#define new DBG_NEW
#endif
#endif // _DEBUG

//throw exception
#define N 30

string leave();
string destination();
int leaveClock();
int arrivalClock();
int startDrive();
int endDrive();
int startValue();
void saveStart();

class TripSpecifics {
	friend ostream& operator <<(ostream& out, const TripSpecifics &r) {
		out << "Start location: " << r.startLocation << endl;
		out << "Start time: " << r.startTime << endl;
		out << "End location: " << r.endLocation << endl;
		out << "End time: " << r.endTime << endl;
		return out;
	}
public:
	TripSpecifics(string startLocation0 = "", string endLocation0 = "", int startTime0 = 0, int endTime0 = 0)
		:startLocation(startLocation0), endLocation(endLocation0), startTime(startTime0), endTime(endTime0) {
	}
	void setStartLocation() {
		startLocation = leave();
	}
	void setEndLocation() {
		endLocation = destination();
	}
	void setStartTime() {
		startTime = leaveClock();
	}
	void setEndTime() {
		endTime = arrivalClock();
	}
private:
	string startLocation;
	string endLocation;
	int startTime;
	int endTime;
	static int countTS;
	static int leaveLenght;
	static int destinationLenght;
	static int timeLenght;
};
int TripSpecifics::countTS = 0;
int TripSpecifics::leaveLenght = 0;
int TripSpecifics::destinationLenght = 0;
int TripSpecifics::timeLenght = 4;

class Exception {
public:
	Exception(const char *explanation0) { explanation = explanation0; }
	const char *what() const { return explanation; }
private:
	const char *explanation;
};

class Odometer {
	friend ostream &operator<<(ostream &out, const Odometer &r) {
		out << "Kilometers at the start: " << r.startKm << "km" << endl;
		out << "Kilometers at the end: " << r.endKm << "km" << endl;
		out << "Distance driven in kilometers" << r.distance << "km" << endl;
		return out;
	}
public:
	Odometer(int startKm0 = 0, int endstartKm0 = 0)
		: startKm(startKm0), endKm(endstartKm0) {
		countO++;
		if (countO >= N)
			throw Exception("error on creating the parameter");
	}
	/*~Odometer() {
		cout << "\n Destructor for the kilometers " << (void*)this << "(" << km << ")" << endl;
	}*/
	/*const Odometer& operator=(const Odometer &sum) {
		if (this != &sum) {
			startKm = sum.startKm;
		}
		return *this;
	}

	Odometer operator+(const Odometer &driveLenght) const {
		Odometer displacement;
		displacement.startKm = startKm + displacement.startKm;
		return displacement;
	}*/

	void resetOdometer() {
		startKm = 0;
		endKm = 0;
	}
	void setStartKm() {
		startKm = startDrive();
	}
	void setEndKm() {
		endKm = endDrive();
	}
	int getKm() {
		return startKm;
	}
	int getEndKm() const {
		return endKm;
	}
	int getDistance() const {
		return (endKm - startKm);
	}
	static int getEndLenght(){
		return endLenght;
	}
	static int getDistanceLenght() {
		return distanceLenght;
	}
private:
	int startKm;
	int endKm;
	static int countO;
	static int endLenght;
	static int distanceLenght;
};
int Odometer::countO = 0;
int Odometer::endLenght = 0;
int Odometer::distanceLenght = 0;

string leave()
{
	string from;
	int optionL = 0;
	do {
		cout << "where are you leaving from?: ";
		cin >> from;
		cout << "You're leaving from: " << from << endl;
		cout << "Press 1: to continue and anything else to try again." << endl;
	} while (optionL != 1);
	return from;
}

string destination()
{
	string to;
	int optionD = 0;
	do {
		cout << "where are you going to?: ";
		cin >> to;
		cout << "You're going to: " << to << endl;
		cout << "Press 1: to continue and anything else to try again." << endl;
	} while (optionD != 1);
	return to;
}

int leaveClock()
{
	int leavingTime = 0;
	int optionLc = 0;
	do {
		cout << "Give the leaving time in format XXXX" << endl;
		cin >> leavingTime;
		cout << "Leaving time is: " << leavingTime << endl;
		cout << "Press 1: to continue and anything else to try again." << endl;
	} while (optionLc != 1 || to_string(leavingTime).length() != 4);
	return leavingTime;
}

int arrivalClock()
{
	int arrivalTime = 0;
	int optionAc = 0;
	do {
		cout << "Give the leaving time in format XXXX" << endl;
		cin >> arrivalTime;
		cout << "Leaving time is: " << arrivalTime << endl;
		cout << "Press 1: to continue and anything else to try again." << endl;
	} while (optionAc != 1 || to_string(arrivalTime).length() != 4);
	return arrivalTime;
}

int startDrive() {
	int option1 = 0;
	int option2 = 0;
	int kilometersDriven = 0;
	do {
		cout << "Choose" << endl;
		cout << "1. Use the previous recording of odometer" << endl;
		cout << "2. Give the (full) kilometers driven: ";
		cin >> option1;
		if (option1 == 1) {
			cout << "ok" << endl;
			kilometersDriven = startValue();
			return kilometersDriven;
		}
		else if (option1 == 2) {
			do {
				cout << "give kilometers: ";
				cin >> kilometersDriven;

				cout << "is " << kilometersDriven << " Correct input?" << endl;
				cout << "Press 1: to continue and anything else to try again." << endl;
				cin >> option2;
			} while (option2 != 1 || kilometersDriven < 0);
			return kilometersDriven;
		}
	} while (option1 != 1 || option1 != 2);
}

int endDrive()
{
	int kilometersInDestination = 0;
	int optionEd = 0;
	do {
		cout << "Give the kilometers: ";
		cin >> kilometersInDestination;
		cout << "is " << kilometersInDestination << " Correct input?" << endl;
		cout << "Press 1: to continue and anything else to try again." << endl;
	} while (optionEd != 1);
	return kilometersInDestination;
}

int startValue()
{
	ifstream inputFile("startingKm.txt");
	return 0;
}

void saveStart() {
	ofstream startingKm;
	cout << "do you want to save the value to file?" << endl;
	cout << "1. YES, press anything else for NO" << endl;
	startingKm.open("startingKm.txt");
	startingKm.close();
}

int main()
{
	try {
		
		/*km.setKm();
		cout << km.getKm() << endl;*/
	}
	catch (Exception e) {
		cout << "Exeption happened: " << e.what() << endl;
		cout << "Managed" << endl;
	}
	_CrtDumpMemoryLeaks;
	system("Pause");
	return EXIT_SUCCESS;
}