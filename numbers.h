//
// Created by Kostas Makedos on 18/07/2020.
// Email: kostas.makedos@gmail.com
// Copyright (c) 2020 All rights reserved.
//

#ifndef CPP_COOKBOOK_TEST_NUMBERS_H
#define CPP_COOKBOOK_TEST_NUMBERS_H
#include <string>
#include <boost/lexical_cast.hpp>


long hex2int(const std::string &hexStr);
std::string int2hex(const int n);

template<typename T>
bool isValid(const std::string& num){
    bool res = true;
    try{
        T tmp = boost::lexical_cast<T>(num);
    }
    catch(boost::bad_lexical_cast &e){
        res = false;
    }
    return res;
}

int compareDoubles(double alpha, double beta, double epsilon);

short cast2short(int x);

template <typename T>
void showLimits(){
    std::cout << std::numeric_limits<T>::min() << std::endl;
    std::cout << std::numeric_limits<T>::max() << std::endl;
}


#endif //CPP_COOKBOOK_TEST_NUMBERS_H
