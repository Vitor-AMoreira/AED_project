//
// Created by victo on 22/10/2022.
//

#ifndef AED_PROJECT_READCLASSESPERUC_H
#define AED_PROJECT_READCLASSESPERUC_H
#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include "Class.h"

using namespace std;

class ReadClasses {
private:
    vector<Class*> allClasses;
public :
    ReadClasses();

    vector<Class*> getAllClasses();
    Class *findClass(string ucCode, string classCode) const;
};


#endif //AED_PROJECT_READCLASSESPERUC_H
