#ifndef __IOT_LIB_THERM_H__
#define __IOT_LIB_THERM_H__

#include "common.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Common ambient temperature, in Kelvin, used to calibrate thermistors probes: 298.15 K, 25°C, 77°F
 */
#define COMMON_THERM_PROBE_AMBIENT_TEMP_KELVIN FLOAT_CONST(298.15)
/**
 * Common thermistors probes resistance, in ohms: 10K
 */
#define COMMON_THERM_PROBE_RESISTANCE FLOAT_CONST(10000.0)
/**
 * Common thermistors probes Betha: 3950.0
 */
#define COMMON_THERM_PROBE_BETHA FLOAT_CONST(3950.0)

    /**
     * @typedef temperature_point_t
     * @brief Thermistor resistance measured at a certain temperature.
     */
    typedef struct
    {
        float_type temperature; /*!< Temperature, in Kelvin. */
        float_type resistance;  /*!< resistance, in ohms. */
    } temperature_point_t;

    /**
     * @typedef steinhart_coefficients_t
     * @brief Steinhart-Hart coefficients.
     */
    typedef struct
    {
        float_type a;
        float_type b;
        float_type c;
    } steinhart_coefficients_t;

    /**
     * @brief Calculates Steinhart-Hart coefficients.
     *
     * @details https://en.wikipedia.org/wiki/Steinhart%E2%80%93Hart_equation
     * @note The narrower the temperature range, the greater the accuracy will be.
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
     *
     * @param coefficients Steinhart-Hart coefficients.
     * @param resistance Actual measured resistance, in ohms.
     *
     * @return Temperature, in Kelvin.
     */
    float_type thermistor_calc_temperature_steinhart(const steinhart_coefficients_t coefficients, float_type resistance);

    /**
     * @brief Calculates a thermistor temperature using Steinhart-Hart Betha equation.
     * @details https://en.wikipedia.org/wiki/Thermistor
     *
     * @param therm_ambient_temperature Ambient temperature, in Kelvin,
     * used to calibrate the thermistor.
     * @param therm_ambient_resistance Thermistor resistance at ambient
     * temperature, in ohms.
     * @param therm_betha Thermistor Betha value, given by the manufacturer.
     * @param resistance Actual measured resistance, in ohms.
     *
     * @return Temperature, in Kelvin.
     */
    float_type thermistor_calc_temperature_steinhart_betha(float_type therm_ambient_temperature,
                                                           float_type therm_ambient_resistance,
                                                           float_type therm_betha,
                                                           float_type resistance);

    /**
     * @brief Calculates a thermistor resistance using inverse Steinhart-Hart Betha equation.
     * @details https://en.wikipedia.org/wiki/Thermistor
     *
     * @param therm_ambient_temperature Ambient temperature, in Kelvin,
     * used to calibrate the thermistor.
     * @param therm_ambient_resistance Thermistor resistance at ambient
     * temperature, in ohms.
     * @param therm_betha Thermistor Betha value, given by the manufacturer.
     * @param temperature Actual measured temperature, in Kelvin.
     *
     * @return Resistance, in ohms.
     */
    float_type thermistor_calc_resistance_steinhart_betha(float_type therm_ambient_temperature,
                                                          float_type therm_ambient_resistance,
                                                          float_type therm_betha,
                                                          float_type temperature);

#ifdef __cplusplus
}
#endif

#endif //__IOT_LIB_THERM_H__