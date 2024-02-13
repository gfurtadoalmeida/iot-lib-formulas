# Contributing

* Branch from the head of the default branch.
* Avoid ```malloc```.
* Use portable types:
  * ```stdbool.h```: [bool](https://en.wikipedia.org/wiki/C_data_types#Boolean_type).
  * ```stdint.h```: [fixed-width integer](https://en.wikipedia.org/wiki/C_data_types#stdint.h).
  * ```stddef.h```: [pointers and sizes](https://en.wikipedia.org/wiki/C_data_types#Size_and_pointer_difference_types).
* Do not hide pointers behind typedefs.
* Create tests for every new functionality.

## Requirements

* [MSVC C++ compiler](https://visualstudio.microsoft.com/vs/features/cplusplus/)
* [CMake](https://cmake.org/)
* [Ninja](https://github.com/ninja-build/ninja)

## Building

### On VS Code

For a better experience it's highly recommended to install the [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools) extension.

```ctrl+shif+p -> CMake Build```

### With the Provided Script

Run the ```project.ps1 generate``` then ```project.ps1 build``` commands on the root folder.

## Testing

### On VS Code

1. Build the project.
2. Run the project.

### With the Provided Script

All commands must be run on the test runner folder.  
Change the COM port to the one you're using.  

1. Build the project.
2. Run the ```project.ps1 test``` commands.
