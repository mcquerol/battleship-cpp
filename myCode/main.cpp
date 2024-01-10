// Standard (system) header files
#include <iostream>
#include <stdlib.h>
#include "CGridPosition.h"
#include "CShip.h"
#include "COwnGrid.h"
#include "COpponentGrid.h"
#include "CBoard.h"
#include "CConsoleView.h"
#include <vector>
#include <set>
using namespace std;

int main() {
    CBoard b(10, 10);

    CGridPosition p1('B', 2);
    CGridPosition p2('B', 4);
    CShip ship1(p1, p2);

    CGridPosition p3('D', 4);
    CGridPosition p4('G', 4);
    CShip ship2(p3, p4);

    CGridPosition p5('F', 6);
    CGridPosition p6('F', 9);
    CShip ship3(p5, p6);

    b.getOwnGrid().placeShip(ship1);
    b.getOwnGrid().placeShip(ship2);
    b.getOwnGrid().placeShip(ship3);

    CConsoleView view(&b);
    view.print();


    const std::vector<CShip> ships = b.getOwnGrid().getShips();

    // Print information about each ship
    for (const auto& ship : ships) {

        // Get the occupied area of the ship
        const std::set<CGridPosition>& occupiedArea = ship.occupiedArea();

        // Print the positions of the ship
        std::cout << "Occupied Area: " << endl;
        for (const auto& position : occupiedArea) {
            std::cout << position.getRow() << "" << position.getColumn() << endl;
        }
        cout << ship.length() << endl;
        std::cout << std::endl;

    }
    return 0;
}


