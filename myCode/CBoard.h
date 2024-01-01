#ifndef CBOARD_H
#define CBOARD_H
#include "COpponentGrid.h"
#include "COwnGrid.h"
class CBoard {
private:
	int rows;
	int columns;
    /**@link aggregation
     * @supplierCardinality 1*/
    COpponentGrid opponentGrid;
    /**@link aggregation
     * @supplierCardinality 1*/
    COwnGrid ownGrid;
    /**@link aggregation
     * @supplierCardinality 1*/
public:

    /** CBoard consctructor
     *
     * EMPTY constructor
     */
    CBoard();

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
    int getRows();

    /** CBoard::getColumns
     *
     * return the columns
     */
    int getColumns();

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
