//
// Created by victo on 22/10/2022.
//

#include "ReadClasses.h"
#include <vector>

ReadClasses::ReadClasses() {
    ifstream file("../schedule/classes.csv");
    string line;
    string field;
    string delimiter = ";";
    int count = 0;
    int pos;

    vector<string> array_of_fields;

    while(getline(file,line)){
        if(count++ == 0) continue;

        pos = 0;
        while ((pos = line.find(delimiter)) != string::npos){
            field = line.substr(0, pos);
            array_of_fields.push_back(field);
            line.erase(0, pos + delimiter.length());
            if(line.find(delimiter) == string::npos) array_of_fields.push_back(line.substr(0,pos));
        }

        Class class_(array_of_fields[0], array_of_fields[1], array_of_fields[2], array_of_fields[3], array_of_fields[4], array_of_fields[5]);
        allClasses.push_back(class_);
        array_of_fields.clear();
    }

}

vector<Class> ReadClasses::getAllClasses() {
    return this->allClasses;
}

Class ReadClasses::findClass(string ucCode, string classCode) {
    for(Class c: this->allClasses) {
        if (c.getUcCode() == ucCode && c.getClassCode() == classCode) {
            return c;
        }
    }
    return Class("01","01","01","01","01","01");
}
