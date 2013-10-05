
#pragma once


#pragma once
#include "CConfigFileBase.h"
#include "CUncopiable.h"
namespace cris{
class CRIS_IMPEXP CGenericSensor : public CUncopiable
{
public:
	enum TSensorState{
		ssInitializing = 0,
		ssWorking,
		ssError
	};
	CGenericSensor( ):m_process_rate(0), 
		m_verbose(false), 
		m_state( ssInitializing ),
		m_vendorID("UNKNOWN_ID"){ }
	virtual ~CGenericSensor(){ }
protected:
	double	m_process_rate; 
	TSensorState    m_state;
	bool            m_verbose;
	std::string m_vendorID;
	virtual void loadConfig_sensorSpecific(
		CConfigFileBase &configSource,
		const std::string& section ) = 0;
public:	
	inline void loadConfig( 
		CConfigFileBase &cfg, 
		const std::string& section ){
	
		m_process_rate = cfg.read_double(section, "process_rate", 0);
		m_vendorID = cfg.read_string(section, "vendorID", m_vendorID);
		loadConfig_sensorSpecific(cfg, section);
	
	}
	virtual void initialize(){ }
	virtual void doProcess() = 0;	
	
	inline TSensorState getState() const { return m_state; }
	inline double getProcessRate() const { return m_process_rate; }
	inline std::string getVendorID() const { return m_vendorID; }
};	// class
}	// namespace