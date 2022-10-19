
#include <fstream>
#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

Student::Student(long int studentCode, string studentName, string ucCode, string classCode) {
    this->studentCode = studentCode;
    this->studentName = studentName;
    this->ucCode = ucCode;
    this->classCode = classCode;
}

void Student::readStudent() {

    ifstream studentFile("../schedule/students_classes.csv");
    string line;
    int line_number = 0;

    while(getline(studentFile,line)){
        //cout << line << endl;
        if(line_number++ == 0) continue; //To skip the first row
        char c_line[line.length() + 1];
        strcpy(c_line,line.c_str());

        char *field;
        field = strtok(c_line,";");

        //cout << field << endl;
        //TESTE
        while(field != NULL){
            cout << field << " ";
            field = strtok(NULL,";");
        }
        cout << endl;
        if(line_number == 5) break; //TEST
    }
}
/*
Student::getStudentName() {
    return studentName;
}

Student::getUcCode() {
    return ucCode;
}

Student::setUcCode() {
    this.ucCode = ucCode;
}

Student::getClassCode() {
    return classCode;
}

Student::setClassCode() {
    this.classCode = classCode;
}*/