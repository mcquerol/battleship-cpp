
#ifndef CSHOT_H_
#define CSHOT_H_
#include "CGridPosition.h"

class CShots
{
private:

	/** CGridPosition targetPosition
	 *
	 * coordinate object for which square to hit a ship
	 */
    CGridPosition targetPosition;
public:

	/** enum shots
	 *
	 * this enum defines each state of the board as
	 * one of these possible states
	 */
	enum Impact
	{
		HIT = 0,
		SUNKEN = 1,
		NONE = 2
	};

	/** CGridPosition constructor
	 *
	 * define a shot based on a desired position on the board
	 * to hit a ship
	 */
	CShots(CGridPosition targetPosition);

	/** CGridPosition::getTargetPosition
	 *
	 * returns the targetPosition
	 */
    CGridPosition getTargetPosition();

};

#endif /* CSHOT_H_ */
