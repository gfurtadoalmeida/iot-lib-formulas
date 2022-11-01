#include "common.h"
#include "thermistor/thermistor.h"

#ifdef __cplusplus
extern "C"
{
#endif

    steinhart_coefficients_t thermistor_calc_steinhart_coefficients(temperature_point_t tp_A,
                                                                    temperature_point_t tp_B,
                                                                    temperature_point_t tp_C)
    {
        const FLOAT_TYPE log1 = FLOAT_LOG(tp_A.resistance);
        const FLOAT_TYPE log2 = FLOAT_LOG(tp_B.resistance);
        const FLOAT_TYPE log3 = FLOAT_LOG(tp_C.resistance);
        const FLOAT_TYPE y1 = FLOAT_CONST(1.0) / tp_A.temperature;
        const FLOAT_TYPE y2 = FLOAT_CONST(1.0) / tp_B.temperature;
        const FLOAT_TYPE y3 = FLOAT_CONST(1.0) / tp_C.temperature;
        const FLOAT_TYPE gamma2 = (y2 - y1) / (log2 - log1);
        const FLOAT_TYPE gamma3 = (y3 - y1) / (log3 - log1);

        steinhart_coefficients_t coeff;
        coeff.c = ((gamma3 - gamma2) / (log3 - log2)) * FLOAT_POW(log1 + log2 + log3, FLOAT_CONST(-1.0));
        coeff.b = gamma2 - coeff.c * ((log1 * log1) + (log1 * log2) + (log2 * log2));
        coeff.a = y1 - (coeff.b + (log1 * log1 * coeff.c)) * log1;

        return coeff;
    }

    FLOAT_TYPE thermistor_calc_temperature_steinhart(const steinhart_coefficients_t coefficients, FLOAT_TYPE resistance)
    {
        return FLOAT_CONST(1.0) / (coefficients.a + (coefficients.b * FLOAT_LOG(resistance)) + (coefficients.c * FLOAT_POW(FLOAT_LOG(resistance), FLOAT_CONST(3.0))));
    }

    FLOAT_TYPE thermistor_calc_temperature_steinhart_betha(FLOAT_TYPE therm_ambient_temperature,
                                                           FLOAT_TYPE therm_ambient_resistance,
                                                           FLOAT_TYPE therm_betha,
                                                           FLOAT_TYPE resistance)
    {
        return FLOAT_CONST(1.0) / ((FLOAT_CONST(1.0) / therm_ambient_temperature) + (FLOAT_CONST(1.0) / therm_betha) * FLOAT_LOG(resistance / therm_ambient_resistance));
    }

    FLOAT_TYPE thermistor_calc_resistance_steinhart_betha(FLOAT_TYPE therm_ambient_temperature,
                                                          FLOAT_TYPE therm_ambient_resistance,
                                                          FLOAT_TYPE therm_betha,
                                                          FLOAT_TYPE temperature)
    {
        return therm_ambient_resistance * FLOAT_POW(ELECTRON_CHARGE, (therm_betha * ((FLOAT_CONST(1.0) / temperature) - (FLOAT_CONST(1.0) / therm_ambient_temperature))));
    }

#ifdef __cplusplus
}
#endif