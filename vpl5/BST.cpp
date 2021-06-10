#include <iostream>
#include "BST.hpp"

NodeT* cria_aluno(Aluno aluno) {
    NodeT* aux = new NodeT;
    aux->aluno = aluno;
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
    if (aluno.matricula < n->aluno.matricula){
        if (n->esq == nullptr){
            n->esq = cria_aluno(aluno);
        } else {
            inserir_aluno_helper(n->esq, aluno);
        }
    } else if (aluno.matricula > n->aluno.matricula){
        if (n->dir == nullptr){
            n->dir = cria_aluno(aluno);
        } else {
            inserir_aluno_helper(n->dir, aluno);
        }
    }
}

Aluno* BST::procurar_aluno(int mat){
    return procurar_aluno(mat, this->raiz);
}

Aluno* BST::procurar_aluno(int mat, NodeT* n){
    if(mat == n->aluno.matricula){
        return &n->aluno;
    } else if (mat < n->aluno.matricula){
        if (n->esq == nullptr){
            return nullptr;
        } else {
            return procurar_aluno(mat, n->esq);
        }
    } else if (mat > n->aluno.matricula){
        if (n->dir == nullptr){
            return nullptr;
        } else {
            return procurar_aluno(mat, n->dir);
        }
    }
    return nullptr;
}

void BST::imprimir_arvore(){
    imprimir_arvore(this->raiz);
}

void BST::imprimir_arvore(NodeT* n){
    if(n == nullptr){return;}
    imprimir_arvore(n->esq);
    n->aluno.imprimir_dados();
    imprimir_arvore(n->dir);
}