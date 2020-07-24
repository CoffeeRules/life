#pragma once

#include <map>
#include <set>

#include "InputReader.h"
#include "LifeCell.h"

//represents the cells in a 2d grid
class LifeGrid
{
public:
	LifeGrid( const char* filename, int maxSteps );

	bool Step();

	void AddLifeCell(LifeCell LE);

	static const int_fast64_t cGridMin = INT_FAST64_MIN;
	static const int_fast64_t cGridMax = INT_FAST64_MAX;

private:
	void ProcessNeighbors();
	void PurgeDead();
	void SpawnNewLiving();

	int m_stepCount = 0;
	InputReader m_reader;
	std::set<LifeCell> m_livingCells;	//set of all currently living cell.

	std::map<LifeCell, int> m_neighborCells;  //map of each cell that is neighbors with at least one living cell

	int m_maxSteps = 1000;
};