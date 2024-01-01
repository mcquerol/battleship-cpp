#include "COwnGrid.h"

using namespace std;

/** COwnGrid constructor
 *
 * EMPTY constructor
 */
COwnGrid::COwnGrid()
{

}

/** COwnGrid constructor
 *
 *  COwnGrid constructor that takes the own grid size
 */
COwnGrid::COwnGrid(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;
}

/** COwnGrid::getRows
 *
 * return the rows
 */
int COwnGrid::getRows()
{
	return this->rows;
}

/** COwnGrid::getColumns
 *
 * return the columns
 */
int COwnGrid::getColumns()
{
	return this->columns;
}

/** COwnGrid::placeShip
 *
 * place a ship in the grid
 */
bool COwnGrid::placeShip(const CShip& ship)
{
	this->ships = ship;

	CShip s(this->ships.getBow(),this->ships.getStern());
	return true;
	//TODO make sure this works
}

/** COwnGrid::getShips
 * a vector which contains the coordinates of different ships
 * on the own grid
 */
const std::vector<CShip> COwnGrid::getShips()
{
	vector<CShip> ships;
	//TODO make sure this works
	return ships;
}
