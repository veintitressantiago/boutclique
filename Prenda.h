#pragma once

#include <string>
#include <vector>

enum class CategoriaPrenda
{
    VESTIDOS,
    ZAPATOS,
    PARTES_DE_ABAJO,
    PARTES_DE_ARRIBA
};

class Prenda
{
public:
    Prenda(std::string nombre, std::string estilo, std::string color, int precio, CategoriaPrenda categoria, std::vector<std::string> ascii);

    void draw(int y, int x) const;

    std::string getNombre() const { return m_nombre; }
    std::string getEstilo() const { return m_estilo; }
    std::string getColor() const { return m_color; }
    int getPrecio() const { return m_precio; }
    CategoriaPrenda getCategoria() const { return m_categoria; }
    const std::vector<std::string>& getAscii() const { return m_ascii; }
    
    int getAlto() const;
    int getAncho() const;

private:
    std::string m_nombre;
    std::string m_estilo;
    std::string m_color;
    int m_precio;
    CategoriaPrenda m_categoria;
    std::vector<std::string> m_ascii;
};
