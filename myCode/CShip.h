/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CSHIP.H
* Author          :
* Description     :
*
*
****************************************************************************/

#ifndef CSHIP_H
#define CSHIP_H
#include <iostream>

#include "CGridPosition.h"
class CShip {
private:
    CGridPosition bow;
    CGridPosition stern;
public:

    void CShip(const CGridPosition& bow, const CGridPosition& stern);

    bool isValid();

    CGridPosition getBow();

    CGridPosition getStern();

     int length();

     const std::set<CGridPosition>occupiedArea();
     const std::set<CGridPosition>blockedArea();
};
/********************
**  CLASS END
*********************/
#endif /* CSHIP_H */
