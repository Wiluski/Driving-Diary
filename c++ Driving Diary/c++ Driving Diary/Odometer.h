#pragma once
#include <iostream>
#include "Exception.h"
#define N 3

class Odometer {
	/*friend ostream &operator<<(ostream &out, const Odometer &r) {
		out << r.km << "km" << endl;
		return out;
	};*/

public:

	Odometer(int startKm0 = 0) : km(startKm0) {
		countO++;
		if (countO >= N)
			throw Exception("error on creating the parameter");
	};

	/*~Odometer() {
		cout << "\n Destructor for the kilometers " << (void*)this << "(" << km << ")" << endl;
	};*/
	const Odometer& operator=(const Odometer &sum) {
		if (this != &sum) {
			km = sum.km;
		}
		return *this;
	};

	Odometer operator+(const Odometer &driveLenght) const {
		Odometer displacement;
		displacement.km = km + displacement.km;
		return displacement;
	};

	void reset() {
		km = 0;
	};

	int getKm() {
		return km;
	};

	static int countO;
private:
	int km;
};
int Odometer::countO = 0;
