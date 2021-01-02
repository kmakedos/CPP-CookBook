set (Boost_USE_STATIC_LIBS OFF)
find_package (Boost REQUIRED COMPONENTS unit_test_framework system filesystem)
include_directories (${Boost_INCLUDE_DIRS})

add_executable (tests_run test_numbers.cpp test_strings.cpp test_files.cpp
        test_vectors.cpp test_maps.cpp test_classes.cpp test_exceptions.cpp
        test_streams_files.cpp test_threads.cpp test_dates.cpp)
target_link_libraries (tests_run ${Boost_LIBRARIES} numbers strings files vectors maps
        classes exceptions streams_files threads dates)
file(COPY test_file01.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY test_file02.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY test_file03.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY test_file04.csv DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
