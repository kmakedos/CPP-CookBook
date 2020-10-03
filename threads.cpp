//
// Created by kostas on 29/9/20.
//

#include "threads.h"
void create_thread(){
    VoidFunc voidFunc;
    auto start = std::chrono::system_clock::now();
    boost::thread myThread(voidFunc);
    myThread.yield();
    myThread.join();
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_secs = end-start;
    std::cout << "Elapsed time: " << elapsed_secs.count() << "\n";
}

void locker(){
    Queue<std::string> queueStrings;
    std::string s;
    std::vector<std::string> vstr = {"alpha", "beta", "delta"};
    for (auto &it: vstr){
        queueStrings.enqueue(it);
    }
    try {
        for (int i=0; i<4; i++){
            std::cout << queueStrings.dequeue() << std::endl;
        }
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
void hello(){
    std::cout << "Hello concurrent world\n";
}

void hello_msg(std::string msg){
    std::cout << msg << std::endl;
}

void test_one(){
    std::thread t1(hello);
    t1.join();
    std::thread t2(hello_msg, "Hello detached");
    t2.detach();
    Generic g1;
    std::string s = "Passing data";
    std::thread t3(&Generic::print, &g1, std::ref(s));
    t3.join();

}
void dummy01(){
    std::cout << "Dummy01" << std::endl;
}
void dummy02(){
    std::cout << "Dummy02" << std::endl;
}
void dummy03(){
    std::cout << "Dummy03" << std::endl;
}

