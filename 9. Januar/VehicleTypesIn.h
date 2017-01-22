#pragma once
#include <string>
#include <istream>

class VehicleTypes {
	int numVehicleTypes = 0;
	int* price = nullptr;
	std::string* vehicleNames = nullptr;
public:
	VehicleTypes() = default;
	VehicleTypes(int);
	void read(std::istream&);
	~VehicleTypes();
	int getPrice(int) const;
	std::string getName(int) const;
};