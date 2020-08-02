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

BOOST_AUTO_TEST_SUITE_END()