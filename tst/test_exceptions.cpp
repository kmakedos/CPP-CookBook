//
// Created by Kostas Makedos on 18/07/2020.
// Email: kostas.makedos@gmail.com
// Copyright (c) 2020 All rights reserved.
//

#define BOOST_TEST_DYN_LINK
#include <list>
#include <boost/test/unit_test.hpp>
#include <vector>
#include <algorithm>
#include <exception>
#include "../exceptions.h"
void f(){
    throw(MyException("Hello world except you!"));
}

BOOST_AUTO_TEST_SUITE(testExceptions)

   BOOST_AUTO_TEST_CASE(TEST_EXCEPTION_CLASS){
       try {
                f();
       }
       catch (MyException &e) {
           std::cout << e.getMessage() << std::endl;
       }

   }
    BOOST_AUTO_TEST_CASE(TEST_SAFE_CLASS){

        BOOST_CHECK_NO_THROW(Machine car = Machine(1,2));
        MachineExec c = MachineExec(-2);

    }
// In general all points where an exception may occur, should be handled first.
// Operators will never throw, and destructors should never throw
// Any other function can throw...
// To create safe copy constructors, or initiliazers you should try to just copy
// internal components using simple copy commands and swaps
// We swap non-primitive members first



BOOST_AUTO_TEST_SUITE_END()