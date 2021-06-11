#include "Cotacao.hpp"

Cotacao::Cotacao(std::string data, double valor){
    this->data = data;
    this->valor = valor;
}

std::string Cotacao::get_data(){
    return this->data;
}

double Cotacao::get_valor(){
    return this->valor;
}