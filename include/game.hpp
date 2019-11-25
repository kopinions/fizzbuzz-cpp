#ifndef FIZZBUZZ_GAME_HPP
#define FIZZBUZZ_GAME_HPP


#include <vector>
#include "student.hpp"

class game: public std::enable_shared_from_this<game> {
private:
    std::vector<std::unique_ptr<student>> _students;
public:
    game() {
    }

    std::vector<std::unique_ptr<student>> &students() {
        return _students;
    }

    std::shared_ptr<game> create() {
        return shared_from_this();
    }

    void involve(std::vector <std::unique_ptr<student>>& students);
};

void game::involve(std::vector<std::unique_ptr<student>>& students) {
    for (auto it = students.begin(); it < students.end(); it++) {
        std::unique_ptr<student> &ptr = *it;

        _students.push_back(std::make_unique<student>(**it));
    }
}


#endif //FIZZBUZZ_GAME_HPP
