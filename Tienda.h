#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Prenda.h"

using namespace std;

class Tienda
{
private:
//-----atributos privados
vector<Prenda> m_inventario;
int m_dinero;

public:
    
Tienda();
void agregarPrenda(Prenda nuevaPrenda);

void mostrarInventario(int y, int x);

int getDinero() const { return m_dinero; 
}
};
