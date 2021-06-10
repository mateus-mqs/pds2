#ifndef BST_H
#define BST_H

#include <iostream>
#include "Aluno.hpp"
using namespace std;

struct NodeT {
    Aluno aluno;
    NodeT* esq;
    NodeT* dir;
};

struct BST {
    NodeT* raiz = nullptr;
    void inserir_aluno_helper(NodeT* raiz, Aluno aluno);
    void inserir_aluno(Aluno aluno);
    Aluno* procurar_aluno(int mat);
    Aluno* procurar_aluno(int mat, NodeT* n);
    void imprimir_arvore();
    void imprimir_arvore(NodeT* n);
};

#endif