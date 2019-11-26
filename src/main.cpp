#include <vector>
#include <student.hpp>
#include <game.hpp>
#include <rule.hpp>

int main(int argc, char **argv) {
    std::vector<std::unique_ptr<student>> students;
    for (auto i = 0; i < 100; i++) {
        students.push_back(std::make_unique<student>(i + 1));
    }

    std::vector<std::shared_ptr<rule>> rules;
    rules.emplace_back(std::make_shared<contains_rule>(contains_rule("3", "Fizz")));
    rules.emplace_back(std::make_shared<times_rule>(times_rule(3, "Fizz")));
    rules.emplace_back(std::make_shared<times_rule>(times_rule(5, "Buzz")));
    rules.emplace_back(std::make_shared<times_rule>(times_rule(7, "Whizz")));
    const std::shared_ptr<game> &ga = game::create(rules);
    ga->involve(students);

    for (auto it = ga->students().begin(); it < ga->students().end(); it++) {
        std::cout << (*it)->countoff() << std::endl;
    }
};