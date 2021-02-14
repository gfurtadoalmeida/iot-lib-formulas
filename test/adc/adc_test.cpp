#include <stdint.h>
#include <math.h>
#include "CppUTest/TestHarness.h"
#include "adc/adc.h"

TEST_GROUP(ADC){};

TEST(ADC, Calc_Frequency_Span)
{
    const double span = adc_calc_frequency_span(100);

    DOUBLES_EQUAL(span, 80.0, 0.001);
}

TEST(ADC, Calc_Sample_Optimal_Frequency)
{
    const double frequency = adc_calc_sample_optimal_frequency(60.0);

    DOUBLES_EQUAL(frequency, 120.0, 0.001);
}

TEST(ADC, Calc_Oversample_Count)
{
    const uint16_t count = adc_calc_oversample_count(4);

    UNSIGNED_LONGS_EQUAL(256, count);
}

TEST(ADC, Calc_Oversample_Frequency)
{
    const double frequency = adc_calc_oversample_frequency(4, 60.0);

    DOUBLES_EQUAL(15360.0, frequency, 0.001);
}

TEST(ADC, Calc_Signal_Noise_Ratio)
{
    const double decibels = adc_calc_signal_noise_ratio(12);

    DOUBLES_EQUAL(74.0, decibels, 0.001);
}

TEST(ADC, Calc_Effective_Number_Bits)
{
    const uint8_t enob = adc_calc_effective_number_bits(74.0);

    UNSIGNED_LONGS_EQUAL(12, enob);
}

TEST(ADC, Calc_Least_Significant_Bit)
{
    const double lsb = adc_calc_least_significant_bit(12, 3300);

    DOUBLES_EQUAL(0.805, lsb, 0.001);
}

TEST(ADC, Calc_Least_Significant_Bit_Diff)
{
    const double lsb = adc_calc_least_significant_bit_diff(12, 3300, -3300);

    DOUBLES_EQUAL(1.611, lsb, 0.001);
}
