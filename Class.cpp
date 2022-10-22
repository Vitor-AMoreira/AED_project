//
// Created by victo on 22/10/2022.
//

#include "Class.h"
#include <vector>

using namespace std;

Class::Class(string ucCode, string classCode, string weekday, float startHour, float duration, string type){
    this->ucCode = ucCode;
    this->classCode = classCode;
    this->weekday = weekday;
    this->startHour = startHour;
    this->duration = duration;
    this->type = type;
}

const string Class::getUcCode() {
    return ucCode;
}

const string Class::getClassCode() {
    return classCode;
}

const string Class::getWeekday() {
    return weekday;
}

const float Class::getStartHour() {
    return startHour;
}

const float Class::getDuration() {
    return duration;
}

const string Class::getType() {
    return type;
}

int Class::getStudentsNumber() {
    return studentsNumber;
}

void Class::addStudentsNumber() {
    this->studentsNumber++;
}

bool Class::isClassBalanced(vector<Class> classes) {
    for(Class i: classes) {
        if(i.getStudentsNumber() >= this->getStudentsNumber() + 4 || i.getStudentsNumber() <= this->getStudentsNumber() - 4) {
            return false;
        }
    }

    return true;
}