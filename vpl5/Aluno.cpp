#include <iostream>
#include <cstring>
#include "Aluno.hpp"

Aluno::Aluno(){

}

Aluno::Aluno(int matricula, std::string nome){
    this->matricula = matricula;
    this->nome = nome;
}

void Aluno::imprimir_dados(){
    std::cout << this->matricula << " " << this->nome << std::endl;
}

