/*
 * Shot.cpp
 *
 *  Created on: 26 Dec 2024
 *      Author: mateo
 */

#include "Shot.h"

Shot::Shot(GridPosition targetPosition) : targetPosition(targetPosition)
{
}

GridPosition Shot::getTargetPosition() const
{
	return targetPosition;
}
