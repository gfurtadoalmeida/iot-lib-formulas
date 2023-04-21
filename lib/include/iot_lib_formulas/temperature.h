#ifndef __IOT_LIB_FORMULAS_TEMPERATURE_H__
#define __IOT_LIB_FORMULAS_TEMPERATURE_H__

#include "float_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Convert Kelvin to Celsius.
 * @param[in] kelvin Temperature, in Kelvin.
 * @return Temperature, in Celsius.
 */
#define CONV_KELVIN_CELSIUS(kelvin) (kelvin - FLOAT_CONST(273.15))

/**
 * @brief Convert Kelvin to Fahrenheit.
 * @param[in] kelvin Temperature, in Kelvin.
 * @return Temperature, in Fahrenheit.
 */
#define CONV_KELVIN_FAHRENHEIT(kelvin) ((kelvin * FLOAT_CONST(1.8)) - FLOAT_CONST(459.67))

/**
 * @brief Convert Celsius to Kelvin.
 * @param[in] kelvin Temperature, in Celsius.
 * @return Temperature, in Kelvin.
 */
#define CONV_CELSIUS_KELVIN(celsius) (celsius + FLOAT_CONST(273.15))

/**
 * @brief Convert Celsius to Fahrenheit.
 * @param[in] kelvin Temperature, in Celsius.
 * @return Temperature, in Fahrenheit.
 */
#define CONV_CELSIUS_FAHRENHEIT(celsius) ((celsius * FLOAT_CONST(1.8)) + FLOAT_CONST(32.0))

/**
 * @brief Convert Fahrenheit to Kelvin.
 * @param[in] kelvin Temperature, in Fahrenheit.
 * @return Temperature, in Kelvin.
 */
#define CONV_FAHRENHEIT_KELVIN(fahrenheit) ((fahrenheit + FLOAT_CONST(459.67)) * FLOAT_CONST(0.55))

/**
 * @brief Convert Fahrenheit to Celsius.
 * @param[in] kelvin Temperature, in Fahrenheit.
 * @return Temperature, in Celsius.
 */
#define CONV_FAHRENHEIT_CELSIUS(fahrenheit) ((fahrenheit - FLOAT_CONST(32.0)) * FLOAT_CONST(1.8))

#ifdef __cplusplus
}
#endif
#endif