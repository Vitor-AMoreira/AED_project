//
// Created by victo on 22/10/2022.
//

#include "ReadClasses.h"
#include <string>
#include <vector>

#include "Class.h"

ReadClasses::ReadClasses() {
    ifstream file("../schedule/classes.csv");
    string line;
    string field;
    string delimiter = ";";
    int count = 0;

    while(getline(file,line)){
        if(count++ == 0) continue;
        vector<string> array_of_fields;
        int pos = 0;
        cout << line << endl;
        while ((pos = line.find(delimiter)) != string::npos){
            field = line.substr(0, pos);
            array_of_fields.push_back(field);
            line.erase(0, pos + delimiter.length());
            //if(line.find(delimiter) == string::npos) cout << line.substr(0,pos) << endl;
        }

        Class class_ = Class(array_of_fields[0],array_of_fields[1],array_of_fields[2],array_of_fields[3],array_of_fields[4],array_of_fields[5]);
        allClasses.push_back(class_);
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