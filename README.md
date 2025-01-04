# IoT Formulas Library

[![GitHub Release Status][git-bagdge-release]][git-release] [![Bugs][sonar-badge-bugs]][sonar-home] [![Code Smells][sonar-badge-smells]][sonar-home] [![Security Rating][sonar-badge-security]][sonar-home] [![Coverage][sonar-badge-coverage]][sonar-home] [![Quality Gate Status][sonar-badge-quality]][sonar-home]  

A **C** library with functions for common formulas used on embedded systems.  

Characteristics:

* Portable-ish: only `double` and `float` [depending on the compilation](docs/wiki/how_to_use.md), are not portable.
* Testable: 20+ tests.
* [ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/) support:
  * Component name: `iot-lib-formulas`.
  * Configurable: using [menuconfig](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/kconfig.html).

Functions:

* [ADC](/docs/wiki/headers/adc.md)
* [Temperature](/docs/wiki/headers/temperature.md)
* [Thermistor](/docs/wiki/headers/thermistor.md)
* [Voltage Divider](/docs/wiki/headers/voltage_divider.md)

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

## Getting Started

### Requirements

* [CMake](https://cmake.org/)
* [Ninja](https://github.com/ninja-build/ninja)
* [Visual Studio][vs-site] with [C++ Tools][vs-cpp]

### Installation

```sh
git clone https://github.com/gfurtadoalmeida/iot-lib-formulas.git
```

## Building

1. Generate the build files:

    ```sh
    project.ps1 generate
    ```

2. Build:

    ```sh
    project.ps1 build
    ```

## Testing

```sh
project.ps1 test
```

## Contributing

To contribute to this project make sure to read our [CONTRIBUTING.md](/docs/CONTRIBUTING.md) file.

[git-bagdge-release]: https://github.com/gfurtadoalmeida/iot-lib-formulas/actions/workflows/release.yml/badge.svg
[git-release]: https://github.com/gfurtadoalmeida/iot-lib-formulas/releases
[sonar-badge-bugs]: https://sonarcloud.io/api/project_badges/measure?project=iot_lib_formulas&metric=bugs
[sonar-badge-coverage]: https://sonarcloud.io/api/project_badges/measure?project=iot_lib_formulas&metric=coverage
[sonar-badge-quality]: https://sonarcloud.io/api/project_badges/measure?project=iot_lib_formulas&metric=alert_status
[sonar-badge-security]: https://sonarcloud.io/api/project_badges/measure?project=iot_lib_formulas&metric=security_rating
[sonar-badge-smells]: https://sonarcloud.io/api/project_badges/measure?project=iot_lib_formulas&metric=code_smells
[sonar-home]: https://sonarcloud.io/project/overview?id=iot_lib_formulas
[vs-cpp]: https://visualstudio.microsoft.com/vs/features/cplusplus/
[vs-site]: https://visualstudio.microsoft.com/
