//
// Created by victo on 03/11/2022.
//

#ifndef AED_PROJECT_REQUEST_H
#define AED_PROJECT_REQUEST_H
#include <string>
#include <iostream>

#include "StudentsTree.h"

using namespace std;

class Request {
    private :
        string action; //Remove from or add to a class
        string studentCode;
        string ucCode;
        string classCode;

    public :
        Request();
        Request(string action, string studentCode, string ucCode, string classCode);

        void setAction(string action);
        void setStudentCode(string studentCode);
        void setUcCode(string ucCode);
        void setClassCode(string classCode);

        string getAction() const;
        string getStudentCode() const;
        string getUcCode() const;
        string getClassCode() const;
};


#endif //AED_PROJECT_REQUEST_H
