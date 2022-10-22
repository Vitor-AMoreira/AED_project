//
// Created by Vitor on 20/10/2022.
//

#ifndef PROJECT_CLASS_H
#define PROJECT_CLASS_H

#include <cstring>
#include <iostream>
#include "Student.h"

using namespace std;

class Class {
private:
    string classCode;
    string ucCode;
    string weekday;
    float startHour;
    float duration;
    string type;

public:
    Class(string classCode, string ucCode, string weekday, float startHour, float duration, string type);

    vector<Student> getStudents();
    void addStudent(long int studentCode);
    void removeStudent(long int studentCode);
    bool class_balanced();

    string getClassCode();
    string getUcCode();
    string getWeekday();
    string getStartHour();
    string getDuration();
    string getType();


};
#endif //PROJECT_CLASS_H