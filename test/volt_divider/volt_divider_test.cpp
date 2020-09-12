#include "CppUTest/TestHarness.h"
#include "volt_divider/volt_divider.h"

TEST_GROUP(VOLT_DIVIDER){};

TEST(VOLT_DIVIDER, Calc_resistive_voltage_out)
{
    double voltage = volt_divider_resistive_calc_voltage_out(3300.0, 10000.0, 5000.0);

    DOUBLES_EQUAL(1100.0, voltage, 0.0001);
}

TEST(VOLT_DIVIDER, Calc_resistive_resistance_1)
{
    double voltage = volt_divider_resistive_calc_resistor_1(3300.0, 5000.0, 1100.0);

    DOUBLES_EQUAL(10000.0, voltage, 0.0001);
}

TEST(VOLT_DIVIDER, Calc_resistive_resistance_2)
{
    double voltage = volt_divider_resistive_calc_resistor_2(3300.0, 10000.0, 1100.0);

    DOUBLES_EQUAL(5000.0, voltage, 0.0001);
}