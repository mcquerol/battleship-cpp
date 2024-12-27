#include "OpponentGrid.h"
#include "Ship.h"
#include <vector>

OpponentGrid::OpponentGrid(int rows, int columns) : rows(rows), columns(columns)
{
}

int OpponentGrid::getRows() const
{
	return rows;
}

int OpponentGrid::getColumns() const
{
	return columns;
}

bool OpponentGrid::placeShip(const Ship &ship)
{
	sunkenShips.push_back(ship);
	return true;
}

const std::vector<Ship> OpponentGrid::getSunkenShips() const
{
	return sunkenShips;
}
