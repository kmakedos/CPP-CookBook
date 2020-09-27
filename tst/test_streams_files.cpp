//
// Created by Kostas Makedos on 18/07/2020.
// Email: kostas.makedos@gmail.com
// Copyright (c) 2020 All rights reserved.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../streams_files.h"
#include <iomanip>


BOOST_AUTO_TEST_SUITE(testStreamsFiles)

    BOOST_AUTO_TEST_CASE(TEST_ALIGN) {
        std::ios_base::fmtflags flags =  std::cout.flags();
        std::vector<std::pair<std::string, std::string>> alpha = {
                {"User", "Password"},
                {"kostas", "alpha123"},
                {"mak", "qwerty"}
        };
        for (auto &it: alpha) {
            std::cout
            << std::left
            << std::setw(20) << it.first
            << std::setw(30) << it.second
            << std::endl;
        }
        double pi = 3.141592635;
        std::cout
        << floatme
        << pi
        << std::endl;


        std::cout.flags(flags);

    }

BOOST_AUTO_TEST_SUITE_END()