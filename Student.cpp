#include "Student.h"

using namespace std;

Student::Student() {}

Student::Student(string studentCode, string studentName,Class studentClass) {
    this->studentCode = studentCode;
    this->studentName = studentName;

    //To insert in list classes
    classes.push_back(studentClass);

    //To add 1 student to the class StudentsNumber
    studentClass.addStudentsNumber();
    cout << studentClass.getStudentsNumber() << endl;
}

void Student::print(){
    cout << studentCode << "," << studentName;
}

void Student::pushClass(Class studentClass) {
    classes.push_back(studentClass);
    studentClass.addStudentsNumber();
    cout << "Entrou" << endl;
}
/*
void Student::removeClass(string ucCode) {
    for(Class c : classes){
        if(c.getUcCode() == ucCode){
            classes.remove(c);
        }
    }
}
 */

string Student::getStudentName() {
    return this->studentName;
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
