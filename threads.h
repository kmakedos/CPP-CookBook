//
// Created by kostas on 29/9/20.
//

#ifndef CPP_COOKBOOK_THREADS_H
#define CPP_COOKBOOK_THREADS_H
#include <vector>
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

template <typename T>
class PriorityQueue{
public:
    PriorityQueue(){}
    ~PriorityQueue(){}
    void enqueue(const T& x){
        mutex_.lock_shared();
        list_.push_back(x);
        mutex_.unlock_shared();
    }
    T dequeue(){
        mutex_.lock_shared();
        T tmp = list_.front();
        list_.pop_front();
        mutex_.unlock_shared();
        return tmp;
    }
    T read_front(){
        mutex_.try_lock_shared();
        T tmp = list_.front();
        mutex_.unlock_shared();
        return tmp;
    }

private:
    boost::shared_mutex mutex_;
    std::list<T> list_;
};

#endif //CPP_COOKBOOK_THREADS_H
