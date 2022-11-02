#include <iostream>
#include <fstream>
#include <string>

#include "Student.h"
#include "Class.h"
#include "ReadStudent.h"
#include "ReadClasses.h"
#include "Animal.h"

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



    StudentsTree tree;

    ReadClasses readClasses;
    ReadStudent readStudent;
    readStudent.read("../schedule/students_classes.csv", readClasses);

    cout << readClasses.findClass("L.EIC023","3LEIC07").getStudentsNumber();
    //Student s1 = tree.head->student;

    //s1.print();

   /*
    Animal dog("Cachorro", 4);
    if(dog.getName() == "Cachorro") cout << "PASSOU!";

    Class c1("01","01", "01", "01", "01", "01");
    Class c2("02","02", "02", "02", "02", "02");
    Class c3("03","03", "03", "03", "03", "03");

    Student s1("01", "Victor", c1);
    Student s2("02", "Vitor", c2);
    Student s3("03", "Daniel", c3);
    Student s4("04", "Daniel", c3);
    Student s5("05", "Daniel", c3);

    StudentsTree tree;

    tree.head = tree.build(tree.head, s1);
    tree.head = tree.build(tree.head,s2);
    tree.head = tree.build(tree.head,s3);

    if(!tree.find(tree.head, s4)) tree.build(tree.head, s4);
    tree.print(tree.head);
    */
    return 0;
}
