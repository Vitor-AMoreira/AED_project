//
// Created by victo on 20/10/2022.
//

#include "ReadStudent.h"

ReadStudent::ReadStudent(){}

StudentsTree ReadStudent::read(string file_name, ReadClasses &readClasses) {

    StudentsTree tree;
    StudentsTree::node *temp;

    ifstream file(file_name);
    string line;
    string field;
    string delimiter = ";";
    int count = 0;

    vector<string> array_of_fields;

    Class c;
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

        temp = tree.find(tree.head, student);
        cout << "temp --->" << temp << endl;

        if (tree.head == nullptr) {
            tree.head = tree.build(tree.head, student);
        }else if( temp != nullptr) {
            cout << "Aqui";
            temp->student.pushClass(readClasses.findClass(array_of_fields[2], array_of_fields[3]));
        }else {
            cout << "As vezes aqu9=i" << endl;
            tree.head = tree.build(tree.head, student); //If students isnt present, add it
        }
        array_of_fields.clear();
    }
    return tree;
}