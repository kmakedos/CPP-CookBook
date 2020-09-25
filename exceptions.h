//
// Created by kostas on 23/9/20.
//

#ifndef CPP_COOKBOOK_EXCEPTIONS_H
#define CPP_COOKBOOK_EXCEPTIONS_H
#include <iostream>
#include <utility>
#include <stdexcept>

class MyException{
public:
    explicit MyException(std::string msg):Message(std::move(msg)){}
    ~MyException()= default;
    std::string getMessage()const {
        return Message;
    }
private:
    std::string Message;
};

class SafeDevice{
public:
    SafeDevice(int no){
        if (no==2){
            throw std::runtime_error("Problem in 2");
        }
    }
    ~SafeDevice(){}
};

class Machine{

public:
    Machine(int devno1, int devno2):dev1(NULL), dev2(NULL){
        try{
            dev1 = new SafeDevice(devno1);
            dev2 = new SafeDevice(devno2);
        }
        catch (std::runtime_error &e) {
            std::cerr << "Error: " << e.what() << std::endl;

        }

    }

private:
    SafeDevice* dev1;
    SafeDevice* dev2;
};

#endif //CPP_COOKBOOK_EXCEPTIONS_H
