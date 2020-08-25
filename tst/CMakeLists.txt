set (Boost_USE_STATIC_LIBS OFF)
find_package (Boost REQUIRED COMPONENTS unit_test_framework)
include_directories (${Boost_INCLUDE_DIRS})

add_executable (tests_run test_numbers.cpp test_strings.cpp test_files.cpp)
target_link_libraries (tests_run ${Boost_LIBRARIES} numbers strings)
file(COPY test_file01.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
