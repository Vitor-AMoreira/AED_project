//
// Created by victo on 20/10/2022.
//

#include "ReadStudent.h"

ReadStudent::ReadStudent(){}

StudentsTree ReadStudent::read(ReadClasses &readClasses) {

    StudentsTree tree;
    StudentsTree::node *temp;

    ifstream file("../schedule/students_classes.csv");
    string line;
    string field;
    string delimiter = ";";
    int count = 0;

    vector<string> array_of_fields;

    Student student;

    while (getline(file, line)) {
        if (count++ == 0) {continue; }
        int pos = 0;

        while ((pos = line.find(delimiter)) != string::npos) {
            field = line.substr(0, pos);
            array_of_fields.push_back(field);
            line.erase(0, pos + delimiter.length());
            if (line.find(delimiter) == string::npos) array_of_fields.push_back(line.substr(0, pos));
        }


        student = Student(array_of_fields[0], array_of_fields[1],
                          readClasses.findClass(array_of_fields[2], array_of_fields[3]));

        if (tree.head == nullptr) { //Case that the tree is empty
            tree.head = tree.build(tree.head, student);
        }else if( (temp = tree.findByObj(tree.head, student)) != nullptr) {
            //Case the student already exits in the tree, so just push the class
            temp->student.pushClass(readClasses.findClass(array_of_fields[2], array_of_fields[3]));
        }else {
            //New student in the tree
            tree.head = tree.build(tree.head, student);
        }
        array_of_fields.clear();
    }
    return tree;
}