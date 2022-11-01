//
// Created by victo on 22/10/2022.
//
#include "StudentsTree.h"

StudentsTree::StudentsTree() { head = nullptr; }

StudentsTree::node *StudentsTree::build(StudentsTree::node *t, Student &student) {
    if(t == nullptr) return new node{nullptr, nullptr, student};
    if(student < t->student) t->left = build(t->left,student);
    else if(student > t->student) t->right = build(t->right, student);
    return t;
}

StudentsTree::node *StudentsTree::find(StudentsTree::node *t, Student &student) {
        StudentsTree::node *temp = t;
        while(temp != nullptr){
            if(t->student == student) return temp;
            temp = student < temp->student ? temp->left : temp->right;
        }
        return temp;
}
/*
StudentsTree::node *StudentsTree::findByName(StudentsTree::node *t, string name) {
    StudentsTree::node *temp = t;
    while(temp != nullptr){
        if(temp->student.getStudentName() == name) return temp;
        temp = student < temp->student ? temp->left : temp->right;
    }
}
 */

void StudentsTree::print(node *t){
    if(!t) return;
    print(t->left);
    t->student.print();
    cout << endl;
    print(t->right);
}