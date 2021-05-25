#include "Triangulo.hpp"

Triangulo::Triangulo(Ponto2D p1, Ponto2D p2, Ponto2D p3){
    _p1 = p1;
    _p2 = p2;
    _p3 = p3;
}

double Triangulo::calcular_area(){
    double a = _p1.calcular_distancia(&_p2);
    double b = _p2.calcular_distancia(&_p3);
    double c = _p3.calcular_distancia(&_p1);
    double p = (a+b+c)/2;
    double area = sqrt(p*(p-a)*(p-b)*(p-c));
    return area;
}

double Triangulo::calcular_perimetro(){
    double a = _p1.calcular_distancia(&_p2);
    double b = _p2.calcular_distancia(&_p3);
    double c = _p3.calcular_distancia(&_p1);
    double p = (a+b+c);
    return p;
}

int Triangulo::comparar_area(Triangulo *triangulo){
    if(this->calcular_area() < triangulo->calcular_area()){
        return -1;
    } else if (this->calcular_area() == triangulo->calcular_area()){
        return 0;
    } else {
        return 1;
    }
}