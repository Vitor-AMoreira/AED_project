
#ifndef PROJECT_STUDENT_H
#define PROJECT_STUDENT_H
#endif //PROJECT_STUDENT_H

Class Student {

private:
    string studentCode;
    string studentName;
    vector<string> ucCode;
    vector<string> classCode;

public:
    Student(string studentCode, string studentName, string ucCode, string classCode);

    getUcCode();
    getClassCode();
    getStudentName();

    setUcCode();
    setClassCode();
    setStudentName();
}

