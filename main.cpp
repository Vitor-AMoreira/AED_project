#include <iostream>
#include "ReadStudent.h"
#include "ReadClasses.h"

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

    tree = readStudent.read(readClasses);

    /*
      202061612 Aristides L.EIC013 2LEIC10
      202061612 Aristides L.EIC021 3LEIC10
      202061612 Aristides L.EIC022 3LEIC08
      202061612 Aristides L.EIC023 3LEIC11
      202061612 Aristides L.EIC025 3LEIC10
     */

    Student aristides = tree.findByCode(tree.head, "202061612")->student;
    aristides.pushClass(readClasses.findClass("L.EIC013", "2LEIC10"));

    return 0;
}
