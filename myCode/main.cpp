#include <iostream>
#include <cstdlib>

#include "GridPosition.h"
#include "Ship.h"
#include "OwnGrid.h"
#include "OpponentGrid.h"
#include <string.h>
#include "ConsoleView.h"
#include "Board.h"
#include "Shot.h"

#include "part1tests.h"
#include "part2tests.h"
#include "part3tests.h"

#include <algorithm>
#include <set>
using namespace std;

int main ()
{

    Board board(10, 10);
    OwnGrid& ownGrid = board.getOwnGrid();

    // Arrange three ships on the board
    Ship ship1(GridPosition{"B2"}, GridPosition{"B4"});
    Ship ship2(GridPosition{"D4"}, GridPosition{"G4"});
    Ship ship3(GridPosition{"F6"}, GridPosition{"F9"});

    if(!ownGrid.placeShip(ship1))
    {
    	cout << "Failed to place ship1 on the board" << endl;
    }
    if(!ownGrid.placeShip(ship2))
    {
    	cout << "Failed to place ship2 on the board" << endl;
    }
    if(!ownGrid.placeShip(ship3))
    {
    	cout << "Failed to place ship3 on the board" << endl;
    }

    // Test shots
    Shot hit1(GridPosition{"B3"});
    Shot hit2(GridPosition{"B4"});
    Shot hit3(GridPosition{"B5"});

    ownGrid.takeBlow(hit1);
    ownGrid.takeBlow(hit2);
    ownGrid.takeBlow(hit3);

    // Create a console view and print
    ConsoleView consoleView(&board);
    consoleView.print();

	return 0;
}
