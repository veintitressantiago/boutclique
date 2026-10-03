#include "Prenda.h"
#include <ncurses.h>

Prenda::Prenda(std::string nombre, std::string estilo, std::string color, int precio, CategoriaPrenda categoria, std::vector<std::string> ascii)
    : m_nombre(nombre), m_estilo(estilo), m_color(color), m_precio(precio), m_categoria(categoria), m_ascii(ascii)
{
}

void Prenda::draw(int y, int x) const
{
    for (size_t i = 0; i < m_ascii.size(); i++)
        mvaddstr(y + (int)i, x, m_ascii[i].c_str());
}

int Prenda::getAlto() const
{
    return (int)m_ascii.size();
}

int Prenda::getAncho() const
{
    size_t maximo = 0;
    for (const auto &linea : m_ascii)
        if (linea.size() > maximo)
            maximo = linea.size();
    return (int)maximo;
}