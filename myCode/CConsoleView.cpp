#include "CConsoleView.h"
#include "CBoard.h"
#include <iostream>

using namespace std;

/** CConsoleView constructor
 *
 * takes in board pointer as input parameter
 * defines the ownGrid and opponentGrid arrays
 */
CConsoleView::CConsoleView(CBoard* board) : board(board) {}

/** CConsoleView destructor
 *
 * deallocates the arrays
 */
CConsoleView::~CConsoleView()
{
	delete [] board;
}

/** CConsoleView::print
 *
 * prints the ownGrid and opponentGrid arrays
 */
void CConsoleView::print()
{

    cout << " OWN GRID\t\t OPPONENT GRID" << endl;
    cout << " ";
    for (int col = 0; col < board->getColumns(); col++) {
        cout << " " << col + 1; // column numbers
    }
    cout << "\t"; // adjust the separator here
    for (int col = 0; col < board->getColumns(); col++) {
        cout << " " << col + 1; // column numbers for opponent grid
    }
    cout << endl;

    for (int row = 0; row < board->getRows(); row++)
    {
	   char c = row + 1 + 64;
	   cout << c << " "; // row numbers
	   for (int col = 0; col < board->getColumns(); col++) {
		   cout << board->getOwnGrid().getGrid()[row][col] << " ";
	   }

	   cout << "\t"; // adjust the separator here

	   cout << c << " "; // row numbers for opponent grid
	   for (int col = 0; col < board->getColumns(); col++) {
		   cout << board->getOpponentGrid().getGrid()[row][col] << " ";
	   }
	   cout << endl;
    }
}




