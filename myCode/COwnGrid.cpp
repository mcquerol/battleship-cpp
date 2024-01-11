#include "COwnGrid.h"
#include "CGridPosition.h"  // Include the appropriate header file for CGridPosition
#include "COpponentGrid.h"  // Include the appropriate header file for COpponentGrid

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
    int bowRow = bow.getRow() - 'A';
    int sternRow = stern.getRow() - 'A';

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
            for (int col = bow.getColumn()-1; col <= stern.getColumn()-1; ++col) {
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

const std::set<CGridPosition> COwnGrid::getShotAt() const
{
    return shotAt;
}

CShots::Impact COwnGrid::takeBlow(const CShots& shot) {
    const CGridPosition& position = shot.getTargetPosition();

    // Check if the position has already been shot
    if (hasBeenShot(position)) {
        // If yes, return the impact (NONE, as the position has already been shot)
        return CShots::Impact::NONE;
    }

    // Convert row from letter to numeric value (adjust for 0-based indexing)
    int row = position.getRow();
    int col = position.getColumn();

    // Iterate over all ships to check if the target position is a member of the occupied positions
    for (const auto& ship : ships) {
        const std::set<CGridPosition>& occupiedArea = ship.occupiedArea();
        if (occupiedArea.find(position) != occupiedArea.end()) {
            // If a ship is hit and it's the final hit, mark the ship as sunk in the grid
            if (isFinalHit(ship, position)) {
                for (const auto& pos : occupiedArea) {
                    int row = pos.getRow() - 'A';
                    int col = pos.getColumn() - 1;
                    grid[row][col] = 'X';  // Use 'X' to represent a sunken ship
                }
                // Update shotAt set and return SUNKEN
                shotAt.insert(position);
                return CShots::Impact::SUNKEN;
            } else {
                // If the target position is part of the occupied area, mark it as a hit
                grid[row][col] = '^';  // Use '^' to represent a hit
                // Update shotAt set and return HIT
                shotAt.insert(position);
                return CShots::Impact::HIT;
            }
        }
        // If the shot doesn't hit a ship
        // Mark the miss in the grid
        grid[row][col] = 'O';  //// Use 'O' to represent a miss
        //does not go into the big if
        cout << row << col << endl;
        // Update shotAt set and return MISS
        shotAt.insert(position);
    }
    return CShots::Impact::NONE;
}

bool COwnGrid::isFinalHit(const CShip& ship, const CGridPosition& currentHit) const {
    // Get all taken blows before the current one
    const auto& previousHits = shotAt;

    // Calculate the intersection of the ship's occupied fields and previous hits
    std::set<CGridPosition> intersection;
    const std::set<CGridPosition>& occupiedArea = ship.occupiedArea();

    std::set_intersection(
        occupiedArea.begin(), occupiedArea.end(),
        previousHits.begin(), previousHits.end(),
        std::inserter(intersection, intersection.begin())
    );

    // Check if the size of the intersection is one less than the length of the ship
    return (intersection.size() == ship.length() - 1);
}

 //Helper method to check if a position has been shot
bool COwnGrid::hasBeenShot(const CGridPosition& position) const
{
	return (shotAt.find(position) != shotAt.end());
}
