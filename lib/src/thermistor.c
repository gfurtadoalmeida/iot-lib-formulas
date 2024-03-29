#include "iot_lib_formulas/thermistor.h"
#include "infrastructure.h"

void thermistor_calc_steinhart_coefficients(const temperature_point_t *tp_A,
                                            const temperature_point_t *tp_B,
                                            const temperature_point_t *tp_C,
                                            steinhart_coefficients_t *coefficients)
{
    const float_type log1 = FLOAT_LOG(tp_A->resistance);
    const float_type log2 = FLOAT_LOG(tp_B->resistance);
    const float_type log3 = FLOAT_LOG(tp_C->resistance);
    const float_type y1 = FLOAT_CONST(1.0) / tp_A->temperature;
    const float_type y2 = FLOAT_CONST(1.0) / tp_B->temperature;
    const float_type y3 = FLOAT_CONST(1.0) / tp_C->temperature;
    const float_type gamma2 = (y2 - y1) / (log2 - log1);
    const float_type gamma3 = (y3 - y1) / (log3 - log1);

    coefficients->c = ((gamma3 - gamma2) / (log3 - log2)) * FLOAT_POW(log1 + log2 + log3, FLOAT_CONST(-1.0));
    coefficients->b = gamma2 - coefficients->c * ((log1 * log1) + (log1 * log2) + (log2 * log2));
    coefficients->a = y1 - (coefficients->b + (log1 * log1 * coefficients->c)) * log1;
}

float_type thermistor_calc_temperature_steinhart(const steinhart_coefficients_t *coefficients, float_type resistance)
{
    return FLOAT_CONST(1.0) / (coefficients->a + (coefficients->b * FLOAT_LOG(resistance)) + (coefficients->c * FLOAT_POW(FLOAT_LOG(resistance), FLOAT_CONST(3.0))));
}

float_type thermistor_calc_temperature_steinhart_betha(float_type therm_ambient_temperature,
                                                       float_type therm_ambient_resistance,
                                                       float_type therm_betha,
                                                       float_type resistance)
{
    return FLOAT_CONST(1.0) / ((FLOAT_CONST(1.0) / therm_ambient_temperature) + (FLOAT_CONST(1.0) / therm_betha) * FLOAT_LOG(resistance / therm_ambient_resistance));
}

float_type thermistor_calc_resistance_steinhart_betha(float_type therm_ambient_temperature,
                                                      float_type therm_ambient_resistance,
                                                      float_type therm_betha,
                                                      float_type temperature)
{
    return therm_ambient_resistance * FLOAT_POW(ELECTRON_CHARGE, (therm_betha * ((FLOAT_CONST(1.0) / temperature) - (FLOAT_CONST(1.0) / therm_ambient_temperature))));
}
