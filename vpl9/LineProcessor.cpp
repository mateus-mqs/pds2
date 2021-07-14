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
      if((str[i] < 48) || (str[i] > 57)){
          if((str[i] == 32) || (str[i] == 10)){
              continue;
          }
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
    std::string dateFormat = "\\s*[a-zA-Z]+\\s*[0-9]+\\s*[a-zA-Z]+\\s*[0-9]+\\s*";
    std::regex regularExpr(dateFormat);
    std::sregex_iterator it(str.begin(), str.end(), regularExpr);
    std::smatch encontrado = *it;
    if(encontrado.empty()){return false;}
    else if(encontrado.str() != str){return false;}
    return true;
}

void LeitorDeFutebol::processaLinha(const std::string &str) {
    std::vector<std::string> aux = {"", "", "", ""};
    std::string aux1 = "";
    int gol1, gol2, j = 0;
    for (int i = 0; i < str.size(); ++i){
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9')){
            aux1.push_back(str[i]);
        }
    }
    aux[0].push_back(aux1[0]);
    for (int i = 1; i < aux1.size(); ++i){
        if((((aux1[i-1] >= 'a' && aux1[i-1] <= 'z') || (aux1[i-1] >= 'A' && aux1[i-1] <= 'Z')) && (aux1[i] >= '0' && aux1[i] <= '9'))
        || (((aux1[i] >= 'a' && aux1[i] <= 'z') || (aux1[i] >= 'A' && aux1[i] <= 'Z')) && (aux1[i-1] >= '0' && aux1[i-1] <= '9'))){
            j++;
        }
        aux[j].push_back(aux1[i]);
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
    if(str.front() == 32){--num;}
    for(int i = 0; i < str.size(); ++i){
        if(str[i] == 32){
            ++num;
        }
    }
    std::cout << num << std::endl;
}

bool InversorDeFrases::linhaValida(const std::string &str) const {
    for (int i = 0; i < str.size(); ++i){
        if(!((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122) || (str[i] == 32) || (str[i] == 10))){
            return false;
        }
    }
    return true;
}

void InversorDeFrases::processaLinha(const std::string &str) {
    std::vector<std::string> aux = {""};
    std::vector<std::string> aux1 = {};
    std::string str1 = {};
    int j = 0;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == 32){
            j++;
            aux.push_back("");
        } else {
            aux[j].push_back(str[i]);
        }
    }
    for(int i = 0; i < aux.size(); i++){
        aux1.push_back("");
        aux1[i] = aux[aux.size()-1-i];
    }
    for(int i = 0; i < aux1.size(); i++){
        for(int j = 0; j < aux1[i].size(); j++){
            str1.push_back(aux1[i][j]);
        }
        str1.push_back(' ');
    }
    std::cout << str1 << std::endl;
}

bool EscritorDeDatas::linhaValida(const std::string &str) const {
    std::string dateFormat = "\\s*\\d\\d?/\\d\\d?/\\d{4}";
    std::regex regularExpr(dateFormat);
    std::sregex_iterator it(str.begin(), str.end(), regularExpr);
    std::smatch encontrado = *it;
    if(encontrado.empty()){return false;}
    else if (encontrado.str() != str){
        return false;
    }
    return true;
}

void EscritorDeDatas::processaLinha(const std::string &str) {
    std::string aux = "";
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '/'){
            aux.push_back(str[i+1]);
            if(str[i+2] != '/'){aux.push_back(str[i+2]);}
            break;
        }
    }
    if (stoi(aux) == 1){std::cout << "Jan" << std::endl;}
    else if (stoi(aux) == 2) {std::cout << "Fev" << std::endl;}
    else if (stoi(aux) == 3) {std::cout << "Mar" << std::endl;}
    else if (stoi(aux) == 4) {std::cout << "Abr" << std::endl;}
    else if (stoi(aux) == 5) {std::cout << "Mai" << std::endl;}
    else if (stoi(aux) == 6) {std::cout << "Jun" << std::endl;}
    else if (stoi(aux) == 7) {std::cout << "Jul" << std::endl;}
    else if (stoi(aux) == 8) {std::cout << "Ago" << std::endl;}
    else if (stoi(aux) == 9) {std::cout << "Set" << std::endl;}
    else if (stoi(aux) == 10) {std::cout << "Out" << std::endl;}
    else if (stoi(aux) == 11) {std::cout << "Nov" << std::endl;}
    else if (stoi(aux) == 12) {std::cout << "Dez" << std::endl;}
}