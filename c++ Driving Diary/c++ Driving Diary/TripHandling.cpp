#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
#include "TripHandling.h"

TripHandling::TripHandling(int day0, int month0, int year0, int startKm0, int endKm0, 
	string startLocation0, string endLocation0, int startTime0, int endTime0) : 
	Date(day0, month0, year0), Odometer(startKm0, endKm0), TripSpecifics(startLocation0, endLocation0, startTime0, endTime0)
{
}

int TripHandling::getDistance()
{
	return getEndKm()-getStartKm();
}

ostream & operator<<(ostream & out, const TripHandling & input)
{
	
}
