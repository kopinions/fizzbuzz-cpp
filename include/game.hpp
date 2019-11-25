#ifndef FIZZBUZZ_GAME_HPP
#define FIZZBUZZ_GAME_HPP


#include <vector>
#include "student.hpp"

class game {
private:
    std::vector<student> _students;
public:
    game(std::vector<student> students) {
        _students = students;
    }
    std::vector<student> students() {
        return _students;
    }
};


#endif //FIZZBUZZ_GAME_HPP
