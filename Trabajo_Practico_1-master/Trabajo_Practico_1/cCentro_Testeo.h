#pragma once

#include <iostream>
#include <string>
#include "cPaciente.h"
#include "cLaboratorio.h"

using namespace std;

class CentroDeTesteo
{
	//Atributos Descriptivos
	unsigned int ID_centro;
	string sid;
	string Comuna;
	string Nombre;
	//Atributos funcionales
	bool completo;
	cPaciente* paciente1;
	cPaciente* paciente2;
	cLaboratorio* laboratorio;
public:
#pragma region Constructores y Destructores
	CentroDeTesteo(unsigned int id_centro, string _Comuna, string _Nombre);
	~CentroDeTesteo();
#pragma region Metodos
	//Vinculacion y Desvinculacion del Laboratorio
	void Asociar_Laboratorio(cLaboratorio* lab);
	void Desasociar_Laboratorio();
	//Agregamos el paciente al centro y laboratorio
	void altapaciente(cPaciente* pac);
	void bajapaciente();
	//Pasamos las muetras al laboratorio
	void Mandar_Testeo(cPaciente* paciente, cLaboratorio* lab);

	string to_stringid(unsigned int id);
	unsigned int getid();
	void imprimircentro();

};