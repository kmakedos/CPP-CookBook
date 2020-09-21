//
// Created by kostas on 21/9/20.
//

#ifndef CPP_COOKBOOK_CLASSES_H
#define CPP_COOKBOOK_CLASSES_H
#include <iostream>
#include <list>
#include <algorithm>
class Session{};
class SessionFactory{
private:
public:
    Session Create(){
        Session s;
        return s;
    }
    Session* CreatePtr(){
        return new Session();
    }
    void Create(Session* &p){
        p = new Session();
    }
};

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


class Animal{
public:
    virtual void walk() const = 0;
    virtual void talk() const = 0;
};

class Dog: public Animal{
public:
    void walk() const{
        std::cout << "Dog walk" << std::endl;
    }

    void talk() const{
        std::cout << voice << std::endl;
    }
private:
    std::string voice = "Woof";
};

class Cat: public Animal{
public:
    void walk() const{
        std::cout << "Cat walk" << std::endl;
    }

    void talk() const{
        std::cout << voice << std::endl;
    }
private:
    std::string voice = "Meow";
};

template <typename T>
class GenericFactory{
public:
    T create(){
        T t;
        return t;
    }
    T* createPtr(){
        return new T;
    }

    void create(T& t){
        t = new T();
    }
};


class Integar{
private:
    int x;
public:
    Integar():x(0){}
    Integar(int x):x(x){}
    Integar& operator++(){
        x++;
        return *this;
    }
    const Integar operator++(int){
        Integar tmp(*this);
        ++(*this);
        return tmp;
    }
    friend std::ostream& operator<<(std::ostream& out, const Integar& t){
        out << t.x;
        return out;
    }

    friend const Integar operator+(const Integar& lhs, const Integar& rhs){
        Integar tmp(lhs.x + rhs.x);
        return tmp;
    }
};

#endif //CPP_COOKBOOK_CLASSES_H
