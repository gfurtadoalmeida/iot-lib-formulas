#include "CppUTest/TestHarness.h"
#include "iot_lib_formulas/temperature.h"

TEST_GROUP(TEMPERATURE){};

TEST(TEMPERATURE, Convert_kelvin_to_celsius)
{
    float_type celsius = CONV_KELVIN_CELSIUS(FLOAT_CONST(273.15));

    DOUBLES_EQUAL(0.0, celsius, 0.0001);
}

TEST(TEMPERATURE, Convert_kelvin_to_fahrenheit)
{
    float_type fahrenheit = CONV_KELVIN_FAHRENHEIT(FLOAT_CONST(255.40));

    DOUBLES_EQUAL(0.05, fahrenheit, 0.0001);
}

TEST(TEMPERATURE, Convert_celsius_to_kelvin)
{
    float_type kelvin = CONV_CELSIUS_KELVIN(FLOAT_CONST(-273.15));

    DOUBLES_EQUAL(0.0, kelvin, 0.0001);
}

TEST(TEMPERATURE, Convert_celsius_to_fahrenheit)
{
    float_type fahrenheit = CONV_CELSIUS_FAHRENHEIT(FLOAT_CONST(-17.8));

    DOUBLES_EQUAL(-0.04, fahrenheit, 0.0001);
}

TEST(TEMPERATURE, Convert_fahrenheit_to_kelvin)
{
    float_type kelvin = CONV_FAHRENHEIT_KELVIN(FLOAT_CONST(-459.67));

    DOUBLES_EQUAL(0.0, kelvin, 0.0001);
}

TEST(TEMPERATURE, Convert_fahrenheit_to_celsius)
{
    float_type celsius = CONV_FAHRENHEIT_CELSIUS(FLOAT_CONST(32.0));

    DOUBLES_EQUAL(0.0, celsius, 0.0001);
}