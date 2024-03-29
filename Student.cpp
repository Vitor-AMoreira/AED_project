#include "Student.h"

using namespace std;

Student::Student() {}

Student::Student(string studentCode, string studentName, Class *studentClass) {
    this->studentCode = studentCode;
    this->studentName = studentName;

    //To insert in list classes
    classes.push_back(studentClass);
    studentClass->addStudentsNumber();
}

void Student::print(){
    cout << studentCode << "," << studentName;
}

bool Student::pushClass(Class *studentClass) {
    studentClass->decStudentsNumber();
    //Check if the max capacity of the class was reached
    if(studentClass->getStudentsNumber() > 25){
        cout << "The student cannot be added to this class\n\n\t\tCLASS IS FULL" << endl;
        return false;
    }

    for(auto it = classes.begin(); it != classes.end(); it++){

        //Check if the student already is in the class
        if((*it) == studentClass) {
            cout << "The student is already in this class" << endl;
            return false;
        }

        //Check if the schedule of the student can accept this new class
        if( (*it)->hourShock(studentClass) )
        {
            cout << "The student cannot be added to this class \n HAS A CLASS AT THE SAME TIME" << endl;
            return false;
        }
    }
    classes.push_back(studentClass);
    studentClass->addStudentsNumber();
    return true;
}
bool Student::removeClass(Class *studentClass) {
    for(auto it = classes.begin(); it != classes.end(); it++){
       if((*it) == studentClass){
           studentClass->decStudentsNumber();
           classes.erase(it);
           return true;
       }
    }
    cout << "!!! THE STUDENT DOES NOT BELONG TO THIS CLASS !!!" << endl;
    return false;
}

void Student::changeToClass(Class *studentClass) {
    for(auto it = classes.begin(); it != classes.end(); it++){

        if(     (*it)->getWeekday() == studentClass->getWeekday() &&
                (*it)->getStartHour() == studentClass->getStartHour() &&
                (*it)->getType() == "TP" &&
                studentClass->getType() == "TP" &&
                studentClass->areBalanced(*it))
        {
            (*it)->decStudentsNumber();
            classes.erase(it);

            studentClass->addStudentsNumber();
            classes.push_back(studentClass);
            return;
        }
    }
}

bool Student::isInClass(Class *studentClass) {
    for(auto it = classes.begin(); it != classes.end(); it++) {
        //Check if the student already is in the class
        if ((*it) == studentClass) return true;
    }
    return false;
}




list<Class*> Student::getClasses() {
    return classes;
}
string Student::getStudentName() {
    return studentName;
}
string Student::getStudentCode() {
    return studentCode;
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
