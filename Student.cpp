
#include <fstream>
#include <iostream>
#include <cstring>
#include "Student.h"
#include "ReadClasses.h"
#include "Class.h"


using namespace std;

Student::Student(string studentCode, string studentName, string ucCode, string classCode, ReadClasses allClasses) {
    this->studentCode = studentCode;
    this->studentName = studentName;

    //To get the class object
    Class class_ = allClasses.findClass(ucCode, classCode);

    //To insert in list classes
    classes.push_back(class_);

    //To add 1 student to the class StudentsNumber
    class_.addStudentsNumber();

}

void Student::print(){
    cout << studentCode << "," << studentName << "," << classes[classes.begin()].getClass() << "," << classes[classes.begin()].getUc();
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
