#ifndef __IOT_LIB_FORMULAS_VOLT_DIVIDER_H__
#define __IOT_LIB_FORMULAS_VOLT_DIVIDER_H__

#include "float_type.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief Calculates the voltage in, of a resistive voltage divider.
     * @details https://en.wikipedia.org/wiki/Voltage_divider
     * @param[in] resistor_1 Resistor 1 resistance, in ohms.
     * @param[in] resistor_2 Resistor 2 resistance, in ohms.
     * @param[in] voltage_out Voltage out, in millivolts.
     * @return Voltage in, in millivolts.
     */
    float_type volt_divider_resistive_calc_voltage_in(float_type resistor_1, float_type resistor_2, float_type voltage_out);

    /**
     * @brief Calculates the resistor 1 resistance, of a resistive voltage divider.
     * @details https://en.wikipedia.org/wiki/Voltage_divider
     * @param[in] voltage_in Voltage in, in millivolts.
     * @param[in] resistor_2 Resistor 2 resistance, in ohms.
     * @param[in] voltage_out Voltage out, in millivolts.
     * @return Resistor 1 resistance, in ohms.
     */
    float_type volt_divider_resistive_calc_resistor_1(float_type voltage_in, float_type resistor_2, float_type voltage_out);

    /**
     * @brief Calculates the resistor 2 resistance, of a resistive voltage divider.
     * @details https://en.wikipedia.org/wiki/Voltage_divider
     * @param[in] voltage_in Voltage in, in millivolts.
     * @param[in] resistor_1 Resistor 1 resistance, in ohms.
     * @param[in] voltage_out Voltage out, in millivolts.
     * @return Resistor 2 resistance, in ohms.
     */
    float_type volt_divider_resistive_calc_resistor_2(float_type voltage_in, float_type resistor_1, float_type voltage_out);

    /**
     * @brief Calculates the voltage out, of a resistive voltage divider.
     * @details https://en.wikipedia.org/wiki/Voltage_divider
     * @param[in] voltage_in Voltage in, in millivolts.
     * @param[in] resistor_1 Resistor 1 resistance, in ohms.
     * @param[in] resistor_2 Resistor 2 resistance, in ohms.
     * @return Voltage out, in millivolts.
     */
    float_type volt_divider_resistive_calc_voltage_out(float_type voltage_in, float_type resistor_1, float_type resistor_2);

#ifdef __cplusplus
}
#endif
#endif