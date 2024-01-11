#ifndef COWNGRID_H
#define COWNGRID_H

#include "CShip.h"
#include "CGridPosition.h"
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#include "CShots.h"

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
    std::set<CGridPosition>shotAt;

    bool hasBeenShot(const CGridPosition& position) const; // helper function

    bool isFinalHit(const CShip& ship, const CGridPosition& currentHit) const;

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

    /** COwnGrid::getShips
     * a vector which contains the coordinates of different ships
     * on the own grid
     */

    CShots::Impact takeBlow(const CShots& shot);

    const std::vector<CShip>getShips() const;
    const std::set<CGridPosition>getShotAt() const;
};
#endif /* COWNGRID_H */
