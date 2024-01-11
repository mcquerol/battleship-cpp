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

	remainingShips.insert(pair<int,int>(5,1)); //carrier
	remainingShips.insert(pair<int,int>(4,2)); //battleship
	remainingShips.insert(pair<int,int>(3,3)); //destroyer
	remainingShips.insert(pair<int,int>(2,4)); //submarine

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
        // Check if the ship touches another ship
        for (const auto& existingShip : ships) {
            const std::set<CGridPosition>& existingOccupiedArea = existingShip.occupiedArea();

            for (const auto& position : existingOccupiedArea) {
                // Check if the position is adjacent to any position of the new ship
                if (std::abs(position.getRow() - bowRow) <= 1 && std::abs(position.getColumn() - bow.getColumn()) <= 1) {
                    return false; // Cannot place the ship, it touches another ship
                }
            }

            // Check if any position of the new ship is adjacent to the existing ship
            for (const auto& position : ship.occupiedArea()) {
                if (std::abs(position.getRow() - existingShip.getBow().getRow() + 1) <= 1 &&
                    std::abs(position.getColumn() - existingShip.getBow().getColumn()) <= 1) {
                    return false; // Cannot place the ship, it touches another ship
                }
            }
        }

        // Check if the ship's occupied positions form a straight line
        const std::set<CGridPosition>& occupiedArea = ship.occupiedArea();
        int commonRow = -1;
        int commonCol = -1;

        for (const auto& position : occupiedArea) {
            if (commonRow == -1 && commonCol == -1) {
                commonRow = position.getRow();
                commonCol = position.getColumn();
            } else {
                if (position.getRow() != commonRow && position.getColumn() != commonCol) {
                    return false; // Cannot place the ship, positions are not in a straight line
                }
            }
        }

        // Place the ship by updating the grid
        for (int row = bowRow; row <= sternRow; ++row) {
            for (int col = bow.getColumn(); col <= stern.getColumn(); ++col) {
                grid[row][col] = '#';
            }
        }

        ships.push_back(ship);
        return true; // Placement successful
    } else {
        return false; // Invalid position, placement failed
    }
}





const std::vector<CShip> COwnGrid::getShips() const
{
    return ships;
}
