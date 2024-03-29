#ifndef FIGURAS_H
#define FIGURAS_H

#include <math.h>
/**
 * \class Figure
 *
 * \brief Esta eh a interface de qualquer figura desta aplicacao. O que
 * caracteriza uma figura eh a habilidade de decidir se ela contem ou nao um
 * ponto. Note que figuras e pontos sao representados sempre em duas dimensoes.
 */
class Figure {
  public:
    /**
     * \brief Este metodo determina se o ponto (x, y) esta contido na figura.
     * \param x Coordenada X do ponto.
     * \param y Coordenada Y do ponto.
     */
    virtual bool contains(double x, double y) const = 0;
    /**
     * \brief A classe prove um destrutor virtual, pois ela foi feita para ser
     * implementada por outras classes, via heranca.
     */
    virtual ~Figure() {}
};

/**
 * \class Rectangle
 *
 * \brief Um retangulo eh uma figura unicamente determinada por um canto
 * inferior esquerdo, mais largura e altura.
 */
class Rectangle: public Figure {
  public:
    /**
     * \brief Metodo construtor que cria um retangulo com canto inferior
     * esquerdo na coordenada (xx, yy), largura igual a ll e altura igual ao
     * parametro aa.
     * \param xx Canto esquerdo do retangulo
     * \param yy Canto inferior do relangulo
     * \param ll A largura do retangulo
     * \param aa A altura do retangulo
     */
    Rectangle(double xx, double yy, double ll, double aa):
      _x(xx), _y(yy), _l(ll), _a(aa) {}
    /**
     * \brief Determina se o ponto (x, y) estah contido dentro deste retangulo.
     */
    bool contains(double x, double y) const {
        if(!((x >= _x && x <= (_x + _l))&&(y >= _y && y <= (_y + _a)))){
            return false;
        }
      return true;
    }
    const double _x; ///< Coordenada X do lado inferior-esquerdo do retangulo
    const double _y; ///< Coordenada Y do lado inferior-esquerdo do retangulo
    const double _l; ///< Largura do Retangulo
    const double _a; ///< Altura do Retangulo
};


/**
 * \class Circle
 *
 * \brief Um circulo eh uma figura determinada por um centro e um raio.
 */
class Circle: public Figure {
  public:
    /**
     * \brief Metodo contrutor que produz um circulo com centro no ponto
     * (xx, yy) e raio rr.
     * \param xx Coordenada X do centro do circulo
     * \param yy Coordenada Y do centro do circulo
     * \param rr Raio do circulo
     */
    Circle(double xx, double yy, double rr): _x(xx), _y(yy), _r(rr) {}
    /**
     * \brief Determina se o ponto (x, y) estah contido dentro deste circulo.
     */
    bool contains(double x, double y) const {
      if(!(sqrt(pow(x - _x, 2) + pow(y - _y, 2)) <= _r)){
          return false;
      }
      return true;
    }
    const double _x; ///< Coordenada X do centro do circulo
    const double _y; ///< Coordenada Y do centro do circulo
    const double _r; ///< O raio do circulo
};

class CompositeFigure: public Figure {
    public:
        CompositeFigure(const Figure& lhs, const Figure& rhs, int op): _lhs(&lhs), _rhs(&rhs), _op(op) {}

        bool contains(double x, double y) const {
            if(!_op){
                if(_lhs->contains(x,y) || _rhs->contains(x,y)){
                    return true;
                }
                return false;
            }
            if(_lhs->contains(x,y) && !_rhs->contains(x,y)){
                return true;
            }
            return false;
        }
        
        const Figure *_lhs;
        const Figure *_rhs;
        const int _op;
};

Figure* operator+(const Figure& lhs, const Figure& rhs) {
    CompositeFigure *f = new CompositeFigure(lhs, rhs, 0);
    return f;
}

Figure* operator-(const Figure& lhs, const Figure& rhs) {
    CompositeFigure *f = new CompositeFigure(lhs, rhs, 1);
    return f;
}

#endif