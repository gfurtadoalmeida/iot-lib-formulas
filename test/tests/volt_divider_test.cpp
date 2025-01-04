#include "common_infra.hpp"
#include "iot_lib_formulas/voltage_divider.h"

TEST(VOLT_DIVIDER, Calc_resistive_voltage_in)
{
    float_type voltage = volt_divider_resistive_calc_voltage_in(FLOAT_CONST(10000.0), FLOAT_CONST(5000.0), FLOAT_CONST(3300.0));

    EXPECT_NEAR(9900.0, voltage, 0.0000001);
}

TEST(VOLT_DIVIDER, Calc_resistive_resistance_1)
{
    float_type voltage = volt_divider_resistive_calc_resistor_1(FLOAT_CONST(3300.0), FLOAT_CONST(5000.0), FLOAT_CONST(1100.0));

    EXPECT_NEAR(10000.0, voltage, 0.0000001);
}

TEST(VOLT_DIVIDER, Calc_resistive_resistance_2)
{
    float_type voltage = volt_divider_resistive_calc_resistor_2(FLOAT_CONST(3300.0), FLOAT_CONST(10000.0), FLOAT_CONST(1100.0));

    EXPECT_NEAR(5000.0, voltage, 0.0000001);
}

TEST(VOLT_DIVIDER, Calc_resistive_voltage_out)
{
    float_type voltage = volt_divider_resistive_calc_voltage_out(FLOAT_CONST(3300.0), FLOAT_CONST(10000.0), FLOAT_CONST(5000.0));

    EXPECT_NEAR(1100.0, voltage, 0.0000001);
}
