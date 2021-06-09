#include <iostream>
#include "BST.hpp"

NodeT* cria_aluno(Aluno aluno) {
    NodeT* aux = new NodeT;
    aux->aluno = &aluno;
    aux->esq = nullptr;
    aux->dir = nullptr;

    return aux;
}

void BST::inserir_aluno(Aluno aluno){
    if (raiz != nullptr){
        inserir_aluno_helper(raiz, aluno);
    } else {
        raiz = cria_aluno(aluno);
    }
}

void BST::inserir_aluno_helper(NodeT* n, Aluno aluno){
    if (aluno._matricula < n->aluno->_matricula){
        if (n->esq == nullptr){
            n->esq = cria_aluno(aluno);
        } else {
            inserir_aluno_helper(n->esq, aluno);
        }
    } else if (aluno._matricula > n->aluno->_matricula){
        if (n->dir == nullptr){
            n->dir = cria_aluno(aluno);
        } else {
            inserir_aluno_helper(n->dir, aluno);
        }
    }
}

void BST::imprime_arvore(NodeT* n){
    if(n == nullptr){return;}
    imprime_arvore(n->esq);
    n->aluno->imprimir_dados();
    imprime_arvore(n->dir);
}