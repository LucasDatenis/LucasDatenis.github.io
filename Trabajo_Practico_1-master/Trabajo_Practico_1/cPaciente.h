#pragma once

#include <iostream>
#include <string>
#include <ctype.h>
#include <cstring>
#include "Enum.h"


using namespace std;

class cPaciente
{
private:
	friend class CentroDeTesteo;
	friend class cLaboratorio;
	string Nombre;
	string Apellido;
	long DNI;
	string sdni;
	string telefono;
	bool Tos;
	bool Mocos;
	bool Fiebre;
	bool Dolor_de_cabeza;
	bool Contacto_estrecho;
	bool Dolor_de_graganta;
	eResultadoTes resultado;
public:
	cPaciente(string _Nombre, string _Apellido, long _DNI, string _Telefono, bool Tos, bool Mocos, bool Fiebre, bool Dolor_de_cabeza, bool Contacto_estrecho, bool Dolor_de_garganta);
	~cPaciente();

	long getdni() {
		return this->DNI;
	}

	string to_stringdni(long DNI);

	void imprimirPaciente();
};