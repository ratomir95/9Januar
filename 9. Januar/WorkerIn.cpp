// Sva imena funkcija su logicna, tako da komentarisanje koda nije potrebno!!!

#include <iostream>
#include "WorkerIn.h"

Worker::Worker(std::string username, std::string password, int userType) :username(username), password(password), userType(userType) {}

std::string Worker::getName() const {
	return username;
}

std::string Worker::getPass() const {
	return password;
}

int Worker::getUserType() const {
	return userType;
}

void Worker::printWorker(std::ostream& str) {
	str << username << " " << password << " " << userType << std::endl;
}