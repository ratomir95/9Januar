// Sva imena funkcija su logicna, tako da komentarisanje koda nije potrebno!!!

#include "HighwayIn.h"

Highway::Highway(std::string checkPointsTxt, std::string vehiclesTypesTxt, std::string workersTxt) {

	std::ifstream iChkPStr(checkPointsTxt.c_str());
	std::ifstream iVehTStr(vehiclesTypesTxt.c_str());
	std::ifstream iWorkersStr(workersTxt.c_str());
	int numCheckPoints, numVehicleTypes, numWorkers;
	iChkPStr >> numCheckPoints;
	iVehTStr >> numVehicleTypes;
	iWorkersStr >> numWorkers;
	checkPoints = new CheckPoints(numCheckPoints);
	vehicleTypes = new VehicleTypes(numVehicleTypes);
	checkPoints->read(iChkPStr);
	vehicleTypes->read(iVehTStr);
	for (int i = 0; i < numWorkers; i++) {
		std::string username;
		std::string password;
		int type;
		iWorkersStr >> username >> password >> type;
		listWorker.push_back(Worker(username, password, type));
	}
}

CheckPoints& Highway::getCheckPoints() {
	return *checkPoints;
}

VehicleTypes& Highway::getVehicleTypes() {
	return *vehicleTypes;
}

std::vector<Worker>& Highway::getWorkerList() {
	return listWorker;
}

bool Highway::isWorkerExist(std::string name) {
	for (Worker& worker : listWorker)
	{
		if (worker.getName() == name)return true;
	}
	return false;
}

int Highway::isSuccLogin(std::string username, std::string pass) {
	for (Worker& worker : listWorker)
	{
		if (worker.getName() == username && worker.getPass() == pass) return worker.getUserType();
	}
	return 0;
}