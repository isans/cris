/*
 * CUnicycleRobot.h
 *
 *  Created on: 2013. 10. 13.
 *      Author: byungchul
 */

#ifndef CUNICYCLEROBOT_H_
#define CUNICYCLEROBOT_H_

#include "CGenericRobot.h"
#include "CMath.h"


/**
 * <B>Unicyle Robot Interface</B>
 *
 * <B>외바퀴 로봇</B>에 필요한 기본 함수를 정의한 인터페이스이다.
 *
 * 외바퀴 구동기는 아래 그림과 같이 하나의 바퀴를 가진 구동기로 직진 운동(driving motion)과 방향 전환 운동(steering motion)이 가능한 구동기이다.
 * 외바퀴 로봇의 운동은 선속도와 각속도로 기술되는 것이 특징이다.
 * 이차원 평면의 차륜 구동기(differential drive)나 전방향 구동기(omni-directional drive) 등 다양한 형태의 구동기는 정기구학(forward kinematics)를 통해 외바퀴 구동기로 일반화 가능하고,
 * 제어 및 시스템 공학, 로봇 공학에서 이차원 평면에서의 이동체에 대한 기본 모델로 널리 사용된다.
 *
 * \image html unicycle_robot.png "외바퀴 로봇 (Unicycle Robot)"
 * \image latex unicycle_robot.png "외바퀴 로봇 (Unicycle Robot)" width=0.1\textwidth
 *
 * 외바퀴 구동기가 아닌 다른 형태의 구동기는 uRON에서 제공되는 정기구학과 역기구학을 통해 이용 가능하다.
 * 예를 들어, 차륜 구동기의 정기구학을 통해 <I>양 바퀴의 속도</I>가 <I>로봇의 선속도과 각속도</I>로 변환되며,
 * 역기구학(inverse kinematics)을 통해 <I>로봇의 선속도와 각속도</I>가 <I>양 바퀴의 속도</I>로 변환된다.
 *
 * \image html differential_drive.png "차륜 구동기의 기구학"
 * \image latex differential_drive.png "차륜 구동기의 기구학" width=0.5\textwidth
 *
 * @see DiffDriveKinematics 차륜 구동기의 기구학
 * @see FourMecanumKinematics 네 개의 메카늄 바퀴를 사용하는 구동기의 기구학
 */
class CUnicycleRobot : public CGenericRobot
{

protected:
	Polar robotVelocity;
	Polar paramMaxVelocity;
	Polar paramMaxAcceleration;
public:
	CUnicycleRobot(): robotVelocity(Polar(0, 0)),
		paramMaxVelocity(Polar(0.3, CRIS_DEG2RAD(45))),
		paramMaxAcceleration(Polar(0.3, CRIS_DEG2RAD(45))){}
	/**
	 * 다른 이동 명령 전까지 로봇을 계속 전진
	 * @return 이동 명령의 전달 성공 여부
	 */
	inline virtual bool MoveForward(){ return ControlVelocity(Polar(paramMaxVelocity.linear, 0)); }
   /**
	 * 다른 이동 명령 전까지 로봇을 계속 후진
	 * @return 이동 명령의 전달 성공 여부
	 */
	inline virtual bool MoveBackward(void){ return ControlVelocity(Polar(-paramMaxVelocity.linear, 0)); }
    /**
     * 다른 이동 명령 전까지 로봇을 계속 왼쪽으로 회전
     * @return 이동 명령의 전달 성공 여부
     */
	inline virtual bool TurnLeft(void){ return ControlVelocity(Polar(0, paramMaxVelocity.angular)); }
	 /**
	 * 다른 이동 명령 전까지 로봇을 계속 오른쪽으로 회전
	 * @return 이동 명령의 전달 성공 여부
	 */
	inline virtual bool TurnRight(void){ return ControlVelocity(Polar(0, -paramMaxVelocity.angular)); }
	/**
	 * 이동 명령에 사용될 최대 운행 속도를 설정
	 * @param velocity 최대 운행 속도 (선속도 기본값: 0.3, 각속도 기본값: MATH_DEG2RAD(45)) (선속도 단위: [m/s], 각속도 단위: [rad/s])
	 * @see MoveForward, MoveBackward, TurnLeft, TurnRight, MoveDelta, TurnDelta
	 */
	inline virtual void SetMaxVelocity(const Polar& velocity){ paramMaxVelocity = velocity; }
	/**
	 * 이동 명령에 사용되는 최대 운행 속도를 반환
	 * @return 최고 운행 속도 (선속도 단위: [m/s], 각속도 단위: [rad/s])
	 * @see MoveForward, MoveBackward, TurnLeft, TurnRight, MoveDelta, TurnDelta
	 */
	inline virtual Polar GetMaxVelocity(void){ return paramMaxVelocity; }
	/**
	 * 이동 명령에 사용될 최대 운행 가속도를 설정
	 * @param acceleration 최대 운행 가속도 (선속도 기본값: 0.3, 각속도 기본값: MATH_DEG2RAD(45)) (선속도 단위: [m/s^2], 각속도 단위: [rad/s^2])
	 * @see MoveForward, MoveBackward, TurnLeft, TurnRight, MoveDelta, TurnDelta
	 */
	inline virtual void SetMaxAcceleration(const Polar& acceleration){ paramMaxAcceleration = acceleration; }
	/**
	 * 이동 명령에 사용되는 최대 운행 가속도 반환
	 * @return 최대 운행 가속도 (선속도 단위: [m/s^2], 각속도 단위: [rad/s^2])
	 * @see MoveForward, MoveBackward, TurnLeft, TurnRight, MoveDelta, TurnDelta
	 */
	inline virtual Polar GetMaxAcceleration(void){ return paramMaxAcceleration; }
	/**
	 * 로봇의 현재 속도 설정 (선속도 초기값: 0, 각속도 초기값: 0)
	 * @param velocity 로봇의 속도 (선속도 단위: [m/s], 각속도 단위: [rad/s])
	 */
	inline virtual void SetVelocity(const Polar& velocity){ robotVelocity = velocity; }
	/**
	 * 로봇의 현재 속도 반환
	 * @return 로봇의 속도 (선속도 단위: [m/s], 각속도 단위: [rad/s])
	 */
	inline virtual Polar GetVelocity(void){ return robotVelocity; }
	/**
	 * 현재 로봇의 속도를 주어진 목표 속도로 제어
	 * @param velocity 목표 속도 (선속도 단위: [m/s], 각속도 단위: [rad/s])
	 * @return 속도 제어 명령의 전달 성공 여부
	 */
	virtual bool ControlVelocity(Polar velocity) = 0;
	// added function
	/**
	 * 로봇을 주어진 위치와 방향각으로 이동 (지도 상의 절대 좌표 이동 명령)
	 * @param target 로봇의 목적지 자세 (거리 단위: [m], 각도 단위: [rad])
	 * @return 이동 명령 전달의 성공 여부
	 */
	inline bool GoToPose(Pose target){ return GoToPosition(Point(target.x, target.y), true, target.theta); }
	/**
	 * 이동 로봇을 지정된 위치와 각도로 이동 (지도 상의 절대 좌표 이동 명령) (blocking function, 이동 종료 후 함수 종료)
	 * @param target 이동할 로봇의 절대 위치 (단위: [m])
	 * @return 이동 명령의 전달 성공 여부, 이동 명령 전달이 성공된 경우 이동 명령 완료 여부
	 */
	inline bool GoToPoseB(Pose target){ return GoToPositionB(Point(target.x, target.y), true, target.theta); }
	/**
	 * 로봇을 정지
	 * @return 정지 명령의 전달 성공 여부
	 */
	inline bool Stop(){ return ControlVelocity(Polar(0, 0)); }
};	// class


#endif /* CUNICYCLEROBOT_H_ */
