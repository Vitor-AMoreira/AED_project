//
// Created by victo on 20/10/2022.
//

#ifndef AED_PROJECT_READSTUDENT_H
#define AED_PROJECT_READSTUDENT_H
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "Student.h"

using namespace std;

class ReadStudent {
    public :
        ReadStudent();
        vector<Student> read(string file_name);
};


#endif //AED_PROJECT_READSTUDENT_H
