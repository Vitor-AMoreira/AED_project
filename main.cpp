#include <iostream>
#include <fstream>

#include "Student.cpp"
#include "Student.h"

int main() {

    Student student = Student(4782, "ifgb", "hifdg", "sidhgsd");
    student.readStudent();
    return 0;
}
