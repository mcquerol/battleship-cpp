
#include "CShots.h"

CShots::CShots(const CGridPosition& targetPosition) : targetPosition(targetPosition) {}

const CGridPosition& CShots::getTargetPosition() const
{
    return targetPosition;
}
