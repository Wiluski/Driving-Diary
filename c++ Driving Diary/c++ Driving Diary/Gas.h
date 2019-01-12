#pragma once
#ifndef GAS_H
#define GAS_H
#include "Odometer.h"

class Gas{
	
public:
	Gas(double litre0 = 0.0, double consumption0 = 0.0, int startKm0 = 0, int endKm0 = 0);
	void setGas();
	void setConsumption();
	void resetGas();
	double getGas() const;
	double getConsumption() const;
private:
	double litre;
	double consumption;
	auto_ptr<Odometer> getODistance;
};


#endif