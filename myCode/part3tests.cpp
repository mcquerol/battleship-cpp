/*
 * part3tests.cpp
 *
 *  Created on: 22 Dec 2024
 *      Author: mateo
 */

#include "part3tests.h"

#include "Ship.h"
#include "Board.h"
#include "ConsoleView.h"
#include "Shot.h"
#include "GridPosition.h"
#include <iostream>
#include <string>

using namespace std;

void part3tests::assertTrue(bool condition, string failedMessage) {
    if (!condition) {
        cout << failedMessage << endl;
    }
}

void part3tests::part3test()
{
    Board board(10, 10);
    OwnGrid& ownGrid = board.getOwnGrid();

    // Arrange a ship on the board
    Ship ship(GridPosition{"B2"}, GridPosition{"B4"});
    assertTrue(ownGrid.placeShip(ship), "Failed to place ship on the board");

    // Test a miss
    Shot missShot(GridPosition{"A1"});
    //assertTrue(ownGrid.takeBlow(missShot) == Shot::Impact::NONE, "Missed shot not handled correctly");

    // Test a hit
    Shot hitShot(GridPosition{"B2"});
    //assertTrue(ownGrid.takeBlow(hitShot) == Shot::Impact::HIT, "Hit shot not handled correctly");

    // Test a final hit (sunk)
    Shot finalHitShot1(GridPosition{"B3"});
    Shot finalHitShot2(GridPosition{"B4"});
    //assertTrue(ownGrid.takeBlow(finalHitShot1) == Shot::Impact::HIT, "Final hit shot 1 not handled correctly");
    //assertTrue(ownGrid.takeBlow(finalHitShot2) == Shot::Impact::SUNKEN, "Final hit shot 2 not handled correctly");

    // Create a console view and print
    ConsoleView consoleView(&board);
    consoleView.print();


}

