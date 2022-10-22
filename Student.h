
#ifndef PROJECT_STUDENT_H
#define PROJECT_STUDENT_H

#include <string>
#include <vector>
#include "UcAndClass.h"
#include "Class.h"

using namespace std;

class Student {

private:
    string studentCode;
    string studentName;
    vector<UcAndClass> ucAndClasses;

public:
    Student(string studentCode, string studentName, string ucCode, string classCode);
    void print();

    vector<UcAndClass> getUcAndClasses();
    string getStudentCode();
    string getStudentName();
    string getUcCode();
    string getClassCode();

    bool operator==(Student student);
    bool operator<(Student student);
    bool operator>(Student student);
};

#endif //PROJECT_STUDENT_H