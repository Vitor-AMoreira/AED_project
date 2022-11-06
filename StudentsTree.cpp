//
// Created by victo on 22/10/2022.
//
#include "StudentsTree.h"

StudentsTree::StudentsTree() { head = nullptr; }

 StudentsTree::node *StudentsTree::build(StudentsTree::node *t, Student &student) {
    if(t == nullptr) {
        return new node{nullptr, nullptr, student};};
    if(student < t->student) t->left = build(t->left,student);
    else if(student > t->student) t->right = build(t->right, student);
    return t;
}

StudentsTree::node *StudentsTree::findByObj(StudentsTree::node *t, Student &student) {
        StudentsTree::node *temp = t;
        while(temp != nullptr){
            if(temp->student == student) {
                return temp;
            }
            temp = student < temp->student ? temp->left : temp->right;
        }
        return nullptr;
}

StudentsTree::node *StudentsTree::findByCode(StudentsTree::node *t, string studentCode) {
    StudentsTree::node *temp = t;
    while(temp != nullptr){
        if(temp->student.getStudentCode() == studentCode) {
            return temp;
        }

        temp = stol(studentCode) < stol(temp->student.getStudentCode()) ? temp->left : temp->right;
    }
    return nullptr;
}

//Loops
//1 - All students in a certain class
//2 - All students that have more than X class
//3 - All students in a year

void StudentsTree::clearBuffStudent() {
    buffStudent.clear();
}

void StudentsTree::allStudentsInAClass(StudentsTree::node *t, Class *c) {
    if(!t) return;
    allStudentsInAClass(t->left, c);
    if(t->student.isInClass(c)) buffStudent.push_back(t->student);
    allStudentsInAClass(t->right, c);
}

void StudentsTree::moreThanXClass(StudentsTree::node *t, int x) {
    if(!t) return;
    moreThanXClass(t->left, x);
    if(t->student.getClasses().size() >= x) buffStudent.push_back(t->student);
    moreThanXClass(t->right, x);
}

void StudentsTree::allStudentsInAYear(StudentsTree::node *t, string &year) {
    if(!t) return;
    allStudentsInAYear(t->left, year);
    if(t->student.getStudentCode().substr(0,4) == year) buffStudent.push_back(t->student);
    allStudentsInAYear(t->right, year);
}

vector<Student> StudentsTree::getBuffStudent() {
    return buffStudent;
}