#include "LifeGrid.h"

#include <vector>

LifeGrid::LifeGrid( const char* filename, int maxSteps )
{
	if (maxSteps > 0)
		m_maxSteps = maxSteps;

	m_reader.Open( filename );
	m_reader.Read( this );
}

bool LifeGrid::Step()
{
	++m_stepCount;

	size_t startedLiving = m_livingCells.size();

	//reset our collection of neighbors
	m_neighborCells.clear();

	ProcessNeighbors();
	PurgeDead();
	SpawnNewLiving();

	std::cout << "Current Generation = " << m_stepCount << " Started with = " << startedLiving << " ended with = " << m_livingCells.size() << " cells" << std::endl;

	if (m_stepCount >= LifeGrid::m_maxSteps)
		return false;

	if (m_livingCells.size() == 0)
		return false;

	return true;
}

//Add initial life cells
void LifeGrid::AddLifeCell(LifeCell LE)
{
	m_livingCells.insert(LE);
}

//remove those cells that don't have 2 or 3 neighbors
void LifeGrid::PurgeDead()
{
	std::vector<LifeCell> purgeList;

	for (LifeCell cell : m_livingCells)
	{
		std::vector<LifeCell> neighborList;
		cell.GetNeighbors(neighborList);

		int neighborCount = 0;
		for (LifeCell neighbor : neighborList)
		{
			auto it = m_livingCells.find(neighbor);
			if (it != m_livingCells.end())
			{
				++neighborCount;
			}
		}

		if (neighborCount != 2 && neighborCount != 3)
		{
			purgeList.push_back(cell);
		}
	}

	for (LifeCell removeCell : purgeList)
	{
		m_livingCells.erase(removeCell);
	}
	purgeList.clear();
}

//Generate a count of how many neighbors each cell has
void LifeGrid::ProcessNeighbors()
{
	for (LifeCell cell : m_livingCells )
	{
		std::vector<LifeCell> neighborList;
		cell.GetNeighbors(neighborList);

		for (LifeCell neighbor : neighborList)
		{
			auto it = m_neighborCells.find(neighbor);
			if (it == m_neighborCells.end())
			{
				m_neighborCells.insert({ neighbor, 1 });
			}
			else
			{
				it->second += 1;
			}
		}
	}
}

//find all the neighbor cells with 3 living neighbors and create a new living cell there.
void LifeGrid::SpawnNewLiving()
{
	for (auto entry: m_neighborCells)
	{
		if (entry.second == 3)
		{
			m_livingCells.insert(entry.first);
		}
	}
}