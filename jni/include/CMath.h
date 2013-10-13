

#pragma once

/** \addtogroup CRIS_Math */
/** @{ */

/** ������ */
#define CRIS_PI                         (3.14159265358979323846)

/**
 * �־��� ���� ������ �� ������ ��ȯ�ϴ� ��ũ�� �Լ�
 * @param x ��ȯ�ϰ��� �ϴ� ���� ���� (����: [rad])
 * @return �� ���� ���� (����: [��])
 * @see MATH_DEG2RAD
 */
#define CRIS_RAD2DEG(x)                 ((x) * 180.0 / CRIS_PI)

/**
 * �־��� �� ���� ������ ���� ������ ��ȯ�ϴ� ��ũ�� �Լ�
 * @param x ��ȯ�ϰ��� �ϴ� �� ���� (����: [��])
 * @return ���� ���� ���� (����: [rad])
 * @see MATH_DEG2RAD
 */
#define CRIS_DEG2RAD(x)                 ((x) * CRIS_PI / 180.0)

/**
 * �־��� �� ������ �ִ밪�� ��ȯ�ϴ� ��ũ�� �Լ�
 * @param a ù ��° ��
 * @param b �� ��° ��
 * @return �� �� �� �ִ밪
 * @see MATH_MIN
 */
#define CRIS_MAX(a, b)                  ( ((a) > (b)) ? (a) : (b) )

/**
 * �־��� �� ������ �ּҰ��� ��ȯ�ϴ� ��ũ�� �Լ�
 * @param a ù ��° ��
 * @param b �� ��° ��
 * @return �� �� �� �ּҰ�
 * @see MATH_MAX
 */
#define CRIS_MIN(a, b)                  ( ((a) < (b)) ? (a) : (b) )

/**
 * �־��� ���� ��ȣ�� ��ȯ�ϴ� ��ũ�� �Լ�
 * @param x ��ȣ�� �˻��� ��
 * @return ����� ��� +1, 0�� ��� 0, ������ ��� -1
 */
#define CRIS_SIGN(x)                    ( ((x) > 0) ? +1 : (((x) < 0) ? -1 : 0) )

/**
 * �־��� ���� ��� �Ǵ� 0�� ����� �ݿø� ���� ��ȯ�ϴ� ��ũ�� �Լ�
 * @param x �ݿø� �� �� (x >= 0)
 * @return �ݿø��� �� (Ÿ��: int)
 */
#define CRIS_ROUND_POS(x)               (static_cast<int>((x) + 0.5))

/**
 * �־��� ���� ������ ����� �ݿø� ���� ��ȯ�ϴ� ��ũ�� �Լ�
 * @param x �ݿø� �� �� (x < 0)
 * @return �ݿø��� �� (Ÿ��: int)
 */
#define CRIS_ROUND_NEG(x)               (static_cast<int>((x) - 0.5))

/**
 * �־��� ���� �ݿø� ���� ��ȯ�ϴ� ��ũ�� �Լ�
 * @param x �ݿø� �� ��
 * @return �ݿø��� �� (Ÿ��: int)
 */
#define CRIS_ROUND(x)                   ( (x) > 0 ? CRIS_ROUND_POS(x) : CRIS_ROUND_NEG(x) )

/**
 * �־��� ���� �ø� ���� ��ȯ�ϴ� ��ũ�� �Լ�
 * @param x �ݿø� �� ��
 * @return �ݿø��� �� (Ÿ��: int)
 */
#define CRIS_CEIL_POS(x)                ( (x - static_cast<int>(x)) > 0 ? static_cast<int>((x) + 1) : static_cast<int>(x) )

/**
 * �־��� ���� ���� �Ǵ� 0�� ��� �ø� ���� ��ȯ�ϴ� ��ũ�� �Լ�
 * @param x �ݿø� �� �� (x <= 0)
 * @return �ݿø��� �� (Ÿ��: int)
 */
#define CRIS_CEIL_NEG(x)                (static_cast<int>(x))

/**
 * �־��� ���� �ø� ���� ��ȯ�ϴ� ��ũ�� �Լ�
 * @param x �ݿø� �� ��
 * @return �ݿø��� �� (Ÿ��: int)
 */
#define CRIS_CEIL(x)                    CRIS_CEIL_POS(x)

/**
 * �־��� ���� ��� �Ǵ� 0�� ��� �ø� ���� ��ȯ�ϴ� ��ũ�� �Լ�
 * @param x �ݿø� �� �� (x >= 0)
 * @return �ݿø��� �� (Ÿ��: int)
 */
#define CRIS_FLOOR_POS(x)               (static_cast<int>(x))

/**
 * �־��� ���� ���� ���� ��ȯ�ϴ� ��ũ�� �Լ�
 * @param x �ݿø� �� ��
 * @return �ݿø��� �� (Ÿ��: int)
 */
#define CRIS_FLOOR_NEG(x)               ( (x - static_cast<int>(x)) < 0 ? static_cast<int>((x) - 1) : static_cast<int>(x) )

/**
 * �־��� ���� ���� ���� ��ȯ�ϴ� ��ũ�� �Լ�
 * @param x �ݿø� �� ��
 * @return �ݿø��� �� (Ÿ��: int)
 */
#define CRIS_FLOOR(x)                   CRIS_FLOOR_NEG(x)
/** @} */

/** �Ÿ� �� ���ӵ��� �ּҰ��� ũ�� (����: [m]) */
#define CRIS_EPSILON_LEN                (0.003)

/** ���� �� ���ӵ��� �ּҰ��� ũ�� (����: [rad]) */
#define CRIS_EPSILON_ANG                (CRIS_DEG2RAD(3.0))

