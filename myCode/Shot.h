/*
 * Shot.h
 *
 *  Created on: 26 Dec 2024
 *      Author: mateo
 */

#ifndef SHOT_H_
#define SHOT_H_

#include "GridPosition.h"

class Shot
{

private:

	GridPosition targetPosition;

public:

	enum Impact
	{
		NONE,
		HIT,
		SUNKEN
	};

	Shot(GridPosition targetPosition);
	GridPosition getTargetPosition() const;

};

#endif /* SHOT_H_ */
