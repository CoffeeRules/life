#include "LifeCell.h"

#include <fstream>

#include "LifeGrid.h"

LifeCell::LifeCell() :
	m_row(0),
	m_col(0)
{

}

LifeCell::LifeCell(int_fast64_t row, int_fast64_t col) :
	m_row(row),
	m_col(col)
{

}

//Reads a single row from the input file.
void LifeCell::Read(std::ifstream& instr)
{
	//Needs error handling.

	//each line looks like:
	//"(0, 1)"

	char ch;
	int_fast64_t row, col;
	//       (     0      ,     1      )      extra spaces and new line
	instr >> ch >> row >> ch >> col >> ch >> std::ws;

	m_row = row;
	m_col = col;
}

bool LifeCell::operator<( const LifeCell& other ) const
{
	//ensure that strict weak ordering is adhered to by testing each element in turn.
	if (m_row < other.m_row)
		return true;
	if (other.m_row < m_row)
		return false;

	if (m_col < other.m_col)
		return true;

	return false;
}

//gets a list of the surrounding 8 cells choosing not to wrap around at the edges.
void LifeCell::GetNeighbors( std::vector<LifeCell>& neighborList) const
{
	for (int_fast64_t i(-1); i <= 1; ++i)
	{
		for (int_fast64_t j(-1); j <= 1; ++j)
		{
			if (i == 0 && j == 0)
				continue;

			if (m_row == LifeGrid::cGridMax && i > 0)
				continue;

			if (m_row == LifeGrid::cGridMin && i < 0)
				continue;

			if (m_col == LifeGrid::cGridMax && j > 0)
				continue;

			if (m_col == LifeGrid::cGridMin && j < 0)
				continue;
			
			neighborList.push_back(LifeCell (m_row + i, m_col+ j));
		}
	}
}
