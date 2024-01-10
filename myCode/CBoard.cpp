#include "CBoard.h"

/** CBoard constructor
 *
 * takes in rows and columns as parameters
 * ownGrid object and opponentGrid objects
 * are created with those dimensions
 */
CBoard::CBoard(int rows, int columns) : rows(rows), columns(columns), ownGrid(rows, columns), opponentGrid(rows, columns) {}


/** CBoard::getRows
 *
 * return the rows
 */
int CBoard::getRows() const
{
	return ownGrid.getRows();
}

/** CBoard::getColumns
 *
 * return the columns
 */
int CBoard::getColumns() const
{
	return ownGrid.getColumns();
}

/** CBoard::getOwnGrid
 *
 * returns a reference of the ownGrid object
 */
COwnGrid& CBoard::getOwnGrid()
{
	return ownGrid;
}

/** CBoard::opponentGrid
 *
 * returns a reference of the opponentGrid object
 */
COpponentGrid& CBoard::getOpponentGrid()
{
	return opponentGrid;
}


