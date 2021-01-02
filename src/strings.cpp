//
// Created by Kostas Makedos on 31/07/2020.
// Email: kostas.makedos@gmail.com
// Copyright (c) 2020 All rights reserved.
//
#include <iostream>
#include <vector>
#include <cctype>
#include <istream>
#include <ostream>
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

void to_lower(std::string &s){
    for (std::string::iterator p = s.begin(); p != s.end(); ++p){
        *p = tolower(*p);
    }
}
void to_upper(std::string &s){
    for (std::string::iterator p = s.begin(); p != s.end(); ++p){
        *p = toupper(*p);
    }
}

bool str_equal(std::string &lh, std::string &rh){
    std::string lh_copy = lh;
    std::string rh_copy =rh;
    to_lower(lh_copy);
    to_lower(rh_copy);
    return lh_copy == rh_copy;
}

int str_search(std::string &needle, std::string &haystack){
    int index = 0;
    if ((needle.length() > haystack.length()) || needle.length() == 0 || haystack.length() == 0){
        return -1;
    }
    std::string::iterator n = needle.begin();
    for (std::string::iterator h = haystack.begin(); h!= haystack.end(); ++h) {
        ++index;
        while ((*n == *h) && (n != needle.end())) {
            ++n;
            ++h;
        }
        if (n == needle.end()) {
            return index;
        }
        else
            n = needle.begin();
    }
    return -1;

}


