#pragma once

#include <string>
#include <vector>

using namespace std;

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
    Prenda(string nombre,string estilo,string color, int precio, CategoriaPrenda categoria,vector<string> ascii);

    void draw(int y, int x) const;

    string getNombre() const { return m_nombre; }
    string getEstilo() const { return m_estilo; }
    string getColor() const { return m_color; }
    int getPrecio() const { return m_precio; }
    CategoriaPrenda getCategoria() const { return m_categoria; }
    const vector<string>& getAscii() const { return m_ascii; }
    
    int getAlto() const;
    int getAncho() const;

private:
    string m_nombre;
    string m_estilo;
    string m_color;
    int m_precio;
    CategoriaPrenda m_categoria;
    vector<string> m_ascii;
};
