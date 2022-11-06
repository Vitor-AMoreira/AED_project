#include <iostream>
#include "ReadStudent.h"
#include "ReadClasses.h"
#include "Menu.h"
#include <string>
#include <string.h>
#include <algorithm>
#include "Class.h"
#include "Request.h"
#include "RequestsQueue.h"
#include <map>

int main() {

    ReadClasses readClasses;
    ReadStudent readStudent;
    StudentsTree tree = readStudent.read(readClasses);

    //Start menu
    while(true) {

        //To show the main menu
        Menu menu;
        //Get a possible quit code
        if(menu.getExit()) break;

        //Enter in visualization section
        if(menu.getLastInput() == "1") {

            //To show the options to filter students
            menu.getOption();
            if(menu.getExit()) continue;

            //For the option of Filter by UCs/Classes
            if(menu.getLastInput() == "1") {
                //Show the UCs
                menu.setOrder();
                menu.getUcs();
                if(menu.getExit()) continue;
                menu.setOrder();

                //Show the classes of the chosen UC
                Class* class_ = menu.getUcClasses(menu.getLastInput(), readClasses);
                if(menu.getExit()) continue;
                menu.setOrder();

                //Show the students and number of students of the chosen UC and class
                menu.getClassStudents(tree, tree.head, class_);
                if(menu.getExit()) continue;

            } else if(menu.getLastInput() == "2"){
                //Show possible years
                menu.getYearOption();
                if(menu.getExit()) continue;
                menu.setOrder();

                //Show all students from the selected year
                menu.getStudentsByYear(tree,tree.head);
                if(menu.getExit()) continue;

            } else if(menu.getLastInput() == "3") {
                //To get the input of from how many UCs the student must have
                menu.getInputOfCountOfUcs();
                if(menu.getExit()) continue;
                menu.setOrder();

                //To show all students filtered by the count of UCs
                menu.getStudentsByCountOfUcs(tree,tree.head);
                if(menu.getExit()) continue;


            } else { continue; }

            //Show the student details
            menu.showStudentDetails(tree, tree.head);
            continue;

        }else if(menu.getLastInput() == "2") {
            //menu.getAllStudents();
            break;
        }
    }
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
    cout << "-----------------------------------" << endl;
    cout << "  Thanks for using our system :)" << endl;
    cout << "-----------------------------------" << endl;
    cout << "\n\n\n";

    return 0;
}
