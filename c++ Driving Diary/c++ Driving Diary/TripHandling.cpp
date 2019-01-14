#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;
#include "TripHandling.h"

//names of the files where filenames, distance and location(in progress) and the kilometers at the end of the each trip are saved
const string TripHandling::distLoc = "distLoc.txt";
const string TripHandling::files = "filenames.txt";
const string TripHandling::saveKilometers = "kilometers.txt";
//integer which is utilized in the main menu
int TripHandling::menuOption = 0;

//constructor for the class which saves to files
TripHandling::TripHandling(string fileName0, int day0, int month0, int year0, int startKm0, int endKm0, 
	string startLocation0, string endLocation0, double litre0, double consumption0) : 
	fileName(fileName0), Date(day0, month0, year0), Odometer(startKm0, endKm0), TripSpecifics(startLocation0, endLocation0),
	Gas(litre0, consumption0)
{
}

//copy constructor
TripHandling::TripHandling(const TripHandling & th) : fileName(th.fileName), Date(th), Odometer(th), TripSpecifics(th)
{
}

//clears all the information 
void TripHandling::initialize()
{
	resetFileName();
	resetOdometer();
	resetDate();
	resetGas();
	resetTripSpecifics();
}

//saves a trip to a file
void TripHandling::saveMainFile(const TripHandling &save)
{
	//uses a helping int function to determine if there's some information to save
	if (checkSave() == 0) {
		cout << "nothing to save" << endl;
	}
	else {
		//if the is, uses helping function to determine the name for file
		helpSave();
		//opens the user determined file, and saves the information
		ofstream mainFile(fileName, ios_base::app);
		mainFile << save;
		mainFile.close();
	}
}

//finds a file(trip) and it's contents
void TripHandling::findFromFile()
{

	cout << "1. check by file name" << endl;
	//cout << "2. check by kilometers to see which locations are in specific range" << endl;
	cout << "2. to return to main menu" << endl;
	int optionF = 0;
	//loops till correct input
	do {
		cout << "choose: ";
		cin >> optionF;
		if (optionF == 1) {
			//uses a function to help find a file
			helpFind1();
		}
	} while (optionF != 1 && optionF != 2);
}

//resets the user determined file name
void TripHandling::resetFileName()
{
	fileName.clear();
}

//function to delete a trip
void TripHandling::deleteFile()
{
	//opens file for where trip names are stored and helping temporary file
	//and a helping string for reading contents of a file
	ifstream getFileName(files);
	ifstream tmp("tmp.txt");
	string read;
	//if the file doesn't exist exits function
	if (!getFileName.is_open()) {
		cout << "No trips saved" << endl;
	}
	else {
		//resets the name of the file and asks user input
		resetFileName();
		cout << "file names:" << endl;
		//prints out the names of the trips
		cout << getFileName.rdbuf();
		cout << "\n which do you want to remove?:";
		//reads the user input for removing a trip
		cin >> fileName;
		//if the file doesn't exist the error message is showed
		if (remove(fileName.c_str()) != 0) {
			perror("error deleting file, returning to main menu");
		}
		else {
			//removes the trip from the file where trip names are saved, and the trip file
			while (getline(getFileName, read)) {
				//replaces the contents so that the name of the deleted file is removed
				read.replace(read.find(fileName), fileName.length(), "");
			}
			tmp.close();
			getFileName.close();
			remove(files.c_str());
			rename("tmp.txt", files.c_str());
			puts("succesful deletion");
		}
	}
	tmp.close();
	getFileName.close();
}

//help function to determine if there is something to save
int TripHandling::checkSave() const
{
	//if there's no data written for a trip, returns a 0, to tell the saving function that there's no data to save
	if (getDay() == 0 && getEndKm() == 0 && getDestination().length() == 0) {
		return 0;
	}
	/*else if(getDistance() != 0 && getStartLocation().length() != 0){
		ofstream distLocFile(distLoc, ios_base::app);
		distLocFile << getStartLocation() << " to " << getDestination() << endl;
		distLocFile << getDistance() << "km" << endl;
		distLocFile.close();
		return 1;
	}*/
	else {
		return 1;
	}
}

//helping function for saving a trip
void TripHandling::helpSave()
{
	//files where names of the files and the kilometers at the end of each trip are saved
	ofstream fileNames;
	ofstream kilometers;
	int check = 0;
	//loop for user to change their mind
	do {
		//reads the user input for a name to a trip and saves it to a datamember
		cout << "Give trip a name *******.txt:" << endl;
		cin >> fileName;
		cout << "file name is: " << fileName << endl;
		cout << "press 1. to continue or anything else give another name: " << endl;
		cin >> check;

	} while (check != 1);
	//saves the name of the file and the amount of kilometers if they are accessible
	fileNames.open(files, ofstream::app);
	kilometers.open(saveKilometers, ofstream::app);
	fileNames << fileName << endl;
	if (getEndKm() != 0) {
		kilometers << "Kilometers at the end of the last trip: " << getEndKm() << "km" << endl;
	}
	fileNames.close();
	kilometers.close();
}

//helping function to search for files
void TripHandling::helpFind1()
{
	//checks if there are any trips saved
	ifstream getFileName(files);
	if (!getFileName.is_open()) {
		cout << "No trips saved" << endl;
	}
	else {
		//resets the name for the file
		resetFileName();
		cout << "file names:" << endl;
		//prints out the names of the trips
		cout << getFileName.rdbuf();
		cout << "\nGive file name: " << endl;
		//asks the user input for the file and opens it
		cin >> fileName;
		ifstream setFile(fileName);
		//if the file exists prints out the contents
		if (setFile.is_open()) {
			cout << setFile.rdbuf();
		}
		else {
			cout << "error opening file, returning to main menu" << endl;
		}
		getFileName.close();
		setFile.close();
	}
}

//output operator for date
ostream & operator<<(ostream & out, const Date & date0)
{
	if ((date0.getDay() && date0.getMonth() && date0.getYear()) != 0) {
		out << date0.getDay() << "/" << date0.getMonth() << "/" << date0.getYear() << endl;
	}
	return out;
}

//output operator for Odometer
ostream & operator<<(ostream &out, const Odometer & o)
{
	if (o.getEndKm() != 0) {
		out << "Kilometers at the start of the trip: " << o.getStartKm() << "km" << endl;
		out << "Kilometers at the end of the trip: " << o.getEndKm() << "km" << endl;
		out << "Distance driven: " << o.getDistance() << "km" << endl;
	}
	return out;
}

//output operator for the locations
ostream & operator<<(ostream & out, const TripSpecifics & ts)
{
	if (ts.getDestination().length() != 0 && ts.getStartLocation().length() != 0) {
		out << "Trip from (" << ts.getStartLocation() << ")" << " to (" << ts.getDestination() << ")" << endl;
	}
	return out;
}

//output operator to print all the data
ostream & operator<<(ostream & out, const TripHandling & input)
{
	out << (Date)input << (TripSpecifics)input << (Odometer)input;
	if (input.Odometer::getDistance() != 0) {
		out << "Gas consumption during the trip was: " << input.getConsumption() << "l/100km" << endl;
		out << "Meaning you used:" << input.getGas() << "litres" << endl;
	}
	return out;
}
