#pragma once


#include <ctime>
#include <ostream>

class Ticket {
	int id = -1;
	int vehicleType;
	int inCheckPoint;
	std::string inCheckPointName;
	long inTime;
public:
	char inTimeStr[25];
	Ticket() = default;
	Ticket(int, int, int, std::string, long = -1);
	void printTicket(std::ostream&);
	void saveTicket(std::ostream&);
	int getId();
	int getCheckPoint();
	int getVehicleType();
	long getTime();
	std::string getInTimeStr();
};