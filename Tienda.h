#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Prenda.h"
#include "Flecha.h"

using namespace std;

class Tienda
{
private:
    vector<vector<Prenda>> m_catalogo;
    int m_dinero;

public:
    Tienda();

    void setup();

    const Prenda &getPrenda(int categoria, int indice) const;

    void mostrarPrendaActual(int y, int x, int categoria, int indice);

    int getDinero() const { return m_dinero; }
    void sumarDinero(int monto) { m_dinero += monto; }
};
