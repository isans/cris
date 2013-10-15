/*
 * CGenericRobot.h
 *
 *  Created on: 2013. 10. 13.
 *      Author: byungchul
 */

#ifndef CGENERICROBOT_H_
#define CGENERICROBOT_H_

#include "CGenericSensor.h"

class CGenericRobot : public CGenericSensor
{
public:
	// action
	virtual bool MoveForward(void){ return false; }
	virtual bool MoveBackward(void){ return false; }
	virtual bool TurnLeft(void){ return false; }
	virtual bool TurnRight(void){ return false; }
	virtual bool MoveDelta(double delta){ return false; }
	virtual bool TurnDelta(double delta){ return false; }
	virtual bool GoToPose(Pose target){ return false; }
	virtual bool Stop(void){ return false; }
	virtual bool SetLed(int which){ return false; }
	virtual bool Command(int cmd){ return false; }

	// blocking function
	virtual bool MoveDeltaB(double delta){ return false; }
	virtual bool TurnDeltaB(double delta){ return false; }
	virtual bool GoToPoseB(Pose target){ return false; }

	// displacement
	virtual void SetMaxVelocity(const Polar& velocity){ }
	virtual Polar GetMaxVelocity(void){ return Polar(0,0); }
	virtual void SetMaxAcceleration(const Polar& acceleration){ }
	virtual Polar GetMaxAcceleration(void){ return Polar(0,0); }
	virtual void SetVelocity(const Polar& velocity){ }
	virtual Polar GetVelocity(void){ return Polar(0,0); }
	virtual Pose GetPose(void){ return Pose(0,0,0); }
	virtual std::vector<PointInfo> GetMap(void){
		std::vector<PointInfo> dummy;
		return dummy;
	}
protected:
	virtual bool GoToPosition(Point target, bool isFinalTurn = false, double finalAngle = 0, bool isInitTurn = true){
		return false;
	}
	virtual bool ControlVelocity(Polar velocity) = 0;
};


#endif /* CGENERICROBOT_H_ */
