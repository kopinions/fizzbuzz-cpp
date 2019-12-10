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
    for (auto it = rules.begin(); it < rules.end(); it++) {
        if (it->matched(position)) {
            words += it->message();
        }
    }
    return words;
}


#endif //FIZZBUZZ_COUNTOFF_HPP
