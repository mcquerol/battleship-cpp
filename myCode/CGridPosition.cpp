#include "CGridPosition.h"
#include <iostream>
#include <string>

using namespace std;


/** CGridPosition constructor 1
 *
 * this constructor takes individual char and int parameters for the
 * row and column respecitvely
 */
CGridPosition::CGridPosition(char row, int column) : row(row), column(column) {}

/** CGridPosition contstructor 2
 *
 * this constructor takes a string input (eg. "B10") and splits it
 * into the row and column
 */
CGridPosition::CGridPosition(std::string position) : row(position[0]), column(std::stoi(position.substr(1))) {}

/** CGridPosition::isValid
 *
 * checks if the
 * row is between 'A' and 'Z' and the column is greater than 1
 */
bool CGridPosition::isValid() const
{
	return (row >= 'A' && row <= 'J') && (column >= 1);
}

/** CGridPosition::getRow
 *
 * return the row
 */
char CGridPosition::getRow() const
{
	return this->row;
}

/** CGridPosition::getColumn
 *
 * return the column
 */
int CGridPosition::getColumn() const
{
	return this->column;
}

/** overloaded cast to string
 *
 * allows for a CGridPosition object to be defined as a string and
 * can later be outputted as a string
 */
CGridPosition::operator std::string() const
{
	std::string temp;
	temp = this->row + std::to_string(this->column);
	return temp;
}

/** '<' operator overload
 *
 * returns true if the (current object) row and column
 * is less than the right hand operand object row and column
 //TODO give exact reason
 */
bool CGridPosition::operator<(CGridPosition other) const
{
	return (row < other.row) || ((row == other.row) && (column < other.column));
}

/** '==' operator overload
 *
 * returns true if the (current object) row and column
 * is equal to the right hand operand object row and column
 */
bool CGridPosition::operator==(CGridPosition other) const
{
	return (row == other.row) && (column == other.column);
}
