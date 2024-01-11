/*
 * part3tests.cpp
 *
 *  Created on: 11 Jan 2024
 *      Author: mateo
 */

#include "part3tests.h"

#include "CShip.h"
#include "CBoard.h"
#include "CConsoleView.h"

#include <iostream>
#include <string>

using namespace std;
part3tests::part3tests()
{

}

void part3tests::assertTrue(bool condition, string failedMessage) {
    if (!condition) {
        cout << failedMessage << endl;
    }
}

void part3tests::part3test()
{
    CBoard board(10, 10);
    COwnGrid& ownGrid = board.getOwnGrid();

    // Arrange a ship on the board
    CShip ship(CGridPosition{"B2"}, CGridPosition{"B4"});
    assertTrue(ownGrid.placeShip(ship), "Failed to place ship on the board");

    // Create a console view and print
    CConsoleView consoleView(&board);

    // Test a miss
    CShots missShot(CGridPosition{"A1"});
    //assertTrue(ownGrid.takeBlow(missShot) == CShots::Impact::NONE, "Missed shot not handled correctly");

    // Test a hit
    CShots hitShot(CGridPosition{"B2"});
    //assertTrue(ownGrid.takeBlow(hitShot) == CShots::Impact::HIT, "Hit shot not handled correctly");

    // Test a final hit (sunk)
    CShots finalHitShot1(CGridPosition{"B3"});
    CShots finalHitShot2(CGridPosition{"B4"});
    //assertTrue(ownGrid.takeBlow(finalHitShot1) == CShots::Impact::HIT, "Final hit shot 1 not handled correctly");
    //assertTrue(ownGrid.takeBlow(finalHitShot2) == CShots::Impact::SUNKEN, "Final hit shot 2 not handled correctly");
}

