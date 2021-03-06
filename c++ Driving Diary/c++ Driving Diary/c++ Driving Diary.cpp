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
//class to check memory leaks
class Exception {
public:
	Exception(const char *explanation0) { explanation = explanation0; }
	const char *what() const { return explanation; }
private:
	const char *explanation;
};

//menu function for the program
void menu() {
	//creates a pointer to "TripHandling" class which uses all of the classes
	unique_ptr<TripHandling> trip(new TripHandling);
	cout << "Welcome" << endl;
	//gives options for user to use. Uses a static integer from the triphandling class
	while (TripHandling::menuOption != 6) {
		cout << "1. Initialize" << endl;
		cout << "2. Save trip data to disk" << endl;
		cout << "3. Read trip data from disk" << endl;
		cout << "4. Add a new trip" << endl;
		cout << "5. Remove a trip" << endl;
		cout << "6. Exit" << endl;
		cout << "choose: " << endl;
		//asks the user input
		cin >> TripHandling::menuOption;
		switch (TripHandling::menuOption) {
		default:
			//if the value is incorrect return an error message
			cout << "fault entry" << endl;
			break;
		case 1:
			//clears all the trip information
			trip->initialize();
			break;
		case 2:
			//saves the trip information to a file and then clears it from the program
			trip->saveMainFile(*trip);
			trip->initialize();
			break;
		case 3:
			//gets a report from a file
			trip->findFromFile();
			break;
		case 4:
			//clears possibly existing data and then uses the functions for setting the different information for a trip
			trip->initialize();
			trip->setDate();
			trip->setStartLocation();
			trip->setDestination();
			trip->setStartKm();
			trip->setEndKm();
			trip->setConsumption();
			trip->setGas();
			//prints a report at the end of the case
			cout << "printing report" << endl;
			cout << *trip;
			system("Pause");
			//gives the user a choice to save their trip immidiately
			while (TripHandling::saveOption != 1 && TripHandling::saveOption != 2) {
				cout << "do you want to save now?" << endl;
				cout << "1.Yes 2.No  : ";
				cin >> TripHandling::saveOption;
				if (TripHandling::saveOption == 1) {
					//opens the save function and initializes data after
					trip->saveMainFile(*trip);
					trip->initialize();
				}
			}
			break;
		case 5:
			//deletes a trip (file)
			trip->deleteFile();
			break;
		case 6:
			//exits the program
			cout << "exiting" << endl;
			break;
		}
	}
}


int main()
{
	menu();
	return EXIT_SUCCESS;
}