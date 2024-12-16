/*
 * GridPosition.h
 *
 *  Created on: 29 Nov 2024
 *      Author: mateo
 */

#ifndef GRIDPOSITION_H_
#define GRIDPOSITION_H_

#include <string>

class GridPosition
{

private:

	char row;
	int column;

public:

	GridPosition(char row, int column);
	GridPosition(std::string position);

	bool isValid() const;
	char getRow() const;
	int getColumn() const;
	operator std::string() const;
	bool operator==(const GridPosition& other) const;
	bool operator<(const GridPosition& other) const;



};

#endif /* GRIDPOSITION_H_ */
