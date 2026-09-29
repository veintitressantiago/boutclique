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
//-----atributos privados
vector<vector<Prenda>> m_catalogo; //  matriz de prendas
int m_dinero;

public:
Tienda();

void setup(); //inicializa la matriz

const Prenda& getPrenda(int categoria, int indice) const;

void mostrarPrendaActual(int y, int x, int categoria, int indice);

int getDinero() const { return m_dinero; }
void sumarDinero(int monto) { m_dinero += monto; }
};
