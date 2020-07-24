#pragma once

#include <fstream>

class LifeGrid;
//Meant to handle file operations for LifeGrid input file.
class InputReader
{
public: 
	bool Open( const char* filename );

	void Read( LifeGrid* pLifeGrid );

private:
	const char* m_filename = "..\\..\\input\\sample.txt";
	std::ifstream m_infile;
};

