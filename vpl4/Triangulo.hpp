#include <cmath>
#include "Ponto2D.hpp"

#ifndef TRIANGULO_H
#define TRIANGULO_H

struct Triangulo {
    Ponto2D _p1;
    Ponto2D _p2;
    Ponto2D _p3;
    Triangulo(Ponto2D _p1, Ponto2D _p2, Ponto2D _p3);
    double calcular_area();
    double calcular_perimetro();
    int comparar_area(Triangulo *triangulo);
};

#endif