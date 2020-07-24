#pragma once

#include <iostream>
#include <vector>

//represents a cell in the life grid, basically just an x, y coordinate.
class LifeCell
{
public:
	LifeCell();
	LifeCell(int_fast64_t row, int_fast64_t col);
	
	void Read(std::ifstream& instr);

	int_fast64_t Row() const { return m_row; }
	int_fast64_t Col() const { return m_col; }

	bool operator<( const LifeCell& other ) const;

	void GetNeighbors( std::vector<LifeCell>& neighborList) const;

private:
	int_fast64_t m_row;
	int_fast64_t m_col;
};

