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
        Class();
        Class(string classCode, string ucCode, string weekday, string startHour, string duration, string type);

        const string getUcCode() const;
        const string getClassCode() const;
        const string getWeekday() const;
        const float getStartHour() const;
        const float getDuration() const;
        const string getType() const;

        void addStudentsNumber();
        void decStudentsNumber();
        int getStudentsNumber() const;

        bool isClassBalanced(vector<Class> classes);
        bool areBalanced(Class *c);
};


#endif //AED_PROJECT_UCANDCLASS_H
