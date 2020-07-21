//
// Created by Kostas Makedos on 18/07/2020.
// Email: kostas.makedos@gmail.com
// Copyright (c) 2020 All rights reserved.
//

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN  // in only one cpp file
#include <boost/test/unit_test.hpp>
#include "../numbers.h"



BOOST_AUTO_TEST_SUITE(testNumbers)
    Numbers tstNums = Numbers();

    BOOST_AUTO_TEST_CASE(Generic){
        BOOST_CHECK_EQUAL(tstNums.hex2int("0x00"), 0);
        BOOST_CHECK_EQUAL(tstNums.hex2int("0x10"), 16);
        BOOST_CHECK_EQUAL(tstNums.hex2int("0xFF"), 255);
        BOOST_CHECK_EQUAL(tstNums.hex2int("0x0f"), 15);
        BOOST_CHECK_EQUAL(tstNums.hex2int("-0x0f"), -15);
        BOOST_CHECK_EQUAL(tstNums.hex2int("0f"), 15);
        BOOST_CHECK_EQUAL(tstNums.hex2int("13"), 19);
        BOOST_CHECK_EQUAL(tstNums.hex2int("-1"), -1);
        BOOST_CHECK_EQUAL(tstNums.hex2int("100"), 256);
}
BOOST_AUTO_TEST_SUITE_END()