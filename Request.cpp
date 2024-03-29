//
// Created by victo on 03/11/2022.
//

#include "Request.h"


    Request::Request() {}
    Request::Request(string action, string studentCode, string ucCode, string classCode) {
        this->action = action;
        this->studentCode = studentCode;
        this->ucCode = ucCode;
        this->classCode = classCode;
    }

    void Request::setAction(string action){
        this->action = action;
    }
    void Request::setStudentCode(std::string studentCode) {
        this->studentCode = studentCode;
    }
    void Request::setUcCode(string ucCode) {
        this->ucCode = ucCode;
    }
    void Request::setClassCode(std::string classCode) {
        this->classCode = classCode;
    }


    string Request::getAction() const {
        return action;
    }
    string Request::getStudentCode() const {
        return studentCode;
    }
    string Request::getUcCode() const {
        return ucCode;
    }
    string Request::getClassCode() const{
        return classCode;
    }