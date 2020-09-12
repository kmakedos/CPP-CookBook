//
// Created by kostas on 22/7/20.
//
#include <iostream>
#include "numbers.h"
class TS{
private:
    std::string p;
public:
    TS(){
        std::cout << "New tS" << std::endl;
    }
    TS(std::string &msg):p(msg){}

    void get_message(std::string &msg){
        p = msg;
    }
};

int main(){
    std::vector<TS> pp(100);
    std::cout << "pp Size: " << pp.size() << std::endl;
    std::cout << "pp capacity: " << pp.capacity() << std::endl;
    TS ss = TS();
    std::string alpha =  "Alpha";
    std::string beta = "Beta";
    ss.get_message(alpha);
    pp.push_back(ss);
    pp.emplace_back(TS(beta));
    std::cout << "pp Size: " << pp.size() << std::endl;
    std::cout << "pp capacity: " << pp.capacity() << std::endl;
}
