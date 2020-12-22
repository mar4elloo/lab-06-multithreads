// Copyright 2020 Artamonov Mark <a.mark.2001@mail.ru>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <header.hpp>
#include <boost/log/trivial.hpp>
#include <picosha2.h>
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <string>
#include <atomic>
#include <cstddef>
#include <thread>

using namespace std;

class The_hash_function_class {
public:
    string the_hash = "";
    string the_hash_prototype = "";
    static void SHA256() {
        The_hash_function_class
        the_hash_data;
        auto start = chrono
                ::steady_clock::now();
        while (true) {
            the_hash_data.
            the_hash_generator_function();
            if (the_hash_data.
            check_if_hash_struct_correct()) {
                auto end = chrono
                        ::steady_clock
                        ::now();
                auto the_timestamp = end-start;
                BOOST_LOG_TRIVIAL(info)
                    << "The id of thread: "
                    << this_thread::get_id()
                    << "; The timestamp: "
                    << the_timestamp.count()
                    << "; The hash prototype: "
                    << the_hash_data.
                    the_hash_prototype
                    << "; The_hash: "
                    << the_hash_data.the_hash
                    << "; Data is correct!;";
                break;
            }
            BOOST_LOG_TRIVIAL(info)
                << "The id of thread: "
                << this_thread::get_id()
                << "; The hash prototype:: "
                << the_hash_data.
                the_hash_prototype
                << "; The_hash: "
                << the_hash_data.the_hash
                << "; Data is incorrect!;";
        }
    }
    void the_hash_generator_function() {
        the_hash_prototype =
                to_string(rand());
        the_hash = picosha2
        ::hash256_hex_string(
                the_hash_prototype);
    }
    bool check_if_hash_struct_correct() {
        string extra = the_hash.substr(
                the_hash.size() - 4, 4);
        return  extra == "0000";
    }
};

#endif // INCLUDE_HEADER_HPP_