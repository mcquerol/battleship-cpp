/*
 * ConsoleView.h
 *
 *  Created on: 29 Nov 2024
 *      Author: mateo
 */

#ifndef CONSOLEVIEW_H_
#define CONSOLEVIEW_H_

#include "Board.h"

class ConsoleView
{

private:

	Board* board;
	char** ownGrid;
	char** opponentGrid;

public:

	ConsoleView(Board* board);
	~ConsoleView();
	void print() const;

};

#endif /* CONSOLEVIEW_H_ */
