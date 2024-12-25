/*
 * GridPosition.cpp
 *
 *  Created on: 29 Nov 2024
 *      Author: mateo
 */

#include "GridPosition.h"
#include <iostream>
GridPosition::GridPosition(char row, int column): row(row), column(column)
{
}

GridPosition::GridPosition(std::string position) : row(position[0]), column(std::stoi(position.substr(1)))
{
}

bool GridPosition::isValid() const
{
	return (row >= 'A' && row <= 'Z') && (column >= 1);
}

char GridPosition::getRow() const
{
	return row;
}

int GridPosition::getColumn() const
{
	return column;
}

GridPosition::operator std::string() const
{
	return this->row + std::to_string(this->column);
}

bool GridPosition::operator==(const GridPosition &other) const
{
	return (row == other.getRow()) && (column == other.getColumn());
}

bool GridPosition::operator<(const GridPosition &other) const
{

    if (row < other.getRow())
	{
    	return true;
	}
    if (row == other.getRow() && column < other.getColumn())
	{
    	return true;
	}
    return false;


}
