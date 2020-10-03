//
// Created by Kostas Makedos on 18/07/2020.
// Email: kostas.makedos@gmail.com
// Copyright (c) 2020 All rights reserved.
//

#define BOOST_TEST_DYN_LINK
#include <list>
#include <iostream>
#include <thread>
#include <boost/test/unit_test.hpp>
#include "../threads.h"

BOOST_AUTO_TEST_SUITE(testTHREADS)

    BOOST_AUTO_TEST_CASE(TEST_CREATE_THREADS){
        create_thread();
    }

    BOOST_AUTO_TEST_CASE(TEST_CREATE_ONE){
        test_one();
    }

    BOOST_AUTO_TEST_CASE(TEST_MOVE_THREADS){
        std::thread moving_thread(dummy01);
        std::thread new_moving_thread(dummy02);
        std::thread yet_another(dummy03);
        std::thread t1 = std::move(moving_thread);
        std::thread t2 = std::move(new_moving_thread);
        std::thread t3 = std::move(yet_another);
        std::thread t4 = std::move(t3);
        t1.join();
        t2.join();
        t4.join();
    }

BOOST_AUTO_TEST_SUITE_END()