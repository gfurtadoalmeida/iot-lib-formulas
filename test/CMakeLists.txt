file(GLOB srcs "tests/*.cpp")

list(APPEND srcs "test_runner.cpp")

add_executable(test_app ${srcs})

include(FetchContent)

FetchContent_Declare(
    CppUTest
    GIT_REPOSITORY https://github.com/cpputest/cpputest.git
    GIT_TAG        latest-passing-build
)

set(TESTS OFF CACHE BOOL "Switch off CppUTest Self-Test build")

FetchContent_MakeAvailable(CppUTest)

target_include_directories(test_app PRIVATE "../lib/include")
target_include_directories(test_app PRIVATE "../lib/private_include")

target_link_libraries(test_app PRIVATE iot-lib-formulas)
target_link_libraries(test_app PRIVATE CppUTest CppUTestExt)