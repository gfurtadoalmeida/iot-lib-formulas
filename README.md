# IoT Formulas Library

![GitHub Build Status](https://github.com/gfurtadoalmeida/iot-lib-formulas/actions/workflows/build.yml/badge.svg) [![Bugs](https://sonarcloud.io/api/project_badges/measure?project=iot_lib_formulas&metric=bugs)](https://sonarcloud.io/summary/new_code?id=iot_lib_formulas) [![Code Smells](https://sonarcloud.io/api/project_badges/measure?project=iot_lib_formulas&metric=code_smells)](https://sonarcloud.io/summary/new_code?id=iot_lib_formulas) [![Maintainability Rating](https://sonarcloud.io/api/project_badges/measure?project=iot_lib_formulas&metric=sqale_rating)](https://sonarcloud.io/summary/new_code?id=iot_lib_formulas) [![Security Rating](https://sonarcloud.io/api/project_badges/measure?project=iot_lib_formulas&metric=security_rating)](https://sonarcloud.io/summary/new_code?id=iot_lib_formulas)      
A **C** library with functions for common formulas used by embedded systems.  

## Characteristics

* Portable-ish: only `double` (or `float`, [depending on the compilation](https://github.com/gfurtadoalmeida/iot-lib-formulas/wiki/Choosing-the-Decimal-Type))  is not portable.
* Testable: 20+ tests.
* Independent: doesn't rely on other libraries or frameworks.

## Integrations

* ESP-IDF: can be used as a component, with the name `iot-lib-formulas`.

## Documentation

Everything is on the [wiki](https://github.com/gfurtadoalmeida/iot-lib-formulas/wiki).
