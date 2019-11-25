#include <student.hpp>
#include <game.hpp>
#include <gtest/gtest.h>

TEST(StudentTest, should_countoff_same_as_position_when_rule_is_empty) {
    std::vector<student> students;
    for (auto i = 0; i < 100; i++) {
        students.push_back(student(i + 1));
    }
    game ga(students);
    const std::vector<student> &stus = ga.students();

    for (auto s : stus) {
        student &student = s;
        EXPECT_EQ(std::to_string(student.position()), student.countoff());
    }
}