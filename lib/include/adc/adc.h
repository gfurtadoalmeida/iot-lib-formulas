#ifndef __IOT_LIB_ADC_H__
#define __IOT_LIB_ADC_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief Calculates the frequency range over which measurements will be taken and
     * not be effected by the anti-aliasing low-pass filters; the alias-free region of the bandwidth.
     * @details It is 80% of the bandwidth.
     *
     * @param bandwidth Frequency range over which measurements will be taken.
     *
     * @return Frequency span, in hertz.
     */
    double adc_calc_frequency_span(double bandwidth);

    /**
     * @brief Calculates the optimal sampling frequency.
     * @details https://en.wikipedia.org/wiki/Nyquist%E2%80%93Shannon_sampling_theorem
     *
     * @param bandwidth The frequency range over which measurements will be taken.
     *
     * @return Optimal sampling frequency, in hertz.
     */
    double adc_calc_sample_optimal_frequency(double bandwidth);

    /**
     * @brief Calculates how many times one needs to sample to increase an ADC resolution.
     * @details Used when increasing the ADC sampling frequency is not possible.
     *
     * @param additional_resolution_bits Number of additional bits needed.
     *
     * @return How many times to sample.
     */
    uint16_t adc_calc_oversample_count(uint8_t additional_resolution_bits);

    /**
     * @brief Calculates the sampling frequency needed to increase an ADC resolution.
     *
     * @param additional_resolution_bits Number of additional bits needed.
     * @param sampling_frequency ADC sampling frequency.
     *
     * @return New ADC sampling frequency.
     */
    double adc_calc_oversample_frequency(uint8_t additional_resolution_bits,
                                         double sampling_frequency);

    /**
     * @brief Calculates the signal-to-noise ratio (ratio of the RMS signal power to
     * the RMS noise power).
     * @details https://en.wikipedia.org/wiki/Signal-to-noise_ratio
     *
     * @param effective_number_bits ADC resolution.
     *
     * @return Signal-to-noise ration, in decibels.
     */
    double adc_calc_signal_noise_ratio(uint8_t effective_number_bits);

    /**
     * @brief Calculates the effective number of bits (ENOB) necessary to achieve a
     * signal-to-noise ratio.
     * @details https://en.wikipedia.org/wiki/Effective_number_of_bits
     *
     * @param signal_noise_ratio Signal-to-noise ration, in decibels.
     *
     * @return Effective number of bits.
     */
    uint8_t adc_calc_effective_number_bits(double signal_noise_ratio);

    /**
     * @brief Calculates the least significant bit (LSB) value.
     * @details The LSB is the ADCs voltage interval; the smallest voltage needed
     * to flip a bit on the ADC.
     *
     * @param resolution_bits ADC resolution bits.
     * @param reference_voltage Reference voltage, in millivolts.
     *
     * @return LSB, in millivolts.
     */
    double adc_calc_least_significant_bit(uint8_t resolution_bits, double reference_voltage);

    /**
     * @brief Calculates the least significant bit (LSB) value, for a differential ADC.
     * @details The LSB is the ADCs voltage interval; the smallest voltage needed
     * to flip a bit on the ADC.
     *
     * @param resolution_bits ADC resolution bits.
     * @param reference_voltage_pos Positive reference voltage, in millivolts.
     * @param reference_voltage_neg Negative reference voltage, in millivolts.
     *
     * @return LSB, in millivolts.
     */
    double adc_calc_least_significant_bit_diff(uint8_t resolution_bits,
                                               double reference_voltage_pos,
                                               double reference_voltage_neg);

#ifdef __cplusplus
}
#endif

#endif //__IOT_LIB_ADC_H__