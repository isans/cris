
// version 0.5

#include "Math.h"
#include "CConfigFileBase.h"
#include "CPoses.h"

class CGenericSensor : public CUncopiable
{
public:
	enum TSensorState
	{
		ssInitializing = 0,
		ssWorking,
		ssError
	};
	CGenericSensor( ):m_process_rate(0), 
		m_sensorLabel("UNNAMED_SENSOR"), 
		m_verbose(false), 
		m_state( ssInitializing ),
		m_vendorID("UNKNOWN_ID"){ }
	virtual ~CGenericSensor(){ }
protected:
	double	m_process_rate; 
	std::string  m_sensorLabel; 
	TSensorState    m_state;
	bool            m_verbose;
	std::string m_vendorID;
	virtual void loadConfig_sensorSpecific(
		CConfigFileBase &configSource,
		const std::string& section ) = 0;
public:	
	inline void loadConfig( 
		CConfigFileBase &configSource, 
		const std::string& section ){
	CRIS_START
		m_process_rate = cfg.read_double(sect, "process_rate", 0);
		m_sensorLabel = cfg.read_string(sect, "sensorLabel", m_sensorLabel);
		m_vendorID = cfg.read_string(sect, "vendorID", m_vendorID);
		loadConfig_sensorSpecific(cfg, sect);
	CRIS_END
	}
	virtual void initialize(){ }
	virtual void doProcess() = 0;	
	
	inline TSensorState getState() const { return m_state; }
	inline double getProcessRate() const { return m_process_rate; }
	inline std::string getSensorLabel() const { return m_sensorLabel; }
	inline std::string getVendorID() const { return m_vendorID; }
}

// communication with RSP
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
	virtual std::vector<PointInfo> GetMap(void){ return ; }
protected:
	virtual bool GoToPosition(Point target, bool isFinalTurn = false, double finalAngle = 0, bool isInitTurn = true){
		return false;
	}
	virtual bool ControlVelocity(Polar velocity) = 0;	
}
class CUnicycleRobot : public CGenericRobot
{
protected:
	Polar robotVelocity;
	Polar paramMaxVelocity;
	Polar paramMaxAcceleration;
public:
	UnicycleRobotBase(): robotVelocity(Polar(0, 0)), 
		paramMaxVelocity(Polar(0, 3, CRIS_DEG2RAD(45))),
		paramMaxAcceleration(Polar(0, 3, CRIS_DEG2RAD(45))){}
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
}
// vendor's examples
class iClebo : public CUnicycleRobot
{
public:
	bool MoveDeltaB(double delta){ return true; }
	bool TurnDeltaB(double delta){ return true; }	
	bool GoToPoseB(Pose target){ return GoToPositionB(Point(target.x, target.y), true, target.theta); }
	bool GoToPosition(Point target, bool isFinalTurn = false, double finalAngle = 0, bool isInitTurn = true){
		return true;
	}
	bool GoToPositionB(Point target, bool isFinalTurn = false, double finalAngle = 0, bool isInitTurn = true){
		return true;
	}	
	bool Command(int cmd){ return true; }
	void initialize(){
	
	}
	void doProcess(){
	
	}
	std::vector<PointInfo> GetMap(){ return good; }
protected:
	SimDiffDriveAPI hwDiffDrive;
	
	bool ControlVelocity(Polar velocity){
		cris::DiffDriveWheel wheelVel;
		cris::DiffDriveKinematics::Inverse(velocity, hwDiffDrive.WHEEL_BASE, wheelVel);
		hwDiffDrive.SendRefWheelVelocity(wheelVel.left, wheelVel.right);
		return true;
	}
}
class OLLO: public CUnicycleRobot
{
public:
	virtual bool SetLed(int which){ return true; }	
	void initialize(){
	
	}
	void doProcess(){
	
	}
protected:
	SimDynamixelDriveAPI hwDynamixelDrive;
	
	bool ControlVelocity(Polar velocity){
		cris::DiffDriveWheel wheelVel;
		cris::DiffDriveKinematics::Inverse(velocity, hwDiffDrive.WHEEL_BASE, wheelVel);
		hwDynamixelDrive.SendRefWheelVelocity(wheelVel.left, wheelVel.right);
		return true;
	}
};

void main 
{
	iClebo robot;
	robot.loadConfig("/config.ini");
	robot.initialize();
	while(1)
	{
		robot.doProcess();
	}
}