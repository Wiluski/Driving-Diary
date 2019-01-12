#include "pch.h"
#include <iostream>
using namespace std;
#include "Gas.h"

Gas::Gas(double litre0, double consumption0, int startKm0, int endKm0) : litre(litre0), consumption(consumption0),
getODistance(new Odometer(startKm0, endKm0))
{
}

void Gas::setGas()
{
	int optionSG = 0;
	do {
		cout << "did you buy gas?" << endl;
		cout << "1. Yes, 2. No" << endl;
		cin >> optionSG;
		if (optionSG == 1) {
			cout << "Give in litres xx.xxl" << endl;
			cout << "How much gas did you buy?: " << endl;
			cin >> litre;
			if (cin.get() != 'l') {
				cout << "\n expected 'l'";
				optionSG = 0;
			}
		litre = litre - ((getODistance->getDistance() / 100) * consumption);
		}
	} while (optionSG != 1 && optionSG != 2);
}

void Gas::setConsumption()
{
	int optionSCK = 0;
	cout << "do you want to give average consumption of gas per 100km?" << endl;
	cout << "else 9l/100km will be used" << endl;
	do {
		cout << "1. Yes 2. No" << endl;
		cin >> optionSCK;
		if (optionSCK == 1) {
			cout << "give in litres per 100km, XX.XXl" << endl;
			cin >> consumption;
			if (cin.get() != 'l') {
				cout << "\n expected: l" << endl;
				consumption = 0.0;
				optionSCK = 0;
			}
		}
		else if (optionSCK == 2) {
			consumption = 9.0;
		}
	} while (optionSCK != 1 && optionSCK != 2);
}

void Gas::resetGas()
{
	litre = 0.0;
	consumption = 0.0;
}

double Gas::getGas() const
{
	return litre;
}

double Gas::getConsumption() const
{
	return consumption;
}
