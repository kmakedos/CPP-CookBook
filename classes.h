//
// Created by kostas on 21/9/20.
//

#ifndef CPP_COOKBOOK_CLASSES_H
#define CPP_COOKBOOK_CLASSES_H
#include <iostream>
#include <list>
#include <algorithm>

class Contained{
protected:
    std::string filename;
    static std::list<Contained*> classes;
    static int x;
public:
    Contained();
    Contained(std::string filename);
    ~Contained();
    void print();
};


class Single{
private:
    static Single* current;
    Single();
    Single(const Single &);
    Single& operator=(const Single &);
public:
    static Single* getInstance();

};

#endif //CPP_COOKBOOK_CLASSES_H
