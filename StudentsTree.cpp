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

bool StudentsTree::contains(StudentsTree::node *t, Student &student) {
        while(t != nullptr){
            if(t->student == student) return true;
            t = student < t->student ? t->left : t->right;
        }
        return false;
}

void StudentsTree::print(const node *t){
    if(!t) return;
    print(t->left);
    t->student.print();
    cout << endl;
    print(t->right);
}