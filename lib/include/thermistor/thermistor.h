#ifndef __IOT_LIB_THERM_H__
#define __IOT_LIB_THERM_H__

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Common ambient temperature, in Kelvin, used to calibrate thermistors: 298.15 K, 25°C, 77°F
 */
#define COMMON_THERM_AMBIENT_TEMP_KELVIN 298.15

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

    /**
     * @typedef temperature_point_t
     * @brief Thermistor resistance measured at a certain temperature.
     */
    typedef struct
    {
        double temperature; /*!< Temperature, in Kelvin. */
        double resistance;  /*!< resistance, in ohms. */
    } temperature_point_t;

    /**
     * @typedef steinhart_coefficients_t
     * @brief Steinhart-Hart coefficients.
     */
    typedef struct
    {
        double a;
        double b;
        double c;
    } steinhart_coefficients_t;

    /**
     * @brief Calculates Steinhart-Hart coefficients.
     *
     * @details https://en.wikipedia.org/wiki/Steinhart%E2%80%93Hart_equation
     * @note The narrowwer the temperature range, the greater the accuracy will be.
     *
     * @param tp_A First temperature point.
     * @param tp_B Second temperature point.
     * @param tp_C Third temperature point.
     *
     * @return Steinhart-Hart coefficients.
     */
    steinhart_coefficients_t thermistor_calc_steinhart_coefficients(temperature_point_t tp_A,
                                                                    temperature_point_t tp_B,
                                                                    temperature_point_t tp_C);

    /**
     * @brief Calculates a thermistor temperature using Steinhart-Hart equation.
     * @details https://en.wikipedia.org/wiki/Steinhart%E2%80%93Hart_equation
     * @param coefficients Steinhart-Hart coefficients.
     * @param resistance Actual measured resistance, in ohms.
     * @return Temperature, in Kelvin.
     */
    double thermistor_calc_temperature_steinhart(const steinhart_coefficients_t coefficients, double resistance);

    /**
     * @brief Calculates a thermistor temperature using Steinhart-Hart Betha equation.
     * @details https://en.wikipedia.org/wiki/Thermistor
     *
     * @param therm_ambient_temperature Ambient temperature, in Kelvin,
     * used to calibrate the thermistor.
     * @param therm_ambient_resistance Thermistor resistance at ambient
     * temperature (therm_ambient_temperature), in ohms.
     * @param therm_betha Thermistor Betha value, given by the manufacturer.
     * @param resistance Actual measured resistance, in ohms.
     *
     * @return Temperature, in Kelvin.
     */
    double thermistor_calc_temperature_steinhart_betha(double therm_ambient_temperature,
                                                       double therm_ambient_resistance,
                                                       double therm_betha,
                                                       double resistance);

    /**
     * @brief Calculates a thermistor resistance using inverse Steinhart-Hart Betha equation.
     * @details https://en.wikipedia.org/wiki/Thermistor
     *
     * @param therm_ambient_temperature Ambient temperature, in Kelvin,
     * used to calibrate the thermistor.
     * @param therm_ambient_resistance Thermistor resistance at ambient
     * temperature (therm_ambient_temperature), in homs.
     * @param therm_betha Thermistor Betha value, given by the manufacturer.
     * @param temperature Actual measured temperature, in Kelvin.
     *
     * @return resistance, in ohms.
     */
    double thermistor_calc_resistance_steinhart_betha(double therm_ambient_temperature,
                                                      double therm_ambient_resistance,
                                                      double therm_betha,
                                                      double temperature);

#ifdef __cplusplus
}
#endif

#endif //__IOT_LIB_THERM_H__