//
// Created by Kostas Makedos on 31/07/2020.
// Email: kostas.makedos@gmail.com
// Copyright (c) 2020 All rights reserved.
//

#ifndef CPP_COOKBOOK_STRINGS_H
#define CPP_COOKBOOK_STRINGS_H
#include <string>
#include <algorithm>
#include <istream>
#include <ostream>
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

template <typename T>
void reverseString(std::basic_string<T> &s){
   std::reverse(s.begin(), s.end());
}

template <typename T>
void reverseAndCopyString(std::basic_string<T> s, std::basic_string<T> &r){
    r.assign(s.rbegin(), s.rend());
}


void splitString(std::string &s, char c, std::vector<std::string> &v);

class StringTokenizer{
public:
    StringTokenizer(const std::string &s, std::string &delim):
    str_(s), count_(-1), begin_(0), end_(0){
        if (delim.empty()){
            delim_ = " \f\n\r\t\v";
        }
        else {
            delim_ = delim;
        }
        begin_ = str_.find_first_not_of(delim_);
        end_ = str_.find_first_of(delim_, begin_);
    }
    size_t countTokens(){
        if (count_ >= 0){
            return count_;
        }
        std::string::size_type n = 0;
        std::string::size_type i = 0;
        for(;;){
            if ((i = str_.find_first_not_of(delim_, i) ) == std::string::npos){
                break;
            }
            i = str_.find_first_of(delim_, i+1);
            n++;
            if (i == std::string::npos)
                break;
        }
        return (count_ = n);
    }
    bool hasMoreTokens() { return begin_ != end_ ;}
    void nextToken(std::string &s){
        if (begin_ != std::string::npos && end_ != std::string::npos){
            s = str_.substr(begin_, end_ - begin_);
            begin_ = str_.find_first_not_of(delim_, end_);
            end_ = str_.find_first_of(delim_, begin_);
        }
        else if (begin_ != std::string::npos && end_ == std::string::npos){
            s = str_.substr(begin_, str_.length() - begin_);
            begin_ = str_.find_first_not_of(delim_, end_);
        }
    }
private:
    StringTokenizer(){};
    std::string delim_;
    std::string str_;
    int count_;
    int begin_;
    int end_;
};


void join_vector(std::vector<std::string> v, const char delim, std::string &s);

template <typename T>
size_t count_words(std::basic_string<T> &s, std::basic_string<T> &delim){
    size_t count = 0;
    int begin = s.find_first_not_of(delim);
    int end = s.find_first_of(delim);
    while (end != std::basic_string<T>::npos){
        begin = s.find_first_not_of(delim, end);
        end = s.find_first_of(delim, begin);
        count++;
    }
    return count;

}


template <typename T>
void remove_string(std::basic_string<T> &s, std::basic_string<T> &t){
    int n = -1; // We put -1 here to start from 0
    while ((n = s.find(t, n+1)) > 0){
        s.erase(n, t.length());
    }

}


void to_lower(std::string &s);
void to_upper(std::string &s);

bool str_equal(std::string &lh, std::string &rh);

int str_search(std::string &needle, std::string &haystack);


#endif //CPP_COOKBOOK_STRINGS_H
