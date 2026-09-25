#include "Tienda.h"
#include <ncurses.h>

Tienda::Tienda() 
{
    m_dinero = 0;
}

void Tienda::mostrarInventario(int y, int x) 
{

if (m_inventario.empty()) {
        mvprintw(y + 1, x, "El inventario esta vacio.");
        return;
    }

for (size_t i = 0; i < m_inventario.size(); i++) {
        mvprintw(y + 2 + i, x, "%d) %s [%s] - $%d", 
            (int)i + 1, 
            m_inventario[i].getNombre().c_str(), 
            m_inventario[i].getEstilo().c_str(), 
            m_inventario[i].getPrecio());
    }

}