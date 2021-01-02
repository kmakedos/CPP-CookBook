cmake_minimum_required(VERSION 3.13)
project(Tests)

set (Boost_USE_STATIC_LIBS OFF)
find_package (Boost REQUIRED COMPONENTS unit_test_framework system filesystem date_time)
include_directories (${Boost_INCLUDE_DIRS})


add_subdirectory(libs/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ..)
add_executable(Tests_run Class01Test.cpp ../Class_01.cpp)
target_link_libraries(Tests_run gtest gtest_main)
target_link_libraries(Tests_run ${Boost_LIBRARIES})
