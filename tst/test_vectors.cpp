//
// Created by Kostas Makedos on 18/07/2020.
// Email: kostas.makedos@gmail.com
// Copyright (c) 2020 All rights reserved.
//

#define BOOST_TEST_DYN_LINK
#include <list>
#include <boost/test/unit_test.hpp>
#include "../vectors.h"

BOOST_AUTO_TEST_SUITE(testVectors)

    BOOST_AUTO_TEST_CASE(TEST_COPY_VECTOR) {
        std::vector<int> x = {1,2,3};
        std::vector<int> y2;
        std::vector<int> y1(x);
        copy_vector_02(y2, x);
        BOOST_CHECK(x == y1);
        BOOST_CHECK(x == y2);
   }
    BOOST_AUTO_TEST_CASE(TEST_VECTOR_POINTER) {
        std::vector<VectorClass*> p;
        VectorClass* vc = NULL;
        for (int i = 0; i < 10; i++){
            vc = new VectorClass(i);
            p.push_back(vc);
        }
        for (std::vector<VectorClass*>::iterator it = p.begin(); it != p.end(); it++){
            std::cout << (*it)->getX();
        }

        for (std::vector<VectorClass*>::iterator it = p.begin(); it != p.end(); it++){
            delete *it;
        }
        p.clear();
    }
    BOOST_AUTO_TEST_CASE(TEST_LIST) {
       std::list<std::string> a,b;
       a.push_back("alpha");
       a.push_back("beta");
       a.push_back("gamma");
       a.push_front("delta");
       b.push_back("theta");
       b.push_front("zeta");
       a.merge(b);
       print_list(a);
       std::cout << std::endl;
       a.sort();
       print_list(a);


    }
BOOST_AUTO_TEST_SUITE_END()