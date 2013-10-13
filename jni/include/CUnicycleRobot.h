/*
 * CUnicycleRobot.h
 *
 *  Created on: 2013. 10. 13.
 *      Author: byungchul
 */

#ifndef CUNICYCLEROBOT_H_
#define CUNICYCLEROBOT_H_

#include "CGenericRobot.h"
#include "CMath.h"
class CUnicycleRobot : public CGenericRobot
{

protected:
	Polar robotVelocity;
	Polar paramMaxVelocity;
	Polar paramMaxAcceleration;
public:
	CUnicycleRobot(): robotVelocity(Polar(0, 0)),
		paramMaxVelocity(Polar(0.3, CRIS_DEG2RAD(45))),
		paramMaxAcceleration(Polar(0.3, CRIS_DEG2RAD(45))){}
	inline virtual bool MoveForward(){ return ControlVelocity(Polar(paramMaxVelocity.linear, 0)); }
	inline virtual bool MoveBackward(void){ return ControlVelocity(Polar(-paramMaxVelocity.linear, 0)); }
	inline virtual bool TurnLeft(void){ return ControlVelocity(Polar(0, paramMaxVelocity.angular)); }
	inline virtual bool TurnRight(void){ return ControlVelocity(Polar(0, -paramMaxVelocity.angular)); }
	inline virtual void SetMaxVelocity(const Polar& velocity){ paramMaxVelocity = velocity; }
	inline virtual Polar GetMaxVelocity(void){ return paramMaxVelocity; }
	inline virtual void SetMaxAcceleration(const Polar& acceleration){ paramMaxAcceleration = acceleration; }
	inline virtual Polar GetMaxAcceleration(void){ return paramMaxAcceleration; }
	inline virtual void SetVelocity(const Polar& velocity){ robotVelocity = velocity; }
	inline virtual Polar GetVelocity(void){ return robotVelocity; }
	virtual bool ControlVelocity(Polar velocity) = 0;
	// added function
	inline bool GoToPose(Pose target){ return GoToPosition(Point(target.x, target.y), true, target.theta); }
	inline bool Stop(){ return ControlVelocity(Polar(0, 0)); }
};	// class


#endif /* CUNICYCLEROBOT_H_ */
