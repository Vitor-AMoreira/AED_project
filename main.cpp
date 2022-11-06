#include <iostream>
#include "ReadStudent.h"
#include "ReadClasses.h"
#include "Menu.h"
#include <string>
#include "Class.h"
#include "RequestsQueue.h"

int main() {

    ReadClasses readClasses;
    ReadStudent readStudent;
    StudentsTree tree = readStudent.read(readClasses);

    //Create the queue of requests
    RequestsQueue queue(tree,readClasses);

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

            //Option of Filter by UCs/Classes
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

            // Option of filter by student year
            } else if(menu.getLastInput() == "2"){
                //Show possible years
                menu.getYearOption();
                if(menu.getExit()) continue;
                menu.setOrder();

                //Show all students from the selected year
                menu.getStudentsByYear(tree,tree.head);
                if(menu.getExit()) continue;

            // Option of filter by a minimum quantity of UCs
            } else if(menu.getLastInput() == "3") {
                //To get the input of from how many UCs the student must have
                menu.getInputOfCountOfUcs();
                if(menu.getExit()) continue;
                menu.setOrder();

                //To show all students filtered by the count of UCs
                menu.getStudentsByCountOfUcs(tree,tree.head);
                if(menu.getExit()) continue;

            //To see details about a specific student
            } else if(menu.getLastInput() == "4") {

                menu.getStudentCode();
                if(menu.getExit()) continue;

                menu.showStudentDetails(tree, tree.head);
                if(menu.getExit()) continue;
            }
            else { continue; }

            //Show the student details
            menu.showStudentDetails(tree, tree.head);
            continue;

        //To change any UC/Classes of a student
        }else if(menu.getLastInput() == "2") {

            //Get the code of student they want to change
            menu.getStudentCode();
            if(menu.getExit()) continue;

            //Show student details and show options to add or remove UC/Class
            Student student = menu.showStudentDetailsToChange(tree, tree.head);
            if(menu.getExit()) continue;

            //Add/Remove UC/Class
            menu.makeChanges(readClasses, student, queue, tree, tree.head);
            if(menu.getExit()) continue;
        } else if(menu.getLastInput() == "3") {

            //To get the number of new requests
            int newRequests = queue.getSize();

            //To save in csv file all requests of the queue
            queue.upload();

            cout << "All your changes were saved" << endl;
            cout << "Number of new requests: " << newRequests << endl;

        } else if(menu.getLastInput() == "4") {
            //To read the csv of saved requests
            queue.download();

            if(queue.getSize() == 0) {
                cout << "No requests to apply!" << endl;
            }

            //To execute all requests in the queue
            while(queue.getSize() > 0) {
                queue.pop();
            }
        } else {
            cout << "Invalid input!" << endl;
        }
    }
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
    cout << "-----------------------------------" << endl;
    cout << "  Thanks for using our system :)" << endl;
    cout << "-----------------------------------" << endl;
    cout << "\n\n\n";

    return 0;
}
