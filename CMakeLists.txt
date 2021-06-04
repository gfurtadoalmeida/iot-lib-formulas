cmake_minimum_required(VERSION 3.8)
project(iot-lib-formulas VERSION 0.1.0)

option(BUILD_TEST "Build test program" OFF)

add_subdirectory("lib")

set_target_properties (${CMAKE_PROJECT_NAME} PROPERTIES
  C_STANDARD 11
  C_STANDARD_REQUIRED TRUE
  C_EXTENSIONS FALSE
  CXX_STANDARD 11
  CXX_STANDARD_REQUIRED TRUE
  CXX_EXTENSIONS FALSE
)

if(BUILD_TEST MATCHES ON)
    add_subdirectory(test)
endif()
