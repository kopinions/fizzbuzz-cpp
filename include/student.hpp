#ifndef FIZZBUZZ_STUDENT_H
#define FIZZBUZZ_STUDENT_H


#include <string>

class student {
private:
    int _position;
public:
    int position() {
        return _position;
    }

    std::string countoff() {
        return std::to_string(_position);
    }

    student(int position) {
        _position = position;
    }
};


#endif //FIZZBUZZ_STUDENT_H
