//
// Created by Vitor on 20/10/2022.
//


#include <cstring>
#include <iostream>
#include "Class.h"
#include "Student.h"

using namespace std;

Class::Class(string classCode, string ucCode, string weekday, float startHour, float duration, string type) {
    this->classCode = classCode;
    this->ucCode = ucCode;
    this->weekday = weekday;
    this->startHour = startHour;
    this->duration = duration;
    this->type = type;
};

Student getStudent() {

};