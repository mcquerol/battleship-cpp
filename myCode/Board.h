/*
 * Board.h
 *
 *  Created on: 29 Nov 2024
 *      Author: mateo
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "OwnGrid.h"
#include "OpponentGrid.h"


class Board
{
private:

	int rows;
	int columns;

	OwnGrid ownGrid;
	OpponentGrid opponentGrid;

public:

	Board(int rows = 10, int columns = 10);
	int getRows() const;
	int getColumns() const;
	OwnGrid& getOwnGrid();
	OpponentGrid& getOpponentGrid();

};

#endif /* BOARD_H_ */
