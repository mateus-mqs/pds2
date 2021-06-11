#ifndef COTACAO_H
#define COTACAO_H

#include <string>

struct Cotacao {
    std::string data;
    double valor;

    Cotacao(std::string data, double valor);
    std::string get_data();
    double get_valor();
};

#endif