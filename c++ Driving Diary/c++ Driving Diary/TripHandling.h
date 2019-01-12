#pragma once
#ifndef TRIPHANDLING_H
#define TRIPHANDLING_H
#include "Date.h"
#include "Odometer.h"
#include "TripSpecifics.h"

class TripHandling : public Date, public Odometer, public TripSpecifics {
	
public:
	TripHandling(int day0 = 0, int month0 = 0, int year0 = 0, int startKm0 = 0, int endKm0 = 0
		, string startLocation0 = "", string endLocation0 = "", int startTime0 = 0, int endTime0 = 0);
	int getDistance();
	void saveMainFile();
	void saveDateDistTime();
	void findFromFile();
	void deleteFile();
private:
	
};
ostream &operator<<(ostream &out, const TripHandling &input);


#endif // !SAVETRIP_H
