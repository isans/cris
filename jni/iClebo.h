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
	virtual void loadConfig_sensorSpecific(
		//CConfigFileBase &configSource,
		const std::string& section ){
			//wheel_base	= configSource.read_float(section, "wheel_base", 0);
	}
	bool MoveDeltaB(double delta){ return true; }
	bool TurnDeltaB(double delta){ return true; }
	bool GoToPoseB(Pose target){ return GoToPositionB(Point(target.x, target.y), true, target.theta); }
	bool GoToPosition(Point target, bool isFinalTurn = false, double finalAngle = 0, bool isInitTurn = true){
		return true;
	}
	bool GoToPositionB(Point target, bool isFinalTurn = false, double finalAngle = 0, bool isInitTurn = true){
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

	bool ControlVelocity(Polar velocity){
		DiffDriveWheel wheelVel;
		DiffDriveKinematics::Inverse(velocity, wheel_base, wheelVel);
		// code here
		return true;
	}
};


#endif /* ICLEBO_H_ */
