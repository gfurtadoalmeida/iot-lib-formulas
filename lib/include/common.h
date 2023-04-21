#ifndef __IOT_LIB_CONST_H__
#define __IOT_LIB_CONST_H__

#include <math.h>

#ifdef __cplusplus
extern "C"
{
#endif

#if IOT_LIB_FORMULAS_USE_FLOAT == 1
typedef float float_type;
#define FLOAT_CONST(value) value##f
#define FLOAT_POW powf
#define FLOAT_LOG logf
#define FLOAT_FLOOR floorf
#else
typedef double float_type;
#define FLOAT_CONST(value) value
#define FLOAT_POW pow
#define FLOAT_LOG log
#define FLOAT_FLOOR floor
#endif

/**
 * @brief Electron charge, in Coulombs: 1.602 * 10^-19
 */
#define ELECTRON_CHARGE FLOAT_CONST(1.602e-19)

/**
 * @brief Euler's number: 2.7182818284
 */
#define EULER_NUMBER FLOAT_CONST(2.7182818284)

#ifdef __cplusplus
}
#endif
#endif