//
// Created by victo on 22/10/2022.
//

#ifndef AED_PROJECT_UCANDCLASS_H
#define AED_PROJECT_UCANDCLASS_H
#include <string>
#include <vector>

using namespace std;

class Class {
    private :
        string ucCode;
        string classCode;
        string weekday;
        float startHour;
        float duration;
        string type;
        int studentsNumber = 0;

    public :
        Class(string ucCode, string classCode, string weekday, float startHour, float duration, string type);

        const string getUcCode();
        const string getClassCode();
        const string getWeekday();
        const float getStartHour();
        const float getDuration();
        const string getType();

        void addStudentsNumber();
        int getStudentsNumber();

        bool isClassBalanced(vector<Class> classes);
};


#endif //AED_PROJECT_UCANDCLASS_H
