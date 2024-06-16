#include "funciones.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "rlutil.h"

using namespace std;

int Menu()
{
    int Opcion;
    do
    {
        rlutil::cls();
        cout << "EMBAUCADO" << endl;
        cout << "---------------------" << endl;
        cout << "1 - JUGAR" << endl;
        cout << "2 - ESTADÍSTICAS" << endl;
        cout << "3 - CRÉDITOS" << endl;
        cout << "---------------------" << endl;
        cout << "0 - SALIR" << endl;
        cout << endl;
        cin >> Opcion;
        cout << endl;

        switch(Opcion)
        {
        case 1:
            return 1;
            break;
        case 2:
            return 2;
            break;
        case 3:
            return 3;
            break;
        case 0:
            exit(0);
            break;
        default:
            break;

        }
    }
    while(Opcion != 0);

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


void Repartir_Cartas(string BarajaValor[], string BarajaPalo[], string MazoValor_J1[], string MazoPalo_J1[], string MazoValor_J2[], string MazoPalo_J2[])
{

    for(int x = 0; x < 5; x++)
    {
        MazoValor_J1[x] = BarajaValor[x];
        MazoPalo_J1[x] = BarajaPalo[x];
        MazoValor_J2[x] = BarajaValor[x + 5];
        MazoPalo_J2[x] = BarajaPalo[x + 5];
    }


}

void Mostrar_Cartas(string MazoValor_J[], string MazoPalo_J[], int VALOR)
{
    for(int x = 0; x < VALOR; x++)
    {
        cout << MazoValor_J[x] << " " << MazoPalo_J[x] << endl;
    }
}


