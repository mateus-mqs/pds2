#include <iostream>
#include <cstring>
#include "Aluno.hpp"

Aluno::Aluno(){

}

Aluno::Aluno(int matricula, char nome[20]){
    this->_matricula = matricula;
    std::strcpy(this->_nome, nome);
}

void Aluno::imprimir_dados(){
    std::cout << this->_matricula << " " << this->_nome << std::endl;
}
