#pragma once
#ifndef TRIPHANDLING_H
#define TRIPHANDLING_H
#include "Date.h"
#include "Odometer.h"
#include "TripSpecifics.h"
#include "Gas.h"

class TripHandling : public Date, public Odometer, public TripSpecifics , public Gas{
	
public:
	TripHandling(int day0 = 0, int month0 = 0, int year0 = 0, int startKm0 = 0, int endKm0 = 0, 
		string startLocation0 = "", string endLocation0 = "", double litre0 = 0.0, double consumption0 = 0.0);
	TripHandling(const TripHandling &th);
	void initialize();
	void saveMainFile();
	void saveDateDistTime();
	void findFromFile();
	void deleteFile();
private:
	
};
ostream &operator<<(ostream &out, const TripHandling &input);
ostream &operator<<(ostream &out, const Date &date0);
ostream &operator<<(ostream &out, const Odometer &o);
ostream &operator<<(ostream &out, const TripSpecifics &ts);
ostream &operator<<(ostream &out, const Gas &g);


#endif // !SAVETRIP_H