#pragma once
#ifndef GAS_H
#define GAS_H
#include "Odometer.h"

class Gas{
	
public:
	Gas(double litre0 = 0.0, double consumption0 = 0.0);
	Gas(const Gas &g);
	void setGas();
	void setConsumption();
	void resetGas();
	double getGas() const;
	double getConsumption() const;
private:
	double litre;
	double consumption;
};


#endif