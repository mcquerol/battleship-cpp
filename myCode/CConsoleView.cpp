#include "CConsoleView.h"
#include "CBoard.h"

/** CConsoleView constructor
 *
 * takes in board pointer as input parameter
 * defines the ownGrid and opponentGrid arrays
 */
CConsoleView::CConsoleView(CBoard* board)
{
	this->board = board;

	this->ownGrid = new char*[this->board->getRows()];
	this->opponentGrid = new char*[this->board->getRows()];

	for (int index = 0; index < this->board->getRows(); index++)
	{
		this->ownGrid[index] = new char[this->board->getColumns()];
		this->opponentGrid[index] = new char[this->board->getColumns()];
	}

	for(int row = 0; row < this->board->getRows(); row++)
	{
		for(int col = 0; col < this->board->getColumns(); col++)
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
	for(int index = 0; index < this->board->getRows(); index++)
	{
		delete [] this->ownGrid;
		delete [] this->opponentGrid;
	}
	delete [] board;
	delete [] ownGrid;
	delete [] opponentGrid;
}

/** CConsoleView::print
 *
 * prints the ownGrid and opponentGrid arrays
 */
void CConsoleView::print()
{
  	cout << " OWN GRID" << endl;
	for(int col = 0; col < this->board->getColumns(); col++)
	{
		cout << " " << col+1; //column numbers
	}
	cout << endl;
  	for(int row = 0; row < this->board->getRows(); row++)
	{
  		char c = row+1+64;
  		cout << c << " "; // row numbers
		for(int col = 0; col < this->board->getColumns(); col++)
	    {
			cout << ownGrid[row][col] << " ";
	    }
		cout << endl;
	}

  	cout << endl;
  	cout << endl;

  	cout << " OPPONENT GRID" << endl;
	for(int col = 0; col < this->board->getColumns(); col++)
	{
		cout << " " << col+1; //column numbers
	}
	cout << endl;
  	for(int row = 0; row < this->board->getRows(); row++)
	{
  		char c = row+1+64;
  		cout << c << " "; // row numbers
		for(int col = 0; col < this->board->getColumns(); col++)
	    {
			cout << opponentGrid[row][col] << " ";
	    }
		cout << endl;
	}
}
