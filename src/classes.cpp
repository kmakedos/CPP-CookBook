//
// Created by kostas on 21/9/20.
//
#include <iostream>
#include "classes.h"

// IMPORTANT!!
// Static members are declared in .h but defined in .cpp files
// Otherwise they do not work
std::list<Contained*> Contained::classes;
int Contained::x = 0;

Contained::Contained(){}
Contained::Contained(std::string filename):filename(filename){
        classes.push_back(this);
        x++;
}
Contained::~Contained(){
    auto it = std::find(classes.begin(), classes.end(), this);
    if (it != classes.end()){
        classes.erase(it);
        x--;
    }
}
void Contained::print(){
    for (auto it:classes){
        std::cout << "Value: " << it->filename << std::endl;
    }
    std::cout << "X:" << x << std::endl;
}

Single::Single() {}
Single* Single::current  = NULL;
Single* Single::getInstance() {
    if (current == NULL){
        current = new Single();
    }
    return current;
}