//
// Created by victo on 02/11/2022.
//

#ifndef AED_PROJECT_ANIMAL_H
#define AED_PROJECT_ANIMAL_H

#include <iostream>

using namespace std;

class Animal {
    public :
        string name;
        int age;
        Animal();
        Animal(string name, int age);
        void talk();
        void print();
        string getName() const;
};


#endif //AED_PROJECT_ANIMAL_H
