// Sva imena funkcija su logicna, tako da komentarisanje koda nije potrebno!!!

#include "UserIn.h"
#include "HighwayIn.h"

User::User(std::string id, std::time_t inTime, int inCheckPointId,
	int vehicleTypeId, const CheckPoints* checkPoints, const VehicleTypes* vehicleTypes) :id(id), inTime(inTime),
	inCheckPointId(inCheckPointId),
	vehicleTypeId(vehicleTypeId), checkPoints(checkPoints), vehicleTypes(vehicleTypes) {}


std::string User::getId() {
	return id;
}

std::time_t User::getInTime() {
	return inTime;
}

std::time_t User::getOutTime() {
	return outTime;
}

void User::setInTime(std::time_t outTime) {
	this->outTime = outTime;
}

double User::getPrice(int outCheckPointId) {
	int dist = checkPoints->getDist(inCheckPointId, outCheckPointId);
	int price = vehicleTypes->getPrice(vehicleTypeId);
	return dist * price;
}

double User::isOutOfSpeedLimit(int outCheckPointId) const {
	double dist = checkPoints->getDist(inCheckPointId, outCheckPointId);
	double sec = difftime(inTime, outTime);
	double h = sec / 3600;
	double speed = dist / h;
	return speed > maxSpeed;
}