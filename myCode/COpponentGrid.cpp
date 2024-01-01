#include "COpponentGrid.h"

/** COpponentGrid constructor
 *
 * EMPTY constructor
 */
COpponentGrid::COpponentGrid()
{

}

/** COpponentGrid constructor
 *
 *  COpponentGrid constructor that takes the own grid size
 */
COpponentGrid::COpponentGrid(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;
}

/** COpponentGrid::getRows
 *
 * return the rows
 */
int COpponentGrid::getRows()
{
	return this->rows;
}

/** COpponentGrid::getColumns
 *
 * return the columns
 */
int COpponentGrid::getColumns()
{
	return this->columns;
}

/** COpponentGrid::getSunkenShips
 * a vector which contains the coordinates of sunken ships
 * on the opponent grid
 */
const std::vector<CShip> COpponentGrid::getSunkenShips()
{
	vector<CShip> ships;
	ships.reserve(10);
	//TODO make sure this works

	return ships;
}
