#include "COpponentGrid.h"


/** COpponentGrid constructor
 *
 *  COpponentGrid constructor that takes the own grid size
 */
COpponentGrid::COpponentGrid(int rows, int columns) : rows(rows), columns(columns) {}

/** COpponentGrid::getRows
 *
 * return the rows
 */
int COpponentGrid::getRows() const
{
	return this->rows;
}

/** COpponentGrid::getColumns
 *
 * return the columns
 */
int COpponentGrid::getColumns() const
{
	return this->columns;
}


/** COpponentGrid::getSunkenShips
 * a vector which contains the coordinates of sunken ships
 * on the opponent grid
 */
const std::vector<CShip> COpponentGrid::getSunkenShips() const
{
	return sunkenShips;
}
