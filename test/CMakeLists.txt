file(GLOB srcsTstADC "adc/*.cpp")
file(GLOB srcsTstTHERM "thermistor/*.cpp")
file(GLOB srcsTstVOLTDIV "volt_divider/*.cpp")

list(APPEND srcsTst "test_runner.cpp")
list(APPEND srcsTst "conversion_test.cpp")
list(APPEND srcsTst ${srcsTstADC})
list(APPEND srcsTst ${srcsTstTHERM})
list(APPEND srcsTst ${srcsTstVOLTDIV})

add_executable(test_app ${srcsTst})

include(FetchContent)

FetchContent_Declare(
    CppUTest
    GIT_REPOSITORY https://github.com/cpputest/cpputest.git
    GIT_TAG        latest-passing-build
)

set(TESTS OFF CACHE BOOL "Switch off CppUTest Self-Test build")

FetchContent_MakeAvailable(CppUTest)

target_include_directories(test_app PUBLIC ".")
target_include_directories(test_app PUBLIC "../lib/include")
target_include_directories(test_app PRIVATE "../lib/private_include")

target_link_libraries(test_app PRIVATE iot-lib-formulas)
target_link_libraries(test_app PRIVATE CppUTest CppUTestExt)
