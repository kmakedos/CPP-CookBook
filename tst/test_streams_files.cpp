//
// Created by Kostas Makedos on 18/07/2020.
// Email: kostas.makedos@gmail.com
// Copyright (c) 2020 All rights reserved.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../streams_files.h"
#include <iomanip>
#include <iostream>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <sys/types.h>
#include <sys/stat.h>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/fstream.hpp>

BOOST_AUTO_TEST_SUITE(testStreamsFiles)

    BOOST_AUTO_TEST_CASE(TEST_ALIGN) {
        std::ios_base::fmtflags flags =  std::cout.flags();
        std::vector<std::pair<std::string, std::string>> alpha = {
                {"User", "Password"},
                {"kostas", "alpha123"},
                {"mak", "qwerty"}
        };
        for (auto &it: alpha) {
            std::cout
            << std::left
            << std::setw(20) << it.first
            << std::setw(30) << it.second
            << std::endl;
        }
        double pi = 3.141592635;
        std::cout
        << floatme
        << pi
        << std::endl;


        std::cout.flags(flags);

    }

    BOOST_AUTO_TEST_CASE(TEST_FILE_INFO) {
       struct stat fileInfo;
       if (stat("test_file04.csv", &fileInfo) !=0 ){
           if ((fileInfo.st_mode & S_IFMT) == S_IFDIR ){
                std::cout << "Directory" << std::endl;
            }
           else {
               std::cout << "File" << std::endl;
           }
       }
       std::cout << "Size: " << fileInfo.st_size << std::endl;
       std::cout << "Device: " << fileInfo.st_dev << std::endl;
       std::cout << "Created: " << std::ctime(&fileInfo.st_ctime) << std::endl;
       std::cout << "Modified: " << std::ctime(&fileInfo.st_mtime) << std::endl;
       if (remove("test_file02_copy.txt") == -1){
           std::cerr << "Error deleting file" << std::endl;
       }
    }
    BOOST_AUTO_TEST_CASE(TEST_FILE_COPY) {
       std::ifstream in("test_file02.txt", std::ios_base::in | std::ios_base::binary);
       std::ofstream out("test_file02_copy.txt", std::ios_base::out | std::ios_base::binary);
       int BUFFER_SIZE = 10;
       char buf[BUFFER_SIZE];
       do{
           in.read(&buf[0], BUFFER_SIZE);
           out.write(&buf[0], BUFFER_SIZE);
       }while (in.gcount() > 0);
       in.close();
       out.close();

       std::string in_file = "test_file03.txt";
       std::string out_file = "test_file03_copy.txt";
       if (boost::filesystem::remove(out_file) == -1){
           std::cout << "We could not delete " << out_file << std::endl;
       }
       boost::filesystem::path src = boost::filesystem::complete(boost::filesystem::path(in_file));
       boost::filesystem::path dst = boost::filesystem::complete(boost::filesystem::path(out_file));
       boost::filesystem::copy(src, dst);

    }
    BOOST_AUTO_TEST_CASE(TEST_DIRECTORY_LISTING) {
        boost::filesystem::path full_path = boost::filesystem::system_complete("/");
        if (!boost::filesystem::exists(full_path)){
            std::cerr << "We are in trouble" << std::endl;
        }
        if (boost::filesystem::is_directory(full_path)){
            std::cout << "It is a folder though" << std::endl;
        }

        boost::filesystem::directory_iterator end;
        for (boost::filesystem::directory_iterator it(full_path); it != end; ++it){
            std::cout << it->path() << std::endl;
        }
}

BOOST_AUTO_TEST_SUITE_END()