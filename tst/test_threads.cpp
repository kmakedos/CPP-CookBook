//
// Created by Kostas Makedos on 18/07/2020.
// Email: kostas.makedos@gmail.com
// Copyright (c) 2020 All rights reserved.
//

#define BOOST_TEST_DYN_LINK
#include <list>
#include <boost/test/unit_test.hpp>
#include "../threads.h"

BOOST_AUTO_TEST_SUITE(testTHREADS)

    BOOST_AUTO_TEST_CASE(TEST_CREATE_THREADS){
        create_thread();
    }
    BOOST_AUTO_TEST_CASE(TEST_LOCKS){
        locker();
        PriorityQueue<std::string> pq;
        std::string s = "Sas:";
        for (int i = 0; i < 10000; i++){
            pq.enqueue(s + std::to_string(i));
        }
        for (int i = 0; i  <10000  ;i++){
            boost::thread writer(pq.dequeue());
            boost::thread reader(pq.read_front());
            writer.yield();
            reader.yield();
        }

    }

BOOST_AUTO_TEST_SUITE_END()