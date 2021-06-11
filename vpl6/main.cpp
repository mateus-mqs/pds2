#include "Cotacao.hpp"
#include "HistoricoBovespa.hpp"
#include <iostream>
int main() {
    std::string sigla;
    std::string data;
    double valor;
    HistoricoBovespa hist;

    while(cin >> sigla >> data >> valor){
        hist.inserir_cotacao(sigla, data, valor);
    }

    hist.imprimir_estatisticas_completas();

    return 0;
}