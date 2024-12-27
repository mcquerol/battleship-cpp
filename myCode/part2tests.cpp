/*
 * part2tests.cpp
 *
 *  Created on: 11 Jan 2024
 *      Author: mateo
 */

#include "Ship.h"
#include "Board.h"
#include "part2tests.h"
#include "ConsoleView.h"

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
    Board board(10, 10);
    OwnGrid& ownGrid = board.getOwnGrid();

    // Arrange three ships on the board
    Ship ship1(GridPosition{"B2"}, GridPosition{"B4"});
    Ship ship2(GridPosition{"D4"}, GridPosition{"G4"});
    Ship ship3(GridPosition{"F6"}, GridPosition{"F9"});

    assertTrue(ownGrid.placeShip(ship1), "Failed to place ship1 on the board");
    assertTrue(ownGrid.placeShip(ship2), "Failed to place ship2 on the board");
    assertTrue(ownGrid.placeShip(ship3), "Failed to place ship3 on the board");

    // Create a console view and print
    ConsoleView consoleView(&board);
    consoleView.print();
}
