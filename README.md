# IoT Formulas Library

![Azure DevOps builds](https://img.shields.io/azure-devops/build/gfurtadoalmeida/GitHub/43?) ![Azure DevOps tests (compact)](https://img.shields.io/azure-devops/tests/gfurtadoalmeida/GitHub/43)  
A **C** library with functions for common formulas used in the electronic field.  

## Characteristics

* Portable-ish: only "double" is not portable.
* Testable: every function has a test.
* Independent: doesn't rely on other libraries or frameworks.

## Formulas

* Thermistor:
  * Calculate [Steinhart-Hart](https://en.wikipedia.org/wiki/Steinhart%E2%80%93Hart_equation) coefficients.
  * Calculate temperature using Steinhart-Hart coefficients.
  * Calculate temperature using [Steinhart-Hart Betha](https://en.wikipedia.org/wiki/Thermistor) equation
  * Calculate resistance using inverse Steinhart-Hart Betha equation.
* Voltage Divider:
  * Resistive:
    * Calculate voltage in.
    * Calculate voltage out.
    * Calculate resistor 1 resistance.
    * Calculate resistor 2 resistance.

## Installation Instructions

1. Clone or download this repository and copy the ["lib"](/lib/) folder onto your project.
2. Include files from the ["include"](/lib/include) folder in your code.

## Project Structure

```text
/
| .vscode               : VS Code configurations
|-- lib
    |-- include         : Includes that can be used by dependent projects
    |-- private_include : Includes that only the library can use
    |-- src             : Implementation files
|-- test                : Test runner and tests
```

## Development Guidelines

* Be as portable as possible, striving to use `stdint`, `stdbool` etc.
* Avoid `malloc`.
* Create tests for every function.

## Build Requirements

* [CMake](https://cmake.org/): 3.8+
* C/C++ compiler: I'm using [MSVC](https://visualstudio.microsoft.com/vs/features/cplusplus/).
* [CppUTest](https://github.com/cpputest/cpputest): will be downloaded by CMake.

## Building

### On VS Code

1. Install [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools).
2. ```ctrl+shif+p -> CMake Build```

### Via Script

Run ```build.ps1```

## Testing

### On VS Code

1. Build it.
2. Run it: `F5`

### Via Script

1. Build it.
2. Run ```test.ps1```

## How to Use

For the time being, look at the [header files](/lib/include/), tests and the test runner 😅.  

As soon as I have time and this library stabilizes I'll write the documentation. Every function has intellisense helpers.

## To Do

* [ ] Documentation
