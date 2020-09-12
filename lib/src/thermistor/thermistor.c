#include <math.h>
#include "constants.h"
#include "thermistor/thermistor.h"

#ifdef __cplusplus
extern "C"
{
#endif

    steinhart_coefficients_t thermistor_calc_steinhart_coefficients(temperature_point_t tp_A,
                                                                    temperature_point_t tp_B,
                                                                    temperature_point_t tp_C)
    {
        const double log1 = log(tp_A.resistance);
        const double log2 = log(tp_B.resistance);
        const double log3 = log(tp_C.resistance);
        const double y1 = 1.0 / tp_A.temperature;
        const double y2 = 1.0 / tp_B.temperature;
        const double y3 = 1.0 / tp_C.temperature;
        const double gamma2 = (y2 - y1) / (log2 - log1);
        const double gamma3 = (y3 - y1) / (log3 - log1);

        steinhart_coefficients_t coeff;
        coeff.c = ((gamma3 - gamma2) / (log3 - log2)) * pow(log1 + log2 + log3, -1.0);
        coeff.b = gamma2 - coeff.c * ((log1 * log1) + (log1 * log2) + (log2 * log2));
        coeff.a = y1 - (coeff.b + (log1 * log1 * coeff.c)) * log1;

        return coeff;
    }

    double thermistor_calc_temperature_steinhart(const steinhart_coefficients_t coefficients, double resistance)
    {
        return 1.0 / (coefficients.a + (coefficients.b * log(resistance)) + (coefficients.c * pow(log(resistance), 3.0)));
    }

    double thermistor_calc_temperature_steinhart_betha(double therm_ambient_temperature,
                                                       double therm_ambient_resistance,
                                                       double therm_betha,
                                                       double resistance)
    {
        return 1.0 / ((1.0 / therm_ambient_temperature) + (1.0 / therm_betha) * log(resistance / therm_ambient_resistance));
    }

    double thermistor_calc_resistance_steinhart_betha(double therm_ambient_temperature,
                                                      double therm_ambient_resistance,
                                                      double therm_betha,
                                                      double temperature)
    {
        return therm_ambient_resistance * pow(ELECTRON_CHARGE, (therm_betha * ((1.0 / temperature) - (1.0 / therm_ambient_temperature))));
    }

#ifdef __cplusplus
}
#endif