//
// Created by Kostas Makedos on 18/07/2020.
// Email: kostas.makedos@gmail.com
// Copyright (c) 2020 All rights reserved.
//

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN  // in only one cpp file
#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_SUITE(Numbers)
    BOOST_AUTO_TEST_CASE(Generic){
        BOOST_CHECK_EQUAL(2+2, 4);
}
BOOST_AUTO_TEST_SUITE_END()