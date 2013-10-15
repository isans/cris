/*
 * iClebo.h
 *
 *  Created on: 2013. 10. 13.
 *      Author: byungchul
 */

#ifndef ICLEBO_H_
#define ICLEBO_H_
#include "CUnicycleRobot.h"
#include "CIK.h"

class iClebo : public CUnicycleRobot
{
	float wheel_base;
public:
	bool MoveDeltaB(double delta){
		// code here
		return true;
	}
	bool TurnDeltaB(double delta){
		// code here
		return true;
	}
	bool GoToPosition(Point target, bool isFinalTurn = false, double finalAngle = 0, bool isInitTurn = true){
		// code here
		return true;
	}
	bool GoToPositionB(Point target, bool isFinalTurn = false, double finalAngle = 0, bool isInitTurn = true){
		// code here
		return true;
	}
	bool Command(int cmd){
		// code here.
		return true;
	}
	bool initialize(){
		// code here.
		return true;
	}
	void doProcess(){
		// code here.
	}
	std::vector<PointInfo> GetMap(){
		std::vector<PointInfo> dummy;
		// code here.
		return dummy;
	}
protected:

	/**
	 * ���� �κ��� �ӵ��� �־��� ��ǥ �ӵ��� ����
	 * @param velocity ��ǥ �ӵ� (���ӵ� ����: [m/s], ���ӵ� ����: [rad/s])
	 * @return �ӵ� ���� ����� ���� ���� ����
	 * @see MoveForward, MoveBackward, TurnLeft, TurnRight, MoveDelta, TurnDelta
	 */
	bool ControlVelocity(Polar velocity){
		DPRINTF("linear:%f, angular:%f, %s", velocity.linear, velocity.angular, __FUNCTION__);
		DiffDriveWheel wheelVel;
		DiffDriveKinematics::Inverse(velocity, wheel_base, wheelVel);
		// code here

		return true;
	}
};


#endif /* ICLEBO_H_ */
