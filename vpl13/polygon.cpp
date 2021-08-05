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
  if(leftLimits.size() != rightLimits.size()){
    return false;
  }
  int aux = 0;
  if(leftLimits.size() != rightLimits.size()){return false;}
  for(int i = 0; i < leftLimits.size(); ++i){
    for(int j = 0; j < rightLimits.size(); ++j){
      if(leftLimits[i].contains(rightLimits[j])){
        aux=1;
      }
    }
    if(!aux){return false;};
    aux = 0;
  }
  return true;
}

bool Point::contains(const Point& p) const {
  return p.x == this->x && p.y == this->y;
}

std::ostream& operator << (std::ostream &out, const Point &p) {
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}

bool RightRectangle::contains(const Point& p) const {
  int x = this->limits[0].x;
  int y = this->limits[0].y;
  int l = this->limits[2].x - this->limits[0].x;
  int a = this->limits[2].y - this->limits[0].y;
  if(!((p.x >= x && p.x <= (x + l))&&(p.y >= y && p.y <= (y + a)))){
    return false;
  }
  return true;
}

Point::Point(int xx, int yy): x(xx), y(yy) {
  this->limits.push_back(*this);
}

RightRectangle::RightRectangle(int x0, int y0, int x1, int y1) {
  int menorX, menorY, maiorX, maiorY;
  std::vector<Point> aux;
  if(x0 <= x1) {
    menorX = x0; maiorX = x1;
  } else {
    menorX = x1; maiorX = x0;
  }
  if(y0 <= y1) {
    menorY = y0; maiorY = y1;
  } else {
    menorY = y1; maiorY = y0;
  }
  aux.push_back(Point(menorX,menorY));
  aux.push_back(Point(menorX,maiorY));
  aux.push_back(Point(maiorX,maiorY));
  aux.push_back(Point(maiorX,menorY));
  for(int i = 0; i < aux.size()-1; ++i){
    if(!(aux[i].contains(aux[i+1]))){
      limits.push_back(aux[i]);
    }
  }
  if(!(aux.front().contains(aux.back()))){
    limits.push_back(aux.back());
  }
}