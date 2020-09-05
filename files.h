//
// Created by kostas on 4/9/20.
//
#include <iostream>
#ifndef CPP_COOKBOOK_FILES_H
#define CPP_COOKBOOK_FILES_H
void tabs_to_spaces(std::istream &in, std::ostream &out);

void spaces_to_tabs(std::istream &in, std::ostream &out);

void wrap_lines(std::istream &in, std::ostream &out, int width=80);


void count(std::istream &in, std::ostream &out);
void count_words(std::istream &in, std::ostream &out);
void add_margins(std::istream &in, std::ostream &out, int left_pad, int width);


#endif //CPP_COOKBOOK_FILES_H
