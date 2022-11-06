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
    Menu();
    string getLastInput();
    void setOrder();
    bool getOrder();
    bool getExit();

    static bool strcmp(string, string);
    static bool mapcmpGreater(pair<string, string>, pair<string, string>);
    static bool mapcmpLess(pair<string, string>, pair<string, string>);

    void getOption();//Doing
    void getUcs();
    Class* getUcClasses(string, ReadClasses);
    void getClassStudents(StudentsTree, StudentsTree::node*, Class*);
    void showStudentDetails(StudentsTree, StudentsTree::node*);
    void getYearOption();
    void getStudentsByYear(StudentsTree, StudentsTree::node*);
    void getInputOfCountOfUcs();
    void getStudentsByCountOfUcs(StudentsTree, StudentsTree::node*);

};


#endif //PROJECT_MENU_H
