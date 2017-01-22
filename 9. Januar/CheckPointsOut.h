#pragma once


#include <iostream>
#include <string>

class CheckPoints {
	int numCheckPoints = 0;
	int **checkPointsDist = nullptr;
	std::string* checkPointNames = nullptr;
public:
	CheckPoints() = default;
	CheckPoints(int);
	void read(std::istream&);
	~CheckPoints();
	int getDist(int, int) const;
	std::string* getCheckPointNames();
	int getNumCheckPoints();
};
