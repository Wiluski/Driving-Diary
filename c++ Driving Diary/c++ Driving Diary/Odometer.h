#pragma once
#ifndef ODOMETER_H
#define ODOMETER_H
#include <iostream>

class Odometer {
public:
	//constructor for odometer
	Odometer(int startKm0 = 0, int endstartKm0 = 0)
		: startKm(startKm0), endKm(endstartKm0) {
	}
	Odometer(const Odometer &o) : startKm(o.startKm), endKm(o.endKm) {

	}
	void resetOdometer();
	void setStartKm();
	void setEndKm();
	int getDistance() const;
	//returns the km at start
	int getStartKm() const {
		return startKm;
	}
	//return kilometers at the end
	int getEndKm() const {
		return endKm;
	}

private:
	int startKm;
	int endKm;
	int startValue();
};

#endif