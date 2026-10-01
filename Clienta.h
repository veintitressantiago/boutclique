#pragma once

#include <ncurses.h>
#include <iostream>
#include <string> 

#include "Prenda.h"

using namespace std;

class Clienta
{

public: 
Clienta(string nombre = "Desconocida", string estilo = "Casual", int presupuesto = 1000, int satisfaccion = 50);

//metodos publicos
void draw(WINDOW* win, int opcion);
void setup();
void update();
bool evaluarPrenda(const Prenda& prendaElegida);

string getNombre() const { return m_nombre; }
string getEstilo() const { return m_estilo; }
int getPresupuesto() const { return m_presupuesto; }
int getSatisfaccion() const { return m_satisfaccion; }

private:
//atributos  privadas
string m_nombre; 
string m_estilo;
int m_presupuesto;
int m_satisfaccion;


};
