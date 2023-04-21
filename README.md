# IoT Formulas Library

![GitHub Build Status](https://github.com/gfurtadoalmeida/iot-lib-formulas/actions/workflows/build.yml/badge.svg) [![Bugs](https://sonarcloud.io/api/project_badges/measure?project=iot_lib_formulas&metric=bugs)](https://sonarcloud.io/summary/new_code?id=iot_lib_formulas) [![Code Smells](https://sonarcloud.io/api/project_badges/measure?project=iot_lib_formulas&metric=code_smells)](https://sonarcloud.io/summary/new_code?id=iot_lib_formulas) [![Maintainability Rating](https://sonarcloud.io/api/project_badges/measure?project=iot_lib_formulas&metric=sqale_rating)](https://sonarcloud.io/summary/new_code?id=iot_lib_formulas) [![Security Rating](https://sonarcloud.io/api/project_badges/measure?project=iot_lib_formulas&metric=security_rating)](https://sonarcloud.io/summary/new_code?id=iot_lib_formulas)      
A **C** library with functions for common formulas used by embedded systems.  

## Characteristics

* Portable-ish: only `double` (or `float`, [depending on the compilation](https://github.com/gfurtadoalmeida/iot-lib-formulas/wiki/Choosing-the-Decimal-Type))  is not portable.
* Testable: 20+ tests.

## Integrations

* ESP-IDF: can be used as a component, with the name `iot-lib-formulas`.

## Documentation

Everything is on the [wiki](https://github.com/gfurtadoalmeida/iot-lib-formulas/wiki).

## Example

```cpp
#include "volt_divider/volt_divider.h"
#include "thermistor/thermistor.h"
#include "conversion.h"
#include <stdio.h>

void app_main(void)
{
    double resistor_1_resistance = volt_divider_resistive_calc_resistor_2(5.0, 10000.0, 2.5);

    double kelvin = thermistor_calc_temperature_steinhart_betha(COMMON_THERM_PROBE_AMBIENT_TEMP_KELVIN,
                                                                COMMON_THERM_PROBE_RESISTANCE,
                                                                COMMON_THERM_PROBE_BETHA,
                                                                resistor_1_resistance);
    double celsius = CONV_KELVIN_CELSIUS(kelvin);

    prinft("Temperature: %f", celsius);
}
```