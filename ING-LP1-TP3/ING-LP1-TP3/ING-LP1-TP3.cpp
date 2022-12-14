// ING-LP1-TP3.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include"cINCUCAI.h"

using namespace std;

int main(){

	//INCUCAI
	cINCUCAI* INCUCAI = new cINCUCAI();
	//Centros de Salud
	cCentroDeSalud* CentroDeSalud1 = new cCentroDeSalud("Centro1", "Direccion1", "Partido1", "Provincia1", 11111);
	cCentroDeSalud* CentroDeSalud2 = new cCentroDeSalud("Centro2", "Direccion2", "Partido2", "Provincia1", 22222);
	cCentroDeSalud* CentroDeSalud3 = new cCentroDeSalud("Centro3", "Direccion3", "Partido1", "Provincia1", 33333);
	//Donantes
	cDonante* Donante1 = new cDonante("Nombre Donante 1 ", "1111", eTipoDeSangre::AB_Negativo, 1, 1, 2000, 1, 1, CentroDeSalud1, 5, 5, 2030, 16, 26);
	//Recpetores
	cReceptor* Receptor1 = new cReceptor("Nombre Recpetor 1 ", "123", eTipoDeSangre::AB_Negativo, 16, 02, 2000, 16, 50, CentroDeSalud3, 1, 01, 2020, 16, 50, ePrioridad::Alta, "Patologia", eEstadoReceptor::Estable, eTipoDeOrgano::Corazon);
	cReceptor* Receptor2 = new cReceptor("Nombre Recpetor 2 ", "123", eTipoDeSangre::AB_Negativo, 16, 02, 2000, 16, 50, CentroDeSalud2, 1, 01, 2020, 16, 50, ePrioridad::Alta, "Patologia", eEstadoReceptor::Estable, eTipoDeOrgano::Higado);
	//Carga Centros de salud en INCUCAI
	try {
		INCUCAI->CargaDeCentroDeSalud(CentroDeSalud1);
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
	try {
		INCUCAI->CargaDeCentroDeSalud(CentroDeSalud2);
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
	try {
		INCUCAI->CargaDeCentroDeSalud(CentroDeSalud3);
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}

	//Incucai recibe receptor 1 
	try {
		INCUCAI->IngresarPaciente(Receptor1);
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
	//Bucar un receptor en la lista de receptores e informar sus datos
	INCUCAI->BuscarReceptorinformarDatos("123");

	//Incucai recibe donante 1
	try {
		INCUCAI->IngresarPaciente(Donante1);
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
	//Incucai recibe receptor 2
	try {
		INCUCAI->IngresarPaciente(Receptor2);
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}


	INCUCAI->imprimir();
	delete Donante1;
	delete Receptor1;
	delete Receptor2;
	delete CentroDeSalud1;
	delete CentroDeSalud2;
	delete CentroDeSalud3;
	delete INCUCAI;
	return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
