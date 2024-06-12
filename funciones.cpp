#include "funciones.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

string CartaEmbaucadora(string VecNaipePalo[], int CANT_PALOS){
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

void Mostrar_Cartas(string MazoValor_J[], string MazoPalo_J[], int VALOR){
    for(int x = 0; x < VALOR; x++){
        cout << MazoValor_J[x] << " " << MazoPalo_J[x] << endl;
    }
}

