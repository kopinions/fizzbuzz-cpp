//
// Created by neo on 12/10/19.
//

#ifndef FIZZBUZZ_RULE_HPP
#define FIZZBUZZ_RULE_HPP


class rule {
public:
    rule(int criteria, std::string message);

    bool matched(int position);

    std::string message();

private:
    std::string _message;
    int _criteria;
};

rule::rule(int criteria, std::string message) {
    _criteria = criteria;
    _message = message;
}

bool rule::matched(int position) {
    return true;
}

std::string rule::message() {
    return _message;
}


#endif //FIZZBUZZ_RULE_HPP
