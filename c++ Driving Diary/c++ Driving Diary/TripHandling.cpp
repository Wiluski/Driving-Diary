#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
#include "TripHandling.h"

TripHandling::TripHandling(int day0, int month0, int year0, int startKm0, int endKm0, 
	string startLocation0, string endLocation0, double litre0, double consumption0) : 
	Date(day0, month0, year0), Odometer(startKm0, endKm0), TripSpecifics(startLocation0, endLocation0),
	Gas(litre0, consumption0)
{
}

void TripHandling::initialize()
{
	resetOdometer();
	resetDate();
	resetGas();
	resetTripSpecifics();
}

ostream & operator<<(ostream & out, const Date & date0)
{
	out << date0.getDay() << "/" << date0.getMonth() << "/" << date0.getYear() << endl;
	return out;
}

ostream & operator<<(ostream &out, const Odometer & o)
{
	out << "Kilometers at the start of the trip: " << o.getStartKm() << "km" << endl;
	out << "Kilometers at the end of the trip: " << o.getEndKm() << "km" << endl;
	out << "Distance driven: " << o.getDistance() << "km" << endl;
	return out;
}

ostream & operator<<(ostream & out, const TripSpecifics & ts)
{
	out << "Trip from (" << ts.getStartLocation() << ")" << " to (" << ts.getDestination() << ")" << endl;
	return out;
}

ostream & operator<<(ostream & out, const Gas & g)
{
	out << "Gas consumption during the trip was: " << g.getConsumption() << "l/100km" << endl;
	out << "Meaning you used :" << g.getGas() << "litres" << endl;
	
	return out;
}

/*ostream & operator<<(ostream & out, const TripHandling & input)
{
	
}*/
