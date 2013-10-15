/*
 * CGenericSensor.h
 *
 *  Created on: 2013. 10. 13.
 *      Author: byungchul
 */

#ifndef CGENERICSENSOR_H_
#define CGENERICSENSOR_H_
#include <string>
#include <vector>
#include "CPoses.h"
#include "macros.h"


class CUncopiable
{
private:
	CUncopiable(const CUncopiable &);  // This doesn't need to be implemented anywhere
	const CUncopiable& operator =(const CUncopiable &);   // This doesn't need to be implemented anywhere
public:
	CUncopiable() {  }
}; // End of class def.

class CGenericSensor : public CUncopiable
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
public:

	/**
	 * 로봇을 초기화 하는 함수 , 표준 정의에서 제외
	 * @return 초기화 성공 여부
	 */
	virtual bool initialize(){ return true; }
	/**
	 * 주기가 있는 함수, 표준 정의에서 제외
	 * @return void
	 */
	virtual void doProcess() = 0;
	/**
	 * 주기가 있는 함수, 표준 정의에서 제외
	 * @return void
	 */
	inline TSensorState getState() const { return m_state; }
	/**
	 * 주기가 있는 함수, 표준 정의에서 제외
	 * @return doProcess의 주기 ( 단위: [msec]
	 */
	inline double getProcessRate() const { return m_process_rate; }
	/**
	 * 로봇의 id를 반환 한다. ex) iclebo, ollo, 표준 정의에서 제외
	 * @return 로봇의  id
	 */
	inline std::string getVendorID() const { return m_vendorID; }

};


#endif /* CGENERICSENSOR_H_ */
