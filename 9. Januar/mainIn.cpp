#include <iostream>
#include "HighwayIn.h"
#include "ViewIn.h"

int main() {
	try {
		Highway highway("checkpoints.txt", "vehicletypes.txt", "workers.txt");
		View view(std::cout, std::cin, &highway);
		view.showMenuScreen();
	}
	catch (...)
	{
		std::cout << "Nesto je poslo po zlu, obratite se sistem administratoru ili kupite bolji program" << std::endl;
	}
	return 0;
}