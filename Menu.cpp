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
#include "Student.h"
#include <map>
#include <iomanip>

using namespace std;

Menu::Menu() {
    string input;
    cout << "\n";
    cout << " --------- MENU --------- " << endl;
    cout << " [1] See students data" << endl;
    cout << " [2] Make changes" << endl;
    cout << " [3] Save changes" << endl;
    cout << " [4] Apply all changes saved" << endl;
    cout << " [0] Quit" << endl;
    cout << " ------------------------ " << endl;
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

bool Menu::isNumber(string& s) {
    for (char const &ch : s) {
        if (isdigit(ch) == 0)
            return false;
    }
    return true;
}

bool Menu::mapcmpGreater(pair<string, string> a,pair<string, string> b) {
    if(a.second.compare(b.second) > 0)
        return true;
    else
        return false;
}

bool Menu::mapcmpLess(pair<string, string> a,pair<string, string> b) {
    if(a.second.compare(b.second) < 0)
        return true;
    else
        return false;
}

void Menu::getOption() {
    cout << "-----------------------" << endl;
    cout << "   CHOOSE AN OPTION" << endl;
    cout << "-----------------------" << endl;
    cout << "[1] Get students by Ucs/Classes" << endl;
    cout << "[2] Get students by year" << endl;
    cout << "[3] Get students with more classes" << endl;
    cout << "[4] Get a student by their code" << endl;
    cout << "[0]  EXIT" << endl;
    cout << "-------------------" << endl;
    cout << "Option: ";


    string input;
    cin >> input;

    if(input == "1" || input == "2" || input == "3" || input == "4") {
        lastInput = input;
    } else if(input == "0"){
        exit = 1;
    } else {
        cout << "Invalid input!" << endl;
        exit = 1;
    }

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
    } else if(input == "0"){
        exit = 1;
    } else {
        cout << "Invalid input!" << endl;
        exit = 1;
    }
}

Class* Menu::getUcClasses(string uc, ReadClasses readClasses) {
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
        return nullptr;
    }

    if(find(ucClasses.begin(), ucClasses.end(), input) != ucClasses.end()) {
        Class* class_ = readClasses.findClass(lastInput, input);
        lastInput = input;
        return class_;
    } else {
        cout << "Invalid input!" << endl;
        exit = 1;
        return nullptr;
    }
}

void Menu::getClassStudents(StudentsTree tree, StudentsTree::node* head, Class* class_) {
    string input;
    tree.clearBuffStudent();
    tree.allStudentsInAClass(head, class_);
    vector<Student> students = tree.getBuffStudent();

    cout << "------------------------------------" << endl;
    cout << "   CHOOSE A STUDENT BY THEIR CODE   " << endl;
    cout << " Number of students in this class: " << class_->getStudentsNumber() << endl;
    cout << "------------------------------------" << endl;

    //Vector to use to sort
    vector<pair<string, string>>  studentsPair;

    //Iterate through the map and insert all items in the new vector
    for (auto itr = students.begin(); itr != students.end(); ++itr) {
        studentsPair.push_back(make_pair(itr->getStudentCode(), itr->getStudentName()));
    }
    bool order = getOrder();
    if(order == true) {
        sort(studentsPair.begin(), studentsPair.end(), mapcmpGreater);
    } else {
        sort(studentsPair.begin(), studentsPair.end(), mapcmpLess);
    }

    for (auto i: studentsPair) {
        cout << i.first << " | " << i.second << endl;
    }

    cout << "[0]  EXIT" << endl;
    cout << "-------------------" << endl;
    cout << "Student code: ";
    cin >> input;

    if(input.size() != 9 || !isNumber(input)) {
        exit = 1;
        return;
    }

    lastInput = input;
}

void Menu::showStudentDetails(StudentsTree tree, StudentsTree::node * head) {
    string studentCode = getLastInput();
    Student student = tree.findByCode(head, studentCode)->student;

    cout << "---------------------------------------------------------" << endl;
    cout << "           ALL DETAILS ABOUT THE STUDENT CHOSEN        " << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << student.getStudentCode() << " | " << student.getStudentName() << endl;

    cout << "---------------------------------------------------------" << endl;
    cout << "                        CLASSES                          " << endl;
    cout << "---------------------------------------------------------" << endl;

    list<Class*> classes = student.getClasses();

    for(Class* i: classes) {
        cout << setw(10) <<i->getUcCode() << setw(10) << " - " << setw(10) << i->getClassCode() << setw(10) << " - " << setw(7) << i->getType() << setw(10) << endl;
        cout << "Week day: " << i->getWeekday() << " | Start hour: " << i->getStartHour() << " | Duration: " << i->getDuration() << " hours" << endl;
        cout << "---------------------------------------------------------" << endl;
    }
    cout << "[0] Return to main menu" << endl;
    string input;
    cin >> input;

    exit = 1;
}

void Menu::getYearOption() {
    cout << "------------------------------" << endl;
    cout << "   CHOOSE AN OPTION OF YEAR" << endl;
    cout << "------------------------------" << endl;
    cout << setw(10) << "2019" << endl;
    cout << setw(10) << "2020" << endl;
    cout << "------------------------------" << endl;
    cout << "Option: ";

    string input;
    cin >> input;

    if(input != "2019" && input != "2020") {
        exit = 1;
    }else {
        lastInput = input;
    }
}

void Menu::getStudentsByYear(StudentsTree tree, StudentsTree::node * head) {
    tree.clearBuffStudent();
    tree.allStudentsInAYear(head, lastInput);
    vector<Student> students = tree.getBuffStudent();

    cout << "------------------------------" << endl;
    cout << "   ALL STUDENTS FROM " << lastInput << endl;
    cout << "------------------------------" << endl;

    //Vector to use to sort
    vector<pair<string, string>>  studentsPair;

    //Iterate through the map and insert all items in the new vector
    for (auto itr = students.begin(); itr != students.end(); ++itr) {
        studentsPair.push_back(make_pair(itr->getStudentCode(), itr->getStudentName()));
    }
    bool order = getOrder();
    if(order == true) {
        sort(studentsPair.begin(), studentsPair.end(), mapcmpGreater);
    } else {
        sort(studentsPair.begin(), studentsPair.end(), mapcmpLess);
    }

    for (auto i: studentsPair) {
        cout << i.first << " | " << i.second << endl;
    }

    cout << "[0]  EXIT" << endl;
    cout << "------------------------------" << endl;
    cout << "Student: ";

    string input;
    cin >> input;

    if(input.size() != 9 || !isNumber(input)) {
        exit = 1;
    } else {
        lastInput = input;
    }

}

void Menu::getInputOfCountOfUcs() {
    cout << "----------------------------------------------------------------" << endl;
    cout << "                         INSERT AN INPUT                        " << endl;
    cout << " The students you want to see must have at least how many UCs?  "  << endl;
    cout << "----------------------------------------------------------------" << endl;
    string input;
    cin >> input;

    if(find_if(input.begin(),input.end(), [](char c) {return !isdigit(c); }) == input.end()) {
        lastInput = input;
    } else {
        exit = 1;
    }

}

void Menu::getStudentsByCountOfUcs(StudentsTree tree, StudentsTree::node *head) {
    tree.clearBuffStudent();
    tree.moreThanXClass(head, stoi(lastInput));
    vector<Student> students = tree.getBuffStudent();

    cout << "-----------------------------------------------" << endl;
    cout << "  ALL STUDENTS WITH MORE THAN " << lastInput << "UCs" << endl;
    cout << "-----------------------------------------------" << endl;


    //Vector to use to sort
    vector<pair<string, string>>  studentsPair;

    //Iterate through the map and insert all items in the new vector
    for (auto itr = students.begin(); itr != students.end(); ++itr) {
        studentsPair.push_back(make_pair(itr->getStudentCode(), itr->getStudentName()));
    }
    bool order = getOrder();
    if(order == true) {
        sort(studentsPair.begin(), studentsPair.end(), mapcmpGreater);
    } else {
        sort(studentsPair.begin(), studentsPair.end(), mapcmpLess);
    }

    for (auto i: studentsPair) {
        cout << i.first << " | " << i.second << endl;
    }

    cout << "[0]  EXIT" << endl;
    cout << "------------------------------" << endl;
    cout << "Student: ";

    string input;
    cin >> input;

    if(input.size() != 9 || !isNumber(input)) {
        exit = 1;
    } else {
        lastInput = input;
    }
}

void Menu::getStudentCode() {
    cout << "-----------------------------------------------------" << endl;
    cout << "  INSERT THE CODE OF THE STUDENT YOU WANT TO CHANGE " << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Student code: ";

    string input;
    cin >> input;

    if(input.size() != 9 || !isNumber(input)) {
        cout << "Invalid input!" << endl;
        exit = 1;
    } else {
        lastInput = input;
    }
}

Student Menu::showStudentDetailsToChange(StudentsTree tree, StudentsTree::node * head) {
    string studentCode = getLastInput();
    Student student = tree.findByCode(head, studentCode)->student;

    cout << "---------------------------------------------------------" << endl;
    cout << "           ALL DETAILS ABOUT THE STUDENT CHOSEN        " << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << student.getStudentCode() << " | " << student.getStudentName() << endl;

    cout << "---------------------------------------------------------" << endl;
    cout << "                        CLASSES                          " << endl;
    cout << "---------------------------------------------------------" << endl;

    list<Class*> classes = student.getClasses();

    for(Class* i: classes) {
        cout << i->getUcCode() << " - " << i->getClassCode() << " - " << i->getType() << endl;
        cout << "Week day: " << i->getWeekday() << " | Start hour: " << i->getStartHour() << " | Duration: " << i->getDuration() << " hours" << endl;
        cout << "---------------------------------------------------------" << endl;
    }
    cout << "[1] To add a UC and class" << endl;
    cout << "[2] To remove a UC and class" << endl;
    cout << "[0] EXIT" << endl;
    cout << "Option: ";

    string input;
    cin >> input;

    if(input == "1") {
        lastInput = "ADD";
    } else if(input == "2") {
        lastInput = "REMOVE";
    } else {
        exit = 1;
    }
    return student;
}

void Menu::makeChanges(ReadClasses readClasses,Student &student, RequestsQueue &queue, StudentsTree tree, StudentsTree::node *head) {
    cout << "---------------------------------------------------------" << endl;
    cout << "  INSERT THE UC AND CLASS CODE YOU WANT TO "               << lastInput << endl;
    cout << "---------------------------------------------------------" << endl;

    cout << "UC code: ";
    string ucCode;
    cin >> ucCode;

    cout << "Class code: ";
    string classCode;
    cin >> classCode;

    Class* class_ = readClasses.findClass(ucCode, classCode);

    if(class_ == nullptr) {
        cout << "\n Class not found!" << endl;
        exit = 1;
        return;
    }

    Request r(lastInput.substr(0, 1), student.getStudentCode(), class_->getUcCode(), class_->getClassCode());

    queue.push(r);

    cout << "Your request was added in our queue!" << endl;

    exit = 1;

}