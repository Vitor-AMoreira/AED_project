//
// Created by victo on 22/10/2022.
//

#ifndef AED_PROJECT_STUDENTSTREE_H
#define AED_PROJECT_STUDENTSTREE_H
#include "Student.h"
#include <iostream>
using namespace std;

class StudentsTree {
    private :
        vector<Student> buffStudent;
    public :
        struct node{
            node *left;
            node *right;
            Student student;
        };
        node *head;

        StudentsTree();
        node *build(node *t, Student &student);
        node *findByObj(node *t, Student &student);
        node *findByCode(node *t, string studentCode);

        // ! BUFFCLEAR MUST PRECED THE NEXT THREE FUNCTIONS
        void clearBuffStudent();

        void allStudentsInAClass(node *t, Class *c);
        void moreThanXClass(node *t, int x);
        void allStudentsInAYear(node *t, string &year);

        vector<Student> getBuffStudent();

};


#endif //AED_PROJECT_STUDENTSTREE_H