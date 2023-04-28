# IoT Formulas Library

![GitHub Build Status](https://github.com/gfurtadoalmeida/iot-lib-formulas/actions/workflows/build.yml/badge.svg) [![Bugs](https://sonarcloud.io/api/project_badges/measure?project=iot_lib_formulas&metric=bugs)](https://sonarcloud.io/summary/new_code?id=iot_lib_formulas) [![Code Smells](https://sonarcloud.io/api/project_badges/measure?project=iot_lib_formulas&metric=code_smells)](https://sonarcloud.io/summary/new_code?id=iot_lib_formulas) [![Maintainability Rating](https://sonarcloud.io/api/project_badges/measure?project=iot_lib_formulas&metric=sqale_rating)](https://sonarcloud.io/summary/new_code?id=iot_lib_formulas) [![Security Rating](https://sonarcloud.io/api/project_badges/measure?project=iot_lib_formulas&metric=security_rating)](https://sonarcloud.io/summary/new_code?id=iot_lib_formulas)      
A **C** library with functions for common formulas used by embedded systems.  

## Characteristics

* Portable-ish: only `double` and `float` [depending on the compilation](https://github.com/gfurtadoalmeida/iot-lib-formulas/wiki/Choosing-the-Decimal-Type), are not portable.
* Testable: 20+ tests.
* [ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/): can be used as a [component](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/build-system.html#component-cmakelists-files), with the name `iot-lib-formulas`.

## Formulas For

* [ADC](https://github.com/gfurtadoalmeida/iot-lib-formulas/wiki/ADC)
* [Temperature](https://github.com/gfurtadoalmeida/iot-lib-formulas/wiki/Temperature)
* [Thermistor](https://github.com/gfurtadoalmeida/iot-lib-formulas/wiki/Thermistor)
* [Voltage Divider](https://github.com/gfurtadoalmeida/iot-lib-formulas/wiki/Voltage-Divider)

## Documentation

Everything is on the [wiki](https://github.com/gfurtadoalmeida/iot-lib-formulas/wiki).

## Example: Calculate Temperature in ºC from Thermistor on a Voltage Divider

```cpp
#include <stdio.h>
#include "iot_lib_formulas/voltage_divider.h"
#include "iot_lib_formulas/thermistor.h"
#include "iot_lib_formulas/temperature.h"

void app_main(void)
{
    float_type thermistor_resistance = volt_divider_resistive_calc_resistor_2(5.0,     // 5V in.
                                                                              10000.0, // 10K resistor 1
                                                                              2.5);    // 2.5V out.

    float_type kelvin = thermistor_calc_temperature_steinhart_betha(COMMON_THERM_PROBE_AMBIENT_TEMP_KELVIN,
                                                                    COMMON_THERM_PROBE_RESISTANCE,
                                                                    COMMON_THERM_PROBE_BETHA,
                                                                    thermistor_resistance);
    float_type celsius = CONV_KELVIN_CELSIUS(kelvin);

    prinft("Temperature: %f celsius", celsius);
}
```
