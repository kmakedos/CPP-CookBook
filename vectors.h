//
// Created by kostas on 12/9/20.
//

#ifndef CPP_COOKBOOK_VECTORS_H
#define CPP_COOKBOOK_VECTORS_H
#include <iostream>
#include <vector>
template <typename T>
void print_vector(const std::vector<T> &vec){
    std::cout << "{ ";
    for (typename std::vector<T>::const_iterator p = vec.begin(); p!= vec.end(); ++p) {
        std::cout << "{ " << *p << " }";
    }
    std::cout << "}" << std::endl;
}

template <typename T>
void copy_vector_02(std::vector<T> &lh, std::vector<T> &rh){
    lh.assign(rh.begin(), rh.end());
}

class VectorClass{
    private:
        int x;
    public:
        VectorClass(int i):x(i){}
        int getX(){
            return x;
        }
    };

#endif //CPP_COOKBOOK_VECTORS_H
