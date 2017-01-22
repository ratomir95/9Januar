// Sva imena funkcija su logicna, tako da komentarisanje koda nije potrebno!!!

#include "CheckPointsIn.h"

CheckPoints::CheckPoints(int numCheckPoints) : numCheckPoints(numCheckPoints) { }

void CheckPoints::read(std::istream &iStr) {
	checkPointsDist = new int *[numCheckPoints];
	for (int i = 0; i < numCheckPoints; i++)
		checkPointsDist[i] = new int[numCheckPoints];
	for (int i = 0; i < numCheckPoints; i++)
		for (int j = 0; j < numCheckPoints; j++)
			iStr >> checkPointsDist[i][j];
	checkPointNames = new std::string[numCheckPoints];
	for (int i = 0; i < numCheckPoints; i++) {
		//getline(iStr, checkPointNames[i], '\n');
		//std::cout << checkPointNames[i] << std::endl;
		//if(checkPointNames[i].length() == 0)i--;
		iStr >> checkPointNames[i];
	}
}

CheckPoints::~CheckPoints() {
	for (int i = 0; i < numCheckPoints; i++)
		delete[] checkPointsDist[i];
	delete[] checkPointsDist;
	delete[] checkPointNames;
}

int CheckPoints::getDist(int i, int j) const {
	return checkPointsDist[i][j];
}

std::string *CheckPoints::getCheckPointNames() {
	return checkPointNames;
}

int CheckPoints::getNumCheckPoints() {
	return numCheckPoints;
}