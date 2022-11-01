#include "volt_divider/volt_divider.h"

#ifdef __cplusplus
extern "C"
{
#endif

    FLOAT_TYPE volt_divider_resistive_calc_voltage_in(FLOAT_TYPE resistor_1, FLOAT_TYPE resistor_2, FLOAT_TYPE voltage_out)
    {
        return voltage_out / (resistor_2 / (resistor_1 + resistor_2));
    }

    FLOAT_TYPE volt_divider_resistive_calc_resistor_1(FLOAT_TYPE voltage_in, FLOAT_TYPE resistor_2, FLOAT_TYPE voltage_out)
    {
        return resistor_2 * ((voltage_in / voltage_out) - FLOAT_CONST(1.0));
    }

    FLOAT_TYPE volt_divider_resistive_calc_resistor_2(FLOAT_TYPE voltage_in, FLOAT_TYPE resistor_1, FLOAT_TYPE voltage_out)
    {
        return resistor_1 * (FLOAT_CONST(1.0) / ((voltage_in / voltage_out) - FLOAT_CONST(1.0)));
    }

    FLOAT_TYPE volt_divider_resistive_calc_voltage_out(FLOAT_TYPE voltage_in, FLOAT_TYPE resistor_1, FLOAT_TYPE resistor_2)
    {
        return (resistor_2 / (resistor_1 + resistor_2)) * voltage_in;
    }

#ifdef __cplusplus
}
#endif