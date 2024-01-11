#include "COpponentGrid.h"


/** COpponentGrid constructor
 *
 *  COpponentGrid constructor that takes the own grid size
 */
COpponentGrid::COpponentGrid(int rows, int columns) : rows(rows), columns(columns)
{
	//initialize owngrid and opponent grid
	grid = new char*[rows];

	for (int index = 0; index < rows; index++)
	{
		grid[index] = new char[columns];
	}

	//set every element in each grid to ~ (empty)
	for(int row = 0; row < rows; row++)
	{
		for(int col = 0; col < columns; col++)
		{
			grid[row][col] = '~';
		}
	}

}

COpponentGrid::~COpponentGrid()
{
    for(int index = 0; index < rows; index++)
    {
        delete [] grid[index];
    }
    delete [] grid;
}
/** COpponentGrid::getRows
 *
 * return the rows
 */
int COpponentGrid::getRows() const
{
	return this->rows;
}

/** COpponentGrid::getColumns
 *
 * return the columns
 */
int COpponentGrid::getColumns() const
{
	return this->columns;
}

char** COpponentGrid::getGrid() const {
    return grid;
}

/** COpponentGrid::getSunkenShips
 * a vector which contains the coordinates of sunken ships
 * on the opponent grid
 */
const std::vector<CShip> COpponentGrid::getSunkenShips() const
{
	return sunkenShips;
}

const std::map<CGridPosition, CShots::Impact>& COpponentGrid::getShotsAt() const
{
    return shots;
}

void COpponentGrid::shotResult(const CShots& shot, CShots::Impact impact)
{
    //const CGridPosition& position = shot.getTargetPosition();

}
