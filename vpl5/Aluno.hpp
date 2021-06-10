#ifndef ALUNO_H
#define ALUNO_H

#include <string>

struct Aluno {
    int matricula;
    std::string nome;
    Aluno();
    Aluno(int matricula, std::string nome);
    void imprimir_dados();
};

#endif