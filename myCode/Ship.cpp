/*
 * Ship.cpp
 *
 *  Created on: 29 Nov 2024
 *      Author: mateo
 */

#include "Ship.h"
#include <iostream>

Ship::Ship(const GridPosition &bow, const GridPosition &stern) : bow(bow), stern(stern)
{
}

bool Ship::isValid() const
{
	/* Checking conditions
	 *
	 * Valid positions (bow and stern within the board)
	 * Length between 2 and 5
	 * Ship is vertical or horizontal
	 *
	 */

	return (bow.isValid() && stern.isValid()) && (this->length() >= 2 && this->length() <=5) && (bow.getRow() == stern.getRow() || bow.getColumn() == stern.getColumn());
}

GridPosition Ship::getBow() const
{
	return bow;
}

GridPosition Ship::getStern() const
{
	return stern;
}

int Ship::length() const
{

	if(bow.getColumn() == stern.getColumn()){return std::abs(bow.getRow() - stern.getRow()) + 1;}
	if(bow.getRow() == stern.getRow()){return std::abs(bow.getColumn() - stern.getColumn()) + 1;}

	return 0;
}

const std::set<GridPosition> Ship::occupiedArea() const
{
	std::set<GridPosition> occupiedarea;

	for(char row = bow.getRow() ; row <= stern.getRow(); row++)
	{
		for(int col = bow.getColumn() ; col <= stern.getColumn(); col++)
		{
			occupiedarea.emplace(row,col);
		}
	}

	return occupiedarea;
}

const std::set<GridPosition> Ship::blockedArea() const
{
	std::set<GridPosition> blockedarea;

	for(const auto& pos: occupiedArea())
	{
		blockedarea.emplace(pos.getRow(),pos.getColumn()); //put the elements frofm ocupied area into blockedarea
		for(int dRow = -1; dRow <= 1; dRow++)
		{
			for(int dCol = -1; dCol <= 1; dCol++)
			{
                GridPosition neighbor(pos.getRow() + dRow, pos.getColumn() + dCol);
                if (!neighbor.isValid()) { // Ensure neighbor is within bounds
                    continue;
                }
                blockedarea.emplace(neighbor);
			}
		}
	}
	return blockedarea;
}

