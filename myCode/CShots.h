#ifndef CSHOTS_H
#define CSHOTS_H

#include "CGridPosition.h"

class CShots {
public:
    enum Impact {
        NONE,
        HIT,
        SUNKEN
    };

    CShots(const CGridPosition& targetPosition);

    const CGridPosition& getTargetPosition() const;


private:
    CGridPosition targetPosition;

};

#endif // CSHOTS_H
