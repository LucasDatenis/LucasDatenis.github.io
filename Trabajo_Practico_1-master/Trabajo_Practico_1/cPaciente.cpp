#include "cPaciente.h"


cPaciente::cPaciente(string _Nombre, string _Apellido, long _DNI, string _Telefono, bool Tos, bool Mocos, bool Fiebre, bool Dolor_de_cabeza, bool Contacto_estrecho, bool Dolor_de_garganta)
{
	//Constructor del paciente
	int vernombre = 0;
	int verapellido = 0;
	int vertelefono = 0;
	int aumento = 0;
	for (aumento = 0; aumento < _Nombre.length(); aumento++)
	{
		if (isalpha(_Nombre[aumento]) == 0)
			vernombre = 1;
	}
	if (vernombre == 0)
		this->Nombre = _Nombre;
	else
		cout << "El nombre "<< _Nombre << " no es valido" << endl;

	for (aumento = 0; aumento < _Apellido.length(); aumento++)
	{
		if (isalpha(_Apellido[aumento]) == 0)
			verapellido = 1;
	}
	if (verapellido == 0)
		this->Apellido = _Apellido;
	else
		cout << "El Apellido " << _Apellido << " no es valido" << endl;
	this->Nombre;
	this->Apellido;
	this->DNI = _DNI;
	this->sdni = "";
	this->telefono = _Telefono;
	this->Tos = Tos;
	this->Mocos = Mocos;
	this->Fiebre = Fiebre;
	this->Dolor_de_cabeza = Dolor_de_cabeza;
	this->Dolor_de_graganta = Dolor_de_garganta;
	this->Contacto_estrecho = Contacto_estrecho;
	this->resultado = eResultadoTes::Sin_Resultado;
}
cPaciente::~cPaciente()
{
	//NO hay nada que destruir
}

string cPaciente::to_stringdni(long DNI)
{
	this->sdni = to_string(DNI);
	return this->sdni;
}

void cPaciente::imprimirPaciente()
{
	cout << Nombre << ", " << Apellido << endl << "DNI: " << sdni << endl << "Telefono: " << telefono << endl << endl;
}
