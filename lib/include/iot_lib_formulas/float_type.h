#ifndef __IOT_LIB_FORMULAS_FLOAT_TYPE_H__
#define __IOT_LIB_FORMULAS_FLOAT_TYPE_H__

#ifdef __cplusplus
extern "C"
{
#endif

#if CONFIG_IOT_LIB_FORMULAS_USE_FLOAT == 1
    /**
     * @typedef float_type
     * @brief Float type (32 bits).
     */
    typedef float float_type;
    /**
     * @brief Create a float constant.
     * @param[in] value Constant value.
     */
#define FLOAT_CONST(value) value##f
#else
/**
 * @typedef float_type
 * @brief Double type (64 bits).
 */
typedef double float_type;
/**
 * @brief Create a double constant.
 * @param[in] value Constant value.
 */
#define FLOAT_CONST(value) value
#endif

#ifdef __cplusplus
}
#endif
#endif