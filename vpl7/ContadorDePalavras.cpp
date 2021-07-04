#include "ContadorDePalavras.hpp"
#include <iostream>

ContadorDePalavras::ContadorDePalavras(){

}

void ContadorDePalavras::Adicionar(string s){
    std::list<Palavra>::iterator it;
    for(it=_lista_de_palavras.begin(); it != _lista_de_palavras.end(); ++it){
        if(s == it->palavra()){
            it->Incrementar();
            return;
        }
    }
    Palavra aux = Palavra(s);
    for(it=_lista_de_palavras.begin(); it != _lista_de_palavras.end(); ++it){
        if(!(it->operator<(aux))){
            _lista_de_palavras.insert(it,aux);
            return;
        }
    }
    _lista_de_palavras.push_back(aux);
}

void ContadorDePalavras::ImprimirOrdenado(){
    std::list<Palavra>::iterator it;
    for(it=_lista_de_palavras.begin(); it != _lista_de_palavras.end(); ++it){
        std::cout << it->palavra() << " " << it->ocorrencias() << std::endl;
    }
}