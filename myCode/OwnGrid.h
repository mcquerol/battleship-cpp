/*
 * OwnGrid.h
 *
 *  Created on: 29 Nov 2024
 *      Author: mateo
 */

#ifndef OWNGRID_H_
#define OWNGRID_H_

#include <vector>
#include <map>

#include "Ship.h"
#include "Shot.h"

class OwnGrid
{

private:

	int rows;
	int columns;

	std::vector<Ship> ships = {}; //vector containing placed ships on owngrid
	std::map<int,int> shipList = {}; //contains the amount of ships for each given length (10 in total)

	std::set<GridPosition> shotAt = {}; //set which contains the gridpositions of the shots
public:

	OwnGrid(int rows, int columns);
	int getRows() const;
	int getColumns() const;
	bool placeShip(const Ship& ship);
	const std::vector<Ship> getShips() const;
	Shot::Impact takeBlow(const Shot& shot);
	const std::set<GridPosition> getShotAt();

};

#endif /* OWNGRID_H_ */
