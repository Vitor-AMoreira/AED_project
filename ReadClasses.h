//
// Created by victo on 22/10/2022.
//

#ifndef AED_PROJECT_READCLASSESPERUC_H
#define AED_PROJECT_READCLASSESPERUC_H
#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include "ReadStudent.h"
#include "Class.h"

using namespace std;

class ReadClasses {
private:
    vector<Class> allClasses;
public :
    ReadClasses(string file_name);

    vector<Class> getAllClasses();
    Class findClass(string ucCode, string classCode);
};


#endif //AED_PROJECT_READCLASSESPERUC_H
