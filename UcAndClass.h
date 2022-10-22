//
// Created by victo on 22/10/2022.
//

#ifndef AED_PROJECT_UCANDCLASS_H
#define AED_PROJECT_UCANDCLASS_H
#include <string>
using namespace std;

class UcAndClass {
    private :
        string uc;
        string clas;

    public :
        UcAndClass();
        UcAndClass(string uc, string clas);

        const string &getUc() const;
        void setUc(const string &uc);

        const string &getClas() const;
        void setClas(const string &clas);
};


#endif //AED_PROJECT_UCANDCLASS_H
