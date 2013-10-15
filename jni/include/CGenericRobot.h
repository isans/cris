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
	 * �ٸ� �̵� ��� ������ �κ��� ��� ����
	 * @return �̵� ����� ���� ���� ����
	 */
	virtual bool MoveForward(void){ return false; }
	/**
	 * �ٸ� �̵� ��� ������ �κ��� ��� ����
	 * @return �̵� ����� ���� ���� ����
	 */
	virtual bool MoveBackward(void){ return false; }
	 /**
	 * �ٸ� �̵� ��� ������ �κ��� ��� �������� ȸ��
	 * @return �̵� ����� ���� ���� ����
	 */
	virtual bool TurnLeft(void){ return false; }
	/**
	 * �ٸ� �̵� ��� ������ �κ��� ��� ���������� ȸ��
	 * @return �̵� ����� ���� ���� ����
	 */
	virtual bool TurnRight(void){ return false; }
	  /**
	 * �κ��� ������ �Ÿ���ŭ ������
	 * @param delta �̵��� �Ÿ� (�Ÿ��� ����� ��� ����, ������ ��� ����) (����: [m])
	 * @return �̵� ����� ���� ���� ����
	 */
	virtual bool MoveDelta(double delta){ return false; }
	/**
	 * �κ��� ������ ������ŭ ȸ��
	 * @param delta ȸ���� ���� (������ ����̸� ����, ������ ��� ���������� ȸ��) (����: [rad])
	 * @return �̵� ����� ���� ���� ����
	 */
	virtual bool TurnDelta(double delta){ return false; }
	/**
	 * �κ��� �־��� ��ġ�� ���Ⱒ���� �̵� (���� ���� ���� ��ǥ �̵� ���)
	 * @param target �κ��� ������ �ڼ� (�Ÿ� ����: [m], ���� ����: [rad])
	 * @return �̵� ��� ������ ���� ����
	 */
	virtual bool GoToPose(Point target){ return false; }
	/**
	 * �κ��� ����
	 * @return ���� ����� ���� ���� ����
	 */
	virtual bool Stop(void){ return false; }
	/**
	 * ��ġ LED
	 * @param which ���� bit  ��) 1,2,3���� ��ġ�� bit�������� 111 -> 0x07
	 * @return led ����� ���� ���� ����
	 */
	virtual bool SetLed(int which){ return false; }
	/**
	 * ����ڰ� ����  ���
	 * @param cmd ���� ��� ��ȣ  ��) 1:û�ұ��, 2:û�ҿ����� ...
	 * @return cmd ����� ���� ���� ����
	 */
	virtual bool Command(int cmd){ return false; }

	// blocking function
	/**
	 * �κ��� ������ �Ÿ���ŭ ������ (blocking function, �̵� ���� �� �Լ� ����)
	 * @param delta �̵��� �Ÿ� (�Ÿ��� ����� ��� ����, ������ ��� ����) (����: [m])
	 * @return �̵� ����� ���� ���� ����, �̵� ��� ������ ������ ��� �̵� ��� �Ϸ� ����
	 */
	virtual bool MoveDeltaB(double delta){ return false; }
	/**
	 * �κ��� ������ ������ŭ ȸ�� (blocking function, �̵� ���� �� �Լ� ����)
	 *
	 * �ִ� ȸ�� ������ [-uRON_PI, +uRON_PI)
	 * @param delta ȸ���� ���� (������ ����̸� ����, ������ ��� ���������� ȸ��) (����: [rad])
	 * @return �̵� ����� ���� ���� ����, �̵� ��� ������ ������ ��� �̵� ��� �Ϸ� ����
	 */
	virtual bool TurnDeltaB(double delta){ return false; }
	/**
	 * �̵� �κ��� ������ ��ġ�� ������ �̵� (���� ���� ���� ��ǥ �̵� ���) (blocking function, �̵� ���� �� �Լ� ����)
	 * @param target �̵��� �κ��� ���� ��ġ (����: [m])
	 * @return �̵� ����� ���� ���� ����, �̵� ��� ������ ������ ��� �̵� ��� �Ϸ� ����
	 */
	virtual bool GoToPoseB(Point target){ return false; }

	// displacement
	/**
	 * �̵� ��ɿ� ���� �ִ� ���� �ӵ��� ����
	 * @param velocity �ִ� ���� �ӵ� (���ӵ� ����: [m/s], ���ӵ� ����: [rad/s])
	 * @see MoveForward, MoveBackward, TurnLeft, TurnRight, MoveDelta, TurnDelta
	 */
	virtual void SetMaxVelocity(const Polar& velocity){ }
	/**
	 * �̵� ��ɿ� ���Ǵ� �ִ� ���� �ӵ��� ��ȯ
	 * @return �ְ� ���� �ӵ� (���ӵ� ����: [m/s], ���ӵ� ����: [rad/s])
	 * @see MoveForward, MoveBackward, TurnLeft, TurnRight, MoveDelta, TurnDelta
	 */
	virtual Polar GetMaxVelocity(void){ return Polar(0,0); }
	/**
	 * �̵� ��ɿ� ���� �ִ� ���� ���ӵ��� ����
	 * @param acceleration �ִ� ���� ���ӵ� (���ӵ� ����: [m/s^2], ���ӵ� ����: [rad/s^2])
	 * @see MoveForward, MoveBackward, TurnLeft, TurnRight, MoveDelta, TurnDelta
	 */
	virtual void SetMaxAcceleration(const Polar& acceleration){ }
	/**
	 * �̵� ��ɿ� ���Ǵ� �ִ� ���� ���ӵ� ��ȯ
	 * @return �ִ� ���� ���ӵ� (���ӵ� ����: [m/s^2], ���ӵ� ����: [rad/s^2])
	 * @see MoveForward, MoveBackward, TurnLeft, TurnRight, MoveDelta, TurnDelta
	 */
	virtual Polar GetMaxAcceleration(void){ return Polar(0,0); }
	/**
	 * ���� �κ��� �ӵ� ����
	 * @param velocity ���� �κ��� �ӵ� (���ӵ� ����: [m/s], ���ӵ� ����: [rad/s])
	 */
	virtual void SetVelocity(const Polar& velocity){ }
	/**
	 * ���� �κ��� �ӵ� ��ȯ
	 * @return ���� �κ��� �ӵ� (���ӵ� ����: [m/s], ���ӵ� ����: [rad/s])
	 */
	virtual Polar GetVelocity(void){ return Polar(0,0); }
	/**
	 * ���� �ڼ��� ��ȯ
	 * @return �ڼ� (�Ÿ� ����: [m], ���� ����: [rad])
	 */
	virtual Pose GetPose(void){ return Pose(0,0,0); }
	/**
	 * �κ��� Ž���� ������  ��ȯ
	 * @return ���� ���� (�Ÿ� ����: [mm], flag, wall)
	 */
	virtual std::vector<PointInfo> GetMap(void){
		std::vector<PointInfo> dummy;
		return dummy;
	}
protected:
	/**
	 * �κ��� �־��� ��ġ�� ���Ⱒ���� �̵� (���� ���� ���� ��ǥ �̵� ���)
	 * @param target �κ��� ���� ��ġ (����: [m])
	 * @param isFinalTurn ���� ��ġ���� �κ��� ������ ������ �ٶ󺸰� ���� ���� (�⺻��: false)
	 * @param finalAngle �κ��� ���� ���Ⱒ (����: [rad], �⺻��: 0)
	 * @param isInitTurn ��� ��ġ���� �κ��� ȸ���Ͽ� ����� ������ �ٶ󺸰� ���� ���� (�⺻��: true)
	 * @return �̵� ��� ������ ���� ����
	 */
	virtual bool GoToPosition(Point target, bool isFinalTurn = false, double finalAngle = 0, bool isInitTurn = true){
		return false;
	}
	/**
	 * �̵� �κ��� ������ ��ġ�� ������ �̵� (���� ���� ���� ��ǥ �̵� ���) (blocking function, �̵� ���� �� �Լ� ����)
	 * @param target �̵��� �κ��� ���� ��ġ (����: [m])
	 * @param isFinalTurn �ش� ��ġ���� �κ��� ������ ���Ⱒ(orientation)���� ȸ������ ���� (�⺻��: false)
	 * @param finalAngle �κ��� ���Ⱒ (����: [rad], �⺻��: 0)
	 * @param isInitTurn ��� ��ġ���� �κ��� ����� ���� �������� ȸ������ ���� (�⺻��: true)
	 * @return �̵� ����� ���� ���� ����, �̵� ��� ������ ������ ��� �̵� ��� �Ϸ� ����
	 */
	virtual bool GoToPositionB(Point target, bool isFinalTurn = false, double finalAngle = 0, bool isInitTurn = true){
		return false;
	}
	/**
	 * ���� �κ��� �ӵ��� �־��� ��ǥ �ӵ��� ����
	 * @param velocity ��ǥ �ӵ� (���ӵ� ����: [m/s], ���ӵ� ����: [rad/s])
	 * @return �ӵ� ���� ����� ���� ���� ����
	 */
	virtual bool ControlVelocity(Polar velocity) = 0;
};


#endif /* CGENERICROBOT_H_ */
