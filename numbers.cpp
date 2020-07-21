//
// Created by Kostas Makedos on 18/07/2020.
// Email: kostas.makedos@gmail.com
// Copyright (c) 2020 All rights reserved.
//

#include "numbers.h"

long Numbers::hex2int(const std::string &hexStr) {
    char *offset;
    if (hexStr.length() > 2){
        if (hexStr[0] == '0' && hexStr[1] == 'x'){
            return std::strtol(hexStr.c_str(), &offset, 0);
        }
    }
    return std::strtol(hexStr.c_str(), &offset, 16);
}