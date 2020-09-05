//
// Created by kostas on 4/9/20.
//
#include <map>
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


void wrap_lines(std::istream &in, std::ostream &out, int width){
    char c;
    int counter = 0;
    bool lock = false;
    while(in.get(c)){
        // We lock if we are in the middle of a word
        lock = (isspace(c) == 0);
        ++counter;
        if ((counter >= width) && ! lock){
            out << std::endl;
            counter = 0;
        }
        out << c ;
    }

}

void count(std::istream &in, std::ostream &out){
    char c;
    int lines = 0;
    int chars = 0;
    int words = 0;
    int spaces = 0;
    int previous = 0;

    while (in.get(c)){
        ++chars;
        if (c == '\n'){
            lines++;
        }
        spaces = (isspace(c)?1:0);
        if ((spaces == 1) && (previous == 0)){
            words++;
        }
        previous = spaces;

    }

    out << "Words:" << words << std::endl;
    out << "Lines:" << lines << std::endl;
    out << "Chars:" << chars << std::endl;
}
void count_words(std::istream &in, std::ostream &out){
    std::map<std::string, int> StringMap;
    std::string s;
    while (in >> s){
        ++StringMap[s];
    }
    for (auto it = StringMap.begin(); it!= StringMap.end(); ++it){
        out << it->first << ":" << it->second << std::endl;
    }
}
void add_margins(std::istream &in, std::ostream &out, int left_pad, int width){
    std::string line;
    int length = 0;
    while (getline(in, line, '\n')){
       length = line.length();
       if (length <= (width - left_pad)){
           for (size_t t= 0; t < left_pad; t++) out << " ";
       }
       out << line << std::endl;
    }
}
