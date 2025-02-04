#include "common_infra.hpp"
#include "iot_lib_formulas/adc.h"

TEST(ADC, Calc_Frequency_Span)
{
    float_type span = adc_calc_frequency_span(FLOAT_CONST(100.0));

    EXPECT_NEAR(span, 80.0, 0.0000001);
}

TEST(ADC, Calc_Sample_Optimal_Frequency)
{
    float_type frequency = adc_calc_sample_optimal_frequency(FLOAT_CONST(60.0));

    EXPECT_NEAR(frequency, 120.0, 0.0000001);
}

TEST(ADC, Calc_Oversample_Count)
{
    uint16_t count = adc_calc_oversample_count(4);

    EXPECT_EQ(256, count);
}

TEST(ADC, Calc_Oversample_Frequency)
{
    float_type frequency = adc_calc_oversample_frequency(4, FLOAT_CONST(60.0));

    EXPECT_NEAR(15360.0, frequency, 0.0000001);
}

TEST(ADC, Calc_Signal_Noise_Ratio)
{
    float_type decibels = adc_calc_signal_noise_ratio(12);

    EXPECT_NEAR(74.0, decibels, 0.0000001);
}

TEST(ADC, Calc_Effective_Number_Bits)
{
    uint8_t enob = adc_calc_effective_number_bits(FLOAT_CONST(74.0));

    EXPECT_EQ(12, enob);
}

TEST(ADC, Calc_Least_Significant_Bit)
{
    float_type lsb = adc_calc_least_significant_bit(12, FLOAT_CONST(3300.0));

    EXPECT_NEAR(0.8056641, lsb, 0.0000001);
}

TEST(ADC, Calc_Least_Significant_Bit_Diff)
{
    float_type lsb = adc_calc_least_significant_bit_diff(12, FLOAT_CONST(3300.0), FLOAT_CONST(-3300.0));

    EXPECT_NEAR(1.6113281, lsb, 0.0000001);
}
