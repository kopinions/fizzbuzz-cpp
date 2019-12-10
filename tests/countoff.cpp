#include <student.hpp>
#include <game.hpp>
#include <gtest/gtest.h>
#include <countoff.hpp>

TEST(StudentTest, should_countoff_same_as_position_when_rule_is_empty) {
    std::vector<int> rules;
    for (int i = 1; i < 100; i++) {
        EXPECT_EQ(countoff(i, rules), std::to_string(i));
    }
}

TEST(StudentTest, should_countoff_bizz_when_postion_is_3_times) {
    std::vector<int> rules;
    rules.emplace_back(3);
    EXPECT_EQ(countoff(3, rules), "Fizz");
}

TEST(StudentTest, should_countoff_bizz_when_postion_is_5_times) {
    std::vector<int> rules;
    rules.emplace_back(5);
    EXPECT_EQ(countoff(5, rules), "Buzz");
}



TEST(StudentTest, should_countoff_bizz_when_postion_is_7_times) {
    std::vector<int> rules;
    rules.emplace_back(7);
    EXPECT_EQ(countoff(7, rules), "Whizz");
}
