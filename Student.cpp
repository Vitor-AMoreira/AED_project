#include "Student.h"

using namespace std;

Student::Student(string studentCode, string studentName,Class &studentClass) {
    this->studentCode = studentCode;
    this->studentName = studentName;

    //To insert in list classes
    classes.push_back(studentClass);

    //To add 1 student to the class StudentsNumber
    studentClass.addStudentsNumber();

}

void Student::print(){
    cout << studentCode << "," << studentName;
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
