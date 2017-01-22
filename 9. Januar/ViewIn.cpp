// Sva imena funkcija su logicna, tako da komentarisanje koda nije potrebno!!!

#include "ViewIn.h"
#include "TicketIn.h"
#include <iostream>
#include <Windows.h>
#include <stdio.h>

#define MAXSPEED 130

unsigned int microseconds = 1000;

void View::showMenuScreen() {
	clearScreen();
	showHeader("MENI");
	ostream << "PRIJAVA NA SISTEM [0], KRAJ [1]: ";
	std::string in;
	do {
		istream >> in;
		if (in == "0") {
			showLoginScreen();
		}
		else if (in == "1") {
			showExitScreen();
		}
		else {
			showBadInputScreen();
		}
	} while (in != "0" && in != "1");
}

void View::showLoginScreen() {
	clearScreen();
	showHeader("PRIJAVA NA SISTEM");
	bool succLogin = false;
	do {

		ostream << "KORISNICKO IME:";
		istream >> username;
		bool isWorkerExist = highway->isWorkerExist(username);
		if (isWorkerExist) {
			ostream << "LOZINKA:";
			/*char ch;
			ch = _getch();
			while(ch != 13){//character 13 is enter
			password.push_back(ch);
			ostream << '*';
			ch = _getch();
			}*/
			HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
			DWORD mode = 0;
			GetConsoleMode(hStdin, &mode);
			SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
			istream >> password;
			SetConsoleMode(hStdin, mode/* & (~ENABLE_ECHO_INPUT)*/);
			int type = highway->isSuccLogin(username, password);
			if (type) {
				showWorkerScreen(type);
				succLogin = true;
			}
			else {
				ostream << "POGRESNA LOZINKA!" << std::endl;
			}
		}
		else {
			ostream << "NE POSTOJI KORISNIK SA KORISNICKIM IMENOM " << username << "!" << std::endl;
		}
	} while (!succLogin);
}

void View::showExitScreen() {
	clearScreen();
	showHeader("KRAJ!");
	Sleep(microseconds);
}

void View::showBadInputScreen() {
	ostream << "POGRESAN UNOS! POKUSAJTE PONOVO: ";
}

View::View(std::ostream &ostream, std::istream &istream, Highway *highway) : ostream(ostream), istream(istream),
highway(highway) { }

void View::showWorkerScreen(int type) {
	if (type == 1) {
		showStandardScreen();
	}
	else if (type == 2) {
		showAdminScreen();
	}
}

void View::showStandardScreen() {
clearScreen();
showHeader("IZDAVANJE KARTICA");
ostream << "Mjesto izdavanja kartica: " << std::endl;
for (int i = 0; i < highway->getCheckPoints().getNumCheckPoints(); i++) {
ostream << (highway->getCheckPoints().getCheckPointNames())[i] << " [" << i << "] " << std::endl;
}
int inCheckPoint;
do {
istream >> inCheckPoint;
} while (inCheckPoint < 0 || inCheckPoint >= highway->getCheckPoints().getNumCheckPoints());

std::ofstream ticketsStr("tickets.txt", std::fstream::app);

ostream << "IZDAJ KARTICU [0], ODJAVA [1]:";
std::string str;
do {
istream >> str;
if (str == "0") {
int id;
int type;
ostream << "Broj tablica: ";
istream >> id;
ostream << "Tip vozila (KLASA I [0], KLASA II [1], KLASA III [2], KLASA IV [3]): ";
istream >> type;
if (type < 0 || type > 3) { str = "next"; continue; }
Ticket ticket(id, type, inCheckPoint, highway->getCheckPoints().getCheckPointNames()[inCheckPoint]);
ticket.printTicket(ostream);
{
std::ofstream printTicketStr("ticket" + std::to_string(id) + ".txt");
ticket.printTicket(printTicketStr);
printTicketStr.close();

ticket.saveTicket(ticketsStr);
}
str = "next";
} else if (str == "1") {
showMenuScreen();
}
ostream << "IZDAJ KARTICU [0], ODJAVA [1]:";
} while (str != "0" && str != "1");
}


void View::check(int id, std::ostream &str, Ticket &ticket, std::string inTimeStr, std::string outTimeStr, double price, bool delict) {
	str << "================================================" << std::endl;
	str << "Vrijeme ulaza: " << inTimeStr << std::endl;
	str << "Vrijeme izlaza: " << outTimeStr << std::endl;
	str << "Mjesto ulaza: " << (highway->getCheckPoints().getCheckPointNames())[ticket.getCheckPoint()] << std::endl;
	str << "Mjesto izlaza: " << (highway->getCheckPoints().getCheckPointNames())[id]  << std::endl;
	str << "Tip vozila: " << ticket.getVehicleType() + 1 << std::endl;
	str << "Cijena: " << price << " KM" << std::endl;
	if (delict) {
		str << "Koristili ste èit (JUMPJET = ON), dobili ste 6 zvjezdica, jure vas tenkovi ...." << std::endl << "Dobili ste kaznu za prebrzu voznju!" << std::endl;
	}
	str << "================================================" << std::endl;
}

void View::showAdminScreen() {
	clearScreen();
	showHeader("UPRAVLJANJE SISTEMOM");
	std::string in;
	do {
		ostream << "DODAJ RADNIKA [0], ODJAVA [1]: ";
		istream >> in;
		if (in == "0") {
			std::string name, pass;
			int type;
			ostream << "Korisnicko ime: ";
			istream >> name;
			ostream << "Lozinka: ";
			istream >> pass;
			ostream << "Radnik [0], Administrator [1]: ";
			istream >> type;
			type++;
			{
				std::ofstream updateUsersStr("workers.txt");
				std::vector<Worker> workers = highway->getWorkerList();
				Worker worker(name, pass, type);
				workers.push_back(worker);
				updateUsersStr << workers.size() << std::endl;
				for (Worker &w : workers) {
					w.printWorker(updateUsersStr);
				}
			}
			in = "next";
		}
		else if (in == "1") {
			showMenuScreen();
		}
	} while (in != "0" && in != "1");
}

void View::showHeader(std::string string) {
	/*struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);*/
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, rows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	int width = columns;

	int stringSize = string.size();
	for (int i = 0; i < width; i++)
		ostream << "=";
	ostream << std::endl << "||";
	int startPos = (width - 4) / 2 - stringSize / 2;
	for (int i = 0; i < startPos; i++)
		ostream << " ";
	ostream << string;
	for (int i = startPos + stringSize; i < width - 4; i++)
		ostream << " ";
	ostream << "||" << std::endl;
	for (int i = 0; i < width; i++)
		ostream << "=";
	ostream << std::endl;
}

void View::clearScreen() {
	ostream.clear();
	system("cls");
}