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

#include "part1tests.h"
#include "part2tests.h"
#include "part3tests.h"

using namespace std;

int main() {

//	part1tests test1;
//    test1.part1test();
//
//	part1tests test2;
//    test2.part1test();
//
//	part1tests test3;
//    test3.part1test();
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


