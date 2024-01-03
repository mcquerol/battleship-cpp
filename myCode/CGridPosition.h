#ifndef CGRIDPOSITION_H
#define CGRIDPOSITION_H

#include <iostream>

class CGridPosition {
private:
    char row;
    int column;
public:

    /** CGridPosition constructor 1
     *
     * this constructor takes individual char and int parameters for the
     * row and column respecitvely
     */
    CGridPosition(char row, int column);

    /** CGridPosition contstructor 2
     *
     * this constructor takes a string input (eg. "B10") and splits it
     * into the row and column
     */
    CGridPosition(std::string position);

    /** CGridPosition::isValid
     *
     * checks if the
     * row is between 'A' and 'Z' and the column is greater than 1
     */
    bool isValid() const;

    /** CGridPosition::getRow
     *
     * return the row
     */
    char getRow() const;

    /** CGridPosition::getColumn
     *
     * return the column
     */
    int getColumn() const;

    /** overloaded cast to string
     *
     * allows for a CGridPosition object to be defined as a string and
     * can later be outputted as a string
     */
    operator std::string() const;

    /** '<' operator overload
     *
     * returns true if the (current object) row and column
     * is less than the right hand operand object row and column
     //TODO give exact reason
     */
    bool operator<(CGridPosition other) const;

    /** '==' operator overload
     *
     * returns true if the (current object) row and column
     * is equal to the right hand operand object row and column
     */
    bool operator==(CGridPosition other) const;
};

#endif /* CGRIDPOSITION_H */
