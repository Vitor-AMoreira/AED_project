//
// Created by Vitor on 03/11/2022.
//

#ifndef PROJECT_MENU_H
#define PROJECT_MENU_H

#include <vector>
#include <string>
#include "Class.h"
#include "StudentsTree.h"

using namespace std;

class Menu {
private:
    string lastInput;
    bool exit;
public:
    Menu(); //Done
    bool getExit(); //Done
    string getLastInput(); //Done
    void getUcs(); //Done
    Class getUcClasses(string); //Done
    void getClassStudents(StudentsTree, Class); //Doing
    void getAllStudents();
    void getStudentsByYear();

};


#endif //PROJECT_MENU_H
