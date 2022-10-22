#include <iostream>
#include <fstream>
#include <string>

#include "Student.h"
#include "ReadStudent.h"
#include "ReadClassesPerUc.h"

int main() {

    Student s1("0", "Victor Careca", "AED", "001");
    Student s2("1", "Victor Morais", "AED", "001");


    if(s1 == s2) cout << "Iguais!";
    else if(s1 > s2) cout << "Careca é maior!";
    else cout << "Morais tem a moral!";


    /*Para testar a função read classes
     *
     *
    ReadClassesPerUc readclassesperuc;
    readclassesperuc.read("../schedule/classes_per_uc.csv");
     */

    /*
    //Para testar o ReadStudent

    ReadStudent readStudent;
    string file_name = "../schedule/students_classes.csv";
    vector<Student> test = readStudent.read(file_name);
    test[0].print();
    */

    return 0;
}
