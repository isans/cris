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
	 * 현재 로봇의 속도를 주어진 목표 속도로 제어
	 * @param velocity 목표 속도 (선속도 단위: [m/s], 각속도 단위: [rad/s])
	 * @return 속도 제어 명령의 전달 성공 여부
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
