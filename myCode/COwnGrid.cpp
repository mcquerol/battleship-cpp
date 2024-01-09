#include "COwnGrid.h"

using namespace std;


/** COwnGrid constructor
 *
 *  COwnGrid constructor that takes the own grid size
 */
COwnGrid::COwnGrid(int rows, int columns) : rows(rows), columns(columns) {}

/** COwnGrid::getRows
 *
 * return the rows
 */
int COwnGrid::getRows() const
{
	return this->rows;
}

/** COwnGrid::getColumns
 *
 * return the columns
 */
int COwnGrid::getColumns() const
{
	return this->columns;
}

/** COwnGrid::placeShip
 *
 * place a ship in the grid
 */
bool COwnGrid::placeShip(const CShip& ship)
{

	if(ship.isValid())
	{
		ships.push_back(ship);
		return true;
	}
	return false;

}

/** COwnGrid::getShips
 * a vector which contains the coordinates of different ships
 * on the own grid
 */
const std::vector<CShip> COwnGrid::getShips() const
{
	return ships;
}
