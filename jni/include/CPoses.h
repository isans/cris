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
     * 생성자 (기본값: 0)
     */
    Point() { x = y = 0; }

    /**
     * X 축과 Y 축 값을 초기화하는 생성자
     * @param x X 축의 값
     * @param y Y 축의 값
     */
    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }

    /**
     * 등가 비교
     * @param rhs 등가 연산자의 오른쪽 항
     * @return 두 피연산자(operand)의 같음 여부
     */
    bool operator==(const Point& rhs) const { return (x == rhs.x) && (y == rhs.y); }

    /**
     * 상등 비교
     * @param rhs 상등 연산자의 오른쪽 항
     * @return 두 피연산자(operand)의 다름 여부
     */
    bool operator!=(const Point& rhs) const { return (x != rhs.x) || (y != rhs.y); }

    /** X 축 값 */
    double x;

    /** Y 축 값 */
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

    // 청소 상태
    int state;
};
/**
 * <B>2D Pose in Rectangular Coordinates</B>
 *
 * 이차원 평면 위에 있는 이차원 강체(rigid body)의 자세(pose)를 표현한다.
 * X 축과 Y 축의 값과 Z 축 방향의 회전에 대한 값을 가진다.
 * 이차원 평면에서 <B>자세(pose)</B>, 즉 X 축, Y 축 위치(position)와 강체의 방향각(orientation)을 표현하는데 주로 사용된다.
 * Z 축 방향의 회전에 대한 부호는 아래 그림과 같은 오른손 좌표계를 따른다.
 *
 * \image html righthand_coordinate.png "오른손 좌표계"
 * \image latex righthand_coordinate.png "오른손 좌표계" width=0.5\textwidth
 */
class Pose : public Point
{
public:
    /**
     * 생성자 (기본값: 0)
     */
    Pose() { x = y = theta = 0; }

    /**
     * X축, Y축 값와 방향각을 초기화하는 생성자
     * @param x X 축 값
     * @param y Y 축 값
     * @param theta Z 축 회전에 대한 값 (오른손 좌표계)
     */
    Pose(double x, double y, double theta)
    {
        this->x = x;
        this->y = y;
        this->theta = theta;
    }

    /**
     * 등가 비교
     * @param rhs 등가 연산자의 오른쪽 항
     * @return 두 피연산자(operand)의 같음 여부
     */
    bool operator==(const Pose& rhs) const { return (x == rhs.x) && (y == rhs.y) && (theta == rhs.theta); }

    /**
     * 상등 비교
     * @param rhs 상등 연산자의 오른쪽 항
     * @return 두 피연산자(operand)의 다름 여부
     */
    bool operator!=(const Pose& rhs) const { return (x != rhs.x) || (y != rhs.y) || (theta != rhs.theta); }

    /** Z 축에 대한 회전 값 */
    double theta;
};

/**
 * <B>2D Vector(Point) in Polar Coordinates</B>
 *
 * 이차원 극좌표계(polar coordinates)에서의 벡터를 표현한다.
 * 선형 성분과 각 성분의 값을 가진다.
 * 이차원 평면에서의 로봇 좌표계에서의 <B>속도(velocity)</B>와 <B>가속도(acceleration)</B>를 표현하는데 주로 사용된다.
 *
 * @see Point 이차원 직교좌표계(rectangular coordinates)에서의 벡터
 */
class Polar
{
public:
    /**
     * 생성자 (기본값: 0)
     */
    Polar() { linear = angular = 0; }

    /**
     * 선형 성분과 각 성분의 값을 초기화하는 생성자
     * @param linear 선형 성분의 값
     * @param angular 각 성분의 값
     */
    Polar(double linear, double angular)
    {
        this->linear = linear;
        this->angular = angular;
    }

    /**
     * 등가 비교
     * @param rhs 등가 연산자의 오른쪽 항
     * @return 두 피연산자(operand)의 같음 여부
     */
    bool operator==(const Polar& rhs) const { return (linear == rhs.linear) && (angular == rhs.angular); }

    /**
     * 상등 비교
     * @param rhs 상등 연산자의 오른쪽 항
     * @return 두 피연산자(operand)의 다름 여부
     */
    bool operator!=(const Polar& rhs) const { return (linear != rhs.linear) || (angular != rhs.angular); }

    /** 선형 성분의 값 */
    double linear;

    /** 각 성분의 값 */
    double angular;
};	// class

#endif /* CPOSES_H_ */
