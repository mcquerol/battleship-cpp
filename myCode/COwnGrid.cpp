// COwnGrid.cpp

#include "COwnGrid.h"

using namespace std;

COwnGrid::COwnGrid(int rows, int columns) : rows(rows), columns(columns) {}

int COwnGrid::getRows() const {
    return rows;
}

int COwnGrid::getColumns() const {
    return columns;
}

bool COwnGrid::placeShip(const CShip& ship) {
    if (ship.isValid()) {
        ships.push_back(new CShip(ship));

        // Now, you can access the board through the const CBoard& parameter
        // For example, if you want to update the grid, you can do something like:
        // board.getOwnGrid().updateGrid();  // Replace this with the actual function you need
        return true;
    } else {
        return false;
    }
}

const std::vector<CShip*>& COwnGrid::getShips() const {
    return ships;
}
