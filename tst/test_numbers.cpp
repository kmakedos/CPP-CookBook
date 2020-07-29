//
// Created by Kostas Makedos on 18/07/2020.
// Email: kostas.makedos@gmail.com
// Copyright (c) 2020 All rights reserved.
//

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN  // in only one cpp file
#include <boost/test/unit_test.hpp>
#include <boost/cast.hpp>
#include "../numbers.h"


BOOST_AUTO_TEST_SUITE(testNumbers)

    BOOST_AUTO_TEST_CASE(TEST_HEX2INTEGER){
        BOOST_CHECK_EQUAL(hex2int("0x00"), 0);
        BOOST_CHECK_EQUAL(hex2int("0x10"), 16);
        BOOST_CHECK_EQUAL(hex2int("0xFF"), 255);
        BOOST_CHECK_EQUAL(hex2int("0x0f"), 15);
        BOOST_CHECK_EQUAL(hex2int("-0x0f"), -15);
        BOOST_CHECK_EQUAL(hex2int("0f"), 15);
        BOOST_CHECK_EQUAL(hex2int("13"), 19);
        BOOST_CHECK_EQUAL(hex2int("-1"), -1);
        BOOST_CHECK_EQUAL(hex2int("100"), 256);
    }
    BOOST_AUTO_TEST_CASE(TEST_INTEGER2HEX){
        BOOST_CHECK_EQUAL(int2hex(0), "0");
        BOOST_CHECK_EQUAL(int2hex(-1), "0xffffffff");
        BOOST_CHECK_EQUAL(int2hex(240), "0xf0");
        BOOST_CHECK_EQUAL(int2hex(2), "0x2");
        BOOST_CHECK_EQUAL(int2hex(200), "0xc8");
        BOOST_CHECK_EQUAL(int2hex(39284), "0x9974");
        BOOST_CHECK_EQUAL(int2hex(-111), "0xffffff91");
    }
    BOOST_AUTO_TEST_CASE(TEST_STRING2NUM){
        BOOST_CHECK_EQUAL(isValid<int>("0"), true);
        BOOST_CHECK_EQUAL(isValid<int>("-1"), true);
        BOOST_CHECK_EQUAL(isValid<int>("- 0"), false);
        BOOST_CHECK_EQUAL(isValid<int>("+23"), true);
        BOOST_CHECK_EQUAL(isValid<float>("-0.44"), true);
        BOOST_CHECK_EQUAL(isValid<float>("+0. 44"), false);
        BOOST_CHECK_EQUAL(isValid<float>("0.44+"), false);
    }

    BOOST_AUTO_TEST_CASE(TEST_BOUNDEDFLOATS){
        BOOST_CHECK_EQUAL(0, compareDoubles(0.000001, 0.000000999999, 0.1));
        BOOST_CHECK_EQUAL(0, compareDoubles(0.1, 0.1, 0.1));
        BOOST_CHECK_EQUAL(0, compareDoubles(0.0, 0.0, 0.1));
        BOOST_CHECK_EQUAL(-1, compareDoubles(0.000001, 0.000009, 0.000001));
        BOOST_CHECK_EQUAL(-1, compareDoubles(0.000001, 0.999999, 0.1));
        BOOST_CHECK_EQUAL(1, compareDoubles(1, 0.9, 0.01));
}
    BOOST_AUTO_TEST_CASE(TEST_CAST2SHORT){
        BOOST_CHECK_EQUAL(100, cast2short(100));
        BOOST_CHECK_EQUAL(-10003, cast2short(-10003));
        BOOST_CHECK_THROW(cast2short(32320948329), boost::bad_numeric_cast);
        BOOST_CHECK_THROW(cast2short(-99222384394), boost::bad_numeric_cast);
    }
    BOOST_AUTO_TEST_CASE(TEST_SHOWLIMITS){
        BOOST_CHECK_NO_THROW(showLimits<int>());
    }
BOOST_AUTO_TEST_SUITE_END()