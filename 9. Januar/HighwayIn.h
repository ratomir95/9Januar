#pragma once


#include "CheckPointsIn.h"
#include "VehicleTypesIn.h"
#include "WorkerIn.h"
#include <string>
#include <fstream>
#include <list>
#include <vector>

class Highway {
	CheckPoints* checkPoints;
	VehicleTypes* vehicleTypes;
	std::vector<Worker> listWorker;
public:
	Highway(std::string, std::string, std::string);
	CheckPoints& getCheckPoints();
	VehicleTypes& getVehicleTypes();
	std::vector<Worker>& getWorkerList();
	bool isWorkerExist(std::string);
	int isSuccLogin(std::string, std::string);
};
