#include <math.h>
#include "CppUTest/TestHarness.h"
#include "thermistor/thermistor.h"

TEST_GROUP(THERMISTOR){};

TEST(THERMISTOR, Calc_Steinhart_coefficients)
{
    temperature_point_t c1;
    c1.temperature = 273.15;
    c1.resistance = 9500.00;

    temperature_point_t c2;
    c2.temperature = 297.039;
    c2.resistance = 2100.00;

    temperature_point_t c3;
    c3.temperature = 322.039;
    c3.resistance = 1000.00;

    steinhart_coefficients_t coeff = thermistor_calc_steinhart_coefficients(c1, c2, c3);

    DOUBLES_EQUAL(-0.0015925922146267837, coeff.a, 0.0000001);
    DOUBLES_EQUAL(0.0008205491888240184, coeff.b, 0.0000001);
    DOUBLES_EQUAL(-0.0000029438499727564513, coeff.c, 0.0000001);
}

TEST(THERMISTOR, Calc_temperature_Steinhart)
{
    temperature_point_t c1;
    c1.temperature = 273.15;
    c1.resistance = 9500.00;

    temperature_point_t c2;
    c2.temperature = 297.039;
    c2.resistance = 2100.00;

    temperature_point_t c3;
    c3.temperature = 322.039;
    c3.resistance = 1000.00;

    steinhart_coefficients_t coeff = thermistor_calc_steinhart_coefficients(c1, c2, c3);

    double temperature = thermistor_calc_temperature_steinhart(coeff, 1800.00);

    DOUBLES_EQUAL(301.37318220079516, temperature, 0.001);
}

TEST(THERMISTOR, Calc_temperature_Steinhart_Betha)
{
    double temperature = thermistor_calc_temperature_steinhart_betha(COMMON_THERM_PROBE_AMBIENT_TEMP_KELVIN,
                                                                     10000.00,
                                                                     3950.00,
                                                                     10000.00);

    DOUBLES_EQUAL(COMMON_THERM_PROBE_AMBIENT_TEMP_KELVIN, temperature, 0.0000001);
}

TEST(THERMISTOR, Calc_resistance_Steinhart_Betha)
{
    double resistance = thermistor_calc_resistance_steinhart_betha(COMMON_THERM_PROBE_AMBIENT_TEMP_KELVIN,
                                                                   10000.00,
                                                                   3950.00,
                                                                   COMMON_THERM_PROBE_AMBIENT_TEMP_KELVIN);
    DOUBLES_EQUAL(10000.00, resistance, 0.0000001);
}