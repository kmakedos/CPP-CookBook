//
// Created by Kostas Makedos on 31/07/2020.
// Email: kostas.makedos@gmail.com
// Copyright (c) 2020 All rights reserved.
//

#ifndef CPP_COOKBOOK_STRINGS_H
#define CPP_COOKBOOK_STRINGS_H
#include <string>
template <typename T>
void padString(std::basic_string<T> &str,
               T pad, int size){
    if (abs(size) > str.length()) {
        if (size < 0){
            size = - size;
            str.insert(str.begin(), size - str.length(), pad);
        }
        else{
            str.append(size - str.length(), pad);
        }
    }
}

template <typename T>
void trimString(std::basic_string<T> &str, T c){
    if (str.empty()){
        return;
    }
    typename std::basic_string<T>::iterator p;
    for (p = str.end(); p != str.begin() && *--p == c;);
    if (*p != c)
        p++;
    str.erase(p, str.end());
}

#endif //CPP_COOKBOOK_STRINGS_H
