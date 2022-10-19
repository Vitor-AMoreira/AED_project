
#ifndef PROJECT_STUDENT_H
#define PROJECT_STUDENT_H

#include <string>
#include <vector>

using namespace std;

class Student {

private:
    long int studentCode;
    string studentName;
    string ucCode;
    string  classCode;

public:
    Student(long int studentCode, string studentName, string ucCode, string classCode);

    string getUcCode();
    string getClassCode();
    string getStudentName();

    void readStudent();
    void setUcCode();
    void setClassCode();
    void setStudentName();
};

#endif //PROJECT_STUDENT_H