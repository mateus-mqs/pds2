#ifndef ALUNO_H
#define ALUNO_H

struct Aluno {
    int _matricula;
    char _nome[20];
    Aluno();
    Aluno(int _matricula, char _nome[]);
    void imprimir_dados();
};

#endif