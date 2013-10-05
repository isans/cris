
#pragma once

#include "CPoses.h"

namespace cris
{
/** \addtogroup cris_Math */
/** @{ */

/**
 * <B>State of Differential Drive</B>
 *
 * 차륜 구동기(differential drive)의 두 바퀴의 값을 표현한다.
 * 두 바퀴의 변위나 속도, 가속도를 표현하는데 주로 사용된다.
 *
 * @see DiffDriveKinematics 차륜 구동기의 기구학
 */
class DiffDriveWheel
{
public:
    /**
     * 생성자 (기본값: 0)
     */
    DiffDriveWheel() { left = right = 0; }

    /**
     * 두 바퀴의 값을 초기화하는 생성자
     * @param left 구동기의 왼쪽 바퀴의 값
     * @param right 구동기의 오른쪽 바퀴의 값
     */
    DiffDriveWheel(double left, double right)
    {
        this->left = left;
        this->right = right;
    }

    /**
     * 등가 비교
     * @param rhs 등치 연산자의 오른쪽 항
     * @return 두 피연산자(operand)의 같음 여부
     */
    bool operator==(const DiffDriveWheel& rhs) const { return (left == rhs.left) && (right == rhs.right); }

    /**
     * 상등 비교
     * @param rhs 상등 연산자의 오른쪽 항
     * @return 두 피연산자(operand)의 다름 여부
     */
    bool operator!=(const DiffDriveWheel& rhs) const { return (left != rhs.left) || (right != rhs.right); }

    /** 차륜 구동기의 왼쪽 바퀴의 값 */
    double left;

    /** 차륜 구동기의 오른쪽 바퀴의 값 */
    double right;
};

/**
 * <B>Kinematics of Differential Drive</B>
 *
 * 차륜 구동기(differential drive) 정기구학(forward kinematics)과 역기구학(inverse kinematics)을 정의한다.
 * 기구학에 사용되는 파라미터는 아래 그림과 같다.
 *
 * \image html differential_drive.png "차륜 구동기의 기구학"
 * \image latex differential_drive.png "차륜 구동기의 기구학" width=0.5\textwidth
 *
 * @see FourMecanumKinematics 네 개의 메카늄 바퀴(Mecanum wheel)을 가진 구동기의 기구학
 */
class DiffDriveKinematics
{
public:
    /**
     * 차륜 구동기의 정기구학 (두 바퀴의 속도가 주어진 경우, 로봇의 선속도와 각속도로 반환)
     * @param wheel 두 바퀴의 속도 (단위: [m/s])
     * @param wheelBase 두 바퀴 사이의 길이 (단위: [m])
     * @param robot 로봇의 속도 <B>[반환값]</B> (선속도 단위: [m/s], 각속도 단위: [rad/s])
     */
    static void Forward(const DiffDriveWheel& wheel, double wheelBase, Polar& robot)
    {
        robot.linear = (wheel.right + wheel.left) / 2.0;
        robot.angular = (wheel.right - wheel.left) / wheelBase;
    }

    /**
     * 차륜 구동기의 역기구학 (로봇의 선속도와 각속도가 주어진 경우, 두 바퀴의 속도로 반환)
     * @param robot 로봇의 속도 (선속도 단위: [m/s], 각속도 단위: [rad/s])
     * @param wheelBase 두 바퀴 사이의 길이 (단위: [m])
     * @param wheel 두 바퀴의 속도 <B>[반환값]</B> (단위: [m/s])
     */
    static void Inverse(const Polar& robot, double wheelBase, DiffDriveWheel& wheel)
    {
        wheel.left  = robot.linear - robot.angular * wheelBase / 2.0;
        wheel.right = robot.linear + robot.angular * wheelBase / 2.0;
    }
};

/**
 * <B>State of Four-Mecanum-Wheel Drive</B>
 *
 * 네 개의 메카늄 바퀴(Mecanum wheel)을 가진 구동기의 네 바퀴의 값을 표현한다.
 * 네 바퀴의 변위나 속도, 가속도를 표현하는데 주로 사용된다.
 *
 * @see FourMecanumKinematics 네 개의 메카늄 바퀴를 가진 구동기의 기구학
 */
class FourMecanumWheel
{
public:
    /**
     * 생성자 (기본값: 0)
     */
    FourMecanumWheel() { frontLeft = frontRight = rearLeft = rearRight = 0; }

    /**
     * 네 바퀴의 값을 초기화하는 생성자
     * @param frontLeft 구동기의 전방 왼쪽 바퀴의 값
     * @param frontRight 구동기의 전방 오른쪽 바퀴의 값
     * @param rearLeft 구동기의 후방 왼쪽 바퀴의 값
     * @param rearRight 구동기의 후방 오른쪽 바퀴의 값
     */
    FourMecanumWheel(double frontLeft, double frontRight, double rearLeft, double rearRight)
    {
        this->frontLeft = frontLeft;
        this->frontRight = frontRight;
        this->rearLeft = rearLeft;
        this->rearRight = rearRight;
    }

    /**
     * 등가 비교
     * @param rhs 등치 연산자의 오른쪽 항
     * @return 두 피연산자(operand)의 같음 여부
     */
    bool operator==(const FourMecanumWheel& rhs) const
    {
        return (frontLeft == rhs.frontLeft) && (frontRight == rhs.frontRight) &&
               (rearLeft == rhs.rearLeft) && (rearRight == rhs.rearRight);
    }

    /**
     * 상등 비교기
     * @param rhs 상등 연산자의 오른쪽 항
     * @return 두 피연산자(operand)의 다름 여부
     */
    bool operator!=(const FourMecanumWheel& rhs) const
    {
        return (frontLeft != rhs.frontLeft) || (frontRight != rhs.frontRight) ||
               (rearLeft != rhs.rearLeft) || (rearRight != rhs.rearRight);
    }

    /** 구동기의 전방 왼쪽 바퀴의 값 */
    double frontLeft;

    /** 구동기의 전방 오른쪽 바퀴의 값 */
    double frontRight;

    /** 구동기의 후방 왼쪽 바퀴의 값 */
    double rearLeft;

    /** 구동기의 후방 오른쪽 바퀴의 값 */
    double rearRight;
};

/**
 * <B>2D Pose of Four-Mecanum-Wheel Drive</B>
 *
 * 네 개의 메카늄 바퀴(Mecanum wheel)을 가진 구동기의 자세를 표현한다.
 *
 * @see FourMecanumKinematics 네 개의 메카늄 바퀴를 가진 구동기의 기구학
 */
class FourMecanumPose : public Pose
{
public:
    /**
     * 생성자 (기본값: 0)
     */
    FourMecanumPose() { error = 0; }

    /**
     * 네 개의 메카늄 바퀴를 가진 구동기의 자세 값을 초기화하는 생성자
     * @param x X 축 값
     * @param y Y 축 값
     * @param theta Z 축 회전에 대한 값 (오른손 좌표계)
     * @param error 에러 보상 값
     */
    FourMecanumPose(double x, double y, double theta, double error)
    {
        this->x = x;
        this->y = y;
        this->theta = theta;
        this->error = error;
    }

    /**
     * 등가 비교
     * @param rhs 등치 연산자의 오른쪽 항
     * @return 두 피연산자(operand)의 같음 여부
     */
    bool operator==(const FourMecanumPose rhs) const
    {
        return (x == rhs.x) && (y == rhs.y) && (theta == rhs.theta) && (error == rhs.error);
    }

    /**
     * 상등 비교기
     * @param rhs 상등 연산자의 오른쪽 항
     * @return 두 피연산자(operand)의 다름 여부
     */
    bool operator!=(const FourMecanumPose rhs) const
    {
        return (x != rhs.x) || (y != rhs.y) || (theta != rhs.theta) || (error != rhs.error);
    }

    /** 에러 보상 값 */
    double error;
};

/**
 * <B>Kinematics of Four-Mecanum-Wheel Drive</B>
 *
 * 네 개의 메카늄 바퀴(Mecanum wheel)을 가진 구동기의 정기구학(forward kinematics)과 역기구학(inverse kinematics)을 정의한다.
 * 기구학에 사용되는 파라미터는 아래 그림과 같다.
 *
 * \image html four_mecanum_drive.png "네 개의 메카늄 바퀴 구동기의 기구학"
 * \image latex four_mecanum_drive.png "네 개의 메카늄 바퀴 구동기의 기구학" width=0.8\textwidth
 *
 * @see DiffDriveKinematics 차륜 구동기(differential drive)의 기구
 */
class FourMecanumKinematics
{
public:
    /**
     * 네 개의 메카늄 바퀴 구동기의 정기구학 (네 바퀴의 속도가 주어진 경우, 로봇의 X, Y 방향 속도 및 Z 방향 회전 속도로 반환)
     * @param wheel 네 바퀴의 속도 (단위: [m/s])
     * @param wheelBase 두 바퀴 사이의 길이 (단위: [m])
     * @param robot 로봇의 속도와 에러 보상값 <B>[반환값]</B> (선속도 단위: [m/s], 각속도 단위: [rad/s])
     */
    static void Forward(const FourMecanumWheel& wheel, const double wheelBase, FourMecanumPose& robot)
    {
        robot.x = (wheel.frontLeft + wheel.frontRight + wheel.rearLeft + wheel.rearRight) / 4.0;
        robot.y = (-wheel.frontLeft + wheel.frontRight + wheel.rearLeft - wheel.rearRight) / 4.0;
        robot.theta = (-wheel.frontLeft + wheel.frontRight - wheel.rearLeft + wheel.rearRight) / 4.0 / (wheelBase / 2.0);
        robot.error = (wheel.frontLeft + wheel.frontRight - wheel.rearLeft - wheel.rearRight) / 4.0;
    }

    /**
     * 네 개의 메카늄 바퀴 구동기의 역기구학 (로봇의 X, Y 방향 속도 및 Z 방향 회전 속도가 주어진 경우, 네 바퀴의 속도로 반환)
     * @param robot 로봇의 속도와 에러 보상값 (선속도 단위: [m/s], 각속도 단위: [rad/s])
     * @param wheelBase 두 바퀴 사이의 길이 (단위: [m])
     * @param wheel 네 바퀴의 속도 <B>[반환값]</B> (단위: [m/s])
     */
    static void Inverse(const FourMecanumPose& robot, const double wheelBase, FourMecanumWheel& wheel)
    {
        double angular = robot.theta * (wheelBase / 2.0);
        wheel.frontLeft  = robot.x - robot.y - angular + robot.error;
        wheel.frontRight = robot.x + robot.y + angular + robot.error;
        wheel.rearLeft   = robot.x + robot.y - angular - robot.error;
        wheel.rearRight  = robot.x - robot.y + angular - robot.error;
    }
};

/** @} */
} // End of 'cris'

