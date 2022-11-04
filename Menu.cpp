//
// Created by Vitor on 03/11/2022.
//

#include "Menu.h"
#include "ReadClasses.h"
#include "StudentsTree.h"
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <list>
#include <string.h>

using namespace std;

Menu::Menu() {
    string input;
    cout << " -------------- MENU -------------- " << endl;
    cout << " [1] Get information from classes" << endl;
    cout << " [2] Get information from students" << endl;
    cout << " [0] Exit" << endl;
    cout << " ---------------------------------- " << endl;
    cout << " Choose a number: ";
    cin >> input;
    if(input == "0") exit = 1;
    else {
        lastInput = input;
    }
};

/*
 * -- MENU --
 * [1] GET INFO FROM CLASSES -> ALL UCS -> ALL CLASSES -> ALL STUDENTS
 *                              FROM YEAR -> ALL STUDENTS
 * [2] GET INFO FROM STUDENTS -> STUDENTS BY UCS -> GIVES: - UCs / Classes / Hours
 *                               STUDENTS BY
 */

string Menu::getLastInput() {
    return this->lastInput;
}

void Menu::setOrder() {
    string input;
    cout << "SELECT THE ORDER YOU WANT TO VIEW THE DATA" << endl;
    cout << "[1] Ascending" << endl;
    cout << "[2] Descending" << endl;
    cout << "------------------------------------------" << endl;
    cout << "Order: ";
    cin >> input;
    if(input == "1") {
        lastInputOrder = 0;
    }else if(input == "2") {
        lastInputOrder = 1;
    } else { exit = 1;}
}

bool Menu::getOrder() {
    return lastInputOrder;
}

bool Menu::getExit() {
    return this->exit;
}

bool Menu::strcmp(string a, string b) {
    if(a.compare(b) > 0)
        return true;
    else
        return false;
}

void Menu::getUcs() {
    ReadClasses readClasses;
    string input;
    vector<Class*> classes = readClasses.getAllClasses();

    set<string> ucsSet = {};

    for(Class *i:classes) {
        ucsSet.insert(i->getUcCode());
    }

    vector<string> ucs;
    ucs.assign(begin(ucsSet), end(ucsSet));

    // To sort the set accordingly to the given sort method
    bool order = getOrder();
    if(order == true) {
        sort(begin(ucs),end(ucs), strcmp);
    }

    cout << "-------------------" << endl;
    cout << "   CHOOSE AN UC" << endl;
    cout << "-------------------" << endl;

    for(string i: ucs) {
        cout << "  |  " << i << "  |  " << endl;
    }
    cout << "[0]  EXIT" << endl;
    cout << "-------------------" << endl;
    cout << "UC: ";
    cin >> input;

    if(find(ucs.begin(), ucs.end(), input) != ucs.end()) {
        lastInput = input;
    } else {
        exit = 1;
    }
}

Class Menu::getUcClasses(string uc) {
    ReadClasses readClasses;
    string input;
    vector<Class*> classes = readClasses.getAllClasses();

    set<string> ucClassesSet;

    for(Class* i: classes) {
        if(i->getUcCode() == uc) {
            ucClassesSet.insert(i->getClassCode());
        }
    }

    vector<string> ucClasses;
    ucClasses.assign(begin(ucClassesSet), end(ucClassesSet));

    // To sort the set accordingly to the given sort method
    bool order = getOrder();
    if(order == true) {
        sort(begin(ucClasses),end(ucClasses), strcmp);
    }

    cout << "-------------------" << endl;
    cout << "  CHOOSE A CLASS" << endl;
    cout << "-------------------" << endl;

    for(string i: ucClasses) {
        cout << "  |  " << i << "  |  " << endl;
    }

    cout << "[0]  EXIT" << endl;
    cout << "-------------------" << endl;
    cout << "Class: ";
    cin >> input;

    if(input == "0") {
        exit = 1;
        return Class("", "", "", "", "", "");
    }

    if(find(ucClasses.begin(), ucClasses.end(), input) != ucClasses.end()) {
        Class* class_ = readClasses.findClass(lastInput, input);
        lastInput = input;
        return *class_;
    }
}

void Menu::getClassStudents(StudentsTree, Class) {

}