#include "Clienta.h"
#include <iostream>
#include <ncurses.h>


Clienta::Clienta(string nombre, string estilo, int presupuesto, int satisfaccion)
{
    m_nombre = nombre;
    m_estilo = estilo;
    m_presupuesto = 1000;
    m_satisfaccion = satisfaccion;
}

void Clienta::draw(WINDOW* win, int opcion)
{
    werase(win);
    box(win, 0, 0);

    mvwprintw(win, 1, 2, "CLIENTA: %s", m_nombre.c_str());
    mvwprintw(win, 2, 2, "ESTILO: %s | PRESUPUESTO: $%d", m_estilo.c_str(), m_presupuesto);

    switch (opcion)
    {
    case 0:
mvwaddstr(win,  5, 2, "Hola! estoy buscando una remera manga corta.");
mvwaddstr(win,  7, 4, "          .:=+##########*=-:              ");
mvwaddstr(win,  8, 4, "        .=##################+:            ");
mvwaddstr(win,  9, 4, "       :+#####################+:          ");
mvwaddstr(win, 10, 4, "      .#%######**###############=         ");
mvwaddstr(win, 11, 4, "      =%#+=============*#########-        ");
mvwaddstr(win, 12, 4, "     .+#+============+===*#######-        ");
mvwaddstr(win, 13, 4, "      -#+===+=====++=======#######-.=:.   ");
mvwaddstr(win, 14, 4, "      .#+++================+######=-+==:  ");
mvwaddstr(win, 15, 4, "      .#*-=*+=======*#=-++==+#####**####=.");
mvwaddstr(win, 16, 4, "      .*--+%*+=====+##*:.-===+*########+. ");
mvwaddstr(win, 17, 4, "      .-:=++=-======++=-=====+=+#######+. ");
mvwaddstr(win, 18, 4, "       .*+====================+###+-##*:  ");
mvwaddstr(win, 19, 4, "       .-*=================+*#####+:#*.   ");
mvwaddstr(win, 20, 4, "       .=##+===++======+*#########+.##-.  ");
mvwaddstr(win, 21, 4, "       .#####+=======+++##########+.##*:  ");
mvwaddstr(win, 22, 4, "       .#+=*###*+==++===+#%#%%####+.##*:  ");
mvwaddstr(win, 23, 4, "    ...##=-=+#+==========*%%%#**##+:##*:  ");
mvwaddstr(win, 24, 4, "   :===##+=**============*%%#+======##=.  ");
mvwaddstr(win, 25, 4, " .-====##++%============+%%%*========+.   ");
mvwaddstr(win, 26, 4, ".-====*#++*+============+#%#+=========:   ");
mvwaddstr(win, 27, 4, ".-====*#+**=============+#%*==========:   ");
mvwaddstr(win, 28, 4, ".=====*#*#*=============+##+==========:   ");

                                                       

        break;

    case 1:
mvwaddstr(win,  5, 2, "Hola! Busco un vestido elegante .");
mvwaddstr(win,  7, 4, "           .:#'---------------'+:         ");
mvwaddstr(win,  8, 4, "         .:*@@@@@@@@@@@@@@@@@@%+.         ");
mvwaddstr(win,  9, 4, "         :%@@@@@@@@@@@@@@@@@@@@@#=.       ");
mvwaddstr(win, 10, 4, "        :@@@#@%#@@@@@@@@@@@@@@@@@@+:      ");
mvwaddstr(win, 11, 4, "        :@#=:::-@@@@@@@@@@@@@@@@@@*:      ");
mvwaddstr(win, 12, 4, "        :*-:::::+@@@@@@@@@@@@@@@@@@:      ");
mvwaddstr(win, 13, 4, "        :*:::-::-*@@@@@@@@@@+%@@@@@:      ");
mvwaddstr(win, 14, 4, "        :=:::::::++*%@@@*+*+-#+@@@@:      ");
mvwaddstr(win, 15, 4, "       :#+*--=::--:*++@@%*-::-%@@@:       ");
mvwaddstr(win, 16, 4, "        .-+=#@%=:::::*--@#*=::-%@@@+.     ");
mvwaddstr(win, 17, 4, "         ..-#%-=:::::=%@#=--::-=--*@#:    ");
mvwaddstr(win, 18, 4, "         .::...::::::::---:::::-:-*=*%=.  ");
mvwaddstr(win, 19, 4, "        .=*-:::::::::::::::::::-=*@:      ");
mvwaddstr(win, 20, 4, "       .-+@+-::---:::::::::-=*%@@@@*:.    ");
mvwaddstr(win, 21, 4, "      :::@@@@*:::::::::::-*@@@@@@@@@*.    ");
mvwaddstr(win, 22, 4, "      :*@#+#@@@+:::::::---*@@@@@@@@@@=.   ");
mvwaddstr(win, 23, 4, "     -:.-*+#@%@@%#-:::::::=#@@@@@@@@@@#==.");
mvwaddstr(win, 24, 4, "    .-*+=+#*+%@@@*-::-+*--@@@@@@@@@@%-.   ");
mvwaddstr(win, 25, 4, "    .*@@@@@-------------------@@@@@@@#-.  ");
mvwaddstr(win, 26, 4, " . =#@@@-----------------------@@@@@@#=.  ");
mvwaddstr(win, 27, 4, "  -#@@--------------------------%@@@@@%+. ");
mvwaddstr(win, 28, 4, " -#@@----------------------------%#-.     ");
mvwaddstr(win, 29, 4, ".=--------------------------------+:.     ");

    

        break;

    case 2:
mvwaddstr(win,  5, 2, "Que tal? necesito unos tacos muy altos.");
mvwaddstr(win,  7, 4, "       MMMMMM@@@@@@@@@@@@             ");
mvwaddstr(win,  8, 4, "       MMMMM@@@@@@@@@@@@@@@@          ");
mvwaddstr(win,  9, 4, "          {@@@@@@@@@@@@@@@@@@@        ");
mvwaddstr(win, 10, 4, "         @@@@@@@@@@@III{@@@@@@-       ");
mvwaddstr(win, 11, 4, "        @@@@@@@@@>IIIIIIII@@@@-       ");
mvwaddstr(win, 12, 4, "       M@@@@@@@IIIIIII°°°II@@@@       ");
mvwaddstr(win, 13, 4, "      M@@@@@@0IIIII@@0IIIIII@@@       ");
mvwaddstr(win, 14, 4, "     MM@@@@@IIIIIIIIIIIIIIII@@@       ");
mvwaddstr(win, 15, 4, "     M @@@@@300IIIIId00ddII@@@@       ");
mvwaddstr(win, 16, 4, "        @@@3@|0IIIIM00M>III@J@@       ");
mvwaddstr(win, 17, 4, "        >@@IdIIIIIII@adJII>->@@       ");
mvwaddstr(win, 18, 4, "        M OIIII--IIIIIIIII>I\"        ");
mvwaddstr(win, 19, 4, "          \"IIIIIIIIIIIIII            ");
mvwaddstr(win, 20, 4, "            III--IIIIII\"             ");
mvwaddstr(win, 21, 4, "              IIIIII-{M               ");
mvwaddstr(win, 22, 4, "       JJJJO@@@@OMM@@@@aJOOOOO        ");
mvwaddstr(win, 23, 4, "     MM@@@@@@ac@@@@@@@MMJ@@@@@MMMM    ");
mvwaddstr(win, 24, 4, "   JM@M@@@@@MMMM@@@@@MMaM@@@@MMMMMM   ");
mvwaddstr(win, 25, 4, "   MM@@@@@@MM@@@MMM@@@@M@@@@@@MM@MMMd ");
mvwaddstr(win, 26, 4, "  dM@@@@@@@MMMM@@@@@@MJ@@@@@@@M@@MMMd ");
mvwaddstr(win, 27, 4, "  M@@MM@@@@MMMd@@da@MMM@@@@@@@@@@MMMM ");
mvwaddstr(win, 28, 4, "  M@@MM@@@@MMMd@@da@MMM@@@@@@@@@@MMMM ");
       break;
       
    case 3:
mvwaddstr(win,  5,  2, "Como va? busco una camisa manga larga.");
mvwaddstr(win,  7,  4,"            +..000000-##                ");
mvwaddstr(win,  8,  4,"         ++#######000000.##             ");
mvwaddstr(win,  9,  4,"        ################000-            ");
mvwaddstr(win, 10,  4,"       .#################-0#            ");
mvwaddstr(win, 11,  4,"       ####################-#           ");
mvwaddstr(win, 12,  4,"       ######################           ");
mvwaddstr(win, 13,  4,"       #######+##############           ");
mvwaddstr(win, 14, 4, "       #+-°+++++++°-+#######            ");
mvwaddstr(win, 15, 4, "       ##xxx++++++xxx+#++#####          ");
mvwaddstr(win, 16, 4, "        +-x. ++++-x  +++#####           ");
mvwaddstr(win, 17, 4, "        ++++++++++++++++##+###          ");
mvwaddstr(win, 18, 4, "        #+++++++++++++++#####           ");
mvwaddstr(win, 19, 4, "         #++++88++++++#######           ");
mvwaddstr(win, 20, 4, "           +++++++++#######.            ");
mvwaddstr(win, 21, 4, "         #+####+###+++##+##             ");
mvwaddstr(win, 22, 4, "    #+#####+----+++----###+####+        ");
mvwaddstr(win, 23, 4, "  #+#+#####+-+++++++++###########.      ");
mvwaddstr(win, 24, 4, " ####+#++#.3+++++++++3++###########     ");
mvwaddstr(win, 25, 4, " #######++..--+333.--#+#+#######+##+    ");
mvwaddstr(win, 26, 4, " ######++##..-...-...-+####+#####+###:  ");
mvwaddstr(win, 27, 4, " ##########.---.---.-####+###########+: ");
mvwaddstr(win, 28, 4, " ##########.---.---.-####+###########++:");
        

        break;  
        
case 4:
mvwaddstr(win,  5,  2, "Buenas! estoy en busqueda de una pollera corta y simple.");
mvwaddstr(win,  7,  4, "          .##############            ");
mvwaddstr(win,  8,  4, "         *#################          ");
mvwaddstr(win,  9,  4, "       ?####################         ");
mvwaddstr(win, 10,  4, "        #####################        ");
mvwaddstr(win, 11,  4, "       %##=:::################       ");
mvwaddstr(win, 12,  4, "      ##:::::##################      ");
mvwaddstr(win, 13,  4, "      =%::::%::###############       ");
mvwaddstr(win, 14,  4, "      ####---:::###:##=:::#####      ");
mvwaddstr(win, 15,  4, "       ##* @3::::=:@@3=:::##%        ");
mvwaddstr(win, 16,  4, "       ##%:@@%:::::@@@@=:::%:        ");
mvwaddstr(win, 17,  4, "      =##: %@:::::@@% ::::--         ");
mvwaddstr(win, 18,  4, "       ##%=::::--:::::::::-::        ");
mvwaddstr(win, 19,  4, "          :::::::::::::: ##          ");
mvwaddstr(win, 20,  4, "            :::::::::-   %           ");
mvwaddstr(win, 21,  4, "              :::::--:               ");
mvwaddstr(win, 22,  4, "         -=%* -:::::::==*%           ");
mvwaddstr(win, 23,  4, "     :=* =*##+.::::::+=%#-+:*#       ");
mvwaddstr(win, 24,  4, "   ++-%@ :**  . :::.  #%+* =*. **+   ");
mvwaddstr(win, 25,  4, "   .*=@@+**#*   ::  .**# #:%*:-==*.  ");
mvwaddstr(win, 26,  4, "   **-%@=.=+ . : .  -@+.=::%¡¨=*==.  ");
mvwaddstr(win, 27,  4, "  %+*=%-+==* :=%::%--== =.:#+++. *   ");
mvwaddstr(win, 28,  4, "  :.. ::.....:::. :......::::: . .:  ");
        

        break;
    }
    wnoutrefresh(win);
}
//     void Clienta::update()
// {
  // Incremento en el eje Y para que el asteroide vaya bajando.
  // Utilizamos un incremento decimal para regular la velocidad del


//   if (m_satisfaccion <= 0 )
//   {

//   }
// }

//bool Clienta::evaluarPrenda(){
//}