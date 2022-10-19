
#include "Student.h"

Student::Student(studentCode, studentName, ucCode, classCode) {
    this.studentCode = studentCode;
    this.studentName = studentName;
    this.ucCode = ucCode;
    this.classCode = classCode;
}

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
}