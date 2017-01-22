// Sva imena funkcija su logicna, tako da komentarisanje koda nije potrebno!!!

#include "VehicleTypesIn.h"

VehicleTypes::VehicleTypes(int numVehicleTypes) :numVehicleTypes(numVehicleTypes) {}

void VehicleTypes::read(std::istream& iStr) {
	price = new int[numVehicleTypes];
	vehicleNames = new std::string[numVehicleTypes];
	for (int i = 0; i<numVehicleTypes; i++)
		iStr >> vehicleNames[i] >> price[i];
}
VehicleTypes::~VehicleTypes()
{
	delete[] price;
	delete[] vehicleNames;
}

int VehicleTypes::getPrice(int i) const {
	return price[i];
}

std::string VehicleTypes::getName(int i) const {
	return vehicleNames[i];
}