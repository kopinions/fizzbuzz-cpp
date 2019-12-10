//
// Created by neo on 12/10/19.
//

#ifndef FIZZBUZZ_COUNTOFF_HPP
#define FIZZBUZZ_COUNTOFF_HPP
std::string countoff(int position, std::vector<int> rules) {
    if (rules.size() == 0) {
        return std::to_string(position);
    }

    if (position % 3 == 0) {
        return "Fizz";
    } else if (position % 5 == 0) {
        return "Buzz";
    }
    return std::to_string(position);
}


#endif //FIZZBUZZ_COUNTOFF_HPP
