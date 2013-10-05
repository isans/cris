
#pragma once

#include "CMath.h"
#include "CIK.h"
#include "CUnicycleRobot.h"

using namespace cris;

// vendor's examples
class OLLO: public CUnicycleRobot
{
	float wheel_base;
public:
	virtual void loadConfig_sensorSpecific(
		CConfigFileBase &configSource,
		const std::string& section ){
			wheel_base	= configSource.read_float(section, "wheel_base", 0);
	}
	virtual bool SetLed(int which){ return true; }	
	void initialize(){
		// code here
	}
	void doProcess(){
		// code here
	}
protected:	
	bool ControlVelocity(Polar velocity){
		cris::DiffDriveWheel wheelVel;
		cris::DiffDriveKinematics::Inverse(velocity, wheel_base, wheelVel);
		// code here
		return true;
	}
};
