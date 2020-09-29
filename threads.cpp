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


