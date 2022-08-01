// ING-LP1-TP2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <time.h>
#include"cAeropuerto.h"
#include"cPasajero.h"
using namespace std;

int main()
{
    //Creación de Aeropuerto

    cAeropuerto* Aeropuerto_1 = new cAeropuerto("destino_2");

    //Crean los Aviones

    cAvion* Avion_001 = new cAvion("Avion_0001");
    cAvion* Avion_002 = new cAvion("Avion_0002");

    //Crean Vuelos 

    cVuelo* Vuelo_001 = new cVuelo("destino_1", 1, 1, 2000, 12, 30, 1, 1, 2000, 20, 30, EstadoVuelo::Partida);
    cVuelo* Vuelo_002 = new cVuelo("destino_2", 1, 1, 2000, 12, 30, 1, 1, 2000, 20, 30, EstadoVuelo::Arribo);

    //Asocia cada avion a un vuelo

    Vuelo_001->AsociarAvion(Avion_001);
    Vuelo_002->AsociarAvion(Avion_002);

    //Crean los pasajeros y se agrega su equipaje usando sobrecarga de operador +
    
    cPasajero* Pasajero_1 = new cPasajero("DNI_0001", "Nombre_0001", 1, 0);
    cPasajero* Pasajero_2 = new cPasajero("DNI_0002", "Nombre_0002", 1, 1);
    cPasajero* Pasajero_3 = new cPasajero("DNI_0003", "Nombre_0003", 1, 2);
    cPasajero* Pasajero_4 = new cPasajero("DNI_0004", "Nombre_0004", 2, 0);
    cPasajero* Pasajero_5 = new cPasajero("DNI_0005", "Nombre_0005", 2, 1);

    *(Pasajero_1) + 5;
    *(Pasajero_1) + 10;
    *(Pasajero_2) + 5;
    *(Pasajero_2) + 10;
    *(Pasajero_3) + 5;
    *(Pasajero_3) + 10;
    *(Pasajero_3) + 3;
    *(Pasajero_3) + 2;

    //Imprimir peso de las 2 valijas del Pasajero_1 usando operador []

    cout << "Peso de la valija 1:" + to_string(Pasajero_1[0][0]) << endl;
    cout << "Peso de la valija 2:" + to_string(Pasajero_1[0][1]) << endl;

    //Imprimen los datos de los pasajeros

    Pasajero_1->imprimir();
    Pasajero_2->imprimir();
    Pasajero_3->imprimir();

    //Eliminar Equipaje del pasajero usando sobrecarga del operador - 

    cout << "Elimino equipaje\n";

    *(Pasajero_2)-2;
    *(Pasajero_3)-2;
    *(Pasajero_1)-6;

    Pasajero_2->imprimir();
    Pasajero_3->imprimir();
    Pasajero_1->imprimir();

    //Agregan los pasajeros al  Vuelo_001

    Vuelo_001->AgregarPasajero(Pasajero_1);
    Vuelo_001->AgregarPasajero(Pasajero_2);
    Vuelo_001->AgregarPasajero(Pasajero_3);

    //Agregan los pasajeros Vuelo_002

    Vuelo_002->AgregarPasajero(Pasajero_4);
    Vuelo_002->AgregarPasajero(Pasajero_5);

    //Carga de Lista de aviones en el hangar del Aeropuerto
  
    Aeropuerto_1->getListaAviones()->AgregarAvion(Avion_001);
   
    //Carga de Lista de Vuelos en el Aeropuerto

    Aeropuerto_1->getListaVuelos()->AgregarVuelo(Vuelo_001);
    Aeropuerto_1->getListaVuelos()->AgregarVuelo(Vuelo_002);

    //Imprimo Vuelo_001 usando el metodo imprimir()

    Vuelo_001->imprimir();

    //Imprimo Vuelo_002 usando sobrecarga el operador <<

    cout << Vuelo_002;

    //Cambio a un pasajero de Vuelo_001 al Vuelo_002

    try {
        Vuelo_001->CambiarPasajero("DNI_0003", Vuelo_002);
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }

    //Despegue de Avion del Aeropuerto 

    Aeropuerto_1->Despegue();

    //Imprime los datos del vuelo_001 para comprobar si fue demorado para despegar

    Vuelo_001->imprimir();

    //Aterrizaje de un Avion en el aeropuerto 
    
    try {
       Aeropuerto_1->Aterrizaje(Vuelo_002);
       Vuelo_002->imprimir();
    }
    catch (exception&e) {
        cout << e.what() << endl;
    }
   
    //Fin del dia

    cout << "\nResumen del dia" << endl;
    Aeropuerto_1->imprimir();

    //Listar las personas de cada vuelo

    Vuelo_001->getAvion()->getListaPasajeros()->listar();
    Vuelo_002->getAvion()->getListaPasajeros()->listar();

    //Deletes

    delete Aeropuerto_1;
    delete Vuelo_001;
    delete Vuelo_002;
    delete Avion_001;
    delete Avion_002;    
    delete Pasajero_1;
    delete Pasajero_2;
    delete Pasajero_3;
    delete Pasajero_4;
    delete Pasajero_5;
   
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
