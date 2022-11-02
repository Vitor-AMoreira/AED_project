//
// Created by victo on 22/10/2022.
//

#include "Class.h"
#include <string>

using namespace std;

Class::Class(){}

Class::Class(string classCode, string ucCode, string weekday, string startHour, string duration, string type){

    float startHourFloat = stof(startHour);
    float durationFloat = stof(duration);

    this->ucCode = ucCode;
    this->classCode = classCode;
    this->weekday = weekday;
    this->startHour = startHourFloat;
    this->duration = durationFloat;
    this->type = type;
}

const string Class::getUcCode() {
    return this->ucCode;
}

const string Class::getClassCode() {
    return this->classCode;
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
    this->studentsNumber = this->studentsNumber + 1;
}

bool Class::isClassBalanced(vector<Class> classes) {
    for(Class i: classes) {
        if(i.getStudentsNumber() >= this->getStudentsNumber() + 4 || i.getStudentsNumber() <= this->getStudentsNumber() - 4) {
            return false;
        }
    }

    return true;
}