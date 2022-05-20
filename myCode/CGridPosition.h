/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CGRIDPOSITION.H
* Author          :
* Description     :
*
*
****************************************************************************/
#include <string>
#ifndef CGRIDPOSITION_H
#define CGRIDPOSITION_H
class CGridPosition {
private:
    char row;
    int column;
public:

    CGridPosition(char row, int column);

    CGridPosition(std::string position);

    bool isValid();

    char getRow();

    int getColumn();

    //std::string operator std::string();

   // bool operator==(CGridPosition pos);

    //bool operator<(CGridPosition pos);
};
/********************
**  CLASS END
*********************/
#endif /* CGRIDPOSITION_H */
