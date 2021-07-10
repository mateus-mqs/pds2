#include <regex>
#include <math.h>
#include <string>
#include <vector>
#include <sstream>

#include "LineProcessor.hpp"

void LinePrinter::processaLinha(const std::string &str) {
  std::cout << str << std::endl;
}

bool ContadorPopRural::linhaValida(const std::string &str) const {
  // Neste exemplo usaremos expressoes regulares para verificar se uma linha
  // eh valida ou nao.
  //
  // Esta expressao regular eh formada por cinco partes. Cada uma dessas
  // partes eh um dos tres tipos de padrao regular abaixo:
  //
  // \\w+ eh qualquer palavra com um ou mais digitos, letras e sublinhas (_)
  // \\s* eh qualquer sequencia de zero ou mais espacos (inclui tab)
  // \\d+ eh qualquer sequencia de um ou mais digitos
  std::regex regularExpr("\\w+\\s*\\d+\\s*\\d+");

  // A funcao regex_match vai retornar verdadeiro se a string str casa-se com
  // a expressao regular que acabamos de criar:
  return std::regex_match(str, regularExpr);
}

void ContadorPopRural::processaLinha(const std::string &str) {
  //
  // Em geral eh mais facil ler dados de uma string se a string eh transformada
  // em um objeto do tipo stringstream:
  std::stringstream ss(str);
  //
  // Iremos ler os dados da string nestas tres variaveis abaixo:
  std::string nomePais;
  unsigned populacao, percUrbana;
  //
  // Como sabemos que a linha contem string int int, podemos fazer a leitura
  // facilmente usando o operador de streaming:
  ss >> nomePais >> populacao >> percUrbana;
  //
  // Note que precisamos arredondar o valor que serah impresso. O arredondamento
  // serah feito via a funcao floor. Ou seja, decimais serao sempre
  // arredondados para baixo:
  unsigned popRural = floor(populacao - (populacao * (percUrbana/100.0)));
  //
  // Uma vez encontrados os valores que precisam ser impressos, seguimos o
  // modelo do enunciado do exercicio:
  std::cout << popRural << " pessoas vivem no campo no " << nomePais <<
    std::endl;
}

bool ContadorNumNaturais::linhaValida(const std::string &str) const {
  for (int i = 0; i < str.size(); i++){
      if((str[i] < 48) || (str[i] > 57) || (str[i] != 32) || (str[i] != 10)){
          return false;
      }
  }
  return true;
}

void ContadorNumNaturais::processaLinha(const std::string &str) {
    std::string aux;
    int num = 0;
    for (int i = 0; i < str.size(); ++i){
        if(str[i] != 32){
            aux.push_back(str[i]);
        } else {
            num += stoi(aux);
            aux = "";
        }
    }
    num += stoi(aux);
    std::cout << num << std::endl;
}

bool LeitorDeFutebol::linhaValida(const std::string &str) const {
    int aux = 0;
    for (int i = 0; i < str.size(); ++i){
        if(str[i] == 32){
            ++aux;
        } else if(!((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122) || (str[i] >= 48 && str[i] <= 57)) || str[i] != 10){
            return false;
        }
    }
    if(aux != 3){
        return false;
    }
    return true;
}

void LeitorDeFutebol::processaLinha(const std::string &str) {
    std::vector<std::string> aux = {"", "", "", ""};
    unsigned int gol1, gol2, j;
    for (int i = 0; i < str.size(); ++i){
        if(str[i] != 32){
            aux[j].push_back(str[i]);
        } else {
            ++j;
        }
    }
    gol1 = stoi(aux[1]); gol2 = stoi(aux[3]);
    if(gol1 > gol2){
        std::cout << "Vencedor: " << aux[0] << std::endl;
    } else if (gol1 < gol2){
        std::cout << "Vencedor: " << aux[2] << std::endl;
    } else {
        std::cout << "Empate" << std::endl;
    }
}

void ContadorDePalavras::processaLinha(const std::string &str) {
    int num = 1;
    for(int i = 0; i < str.size(); ++i){
        if(str[i] == 32){
            ++num;
        }
    }
  std::cout << num << std::endl;
}

bool InversorDeFrases::linhaValida(const std::string &str) const {
    for (int i = 0; i < str.size(); ++i){
        if(!((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)) || str[i] != 10){
            return false;
        }
    }
    return true;
}

void InversorDeFrases::processaLinha(const std::string &str) {
  int tam = str.size();
  std::string aux = "";
  for(int i = 0; i < tam; i++){
      aux[i] = str[tam-i-1];
  } 
  std::cout << aux << std::endl;
}

bool EscritorDeDatas::linhaValida(const std::string &str) const {
  std::string dateFormat = "\\s*\\d\\d?/\\d\\d?/\\d{4}";
  // TODO: Implemente este metodo
  // Note que você pode usar uma expressao regular como:
  // "\\s*\\d\\d?/\\d\\d?/\\d{4}" para saber se a linha eh valida:
  return false;
}

void EscritorDeDatas::processaLinha(const std::string &str) {
  // TODO: Implemente este metodo:
  // Lembre-se que as iniciais dos meses sao:
  // "Jan", "Fev", "Mar", "Abr", "Mai", "Jun", "Jul", "Ago", "Set", "Out",
  // "Nov", e "Dez".
  std::cout << "Imprime algo aqui!" << std::endl;
}