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
    bool lastInputOrder = 0;
    bool exit = 0;
public:
    Menu(); //Done
    string getLastInput(); //Done
    void setOrder(); //Done
    bool getOrder(); //Done
    bool getExit(); //Done
    static bool strcmp(string, string); //Doing
    void getUcs(); //Done
    Class getUcClasses(string); //Done
    void getClassStudents(StudentsTree, Class); //Doing
    //void getAllStudents();
    //void getStudentsByYear();

};


#endif //PROJECT_MENU_H
