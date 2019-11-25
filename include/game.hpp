#pragma once
#ifndef FIZZBUZZ_GAME_HPP
#define FIZZBUZZ_GAME_HPP


#include <utility>
#include <vector>
#include "student.hpp"
#include "rule.hpp"
class student;

class game: public std::enable_shared_from_this<game> {
private:
    std::vector<std::unique_ptr<student>> _students;
    std::vector<std::shared_ptr<rule>> _rules;
public:
    game() {
    }

    std::vector<std::unique_ptr<student>> &students() {
        return _students;
    }

    static std::shared_ptr<game> create(std::vector<rule> rules) {
//        const game &args = ;
//        return std::make_shared<game>(game());
        return std::make_shared<game>(game(rules));
    }

    std::vector<std::shared_ptr<rule>> rules() {
        return _rules;
    }

    std::shared_ptr<game> shared();

    void involve(std::vector <std::unique_ptr<student>>& students);
private:
    explicit game(const std::vector<rule>& rules);
};




#endif //FIZZBUZZ_GAME_HPP
