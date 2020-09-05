//
// Created by Kostas Makedos on 18/07/2020.
// Email: kostas.makedos@gmail.com
// Copyright (c) 2020 All rights reserved.
//

#define BOOST_TEST_DYN_LINK
#include <istream>
#include <ostream>
#include <fstream>
#include <map>
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
        count(in, std::cout);
        in.close();
    }
    BOOST_AUTO_TEST_CASE(TEST_COUNT_WORD_INSTANCES) {
        std::ifstream in("test_file02.txt");
        if (!in) exit(EXIT_FAILURE);
        count_words(in, std::cout);
        in.close();
    }
    BOOST_AUTO_TEST_CASE(TEST_ADD_MARGINS) {
        std::ifstream in("test_file02.txt");
        std::ofstream tmp("test_file02_corrected.txt");
        if (!in || !tmp) exit(EXIT_FAILURE);
        wrap_lines(in, tmp, 70);
        in.close();
        tmp.close();
        std::ifstream in2("test_file02_corrected.txt");
        std::ofstream out("test_file02_result03.txt");
        if (!in2 || !out) exit(EXIT_FAILURE);
        add_margins(in2, out, 10, 80);
        in2.close();
        out.close();
    }
    BOOST_AUTO_TEST_CASE(TEST_JUSTIFY) {
        std::ifstream in("test_file02.txt");
        std::ofstream tmp("test_file02_fixed_width.txt");
        if (!in || !tmp) exit(EXIT_FAILURE);
        wrap_lines(in, tmp, 40);
        in.close();
        tmp.close();
        std::ifstream in2("test_file02_fixed_width.txt");
        std::ofstream out("test_file02_result04.txt");
        if (!in2 || !out) exit(EXIT_FAILURE);
        justify(in2, out, 40, true );
        in2.close();
        out.close();
    }
    BOOST_AUTO_TEST_CASE(TEST_COMPRESS_WHITESPACE) {
        std::ifstream in("test_file02.txt");
        std::ofstream out("test_file02_result05.txt");
        if (!in || !out) exit(EXIT_FAILURE);
        compress_w(in, out);
        in.close();
        out.close();
    }
    BOOST_AUTO_TEST_CASE(TEST_AUTOCORRECT) {
        std::map<std::string, std::string> dictionary;
        dictionary["thsi"] = "this";
        dictionary["simlpe"] = "simple";
        dictionary["pelecan"] = "pelican";
        dictionary["anwser"] = "answer";
        dictionary["monney"] = "money";
        dictionary["hopse"] = "hopes";
        std::ifstream in("test_file03.txt");
        std::ofstream out("test_file03_result01.txt");
        if (!in || !out) exit(EXIT_FAILURE);
        autocorrect(in, out, dictionary);
        in.close();
        out.close();
    }
    BOOST_AUTO_TEST_CASE(TEST_READ_CSV) {
        std::ifstream in("test_file04.csv");
        std::ofstream out("test_file04_result01.txt");
        if (!in || !out) exit(EXIT_FAILURE);
        read_csv(in, out);
        in.close();
        out.close();
    }

BOOST_AUTO_TEST_SUITE_END()