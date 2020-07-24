// life.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <sstream>

#include "LifeGrid.h"

int main(int argc, char *argv[])
{
	//std::cout << "Beginning of Life!\n";

	if ( argc > 3)
	{
		std::cerr << "expected usage: Life [filename.txt] [Generations]" << std::endl;
		std::cerr << "eg: life.exe ..\\..\\input\\acorn.txt 500" << std::endl;
		return -1;
	}

	const char* filename = "";
	if (argc >= 2)
	{
		//set an optional filename to use.
		filename = argv[1];
	}

	int maxSteps = -1;
	if (argc >= 3)
	{
		//set an optional max number of generations to run.
		std::istringstream ss(argv[2]);
		if (!(ss >> maxSteps)) 
		{
			std::cerr << "Invalid number: " << argv[2] << std::endl;
		}
	}

	LifeGrid grid( filename, maxSteps );

	while (grid.Step())
		continue;

	return 0;
}
