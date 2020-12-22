// Copyright 2020 Artamonov Mark <a.mark.2001@mail.ru>

#include <gtest/gtest.h>
#include "header.hpp"

TEST(the_hash,
        the_hash_generator_function) {
    The_hash_function_class the_hash_data;
    the_hash_data.
    the_hash_generator_function();
    EXPECT_EQ(the_hash_data.the_hash,
            picosha2::
            hash256_hex_string(
                    the_hash_data.
                    the_hash_prototype));
    the_hash_data.
    the_hash_generator_function();
    EXPECT_EQ(the_hash_data.the_hash,
            picosha2::
            hash256_hex_string(
                    the_hash_data.
                    the_hash_prototype));
    the_hash_data.
    the_hash_generator_function();
    EXPECT_EQ(the_hash_data.the_hash,
            picosha2::
            hash256_hex_string(
                    the_hash_data.
                    the_hash_prototype));
}

TEST(the_hash,
        check_if_hash_struct_correct) {
    The_hash_function_class the_hash_data;
    the_hash_data.the_hash
    ="9f86d081884c7d659a2feaa0c55ad015a3bf0000";
    EXPECT_EQ(true,
            the_hash_data.
            check_if_hash_struct_correct());
    the_hash_data.the_hash
    = "9f86d081884c7d659a2feaa0c55ad015a3bf0000d";
    EXPECT_EQ(false,
            the_hash_data.
            check_if_hash_struct_correct());
    the_hash_data.the_hash
    = "9f86d081884c7d659a2feaa0c55ad015a3bf000";
    EXPECT_EQ(false,
            the_hash_data.
            check_if_hash_struct_correct());
    the_hash_data.the_hash
    = "9f86d0d659a2feaa0c55ad015a3bfqwuweh300000";
    EXPECT_EQ(true,
            the_hash_data.
            check_if_hash_struct_correct());
    the_hash_data.the_hash
    = "0000";
    EXPECT_EQ(true,
            the_hash_data.
            check_if_hash_struct_correct());
}