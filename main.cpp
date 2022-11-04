#include <iostream>
#include "ReadStudent.h"
#include "ReadClasses.h"
#include "Menu.h"
#include <string>
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

    ReadClasses readClasses;
    ReadStudent readStudent;
    StudentsTree tree = readStudent.read(readClasses);

    /*
    //First question
    while(true) {
        Menu menu;

        if(menu.getLastInput() == "1") {

            //Get the input when the UCs are shown
            menu.getUcs();
            if(menu.getExit()) break;

            //Get the input when the classes are shown
            Class class_ = menu.getUcClasses(menu.getLastInput());
            if(menu.getExit()) break;

            //Get the students from the class chosen
            menu.getClassStudents(tree, class_);
            break;
        }else if(menu.getLastInput() == "2") {
            menu.getAllStudents();
            break;
        }
    }
    */
    return 0;
}
