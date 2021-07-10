#include "fila_de_prioridade.h"

FilaDePrioridade::FilaDePrioridade(): primeiro_(nullptr), tamanho_(0), lista_({}){

}

string FilaDePrioridade::primeiro() const {
    return primeiro_->nome;
}

int FilaDePrioridade::tamanho() const {
    return tamanho_;
}

bool FilaDePrioridade::vazia() const {
    return (tamanho_ == 0);
}

void FilaDePrioridade::RemoverPrimeiro(){
    lista_.pop_front();
    primeiro_ = lista_.front();
    tamanho_--;
}

void FilaDePrioridade::Inserir(int p, string s){
    tamanho_++;
    No* aux;
    aux->idade = p;
    aux->nome = s;
    if(primeiro_ == nullptr){
        lista_.push_back(aux);
        primeiro_ = lista_.front(); //???????
        return;
    }
    if(primeiro_->idade > p){
        std::list<No*>::iterator it;
        for(it=lista_.begin(); it != lista_.end(); ++it){
            if(it->idade < p){
                lista_.insert(it,aux);
            }
        }
    }
    primeiro_ = lista_.front(); //???????
    return;
}

void FilaDePrioridade::Limpar(){
    std::list<No*>::iterator it;
    for(it=lista_.begin(); it != lista_.end(); ++it){
        lista_.pop_front();
        tamanho_--;
    }
    primeiro_ = nullptr;
}
