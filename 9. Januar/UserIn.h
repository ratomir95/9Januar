#pragma once
#include <string>
#include <ctime>
#include "CheckPointsIn.h"
#include "VehicleTypesIn.h"

#define maxSpeed 130

class User {
	std::string id;
	std::time_t inTime;
	std::time_t outTime;
	int inCheckPointId;
	int vehicleTypeId;
	const CheckPoints* checkPoints;
	const VehicleTypes* vehicleTypes;
public:
	User(std::string, std::time_t, int, int, const CheckPoints*, const VehicleTypes*);
	std::string getId();
	std::time_t getInTime();
	std::time_t getOutTime();
	void setInTime(std::time_t);
	double getPrice(int);
	double isOutOfSpeedLimit(int) const;
};