#pragma once
#ifndef TRIPSPECIFICS_H
#define TRIPSPECIFICS_H
#include <iostream>


class TripSpecifics {
	//friend ostream& operator <<(ostream& out, const TripSpecifics &r);
public:
	TripSpecifics(string startLocation0 = "", string endLocation0 = "", int startTime0 = 0, int endTime0 = 0)
		: startLocation(startLocation0), endLocation(endLocation0), startTime(startTime0), endTime(endTime0) {
	}
	void setStartLocation();
	void setDestination();
	void setStartTime();
	void setEndTime();
	string getStartLocation() const;
	string getDestination() const;
	int getStartTime() const;
	int getEndTime() const;
private:
	string startLocation;
	string endLocation;
	int startTime;
	int endTime;
	static int countTS;
	static int leaveLenght;
	static int destinationLenght;
	static int timeLenght;
};


#endif
