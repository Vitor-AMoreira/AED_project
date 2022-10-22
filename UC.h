//
// Created by Vitor on 20/10/2022.
//

#ifndef PROJECT_UC_H
#define PROJECT_UC_H

#include <string>
#include <vector>
#include "Class.h"

using namespace std;

class UC {
private:
    string ucCode;
    string classes;
public:
    UC(string ucCode, string classCode);

    vector<Class> getClasses();
};

#endif //PROJECT_UC_H
