#pragma once
#include <iostream>
#include <string>
#include "cPaciente.h"

using namespace std;

class cLaboratorio {
	//Atributos descriprivos
	friend class CentroDeTesteo;
	unsigned int ID_laboratorio;
	string sid;
	string Nombre;
	string Comuna;
	//Atributos Funcionales
	bool comple;
	cPaciente* paciente;
	cPaciente* paciente2;
	cPaciente* apaciente1;
	cPaciente* apaciente2;
	cPaciente* pacsintel1;
	cPaciente* pacsintel2;
public:

	cLaboratorio(unsigned int _ID_laboratorio, string _Nombre, string _Comuna);
	~cLaboratorio();

	void RecibirMuestra();
	void AnalisisMuestra();
	void avisarpaciente();

	string to_stringid(unsigned int id);
	unsigned int getid();
	void imprimirlaboratorio();
};