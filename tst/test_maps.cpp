//
// Created by Kostas Makedos on 18/07/2020.
// Email: kostas.makedos@gmail.com
// Copyright (c) 2020 All rights reserved.
//

#define BOOST_TEST_DYN_LINK
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <boost/test/unit_test.hpp>
#include "../maps.h"

BOOST_AUTO_TEST_SUITE(testMaps)


    BOOST_AUTO_TEST_CASE(TEST_MAP_STRINGS) {

        std::map<std::string, std::string> dictionary;
        dictionary["Moon"] = "Small planet, a satellite of Earth";
        dictionary["Venus"] = "Hot, medium planet, sitting after Earth from Sun";
        dictionary["Mars"] = "Hot, medium planet, previous from Earth towards Sun";
        print_map(dictionary);
    }
    BOOST_AUTO_TEST_CASE(TEST_MAP_HASH) {
        std::unordered_map<std::string, std::string> dictionary;
        dictionary["Moon"] = "Small planet, a satellite of Earth";
        dictionary["Venus"] = "Hot, medium planet, sitting after Earth from Sun";
        dictionary["Mars"] = "Hot, medium planet, previous from Earth towards Sun";
        print_hashmap(dictionary);
    }
    BOOST_AUTO_TEST_CASE(TEST_CONTAINERS) {
        std::map<std::string, std::string> mp;
        std::unordered_map<std::string, std::string> ump;
        std::set<std::string> st;
        std::unordered_set<std::string> ust;
        mp["alpha"] = "First letter in Greek alphabet";
        mp["beta"] = "Second letter in Greek alphabet";
        mp["gamma"] = "Third letter in Greek alphabet";
        mp["delta"] = "Fourth letter in Greek alphabet";
        print_map(mp);
        ump["alpha"] = "First letter in Greek alphabet";
        ump["beta"] = "Second letter in Greek alphabet";
        ump["gamma"] = "Third letter in Greek alphabet";
        ump["delta"] = "Fourth letter in Greek alphabet";
        print_hashmap(ump);
        st.insert("alpha");
        st.insert("beta");
        st.insert("gamma");
        st.insert("delta");
        st.insert("delta");
        ust.insert("delta");
        ust.insert("alpha");
        ust.insert("alpha");
        ust.insert("alpha");
        ust.insert("gamma");
        ust.insert("gamma");
        ust.insert("gamma");
        ust.insert("delta");

        print_set(st);
        print_unorderedset(ust);

    }
    BOOST_AUTO_TEST_CASE(TEST_CONTAINERS_IN_CONTAINERS) {
        SetOfString ss;
        ss.insert("Print a name");
        std::string command = "print";
        CLI cli = CLI();
        cli.add_command(command, &ss);
        command = "Sloa";

        cli.print_commands();
    }



BOOST_AUTO_TEST_SUITE_END()