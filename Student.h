
#ifndef PROJECT_STUDENT_H
#define PROJECT_STUDENT_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include "Class.h"
#include "ReadClasses.h"

using namespace std;

class Student {

private:

    string studentCode;
    string studentName;
    list<Class*> classes;

public:

    Student();
    Student(string studentCode, string studentName,  Class *studentClass);
    void print();

    void pushClass(Class *studentClass);
    void removeClass(Class *studentClass); //To remove a student from a Uc/class
    void changeToClass(Class *studentClass);
    bool isInClass(Class *studentClass);


    list<Class*> getClasses();
    string getStudentName();
    string getStudentCode();

    bool operator==(Student student);
    bool operator<(Student student);
    bool operator>(Student student);
};

#endif //PROJECT_STUDENT_H