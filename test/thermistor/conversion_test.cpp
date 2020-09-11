#include <math.h>
#include "CppUTest/TestHarness.h"
#include "thermistor/thermistor.h"

TEST_GROUP(TEMPERATURE_CONV){};

TEST(TEMPERATURE_CONV, Convert_kelvin_to_celsius)
{
    const double celsius = CONV_KELVIN_CELSIUS(273.15);

    DOUBLES_EQUAL(0.0, celsius, 0.1);
}

TEST(TEMPERATURE_CONV, Convert_kelvin_to_fahrenheit)
{
    const double fahrenheit = CONV_KELVIN_FAHRENHEIT(255.40);

    DOUBLES_EQUAL(0.05, fahrenheit, 0.1);
}

TEST(TEMPERATURE_CONV, Convert_celsius_to_kelvin)
{
    const double kelvin = CONV_CELSIUS_KELVIN(-273.15);

    DOUBLES_EQUAL(0.0, kelvin, 0.1);
}

TEST(TEMPERATURE_CONV, Convert_celsius_to_fahrenheit)
{
    const double fahrenheit = CONV_CELSIUS_FAHRENHEIT(-17.8);

    DOUBLES_EQUAL(-0.04, fahrenheit, 0.1);
}

TEST(TEMPERATURE_CONV, Convert_fahrenheit_to_kelvin)
{
    const double kelvin = CONV_FAHRENHEIT_KELVIN(-459.67);

    DOUBLES_EQUAL(0.0, kelvin, 0.1);
}

TEST(TEMPERATURE_CONV, Convert_fahrenheit_to_celsius)
{
    const double celsius = CONV_FAHRENHEIT_CELSIUS(32.0);

    DOUBLES_EQUAL(0.0, celsius, 0.1);
}