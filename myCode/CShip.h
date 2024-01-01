#ifndef CSHIP_H
#define CSHIP_H

#include "CGridPosition.h"

#include <iostream>
#include <set>
#include <string>

class CShip {
private:
    CGridPosition bow;
    CGridPosition stern;
public:

    CShip();
    /** CShip constructor
     *
     * this constructor takes 2 const CGridPosition references
     * for the bow (beginning) and stern (end) of a ship.
     */
    CShip(const CGridPosition &bow, const CGridPosition &stern);

    /** CShip::isValid
     *
     * checks if the
     * bow and stern are valid cooridinates for the 10x10 board
     */
    bool isValid();

    /** CShip::getBow
     *
     * return the bow
     */
    CGridPosition getBow();

    /** CShip::getStern
     *
     * return the stern
     */
    CGridPosition getStern();

    /** CShip::length
     *
     * return the length of the ship
     */
    int length();

    /** CShip::occupiedArea
     *
     * returns the size of a set of coordinates which is the area of the board covered
     * by a ship. This is calculated based upon the bow and stern
     */
    const std::set<CGridPosition>occupiedArea();

    /** CShip::blockedArea
     *
     * returns the size of a set of coordinates which is the area of the board covered
     * by a ship but ships cannot touch one another so a minimum of one space needs to be kept between each ship
     * this area also includes the area of the ship
     */
    //const std::set<CGridPosition>blockedArea();
};
#endif /* CSHIP_H */
