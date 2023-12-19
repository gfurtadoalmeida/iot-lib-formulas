# Contributing

* Branch from the head of the default branch.
* Avoid ```malloc```.
* Use portable types:
  * ```stdbool.h```: [bool](https://en.wikipedia.org/wiki/C_data_types#Boolean_type).
  * ```stdint.h```: [fixed-width integer](https://en.wikipedia.org/wiki/C_data_types#stdint.h).
  * ```stddef.h```: [pointers and sizes](https://en.wikipedia.org/wiki/C_data_types#Size_and_pointer_difference_types).
* Do not hide pointers behind typedefs.
* Create tests for every new functionality or fix.