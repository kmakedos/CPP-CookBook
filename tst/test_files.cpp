//
// Created by Kostas Makedos on 18/07/2020.
// Email: kostas.makedos@gmail.com
// Copyright (c) 2020 All rights reserved.
//

#define BOOST_TEST_DYN_LINK
#include <istream>
#include <ostream>
#include <fstream>
#include <boost/test/unit_test.hpp>
#include "../files.h"

BOOST_AUTO_TEST_SUITE(testFiles)


    BOOST_AUTO_TEST_CASE(TEST_TABS_TO_SPACES) {
        std::ifstream in("test_file01.txt");
        std::ofstream out("test_file01_result01.txt");
        if (!in || !out){
            exit(EXIT_FAILURE);
        }
        tabs_to_spaces(in, out);
        in.close();
        out.close();
    }
    BOOST_AUTO_TEST_CASE(TEST_SPACES_TO_TABS) {
        std::ifstream in("test_file01_result01.txt");
        std::ofstream out("test_file01_result02.txt");
        if (!in || !out){
            exit(EXIT_FAILURE);
        }
        spaces_to_tabs(in, out);
        in.close();
        out.close();
    }
    BOOST_AUTO_TEST_CASE(TEST_WRAP_FILES) {
        std::ifstream in("test_file02.txt");
        std::ofstream out("test_file02_result01.txt");
        if (!in || !out){
            exit(EXIT_FAILURE);
        }
        wrap_lines(in, out);
        in.close();
        out.close();
    }
    BOOST_AUTO_TEST_CASE(TEST_COUNT_WORDS_CHARS_LINES) {
        std::ifstream in("test_file02.txt");
        if (!in){
            exit(EXIT_FAILURE);
        }
        count(in);
        in.close();
    }

BOOST_AUTO_TEST_SUITE_END()