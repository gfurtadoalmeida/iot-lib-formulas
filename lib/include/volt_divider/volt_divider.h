#ifndef __IOT_LIB_VOLT_DIVIDER_H__
#define __IOT_LIB_VOLT_DIVIDER_H__

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief Calculates the voltage out of a resistive voltage divider.
     *
     * @details https://en.wikipedia.org/wiki/Voltage_divider
     *
     * @param voltage_in Voltage in, in volts.
     * @param resistor_1 Resistor 1 resistance, in ohms.
     * @param resistor_2 Resistor 2 resistance, in ohms.
     *
     * @return Voltage out, in volts.
     */
    double volt_divider_resistive_calc_voltage_out(double voltage_in, double resistor_1, double resistor_2);

    /**
     * @brief Calculates the resistor 1 resistance, of a resistive voltage divider.
     *
     * @details https://en.wikipedia.org/wiki/Voltage_divider
     *
     * @param voltage_in Voltage in, in volts.
     * @param resistor_2 Resistor 2 resistance, in ohms.
     * @param voltage_out Voltage out, in volts.
     *
     * @return Resistor 1 resistance, in ohms.
     */
    double volt_divider_resistive_calc_resistor_1(double voltage_in, double resistor_2, double voltage_out);

    /**
     * @brief Calculates the resistor 2 resistance, of a resistive voltage divider.
     *
     * @details https://en.wikipedia.org/wiki/Voltage_divider
     *
     * @param voltage_in Voltage in, in volts.
     * @param resistor_1 Resistor 1 resistance, in ohms.
     * @param voltage_out Voltage out, in volts.
     *
     * @return Resistor 2 resistance, in ohms.
     */
    double volt_divider_resistive_calc_resistor_2(double voltage_in, double resistor_1, double voltage_out);

#ifdef __cplusplus
}
#endif

#endif //__IOT_LIB_VOLT_DIVIDER_H__