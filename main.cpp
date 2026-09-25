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

//------variables globales
bool salir;
bool mostrar_menu;
bool game_over;
int puntaje;

Cursor cursor1;
Clienta clienta1;
Flechas flechas1;
SentidoFlecha flechaActual =
    SentidoFlecha::IZQUIERDA;

int clientaElegida;
bool seleccionandoPrenda = false;
int categoriaActual = 0;
int prendaActual = 0;

std::vector<std::vector<Prenda>> catalogo;


//------funciones globales
void menu();
void instrucciones();
void creditos();
void setup();
void input();
void update();
void draw();
void gameover();

std::vector<std::vector<Prenda>> crearCatalogo()
{
    using C = CategoriaPrenda;

    return {
        {
            Prenda("Vestido elegante", "Elegante", "Negro", 900,
                   C::VESTIDOS,
                   {" /\\ ", "/##\\", "/__\\ "}),

            Prenda("Vestido corto", "Casual", "Rojo", 700,
                   C::VESTIDOS,
                   {" /\\ ", "|()|", "/__\\ "}),

            Prenda("Vestido floral", "Romantico", "Rosa", 850,
                   C::VESTIDOS,
                   {" /\\ ", "|**|", "/\\/\\ "}),

            Prenda("Vestido de fiesta", "Fiesta", "Dorado", 1200,
                   C::VESTIDOS,
                   {" /\\ ", "|@@|", "/==\\ "})
        },

        {
            Prenda("Tacos muy altos", "Elegante", "Negro", 1100,
                   C::ZAPATOS,
                   {" __ ", "/_/ ", "\\__ "}),

            Prenda("Zapatillas urbanas", "Casual", "Blanco", 650,
                   C::ZAPATOS,
                   {" __ ", "/##\\", "\\___"}),

            Prenda("Botas altas", "Urbano", "Marron", 950,
                   C::ZAPATOS,
                   {" |\\ ", " |#|", "/___"}),

            Prenda("Sandalias", "Verano", "Dorado", 500,
                   C::ZAPATOS,
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


int main() 
{
	srand(time(0));
	initscr(); 
	noecho();
	curs_set(false);
	keypad(stdscr, true);
	nodelay(stdscr, true);

// check terminal 
	if (LINES < ALTO || COLS < ANCHO)
	{
		endwin();
		printf("La terminal tiene que tener como mínimo %dx%d\n\n", ANCHO, ALTO);
		exit(1);
	}

  salir = false;
  mostrar_menu = true;
  game_over = true;
    
//BUCLE PRINCIPAL
  while (!salir)
	{
    while (mostrar_menu)
    {
      menu();
    }

    while (!game_over)
    {
			input();
			update();
			draw();
		}

    if (game_over) gameover();
	}

  endwin();

	cout << endl;
	return 0;
}

void menu()
{
erase();
mvprintw(3, 50, "BOUT(CL)IQUE");
mvprintw(4, 65, "+@@@@:");
mvprintw(5, 40, ":@@@@@=                 @@@@@@@:");
mvprintw(6, 39, "@@@@@@@@@                @@@@@@@:");
mvprintw(7, 39, "@@@@@@@@@@                -@@@@@.");
mvprintw(8, 39, "@@@@@@@@@@              -@@@@@");
mvprintw(9, 40, "+@@@@@@@@              @@@@@@@@.");
mvprintw(10, 43, "@@@@@@              @@@@@@@@:");
mvprintw(11, 39, "-@@@@@@@@@*             @@@@@@@@");
mvprintw(12, 39, "@@@@@@@@@@*             @@@@@@@@");
mvprintw(13, 38, ":@@@@@@@@@@              @@@@@@@@.");
mvprintw(14, 38, ":@@@@@@@@@@              @ @@@@@@@");
mvprintw(15, 38, "@@@@@@@= @@             @ =@@@@@@@@");
mvprintw(16, 37, "@@@@@@@@@               %@#=@@@@@@@@@");
mvprintw(17, 37, "@@@@@@@@@@               @  *@@@@@@@#");
mvprintw(18, 37, "@@@@@@@@@@@*                  @@@@@@");
mvprintw(19, 36, "#@@@@@@@@@@@@-                 .@@@@@");
mvprintw(20, 38, "@@@@@@@@@@@@                @@: #@@");
mvprintw(21, 38, "@@@@@@@@@@@@=              @@    @@");
mvprintw(22, 38, "@@@@@@@@@@@@=              @:    @@");
mvprintw(23, 38, "=@@@@-@@@@               :@=      @");
mvprintw(24, 40, "@@  @@@                @@       @-");
mvprintw(25, 40, "@@@  @@@                        @@");

mvprintw(27, 58, "MENU");
mvprintw(29, 54, "1 - JUGAR");
mvprintw(32, 54, "4 - SALIR");

  char opcion = getch();

  switch (opcion)
  {
  case '1':
    mostrar_menu = false;
    setup();
    break;
  case '2':
    mostrar_menu = false;
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

	catalogo = crearCatalogo();
    seleccionandoPrenda = false;
    categoriaActual = 0;
    prendaActual = 0;
    flechaActual =
        SentidoFlecha::IZQUIERDA;
    cursor1.setup();
    flechas1.setup();
    clientaElegida = rand() % 5;

    //Tienda.setup();
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
            categoriaActual = categoriaActual;

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
        if (tecla == KEY_LEFT &&
            categoriaActual % 2 == 1)
        {
            categoriaActual--;
        }

        if (tecla == KEY_RIGHT &&
            categoriaActual % 2 == 0)
        {
            categoriaActual++;
        }

        if (tecla == KEY_UP &&
            categoriaActual >= 2)
        {
            categoriaActual -= 2;
        }

        if (tecla == KEY_DOWN &&
            categoriaActual < 2)
        {
            categoriaActual += 2;
        }

        // Mover el cursor a la categoria actual
        cursor1.setX(
            (categoriaActual % 2 == 0) ? 15 : 45
        );

        cursor1.setY(
            (categoriaActual < 2) ? 5 : 15
        );

        // Enter para entrar a la categoria
        if (tecla == KEY_ENTER ||
            tecla == '\n')
        {
            seleccionandoPrenda = true;
            prendaActual = 0;
            flechaActual =
                SentidoFlecha::IZQUIERDA;

            cursor1.setX(
                flechas1.getX(flechaActual)
            );

            cursor1.setY(
                flechas1.getY()
            );
        }

        return;
    }

    // Pantalla de una prenda con las dos flechas

    if (tecla == KEY_LEFT)
    {
        flechaActual =
            SentidoFlecha::IZQUIERDA;
    }

    if (tecla == KEY_RIGHT)
    {
        flechaActual =
            SentidoFlecha::DERECHA;
    }

    // Mover el cursor a la flecha elegida
    cursor1.setX(
        flechas1.getX(flechaActual)
    );

    cursor1.setY(
        flechas1.getY()
    );

    // Enter sobre una flecha
    if (tecla == KEY_ENTER ||
        tecla == '\n')
    {
        if (flechaActual ==
            SentidoFlecha::IZQUIERDA)
        {
            if (prendaActual == 0)
                prendaActual = 3;
            else
                prendaActual--;
        }
        else
        {
            prendaActual++;

            if (prendaActual > 3)
                prendaActual = 0;
        }
    }
}

void update()
{

}

void drawCatalogo()
{
    if (!seleccionandoPrenda)
    {
        // Interfaz de selección de categoría
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
        const Prenda& prendaMostrada = catalogo[categoriaActual][prendaActual];

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

    mvprintw(0, 80, "[ EXITO:     ]");
    mvprintw(0, 100, "[ DINERO:$     ]");

    // Dibuja la clienta a la derecha
    clienta1.draw(clientaElegida);	

    // Renderiza el menú o el carrusel a la izquierda
    drawCatalogo();

    // Dibuja el cursor interactivo
    cursor1.draw();

    refresh();
    delay_output(DELAY);
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