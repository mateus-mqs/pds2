#include "HistoricoBovespa.hpp"

HistoricoBovespa::HistoricoBovespa(){

}

void HistoricoBovespa::inserir_cotacao(std::string sigla, std::string data, double valor){
    Cotacao novaC = Cotacao(data, valor);

    std::map<std::string, std::vector<Cotacao>>::iterator it;
    for(it = hist.begin(); it != hist.end(); it++){
        if(it->first == sigla){
            it->second.push_back(novaC);
            return;
        }
    }
    hist.insert(std::pair<std::string,std::vector<Cotacao>>(sigla,{novaC}));
    return;
}

double HistoricoBovespa::calcular_valor_medio_acao(string sigla){
    double media = 0;
    std::map<std::string, std::vector<Cotacao>>::iterator it;
    for(it = hist.begin(); it != hist.end(); it++){
        if(it->first == sigla){
            for(unsigned int i = 0; i < it->second.size(); i++){
                media += it->second[i].get_valor();
            }
            return (media /= it->second.size());
        }
    }
    return 0;
}

Cotacao* HistoricoBovespa::recuperar_cotacao_minima_acao(string sigla){
    double menor = 9999999;
    Cotacao* minimo;
    std::map<std::string, std::vector<Cotacao>>::iterator it;
    for(it = hist.begin(); it != hist.end(); it++){
        if(it->first == sigla){
            for(unsigned int i = 0; i < it->second.size(); i++){
                if(it->second[i].get_valor() < menor){
                    menor = it->second[i].get_valor();
                    minimo = &it->second[i];
                }
            }
            return minimo;
        }
    }
    return nullptr;
}

Cotacao* HistoricoBovespa::recuperar_cotacao_maxima_acao(string sigla){
    double maior = -1;
    Cotacao* maximo;
    std::map<std::string, std::vector<Cotacao>>::iterator it;
    for(it = hist.begin(); it != hist.end(); it++){
        if(it->first == sigla){
            for(unsigned int i = 0; i < it->second.size(); i++){
                if(it->second[i].get_valor() > maior){
                    maior = it->second[i].get_valor();
                    maximo = &it->second[i];
                }
            }
            return maximo;
        }
    }
    return nullptr;
}

void HistoricoBovespa::imprimir_estatisticas_completas(){
    std::map<std::string, std::vector<Cotacao>>::iterator it;
    for(it = hist.begin(); it != hist.end(); it++){
        std::cout << it->first << " ";
        for(unsigned int i = 0; i < it->second.size(); i++){
            std::cout << it->second[i].get_valor() << " ";
        }
        std::cout << "| ";
        std::cout << recuperar_cotacao_minima_acao(it->first)->get_valor() << " ";
        std::cout << recuperar_cotacao_maxima_acao(it->first)->get_valor() << " ";
        std::cout << fixed << setprecision(2) << calcular_valor_medio_acao(it->first) << std::endl;
    }
}