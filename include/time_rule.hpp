#ifndef FIZZBUZZ_TIME_RULE_HPP
#define FIZZBUZZ_TIME_RULE_HPP

class rule {
public:
    virtual bool matched(int position) = 0;
    virtual std::string message() = 0;
};

class time_rule : public rule {
public:
    time_rule(int criteria, std::string message);

    bool matched(int position) override;

    std::string message() override;

private:
    std::string _message;
    int _criteria;
};

class contains_rule : public rule {
private:
    std::string _message;
    int _criteria;
public:
    contains_rule(int criteria, std::string message) {
        _criteria = criteria;
        _message = message;
    }

    bool matched(int position) override;

    std::string message() override;

    contains_rule(contains_rule &rule);
};

contains_rule::contains_rule(contains_rule &rule) {
    _criteria = rule._criteria;
    _message = rule._message;
}

bool contains_rule::matched(int position) {
    std::cout << "position:" << position << "criteria" << _criteria << std::endl;
    return std::to_string(position).find(std::to_string(_criteria)) != std::string::npos;
}

std::string contains_rule::message() {
    return _message;
}

time_rule::time_rule(int criteria, std::string message) {
    _criteria = criteria;
    _message = message;
}

bool time_rule::matched(int position) {
    return position % _criteria == 0;
}

std::string time_rule::message() {
    return _message;
}


#endif //FIZZBUZZ_TIME_RULE_HPP
