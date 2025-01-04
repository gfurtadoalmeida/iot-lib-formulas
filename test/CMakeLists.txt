file(GLOB_RECURSE srcs "*.cpp")

enable_testing()

add_executable(test_app ${srcs})

set_target_properties(test_app PROPERTIES LINK_FLAGS /PROFILE)
set_target_properties(iot-lib-formulas PROPERTIES LINK_FLAGS /PROFILE;/DEBUG:FULL;/DEBUGTYPE:cv,fixup;/OPT:REF;/OPT:NOICF;/INCREMENTAL:NO;/FIXED:NO)

target_include_directories(test_app
  PRIVATE
  .
  ${CMAKE_SOURCE_DIR}/lib
)

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG main
)

# For Windows: Prevent overriding the parent project's compiler/linker settings.
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

target_link_libraries(test_app PRIVATE gtest)
target_link_libraries(test_app PRIVATE iot-lib-formulas)

include(GoogleTest)

gtest_discover_tests(test_app)