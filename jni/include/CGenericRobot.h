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
	/**
	 * 다른 이동 명령 전까지 로봇을 계속 전진
	 * @return 이동 명령의 전달 성공 여부
	 */
	virtual bool MoveForward(void){ return false; }
	/**
	 * 다른 이동 명령 전까지 로봇을 계속 후진
	 * @return 이동 명령의 전달 성공 여부
	 */
	virtual bool MoveBackward(void){ return false; }
	 /**
	 * 다른 이동 명령 전까지 로봇을 계속 왼쪽으로 회전
	 * @return 이동 명령의 전달 성공 여부
	 */
	virtual bool TurnLeft(void){ return false; }
	/**
	 * 다른 이동 명령 전까지 로봇을 계속 오른쪽으로 회전
	 * @return 이동 명령의 전달 성공 여부
	 */
	virtual bool TurnRight(void){ return false; }
	  /**
	 * 로봇을 정해진 거리만큼 전후진
	 * @param delta 이동할 거리 (거리가 양수인 경우 전진, 음수인 경우 후진) (단위: [m])
	 * @return 이동 명령의 전달 성공 여부
	 */
	virtual bool MoveDelta(double delta){ return false; }
	/**
	 * 로봇을 정해진 각도만큼 회전
	 * @param delta 회전할 각도 (각도가 양수이면 왼쪽, 음수인 경우 오른쪽으로 회전) (단위: [rad])
	 * @return 이동 명령의 전달 성공 여부
	 */
	virtual bool TurnDelta(double delta){ return false; }
	/**
	 * 로봇을 주어진 위치와 방향각으로 이동 (지도 상의 절대 좌표 이동 명령)
	 * @param target 로봇의 목적지 자세 (거리 단위: [m], 각도 단위: [rad])
	 * @return 이동 명령 전달의 성공 여부
	 */
	virtual bool GoToPose(Point target){ return false; }
	/**
	 * 로봇을 정지
	 * @return 정지 명령의 전달 성공 여부
	 */
	virtual bool Stop(void){ return false; }
	/**
	 * 장치 LED
	 * @param which 단위 bit  예) 1,2,3번의 위치는 bit연산으로 111 -> 0x07
	 * @return led 명령의 전달 성공 여부
	 */
	virtual bool SetLed(int which){ return false; }
	/**
	 * 사용자가 정의  명령
	 * @param cmd 단위 명령 번호  예) 1:청소기능, 2:청소예약기능 ...
	 * @return cmd 명령의 전달 성공 여부
	 */
	virtual bool Command(int cmd){ return false; }

	// blocking function
	/**
	 * 로봇을 정해진 거리만큼 전후진 (blocking function, 이동 종료 후 함수 종료)
	 * @param delta 이동할 거리 (거리가 양수인 경우 전진, 음수인 경우 후진) (단위: [m])
	 * @return 이동 명령의 전달 성공 여부, 이동 명령 전달이 성공된 경우 이동 명령 완료 여부
	 */
	virtual bool MoveDeltaB(double delta){ return false; }
	/**
	 * 로봇을 정해진 각도만큼 회전 (blocking function, 이동 종료 후 함수 종료)
	 *
	 * 최대 회전 각도는 [-uRON_PI, +uRON_PI)
	 * @param delta 회전할 각도 (각도가 양수이면 왼쪽, 음수인 경우 오른쪽으로 회전) (단위: [rad])
	 * @return 이동 명령의 전달 성공 여부, 이동 명령 전달이 성공된 경우 이동 명령 완료 여부
	 */
	virtual bool TurnDeltaB(double delta){ return false; }
	/**
	 * 이동 로봇을 지정된 위치와 각도로 이동 (지도 상의 절대 좌표 이동 명령) (blocking function, 이동 종료 후 함수 종료)
	 * @param target 이동할 로봇의 절대 위치 (단위: [m])
	 * @return 이동 명령의 전달 성공 여부, 이동 명령 전달이 성공된 경우 이동 명령 완료 여부
	 */
	virtual bool GoToPoseB(Point target){ return false; }

	// displacement
	/**
	 * 이동 명령에 사용될 최대 운행 속도를 설정
	 * @param velocity 최대 운행 속도 (선속도 단위: [m/s], 각속도 단위: [rad/s])
	 * @see MoveForward, MoveBackward, TurnLeft, TurnRight, MoveDelta, TurnDelta
	 */
	virtual void SetMaxVelocity(const Polar& velocity){ }
	/**
	 * 이동 명령에 사용되는 최대 운행 속도를 반환
	 * @return 최고 운행 속도 (선속도 단위: [m/s], 각속도 단위: [rad/s])
	 * @see MoveForward, MoveBackward, TurnLeft, TurnRight, MoveDelta, TurnDelta
	 */
	virtual Polar GetMaxVelocity(void){ return Polar(0,0); }
	/**
	 * 이동 명령에 사용될 최대 운행 가속도를 설정
	 * @param acceleration 최대 운행 가속도 (선속도 단위: [m/s^2], 각속도 단위: [rad/s^2])
	 * @see MoveForward, MoveBackward, TurnLeft, TurnRight, MoveDelta, TurnDelta
	 */
	virtual void SetMaxAcceleration(const Polar& acceleration){ }
	/**
	 * 이동 명령에 사용되는 최대 운행 가속도 반환
	 * @return 최대 운행 가속도 (선속도 단위: [m/s^2], 각속도 단위: [rad/s^2])
	 * @see MoveForward, MoveBackward, TurnLeft, TurnRight, MoveDelta, TurnDelta
	 */
	virtual Polar GetMaxAcceleration(void){ return Polar(0,0); }
	/**
	 * 현재 로봇의 속도 설정
	 * @param velocity 현재 로봇의 속도 (선속도 단위: [m/s], 각속도 단위: [rad/s])
	 */
	virtual void SetVelocity(const Polar& velocity){ }
	/**
	 * 현재 로봇의 속도 반환
	 * @return 현재 로봇의 속도 (선속도 단위: [m/s], 각속도 단위: [rad/s])
	 */
	virtual Polar GetVelocity(void){ return Polar(0,0); }
	/**
	 * 현재 자세를 반환
	 * @return 자세 (거리 단위: [m], 각도 단위: [rad])
	 */
	virtual Pose GetPose(void){ return Pose(0,0,0); }
	/**
	 * 로봇이 탐색한 지도를  반환
	 * @return 지도 정보 (거리 단위: [mm], flag, wall)
	 */
	virtual std::vector<PointInfo> GetMap(void){
		std::vector<PointInfo> dummy;
		return dummy;
	}
protected:
	/**
	 * 로봇을 주어진 위치와 방향각으로 이동 (지도 상의 절대 좌표 이동 명령)
	 * @param target 로봇의 목적 위치 (단위: [m])
	 * @param isFinalTurn 목적 위치에서 로봇이 정해진 방향을 바라보게 할지 여부 (기본값: false)
	 * @param finalAngle 로봇의 목적 방향각 (단위: [rad], 기본값: 0)
	 * @param isInitTurn 출발 위치에서 로봇이 회전하여 경로의 방향을 바라보게 할지 여부 (기본값: true)
	 * @return 이동 명령 전달의 성공 여부
	 */
	virtual bool GoToPosition(Point target, bool isFinalTurn = false, double finalAngle = 0, bool isInitTurn = true){
		return false;
	}
	/**
	 * 이동 로봇을 지정된 위치와 각도로 이동 (지도 상의 절대 좌표 이동 명령) (blocking function, 이동 종료 후 함수 종료)
	 * @param target 이동할 로봇의 절대 위치 (단위: [m])
	 * @param isFinalTurn 해당 위치에서 로봇이 정해진 방향각(orientation)으로 회전할지 여부 (기본값: false)
	 * @param finalAngle 로봇의 방향각 (단위: [rad], 기본값: 0)
	 * @param isInitTurn 출발 위치에서 로봇이 경로의 진행 방향으로 회전할지 여부 (기본값: true)
	 * @return 이동 명령의 전달 성공 여부, 이동 명령 전달이 성공된 경우 이동 명령 완료 여부
	 */
	virtual bool GoToPositionB(Point target, bool isFinalTurn = false, double finalAngle = 0, bool isInitTurn = true){
		return false;
	}
	/**
	 * 현재 로봇의 속도를 주어진 목표 속도로 제어
	 * @param velocity 목표 속도 (선속도 단위: [m/s], 각속도 단위: [rad/s])
	 * @return 속도 제어 명령의 전달 성공 여부
	 */
	virtual bool ControlVelocity(Polar velocity) = 0;
};


#endif /* CGENERICROBOT_H_ */
