PROJECT(CPP-Cookbook)
CMAKE_MINIMUM_REQUIRED(VERSION 3.16.5)
find_package(Boost REQUIRED COMPONENTS system)

include_directories(${Boost_INCLUDE_DIR})
# Note: a target should be already defined using 'add_executable' or 'add_library'
add_library(numbers numbers.cpp)
add_library(strings strings.cpp)
target_link_libraries(numbers ${Boost_LIBRARIES})
target_link_libraries(strings ${Boost_LIBRARIES})
add_executable(main main.cpp)
target_link_libraries(main numbers strings)
add_subdirectory(tst)
