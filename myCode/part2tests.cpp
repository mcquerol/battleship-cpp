/*
 * part2tests.cpp
 *
 *  Created on: 11 Jan 2024
 *      Author: mateo
 */

#include "CShip.h"
#include "CBoard.h"
#include "part2tests.h"
#include "CConsoleView.h"

#include <iostream>
#include <string>

using namespace std;

void part2tests::assertTrue(bool condition, string failedMessage)
{
    if (!condition) {
        cout << failedMessage << endl;
    }
}

void part2tests::part2test()
{
    CBoard board(10, 10);
    COwnGrid& ownGrid = board.getOwnGrid();

    // Arrange three ships on the board
    CShip ship1(CGridPosition{"B2"}, CGridPosition{"B4"});
    CShip ship2(CGridPosition{"D4"}, CGridPosition{"G4"});
    CShip ship3(CGridPosition{"F6"}, CGridPosition{"F9"});

    assertTrue(ownGrid.placeShip(ship1), "Failed to place ship1 on the board");
    assertTrue(ownGrid.placeShip(ship2), "Failed to place ship2 on the board");
    assertTrue(ownGrid.placeShip(ship3), "Failed to place ship3 on the board");

    // Create a console view and print
    CConsoleView consoleView(&board);
    consoleView.print();
}
