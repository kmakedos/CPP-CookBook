//
// Created by Kostas Makedos on 18/07/2020.
// Email: kostas.makedos@gmail.com
// Copyright (c) 2020 All rights reserved.
//
#include <iostream>
#include <limits>
#include <boost/cast.hpp>
#include "numbers.h"

long hex2int(const std::string &hexStr) {
    char *offset;
    if (hexStr.length() > 2){
        if (hexStr[0] == '0' && hexStr[1] == 'x'){
            return std::strtol(hexStr.c_str(), &offset, 0);
        }
    }
    return std::strtol(hexStr.c_str(), &offset, 16);
}

std::string int2hex(const int n) {
    std::stringstream s;
    s << std::showbase << std::hex << n;
    return s.str();
}

int compareDoubles(double alpha, double beta, double epsilon){
    double diff = alpha-beta;
    double absdiff = fabs(diff);
    if (absdiff < epsilon || absdiff == 0.0){
        return 0;
    } else {
        return (diff/absdiff);
    }
}

short cast2short(int x){
    return boost::numeric_cast<short>(x);
}

