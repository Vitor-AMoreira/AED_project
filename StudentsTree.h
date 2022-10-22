//
// Created by victo on 22/10/2022.
//

#ifndef AED_PROJECT_STUDENTSTREE_H
#define AED_PROJECT_STUDENTSTREE_H
#include "Student.h"
#include <iostream>
using namespace std;

class StudentsTree {
    public :
        struct node{
            node *left;
            node *right;
            Student &student;
        };
        node *head;

        StudentsTree();
        node *build(node *t, Student &student);
        bool contains(node *t, Student &student);
        void print(const node *t);

};


#endif //AED_PROJECT_STUDENTSTREE_H