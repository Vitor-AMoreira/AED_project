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

        //Class c = ReadClasses::findClass(array_of_fields[2], array_of_fields[3]);
        //Criar um atributo e um método que coloquem o estudante nessa classe. Pode ser simplesmente colocar o Código
        //de estudante
        //Student student(array_of_fields[0], array_of_fields[1], c);
        StudentsTree::node *temp;

        if (tree.head == nullptr) tree.head = tree.build(tree.head, student); //Case if the tree is empty
        else if ((temp = tree.find(tree.head, student)) != nullptr) {
            temp->student.pushClass(c);
        } else tree.build(tree.head, student); //If students isnt present, add it
    }
}