

#pragma once

/** \addtogroup CRIS_Math */
/** @{ */

/** 원주율 */
#define CRIS_PI                         (3.14159265358979323846)

/**
 * 주어진 라디안 각도를 도 단위로 변환하는 매크로 함수
 * @param x 변환하고자 하는 라디안 각도 (단위: [rad])
 * @return 도 단위 각도 (단위: [도])
 * @see MATH_DEG2RAD
 */
#define CRIS_RAD2DEG(x)                 ((x) * 180.0 / CRIS_PI)

/**
 * 주어진 도 단위 각도를 라디언 단위로 변환하는 매크로 함수
 * @param x 변환하고자 하는 도 각도 (단위: [도])
 * @return 라디언 단위 각도 (단위: [rad])
 * @see MATH_DEG2RAD
 */
#define CRIS_DEG2RAD(x)                 ((x) * CRIS_PI / 180.0)

/**
 * 주어진 두 값에서 최대값을 반환하는 매크로 함수
 * @param a 첫 번째 값
 * @param b 두 번째 값
 * @return 두 값 중 최대값
 * @see MATH_MIN
 */
#define CRIS_MAX(a, b)                  ( ((a) > (b)) ? (a) : (b) )

/**
 * 주어진 두 값에서 최소값을 반환하는 매크로 함수
 * @param a 첫 번째 값
 * @param b 두 번째 값
 * @return 두 값 중 최소값
 * @see MATH_MAX
 */
#define CRIS_MIN(a, b)                  ( ((a) < (b)) ? (a) : (b) )

/**
 * 주어진 값의 기호를 반환하는 매크로 함수
 * @param x 기호를 검사할 값
 * @return 양수인 경우 +1, 0인 경우 0, 음수인 경우 -1
 */
#define CRIS_SIGN(x)                    ( ((x) > 0) ? +1 : (((x) < 0) ? -1 : 0) )

/**
 * 주어진 값이 양수 또는 0인 경우의 반올림 값을 반환하는 매크로 함수
 * @param x 반올림 할 값 (x >= 0)
 * @return 반올림된 값 (타입: int)
 */
#define CRIS_ROUND_POS(x)               (static_cast<int>((x) + 0.5))

/**
 * 주어진 값이 음수인 경우의 반올림 값을 반환하는 매크로 함수
 * @param x 반올림 할 값 (x < 0)
 * @return 반올림된 값 (타입: int)
 */
#define CRIS_ROUND_NEG(x)               (static_cast<int>((x) - 0.5))

/**
 * 주어진 값의 반올림 값을 반환하는 매크로 함수
 * @param x 반올림 할 값
 * @return 반올림된 값 (타입: int)
 */
#define CRIS_ROUND(x)                   ( (x) > 0 ? CRIS_ROUND_POS(x) : CRIS_ROUND_NEG(x) )

/**
 * 주어진 값의 올림 값을 반환하는 매크로 함수
 * @param x 반올림 할 값
 * @return 반올림된 값 (타입: int)
 */
#define CRIS_CEIL_POS(x)                ( (x - static_cast<int>(x)) > 0 ? static_cast<int>((x) + 1) : static_cast<int>(x) )

/**
 * 주어진 값이 음수 또는 0인 경우 올림 값을 반환하는 매크로 함수
 * @param x 반올림 할 값 (x <= 0)
 * @return 반올림된 값 (타입: int)
 */
#define CRIS_CEIL_NEG(x)                (static_cast<int>(x))

/**
 * 주어진 값의 올림 값을 반환하는 매크로 함수
 * @param x 반올림 할 값
 * @return 반올림된 값 (타입: int)
 */
#define CRIS_CEIL(x)                    CRIS_CEIL_POS(x)

/**
 * 주어진 값이 양수 또는 0인 경우 올림 값을 반환하는 매크로 함수
 * @param x 반올림 할 값 (x >= 0)
 * @return 반올림된 값 (타입: int)
 */
#define CRIS_FLOOR_POS(x)               (static_cast<int>(x))

/**
 * 주어진 값의 내림 값을 반환하는 매크로 함수
 * @param x 반올림 할 값
 * @return 반올림된 값 (타입: int)
 */
#define CRIS_FLOOR_NEG(x)               ( (x - static_cast<int>(x)) < 0 ? static_cast<int>((x) - 1) : static_cast<int>(x) )

/**
 * 주어진 값의 내림 값을 반환하는 매크로 함수
 * @param x 반올림 할 값
 * @return 반올림된 값 (타입: int)
 */
#define CRIS_FLOOR(x)                   CRIS_FLOOR_NEG(x)
/** @} */

/** 거리 및 선속도의 최소값의 크기 (단위: [m]) */
#define CRIS_EPSILON_LEN                (0.003)

/** 각도 및 각속도의 최소값의 크기 (단위: [rad]) */
#define CRIS_EPSILON_ANG                (CRIS_DEG2RAD(3.0))

