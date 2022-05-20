/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : COPPONENTGRID.H
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef COPPONENTGRID_H
#define COPPONENTGRID_H
class COpponentGrid {
private:
    int rows;
    int columns;
    /**
     * @supplierCardinality 0..10 
     */
    CShip sunkenShips;
public:

    void COpponentGrid(int rows, int columns);

     int getRows();

     int getColumns();
};
/********************
**  CLASS END
*********************/
#endif /* COPPONENTGRID_H */
