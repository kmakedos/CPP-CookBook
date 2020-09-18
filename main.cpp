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


class C{
private:
    int active;
public:
    C(int activate):active(activate){}
    int is_idle(){
        return active;
    }
};



struct IdleConn :
public std::unary_function<class C, bool>{
    IdleConn(){}
    bool operator()(C &c){
       if (c.is_idle() == 0) {
           return true;
       }
       else {
           return false;
       }
    }
}idle;

struct MyFunct{
private:
    int internal;
public:
    MyFunct(int x): internal(x){}
    int operator()(int x) const {
        return internal + x;

    }
};


int main(){
/*    std::vector<TS> pp(100);
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
    std::vector<std::string> x;
    std::vector<int> int_vec;
    int_vec.push_back(3);
    int_vec.push_back(4);
    int_vec.push_back(5);
    int_vec.push_back(1);

    std::vector<int> out_vec(int_vec.size());
    MyFunct operate(5);
    std::transform(int_vec.begin(), int_vec.end(), out_vec.begin(), MyFunct(10));
    for (int & it : out_vec){
        std::cout << it << std::endl;
    }*/
/*    std::vector<C> connections;
    connections.emplace_back(C(1));
    connections.emplace_back(C(2));
    connections.emplace_back(C(0));
    connections.emplace_back(C(4));
    connections.emplace_back(C(5));
    connections.emplace_back(C(0));
    connections.emplace_back(C(7));
    connections.erase(std::remove_if(connections.begin(), connections.end(), idle), connections.end());
    for (auto & connection : connections){
        std::cout << connection.is_idle() << std::endl;
    }
*/
    std::cout << "Enter a series of strings:" ;
    std::istream_iterator<std::string> start(std::cin);
    std::istream_iterator<std::string> end;
    std::vector<std::string> v(start, end);
   /* std::vector<std::string>::iterator p =
            std::partition(v.begin(), v.end(),
                           std::bind2nd(std::less<std::string>(), "kol"));*/
    for (auto it = v.begin(); it!= v.end(); ++it ){
        std::cout << *it << std::endl;
    }

}
