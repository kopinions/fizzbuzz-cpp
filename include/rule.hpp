#pragma once
#ifndef FIZZBUZZ_RULE_HPP
#define FIZZBUZZ_RULE_HPP


class rule {
protected:
    // allow construction for child classes only
    rule();

public:
    virtual ~rule() = default;

    rule(rule const &) = delete;

    rule &operator=(rule const &) = delete;

    virtual bool matched(int id) = 0;

    virtual std::string applied() = 0;

    virtual bool exclusive() = 0;
};

rule::rule() {

}

class times_rule : public rule {
private:
    int _target;
    std::string _output;
public:
    times_rule(int target, const std::string output) {
        _target = target;
        _output = output;
    }

    ~times_rule() {

    }

    times_rule(times_rule const &tr) {
        _target = tr._target;
        _output = tr._output;
    };

    times_rule &operator=(times_rule const &tr) {
        _target = tr._target;
        _output = tr._output;
        return *this;
    };

    virtual bool matched(int id) override;
    virtual bool exclusive() override;

    virtual std::string applied() override;

};

bool times_rule::matched(int id) {
    return id % _target == 0;
}

std::string times_rule::applied() {
    return _output;
}

bool times_rule::exclusive() {
    return false;
}

class contains_rule : public rule {
private:
    std::string _target;
    std::string _output;
public:
    contains_rule(const std::string &target, const std::string &output);

    ~contains_rule() {

    }

    contains_rule(contains_rule const &tr) {
        _target = tr._target;
        _output = tr._output;
    };

    contains_rule &operator=(contains_rule const &tr) {
        _target = tr._target;
        _output = tr._output;
        return *this;
    };

    virtual bool matched(int id) override;

    virtual bool exclusive() override;

    virtual std::string applied() override;
};

contains_rule::contains_rule(const std::string &target, const std::string &output) {
    _target = target;
    _output = output;
}

bool contains_rule::matched(int id) {
    return std::to_string(id).find(_target) != std::string::npos;
}

std::string contains_rule::applied() {
    return _output;
}

bool contains_rule::exclusive() {
    return true;
}

#endif //FIZZBUZZ_RULE_HPP
