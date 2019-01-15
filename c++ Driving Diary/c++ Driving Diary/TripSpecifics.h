#pragma once
#ifndef TRIPSPECIFICS_H
#define TRIPSPECIFICS_H
#include <iostream>


class TripSpecifics {
	//friend ostream& operator <<(ostream& out, const TripSpecifics &r);
public:
	//constructor
	TripSpecifics(string startLocation0 = "", string endLocation0 = "")
		: startLocation(startLocation0), endLocation(endLocation0){
	}
	//copy constructor
	TripSpecifics(const TripSpecifics &ts) : startLocation(ts.startLocation), endLocation(ts.endLocation) {

	}
	void setStartLocation();
	void setDestination();
	void resetTripSpecifics();
	string getStartLocation() const;
	string getDestination() const;
private:
	string startLocation;
	string endLocation;
};


#endif
