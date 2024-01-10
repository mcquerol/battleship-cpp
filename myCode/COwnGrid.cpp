// COwnGrid.cpp

#include "COwnGrid.h"

using namespace std;

COwnGrid::COwnGrid(int rows, int columns) : rows(rows), columns(columns)
{
	//initialize owngrid and opponent grid
	grid = new char*[rows];

	for (int index = 0; index < rows; index++)
	{
		grid[index] = new char[columns];
	}

	//set every element in each grid to ~ (empty)
	for(int row = 0; row < rows; row++)
	{
		for(int col = 0; col < columns; col++)
		{
			grid[row][col] = '~';
		}
	}

}

COwnGrid::~COwnGrid()
{
    for(int index = 0; index < rows; index++)
    {
        delete [] grid[index];
    }
    delete [] grid;
}

int COwnGrid::getRows() const {
    return rows;
}

int COwnGrid::getColumns() const {
    return columns;
}
char** COwnGrid::getGrid() const {
    return grid;
}
bool COwnGrid::placeShip(const CShip& ship) {
    const CGridPosition& bow = ship.getBow();
    const CGridPosition& stern = ship.getStern();

    // Convert row from letter to numeric value
    int bowRow = bow.getRow() - 'A' + 1;
    int sternRow = stern.getRow() - 'A' + 1;

    // Check if the ship can be placed within the boundaries of the grid
    if (ship.isValid()) {
        ships.push_back(ship);
        // Place the ship by updating the grid
        for (int row = bowRow; row <= sternRow; ++row) {
            for (int col = bow.getColumn(); col <= stern.getColumn(); ++col) {
                grid[row][col] = '#';
            }
        }
        return true; // Placement successful
    } else {
        return false; // Invalid position, placement failed
    }
}



bool COwnGrid::placeShipForTesting(const CShip& ship, int testRow, int testCol)
{
    if (ship.isValid())
    {
    	ships.push_back(ship);
        auto shipPositions = ship.occupiedArea();
        for (const auto& position : shipPositions)
        {
            int row = position.getRow() - 1 + testRow;
            int col = position.getColumn() - 1 + testCol;

            // Check if the position is within the bounds of the grid
            if (row >= 0 && row < rows && col >= 0 && col < columns)
            {
                // Update the board's ownGrid with '#' to mark the ship's position
                grid[row][col] = '#';
            }
            else
            {
                // Invalid position, ship cannot be placed
                return false;
            }
        }
        ships.push_back(ship);
        return true;
    }
    else
    {
        return false;
    }
}



const std::vector<CShip> COwnGrid::getShips() const {
    return ships;
}
