#include "CShip.h"
#include "CGridPosition.h"


/** CShip constructor
 *
 * this constructor takes 2 const CGridPosition references
 * for the bow (beginning) and stern (end) of a ship.
 */
CShip::CShip(const CGridPosition& bow, const CGridPosition& stern) : bow(bow), stern(stern) {}

/** CShip::isValid
  *
  * checks if the
  * bow and stern are valid cooridinates for the board
  * length is in between 2 and 5
  */
bool CShip::isValid() const
{
	//check for valid coordinates and check for correct length
	//TODO check if ship is vertical or horizontal
	return ((this->bow.isValid() && this->stern.isValid()) && (this->length() >=2 && this->length() <=5));

}

/** CShip::getBow
 *
 * return the bow
 */
CGridPosition CShip::getBow() const
{
	return bow;
}

/** CShip::getStern
 *
 * return the stern
 */
CGridPosition CShip::getStern() const
{
	return stern;
}

/** CShip::length
 *
 * return the length of the ship
 * length is calculated by finding the stern.row - bow.row
 * or stern.column - bow.column depending on whether it is vertical or horizontal
 */
int CShip::length() const
{
    // Calculate and return the length of the ship
    if (bow.getRow() == stern.getRow()) {
        // Ship is placed horizontally
        return std::abs(bow.getColumn() - stern.getColumn()) + 1;
    } else if (bow.getColumn() == stern.getColumn()) {
        // Ship is placed vertically
        return std::abs(bow.getRow() - stern.getRow()) + 1;
    } else {
        // Invalid ship orientation
        return 0;
    }
}

/** CShip::occupiedArea
 *
 * returns the size of a set of coordinates which is the area of the board covered
 * by a ship. This is calculated based upon the bow and stern
 */
const std::set<CGridPosition> CShip::occupiedArea() const
{
    std::set<CGridPosition> positions;

    // Example implementation: Assuming the ship is either horizontally or vertically placed
    if (bow.getRow() == stern.getRow()) {
        // Ship is placed horizontally
        for (int col = std::min(bow.getColumn(), stern.getColumn()); col <= std::max(bow.getColumn(), stern.getColumn()); ++col) {
            positions.insert(CGridPosition(bow.getRow(), col));
        }
    } else if (bow.getColumn() == stern.getColumn()) {
        // Ship is placed vertically
        for (char row = std::min(bow.getRow(), stern.getRow()); row <= std::max(bow.getRow(), stern.getRow()); ++row) {
            positions.insert(CGridPosition(row, bow.getColumn()));
        }
    }

    return positions;
}

/** CShip::blockedArea
 *
 * returns the size of a set of coordinates which is the area of the board covered
 * by a ship but ships cannot touch one another so a minimum of one space needs to be kept between each ship
 * this area also includes the area of the ship
 */
const std::set<CGridPosition> CShip::blockedArea() const
{
    std::set<CGridPosition> blockedPositions = occupiedArea();

    for (const auto& position : occupiedArea()) {
        // Iterate over adjacent positions in a 3x3 grid centered on the ship position
        for (int rowOffset = -1; rowOffset <= 1; ++rowOffset) {
            for (int colOffset = -1; colOffset <= 1; ++colOffset) {
                // Skip the center position (ship position)
                if (rowOffset == 0 && colOffset == 0) {
                    continue;
                }

                // Calculate the adjacent position
                char newRow = position.getRow() + rowOffset;
                int newColumn = position.getColumn() + colOffset;

                // Add the adjacent position to the blocked positions
                blockedPositions.insert(CGridPosition(newRow, newColumn));
            }
        }
    }

    return blockedPositions;
}
