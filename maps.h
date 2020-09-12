//
// Created by kostas on 12/9/20.
//

#ifndef CPP_COOKBOOK_MAPS_H
#define CPP_COOKBOOK_MAPS_H
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <iostream>


template <typename T, typename Y>
void print_map(std::map<T, Y> &m){
    for (auto it = m.begin(); it != m.end(); ++it){
        std::cout << (*it).first << " -> "<< (*it).second << std::endl;
    }
}
template <typename T, typename Y>
void print_hashmap(std::unordered_map<T, Y> &m){
    for (auto it = m.begin(); it != m.end(); ++it){
        std::cout << (*it).first << " -> "<< (*it).second << std::endl;
    }
}

template <typename T, typename Y>
void print_set(std::set<T, Y> &m){
    for (auto it = m.begin(); it != m.end(); ++it){
        std::cout << *it << std::endl;
    }
}
template <typename T, typename Y>
void print_unorderedset(std::unordered_set<T, Y> &m){
    for (auto it = m.begin(); it != m.end(); ++it){
        std::cout << *it << std::endl;
    }
}

typedef std::set<std::string> SetOfString;
typedef std::map<std::string, SetOfString *> MapString_SetOfString;

class CLI{
private:
    MapString_SetOfString commands;
public:
    void add_command(std::string &cmd_name, SetOfString *command){
        commands[cmd_name] = command;
    }

    void print_commands(){
        for (auto it = commands.begin(); it!=commands.end(); it++){
            std::cout << it->first << ":" << *(it->second->begin()) << std::endl;
        }
    }
};

#endif //CPP_COOKBOOK_MAPS_H
