//
// Created by victo on 22/10/2022.
//

#include "Class.h"
#include <string>

using namespace std;

Class::Class(){}

Class::Class(string classCode, string ucCode, string weekday, string startHour, string duration, string type){
    float startHourFloat;
    float durationFloat;

    if(startHour == "") {
        startHourFloat = 0;
    } else {
        startHourFloat = stof(startHour);
    }
    if(duration == "") {
        durationFloat = 0;
    } else {
        durationFloat = stof(duration);
    }


    this->ucCode = ucCode;
    this->classCode = classCode;
    this->weekday = weekday;
    this->startHour = startHourFloat;
    this->duration = durationFloat;
    this->type = type;
}

const string Class::getUcCode() const{
    return this->ucCode;
}

const string Class::getClassCode() const{
    return this->classCode;
}

const string Class::getWeekday() const{
    return weekday;
}

const float Class::getStartHour() const{
    return startHour;
}

const float Class::getDuration() const{
    return duration;
}

const string Class::getType() const{
    return type;
}

int Class::getStudentsNumber() const{
    return studentsNumber;
}

void Class::addStudentsNumber() {
    this->studentsNumber = this->studentsNumber + 1;
}

void Class::decStudentsNumber(){
    this->studentsNumber = this->studentsNumber - 1;
};

bool Class::isClassBalanced(vector<Class> classes) {
    for(Class i: classes) {
        if(i.getStudentsNumber() >= this->getStudentsNumber() + 4 || i.getStudentsNumber() <= this->getStudentsNumber() - 4) {
            return false;
        }
    }
    return true;
}

bool Class::areBalanced(Class *c){
    int diff = this->getStudentsNumber() - c->getStudentsNumber();
    diff = diff > 0 ? diff : -diff; //Getting the modulos
    return diff <= 4;
}