#include "CGridPosition.h"
#include <iostream>
#include <string>

using namespace std;


CGridPosition::CGridPosition()
{

}

/** CGridPosition constructor 1
 *
 * this constructor takes individual char and int parameters for the
 * row and column respecitvely
 */
CGridPosition::CGridPosition(char row, int column)
{
	this->row = row;
	this->column = column;
}

/** CGridPosition contstructor 2
 *
 * this constructor takes a string input (eg. "B10") and splits it
 * into the row and column
 */
CGridPosition::CGridPosition(std::string position)
{
	//TODO make sure it can take 10 as a result
	for(unsigned int i = 0; i < position.length(); i++)
	{
		if(isdigit(position[i]))
		{
			if(position[i] == '1' && position[i+1] == '0')
			{
				this->column = 10;
			}
			else
			{
				char pos = position[i];
				this->column = std::stoi(&pos);
			}
		}
		else
		{
			this->row = position[i];
		}
	}
}

/** CGridPosition::isValid
 *
 * checks if the
 * row is between 'A' and 'Z' and the column is greater than 1
 */
bool CGridPosition::isValid()
{
	if(((int)row >= 65 && (int)row <= 90) && column >= 1)
	{
		return true;
	}
	else
	{
		return false;
	}

}

/** CGridPosition::getRow
 *
 * return the row
 */
char CGridPosition::getRow()
{
	return this->row;
}

/** CGridPosition::getColumn
 *
 * return the column
 */
int CGridPosition::getColumn()
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
	if((int)this->row < (int)other.row || this->column < other.column)
	{
		return true;
	}
	return false;
}

/** '==' operator overload
 *
 * returns true if the (current object) row and column
 * is equal to the right hand operand object row and column
 */
bool CGridPosition::operator==(CGridPosition other) const
{
	if((int)this->row == (int)other.row && this->column == other.column)
	{
		return true;
	}
	return false;
}
