//
// Created by victo on 22/10/2022.
//

#include "StudentsTree.h"

StudentsTree::StudentsTree() {}

StudentsTree::students_tree *StudentsTree::build(StudentsTree::students_tree *t, Student student) {
    if(t == nullptr) return new students_tree{nullptr, nullptr, student};
    if()
}