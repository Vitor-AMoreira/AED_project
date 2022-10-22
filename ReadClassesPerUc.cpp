//
// Created by victo on 22/10/2022.
//

#include "ReadClassesPerUc.h"

ReadClassesPerUc::ReadClassesPerUc() {}

void ReadClassesPerUc::read(string file_name) {

    ifstream file(file_name);
    string line; string field; string delimiter = ";";
    int count = 0;

    while(getline(file,line)){
        if(count++ == 0) continue;

        int pos = 0;

        while ((pos = line.find(delimiter)) != string::npos){
            field = line.substr(0, pos);
            cout << field << "#";
            line.erase(0, pos + delimiter.length());
            if(line.find(delimiter) == string::npos) cout << line.substr(0,pos) << endl;
                //array_of_fields.push_back(line.substr(0, pos));
        }
        //Student student = Student(array_of_fields[0],array_of_fields[1],array_of_fields[2],array_of_fields[3]);
        //all_students.push_back(student);
    }
    return;
}