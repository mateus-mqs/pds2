#pragma once

#include <cassert>
#include <vector>
#include <algorithm>

// Define um arranjo de qualquer Tipo cujos índices variam em
// qualquer intervalo, inclusive negativos.
template <class Tipo> 
class Arranjo {
  public:
    // Cria um arranjo cujos índices variam de 'inicio' até 'fim'.
    // PRECONDIÇÃO: fim >= inicio.
    Arranjo(int inicio, int fim);

    // Altera o valor do índice i.
    // PRECONDIÇÃO: i está dentro do intervalo de índices do vetor.
    void atribuir(int i, Tipo valor);

    // Retorna o valor do índice i.
    // PRECONDIÇÕES: 
    // (1) i está dentro do intervalo de índices do vetor.
    // (2) i foi inicializando anteriormente.
    Tipo valor(int i) const; 
  
  private:
    int inicio_;  // Primeiro índice válido do arranjo.
    int fim_;  // Último índice válido do arranjo.
    std::vector<Tipo> elementos_;  // Elementos do arranjo.
    std::vector<Tipo> indices_;
};

// DEFINIÇÃO DAS CLASSES DE EXCEÇÃO.

struct ExcecaoIntervaloVazio {
  // Completar. Vide main.cpp.
  int inicio;
  int fim;
};

struct ExcecaoIndiceInvalido {
  // Completar. Vide main.cpp.
  int inicio;
  int fim;
  int indice;
};

struct ExcecaoIndiceNaoInicializado {
  // Completar. Vide main.cpp.
  int indice;
};

// IMPLEMENTAÇÃO DOS MÉTODOS DA CLASSE.

template <class Tipo> 
Arranjo<Tipo>::Arranjo(int inicio, int fim) : 
    inicio_(inicio), 
    fim_(fim) {
        if(!(inicio_ <= fim_)){
            throw ExcecaoIntervaloVazio{inicio_, fim_};
        }
  elementos_.resize(fim - inicio + 1);
}

template <class Tipo> 
void Arranjo<Tipo>::atribuir(int i, Tipo valor) {
    if(!(inicio_ <= i && i <= fim_)){
        throw ExcecaoIndiceInvalido{inicio_, fim_, i};
    }
    indices_.push_back(i);
  int j = i - inicio_;
  elementos_[j] = valor;
}

template <class Tipo> 
Tipo Arranjo<Tipo>::valor(int i) const { 
    if(!(inicio_ <= i && i <= fim_)){
        throw ExcecaoIndiceInvalido{inicio_, fim_, i};
    }
    if(!(std::find(indices_.begin(), indices_.end(), i) != indices_.end())){
        throw ExcecaoIndiceNaoInicializado{i};
    }
  int j = i - inicio_;     
  return elementos_[j];
}