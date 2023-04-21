#include "iot_lib_formulas/voltage_divider.h"
#include "infrastructure.h"

float_type volt_divider_resistive_calc_voltage_in(float_type resistor_1, float_type resistor_2, float_type voltage_out)
{
    return voltage_out / (resistor_2 / (resistor_1 + resistor_2));
}

float_type volt_divider_resistive_calc_resistor_1(float_type voltage_in, float_type resistor_2, float_type voltage_out)
{
    return resistor_2 * ((voltage_in / voltage_out) - FLOAT_CONST(1.0));
}

float_type volt_divider_resistive_calc_resistor_2(float_type voltage_in, float_type resistor_1, float_type voltage_out)
{
    return resistor_1 * (FLOAT_CONST(1.0) / ((voltage_in / voltage_out) - FLOAT_CONST(1.0)));
}

float_type volt_divider_resistive_calc_voltage_out(float_type voltage_in, float_type resistor_1, float_type resistor_2)
{
    return (resistor_2 / (resistor_1 + resistor_2)) * voltage_in;
}
