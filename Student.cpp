
#include <fstream>
#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

Student::Student(string studentCode, string studentName, string ucCode, string classCode) {
    this->studentCode = studentCode;
    this->studentName = studentName;
    ucAndClasses.push_back(UcAndClass(ucCode,classCode));
    //this->ucCode = ucCode;
    //this->classCode = classCode;
}

void Student::print(){
    cout << studentCode << "," << studentName << "," << ucAndClasses[0].getClas() << "," << ucAndClasses[0].getUc();
}

bool Student::operator==(Student student) {
    return this->studentCode == student.studentCode;
}
bool Student::operator<(Student student){
    return this->studentCode < student.studentCode;
}
bool Student::operator>(Student student){
    return this->studentCode > student.studentCode;
}


        //cout << field << endl;
        //TESTEjksdfnbojsd faz o kenny G
        while(field != NULL){
            cout << field << " ";
            field = strtok(NULL,";");
        }
        cout << endl;
        if(line_number == 5) break; //TEST
    }
}
