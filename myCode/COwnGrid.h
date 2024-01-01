#ifndef COWNGRID_H
#define COWNGRID_H
#include "CShip.h"
#include <iostream>
#include <vector>
#include <set>
class COwnGrid {
private:
	/** private int rows
	 *
	 * the rows of player 1's grid
	 */
    int rows;

	/** private int columns
	 *
	 * the columns of player 1's grid
	 */
    int columns;

    /**
     * @supplierCardinality 10 
     */
    CShip ships;

public:

	/** COwnGrid constructor
	 *
	 * EMPTY constructor
	 */
    COwnGrid();

	/** COwnGrid constructor
	 *
	 *  COwnGrid constructor that takes the own grid size
	 */
    COwnGrid(int rows, int columns);

    /** COwnGrid::getRows
     *
     * return the rows
     */
    int getRows();

    /** COwnGrid::getColumns
     *
     * return the columns
     */
    int getColumns();

    /** COwnGrid::placeShip
     *
     * place a ship in the grid
     */
    bool placeShip(const CShip& ship);

    /** COwnGrid::getShips
     * a vector which contains the coordinates of different ships
     * on the own grid
     */
    const std::vector<CShip>getShips();
};
#endif /* COWNGRID_H */
