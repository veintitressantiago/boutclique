#include "Tienda.h"
#include <ncurses.h>

Tienda::Tienda() 
{
    m_dinero = 0;
}

void Tienda::setup() {

        using C = CategoriaPrenda;

m_catalogo = {
    {
        Prenda("Vestido elegante", "Elegante", "Negro", 900, C::VESTIDOS,
            {" /\\ ", "/##\\", "/__\\ "}),

        Prenda("Vestido corto", "Casual", "Rojo", 700, C::VESTIDOS,
            {" /\\ ", "|()|", "/__\\ "}),

        Prenda("Vestido floral", "Romantico", "Rosa", 850, C::VESTIDOS,
            {" /\\ ", "|**|", "/\\/\\ "}),

        Prenda("Vestido de fiesta", "Fiesta", "Dorado", 1200, C::VESTIDOS,
            {" /\\ ", "|@@|", "/==\\ "})
    },
    {
        Prenda("Tacos muy altos", "Elegante", "Negro", 1100, C::ZAPATOS,
            {" __ ", "/_/ ", "\\__ "}),

        Prenda("Zapatillas urbanas", "Casual", "Blanco", 650, C::ZAPATOS,
            {" __ ", "/##\\", "\\___"}),

        Prenda("Botas altas", "Urbano", "Marron", 950, C::ZAPATOS,
            {" |\\ ", " |#|", "/___"}),

        Prenda("Sandalias", "Verano", "Dorado", 500, C::ZAPATOS,
            {" __ ", "\\##/", " \\/ "})
    },

        {
            Prenda("Pollera corta", "Casual", "Azul", 600,
                   C::PARTES_DE_ABAJO,
                   {"____", "\\##/", " \\/ "}),

            Prenda("Jean recto", "Urbano", "Azul", 750,
                   C::PARTES_DE_ABAJO,
                   {" || ", " || ", "/__\\"}),

            Prenda("Short de verano", "Verano", "Blanco", 450,
                   C::PARTES_DE_ABAJO,
                   {"____", "\\  /", " \\/ "}),

            Prenda("Pantalon sastrero", "Elegante", "Negro", 900,
                   C::PARTES_DE_ABAJO,
                   {" || ", "/##\\", "/__\\"})
        },

        {
            Prenda("Remera manga corta", "Casual", "Blanco", 450,
                   C::PARTES_DE_ARRIBA,
                   {" __ ", "/##\\", "\\__/"}),

            Prenda("Camisa manga larga", "Elegante", "Celeste", 800,
                   C::PARTES_DE_ARRIBA,
                   {" __ ", "|##|", "|__|"}),

            Prenda("Top", "Verano", "Rosa", 400,
                   C::PARTES_DE_ARRIBA,
                   {" __ ", "\\##/", " \\/ "}),

            Prenda("Sweater", "Abrigo", "Verde", 700,
                   C::PARTES_DE_ARRIBA,
                   {" __ ", "/@@\\", "\\__/"})
        }
 

        };
}

const Prenda& Tienda::getPrenda(int categoria, int indice) const 
{
    return m_catalogo[categoria][indice];
}

void Tienda::mostrarPrendaActual(int y, int x, int categoria, int indice) 
{

if (m_catalogo.empty()) {
        mvprintw(y + 1, x, "El catalogo esta vacio.");
        return;
    }

    const Prenda& p = m_catalogo[categoria][indice];

    p.draw(y, x);
    mvprintw(y + 6, x, "Prenda: %s", p.getNombre().c_str());
    mvprintw(y + 7, x, "Estilo: %s", p.getEstilo().c_str());
    mvprintw(y + 8, x, "Precio: %d", p.getPrecio());


}