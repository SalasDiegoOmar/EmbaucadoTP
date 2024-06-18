#include "funciones.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "rlutil.h"


using namespace std;


int Menu()
{
    int Opcion;
    bool Menu_Opcion = false;

    while(Menu_Opcion == false)
    {
        rlutil::cls();
        cout << endl;
        cout << "     EMBAUCADO" << endl;
        cout << "---------------------" << endl;
        cout << " 1 - JUGAR" << endl;
        cout << " 2 - ESTADÍSTICAS" << endl;
        cout << " 3 - CRÉDITOS" << endl;
        cout << "---------------------" << endl;
        cout << " 0 - SALIR" << endl;
        cout << endl;
        rlutil::hidecursor();

        while(!(cin >> Opcion))
        {
            rlutil::cls();
            cout << endl;
            cout << "ERROR: Ingreso invalido" << endl;
            cout << endl;
            rlutil::anykey();
            rlutil::cls();
            cout << endl;
            cout << "     EMBAUCADO" << endl;
            cout << "---------------------" << endl;
            cout << " 1 - JUGAR" << endl;
            cout << " 2 - ESTADÍSTICAS" << endl;
            cout << " 3 - CRÉDITOS" << endl;
            cout << "---------------------" << endl;
            cout << " 0 - SALIR" << endl;
            cout << endl;

            cin.clear();
            cin.ignore(100,'\n');
        }

        switch(Opcion)
        {
        case 1:
            Menu_Opcion = true;
            return Opcion;
            rlutil::showcursor();
            break;

        case 2:
            Menu_Opcion = true;
            return Opcion;
            rlutil::showcursor();
            break;

        case 3:
            Menu_Opcion = true;
            return Opcion;
            rlutil::showcursor();
            break;

        case 0:
            Menu_Opcion = true;
            exit(0);
            rlutil::showcursor();
            break;

        default:
            break;
        }
    }
return 0;
}



//TIENE LA FUNCION toupper(); PARA QUE CONVIERTA LA LETRA MINUSCULA EN MAYUSCULA Y NO SE ERROR EN EL SWITCH,
// SE AGREGO EL RLUTIL CLS PARA QUE LIMPIE LA PANTALLA Y EL ANYKEY PARA RETARDAR LAS OPCIONES
// rlutil locate para ubicar el cursor en (S/N)

void NombreJugadores(string &Nombre_Jugador_1, string &Nombre_Jugador_2)
{
    char Opcion;

    do
    {
        rlutil::cls();
        cout << "EMBAUCADO" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "Antes de comenzar deben registrar sus nombre: " << endl;
        cout << endl;
        cout << "¿Nombre del jugador 1? ";
        cin >> Nombre_Jugador_1;
        cout << "¿Nombre del jugador 2? ";
        cin >> Nombre_Jugador_2;
        cout << endl;
        cout << "¿Confirmar Nombres? (S/N) " << endl;
        cout << endl << "-------------------------------------------------" << endl;
        rlutil::locate(27,8);
        cin >> Opcion;

        Opcion = toupper(Opcion);
        switch (Opcion)
        {
        case 'S':
            rlutil::cls();
            cout << endl;
            break;
        case 'N':
            cout << "Vuelva a registrar nuevamente los nombres" << endl;
            rlutil::anykey();
            rlutil::cls();
            break;
        default:
            cout << "Opcion incorrecta." << endl;
            rlutil::anykey();
            rlutil::cls();
            cout << "¿Confirmar Nombres? (S/N) ";
            cin >> Opcion;
            Opcion = toupper(Opcion);
            switch (Opcion)
            {
            case 'S':
                rlutil::cls();
                cout << endl;
                break;
            case 'N':
                cout << "Vuelva a registrar nuevamente los nombres" << endl;
                rlutil::anykey();
                rlutil::cls();
                break;
            default:
                cout << "Opcion incorrecta." << endl;
                cout << "Vuelva a registrar nuevamente los nombres" << endl;
                rlutil::anykey();
                rlutil::cls();
                break;
            }
        }

    }
    while(Opcion != 'S');
}





string CartaEmbaucadora(string VecNaipePalo[], int CANT_PALOS)
{
    srand(time(0));
    int NumAzar;
    string Carta;
    NumAzar = rand() % CANT_PALOS;
    return Carta = VecNaipePalo[NumAzar];



}

void Barajar_Cartas(string VecNaipeValor[], string VecNaipePalo[], string BarajaValor[], string BarajaPalo[], int VALOR, int PALO, int CARTAS)
{

    bool Repetidos = true;
    int ContadorRepetidos = 0, NumAzar;
    string RepetidaValor, RepetidaPalo;

    srand(time(0));

    while(Repetidos == true)
    {
        for(int x = 0; x < CARTAS; x ++)
        {
            NumAzar = rand() % VALOR;
            BarajaValor[x] = VecNaipeValor[NumAzar];
            NumAzar = rand() % PALO;
            BarajaPalo[x] = VecNaipePalo[NumAzar];
        }
        for(int x = 0; x < CARTAS; x ++)
        {
            RepetidaValor = BarajaValor[x];
            RepetidaPalo = BarajaPalo[x];

            for(int i = 0; i < CARTAS; i ++)
            {
                if(RepetidaValor == BarajaValor[i] && RepetidaPalo == BarajaPalo[i])
                {
                    ContadorRepetidos ++;
                }
            }
        }
        if(ContadorRepetidos == 10)
        {
            Repetidos = false;
        }
        else
        {
            ContadorRepetidos = 0;
        }
    }


}


void Repartir_Cartas(string BarajaValor[], string BarajaPalo[], string MazoValor_J1[], string MazoPalo_J1[], string MazoValor_J2[], string MazoPalo_J2[], int VALOR)
{

    for(int x = 0; x < VALOR; x++)
    {
        MazoValor_J1[x] = BarajaValor[x];
        MazoPalo_J1[x] = BarajaPalo[x];
        MazoValor_J2[x] = BarajaValor[x + VALOR];
        MazoPalo_J2[x] = BarajaPalo[x + VALOR];
    }


}

void Mostrar_Cartas(string MazoValor_J[], string MazoPalo_J[], int VALOR)
{
    for(int x = 0; x < VALOR; x++)
    {
        cout << MazoValor_J[x] << " " << MazoPalo_J[x] << endl;
    }
}



void Creditos()
{
    rlutil::cls();
    cout << endl;
    cout << "Tecnicatura Universitaria en Programación" << endl;
    cout << endl;
    cout << "\t\tGrupo 9" << endl;
    cout << endl;
    cout << "30490 Natalia Patricia Mucci" << endl;
    cout << endl;
    cout << "30591 Diego Omar Salas" << endl;
    cout << endl;
    cout << "Juego inventado por Angel Simón." << endl;
    cout << "Inspirado levemente en un juego Push your luck de Bob Lancaster." << endl;
    cout << endl;
    cout << "Presione cualquier tecla para continuar....";
    rlutil::anykey();

}


void Jugar()
{

    setlocale(LC_CTYPE, "spanish");
    const int CARTAS = 10, VALOR = 5,PALO = 4, RONDAS = 3;
    string VecNaipeValor[VALOR] = {"10", "J", "Q", "K", "A"};
    string VecNaipePalo[PALO] = {"Corazones", "Diamantes", "Picas", "Treboles"};
    string BarajaValor[CARTAS];
    string BarajaPalo[CARTAS];
    string MazoValor_J1 [VALOR], MazoPalo_J1[VALOR];
    string MazoValor_J2[VALOR], MazoPalo_J2[VALOR];
    string Embaucado;
    string Nombre_Jugador_1, Nombre_Jugador_2;
    int Puntos_Maximos_J1 = 0, Puntos_Maximos_J2 = 0, Puntos_Ronda1_J1 = 0, Puntos_Ronda1_J2 = 0, Num_Ronda;

    NombreJugadores(Nombre_Jugador_1, Nombre_Jugador_2);

    for(int x = 0; x < RONDAS; x ++)
    {

        Barajar_Cartas(VecNaipeValor,VecNaipePalo,BarajaValor,BarajaPalo,VALOR,PALO,CARTAS);
        Repartir_Cartas(BarajaValor,BarajaPalo,MazoValor_J1,MazoPalo_J1,MazoValor_J2,MazoPalo_J2,VALOR);
        Embaucado = CartaEmbaucadora(VecNaipePalo, PALO);

        Num_Ronda = x + 1;

        cout << "EMBAUCADO" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        cout << "RONDA #" << Num_Ronda << endl;
        cout << Nombre_Jugador_1 << " Vs " << Nombre_Jugador_2 << endl;
        cout << endl;
        cout << endl;
        cout << Nombre_Jugador_1 << "(" << Puntos_Maximos_J1 << ")" << endl;
        cout << endl;
        Mostrar_Cartas(MazoValor_J1,MazoPalo_J1,VALOR);
        rlutil::anykey();
        cout << endl;
        cout << Nombre_Jugador_2 << "(" << Puntos_Maximos_J2 << ")" << endl;
        cout << endl;
        Mostrar_Cartas(MazoValor_J2,MazoPalo_J2,VALOR);
        cout << endl;
        cout << "Embaucadora: " << Embaucado << endl;
        rlutil::anykey();
        rlutil::cls();

    }

}
