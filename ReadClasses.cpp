//
// Created by victo on 22/10/2022.
//

#include "ReadClasses.h"
#include <string>
#include <list>

#include "Class.h"

ReadClasses::ReadClasses(string file_name) {

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
}

vector<Class> ReadClasses::getAllClasses() {
    return this->allClasses;
}

Class ReadClasses::findClass(string ucCode, string classCode) {
    for(Class c: allClasses) {
        if(c.getUcCode() == ucCode && c.getClassCode() == classCode) {
            return c;
        }
    }
}