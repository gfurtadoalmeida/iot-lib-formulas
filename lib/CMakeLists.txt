file(GLOB srcsADC "src/adc/*.c")
file(GLOB srcsTHERM "src/thermistor/*.c")
file(GLOB srcsVOLTDIV "src/volt_divider/*.c")

list(APPEND srcs ${srcsADC})
list(APPEND srcs ${srcsTHERM})
list(APPEND srcs ${srcsVOLTDIV})

add_library(${CMAKE_PROJECT_NAME} STATIC ${srcs})

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC "include")
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE "private_include")