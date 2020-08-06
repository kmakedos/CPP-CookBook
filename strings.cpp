//
// Created by Kostas Makedos on 31/07/2020.
// Email: kostas.makedos@gmail.com
// Copyright (c) 2020 All rights reserved.
//
#include <iostream>
#include <vector>
#include "strings.h"
void splitString(std::string &s, char c, std::vector<std::string> &v){
    std::string::size_type i = 0;
    std::string::size_type j = s.find(c);
    while (j != std::string::npos){
        v.push_back(s.substr(i, j-i));
        i = ++j;
        j = s.find(c, j);
        if (j == std::string::npos){
            v.push_back(s.substr(i, s.length()));
        }
    }

}

void join_vector(std::vector<std::string> v, const char delim, std::string &s){
    s.clear();
    for (std::vector<std::string>::const_iterator i = v.begin(); i != v.end(); ++i){
        s += *i;
        if (i != v.end()-1){
            s += delim;
        }

    }
}
