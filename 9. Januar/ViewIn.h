#pragma once
#include <iostream>
#include "HighwayIn.h"
#include "TicketIn.h"

#define widthd 50

class View {
	std::ostream& ostream;
	std::istream& istream;
	Highway* highway;
	std::string username, password;
public:
	View(std::ostream&, std::istream&, Highway*);
	void showMenuScreen();
	void showLoginScreen();
	void showExitScreen();
	void showBadInputScreen();
	void showWorkerScreen(int);
	void showStandardScreen();
	void showAdminScreen();
	void showHeader(std::string);
	void clearScreen();
	void check(int, std::ostream&, Ticket&, std::string, std::string, double, bool);
};