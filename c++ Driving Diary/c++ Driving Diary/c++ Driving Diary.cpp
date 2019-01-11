#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <chrono>
using namespace std;
#include "Date.h"
#include "TripSpecifics.h"
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK ,__FILE__, __LINE__)
#define new DBG_NEW
#endif
#endif // _DEBUG

//throw exception
#define N 30


int startValue();

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
		out << "Distance driven in kilometers" << (r.endKm-r.startKm) << "km" << endl;
		return out;
	}
public:
	Odometer(int startKm0 = 0, int endstartKm0 = 0)
		: startKm(startKm0), endKm(endstartKm0) {
		countO++;
		if (countO >= N)
			throw Exception("error on creating the parameter");
	}
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
	int getStartKm() const{
		return startKm;
	}
	int getEndKm() const {
		return endKm;
	}
	static int getEndLenght(){
		return endLenght;
	}

private:
	int startKm;
	int endKm;
	static int countO;
	static int endLenght;
	int startDrive();
	int endDrive();
};
int Odometer::countO = 0;
int Odometer::endLenght = 0;

/*class SaveFile {

public:
	SaveFile(int startKm0 = 0, int endKm0 = 0, string startLocation0 = "", string endLocation0 = "", int startTime0 = 0, int endTime0 = 0) 
		: kilometers(new Odometer(startKm0, endKm0)), trip(new TripSpecifics(startLocation0, endLocation0, startTime0, endTime0)){

	}

private:
	auto_ptr<Odometer> kilometers;
	auto_ptr<TripSpecifics> trip;
	static int tripCount;
};
int SaveFile::tripCount = 0;*/


int Odometer::startDrive() {
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

int Odometer::endDrive()
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
	ifstream readStartValue;
	readStartValue.open("startingKm.txt");
	string loc1 = "Kilometers at the end: ";
	string getStartValue = "";
	
	readStartValue.close();
	return 0;
}

/*void saveTripInformation(const Odometer &km, const TripSpecifics &info) {
	
}*/

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
	//system("Pause");
	return EXIT_SUCCESS;
}