#ifndef __IOT_LIB_VOLT_DIVIDER_H__
#define __IOT_LIB_VOLT_DIVIDER_H__

#include "common.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief Calculates the voltage in, of a resistive voltage divider.
     * @details https://en.wikipedia.org/wiki/Voltage_divider
     *
     * @param resistor_1 Resistor 1 resistance, in ohms.
     * @param resistor_2 Resistor 2 resistance, in ohms.
     * @param voltage_out Voltage out, in millivolts.
     *
     * @return Voltage in, in millivolts.
     */
    FLOAT_TYPE volt_divider_resistive_calc_voltage_in(FLOAT_TYPE resistor_1, FLOAT_TYPE resistor_2, FLOAT_TYPE voltage_out);

    /**
     * @brief Calculates the resistor 1 resistance, of a resistive voltage divider.
     * @details https://en.wikipedia.org/wiki/Voltage_divider
     *
     * @param voltage_in Voltage in, in millivolts.
     * @param resistor_2 Resistor 2 resistance, in ohms.
     * @param voltage_out Voltage out, in millivolts.
     *
     * @return Resistor 1 resistance, in ohms.
     */
    FLOAT_TYPE volt_divider_resistive_calc_resistor_1(FLOAT_TYPE voltage_in, FLOAT_TYPE resistor_2, FLOAT_TYPE voltage_out);

    /**
     * @brief Calculates the resistor 2 resistance, of a resistive voltage divider.
     * @details https://en.wikipedia.org/wiki/Voltage_divider
     *
     * @param voltage_in Voltage in, in millivolts.
     * @param resistor_1 Resistor 1 resistance, in ohms.
     * @param voltage_out Voltage out, in millivolts.
     *
     * @return Resistor 2 resistance, in ohms.
     */
    FLOAT_TYPE volt_divider_resistive_calc_resistor_2(FLOAT_TYPE voltage_in, FLOAT_TYPE resistor_1, FLOAT_TYPE voltage_out);

    /**
     * @brief Calculates the voltage out, of a resistive voltage divider.
     * @details https://en.wikipedia.org/wiki/Voltage_divider
     *
     * @param voltage_in Voltage in, in millivolts.
     * @param resistor_1 Resistor 1 resistance, in ohms.
     * @param resistor_2 Resistor 2 resistance, in ohms.
     *
     * @return Voltage out, in millivolts.
     */
    FLOAT_TYPE volt_divider_resistive_calc_voltage_out(FLOAT_TYPE voltage_in, FLOAT_TYPE resistor_1, FLOAT_TYPE resistor_2);

#ifdef __cplusplus
}
#endif

#endif //__IOT_LIB_VOLT_DIVIDER_H__