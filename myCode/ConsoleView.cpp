#include "ConsoleView.h"
#include <iostream>

using namespace std;

ConsoleView::ConsoleView(Board *board) : board(board)
{

	ownGrid = new char*[board->getRows()];
	opponentGrid = new char*[board->getRows()];

	for(int row = 0; row < board->getRows(); row++)
	{
		ownGrid[row] = new char[board->getColumns()];
		opponentGrid[row] = new char[board->getColumns()];
	}


	for(int row = 0; row < board->getRows(); row++)
	{
		for(int col = 0; col < board->getColumns(); col++)
		{
			ownGrid[row][col] = '~';
			opponentGrid[row][col] = '~';

			for(const auto& ownGridShip : board->getOwnGrid().getShips())
			{
				for(const auto& pos : ownGridShip.occupiedArea())
				{
				    if (pos == GridPosition('A' + row, col + 1))
				    {
				    	ownGrid[row][col] = '#';
				    }
				}
			}
	        for (const auto& shot : board->getOwnGrid().getShotAt())
	        {
	            if (shot == GridPosition('A' + row, col + 1))
	            {
	                // Determine the impact of the shot
	                Shot::Impact impact = board->getOwnGrid().takeBlow(Shot(shot));
	                if (impact == Shot::Impact::HIT || impact == Shot::Impact::SUNKEN)
	                {
	                    ownGrid[row][col] = 'O'; // Hit
	                }
	                else if(impact == Shot::Impact::NONE)
	                {
	                	ownGrid[row][col] = '^';
	                }

	            }
	        }
		}
	}
}

ConsoleView::~ConsoleView()
{

	for(int row = 0; row < board->getRows(); row++)
	{
		delete [] ownGrid;
		delete [] opponentGrid;
	}

	delete [] ownGrid;
	delete [] opponentGrid;

	delete [] board;

}

void ConsoleView::print() const
{
  	cout << " OWN GRID" << endl;
  	cout << " ";
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

  	cout << " OPPONENT GRID" << endl;
  	cout << " ";
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
