#ifndef BST_H
#define BST_H

#include <iostream>
#include "Aluno.hpp"
using namespace std;

struct NodeT {
    Aluno *aluno;
    NodeT* esq;
    NodeT* dir;
};

struct BST {
    NodeT* raiz = nullptr;
    void inserir_aluno_helper(NodeT* raiz, Aluno aluno);
    void inserir_aluno(Aluno aluno);
    void imprime_arvore(NodeT* n);
};

#endif