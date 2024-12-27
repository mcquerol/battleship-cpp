/*
 * OwnGrid.cpp
 *
 *  Created on: 29 Nov 2024
 *      Author: mateo
 */

#include "OwnGrid.h"
#include <algorithm>
#include <iostream>

using namespace std;


OwnGrid::OwnGrid(int rows, int columns) : rows(rows), columns(columns)
{
	//map which represents a list of ship (LENGTH | AMOUNT)
	shipList.insert(pair<int,int>(5,1));
	shipList.insert(pair<int,int>(4,2));
	shipList.insert(pair<int,int>(3,3));
	shipList.insert(pair<int,int>(2,4));

}

int OwnGrid::getRows() const
{
	return rows;
}

int OwnGrid::getColumns() const
{
	return columns;
}


bool OwnGrid::placeShip(const Ship& ship)
{

	/* TODO check for conditions..
	 * ships may not touch each other
	 * the grid felds occupied by a ship form a straight line
	 * ships must be positioned horizontally or vertically
	 * each player has 10 ships...
	 */

	//reference to occupied area of ship to be placed
    const auto& occupiedArea = ship.occupiedArea();

    for (const auto& existingShip : ships)
    {
        const auto& blockedArea = existingShip.blockedArea();

        // Check for intersections between existing ship blockedArea and ship to be placed occupiedArea
        std::set<GridPosition> intersection;
        for (const auto& pos : blockedArea)
        {
            if (occupiedArea.find(pos) != occupiedArea.end())
            {
                intersection.insert(pos);
            }
        }

        if (!intersection.empty())
        {
            return false; // Ship overlaps or touches an existing ship
        }
    }

	if (!ship.isValid())
	{
		cerr << "Ship is invalid!\n";
		return false;
	}

	if (ships.size() == 10)
	{
		cerr << "Max ships already placed!\n";
		return false;
	}

    // If no intersections or invalid cases, place the ship but decrease amount of length in map
	if(shipList[ship.length()] > 0)
	{
		shipList[ship.length()]--;
		ships.push_back(ship);
	}
	else
	{
		return false;
	}
//  debug output displas values of map to show a decrease is amount of ships for a given length
//	for(const auto& ship: shipList)
//	{
//		cout << ship.first << ship.second << endl;
//	}

    return true;
}

const std::vector<Ship> OwnGrid::getShips() const
{
	return ships;
}

Shot::Impact OwnGrid::takeBlow(const Shot& shot)
{
    const GridPosition& targetPosition = shot.getTargetPosition();

    // Check each ship
    for (const auto& ship : ships)
    {
        const auto& occupiedArea = ship.occupiedArea();

        // Check if the target position is in the occupied area
        if (occupiedArea.find(targetPosition) != occupiedArea.end())
        {
            // Target position is a hit
            shotAt.insert(targetPosition); // Record the shot

            // Check if it's the final hit
            std::set<GridPosition> intersection;
            std::set_intersection(
                occupiedArea.begin(), occupiedArea.end(),
                shotAt.begin(), shotAt.end(),
                std::inserter(intersection, intersection.begin())
            );

            // If all positions except the current hit have already been shot
            if (intersection.size() == ship.length() - 1)
            {
            	shotAt.insert(targetPosition); // Record the shot
                return Shot::Impact::SUNKEN;
            }

            return Shot::Impact::HIT;
        }
    }

    // If no ship was hit
    shotAt.insert(targetPosition); // Record the shot
    return Shot::Impact::NONE;
}

const std::set<GridPosition> OwnGrid::getShotAt()
{
	return shotAt;
}
