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
 * <B>�ܹ��� �κ�</B>�� �ʿ��� �⺻ �Լ��� ������ �������̽��̴�.
 *
 * �ܹ��� ������� �Ʒ� �׸��� ���� �ϳ��� ������ ���� ������� ���� �(driving motion)�� ���� ��ȯ �(steering motion)�� ������ �������̴�.
 * �ܹ��� �κ��� ��� ���ӵ��� ���ӵ��� ����Ǵ� ���� Ư¡�̴�.
 * ������ ����� ���� ������(differential drive)�� ������ ������(omni-directional drive) �� �پ��� ������ ������� ���ⱸ��(forward kinematics)�� ���� �ܹ��� ������� �Ϲ�ȭ �����ϰ�,
 * ���� �� �ý��� ����, �κ� ���п��� ������ ��鿡���� �̵�ü�� ���� �⺻ �𵨷� �θ� ���ȴ�.
 *
 * \image html unicycle_robot.png "�ܹ��� �κ� (Unicycle Robot)"
 * \image latex unicycle_robot.png "�ܹ��� �κ� (Unicycle Robot)" width=0.1\textwidth
 *
 * �ܹ��� �����Ⱑ �ƴ� �ٸ� ������ ������� uRON���� �����Ǵ� ���ⱸ�а� ���ⱸ���� ���� �̿� �����ϴ�.
 * ���� ���, ���� �������� ���ⱸ���� ���� <I>�� ������ �ӵ�</I>�� <I>�κ��� ���ӵ��� ���ӵ�</I>�� ��ȯ�Ǹ�,
 * ���ⱸ��(inverse kinematics)�� ���� <I>�κ��� ���ӵ��� ���ӵ�</I>�� <I>�� ������ �ӵ�</I>�� ��ȯ�ȴ�.
 *
 * \image html differential_drive.png "���� �������� �ⱸ��"
 * \image latex differential_drive.png "���� �������� �ⱸ��" width=0.5\textwidth
 *
 * @see DiffDriveKinematics ���� �������� �ⱸ��
 * @see FourMecanumKinematics �� ���� ��ī�� ������ ����ϴ� �������� �ⱸ��
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
	 * �ٸ� �̵� ��� ������ �κ��� ��� ����
	 * @return �̵� ����� ���� ���� ����
	 */
	inline virtual bool MoveForward(){ return ControlVelocity(Polar(paramMaxVelocity.linear, 0)); }
   /**
	 * �ٸ� �̵� ��� ������ �κ��� ��� ����
	 * @return �̵� ����� ���� ���� ����
	 */
	inline virtual bool MoveBackward(void){ return ControlVelocity(Polar(-paramMaxVelocity.linear, 0)); }
    /**
     * �ٸ� �̵� ��� ������ �κ��� ��� �������� ȸ��
     * @return �̵� ����� ���� ���� ����
     */
	inline virtual bool TurnLeft(void){ return ControlVelocity(Polar(0, paramMaxVelocity.angular)); }
	 /**
	 * �ٸ� �̵� ��� ������ �κ��� ��� ���������� ȸ��
	 * @return �̵� ����� ���� ���� ����
	 */
	inline virtual bool TurnRight(void){ return ControlVelocity(Polar(0, -paramMaxVelocity.angular)); }
	/**
	 * �̵� ��ɿ� ���� �ִ� ���� �ӵ��� ����
	 * @param velocity �ִ� ���� �ӵ� (���ӵ� �⺻��: 0.3, ���ӵ� �⺻��: MATH_DEG2RAD(45)) (���ӵ� ����: [m/s], ���ӵ� ����: [rad/s])
	 * @see MoveForward, MoveBackward, TurnLeft, TurnRight, MoveDelta, TurnDelta
	 */
	inline virtual void SetMaxVelocity(const Polar& velocity){ paramMaxVelocity = velocity; }
	/**
	 * �̵� ��ɿ� ���Ǵ� �ִ� ���� �ӵ��� ��ȯ
	 * @return �ְ� ���� �ӵ� (���ӵ� ����: [m/s], ���ӵ� ����: [rad/s])
	 * @see MoveForward, MoveBackward, TurnLeft, TurnRight, MoveDelta, TurnDelta
	 */
	inline virtual Polar GetMaxVelocity(void){ return paramMaxVelocity; }
	/**
	 * �̵� ��ɿ� ���� �ִ� ���� ���ӵ��� ����
	 * @param acceleration �ִ� ���� ���ӵ� (���ӵ� �⺻��: 0.3, ���ӵ� �⺻��: MATH_DEG2RAD(45)) (���ӵ� ����: [m/s^2], ���ӵ� ����: [rad/s^2])
	 * @see MoveForward, MoveBackward, TurnLeft, TurnRight, MoveDelta, TurnDelta
	 */
	inline virtual void SetMaxAcceleration(const Polar& acceleration){ paramMaxAcceleration = acceleration; }
	/**
	 * �̵� ��ɿ� ���Ǵ� �ִ� ���� ���ӵ� ��ȯ
	 * @return �ִ� ���� ���ӵ� (���ӵ� ����: [m/s^2], ���ӵ� ����: [rad/s^2])
	 * @see MoveForward, MoveBackward, TurnLeft, TurnRight, MoveDelta, TurnDelta
	 */
	inline virtual Polar GetMaxAcceleration(void){ return paramMaxAcceleration; }
	/**
	 * �κ��� ���� �ӵ� ���� (���ӵ� �ʱⰪ: 0, ���ӵ� �ʱⰪ: 0)
	 * @param velocity �κ��� �ӵ� (���ӵ� ����: [m/s], ���ӵ� ����: [rad/s])
	 */
	inline virtual void SetVelocity(const Polar& velocity){ robotVelocity = velocity; }
	/**
	 * �κ��� ���� �ӵ� ��ȯ
	 * @return �κ��� �ӵ� (���ӵ� ����: [m/s], ���ӵ� ����: [rad/s])
	 */
	inline virtual Polar GetVelocity(void){ return robotVelocity; }
	/**
	 * ���� �κ��� �ӵ��� �־��� ��ǥ �ӵ��� ����
	 * @param velocity ��ǥ �ӵ� (���ӵ� ����: [m/s], ���ӵ� ����: [rad/s])
	 * @return �ӵ� ���� ����� ���� ���� ����
	 */
	virtual bool ControlVelocity(Polar velocity) = 0;
	// added function
	/**
	 * �κ��� �־��� ��ġ�� ���Ⱒ���� �̵� (���� ���� ���� ��ǥ �̵� ���)
	 * @param target �κ��� ������ �ڼ� (�Ÿ� ����: [m], ���� ����: [rad])
	 * @return �̵� ��� ������ ���� ����
	 */
	inline bool GoToPose(Pose target){ return GoToPosition(Point(target.x, target.y), true, target.theta); }
	/**
	 * �̵� �κ��� ������ ��ġ�� ������ �̵� (���� ���� ���� ��ǥ �̵� ���) (blocking function, �̵� ���� �� �Լ� ����)
	 * @param target �̵��� �κ��� ���� ��ġ (����: [m])
	 * @return �̵� ����� ���� ���� ����, �̵� ��� ������ ������ ��� �̵� ��� �Ϸ� ����
	 */
	inline bool GoToPoseB(Pose target){ return GoToPositionB(Point(target.x, target.y), true, target.theta); }
	/**
	 * �κ��� ����
	 * @return ���� ����� ���� ���� ����
	 */
	inline bool Stop(){ return ControlVelocity(Polar(0, 0)); }
};	// class


#endif /* CUNICYCLEROBOT_H_ */
