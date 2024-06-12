#pragma once

#include <string>
using namespace std;


void Barajar_Cartas(string VecNaipeValor[], string VecNaipePalo[], string BarajaValor[], string BarajaPalo[], int VALOR, int PALO, int CARTAS);

void Repartir_Cartas(string BarajaValor[], string BarajaPalo[], string MazoValor_J1[], string MazoPalo_J1[], string MazoValor_J2[], string MazoPalo_J2[]);

string CartaEmbaucadora(string VecNaipePalo[], int CANT_PALOS);

void Mostrar_Cartas(string MazoValor_J[], string MazoPalo_J[], int VALOR);
