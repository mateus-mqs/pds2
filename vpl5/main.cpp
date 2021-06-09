// NÃO ALTERE ESSA LINHA
#include "BST.hpp"
#include "Aluno.hpp"
#include <iostream>

int main() {
    int mat;
    char nom[20];

    BST bst;
    while(cin >> mat >> nom){
        Aluno aluno = Aluno(mat, nom);
        std::cout << aluno._matricula << aluno._nome << std::endl;
        bst.inserir_aluno(aluno);
    }
    bst.imprime_arvore(bst.raiz);
    return 0;
}