#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <chrono>
#include <sstream>
using namespace std;
#include "Date.h"
#include "TripSpecifics.h"
#include "Odometer.h"
#include "TripHandling.h"
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK ,__FILE__, __LINE__)
#define new DBG_NEW
#endif
#endif // _DEBUG

//throw exception
#define N 30
void menu();

class Exception {
public:
	Exception(const char *explanation0) { explanation = explanation0; }
	const char *what() const { return explanation; }
private:
	const char *explanation;
};

void menu() {
	unique_ptr<TripHandling> trip(new TripHandling);
	cout << "Welcome" << endl;
	while (TripHandling::menuOption != 6) {
		cout << "1. Initialize" << endl;
		cout << "2. Save trip data to disk" << endl;
		cout << "3. Read trip data from disk" << endl;
		cout << "4. Add a new trip" << endl;
		cout << "5. Remove a trip" << endl;
		cout << "6. Exit" << endl;
		cout << "choose: " << endl;
		cin >> TripHandling::menuOption;
		switch (TripHandling::menuOption) {
		default:
			cout << "fault entry" << endl;
			break;
		case 1:
			trip->initialize();
			break;
		case 2:
			trip->saveMainFile(*trip);
			trip->initialize();
			break;
		case 3:
			trip->findFromFile();
			break;
		case 4:
			trip->initialize();
			trip->setDate();
			trip->setStartLocation();
			trip->setDestination();
			trip->setStartKm();
			trip->setEndKm();
			trip->setGas();
			trip->setConsumption();
			cout << "printing report" << endl;
			cout << *trip;
			break;
		case 5:
			trip->deleteFile();
			break;
		}
	}
	cout << "exiting" << endl;
}

int main()
{
	try {
		menu();
	}
	catch (Exception e) {
		cout << "Exeption happened: " << e.what() << endl;
		cout << "Managed" << endl;
	}
	_CrtDumpMemoryLeaks;
	//system("Pause");
	return EXIT_SUCCESS;
}