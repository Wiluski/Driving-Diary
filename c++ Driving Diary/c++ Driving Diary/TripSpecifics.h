#pragma once
#ifndef TRIPSPECIFICS_H
#define TRIPSPECIFICS_H
#include <iostream>


class TripSpecifics {
	//friend ostream& operator <<(ostream& out, const TripSpecifics &r);
public:
	TripSpecifics(string startLocation0 = "", string endLocation0 = "")
		: startLocation(startLocation0), endLocation(endLocation0){
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
