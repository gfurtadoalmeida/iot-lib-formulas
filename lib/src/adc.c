#include "iot_lib_formulas/adc.h"
#include "infrastructure.h"

float_type adc_calc_frequency_span(float_type bandwidth)
{
    return bandwidth * FLOAT_CONST(0.8);
}

float_type adc_calc_sample_optimal_frequency(float_type bandwidth)
{
    return bandwidth * FLOAT_CONST(2.0);
}

uint16_t adc_calc_oversample_count(uint8_t additional_resolution_bits)
{
    return (uint16_t)FLOAT_POW(4, additional_resolution_bits);
}

float_type adc_calc_oversample_frequency(uint8_t additional_resolution_bits, float_type sampling_frequency)
{
    return FLOAT_POW(4, additional_resolution_bits) * sampling_frequency;
}

float_type adc_calc_signal_noise_ratio(uint8_t effective_number_bits)
{
    return (FLOAT_CONST(6.02) * effective_number_bits) + FLOAT_CONST(1.76);
}

uint8_t adc_calc_effective_number_bits(float_type signal_noise_ratio)
{
    return (uint8_t)FLOAT_FLOOR((signal_noise_ratio - FLOAT_CONST(1.76)) / FLOAT_CONST(6.02));
}

float_type adc_calc_least_significant_bit(uint8_t resolution_bits, float_type reference_voltage)
{
    return reference_voltage / FLOAT_POW(2, resolution_bits);
}

float_type adc_calc_least_significant_bit_diff(uint8_t resolution_bits,
                                               float_type reference_voltage_pos,
                                               float_type reference_voltage_neg)
{
    return (reference_voltage_pos - reference_voltage_neg) / FLOAT_POW(2, resolution_bits);
}