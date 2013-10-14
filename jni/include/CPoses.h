/*
 * CPoses.h
 *
 *  Created on: 2013. 10. 13.
 *      Author: byungchul
 */

#ifndef CPOSES_H_
#define CPOSES_H_

class Point
{
public:
    /**
     * ������ (�⺻��: 0)
     */
    Point() { x = y = 0; }

    /**
     * X ��� Y �� ���� �ʱ�ȭ�ϴ� ������
     * @param x X ���� ��
     * @param y Y ���� ��
     */
    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }

    /**
     * � ��
     * @param rhs � �������� ������ ��
     * @return �� �ǿ�����(operand)�� ���� ����
     */
    bool operator==(const Point& rhs) const { return (x == rhs.x) && (y == rhs.y); }

    /**
     * ��� ��
     * @param rhs ��� �������� ������ ��
     * @return �� �ǿ�����(operand)�� �ٸ� ����
     */
    bool operator!=(const Point& rhs) const { return (x != rhs.x) || (y != rhs.y); }

    /** X �� �� */
    double x;

    /** Y �� �� */
    double y;
};
class PointInfo : public Point
{
public:
	PointInfo() { x = y = 0;
	state = -1;
	}
	PointInfo(double x, double y, int type)
	{
		this->x = x;
		this->y = y;
		this->state = state;
	}
	bool operator==(const PointInfo& rhs) const { return (x == rhs.x) && (y == rhs.y) && (state == rhs.state); }
    bool operator!=(const PointInfo& rhs) const { return (x != rhs.x) || (y != rhs.y) || (state != rhs.state); }

    // û�� ����
    int state;
};
/**
 * <B>2D Pose in Rectangular Coordinates</B>
 *
 * ������ ��� ���� �ִ� ������ ��ü(rigid body)�� �ڼ�(pose)�� ǥ���Ѵ�.
 * X ��� Y ���� ���� Z �� ������ ȸ���� ���� ���� ������.
 * ������ ��鿡�� <B>�ڼ�(pose)</B>, �� X ��, Y �� ��ġ(position)�� ��ü�� ���Ⱒ(orientation)�� ǥ���ϴµ� �ַ� ���ȴ�.
 * Z �� ������ ȸ���� ���� ��ȣ�� �Ʒ� �׸��� ���� ������ ��ǥ�踦 ������.
 *
 * \image html righthand_coordinate.png "������ ��ǥ��"
 * \image latex righthand_coordinate.png "������ ��ǥ��" width=0.5\textwidth
 */
class Pose : public Point
{
public:
    /**
     * ������ (�⺻��: 0)
     */
    Pose() { x = y = theta = 0; }

    /**
     * X��, Y�� ���� ���Ⱒ�� �ʱ�ȭ�ϴ� ������
     * @param x X �� ��
     * @param y Y �� ��
     * @param theta Z �� ȸ���� ���� �� (������ ��ǥ��)
     */
    Pose(double x, double y, double theta)
    {
        this->x = x;
        this->y = y;
        this->theta = theta;
    }

    /**
     * � ��
     * @param rhs � �������� ������ ��
     * @return �� �ǿ�����(operand)�� ���� ����
     */
    bool operator==(const Pose& rhs) const { return (x == rhs.x) && (y == rhs.y) && (theta == rhs.theta); }

    /**
     * ��� ��
     * @param rhs ��� �������� ������ ��
     * @return �� �ǿ�����(operand)�� �ٸ� ����
     */
    bool operator!=(const Pose& rhs) const { return (x != rhs.x) || (y != rhs.y) || (theta != rhs.theta); }

    /** Z �࿡ ���� ȸ�� �� */
    double theta;
};

/**
 * <B>2D Vector(Point) in Polar Coordinates</B>
 *
 * ������ ����ǥ��(polar coordinates)������ ���͸� ǥ���Ѵ�.
 * ���� ���а� �� ������ ���� ������.
 * ������ ��鿡���� �κ� ��ǥ�迡���� <B>�ӵ�(velocity)</B>�� <B>���ӵ�(acceleration)</B>�� ǥ���ϴµ� �ַ� ���ȴ�.
 *
 * @see Point ������ ������ǥ��(rectangular coordinates)������ ����
 */
class Polar
{
public:
    /**
     * ������ (�⺻��: 0)
     */
    Polar() { linear = angular = 0; }

    /**
     * ���� ���а� �� ������ ���� �ʱ�ȭ�ϴ� ������
     * @param linear ���� ������ ��
     * @param angular �� ������ ��
     */
    Polar(double linear, double angular)
    {
        this->linear = linear;
        this->angular = angular;
    }

    /**
     * � ��
     * @param rhs � �������� ������ ��
     * @return �� �ǿ�����(operand)�� ���� ����
     */
    bool operator==(const Polar& rhs) const { return (linear == rhs.linear) && (angular == rhs.angular); }

    /**
     * ��� ��
     * @param rhs ��� �������� ������ ��
     * @return �� �ǿ�����(operand)�� �ٸ� ����
     */
    bool operator!=(const Polar& rhs) const { return (linear != rhs.linear) || (angular != rhs.angular); }

    /** ���� ������ �� */
    double linear;

    /** �� ������ �� */
    double angular;
};	// class

#endif /* CPOSES_H_ */
