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
    else { lastInput = input; }
};

/*
 * -- MENU --
 * [1] GET INFO FROM CLASSES -> FROM UC -> ALL UCS -> ALL CLASSES -> ALL STUDENTS
 *                              FROM YEAR -> ALL STUDENTS
 * [2] GET INFO FROM STUDENTS -> ALL STUDENTS -> GIVES: - UCs / Classes / Hours
 */

string Menu::getLastInput() {
    return this->lastInput;
}

bool Menu::getExit() {
    return this->exit;
}

void Menu::getUcs() {
    ReadClasses readClasses;
    string input;
    vector<Class*> classes = readClasses.getAllClasses();

    set<string> uniqueUcs;
    for(Class *i:classes) {
        uniqueUcs.insert(i->getUcCode());
    }

    cout << "-------------------" << endl;
    cout << "   CHOOSE AN UC" << endl;
    cout << "-------------------" << endl;

    for(string i: uniqueUcs) {
        cout << "  |  " << i << "  |  " << endl;
    }
    cout << "[0]  EXIT" << endl;
    cout << "-------------------" << endl;
    cout << "UC: ";
    cin >> input;

    if(find(uniqueUcs.begin(), uniqueUcs.end(), input) != uniqueUcs.end()) {
        lastInput = input;
    } else {
        exit = 1;
    }
}

Class Menu::getUcClasses(string uc) {
    ReadClasses readClasses;
    string input;
    vector<Class*> classes = readClasses.getAllClasses();

    set<string> ucClasses;

    for(Class* i: classes) {
        if(i->getUcCode() == uc) {
            ucClasses.insert(i->getClassCode());
        }
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

    if(find(ucClasses.begin(), ucClasses.end(), input) != ucClasses.end()) {
        lastInput = input;
    } else {
        exit = 1;
    }
}

void Menu::getClassStudents(StudentsTree tree, Class class_) {

}