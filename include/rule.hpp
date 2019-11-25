#pragma once
#ifndef FIZZBUZZ_RULE_HPP
#define FIZZBUZZ_RULE_HPP


class rule {
private:
    int _target;
    std::string _output;
public:
    rule(int target, const std::string& output) {
        _target = target;
        _output = output;
    }

    bool matched(int id);

    std::string applied();
};

bool rule::matched(int id) {
    return id % _target == 0;
}

std::string rule::applied() {
    return _output;
}


#endif //FIZZBUZZ_RULE_HPP
