#include "CShip.h"
#include <iterator>
#include <set>

CShip::CShip()
{

}
/** CShip constructor
 *
 * this constructor takes 2 const CGridPosition references
 * for the bow (beginning) and stern (end) of a ship.
 */
CShip::CShip(const CGridPosition &bow, const CGridPosition &stern)
{
	this->bow = bow;
	this->stern = stern;
}

/** CShip::isValid
  *
  * checks if the
  * bow and stern are valid cooridinates for the board
  * length is in between 2 and 5
  */
bool CShip::isValid()
{
	//check for valid coordinates and check for correct length
	//TODO check if ship is vertical or horizontal
	if((this->bow.isValid() && this->stern.isValid()) && (this->length() >=2 && this->length() <=5))
	{
		return true;
	}
	else
	{
		return false;
	}
}

/** CShip::getBow
 *
 * return the bow
 */
CGridPosition CShip::getBow()
{
	return this->bow;
}

/** CShip::getStern
 *
 * return the stern
 */
CGridPosition CShip::getStern()
{
	return this->stern;
}

/** CShip::length
 *
 * return the length of the ship
 * length is calculated by finding the stern.row - bow.row
 * or stern.column - bow.column depending on whether it is vertical or horizontal
 */
int CShip::length()
{
	int length;

	if((int)this->bow.getRow() < (int)this->stern.getRow())
	{
		length = (int)this->stern.getRow() - ((int)this->bow.getRow()-1);
	}
	else if (this->bow.getColumn() < this->stern.getColumn())
	{
		length = this->stern.getColumn() - this->bow.getColumn()+1;
	}

	return length;
}

/** CShip::occupiedArea
 *
 * returns the size of a set of coordinates which is the area of the board covered
 * by a ship. This is calculated based upon the bow and stern
 */
const std::set<CGridPosition> CShip::occupiedArea()
{
	bool orientation;
	std::set<CGridPosition> area;

	//vertical
	if((int)this->bow.getRow() < (int)this->stern.getRow())
	{
		orientation = true;
	}
	//horizontal
	else if (this->bow.getColumn() < this->stern.getColumn())
	{
		orientation = false;
	}

	int row = (int)this->stern.getRow();
	int col = this->stern.getColumn();

	area.insert(this->stern);
	for(int l = 0; l <this->length()-1; l++)
	{
		if(orientation)
		{
			row--;
			area.insert({(char)row,this->bow.getColumn()});
		}
		else
		{
			col--;
			area.insert({this->bow.getRow(),col});
		}
	}
	area.insert(this->bow);

	return area;
}

/** CShip::blockedArea
 *
 * returns the size of a set of coordinates which is the area of the board covered
 * by a ship but ships cannot touch one another so a minimum of one space needs to be kept between each ship
 * this area also includes the area of the ship
 */
//const std::set<CGridPosition> CShip::blockedArea()
//{
//	return 1;
//}
