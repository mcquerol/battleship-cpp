// Standard (system) header files
#include <iostream>
#include <stdlib.h>
#include "CGridPosition.h"
#include "CShip.h"
#include "COwnGrid.h"
#include "COpponentGrid.h"
#include "CBoard.h"
#include "CConsoleView.h"
using namespace std;

int main(void) {
//    CGridPosition p1('B', 2);
//    CGridPosition p2('E', 2);
//
//    CShip ship1(p1, p2);
//
//    std::string bow1 = ship1.getBow();
//    std::string stern1 = ship1.getStern();
//
//    cout << "bow = " << bow1 << " and stern = " << stern1 << endl;
//    cout << "LENGTH: " << ship1.length() << endl;
//
//    for (const auto& position : ship1.occupiedArea())
//    {
//        cout << "Row: " << position.getRow() << ", Column: " << position.getColumn() << endl;
//    }
//
//    cout << " size is " << ship1.occupiedArea().size() << endl;
//
//    CBoard b(10, 10);
//    CConsoleView view(&b);
//
//    view.print();
//    return 0;
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

	    return 0;
}


