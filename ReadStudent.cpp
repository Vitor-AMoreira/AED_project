//
// Created by victo on 20/10/2022.
//

#include "ReadStudent.h"

ReadStudent::ReadStudent(){}

void ReadStudent::read(string file_name) {

    StudentsTree tree;

    ifstream file(file_name);
    string line;
    string field;
    string delimiter = ";";
    int count = 0;

    while (getline(file, line)) {
        if (count++ == 0) continue;

        vector<string> array_of_fields;
        int pos = 0;

        while ((pos = line.find(delimiter)) != string::npos) {
            field = line.substr(0, pos);
            array_of_fields.push_back(field);
            line.erase(0, pos + delimiter.length());
            if (line.find(delimiter) == string::npos) array_of_fields.push_back(line.substr(0, pos));
        }
        //Creating an obj for each interation
        Student student(array_of_fields[0], array_of_fields[1], array_of_fields[2], array_of_fields[3]);
        if (tree.head == nullptr) tree.head = tree.build(tree.head, student); //Case if the tree is empty
        else if (tree.contains(tree.head, student)) {
            continue; //If already contains student, go to next interation
        } else tree.build(tree.head, student); //If students isnt present, add it
    }
    tree.print(tree.head);
}