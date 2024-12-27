#include "Board.h"

Board::Board(int rows, int columns) : rows(rows), columns(columns), ownGrid(rows, columns), opponentGrid(rows, columns)
{
}

int Board::getRows() const
{
	return rows;
}

int Board::getColumns() const
{
	return columns;
}

OwnGrid& Board::getOwnGrid()
{
	return ownGrid;
}

OpponentGrid& Board::getOpponentGrid()
{
	return opponentGrid;
}
