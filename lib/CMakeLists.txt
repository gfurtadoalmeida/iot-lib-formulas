file(GLOB srcsTHERM "src/thermistor/*.c")
file(GLOB srcsVOLTDIV "src/volt_divider/*.c")

list(APPEND srcs ${srcsTHERM})
list(APPEND srcs ${srcsVOLTDIV})

add_library(iot-lib-formulas STATIC ${srcs})

target_include_directories(iot-lib-formulas PUBLIC "include")
target_include_directories(iot-lib-formulas PRIVATE "private_include")