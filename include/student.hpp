#pragma once

#ifndef FIZZBUZZ_STUDENT_H
#define FIZZBUZZ_STUDENT_H


#include <string>
#include <iostream>
#include "game.hpp"

class student {
private:
    int _position;
    std::shared_ptr<game> _game;
public:
    int position() {
        return _position;
    }

    std::string countoff();

    explicit student(int position) {
        _position = position;
    }

    void join(const std::shared_ptr<game> &game);
};

void student::join(const std::shared_ptr<game> &game) {
    _game = game;
}

std::string student::countoff() {
    const std::vector<std::shared_ptr<rule>> &rules = _game->rules();
    std::vector<std::shared_ptr<rule>> matched;
    for (const auto &r : rules) {
        if (r->matched(_position)) {
            matched.emplace_back(r);
            if (r->exclusive()) {
                break;
            }
        }
    }
    if (matched.empty()) {

        return std::to_string(_position);
    } else {
        std::string result = "";
        for (const auto &r: matched) {
            result += r->applied();
        }
        return result;
    }
}

void game::involve(std::vector<std::unique_ptr<student>> &students) {
    for (auto it = students.begin(); it < students.end(); it++) {
        std::unique_ptr<student> &ptr = *it;
        _students.push_back(std::make_unique<student>(**it));
    }
    for (auto it = _students.begin(); it < _students.end(); it++) {
        std::unique_ptr<student> &ptr = *it;
        const std::shared_ptr<game> &sharedPtr = shared();
        ptr->join(sharedPtr);
    }
}

game::game(const std::vector<std::shared_ptr<rule>> &rules) {
    _rules = rules;
}

std::shared_ptr<game> game::shared() {
    return shared_from_this();
}


#endif //FIZZBUZZ_STUDENT_H
