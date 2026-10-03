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

const int ANCHO = 120;
const int ALTO = 40;
const int DELAY = 30;

bool salir = false;
bool mostrar_menu = true;
bool game_over = false;
int puntaje = 0;
WINDOW *winClienta = 0;

Tienda tienda1;
Cursor cursor1;
Clienta clienta1;
Clienta clienta2;
Clienta clienta3;
Clienta clienta4;
Clienta clienta5;
Flechas flechas1;
SentidoFlecha flechaActual = SentidoFlecha::IZQUIERDA;

int clientaElegida;
bool seleccionandoPrenda = false;
int categoriaActual = 0;
int prendaActual = 0;

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
    nodelay(stdscr, TRUE);
    set_escdelay(25);

    if (has_colors())
    {
        start_color();

        init_pair(1, COLOR_BLACK, COLOR_WHITE);
        init_pair(2, COLOR_WHITE, COLOR_BLACK);
        init_pair(3, COLOR_RED, COLOR_BLACK);
        init_pair(4, COLOR_GREEN, COLOR_BLACK);
        init_pair(5, COLOR_YELLOW, COLOR_BLACK);
        init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(7, COLOR_CYAN, COLOR_BLACK);
        init_pair(8, COLOR_BLUE, COLOR_BLACK);
    }

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
        else
        {
            nodelay(stdscr, false);
            gameover();
        }
    }

    if (winClienta)
        delwin(winClienta);
    endwin();
    return 0;
}

void menu()
{

    erase();
    mvprintw(3, 45, "BOUT(CL)IQUE");
    mvprintw(4, 45, "                                  +@@@@:           ");
    mvprintw(5, 45, "         :@@@@@=                 @@@@@@@:          ");
    mvprintw(6, 45, "        @@@@@@@@@                @@@@@@@:          ");
    mvprintw(7, 45, "        @@@@@@@@@@                -@@@@@.          ");
    mvprintw(8, 45, "        @@@@@@@@@@              -@@@@@             ");
    mvprintw(9, 45, "         +@@@@@@@@              @@@@@@@@.          ");
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
    mvprintw(31, 54, "2 - INSTRUCCIONES");
    mvprintw(33, 54, "3 - CREDITOS");
    mvprintw(35, 54, "4 - SALIR ");
    refresh();

    napms(DELAY);

    char opcion = getch();

    switch (opcion)
    {
    case '1':
        mostrar_menu = false;
        setup();
        break;
    case '2':
        instrucciones();
        break;
    case '3':
        creditos();
        break;
    case '4':
        mostrar_menu = false;
        salir = true;
        break;
    default:
        break;
    }
}

void instrucciones()
{
    char opcion;
    do
    {
        erase();
        mvprintw(12, 34, "El juego consiste en elegir la prenda correcta ");
        mvprintw(13, 34, "segun lo que busquen las clientas.");
        mvprintw(14, 34, "Elegir la categoría de prenda con las flechas del cursor.");
        mvprintw(15, 34, "Disparar con la tecla 'z'."); // elegir y eso
        mvprintw(17, 34, "Presione la barra para volver al menú...");
        opcion = getch();
    } while (opcion != ' ');
}

void creditos()
{
    char opcion;
    do
    {
        erase();
        mvprintw(11, 34, "_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'");
        mvprintw(12, 34, "       INFORMATICA GENERAL CATEDRA TIRIGALL        ");
        mvprintw(13, 34, " Juan Derene, Valentina Mauro, Santiago Stillitano ");
        mvprintw(14, 34, "_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'");
        mvprintw(16, 34, "Presione la barra para volver al menú...");
        opcion = getch();
    } while (opcion != ' ');
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

    if (tecla == 27)
    {
        if (seleccionandoPrenda)
        {
            // Volver a las cuatro categorias
            seleccionandoPrenda = false;

            cursor1.setX(
                (categoriaActual % 2 == 0) ? 15 : 45);

            cursor1.setY(
                (categoriaActual < 2) ? 5 : 15);
        }
        else
        {
            game_over = true;
        }

        return;
    }

    if (!seleccionandoPrenda)
    {
        switch (tecla)
        {
        case KEY_LEFT:
            if (categoriaActual % 2 == 1)
                categoriaActual--;
            break;

        case KEY_RIGHT:
            if (categoriaActual % 2 == 0)
                categoriaActual++;
            break;

        case KEY_UP:
            if (categoriaActual >= 2)
                categoriaActual -= 2;
            break;

        case KEY_DOWN:
            if (categoriaActual < 2)
                categoriaActual += 2;
            break;

        case KEY_ENTER:
        case '\n':
            seleccionandoPrenda = true;
            prendaActual = 0;
            flechaActual = SentidoFlecha::IZQUIERDA;

            cursor1.setX(flechas1.getX(flechaActual));
            cursor1.setY(flechas1.getY());
            break;

        default:
            break;
        }

        if (tecla == KEY_LEFT || tecla == KEY_RIGHT || tecla == KEY_UP || tecla == KEY_DOWN)
        {
            cursor1.setX((categoriaActual % 2 == 0) ? 15 : 45);
            cursor1.setY((categoriaActual < 2) ? 5 : 15);
        }

        return;
    }

    switch (tecla)
    {
    case KEY_LEFT:

        if (prendaActual == 0)
            prendaActual = 3;
        else
            prendaActual--;
        break;

    case KEY_RIGHT:

        prendaActual++;
        if (prendaActual > 3)
            prendaActual = 0;
        break;

    case KEY_ENTER:
    case '\n':
    {

        const Prenda &prenda = tienda1.getPrenda(categoriaActual, prendaActual);

        if (clienta1.evaluarPrenda(prenda))
        {
            puntaje++;
        }
        else
        {
        }

        seleccionandoPrenda = false;
        clientaElegida = rand() % 5;

        cursor1.setX((categoriaActual % 2 == 0) ? 15 : 45);
        cursor1.setY((categoriaActual < 2) ? 5 : 15);
        break;
    }

    default:
        break;
    }
}

void update()
{
}

void drawCatalogo()
{
    if (!seleccionandoPrenda)
    {
        mvprintw(4, 10, "1. Vestidos");
        mvprintw(4, 40, "2. Zapatos");
        mvprintw(14, 10, "3. Partes de Abajo");
        mvprintw(14, 40, "4. Partes de Arriba");
    }
    else
    {

        flechas1.draw();

        const Prenda &prendaMostrada = tienda1.getPrenda(categoriaActual, prendaActual);

        int COLOR = 1;

        if (categoriaActual == 0)
        {
            if (prendaActual == 0)
                COLOR = 1;
            if (prendaActual == 1)
                COLOR = 3;
            if (prendaActual == 2)
                COLOR = 6;
            if (prendaActual == 3)
                COLOR = 5;
        }
        else if (categoriaActual == 1)
        {
            if (prendaActual == 0)
                COLOR = 1;
            if (prendaActual == 1)
                COLOR = 2;
            if (prendaActual == 2)
                COLOR = 4;
            if (prendaActual == 3)
                COLOR = 5;
        }
        else if (categoriaActual == 2)
        {
            if (prendaActual == 0)
                COLOR = 8;
            if (prendaActual == 1)
                COLOR = 8;
            if (prendaActual == 2)
                COLOR = 2;
            if (prendaActual == 3)
                COLOR = 1;
        }
        else if (categoriaActual == 3)
        {
            if (prendaActual == 0)
                COLOR = 2;
            if (prendaActual == 1)
                COLOR = 7;
            if (prendaActual == 2)
                COLOR = 6;
            if (prendaActual == 3)
                COLOR = 4;
        }

        attron(COLOR_PAIR(COLOR));
        prendaMostrada.draw(6, 20);
        attroff(COLOR_PAIR(COLOR));

        mvprintw(23, 16, "Prenda: %s", prendaMostrada.getNombre().c_str());
        mvprintw(24, 16, "Estilo: %s", prendaMostrada.getEstilo().c_str());
        mvprintw(25, 16, "Precio: $%d", prendaMostrada.getPrecio());
        mvprintw(26, 16, "[ENTER] Seleccionar");
        mvprintw(27, 16, "[ESC]   Volver");
    }
}

void draw()
{
    erase();
    box(stdscr, 0, 0);

    mvprintw(0, 80, "[ EXITO: %d    ]", puntaje);
    for (int i = 0; i < puntaje; i++)
    {
        mvaddch(0, 91 + i, ACS_CKBOARD);
    }
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

    for (int y = 10; y < 16; y++)
        mvhline(y, 40, ' ', 40);

    // esto lo podemos hacer un win y box????
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
    mvprintw(13, 50, "1- RESTART");
    mvprintw(14, 50, "2- VOLVER AL MENU");

    int opcion = getch();

    if (opcion == '1')
    {
        setup();
    }
    else if (opcion == '2')
    {
        mostrar_menu = true;
        game_over = false;
    }
}
