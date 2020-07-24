#include "InputReader.h"

#include <string>
#include <fstream>
#include <iostream>

#include "LifeGrid.h"
#include "LifeCell.h"

bool InputReader::Open(const char* filename )
{
	if (filename == "")
	{
		m_infile.open(m_filename);
	}
	else
	{
		m_infile.open(filename);
	}

	if (!m_infile.good())
	{
		std::cout << "Failed to open either filename (" << filename << ") or default (" << m_filename << ")" << std::endl;
		return false;
	}

	return true;
}

void InputReader::Read( LifeGrid* pLifeGrid )
{
	//Expecting each line to look like:
	//"(0, 1)"

	while (m_infile.peek() == '(')
	{
		LifeCell cell;
		cell.Read(m_infile);

		pLifeGrid->AddLifeCell(cell);
	}
}
