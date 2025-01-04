file(GLOB_RECURSE srcs "src/*.c")

add_library(iot-lib-formulas STATIC ${srcs})

target_include_directories(iot-lib-formulas PUBLIC "include")
target_include_directories(iot-lib-formulas PRIVATE "private_include")
