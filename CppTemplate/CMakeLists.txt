cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 14)
project(Class01)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set (Boost_USE_STATIC_LIBS OFF)
find_package (Boost REQUIRED COMPONENTS unit_test_framework system filesystem date_time)
include_directories (${Boost_INCLUDE_DIRS})

include_directories(.)
add_executable(Class01 main.cpp Class_01.cpp)
target_link_libraries(Class01 ${Boost_LIBRARIES})
add_subdirectory(test)
