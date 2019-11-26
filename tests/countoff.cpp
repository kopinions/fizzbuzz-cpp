#include <student.hpp>
#include <game.hpp>
#include <gtest/gtest.h>
#include <memory>

TEST(StudentTest, should_countoff_same_as_position_when_rule_is_empty) {
    std::vector<std::unique_ptr<student>> students;
    for (auto i = 0; i < 100; i++) {
        students.push_back(std::make_unique<student>(i + 1));
    }
    const std::shared_ptr<game> &ga = std::make_shared<game>(game());
    ga->involve(students);

    for (auto it = ga->students().begin(); it < ga->students().end(); it++) {
        std::unique_ptr<student> &ptr = *it;
        EXPECT_EQ(std::to_string(ptr->position()), ptr->countoff());
    }
}

TEST(StudentTest, should_countoff_the_fizz_when_the_first_number_matched) {
    std::vector<std::unique_ptr<student>> students;
    for (auto i = 0; i < 100; i++) {
        students.push_back(std::make_unique<student>(i + 1));
    }
//    const std::shared_ptr<game> &ga = std::make_shared<game>(game());

    std::vector<std::shared_ptr<rule>> rules;
    rules.emplace_back(std::make_shared<times_rule>(times_rule(3, "Fizz")));
    const std::shared_ptr<game> &ga = game::create(rules);
    ga->involve(students);

    EXPECT_EQ("Fizz", ga->students().at(2)->countoff());
}


TEST(StudentTest, should_countoff_the_fizz_when_the_second_number_matched) {
    std::vector<std::unique_ptr<student>> students;
    for (auto i = 0; i < 100; i++) {
        students.push_back(std::make_unique<student>(i + 1));
    }
//    const std::shared_ptr<game> &ga = std::make_shared<game>(game());


    std::vector<std::shared_ptr<rule>> rules;
    rules.emplace_back(std::make_shared<times_rule>(times_rule(5, "Buzz")));
    const std::shared_ptr<game> &ga = game::create(rules);
    ga->involve(students);

    EXPECT_EQ("Buzz", ga->students().at(4)->countoff());
}


TEST(StudentTest, should_countoff_the_fizz_when_the_third_number_matched) {
    std::vector<std::unique_ptr<student>> students;
    for (auto i = 0; i < 100; i++) {
        students.push_back(std::make_unique<student>(i + 1));
    }
//    const std::shared_ptr<game> &ga = std::make_shared<game>(game());

    std::vector<std::shared_ptr<rule>> rules;
    rules.emplace_back(std::make_shared<times_rule>(times_rule(7, "Whizz")));
    const std::shared_ptr<game> &ga = game::create(rules);
    ga->involve(students);

    EXPECT_EQ("Whizz", ga->students().at(6)->countoff());
}

TEST(StudentTest, should_countoff_the_fizz_when_the_three_number_matched) {
    std::vector<std::unique_ptr<student>> students;
    for (auto i = 0; i < 100; i++) {
        students.push_back(std::make_unique<student>(i + 1));
    }
//    const std::shared_ptr<game> &ga = std::make_shared<game>(game());

    std::vector<std::shared_ptr<rule>> rules;
    rules.emplace_back(std::make_shared<times_rule>(times_rule(3, "Fizz")));
    rules.emplace_back(std::make_shared<times_rule>(times_rule(4, "Buzz")));
    rules.emplace_back(std::make_shared<times_rule>(times_rule(5, "Whizz")));
    const std::shared_ptr<game> &ga = game::create(rules);
    ga->involve(students);

    EXPECT_EQ("FizzBuzzWhizz", ga->students().at(59)->countoff());
}

TEST(StudentTest, should_skip_when_first_number_contains) {
    std::vector<std::unique_ptr<student>> students;
    for (auto i = 0; i < 100; i++) {
        students.push_back(std::make_unique<student>(i + 1));
    }

    std::vector<std::shared_ptr<rule>> rules;
    rules.emplace_back(std::make_shared<contains_rule>(contains_rule("3", "Fizz")));
    rules.emplace_back(std::make_shared<times_rule>(times_rule(3, "Fizz")));
    rules.emplace_back(std::make_shared<times_rule>(times_rule(5, "Buzz")));
    const std::shared_ptr<game> &ga = game::create(rules);
    ga->involve(students);

    EXPECT_EQ("Fizz", ga->students().at(34)->countoff());
    EXPECT_EQ("Buzz", ga->students().at(5-1)->countoff());
}


TEST(StudentTest, should_skip_when_no_rule_matched) {
    std::vector<std::unique_ptr<student>> students;
    for (auto i = 0; i < 100; i++) {
        students.push_back(std::make_unique<student>(i + 1));
    }

    std::vector<std::shared_ptr<rule>> rules;
    rules.emplace_back(std::make_shared<contains_rule>(contains_rule("3", "Fizz")));
    rules.emplace_back(std::make_shared<times_rule>(times_rule(3, "Fizz")));
    rules.emplace_back(std::make_shared<times_rule>(times_rule(4, "Buzz")));
    rules.emplace_back(std::make_shared<times_rule>(times_rule(5, "Whizz")));
    const std::shared_ptr<game> &ga = game::create(rules);
    ga->involve(students);

    EXPECT_EQ("7", ga->students().at(7-1)->countoff());
}