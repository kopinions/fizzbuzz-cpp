//
// Created by neo on 12/10/19.
//

#ifndef FIZZBUZZ_COUNTOFF_HPP
#define FIZZBUZZ_COUNTOFF_HPP

#include "rule.hpp"

std::string countoff(int position, std::vector<rule> rules) {
    if (rules.size() == 0) {
        return std::to_string(position);
    }
    std::string words;
    if (position % 3 == 0) {
        words += "Fizz";
    }
    if (position % 5 == 0) {
        words += "Buzz";
    }
    if (position % 7 == 0) {
        words += "Whizz";
    }
    return words;
}


#endif //FIZZBUZZ_COUNTOFF_HPP
