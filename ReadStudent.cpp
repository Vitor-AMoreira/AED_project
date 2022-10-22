//
// Created by victo on 20/10/2022.
//

#include "ReadStudent.h"

ReadStudent::ReadStudent(){}

vector<Student> ReadStudent::read(string file_name){
    vector<Student> all_students;

    ifstream file(file_name);
    string line; string field; string delimiter = ";";
    int count = 0;

    while(getline(file,line)){
        if(count++ == 0) continue;

        vector<string> array_of_fields;
        int pos = 0;

        while ((pos = line.find(delimiter)) != string::npos){
            field = line.substr(0, pos);
            array_of_fields.push_back(field);
            line.erase(0, pos + delimiter.length());
            if(line.find(delimiter) == string::npos) array_of_fields.push_back(line.substr(0, pos));
        }

        //Ver na árvore binária se já existe esse Uc, caso não exista, criar o obj. Caso exista dar um push na UcAndClass
        Student student = Student(array_of_fields[0],array_of_fields[1],array_of_fields[2],array_of_fields[3]);
        //Ao inves de eu colar em all_students aqui, eu coloco na tree
        all_students.push_back(student);
    }
    return all_students;
}