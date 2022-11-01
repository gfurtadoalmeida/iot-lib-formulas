#include "adc/adc.h"

#ifdef __cplusplus
extern "C"
{
#endif

    FLOAT_TYPE adc_calc_frequency_span(FLOAT_TYPE bandwidth)
    {
        return bandwidth * FLOAT_CONST(0.8);
    }

    FLOAT_TYPE adc_calc_sample_optimal_frequency(FLOAT_TYPE bandwidth)
    {
        return bandwidth * FLOAT_CONST(2.0);
    }

    uint16_t adc_calc_oversample_count(uint8_t additional_resolution_bits)
    {
        return (uint16_t)FLOAT_POW(4, additional_resolution_bits);
    }

    FLOAT_TYPE adc_calc_oversample_frequency(uint8_t additional_resolution_bits, FLOAT_TYPE sampling_frequency)
    {
        return (uint16_t)(FLOAT_POW(4, additional_resolution_bits) * sampling_frequency);
    }

    FLOAT_TYPE adc_calc_signal_noise_ratio(uint8_t effective_number_bits)
    {
        return (FLOAT_CONST(6.02) * effective_number_bits) + FLOAT_CONST(1.76);
    }

    uint8_t adc_calc_effective_number_bits(FLOAT_TYPE signal_noise_ratio)
    {
        return (uint8_t)FLOAT_FLOOR((signal_noise_ratio - FLOAT_CONST(1.76)) / FLOAT_CONST(6.02));
    }

    FLOAT_TYPE adc_calc_least_significant_bit(uint8_t resolution_bits, FLOAT_TYPE reference_voltage)
    {
        return reference_voltage / FLOAT_POW(2, resolution_bits);
    }

    FLOAT_TYPE adc_calc_least_significant_bit_diff(uint8_t resolution_bits,
                                                   FLOAT_TYPE reference_voltage_pos,
                                                   FLOAT_TYPE reference_voltage_neg)
    {
        return (reference_voltage_pos - reference_voltage_neg) / FLOAT_POW(2, resolution_bits);
    }

#ifdef __cplusplus
}
#endif