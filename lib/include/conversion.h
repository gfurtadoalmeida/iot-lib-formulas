#ifndef __IOT_LIB_CONV_H__
#define __IOT_LIB_CONV_H__

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Convert Kelvin to Celsius.
 * @param kelvin Temperature, in Kelvin.
 * @return Temperature, in Celsius.
 */
#define CONV_KELVIN_CELSIUS(kelvin) (kelvin - 273.15)

/**
 * @brief Convert Kelvin to Fahrenheit.
 * @param kelvin Temperature, in Kelvin.
 * @return Temperature, in Fahrenheit.
 */
#define CONV_KELVIN_FAHRENHEIT(kelvin) ((kelvin * 1.8) - 459.67)

/**
 * @brief Convert Celsius to Kelvin.
 * @param kelvin Temperature, in Celsius.
 * @return Temperature, in Kelvin.
 */
#define CONV_CELSIUS_KELVIN(celsius) (celsius + 273.15)

/**
 * @brief Convert Celsius to Fahrenheit.
 * @param kelvin Temperature, in Celsius.
 * @return Temperature, in Fahrenheit.
 */
#define CONV_CELSIUS_FAHRENHEIT(celsius) ((celsius * 1.8) + 32.0)

/**
 * @brief Convert Fahrenheit to Kelvin.
 * @param kelvin Temperature, in Fahrenheit.
 * @return Temperature, in Kelvin.
 */
#define CONV_FAHRENHEIT_KELVIN(fahrenheit) ((fahrenheit + 459.67) * 0.55)

/**
 * @brief Convert Fahrenheit to Celsius.
 * @param kelvin Temperature, in Fahrenheit.
 * @return Temperature, in Celsius.
 */
#define CONV_FAHRENHEIT_CELSIUS(fahrenheit) ((fahrenheit - 32.0) * 1.8)

#ifdef __cplusplus
}
#endif

#endif //__IOT_LIB_CONV_H__