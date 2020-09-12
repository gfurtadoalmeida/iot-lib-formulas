#include "volt_divider/volt_divider.h"

#ifdef __cplusplus
extern "C"
{
#endif

    double volt_divider_resistive_calc_voltage_out(double voltage_in, double resistor_1, double resistor_2)
    {
        return (resistor_2 / (resistor_1 + resistor_2)) * voltage_in;
    }

    double volt_divider_resistive_calc_resistor_1(double voltage_in, double resistor_2, double voltage_out)
    {
        return resistor_2 * ((voltage_in / voltage_out) - 1.0);
    }

    double volt_divider_resistive_calc_resistor_2(double voltage_in, double resistor_1, double voltage_out)
    {
        return resistor_1 * (1.0 / ((voltage_in / voltage_out) - 1.0));
    }

#ifdef __cplusplus
}
#endif