#ifndef CBOARD_H
#define CBOARD_H

#include "COpponentGrid.h"
#include "COwnGrid.h"

class CBoard {
private:
	int rows;
	int columns;

    COpponentGrid opponentGrid;

    COwnGrid ownGrid;

public:


    /** CBoard constructor
     *
     * takes in rows and columns as parameters
     * ownGrid object and opponentGrid objects
     * are created with those dimensions
     */
    CBoard(int rows, int columns);

    /** CBoard::getRows
     *
     * return the rows
     */
    int getRows() const;

    /** CBoard::getColumns
     *
     * return the columns
     */
    int getColumns() const;

    /** CBoard::getOwnGrid
     *
     * returns a reference of the ownGrid object
     */
    COwnGrid& getOwnGrid();

    /** CBoard::opponentGrid
     *
     * returns a reference of the opponentGrid object
     */
    COpponentGrid& getOpponentGrid();
};

#endif /* CBOARD_H */
