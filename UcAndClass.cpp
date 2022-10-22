//
// Created by victo on 22/10/2022.
//

#include "UcAndClass.h"

UcAndClass::UcAndClass(){}

UcAndClass::UcAndClass(string uc, string clas) {
    this->uc = uc; this->clas = clas;
}

const string &UcAndClass::getUc() const {
    return uc;
}
void UcAndClass::setUc(const string &uc) {
    UcAndClass::uc = uc;
}

const string &UcAndClass::getClas() const {
    return clas;
}
void UcAndClass::setClas(const std::string &clas) {
    UcAndClass::clas = clas;
}