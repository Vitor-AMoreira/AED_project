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

int main() {
    //MENU
    //Gerenciar estudantes em UCS (adicionar/remover/alterar)
    //Gerenciar estudantes em turmas (adicionar/remover(alterar)
    //Alterar conjunto de turmas/UCs

    //Ordem de leitura:
    //Ler as classes e definir o vetor allClasses do ReadClasses

    //Ler os students e definir o vetor allStudents do ReadStudents

    //Com isso todos os students vão ter a lista classes das classes deles

    //Depois executa a função setStudentsNumber(ReadStudents.getAllClasses()) de cada class
    // para saber quantos alunos cada class possui



    /*
    //First question
    while(true) {
        //To show the main menu
        Menu menu;

        //Get a possible exit code
        if(menu.getExit()) continue;
        //to get the order the user want their information to be displayed
        menu.setOrder();

        if(menu.getLastInput() == "1") {

            //Show the UCs
            menu.getUcs();
            if(menu.getExit()) continue;
            menu.setOrder();

            //Show the classes of the chosen UC
            Class class_ = menu.getUcClasses(menu.getLastInput());
            if(menu.getExit()) continue;
            menu.setOrder();

            //Show the students and number of students of the chosen UC and class
            //menu.getClassStudents(tree, class_);
            break;
        }else if(menu.getLastInput() == "2") {
            //menu.getAllStudents();
            break;
        }
    }
    */
    return 0;
}
