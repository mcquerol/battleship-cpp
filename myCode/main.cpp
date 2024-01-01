// Standard (system) header files
#include <iostream>
#include <stdlib.h>
#include "CGridPosition.h"
#include "CShip.h"
#include "COwnGrid.h"
#include "CBoard.h"
#include "CConsoleView.h"
using namespace std;

int main (void)
{
	CGridPosition p1('B', 2);
	CGridPosition p2('E', 2);

	CShip ship1(p1,p2);

	std::string bow1 = ship1.getBow();
	std::string stern1 = ship1.getStern();

	cout << "bow = " << bow1 << " and stern = " << stern1 << endl;
	cout <<"LENGTH: " << ship1.length() << endl;

	for(auto i = ship1.occupiedArea().begin(); i != ship1.occupiedArea().end(); ++i)
	{
		cout << (string)*i << endl;
	}
	cout << " size is " << ship1.occupiedArea().size();

	CBoard b(10,10);

	CConsoleView view(&b);

	view.print();
	return 0;
}

