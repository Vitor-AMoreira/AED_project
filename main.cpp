#include <iostream>
#include <fstream>
#include <string>

#include "Student.h"
#include "Class.h"
#include "ReadStudent.h"
#include "ReadClasses.h"

using namespace std;

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

    //Class(string ucCode, string classCode, string weekday, float startHour, float duration, string type);

    ReadClasses readClasses;

    return 0;
}
