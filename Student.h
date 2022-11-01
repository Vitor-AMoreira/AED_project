
#ifndef PROJECT_STUDENT_H
#define PROJECT_STUDENT_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include "Class.h"

using namespace std;

class Student {

private:

    string studentCode;
    string studentName;
    list<Class> classes;

public:
    Student(string studentCode, string studentName, Class &studentClass);
    void print();

    void pushClass(Class &studentClass);
    void removeClass(string ucCode); //To remove a student from a Uc/class

    /*
    list<Class> getClasses();
    string getStudentCode();
    */
    string getStudentName();

    bool operator==(Student student);
    bool operator<(Student student);
    bool operator>(Student student);
};

#endif //PROJECT_STUDENT_H