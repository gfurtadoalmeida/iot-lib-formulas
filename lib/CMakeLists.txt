file(GLOB srcs "src/*.c")

add_library(${CMAKE_PROJECT_NAME} STATIC ${srcs})

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC "include")
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE "private_include")