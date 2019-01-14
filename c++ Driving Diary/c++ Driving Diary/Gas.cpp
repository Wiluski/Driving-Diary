#include "pch.h"
#include <iostream>
using namespace std;
#include "Gas.h"

//constructor for gas
Gas::Gas(double litre0, double consumption0, int startKm0, int endKm0) : litre(litre0), consumption(consumption0),
getODistance(new Odometer(startKm0, endKm0))
{
}

//function for determening if gas was bought during trip
void Gas::setGas()
{
	//int for verifying user input
	int optionSG = 0;
	//loops until correct input has been received
	do {
		cout << "did you buy gas?" << endl;
		cout << "1. Yes, 2. No" << endl;
		cin >> optionSG;
		if (optionSG == 1) {
			cout << "Give in litres xx.xxl" << endl;
			cout << "How much gas did you buy?: " << endl;
			//reads the input for litres bought
			cin >> litre;
			//if the input doesn't include l (litres), the loop continues
			if (cin.get() != 'l') {
				cout << "\n expected 'l'\n";
				optionSG = 0;
			}
			//calculates the litres depending on distance and consumption
			//uses the autopointer for Odometer(getODistance) to get the distance
		litre = litre - ((getODistance->getDistance() / 100) * consumption);
		}
	} while (optionSG != 1 && optionSG != 2);
}

//consumption of gas per 100km
//about the same as the function for setGas(), but uses default of 9.0l/100km
void Gas::setConsumption()
{
	int optionSCK = 0;
	do {
		cout << "do you want to give average consumption of gas per 100km?" << endl;
		cout << "else 9l/100km will be used" << endl;
		cout << "1. Yes 2. No" << endl;
		cin >> optionSCK;
		if (optionSCK == 1) {
			cout << "give in litres per 100km, XX.XXl" << endl;
			cin >> consumption;
			if (cin.get() != 'l') {
				cout << "\n expected: l\n" << endl;
				consumption = 0.0;
				optionSCK = 0;
			}
		}
		else if (optionSCK == 2) {
			consumption = 9.0;
		}
	} while (optionSCK != 1 && optionSCK != 2);
}

//resets the values for litre and consumption
void Gas::resetGas()
{
	litre = 0.0;
	consumption = 0.0;
}

//returns the value for gas
double Gas::getGas() const
{
	return litre;
}

//returns the consumption
double Gas::getConsumption() const
{
	return consumption;
}
