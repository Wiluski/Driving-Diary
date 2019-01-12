#pragma once
#ifndef ODOMETER_H
#define ODOMETER_H
#include <iostream>

class Odometer {
	/*friend ostream &operator<<(ostream &out, const Odometer &r) {
		out << "Kilometers at the start: " << r.startKm << "km" << endl;
		out << "Kilometers at the end: " << r.endKm << "km" << endl;
		out << "Distance driven in kilometers" << (r.endKm-r.startKm) << "km" << endl;
		return out;
	}*/
public:
	Odometer(int startKm0 = 0, int endstartKm0 = 0)
		: startKm(startKm0), endKm(endstartKm0) {
	}
	void resetOdometer();
	void setStartKm();
	void setEndKm();
	int getDistance() const;
	int getStartKm() const {
		return startKm;
	}
	int getEndKm() const {
		return endKm;
	}

private:
	int startKm;
	int endKm;
	int startValue();
};

#endif