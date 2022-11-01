#include "CppUTest/TestHarness.h"
#include "conversion.h"

TEST_GROUP(CONVERSION){};

TEST(CONVERSION, Convert_kelvin_to_celsius)
{
    FLOAT_TYPE celsius = CONV_KELVIN_CELSIUS(FLOAT_CONST(273.15));

    DOUBLES_EQUAL(0.0, celsius, 0.0001);
}

TEST(CONVERSION, Convert_kelvin_to_fahrenheit)
{
    FLOAT_TYPE fahrenheit = CONV_KELVIN_FAHRENHEIT(FLOAT_CONST(255.40));

    DOUBLES_EQUAL(0.05, fahrenheit, 0.0001);
}

TEST(CONVERSION, Convert_celsius_to_kelvin)
{
    FLOAT_TYPE kelvin = CONV_CELSIUS_KELVIN(FLOAT_CONST(-273.15));

    DOUBLES_EQUAL(0.0, kelvin, 0.0001);
}

TEST(CONVERSION, Convert_celsius_to_fahrenheit)
{
    FLOAT_TYPE fahrenheit = CONV_CELSIUS_FAHRENHEIT(FLOAT_CONST(-17.8));

    DOUBLES_EQUAL(-0.04, fahrenheit, 0.0001);
}

TEST(CONVERSION, Convert_fahrenheit_to_kelvin)
{
    FLOAT_TYPE kelvin = CONV_FAHRENHEIT_KELVIN(FLOAT_CONST(-459.67));

    DOUBLES_EQUAL(0.0, kelvin, 0.0001);
}

TEST(CONVERSION, Convert_fahrenheit_to_celsius)
{
    FLOAT_TYPE celsius = CONV_FAHRENHEIT_CELSIUS(FLOAT_CONST(32.0));

    DOUBLES_EQUAL(0.0, celsius, 0.0001);
}