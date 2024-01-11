#ifndef COWNGRID_H
#define COWNGRID_H

#include "CShip.h"
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

class COwnGrid {
private:
	char** grid;
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

    std::vector<CShip> ships;

    std::map<int, int> remainingShips;


public:


	/** COwnGrid constructor
	 *
	 *  COwnGrid constructor that takes the own grid size
	 */
    COwnGrid(int rows, int columns);
    ~COwnGrid();

    /** COwnGrid::getRows
     *
     * return the rows
     */
    int getRows() const ;

    /** COwnGrid::getColumns
     *
     * return the columns
     */
    int getColumns() const;

    /** COwnGrid::placeShip
     *
     * place a ship in the grid
     */
    bool placeShip(const CShip& ship);

    char** getGrid() const;

    bool placeShipForTesting(const CShip& ship, int testRow, int testCol);

    /** COwnGrid::getShips
     * a vector which contains the coordinates of different ships
     * on the own grid
     */
    const std::vector<CShip>getShips() const;
};
#endif /* COWNGRID_H */
