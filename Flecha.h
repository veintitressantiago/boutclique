#pragma once
#include <ncurses.h>
enum class SentidoFlecha
{
    IZQUIERDA,
    DERECHA
};
class Flechas
{
public:
    void setup();
    void draw() const;
    int getX(SentidoFlecha sentido) const;
    int getY() const;
private:
    int m_xIzquierda = 16;
    int m_xDerecha = 42;
    int m_y = 8;
};

