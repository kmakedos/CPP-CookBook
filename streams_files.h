//
// Created by kostas on 27/9/20.
//

#ifndef CPP_COOKBOOK_STREAMS_FILES_H
#define CPP_COOKBOOK_STREAMS_FILES_H
#include <iomanip>
#include <iostream>
// Does not work :(
inline std::ios_base& floatme(std::ios_base& io){
    io.setf(std::ios_base::floatfield);
    return(io);
}
#endif //CPP_COOKBOOK_STREAMS_FILES_H
