#include <stdint.h>
#include <math.h>
#include "adc/adc.h"

#ifdef __cplusplus
extern "C"
{
#endif

    double adc_calc_frequency_span(double bandwidth)
    {
        return bandwidth * 0.8;
    }

    double adc_calc_sample_optimal_frequency(double bandwidth)
    {
        return bandwidth * 2.0;
    }

    uint16_t adc_calc_oversample_count(uint8_t additional_resolution_bits)
    {
        return (uint16_t)pow(4, additional_resolution_bits);
    }

    double adc_calc_oversample_frequency(uint8_t additional_resolution_bits,
                                         double sampling_frequency)
    {
        return (uint16_t)(pow(4, additional_resolution_bits) * sampling_frequency);
    }

    double adc_calc_signal_noise_ratio(uint8_t effective_number_bits)
    {
        return (6.02 * effective_number_bits) + 1.76;
    }

    uint8_t adc_calc_effective_number_bits(double signal_noise_ratio)
    {
        return (uint8_t)floorl((signal_noise_ratio - 1.76) / 6.02);
    }

    double adc_calc_least_significant_bit(uint8_t resolution_bits, double reference_voltage)
    {
        return reference_voltage / pow(2, resolution_bits);
    }

    double adc_calc_least_significant_bit_diff(uint8_t resolution_bits,
                                               double reference_voltage_pos,
                                               double reference_voltage_neg)
    {
        return (reference_voltage_pos - reference_voltage_neg) / pow(2, resolution_bits);
    }

#ifdef __cplusplus
}
#endif