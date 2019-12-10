#include <student.hpp>
#include <game.hpp>
#include <gtest/gtest.h>
#include <countoff.hpp>

TEST(StudentTest, should_countoff_same_as_position_when_rule_is_empty) {
    std::vector<rule> rules;
    for (int i = 1; i < 100; i++) {
        EXPECT_EQ(countoff(i, rules), std::to_string(i));
    }
}

TEST(StudentTest, should_countoff_bizz_when_postion_is_3_times) {
    std::vector<rule> rules;
    rules.emplace_back(rule(3, "Fizz"));
    EXPECT_EQ(countoff(3, rules), "Fizz");
}

TEST(StudentTest, should_countoff_bizz_when_postion_is_5_times) {
    std::vector<rule> rules;
    rules.emplace_back(rule(5, "Buzz"));
    EXPECT_EQ(countoff(5, rules), "Buzz");
}



TEST(StudentTest, should_countoff_bizz_when_postion_is_7_times) {
    std::vector<rule> rules;
    rules.emplace_back(rule(7, "Whizz"));
    EXPECT_EQ(countoff(7, rules), "Whizz");
}

TEST(StudentTest, should_countoff_bizz_when_postion_both_3_and_5_times) {
    std::vector<rule> rules;
    rules.emplace_back(rule(3, "Fizz"));
    rules.emplace_back(rule(5, "Buzz"));
    EXPECT_EQ(countoff(15, rules), "FizzBuzz");
}

TEST(StudentTest, should_countoff_bizz_when_postion_both_5_and_7_times) {
    std::vector<rule> rules;
    rules.emplace_back(rule(5, "Buzz"));
    rules.emplace_back(rule(7, "Whizz"));
    EXPECT_EQ(countoff(35, rules), "BuzzWhizz");
}

TEST(StudentTest, should_count_off_buzz_when_rule_is_defined_5_fizz) {
    std::vector<rule> rules;
    rules.emplace_back(rule(5, "Fizz"));
    EXPECT_EQ(countoff(5, rules), "Fizz");
}