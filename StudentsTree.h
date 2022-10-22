//
// Created by victo on 22/10/2022.
//

#ifndef AED_PROJECT_STUDENTSTREE_H
#define AED_PROJECT_STUDENTSTREE_H
#include "Student.h"

class StudentsTree {
    public :
        struct students_tree{
            students_tree *left;
            students_tree *right;
            Student student;
        };

        StudentsTree();
        students_tree *build(students_tree *t, Student student);
        bool contains(const students_tree *t, Student student);
};


#endif //AED_PROJECT_STUDENTSTREE_H