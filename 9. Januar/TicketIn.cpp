// Sva imena funkcija su logicna, tako da komentarisanje koda nije potrebno!!!

#include "TicketIn.h"
#include <string>
Ticket::Ticket(int id, int vehicleType, int inCheckPoint, std::string inCheckPointName, long t) : id(id), vehicleType(
	vehicleType), inCheckPoint(inCheckPoint), inTime(inTime), inCheckPointName(inCheckPointName) {
	if (t == -1) {
		time_t now = time(NULL);
		strftime(inTimeStr, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));
		inTime = time(&now);
	}
	else
	{
		inTime = t;
	}
}

void Ticket::printTicket(std::ostream &str) {
	str << "===========================================" << std::endl;
	str << "ID: " << id << std::endl;
	str << "TipVozila: " << vehicleType + 1 << std::endl;
	str << "Ulaz: " << inCheckPointName << std::endl;
	str << "Vrijeme: " << inTimeStr << std::endl;
	str << "===========================================" << std::endl;
}

void Ticket::saveTicket(std::ostream &str) {
	str << id << " " << vehicleType << " " << inCheckPoint << " " << inTime << std::endl;
}

int Ticket::getId() {
	return id;
}

int Ticket::getCheckPoint() {
	return inCheckPoint;
}

int Ticket::getVehicleType() {
	return vehicleType;
}

long Ticket::getTime() {
	return inTime;
}

std::string Ticket::getInTimeStr() {
	return inTimeStr;
}
