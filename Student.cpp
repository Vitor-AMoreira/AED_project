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

void Student::pushClass(Class *studentClass) {
    studentClass->decStudentsNumber();
    //Check if the max capacity of the class was reached
    if(studentClass->getStudentsNumber() > 25){
        cout << "The class is full" << endl;
        return;
    }

    for(auto it = classes.begin(); it != classes.end(); it++){

        //Check if the student already is in the class
        if((*it) == studentClass) {
            cout << "The student is already in this class" << endl;
            return ;
        }

        //Check if the schedule of the student can accept this new class
        if( (*it)->getWeekday() == studentClass->getWeekday() &&
            (*it)->getStartHour() == studentClass->getStartHour() &&
            (*it)->getType() == "TP" && studentClass->getType() == "TP"
            )
        {
            cout << "The student has a class at that time" << endl;
            return;
        }
    }
    classes.push_back(studentClass);
    studentClass->addStudentsNumber();
}
void Student::removeClass(Class *studentClass) {
    for(auto it = classes.begin(); it != classes.end(); it++){
       if((*it)->getUcCode() == studentClass->getUcCode() && (*it)->getClassCode() == studentClass->getClassCode()){
           (*it)->decStudentsNumber();
           classes.erase(it);
       }
    }
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
