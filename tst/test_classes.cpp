//
// Created by Kostas Makedos on 18/07/2020.
// Email: kostas.makedos@gmail.com
// Copyright (c) 2020 All rights reserved.
//

#define BOOST_TEST_DYN_LINK
#include <list>
#include <boost/test/unit_test.hpp>
#include <vector>
#include <algorithm>
#include <exception>
#include "../classes.h"

BOOST_AUTO_TEST_SUITE(testClasses)

    BOOST_AUTO_TEST_CASE(TEST_FACTORY_PATTERN){

        SessionFactory sf;
        Session ms = sf.Create();
        Session *ns = sf.CreatePtr();
        Session *gs;
        sf.Create(gs);

        BOOST_CHECK_NO_THROW(dynamic_cast<Session*>(&ms));
        BOOST_CHECK_NO_THROW(dynamic_cast<Session*>(gs));
        BOOST_CHECK_NO_THROW(dynamic_cast<Session*>(ns));
        //Could also use typeid
    }
    BOOST_AUTO_TEST_CASE(TEST_RAII){
        class Filer{
        private:
            std::string filename;
        public:
            Filer(std::string filename):filename(filename){
                std::cout << "Opening: "  << filename << std::endl;
            }
            ~Filer(){
                std::cout << "Closing: " << filename << std::endl;
            }
        };
        Filer f1 = Filer("Alpha1");
        Filer f2 = Filer("Beta2");
    }
    BOOST_AUTO_TEST_CASE(TEST_ADD_CLASSES_TO_CONTAINERS){

        {
            Contained c1("Class 1");
            c1.print();
        }
        {
            Contained c1("Class 1");
            Contained c2("Class 2");
            Contained c3("Class 3");
            c1.print();
        }

    }
    BOOST_AUTO_TEST_CASE(TEST_SINGLETON){
        Single *s1 = Single::getInstance();
        Single *s2 = Single::getInstance();
        BOOST_CHECK(s1==s2);
        Single *s3(s2);
        BOOST_CHECK(s3==s2);
    }

    BOOST_AUTO_TEST_CASE(TEST_VIRTUAL){
        std::vector<Animal*> animals;
        animals.emplace_back(new Dog());
        animals.emplace_back(new Cat());
        for (auto &it: animals){
           it->walk();
           it->talk();
        }
    }

    BOOST_AUTO_TEST_CASE(TEST_TEMPLATED_FACTORY){
        GenericFactory<Dog> gfd;
        GenericFactory<Cat> gfc;
        std::vector<Animal*> animals;
        for (int i = 0; i < 3; i++ ){
            animals.emplace_back(gfd.createPtr());
            animals.emplace_back(gfc.createPtr());
        }
        for (auto it:animals){
            it->walk();
            it->talk();
        }

    }

    BOOST_AUTO_TEST_CASE(TEST_OPERATORS_POST_PRE_FIX){
    // Simulating pre and postfix
        Integar i, j;
        std::cout << ++i << std::endl;
        std::cout << i++ << std::endl;
        std::cout << i << std::endl;
        std::cout << i+j << std::endl;

    }
BOOST_AUTO_TEST_SUITE_END()