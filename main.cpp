#include <iostream>
#include <ncurses.h>
#include <curses.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

#include "Clienta.h"
#include "Prenda.h"
#include "Cursor.h"
#include "Tienda.h"
#include "Flecha.h"



using namespace std;

//------constantes
const int ANCHO = 120;
const int ALTO = 40;
const int DELAY = 30;

//------variables globales ( estados )
bool salir = false;
bool mostrar_menu = true;
bool game_over = false;
int puntaje = 0;
WINDOW* winClienta = 0;

//----------objetos 
Tienda tienda1;
Cursor cursor1;
Clienta clienta1;
Flechas flechas1;
SentidoFlecha flechaActual = SentidoFlecha::IZQUIERDA;

int clientaElegida;
bool seleccionandoPrenda = false;
int categoriaActual = 0;
int prendaActual = 0;


//------funciones globales
void menu();
void instrucciones();
void creditos();
void setup();
void input();
void update();
void draw();
void drawCatalogo();
void gameover();


int main() 
{
	srand(time(0));

	initscr(); 
	noecho();
	curs_set(false);
	keypad(stdscr, true);

// check terminal 
	if (LINES < ALTO || COLS < ANCHO)
	{
		endwin();
		printf("La terminal tiene que tener como mínimo %dx%d\n\n", ANCHO, ALTO);
		exit(1);
	}

    int altoWin = 35; 
    int anchoWin = 53; 
    int posY = 1;
    int posX = 66;

    winClienta = newwin(altoWin, anchoWin, posY, posX);

    tienda1.setup();

//BUCLE PRINCIPAL
  while (!salir)
{
    if (mostrar_menu)
    {
      nodelay(stdscr, false);
      menu();
    }
    else if (!game_over)
    {
        nodelay(stdscr, true);
		input();
		update();
		draw();
        delay_output(DELAY);
	    }
    else {
        nodelay(stdscr, false);
        gameover();
    }
}

delay_output(DELAY); 

    if(winClienta) delwin (winClienta);
    endwin();
	return 0;
}

void menu()
{

erase();

mvprintw( 3, 45,    "BOUT(CL)IQUE");
mvprintw( 4, 45, "                                  +@@@@:           ");
mvprintw( 5, 45, "         :@@@@@=                 @@@@@@@:          ");
mvprintw( 6, 45, "        @@@@@@@@@                @@@@@@@:          ");
mvprintw( 7, 45, "        @@@@@@@@@@                -@@@@@.          ");
mvprintw( 8, 45, "        @@@@@@@@@@              -@@@@@             ");
mvprintw( 9, 45, "         +@@@@@@@@              @@@@@@@@.          ");
mvprintw(10, 45, "            @@@@@@              @@@@@@@@:          ");
mvprintw(11, 45, "        -@@@@@@@@@*             @@@@@@@@           ");
mvprintw(12, 45, "        @@@@@@@@@@*             @@@@@@@@           ");
mvprintw(13, 45, "       :@@@@@@@@@@              @@@@@@@@.          ");
mvprintw(14, 45, "       :@@@@@@@@@@              @ @@@@@@@          ");
mvprintw(15, 45, "       @@@@@@@= @@             @ =@@@@@@@@         ");
mvprintw(16, 45, "       @@@@@@@@@@-             @ @@@@@@@@@         ");
mvprintw(17, 45, "      @@@@@@@@@               #@#=@@@@@@@@@        ");
mvprintw(18, 45, "      @@@@@@@@@@               @  *@@@@@@@#        ");
mvprintw(19, 45, "      @@@@@@@@@@@*                  @@@@@@         ");
mvprintw(20, 45, "     #@@@@@@@@@@@@-                 .@@@@@         ");
mvprintw(21, 45, "      @@@@@@@@@@@@@                .@@*#@@         ");
mvprintw(22, 45, "       @@@@@@@@@@@@                @@: #@@         ");
mvprintw(23, 45, "       @@@@@@@@@@@@=              @@    @@         ");
mvprintw(24, 45, "       @@@@@@@@@@@@=              @:    @@         ");
mvprintw(25, 45, "       =@@@@-@@@@               :@=      @         ");

mvprintw(27, 58, "MENU");
mvprintw(29, 54, "1 - JUGAR");
mvprintw(32, 54, "2 - SALIR");

refresh();

char opcion = getch();

 switch (opcion)
  {
  case '1':
    mostrar_menu = false;
    setup();
    break;
  case '2':
		salir = true;
    break;
  default:
    break;
  }
}


void setup()
{
	game_over = false;
	puntaje = 0;

    tienda1.setup();

    seleccionandoPrenda = false;
    categoriaActual = 0;
    prendaActual = 0;
    flechaActual = SentidoFlecha::IZQUIERDA;

    cursor1.setup();
    flechas1.setup();
    clientaElegida = rand() % 5;

}


void input()
{
    int tecla = getch();

    // ESC
    if (tecla == 27)
    {
        if (seleccionandoPrenda)
        {
            // Volver a las cuatro categorias
            seleccionandoPrenda = false;

            cursor1.setX(
                (categoriaActual % 2 == 0) ? 15 : 45
            );

            cursor1.setY(
                (categoriaActual < 2) ? 5 : 15
            );
        }
        else
        {
            game_over = true;
        }

        return;
    }

    // Pantalla categorias
    if (!seleccionandoPrenda)
    {
        switch(tecla)
        {
        case KEY_LEFT: 
            if(categoriaActual % 2 == 1) categoriaActual--;
            break;
        
        case KEY_RIGHT:
            if(categoriaActual % 2 == 0) categoriaActual++;
            break;

        case KEY_UP:
            if(categoriaActual >= 2) categoriaActual -= 2;
            break;

        case KEY_DOWN:
            if(categoriaActual < 2) categoriaActual += 2;
            break;
        
        case KEY_ENTER:
        case '\n': 
            seleccionandoPrenda = true;
            prendaActual= 0;
            flechaActual = SentidoFlecha::IZQUIERDA;

            cursor1.setX(flechas1.getX(flechaActual));
            cursor1.setY(flechas1.getY());
            break;

        default: 
            break;
        }

        if (tecla == KEY_LEFT || tecla == KEY_RIGHT ||tecla == KEY_UP || tecla == KEY_DOWN)
        {
            cursor1.setX((categoriaActual % 2 == 0) ? 15 : 45);
           cursor1.setY((categoriaActual < 2) ? 5 : 15);  
        }

        return;
    }

    // Pantalla de una prenda con las dos flechas

    switch (tecla)
    {
        // carrusel va izq o der
       case KEY_LEFT:
        flechaActual = SentidoFlecha::IZQUIERDA;
        cursor1.setX(flechas1.getX(flechaActual));
        cursor1.setY(flechas1.getY());
        break;

        case KEY_RIGHT:
         flechaActual = SentidoFlecha::DERECHA;
         cursor1.setX(flechas1.getX(flechaActual));
         cursor1.setY(flechas1.getY());
         break;

         case KEY_ENTER:
         case '\n':
            if (flechaActual == SentidoFlecha::IZQUIERDA)
        {
            if (prendaActual == 0)
                prendaActual = 3;
            else
                prendaActual--; 
        }
        else {
            prendaActual++;
            if (prendaActual > 3)
                prendaActual = 0;
        }
        break;

         default:
        break;
    }

}

void update()
{
//logica de actualizacion
}

void drawCatalogo()
{
    if (!seleccionandoPrenda)
    {
        mvprintw(4, 15, "1. Vestidos");
        mvprintw(4, 45, "2. Zapatos");
        mvprintw(14, 15, "3. Partes de Abajo");
        mvprintw(14, 45, "4. Partes de Arriba");
    }
    else
    {
        // Interfaz Carrusel (Muestra la prenda iterada)
        flechas1.draw();

        // Obtener la prenda actual basándonos en los índices
        const Prenda& prendaMostrada = tienda1.getPrenda(categoriaActual, prendaActual);

        // Dibujar el arte ASCII de la prenda entre las flechas
        prendaMostrada.draw(6, 26); 

        // Panel de detalles de la prenda
        mvprintw(12, 16, "Prenda: %s", prendaMostrada.getNombre().c_str());
        mvprintw(13, 16, "Estilo: %s", prendaMostrada.getEstilo().c_str());
        mvprintw(14, 16, "Precio: $%d", prendaMostrada.getPrecio());
        mvprintw(16, 16, "[ENTER] Seleccionar");
        mvprintw(17, 16, "[ESC]   Volver");
    }
} 

void draw()
{
    erase();
    box(stdscr, 0, 0);

    mvprintw(0, 80, "[ EXITO: %d    ]", puntaje);
    mvprintw(0, 100, "[ DINERO:$ %d    ]", tienda1.getDinero());

    clienta1.draw(winClienta, clientaElegida);	

    drawCatalogo();
    cursor1.draw();

    wnoutrefresh(stdscr);

    clienta1.draw(winClienta, clientaElegida);	

    doupdate();
}

void gameover()
{
	for (int y = 10; y < 16; y++) mvhline(y, 40, ' ', 40);

	mvaddch(9, 39, ACS_ULCORNER);
	mvaddch(9, 80, ACS_URCORNER);
	mvaddch(16, 39, ACS_LLCORNER);
	mvaddch(16, 80, ACS_LRCORNER);
	// Los marcos horizontales.
	mvhline(9, 40, ACS_HLINE, 40);
	mvhline(16, 40, ACS_HLINE, 40);
	// Los marcos verticales.
	mvvline(10, 39, ACS_VLINE, 6);
	mvvline(10, 80, ACS_VLINE, 6);

	mvprintw(12, 55, "GAME OVER");
	mvprintw(13, 50, "VOLVER A JUGAR? (S/N)");

	int opcion = getch();

	if (opcion == 's' || opcion == 'S')
	{
		setup();
	}
	else if (opcion == 'n' || opcion == 'N')
	{
		salir = true;
	}
}