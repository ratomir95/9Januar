#pragma once
#include <string>

class Worker {
	std::string username;
	std::string password;
	int userType; //1-standard, 2-admin
public:
	Worker(std::string, std::string, int);
	std::string getName() const;
	std::string getPass() const;
	int getUserType() const;
	void printWorker(std::ostream&);
};
