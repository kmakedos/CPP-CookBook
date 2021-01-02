//
// Created by kostas on 29/9/20.
//

#ifndef CPP_COOKBOOK_THREADS_H
#define CPP_COOKBOOK_THREADS_H
#include <vector>
#include <thread>
#include <iostream>
#include <numeric>
#include <ctime>
#include <chrono>
#include <boost/thread/thread.hpp>
#include <boost/thread/shared_mutex.hpp>

struct VoidFunc{
public:
    std::vector<int> stack;
    void operator()(){
        for (int i=0; i<5000; i++){
            for(int j=0; j<10000; j++){
                stack.push_back(j+i);
            }
        }
        int sum = std::accumulate(stack.begin(), stack.end(), 0);
        std::cout << "Sum:" << sum << std::endl;
    }
};

void create_thread();


template <typename T>
class Queue{
public:
    Queue(){}
    ~Queue(){}
    void enqueue(const T& x){
        boost::mutex::scoped_lock lock(mutex_);
        list_.push_back(x);
    }

    T dequeue(){
        boost::mutex::scoped_lock lock(mutex_);
        if (list_.empty()){
            throw std::runtime_error("Empty list");
        }
        T tmp = list_.front();
        list_.pop_front();
        return tmp;
    }
private:
    std::list<T> list_;
    boost::mutex mutex_;
};


void locker();


class Generic{
private:
    std::string _msg;
public:
    Generic():_msg("Empty"){}
    void print(std::string &msg){
        std::cout << msg << std::endl;
    }

    Generic(Generic &)=delete;
    Generic& operator=(Generic&)=delete;
};
void test_one();

void dummy01();
void dummy02();
void dummy03();


#endif //CPP_COOKBOOK_THREADS_H
