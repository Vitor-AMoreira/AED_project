
#ifndef PROJECT_STUDENT_H
#define PROJECT_STUDENT_H

#include <string>
#include <vector>
#include "Class.h"
#include "ReadClasses.h"

using namespace std;

class Student {

private:
    string studentCode;
    string studentName;
    list<Class> classes;

public:
    Student(string studentCode, string studentName, string ucCode, string classCode, ReadClasses allClasses);
    void print();

    list<Class> getClasses();
    string getStudentCode();
    string getStudentName();

    bool operator==(Student student);
    bool operator<(Student student);
    bool operator>(Student student);
};

#endif //PROJECT_STUDENT_H