/*
 * OpponentGrid.h
 *
 *  Created on: 29 Nov 2024
 *      Author: mateo
 */

#ifndef OPPONENTGRID_H_
#define OPPONENTGRID_H_

#include <vector>
#include "Ship.h"

class OpponentGrid
{
private:

	int rows;
	int columns;

	std::vector<Ship> sunkenShips = {}; //start with 0 sunkenships at the start of the game

public:

	OpponentGrid(int rows, int columns);
	int getRows() const;
	int getColumns() const;
	bool placeShip(const Ship& ship);
	const std::vector<Ship> getSunkenShips() const;

};

#endif /* OPPONENTGRID_H_ */
