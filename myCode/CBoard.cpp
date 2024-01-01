#include "CBoard.h"
/** CBoard consctructor
 *
 * EMPTY constructor
 */
CBoard::CBoard()
{

}

/** CBoard constructor
 *
 * takes in rows and columns as parameters
 * ownGrid object and opponentGrid objects
 * are created with those dimensions
 */
CBoard::CBoard(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;
}

/** CBoard::getRows
 *
 * return the rows
 */
int CBoard::getRows()
{
	return this->rows;
}

/** CBoard::getColumns
 *
 * return the columns
 */
int CBoard::getColumns()
{
	return this->columns;
}

/** CBoard::getOwnGrid
 *
 * returns a reference of the ownGrid object
 */
COwnGrid& CBoard::getOwnGrid()
{
	return this->ownGrid;
}

/** CBoard::opponentGrid
 *
 * returns a reference of the opponentGrid object
 */
COpponentGrid& CBoard::getOpponentGrid()
{
	return this->opponentGrid;
}
