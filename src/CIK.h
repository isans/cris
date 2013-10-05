
#pragma once

#include "CPoses.h"

namespace cris
{
/** \addtogroup cris_Math */
/** @{ */

/**
 * <B>State of Differential Drive</B>
 *
 * ���� ������(differential drive)�� �� ������ ���� ǥ���Ѵ�.
 * �� ������ ������ �ӵ�, ���ӵ��� ǥ���ϴµ� �ַ� ���ȴ�.
 *
 * @see DiffDriveKinematics ���� �������� �ⱸ��
 */
class DiffDriveWheel
{
public:
    /**
     * ������ (�⺻��: 0)
     */
    DiffDriveWheel() { left = right = 0; }

    /**
     * �� ������ ���� �ʱ�ȭ�ϴ� ������
     * @param left �������� ���� ������ ��
     * @param right �������� ������ ������ ��
     */
    DiffDriveWheel(double left, double right)
    {
        this->left = left;
        this->right = right;
    }

    /**
     * � ��
     * @param rhs ��ġ �������� ������ ��
     * @return �� �ǿ�����(operand)�� ���� ����
     */
    bool operator==(const DiffDriveWheel& rhs) const { return (left == rhs.left) && (right == rhs.right); }

    /**
     * ��� ��
     * @param rhs ��� �������� ������ ��
     * @return �� �ǿ�����(operand)�� �ٸ� ����
     */
    bool operator!=(const DiffDriveWheel& rhs) const { return (left != rhs.left) || (right != rhs.right); }

    /** ���� �������� ���� ������ �� */
    double left;

    /** ���� �������� ������ ������ �� */
    double right;
};

/**
 * <B>Kinematics of Differential Drive</B>
 *
 * ���� ������(differential drive) ���ⱸ��(forward kinematics)�� ���ⱸ��(inverse kinematics)�� �����Ѵ�.
 * �ⱸ�п� ���Ǵ� �Ķ���ʹ� �Ʒ� �׸��� ����.
 *
 * \image html differential_drive.png "���� �������� �ⱸ��"
 * \image latex differential_drive.png "���� �������� �ⱸ��" width=0.5\textwidth
 *
 * @see FourMecanumKinematics �� ���� ��ī�� ����(Mecanum wheel)�� ���� �������� �ⱸ��
 */
class DiffDriveKinematics
{
public:
    /**
     * ���� �������� ���ⱸ�� (�� ������ �ӵ��� �־��� ���, �κ��� ���ӵ��� ���ӵ��� ��ȯ)
     * @param wheel �� ������ �ӵ� (����: [m/s])
     * @param wheelBase �� ���� ������ ���� (����: [m])
     * @param robot �κ��� �ӵ� <B>[��ȯ��]</B> (���ӵ� ����: [m/s], ���ӵ� ����: [rad/s])
     */
    static void Forward(const DiffDriveWheel& wheel, double wheelBase, Polar& robot)
    {
        robot.linear = (wheel.right + wheel.left) / 2.0;
        robot.angular = (wheel.right - wheel.left) / wheelBase;
    }

    /**
     * ���� �������� ���ⱸ�� (�κ��� ���ӵ��� ���ӵ��� �־��� ���, �� ������ �ӵ��� ��ȯ)
     * @param robot �κ��� �ӵ� (���ӵ� ����: [m/s], ���ӵ� ����: [rad/s])
     * @param wheelBase �� ���� ������ ���� (����: [m])
     * @param wheel �� ������ �ӵ� <B>[��ȯ��]</B> (����: [m/s])
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
 * �� ���� ��ī�� ����(Mecanum wheel)�� ���� �������� �� ������ ���� ǥ���Ѵ�.
 * �� ������ ������ �ӵ�, ���ӵ��� ǥ���ϴµ� �ַ� ���ȴ�.
 *
 * @see FourMecanumKinematics �� ���� ��ī�� ������ ���� �������� �ⱸ��
 */
class FourMecanumWheel
{
public:
    /**
     * ������ (�⺻��: 0)
     */
    FourMecanumWheel() { frontLeft = frontRight = rearLeft = rearRight = 0; }

    /**
     * �� ������ ���� �ʱ�ȭ�ϴ� ������
     * @param frontLeft �������� ���� ���� ������ ��
     * @param frontRight �������� ���� ������ ������ ��
     * @param rearLeft �������� �Ĺ� ���� ������ ��
     * @param rearRight �������� �Ĺ� ������ ������ ��
     */
    FourMecanumWheel(double frontLeft, double frontRight, double rearLeft, double rearRight)
    {
        this->frontLeft = frontLeft;
        this->frontRight = frontRight;
        this->rearLeft = rearLeft;
        this->rearRight = rearRight;
    }

    /**
     * � ��
     * @param rhs ��ġ �������� ������ ��
     * @return �� �ǿ�����(operand)�� ���� ����
     */
    bool operator==(const FourMecanumWheel& rhs) const
    {
        return (frontLeft == rhs.frontLeft) && (frontRight == rhs.frontRight) &&
               (rearLeft == rhs.rearLeft) && (rearRight == rhs.rearRight);
    }

    /**
     * ��� �񱳱�
     * @param rhs ��� �������� ������ ��
     * @return �� �ǿ�����(operand)�� �ٸ� ����
     */
    bool operator!=(const FourMecanumWheel& rhs) const
    {
        return (frontLeft != rhs.frontLeft) || (frontRight != rhs.frontRight) ||
               (rearLeft != rhs.rearLeft) || (rearRight != rhs.rearRight);
    }

    /** �������� ���� ���� ������ �� */
    double frontLeft;

    /** �������� ���� ������ ������ �� */
    double frontRight;

    /** �������� �Ĺ� ���� ������ �� */
    double rearLeft;

    /** �������� �Ĺ� ������ ������ �� */
    double rearRight;
};

/**
 * <B>2D Pose of Four-Mecanum-Wheel Drive</B>
 *
 * �� ���� ��ī�� ����(Mecanum wheel)�� ���� �������� �ڼ��� ǥ���Ѵ�.
 *
 * @see FourMecanumKinematics �� ���� ��ī�� ������ ���� �������� �ⱸ��
 */
class FourMecanumPose : public Pose
{
public:
    /**
     * ������ (�⺻��: 0)
     */
    FourMecanumPose() { error = 0; }

    /**
     * �� ���� ��ī�� ������ ���� �������� �ڼ� ���� �ʱ�ȭ�ϴ� ������
     * @param x X �� ��
     * @param y Y �� ��
     * @param theta Z �� ȸ���� ���� �� (������ ��ǥ��)
     * @param error ���� ���� ��
     */
    FourMecanumPose(double x, double y, double theta, double error)
    {
        this->x = x;
        this->y = y;
        this->theta = theta;
        this->error = error;
    }

    /**
     * � ��
     * @param rhs ��ġ �������� ������ ��
     * @return �� �ǿ�����(operand)�� ���� ����
     */
    bool operator==(const FourMecanumPose rhs) const
    {
        return (x == rhs.x) && (y == rhs.y) && (theta == rhs.theta) && (error == rhs.error);
    }

    /**
     * ��� �񱳱�
     * @param rhs ��� �������� ������ ��
     * @return �� �ǿ�����(operand)�� �ٸ� ����
     */
    bool operator!=(const FourMecanumPose rhs) const
    {
        return (x != rhs.x) || (y != rhs.y) || (theta != rhs.theta) || (error != rhs.error);
    }

    /** ���� ���� �� */
    double error;
};

/**
 * <B>Kinematics of Four-Mecanum-Wheel Drive</B>
 *
 * �� ���� ��ī�� ����(Mecanum wheel)�� ���� �������� ���ⱸ��(forward kinematics)�� ���ⱸ��(inverse kinematics)�� �����Ѵ�.
 * �ⱸ�п� ���Ǵ� �Ķ���ʹ� �Ʒ� �׸��� ����.
 *
 * \image html four_mecanum_drive.png "�� ���� ��ī�� ���� �������� �ⱸ��"
 * \image latex four_mecanum_drive.png "�� ���� ��ī�� ���� �������� �ⱸ��" width=0.8\textwidth
 *
 * @see DiffDriveKinematics ���� ������(differential drive)�� �ⱸ
 */
class FourMecanumKinematics
{
public:
    /**
     * �� ���� ��ī�� ���� �������� ���ⱸ�� (�� ������ �ӵ��� �־��� ���, �κ��� X, Y ���� �ӵ� �� Z ���� ȸ�� �ӵ��� ��ȯ)
     * @param wheel �� ������ �ӵ� (����: [m/s])
     * @param wheelBase �� ���� ������ ���� (����: [m])
     * @param robot �κ��� �ӵ��� ���� ���� <B>[��ȯ��]</B> (���ӵ� ����: [m/s], ���ӵ� ����: [rad/s])
     */
    static void Forward(const FourMecanumWheel& wheel, const double wheelBase, FourMecanumPose& robot)
    {
        robot.x = (wheel.frontLeft + wheel.frontRight + wheel.rearLeft + wheel.rearRight) / 4.0;
        robot.y = (-wheel.frontLeft + wheel.frontRight + wheel.rearLeft - wheel.rearRight) / 4.0;
        robot.theta = (-wheel.frontLeft + wheel.frontRight - wheel.rearLeft + wheel.rearRight) / 4.0 / (wheelBase / 2.0);
        robot.error = (wheel.frontLeft + wheel.frontRight - wheel.rearLeft - wheel.rearRight) / 4.0;
    }

    /**
     * �� ���� ��ī�� ���� �������� ���ⱸ�� (�κ��� X, Y ���� �ӵ� �� Z ���� ȸ�� �ӵ��� �־��� ���, �� ������ �ӵ��� ��ȯ)
     * @param robot �κ��� �ӵ��� ���� ���� (���ӵ� ����: [m/s], ���ӵ� ����: [rad/s])
     * @param wheelBase �� ���� ������ ���� (����: [m])
     * @param wheel �� ������ �ӵ� <B>[��ȯ��]</B> (����: [m/s])
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

