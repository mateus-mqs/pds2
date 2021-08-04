/**
 * Todas as tarefas deste exercicio devem ser feitas sobre esse arquivo.
 * Os metodos e operacoes marcados com a tag "TODO" devem ser editados.
 */

#include <iostream>
#include "polygon.h"

std::ostream& operator << (std::ostream &out, const Polygon &poly) {
  for (const Point& p: poly.limits) {
    out << " " << p;
  }
  return out;
}

bool operator == (const Polygon &lhs, const Polygon &rhs) {
  std::vector<Point> leftLimits = lhs;
  std::vector<Point> rightLimits = rhs;
  std::vector<Point> auxLeft;
  std::vector<Point> auxRight;
  auxLeft.push_back(leftLimits[0]);
  for(int i = 1; i < leftLimits.size()-1; ++i){
    if(!(leftLimits[i].contains(leftLimits[i+1]))){
      auxLeft.push_back(leftLimits[i]);
    }
  }
  auxRight.push_back(rightLimits[0]);
  if(!(leftLimits.front().contains(leftLimits.back()))){
    auxLeft.push_back(leftLimits.back());
  }
  for(int i = 1; i < rightLimits.size()-1; ++i){
    if(!(rightLimits[i].contains(rightLimits[i+1]))){
      auxRight.push_back(rightLimits[i]);
    }
  }
  if(!(rightLimits.front().contains(rightLimits.back()))){
    auxRight.push_back(rightLimits.back());
  }
  if(auxLeft.size() != auxRight.size()){return false;}
  int aux = 0;
  for(int i = 0; i < auxLeft.size(); ++i){
    for(int j = 0; j < auxRight.size(); ++j){
      //std::cout << auxLeft[i].x << "|" << auxLeft[i].y << " com " << auxRight[i].x << "|" << auxRight[i].y << std::endl;
      if(auxLeft[i].contains(auxRight[j])){
        aux=1;
      }
    }
    if(!aux){return false;};
    aux = 0;
  }
  return true;
  /*
  for(int i = 0; i < leftLimits.size()-1; ++i){
    if(leftLimits[i].contains(leftLimits[i+1])){
      leftLimits.erase(leftLimits.begin()+i);
    }
  }
  if(leftLimits[0].contains(leftLimits[leftLimits.size()])){
    leftLimits.erase(leftLimits.end());
  }
  for(int i = 0; i < leftLimits.size()-1; ++i){
    if(rightLimits[i].contains(rightLimits[i+1])){
      rightLimits.erase(rightLimits.begin()+i);
    }
  }
  if(rightLimits[0].contains(rightLimits[rightLimits.size()])){
    rightLimits.erase(rightLimits.end());
  }
  if(leftLimits.size() != rightLimits.size()){return false;}
  int tam = leftLimits.size();
  int aux = -1, j;
  for(int i = 0; i < tam; ++i){
    if(leftLimits[i].contains(rightLimits[0])){
      int aux = i;
    }
  }
  if(aux == -1){return false;}
  for(int i = 0; i < tam; ++i){
    j = aux+i;
    if(j >= tam){
      j = aux + i - tam;
    }
    if(!(rightLimits[i].contains(leftLimits[j]))){
      return false;
    }
  }
  return true; */
}

bool Point::contains(const Point& p) const {
  return p.x == this->x && p.y == this->y;
}

std::ostream& operator << (std::ostream &out, const Point &p) {
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}

bool RightRectangle::contains(const Point& p) const {
  for(int i = 0; i < limits.size(); ++i){
    if(limits[i].contains(p)){
      return true;
    }
  }
  return false;
}

Point::Point(int xx, int yy): x(xx), y(yy) {
}

RightRectangle::RightRectangle(int x0, int y0, int x1, int y1) {
  limits.push_back(Point(x0,y0));
  //std::cout << x0 << y0 << std::endl;
  limits.push_back(Point(x0,y1));
  //std::cout << x0 << y1 << std::endl;
  limits.push_back(Point(x1,y1));
  //std::cout << x1 << y1 << std::endl;
  limits.push_back(Point(x1,y0));
  //std::cout << x1 << y0 << std::endl;
}