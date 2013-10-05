
#pragma once

#include "CMath.h"
#include "CIK.h"
#include "CUnicycleRobot.h"

using namespace cris;

// vendor's examples
class iClebo : public CUnicycleRobot
{
	float wheel_base;
public:
	virtual void loadConfig_sensorSpecific(
		CConfigFileBase &configSource,
		const std::string& section ){
			wheel_base	= configSource.read_float(section, "wheel_base", 0);
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
	void initialize(){
		// code here.
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
		cris::DiffDriveWheel wheelVel;
		cris::DiffDriveKinematics::Inverse(velocity, wheel_base, wheelVel);
		// code here
		return true;
	}
};
