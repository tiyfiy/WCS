cmake_minimum_required(VERSION 3.16)
project(mini-wcs LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -Wall enables -Wswitch: a switch over an enum class that omits an enumerator
# and has no `default:` label becomes a compiler diagnostic.
add_library(wcs_warnings INTERFACE)
target_compile_options(wcs_warnings INTERFACE -Wall -Wextra -Wpedantic)

add_library(wcs_domain src/ping.cpp)
target_include_directories(wcs_domain PUBLIC include)
target_link_libraries(wcs_domain PRIVATE wcs_warnings)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(wcs_tests
  tests/test_ping.cpp
  tests/test_ids.cpp
  tests/test_location.cpp
  tests/test_transport_unit.cpp
)
target_link_libraries(wcs_tests PRIVATE wcs_domain wcs_warnings GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(wcs_tests)
