//
// Created by Kostas Makedos on 18/07/2020.
// Email: kostas.makedos@gmail.com
// Copyright (c) 2020 All rights reserved.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../strings.h"

BOOST_AUTO_TEST_SUITE(testStrings)

    BOOST_AUTO_TEST_CASE(TEST_PADSTRING) {
        std::wstring alpha = L"Alpha";
        padString(alpha, L'a', 6);
        BOOST_CHECK(alpha == L"Alphaa");
        std::wstring beta = L"Beta";
        padString(beta, L'δ', 7);
        BOOST_CHECK(beta == L"Betaδδδ");
        std::string gamma = "foo";
        padString(gamma, '.', -6);
        BOOST_CHECK(gamma == "...foo");
    }
    BOOST_AUTO_TEST_CASE(TEST_TRIMSTRING){
        std::string trim01 = "Lemonsss";
        trimString(trim01, 's');
        BOOST_CHECK(trim01 == "Lemon");

        std::wstring trim02= L"Κωστας Μακέδοςςςς.ςςς";
        trimString(trim02, L'ς');
        BOOST_CHECK(trim02 == L"Κωστας Μακέδοςςςς.");
    }
    BOOST_AUTO_TEST_CASE(TEST_STRINGSEQUENCE) {
        std::vector<std::string> str_vec;
        for (int i = 0 ;i < 100; i++){
            str_vec.push_back("TestString");
        }
        std::cout << "Vector size :"  << str_vec.size() << std::endl;
    }

    BOOST_AUTO_TEST_CASE(TEST_STRINGLENGTH) {
        std::string tst = "Solop";
        std::string::size_type init_len = tst.length();
        std::string::size_type init_cap = tst.capacity();
        tst += "123456789012345678";
        std::string::size_type final_len = tst.length();
        std::string::size_type final_cap = tst.capacity();
        BOOST_CHECK_GE(final_len, init_len);
        BOOST_CHECK_GE(final_cap, init_cap);
    }
    BOOST_AUTO_TEST_CASE(TEST_STRINGREVERSE) {
        std::string tst = "Solop";
        reverseString(tst);
        BOOST_CHECK(tst == "poloS");
        std::string tst2;
        reverseAndCopyString(tst, tst2);
        BOOST_CHECK(tst2 == "Solop");
    }

    BOOST_AUTO_TEST_CASE(TEST_SPLITSTRING) {
        std::string address = "kostas.makedos@gmail.com";
        std::vector<std::string> v;
        splitString(address, '.', v);
        BOOST_CHECK(v[0] == "kostas");
        BOOST_CHECK(v[1] == "makedos@gmail");
        BOOST_CHECK(v[2] == "com");


    }

BOOST_AUTO_TEST_SUITE_END()