#include <iostream>
using namespace std;
#include "funciones.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include "rlutil.h"
#include <locale.h>

int main()
{
    setlocale(LC_CTYPE, "spanish");
    //const int CARTAS = 10, VALOR = 5,PALO = 4, RONDA = 3;
    //int VecRondaJuego[RONDA] = {1, 2, 3};
    //string VecNaipeValor[VALOR] = {"10", "J", "Q", "K", "A"};
    //string VecNaipePalo[PALO] = {"Corazones", "Diamantes", "Picas", "Treboles"};
    //string BarajaValor[CARTAS];
    //string BarajaPalo[CARTAS];
    //string MazoValor_J1 [VALOR], MazoPalo_J1[VALOR];
    //string MazoValor_J2[VALOR], MazoPalo_J2[VALOR];
    //string Embaucado;
    //string Nombre_Jugador_1, Nombre_Jugador_2;
    //int Puntos_Ronda1_J1 = 0, Puntos_Ronda1_J2 = 0;
    int Opcion_Menu;


    Opcion_Menu = Menu();

    while(Opcion_Menu != 0)
    {
        switch(Opcion_Menu)
        {
        case 1:
            Jugar();
            break;

        case 2:
            break;

        case 3:
            Creditos();
            break;

        case 0:
            exit(0);
            break;
        }
        Opcion_Menu = Menu();
    }
    return 0;
}












//NombreJugadores(Nombre_Jugador_1, Nombre_Jugador_2);
//Embaucado = CartaEmbaucadora(VecNaipePalo, PALO);
//Barajar_Cartas(VecNaipeValor, VecNaipePalo, BarajaValor, BarajaPalo, VALOR, PALO, CARTAS);
//Repartir_Cartas(BarajaValor,BarajaPalo,MazoValor_J1,MazoPalo_J1,MazoValor_J2,MazoPalo_J2);
//Mostrar_Cartas(MazoValor_J1, MazoPalo_J1,VALOR);
// Mostrar_Cartas(MazoValor_J2, MazoPalo_J2, VALOR);



