#ifndef COPPONENTGRID_H
#define COPPONENTGRID_H

#include "CShip.h"
#include <vector>
class COpponentGrid {
private:
	char** grid;
	/** private int rows
	 *
	 * the rows of player 2's grid
	 */
    int rows;

	/** private int columns
	 *
	 * the columns of player 2's grid
	 */
    int columns;

    /**
     * @supplierCardinality 0..10 
     */
    std::vector<CShip> sunkenShips;
public:


     /** COpponentGrid constructor
      *
      *  COpponentGrid constructor that takes the own grid size
      */
     COpponentGrid(int rows, int columns);
     ~COpponentGrid();
     /** COpponentGrid::getRows
      *
      * return the rows
      */
     int getRows() const;

     /** COpponentGrid::getColumns
      *
      * return the columns
      */
     int getColumns() const;

     /** COpponentGrid::getSunkenShips
      * a vector which contains the coordinates of sunken ships
      * on the opponent grid
      */
     char** getGrid() const;

     void markShipAsSunken(const CShip& ship);

     const std::vector<CShip>getSunkenShips() const;

};
#endif /* COPPONENTGRID_H */
