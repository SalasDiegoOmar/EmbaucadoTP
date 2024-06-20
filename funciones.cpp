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
            return Opcion;

            break;

        case 2:
            return Opcion;

            break;

        case 3:
            return Opcion;

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
    char confirmacion;

    do
    {
        rlutil::cls();
        rlutil::showcursor();
        cout << endl;
        cout << "EMBAUCADO" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "Antes de comenzar deben registrar sus nombre: " << endl;
        cout << endl;
        cout << "¿Nombre del jugador 1? ";
        cin.ignore();
        getline(cin,Nombre_Jugador_1);
        cout << endl;
        cout << "¿Nombre del jugador 2? ";
        getline(cin,Nombre_Jugador_2);
        cout << endl;
        cout << "¿Confirmar Nombres? (S/N) " << endl;
        cout << endl;
        cout << endl << endl << "-------------------------------------------------" << endl;
        rlutil::locate(27,10);
        cin >> confirmacion;
        confirmacion = toupper(confirmacion);
        cin.ignore(100,'\n');


        while(confirmacion != 'S' && confirmacion != 'N')
        {
            cout << endl;
            cout << "ERROR solo se admite 'S' o 'N'" << endl;
            cout << endl;
            rlutil::anykey();
            rlutil::cls();
            cout << "\nConfirmar nombres (S/N): ";
            cin >> confirmacion;
            confirmacion = toupper(confirmacion);
            cin.ignore(100,'\n');
        }
        if(confirmacion == 'N')
        {
            cout << endl;
            cout << "Ingrese los nombres nuevamente\n";
            rlutil::anykey();
            rlutil::cls();
        }
        else
        {
            cout << "\n------------------------------------------------------------------------" << endl;
        }

        rlutil::cls();

    }
    while(confirmacion != 'S');

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
        cout << "\t" << MazoValor_J[x] << " " << MazoPalo_J[x] << endl;
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
    int VecNaipeValorPuntos[VALOR] = {10, 11, 12, 15, 20};
    string VecNaipeValor[VALOR] = {"10", "J", "Q", "K", "A"};
    string VecNaipePalo[PALO] = {"Corazones", "Diamantes", "Picas", "Treboles"};
    string BarajaValor[CARTAS];
    string BarajaPalo[CARTAS];
    string MazoValor_J1 [VALOR], MazoPalo_J1[VALOR];
    string MazoValor_J2[VALOR], MazoPalo_J2[VALOR];
    string Embaucado;
    string Nombre_Jugador_1, Nombre_Jugador_2;
    char confirmacion;
    int Puntos_Maximos_J1 = 0, Puntos_Maximos_J2 = 0, Num_Ronda;
    int Puntos_Ronda_J1[RONDAS] = {}, Puntos_Ronda_J2[RONDAS] = {};
    NombreJugadores(Nombre_Jugador_1, Nombre_Jugador_2);

    for(int x = 0; x < RONDAS; x ++)
    {

        Barajar_Cartas(VecNaipeValor,VecNaipePalo,BarajaValor,BarajaPalo,VALOR,PALO,CARTAS);
        Repartir_Cartas(BarajaValor,BarajaPalo,MazoValor_J1,MazoPalo_J1,MazoValor_J2,MazoPalo_J2,VALOR);
        Embaucado = CartaEmbaucadora(VecNaipePalo, PALO);

        Num_Ronda = x + 1;
        if(Num_Ronda == 1)  //RONDA 1
        {
            cout << endl;
            cout << " EMBAUCADO" << endl;
            cout << " ----------------------------------------------------" << endl;
            cout << " RONDA #" << Num_Ronda << endl;
            //cout << endl;
            cout << " " << Nombre_Jugador_1 << " Vs " << Nombre_Jugador_2 << endl;
            cout << endl;
            cout << "+---------------------------+" << endl;
            cout << "\t" << Nombre_Jugador_1 << "(" << Puntos_Maximos_J1 << ")" << endl;
            cout << endl;
            Mostrar_Cartas(MazoValor_J1,MazoPalo_J1,VALOR);
            rlutil::anykey();
            cout << endl;
            cout << "\t" << Nombre_Jugador_2 << "(" << Puntos_Maximos_J2 << ")" << endl;
            cout << endl;
            Mostrar_Cartas(MazoValor_J2,MazoPalo_J2,VALOR);
            rlutil::anykey();
            cout << endl;
            cout << "    Embaucadora: " << Embaucado << endl;
            cout << endl;
            cout << "+---------------------------+" << endl;
            cout << endl;

            cout << "Puntajes obtenidos:" << endl;
            cout << " ----------------------------------------------------" << endl;
            cout << Nombre_Jugador_1 << ": ";
            Puntos_Ronda_J1[x] = SumaPuntos(MazoValor_J1, MazoPalo_J1,Embaucado,VALOR);
            cout << " = " << Puntos_Ronda_J1[x] << " puntos" <<endl;
            cout << Nombre_Jugador_2 << ": ";
            Puntos_Ronda_J2[x] = SumaPuntos(MazoValor_J2, MazoPalo_J2, Embaucado, VALOR);
            cout << " = " << Puntos_Ronda_J2[x] << " puntos" <<endl;
            rlutil::anykey();
            rlutil::cls();
        }
        else if(Num_Ronda == 2) // RONDA 2
        {
            cout << endl;
            cout << " EMBAUCADO" << endl;
            cout << " ----------------------------------------------------" << endl;
            cout << " RONDA #" << Num_Ronda << endl;
            //cout << endl;
            cout << " " << Nombre_Jugador_1 << " Vs " << Nombre_Jugador_2 << endl;
            cout << endl;
            cout << "+---------------------------+" << endl;
            cout << "\t" << Nombre_Jugador_1 << "(" << Puntos_Maximos_J1 << ")" << endl;
            cout << endl;
            Mostrar_Cartas(MazoValor_J1,MazoPalo_J1,VALOR);
            cout << endl;
            cout << "    Embaucadora: " << Embaucado << endl;
            rlutil::anykey();
            cout << endl;
            cout << Nombre_Jugador_1 << " ¿Desea modificar la carta embaucadora actual? (" << Embaucado << ")?" << "(S/N):";
            cin >> confirmacion;
            confirmacion = toupper(confirmacion);
            cin.ignore(100,'\n');

            while(confirmacion != 'S' && confirmacion != 'N')
            {
                cout << endl;
                cout << "ERROR solo se admite 'S' o 'N'" << endl;
                cout << endl;
                rlutil::anykey();
                //rlutil::cls();
                cout << Nombre_Jugador_1 << " ¿Desea modificar la carta embaucadora actual? (" << Embaucado << ")?" << "(S/N):";
                cin >> confirmacion;
                confirmacion = toupper(confirmacion);
                cin.ignore(100,'\n');
            }
            if(confirmacion == 'S')
            {
                cout << endl;
                Embaucado = CartaEmbaucadora(VecNaipePalo, PALO);
                cout << "Se retan 20 punto por el uso del cambio de carta embaucadora" << endl;
                Puntos_Ronda_J1[x] -= 20;
                cout << endl;
                cout << "Nueva carta Embaucadora: " << Embaucado << endl;
                rlutil::anykey();
                cout << endl;
                cout << "\t" << Nombre_Jugador_2 << "(" << Puntos_Maximos_J2 << ")" << endl;
                cout << endl;
                Mostrar_Cartas(MazoValor_J2,MazoPalo_J2,VALOR);
                rlutil::anykey();
                cout << endl;
            }
            else
            {
                cout << endl;
                cout << "\t" << Nombre_Jugador_2 << "(" << Puntos_Maximos_J2 << ")" << endl;
                cout << endl;
                Mostrar_Cartas(MazoValor_J2,MazoPalo_J2,VALOR);
                cout << endl;
                cout << Nombre_Jugador_2 << " ¿Desea modificar la carta embaucadora actual? (" << Embaucado << ")?" << "(S/N):";
                cin >> confirmacion;
                confirmacion = toupper(confirmacion);
                cin.ignore(100,'\n');
                while(confirmacion != 'S' && confirmacion != 'N')
                {
                    cout << endl;
                    cout << "ERROR solo se admite 'S' o 'N'" << endl;
                    cout << endl;
                    //rlutil::anykey();
                    //rlutil::cls();
                    cout << Nombre_Jugador_2 << " ¿Desea modificar la carta embaucadora actual? (" << Embaucado << ")?" << "(S/N):";
                    cin >> confirmacion;
                    confirmacion = toupper(confirmacion);
                    cin.ignore(100,'\n');
                }
                if(confirmacion == 'S')
                {
                    Embaucado = CartaEmbaucadora(VecNaipePalo, PALO);
                    cout << endl;
                    cout << "Se retan 20 punto por el uso del cambio de carta embaucadora" << endl;
                    Puntos_Ronda_J2[x] -= 20;
                    cout << endl;
                    cout << "Nueva carta Embaucadora: " << Embaucado << endl;
                    //rlutil::anykey();
                    //rlutil::cls();
                }
            }
            cout << endl;
            cout << "+---------------------------+" << endl;
            cout << endl;
            cout << "Puntajes obtenidos:" << endl;
            cout << " ----------------------------------------------------" << endl;
            cout << Nombre_Jugador_1 << ": ";
            Puntos_Ronda_J1[x] = SumaPuntos(MazoValor_J1, MazoPalo_J1,Embaucado,VALOR);
            cout << " = " << Puntos_Ronda_J1[x] << " puntos" <<endl;
            cout << Nombre_Jugador_2 << ": ";
            Puntos_Ronda_J2[x] = SumaPuntos(MazoValor_J2, MazoPalo_J2, Embaucado, VALOR);
            cout << " = " << Puntos_Ronda_J2[x] << " puntos" <<endl;
            rlutil::anykey();
            rlutil::cls();



        }
    }


}



int SumaPuntos(string MazoValor_J[], string MazoPalo_J[], string CartaEmbaucado,int VALOR)
{
    int PuntajeRonda = 0;
    bool PrimerPunto = false;
    for(int x = 0; x < VALOR; x++)
    {
        if(MazoPalo_J[x] != CartaEmbaucado)
        {
            if(MazoValor_J[x] == "10")
            {
                PuntajeRonda += 10;
                if(PrimerPunto == false)
                {
                    cout << "10";
                    PrimerPunto = true;
                }
                else
                {
                    cout << " + 10";
                }
            }
            else if(MazoValor_J[x] == "J")
            {
                PuntajeRonda += 11;
                if(PrimerPunto == false)
                {
                    cout << "11";
                    PrimerPunto = true;
                }
                else
                {
                    cout << " + 11";
                }
            }
            else if(MazoValor_J[x] == "Q")
            {
                PuntajeRonda += 12;
                if(PrimerPunto == false)
                {
                    cout << "12";
                    PrimerPunto = true;
                }
                else
                {
                    cout << " + 12";
                }
            }
            else if(MazoValor_J[x] == "K")
            {
                PuntajeRonda += 15;
                if(PrimerPunto == false)
                {
                    cout << "15";
                    PrimerPunto = true;
                }
                else
                {
                    cout << " + 15";
                }
            }
            else
            {
                PuntajeRonda += 20;
                if(PrimerPunto == false)
                {
                    cout << "20";
                    PrimerPunto = true;
                }
                else
                {
                    cout << " + 20";
                }
            }
        }
    }
    return PuntajeRonda;
}
