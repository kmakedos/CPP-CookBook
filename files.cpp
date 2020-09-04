//
// Created by kostas on 4/9/20.
//

#include "files.h"
void tabs_to_spaces(std::istream &in, std::ostream &out){
    char c;
    while (in.get(c)){
        if (c == '\t'){
            for (short i = 0; i < 4; i++)
                out.put(' ');
        }
        else {
            out.put(c);
        }
    }
}

void spaces_to_tabs(std::istream &in, std::ostream &out){
    char c;
    int num_spaces = 4;
    int counted = 0;
    while (in.get(c)){
        if ((c == ' ') && (counted == num_spaces)){
            out.put('\t');
        }
        if (c != ' '){
            if (counted > 0){
                for (int i=0; i < counted; i++) out.put(' ');
            }
            out.put(c);
            counted = 0;
        }
    }
}


void wrap_lines(std::istream &in, std::ostream &out){
    char c;
    int counter = 0;
    bool lock = false;
    while(in.get(c)){
        // We lock if we are in the middle of a word
        lock = (isspace(c) == 0);
        ++counter;
        if ((counter >= 80) && ! lock){
            out << std::endl;
            counter = 0;
        }
        out << c ;
    }

}

void count(std::istream &in){
    char c;
    int lines = 0;
    int chars = 0;
    int words = 0;
    int spaces = 0;
    int previous = 0;

    while (in.get(c)){
        if (c == '\n'){
            lines++;
        }
        spaces = (isspace(c)?1:0);
        if ((spaces == 1) && (previous == 0)){
            words++;
        }
        previous = spaces;

    }
    std::cout << "Words:" << words << std::endl;
    std::cout << "Lines:" << lines << std::endl;
}