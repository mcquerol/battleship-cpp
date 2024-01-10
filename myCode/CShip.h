#ifndef CSHIP_H
#define CSHIP_H

#include "CGridPosition.h"

#include <iostream>
#include <set>
#include <string>
#include <iterator>
#include <set>

class CShip {
private:
    CGridPosition bow;
    CGridPosition stern;
public:

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
    bool isValid() const;

    /** CShip::getBow
     *
     * return the bow
     */
    CGridPosition getBow() const;

    /** CShip::getStern
     *
     * return the stern
     */
    CGridPosition getStern() const;

    /** CShip::length
     *
     * return the length of the ship
     */
    int length() const;

    /** CShip::occupiedArea
     *
     * returns the size of a set of coordinates which is the area of the board covered
     * by a ship. This is calculated based upon the bow and stern
     */
    const std::set<CGridPosition> occupiedArea() const;

    /** CShip::blockedArea
     *
     * returns the size of a set of coordinates which is the area of the board covered
     * by a ship but ships cannot touch one another so a minimum of one space needs to be kept between each ship
     * this area also includes the area of the ship
     */
    const std::set<CGridPosition> blockedArea() const;
};
#endif /* CSHIP_H */
