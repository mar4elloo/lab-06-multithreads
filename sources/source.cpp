// Copyright 2020 Artamonov Mark <a.mark.2001@mail.ru>

#include "header.hpp"

using namespace std;

int main(int const arguments_count,
        char const* arguments[]) {
    if (arguments_count > 2) {
        cerr
        << "There are too much arguments!"
        << endl;
        return 1;
    }
    size_t the_number_of_threads;
    if (arguments_count == 2) {
        the_number_of_threads
        = size_t(arguments[1]);
        BOOST_LOG_TRIVIAL(info)
        << arguments[1]
        << " traces";
    }
    if (arguments_count == 1) {
        the_number_of_threads =
                thread
                ::hardware_concurrency();
        BOOST_LOG_TRIVIAL(info)
            << the_number_of_threads
            << " the_number_of_threads";
    }
    vector<thread> the_threads_vector;
    for (size_t i = 0;
         i < the_number_of_threads; ++i) {
        the_threads_vector.push_back(thread(
                The_hash_function_class
                ::SHA256));
    }
    for (size_t i = 0;
         i < the_number_of_threads; ++i) {
        the_threads_vector[i].join();
    }

    return 0;
}
