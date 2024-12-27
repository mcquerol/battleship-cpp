/*
 * Ship.h
 *
 *  Created on: 29 Nov 2024
 *      Author: mateo
 */

#ifndef SHIP_H_
#define SHIP_H_

#include <set>
#include <string>

#include "GridPosition.h"


class Ship
{

private:

	GridPosition bow;
	GridPosition stern;

public:

	Ship(const GridPosition& bow, const GridPosition& stern);
	bool isValid() const;
	GridPosition getBow() const;
	GridPosition getStern() const;
	int length() const;
	const std::set<GridPosition> occupiedArea() const;
	const std::set<GridPosition> blockedArea() const;

};

#endif /* SHIP_H_ */
