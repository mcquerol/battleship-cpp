
#ifndef CCONSOLEVIEW_H
#define CCONSOLEVIEW_H
#include "CBoard.h"

class CConsoleView {
private:
	/** CBoard pointer
	 *
	 * pointer to CBoard class
	 */
    CBoard* board;

public:

    /** CConsoleView constructor
     *
     * takes in board pointer as input parameter
     * defines the ownGrid and opponentGrid arrays
     */
    CConsoleView(CBoard* board);

    /** CConsoleView destructor
     *
     * deallocates the arrays
     */
   ~CConsoleView();

   /** CConsoleView::print
    *
	* prints the ownGrid and opponentGrid arrays
    */
    void print();    
};

#endif /* CCONSOLEVIEW_H */
