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
vector<Clienta> clientas;
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
    mvprintw(3, 8, " ,ggggggggggg,                                                                                      ");
    mvprintw(4, 8, "dP---88------Y8,                            ss                                                      ");
    mvprintw(5, 8, "Yb,  88      `8b                            I8                                                      ");
    mvprintw(6, 8, " -  88      ,8P                         88888888                      jd                                   ");
    mvprintw(7, 8, "     88aaaad8P-                             I8                        --                                   ");
    mvprintw(8, 8, "     88----Y8ba    ,ggggg,    jd      vm    I8                        gg     ,gggg,gg  vm      ss   ,ggg,  ");
    mvprintw(9, 8, "     88      `8b  dP-  -Y8ggg I8      8I    I8                        88    dP-  -Y8I  I8      8I  i8- -8i ");
    mvprintw(10, 8, "     88      ,8P i8'    ,8I   I8,    ,8I   ,I8,                       88   i8'    ,8I  I8,    ,8I  I8, ,8I ");
    mvprintw(11, 8, "     88_____,d8',d8,   ,d8'  ,d8b,  ,d8b, ,d88b,                    _,88,_,d8,   ,d8b ,d8b,  ,d8b, `YbadP' ");
    mvprintw(12, 8, "    88888888P-  P-Y8888P-    8P--Y88P--Y888P--Y88                   8P--Y8P-Y8888P-88d8P--Y88P--Y8888P-Y888-");
    mvprintw(13, 8, "                                                                                   I8P                     ");
    mvprintw(14, 8, "                                                                                   I8'                     ");
    mvprintw(15, 8, "                                                                                   I8                      ");
    mvprintw(16, 8, "                                                                                   I8                      ");
    mvprintw(17, 8, "                                                                                   I8                      ");
    mvprintw(18, 8, "                                                                                   I8                      ");
    mvprintw(7, 57, "  .-._   .-._..-.  ");
    mvprintw(8, 57, "..' (_)`-'    / (_)");
    mvprintw(9, 57, "|           /      ");
    mvprintw(10, 57, "|    _     /       ");
    mvprintw(11, 57, "`.    ) .-/.    .-.");
    mvprintw(12, 57, "  `--' (_/ `-._.   ");
    mvprintw(14, 95, "         :@@@@@=");
    mvprintw(15, 95, "        @@@@@@@@@");
    mvprintw(16, 95, "        @@@@@@@@@@");
    mvprintw(17, 95, "        @@@@@@@@@@");
    mvprintw(18, 95, "         +@@@@@@@@");
    mvprintw(19, 95, "            @@@@@@");
    mvprintw(20, 95, "        -@@@@@@@@@*");
    mvprintw(21, 95, "        @@@@@@@@@@*");
    mvprintw(22, 95, "       :@@@@@@@@@@");
    mvprintw(23, 95, "       :@@@@@@@@@@");
    mvprintw(24, 95, "       @@@@@@@= @@");
    mvprintw(25, 95, "       @@@@@@@@@@-");
    mvprintw(26, 95, "      @@@@@@@@@");
    mvprintw(27, 95, "      @@@@@@@@@@");
    mvprintw(28, 95, "      @@@@@@@@@@@*");
    mvprintw(29, 95, "     #@@@@@@@@@@@@-");
    mvprintw(30, 95, "      @@@@@@@@@@@@@");
    mvprintw(31, 95, "       @@@@@@@@@@@@");
    mvprintw(32, 95, "       @@@@@@@@@@@@=");
    mvprintw(33, 95, "       @@@@@@@@@@@@=");
    mvprintw(34, 95, "       =@@@@-@@@@");
    mvprintw(8, 1, "   +@@@@:");
    mvprintw(9, 1, "  @@@@@@@:");
    mvprintw(10, 1, "  @@@@@@@:");
    mvprintw(11, 1, "   -@@@@@.");
    mvprintw(12, 1, "  -@@@@@");
    mvprintw(13, 1, "  @@@@@@@@.");
    mvprintw(14, 1, "  @@@@@@@@:");
    mvprintw(15, 1, "  @@@@@@@@");
    mvprintw(16, 1, "  @@@@@@@@");
    mvprintw(17, 1, "  @@@@@@@@.");
    mvprintw(18, 1, "  @ @@@@@@@");
    mvprintw(19, 1, " @ =@@@@@@@@");
    mvprintw(20, 1, " @ @@@@@@@@@");
    mvprintw(21, 1, "#@#=@@@@@@@@@");
    mvprintw(22, 1, " @  *@@@@@@@#");
    mvprintw(23, 1, "      @@@@@@");
    mvprintw(24, 1, "      .@@@@@");
    mvprintw(25, 1, "     .@@*#@@");
    mvprintw(26, 1, "     @@: #@@");
    mvprintw(27, 1, "    @@    @@");
    mvprintw(28, 1, "    @:    @@");
    mvprintw(29, 1, "  :@=      @");
    mvprintw(16, 50, "   -.   ");
    mvprintw(17, 50, "   /    ");
    mvprintw(18, 50, "  /      Jugar");
    mvprintw(19, 50, "-----   ");
    mvprintw(20, 50, "        ");
    mvprintw(21, 50, "        ");
    mvprintw(22, 50, " .-.    ");
    mvprintw(23, 50, "    )   ");
    mvprintw(24, 50, " .-/.    Instrucciones");
    mvprintw(25, 50, "(_/  `-'");
    mvprintw(26, 50, "        ");
    mvprintw(27, 50, "        ");
    mvprintw(28, 50, " .--.   ");
    mvprintw(29, 50, "    .'  ");
    mvprintw(30, 50, "   '.    Creditos");
    mvprintw(31, 50, "'----'  ");
    mvprintw(32, 50, "        ");
    mvprintw(33, 50, "        ");
    mvprintw(34, 50, " /  / ");
    mvprintw(35, 50, "/__/  ");
    mvprintw(36, 50, "  /      Salir");
    mvprintw(37, 50, " /    ");

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
        mvprintw(15, 34, "Disparar con la tecla 'z'.");
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
    clientas = {
        // remera manga corta
        Clienta("Ana", "Casual", 500, 50),
        // vestido elegante
        Clienta("Maria", "Elegante", 1000, 50),
        // tacos muy altos
        Clienta("Sofia", "Elegante", 1200, 50),
        // camisa manga larga
        Clienta("Laura", "Elegante", 900, 50),
        // pollera corta y simple
        Clienta("Julia", "Casual", 700, 50)};

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

        if (clientas[clientaElegida].evaluarPrenda(prenda))
        {
            puntaje++;
            tienda1.sumarDinero(prenda.getPrecio());
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

    mvprintw(0, 10, "[ EXITO: %d]", puntaje);
    mvprintw(0, 40, "[ DINERO: $%d]", tienda1.getDinero());

    clientas[clientaElegida].draw(winClienta, clientaElegida);

    drawCatalogo();
    if (!seleccionandoPrenda)
    {
        cursor1.draw();
    }

    wnoutrefresh(stdscr);

    clientas[clientaElegida].draw(winClienta, clientaElegida);

    doupdate();

    wnoutrefresh(stdscr);

    clientas[clientaElegida].draw(winClienta, clientaElegida);

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
    mvhline(9, 40, ACS_HLINE, 40);
    mvhline(16, 40, ACS_HLINE, 40);
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
