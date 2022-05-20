/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : COWNGRID.H
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef COWNGRID_H
#define COWNGRID_H
#include "CShip.h"
#include <iostream>
#include <vector>

class COwnGrid {
private:
    int rows;
    int columns;
    /**
     * @supplierCardinality 10 
     */
    CShip ships;
public:

    void COwnGrid(int rows, int columns);

    int getRows();

    int getColumns();

    bool placeShip(const CShip& ship);

    const std::vector<CShip>getShips();
};
/********************
**  CLASS END
*********************/
#endif /* COWNGRID_H */
