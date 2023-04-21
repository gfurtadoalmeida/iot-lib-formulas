#ifndef __IOT_LIB_FORMULAS_FLOAT_TYPE_H__
#define __IOT_LIB_FORMULAS_FLOAT_TYPE_H__

#ifdef __cplusplus
extern "C"
{
#endif

#if IOT_LIB_FORMULAS_USE_FLOAT == 1
typedef float float_type;
#define FLOAT_CONST(value) value##f
#else
typedef double float_type;
#define FLOAT_CONST(value) value
#endif

#ifdef __cplusplus
}
#endif
#endif