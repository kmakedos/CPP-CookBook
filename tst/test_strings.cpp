//
// Created by Kostas Makedos on 18/07/2020.
// Email: kostas.makedos@gmail.com
// Copyright (c) 2020 All rights reserved.
//

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../strings.h"

BOOST_AUTO_TEST_SUITE(testStrings)

    BOOST_AUTO_TEST_CASE(TEST_PADSTRING) {
        std::wstring alpha = L"Alpha";
        padString(alpha, L'a', 6);
        BOOST_CHECK(alpha == L"Alphaa");
        std::wstring beta = L"Beta";
        padString(beta, L'δ', 7);
        BOOST_CHECK(beta == L"Betaδδδ");
        std::string gamma = "foo";
        padString(gamma, '.', -6);
        BOOST_CHECK(gamma == "...foo");
    }
    BOOST_AUTO_TEST_CASE(TEST_TRIMSTRING){
        std::string trim01 = "Lemonsss";
        trimString(trim01, 's');
        BOOST_CHECK(trim01 == "Lemon");

        std::wstring trim02= L"Κωστας Μακέδοςςςς.ςςς";
        trimString(trim02, L'ς');
        BOOST_CHECK(trim02 == L"Κωστας Μακέδοςςςς.");
    }
    BOOST_AUTO_TEST_CASE(TEST_STRINGSEQUENCE) {
        std::vector<std::string> str_vec;
        for (int i = 0 ;i < 100; i++){
            str_vec.push_back("TestString");
        }
        std::cout << "Vector size :"  << str_vec.size() << std::endl;
    }

    BOOST_AUTO_TEST_CASE(TEST_STRINGLENGTH) {
        std::string tst = "Solop";
        std::string::size_type init_len = tst.length();
        std::string::size_type init_cap = tst.capacity();
        tst += "123456789012345678";
        std::string::size_type final_len = tst.length();
        std::string::size_type final_cap = tst.capacity();
        BOOST_CHECK_GE(final_len, init_len);
        BOOST_CHECK_GE(final_cap, init_cap);
    }
    BOOST_AUTO_TEST_CASE(TEST_STRINGREVERSE) {
        std::string tst = "Solop";
        reverseString(tst);
        BOOST_CHECK(tst == "poloS");
        std::string tst2;
        reverseAndCopyString(tst, tst2);
        BOOST_CHECK(tst2 == "Solop");
    }

    BOOST_AUTO_TEST_CASE(TEST_SPLITSTRING) {
        std::string address = "kostas.makedos@gmail.com";
        std::vector<std::string> v;
        splitString(address, '.', v);
        BOOST_CHECK(v[0] == "kostas");
        BOOST_CHECK(v[1] == "makedos@gmail");
        BOOST_CHECK(v[2] == "com");
    }
    BOOST_AUTO_TEST_CASE(TEST_STRINGTOKENIZER) {
        std::string address = "kostas.makedos@gmail.com";
        std::string delim = ".";
        std::string next_token;
        StringTokenizer *strtoken = new StringTokenizer(address, delim);
        BOOST_CHECK_EQUAL(strtoken->countTokens(), 3);
        BOOST_CHECK_EQUAL(strtoken->hasMoreTokens(), true);
        std::vector<std::string> v;
        while (strtoken->hasMoreTokens()){
            strtoken->nextToken(next_token);
            v.push_back(next_token);
        }
        std::string address2;
        join_vector(v, '.', address2);
        BOOST_CHECK(address == address2);
        std::wstring sor = L"ΕλαμΕλαμμαλαλΕρε μαλαE";
        std::wstring isordelim = L"Ε";
        BOOST_CHECK_EQUAL(count_words(sor, isordelim), 3);
        delete strtoken;
    }
    BOOST_AUTO_TEST_CASE(TEST_STRINGREMOVE) {
        std::string s = "NipsonAnomimataMiMonanopis";
        std::string t = "o";
        remove_string(s,t);
        BOOST_CHECK(s == "NipsnAnmimataMiMnanpis");
    }
    BOOST_AUTO_TEST_CASE(TEST_STRINGCASE) {
        std::string s = "NipsonAnomimataMiMonanopis";
        std::string ls;
        std::string us;
        to_lower(s);
        BOOST_CHECK(s == "nipsonanomimatamimonanopis");
        to_upper(s);
        BOOST_CHECK(s == "NIPSONANOMIMATAMIMONANOPIS");
    }
    BOOST_AUTO_TEST_CASE(TEST_STRINGCOMP) {
        std::string cat = "cAT";
        std::string dog = "Dog";
        std::string cat2 = "CAT";
        std::string dog2 = "DOgg";

        BOOST_CHECK(str_equal(cat, cat2) == true);
        BOOST_CHECK(str_equal(dog, dog2) == false);
    }
    BOOST_AUTO_TEST_CASE(TEST_STRINGSEARCH) {
        std::string cat = "CAT";
        std::string haystack1 = "dog's-CAT";
        std::string haystack2 = "killed the cats inside CaTroom: CATtter";
        std::string haystack3 = "No c at and no dog. CArs and Cast and C A T. Ca tr";
        BOOST_CHECK(str_search(cat, haystack1) == 7 );
        BOOST_CHECK(str_search(cat, haystack2) == 32);
        BOOST_CHECK(str_search(cat, haystack3) == -1);
    }

BOOST_AUTO_TEST_SUITE_END()