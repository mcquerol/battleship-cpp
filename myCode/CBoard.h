/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CBOARD.H
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CBOARD_H
#define CBOARD_H
#include "COpponentGrid.h"
#include "COwnGrid.h"
class CBoard {
private:
    /**@link aggregation
     * @supplierCardinality 1*/
    COpponentGrid opponentGrid;
    /**@link aggregation
     * @supplierCardinality 1*/
    COwnGrid ownGrid;
    /**@link aggregation
     * @supplierCardinality 1*/
    ;
public:

    CBoard(int rows, int columns);

    int getRows();

    int getColumns();

    COwnGrid& getOwnGrid();

    COpponentGrid& getOpponentGrid();
};
/********************
**  CLASS END
*********************/
#endif /* CBOARD_H */
