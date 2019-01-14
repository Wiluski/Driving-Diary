#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;
#include "TripHandling.h"

const string TripHandling::distLoc = "distLoc.txt";
const string TripHandling::files = "filenames.txt";
const string TripHandling::saveKilometers = "kilometers.txt";
int TripHandling::menuOption = 0;

TripHandling::TripHandling(string fileName0, int day0, int month0, int year0, int startKm0, int endKm0, 
	string startLocation0, string endLocation0, double litre0, double consumption0) : 
	fileName(fileName0), Date(day0, month0, year0), Odometer(startKm0, endKm0), TripSpecifics(startLocation0, endLocation0),
	Gas(litre0, consumption0)
{
}

void TripHandling::initialize()
{
	resetFileName();
	resetOdometer();
	resetDate();
	resetGas();
	resetTripSpecifics();
}

void TripHandling::saveMainFile(const TripHandling &save)
{
	if (checkSave() == 0) {
		cout << "nothing to save" << endl;
	}
	else {
		helpSave();
		ofstream mainFile(fileName, ios_base::app);
		mainFile << save;
		mainFile.close();
	}
}

void TripHandling::findFromFile()
{

	cout << "1. check by file name" << endl;
	cout << "2. check by kilometers to see which locations are in specific range" << endl;
	cout << "3. to return to main menu" << endl;
	int optionF = 0;
	do {
		cout << "choose: ";
		cin >> optionF;
		if (optionF == 1) {
			helpFind1();
		}
	} while (optionF != 1 && optionF != 2 && optionF != 3);
}

void TripHandling::resetFileName()
{
	fileName.clear();
}

void TripHandling::deleteFile()
{
	ifstream getFileName(files);
	ifstream tmp("tmp.txt");
	string read;
	if (!getFileName.is_open()) {
		cout << "No trips saved" << endl;
	}
	else {
		resetFileName();
		cout << "file names:" << endl;
		cout << getFileName.rdbuf();
		cout << "\n which do you want to remove?:";
		cin >> fileName;
		if (remove(fileName.c_str()) != 0) {
			perror("error deleting file, returning to main menu");
		}
		else {
			while (getline(getFileName, read)) {
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

int TripHandling::checkSave() const
{
	if (getDay() == 0 && getEndKm() == 0 && getDestination().length() == 0) {
		return 0;
	}
	else if(getDistance() != 0 && getStartLocation().length() != 0){
		ofstream distLocFile(distLoc, ios_base::app);
		distLocFile << getStartLocation() << " to " << getDestination() << endl;
		distLocFile << getDistance() << "km" << endl;
		distLocFile.close();
		return 1;
	}
	else {
		return 2;
	}
}

void TripHandling::helpSave()
{
	ofstream fileNames;
	ofstream kilometers;
	int check = 0;
	do {
		cout << "Give trip a name *******.txt:" << endl;
		cin >> fileName;
		cout << "file name is: " << fileName << endl;
		cout << "press 1. to continue or anything else give another name: " << endl;
		cin >> check;

	} while (check != 1);
	fileNames.open(files, ofstream::app);
	kilometers.open(saveKilometers, ofstream::app);
	fileNames << fileName << endl;
	if (getEndKm() != 0) {
		kilometers << "Kilometers at the end of the last trip: " << getEndKm() << "km" << endl;
	}
	fileNames.close();
}

void TripHandling::helpFind1()
{
	ifstream getFileName(files);
	if (!getFileName.is_open()) {
		cout << "No trips saved" << endl;
	}
	else {
		resetFileName();
		cout << "file names:" << endl;
		cout << getFileName.rdbuf();
		cout << "\nGive file name: " << endl;
		cin >> fileName;
		ifstream setFile(fileName);
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


ostream & operator<<(ostream & out, const Date & date0)
{
	if ((date0.getDay() && date0.getMonth() && date0.getYear()) != 0) {
		out << date0.getDay() << "/" << date0.getMonth() << "/" << date0.getYear() << endl;
	}
	return out;
}

ostream & operator<<(ostream &out, const Odometer & o)
{
	if (o.getEndKm() != 0) {
		out << "Kilometers at the start of the trip: " << o.getStartKm() << "km" << endl;
		out << "Kilometers at the end of the trip: " << o.getEndKm() << "km" << endl;
		out << "Distance driven: " << o.getDistance() << "km" << endl;
	}
	return out;
}

ostream & operator<<(ostream & out, const TripSpecifics & ts)
{
	if (ts.getDestination().length() != 0 && ts.getStartLocation().length() != 0) {
		out << "Trip from (" << ts.getStartLocation() << ")" << " to (" << ts.getDestination() << ")" << endl;
	}
	return out;
}


ostream & operator<<(ostream & out, const TripHandling & input)
{
	out << (Date)input << (TripSpecifics)input << (Odometer)input;
	if (input.Odometer::getDistance() != 0) {
		out << "Gas consumption during the trip was: " << input.getConsumption() << "l/100km" << endl;
		out << "Meaning you used:" << input.getGas() << "litres" << endl;
	}
	return out;
}
