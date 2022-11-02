//
// Created by victo on 02/11/2022.
//

#include "Animal.h"

Animal::Animal(){

}

Animal::Animal(string name, int age){
    this->name = name;
    this->age = age;
}

void Animal::talk(){
    cout << "Animais não falam";
}

void Animal::print(){
    cout << this->name << " " << this->age;
}

string Animal::getName() const {
    return this->name;
}