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

#include "Clienta.h"
void Clienta::draw(int opcion)
{
    switch (opcion)
    {
    case 0:
mvaddstr(5, 70, "Hola! estoy buscando una remera manga corta.");
mvaddstr(10, 82, ".:=+##########*=-:");
mvaddstr(11, 80, ".=##################+:");
mvaddstr(12, 79, ":+#####################+:");
mvaddstr(13, 78, ".#%######**###############=");
mvaddstr(14, 78, "=%#+=============*#########-");
mvaddstr(15, 77, ".+#+============+===*#######-");
mvaddstr(16, 78, "-#+===+=====++=======#######-.:=:.");
mvaddstr(17, 78, ".#+++================+######=-*+==:");
mvaddstr(18, 78, ".#*-=*+=======*#=-++==+#####**#####=.");
mvaddstr(19, 78 , ".*--+%*+=====+##*:.-===+*#########+.");
mvaddstr(20, 78, ".-:=++=-======++=-=====+=+########+.");
mvaddstr(21, 79 , ".*+====================+###+-+##*:");
mvaddstr(22, 79 , ".-*=================+*#####+:=#*.");
mvaddstr(23, 79, ".=##+===++======+*#########+.-##-.");
mvaddstr(24, 79, ".#####+=======+++##########+.-##*:");
mvaddstr(25, 79, ".#+=*###*+==++===+#===%####+.-##*:");
mvaddstr(26, 76, "...##=-=+#+==========*==%#**##+:=##*:");
mvaddstr(27, 75, ":===##+=**============*==#+======*##=.");
mvaddstr(28, 73, ".-====##++%============+==%*=========+.");
mvaddstr(29, 72, ".-====*#++*+============+#%#+==========:");
mvaddstr(30, 72, ".-====*#+**=============+#%*===========:");
mvaddstr(31, 72, ".=====*#*#*=============+##+===========:");


        break;

    case 1:
mvaddstr(5, 70, "Hola! Busco un vestido elegante .");
mvaddstr(10, 80, "           .:#'---------------'+:");
mvaddstr(11, 80, "         .:*@@@@@@@@@@@@@@@@@@%+.");
mvaddstr(12, 79, "         :%@@@@@@@@@@@@@@@@@@@@@#=.");
mvaddstr(13, 78, "        :@@@#@%#@@@@@@@@@@@@@@@@@@+:");
mvaddstr(14, 55, "        :@#=:::-@@@@@@@@@@@@@@@@@@*:");
mvaddstr(15, 55, "        :*-:::::+@@@@@@@@@@@@@@@@@@:");
mvaddstr(16, 55, "        :*:::-::-*@@@@@@@@@@+%@@@@@:");
mvaddstr(17, 55, "        :=:::::::++*%@@@*+*+-#+@@@@:");
mvaddstr(18, 55, "       :#+*--=::--:*++@@%*-::-%@@@:");
mvaddstr(19, 55, "        .-+=#@%=:::::*--@#*=::-%@@@+.");
mvaddstr(20, 55, "         ..-#%-=:::::=%@#=--::-=--*@#:");
mvaddstr(21, 55, "         .::...::::::::---:::::-:-*=*%=.");
mvaddstr(22, 55, "        .=*-:::::::::::::::::::-=*@:");
mvaddstr(23, 55, "       .-+@+-::---:::::::::-=*%@@@@*:.");
mvaddstr(24, 55, "      :::@@@@*:::::::::::-*@@@@@@@@@*.");
mvaddstr(25, 55, "      :*@#+#@@@+:::::::---*@@@@@@@@@@=.");
mvaddstr(26, 55, "     -:.-*+#@%@@%#-:::::::=#@@@@@@@@@@#==.");
mvaddstr(27, 55, "    .-*+=+#*+%@@@*-::-+*--@@@@@@@@@@%-.");
mvaddstr(28, 55, "   .*@@@@@-------------------@@@@@@@#-.");
mvaddstr(29, 55, " .=#@@@-----------------------@@@@@@#=.");
mvaddstr(30, 55, " -#@@--------------------------%@@@@@%+.");
mvaddstr(31, 55, " -#@@----------------------------%#-.");
mvaddstr(32, 55, ".=--------------------------------+:.");

    

        break;

    case 2:
mvaddstr(5, 70, "Que tal? necesito unos tacos muy altos.");
mvaddstr(3,  20, "      MMMMMM@@@@@@@@@@@@");
mvaddstr(4,  20, "      MMMMM@@@@@@@@@@@@@@@@");
mvaddstr(5,  20, "         {@@@@@@@@@@@@@@@@@@@");
mvaddstr(6,  20, "        @@@@@@@@@@@III{@@@@@@-");
mvaddstr(7,  20, "       @@@@@@@@@>IIIIIIII@@@@-");
mvaddstr(8,  20, "      M@@@@@@@IIIIIII°°°II@@@@");
mvaddstr(9,  20, "     M@@@@@@0IIIII@@0IIIIII@@@");
mvaddstr(10, 20, "    MM@@@@@IIIIIIIIIIIIIIII@@@");
mvaddstr(11, 20, "    M @@@@@300IIIIId00ddII@@@@");
mvaddstr(12, 20, "       @@@3@|0IIIIM00M>III@J@@");
mvaddstr(13, 20, "       >@@IdIIIIIII@adJII>->@@");
mvaddstr(14, 20, "       M OIIII--IIIIIIIII>I\"");
mvaddstr(15, 20, "         \"IIIIIIIIIIIIII");
mvaddstr(16, 20, "           III--IIIIII\"");
mvaddstr(17, 20, "             IIIIII-{M");
mvaddstr(18, 20, "      JJJJO@@@@OMM@@@@aJOOOOO");
mvaddstr(19, 20, "    MM@@@@@@ac@@@@@@@MMJ@@@@@MMMM");
mvaddstr(20, 20, "  JM@M@@@@@MMMM@@@@@MMaM@@@@MMMMMM");
mvaddstr(21, 20, "  MM@@@@@@MM@@@MMM@@@@M@@@@@@MM@MMMd");
mvaddstr(22, 20, " dM@@@@@@@MMMM@@@@@@MJ@@@@@@@M@@MMMd");
mvaddstr(23, 20, " M@@MM@@@@MMMd@@da@MMM@@@@@@@@@@MMMM");
mvaddstr(24, 20, " M@@MM@@@@MMMd@@da@MMM@@@@@@@@@@MMMM");

       break;
       
    case 3:
mvaddstr(5, 70, "Como va? busco una camisa manga larga.");
mvaddstr(3,  20, "            +..000000-##");
mvaddstr(4,  20, "         ++#######000000.##");
mvaddstr(5,  20, "        ################000-");
mvaddstr(6,  20, "       .#################-0#");
mvaddstr(7,  20, "       ####################-#");
mvaddstr(8,  20, "       ######################");
mvaddstr(9,  20, "       #######+##############");
mvaddstr(10, 20, "       #+-°+++++++°-+#######");
mvaddstr(11, 20, "       ##xxx++++++xxx+#++#####");
mvaddstr(12, 20, "        +-x. ++++-x  +++#####");
mvaddstr(13, 20, "        ++++++++++++++++##+###");
mvaddstr(14, 20, "        #+++++++++++++++#####");
mvaddstr(15, 20, "         #++++88++++++#######");
mvaddstr(16, 20, "           +++++++++#######.");
mvaddstr(17, 20, "         #+####+###+++##+##");
mvaddstr(18, 20, "    #+#####+----+++----###+####+");
mvaddstr(19, 20, "  #+#+#####+-+++++++++###########.");
mvaddstr(20, 20, " ####+#++#.3+++++++++3++########### ");
mvaddstr(21, 20, " #######++..--+333.--#+#+#######+##+");
mvaddstr(22, 20, " ######++##..-...-...-+####+#####+###:");
mvaddstr(23, 20, " ##########.---.---.-####+###########+:");
mvaddstr(24, 20, " ##########.---.---.-####+###########++:");
        

        break;  
        
    case 4:
    mvaddstr(5, 70, "Buenas! estoy en busqueda de una pollera corta y simple.");
    mvaddstr(3,  20, "        .##############");
    mvaddstr(4,  20, "       *#################");
    mvaddstr(5,  20, "     ?####################");
    mvaddstr(6,  20, "      #####################");
    mvaddstr(7,  20, "     %##=:::################");
    mvaddstr(8,  20, "    ##:::::##################");
    mvaddstr(9,  20, "    =%::::%::###############");
    mvaddstr(10, 20, "    ####---:::###:##=:::#####");
    mvaddstr(11, 20, "     ##* @3::::=:@@3=:::##%");
    mvaddstr(12, 20, "     ##%:@@%:::::@@@@=:::%:");
    mvaddstr(13, 20, "    =##: %@:::::@@% ::::--");
    mvaddstr(14, 20, "     ##%=::::--:::::::::-::");
    mvaddstr(15, 20, "        :::::::::::::: ##");
    mvaddstr(16, 20, "          :::::::::-   %");
    mvaddstr(17, 20, "            :::::--:");
    mvaddstr(18, 20, "       -=%* -:::::::==*%");
    mvaddstr(19, 20, "   :=* =*##+.::::::+=%#-+:*#");
    mvaddstr(20, 20, " ++-%@ :**  . :::.  #%+* =*. **+");
    mvaddstr(21, 20, " .*=@@+**#*   ::  .**# #:%*:-==*.");
    mvaddstr(22, 20, " **-%@=.=+ . : .  -@+.=::%¡¨=*==.");
    mvaddstr(23, 20, "%+*=%-+==* :=%::%--== =.:#+++. *");
    mvaddstr(24, 20, ":.. ::.....:::. :......::::: . .:");
        

        break;
    }
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