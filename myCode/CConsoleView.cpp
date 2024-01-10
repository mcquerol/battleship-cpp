#include "CConsoleView.h"
#include "CBoard.h"
#include <iostream>

using namespace std;

/** CConsoleView constructor
 *
 * takes in board pointer as input parameter
 * defines the ownGrid and opponentGrid arrays
 */
CConsoleView::CConsoleView(CBoard* board) : board(board)
{

	//initialize owngrid and opponent grid
	this->ownGrid = new char*[board->getRows()];
	this->opponentGrid = new char*[board->getRows()];

	for (int index = 0; index < board->getRows(); index++)
	{
		this->ownGrid[index] = new char[board->getColumns()];
		this->opponentGrid[index] = new char[board->getColumns()];
	}

	//set every element in each grid to ~ (empty)
	for(int row = 0; row < board->getRows(); row++)
	{
		for(int col = 0; col < board->getColumns(); col++)
		{
			this->ownGrid[row][col] = '~';
			this->opponentGrid[row][col] = '~';
		}
	}
}

/** CConsoleView destructor
 *
 * deallocates the arrays
 */
CConsoleView::~CConsoleView()
{
	for(int index = 0; index <board->getRows(); index++)
	{
		delete [] ownGrid;
		delete [] opponentGrid;
	}
	delete [] board;
	delete [] ownGrid;
	delete [] opponentGrid;
}

/** CConsoleView::print
 *
 * prints the ownGrid and opponentGrid arrays
 */
void CConsoleView::print() {
    cout << " OWN GRID\t\t OPPONENT GRID" << endl;
    for (int col = 0; col < board->getColumns(); col++) {
        cout << " " << col + 1; // column numbers
    }
    cout << "\t"; // adjust the separator here
    for (int col = 0; col < board->getColumns(); col++) {
        cout << " " << col + 1; // column numbers for opponent grid
    }
    cout << endl;

    for (int row = 0; row < board->getRows(); row++) {
        char c = row + 1 + 64;
        cout << c << " "; // row numbers
        for (int col = 0; col < board->getColumns(); col++) {
            cout << ownGrid[row][col] << " ";
        }

        cout << "\t"; // adjust the separator here

        cout << c << " "; // row numbers for opponent grid
        for (int col = 0; col < board->getColumns(); col++) {
            cout << opponentGrid[row][col] << " ";
        }
        cout << endl;
    }

    cout << endl;
}


