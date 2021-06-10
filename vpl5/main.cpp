// NÃO ALTERE ESSA LINHA
#include "BST.hpp"
#include "Aluno.hpp"
#include <iostream>
#include "avaliacao_basica_bst.hpp"

int main() {
    avaliacao_basica();

    int mat;
    string nom;
    BST bst;

    while(cin >> mat >> nom){
        Aluno aluno = Aluno(mat, nom);
        bst.inserir_aluno(aluno);
    }

    bst.imprimir_arvore(bst.raiz);

    return 0;
}