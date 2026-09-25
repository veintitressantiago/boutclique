#include "Flecha.h"
void Flechas::setup()
{
    m_xIzquierda = 16;
    m_xDerecha = 42;
    m_y = 8;
}
void Flechas::draw() const
{
    // Esta funcion solamente dibuja las flechas ASCII.
    mvaddch(m_y, m_xIzquierda, '<');
    mvaddch(m_y, m_xDerecha, '>');
}
int Flechas::getX(SentidoFlecha sentido) const
{
    if (sentido == SentidoFlecha::IZQUIERDA)
        return m_xIzquierda;
    return m_xDerecha;
}
int Flechas::getY() const
{
    return m_y;
}

