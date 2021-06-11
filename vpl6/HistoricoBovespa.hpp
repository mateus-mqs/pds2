#ifndef HISTORICOBOVESPA_H
#define HISTORICOBOVESPA_H

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <iomanip>
#include "Cotacao.hpp"

using namespace std;

struct HistoricoBovespa{
    map<std::string, std::vector<Cotacao>> hist;

    HistoricoBovespa();
    void inserir_cotacao(string sigla, string data, double valor);
    double calcular_valor_medio_acao(string sigla);
    Cotacao* recuperar_cotacao_maxima_acao(string sigla);
    Cotacao* recuperar_cotacao_minima_acao(string sigla);
    void imprimir_estatisticas_completas();
};

#endif