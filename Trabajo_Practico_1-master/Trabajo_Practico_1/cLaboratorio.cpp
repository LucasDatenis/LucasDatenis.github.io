#define _CRT_SECURE_NO_WARNINGS

#include "cLaboratorio.h"
#include "cPaciente.h"

cLaboratorio::cLaboratorio(unsigned int _ID_laboratorio, string _Nombre, string _Comuna)
{
	this->ID_laboratorio = _ID_laboratorio;
	this->Nombre = _Nombre;
	this->Comuna = _Comuna;
	this->sid = "";
	this->paciente = NULL;
	this->paciente2 = NULL;
	this->apaciente1 = NULL;
	this->apaciente2 = NULL;
	this->pacsintel1 = NULL;
	this->pacsintel2 = NULL;
	this->comple = false;
}

cLaboratorio::~cLaboratorio()
{

}

void cLaboratorio::RecibirMuestra()
{
	if (comple == false)
	{
		if (paciente == NULL)
		{
			paciente = apaciente1;
		}
		else
		{
			if (paciente2 == NULL)
			{
				paciente2 = apaciente2;
				comple = true;
			}
			else
				comple = true;
		}
	}
	else
	{
		cout << "La muestra no puede ser recibida" << endl;
	}
}
void cLaboratorio::AnalisisMuestra()
{
	//Paciente numero 1
	if (paciente != NULL)
	{
		int sintomas_totales = 0;
		if (paciente->Tos == true)
			sintomas_totales++;
		if (paciente->Mocos == true)
			sintomas_totales++;
		if (paciente->Fiebre == true)
			sintomas_totales++;
		if (paciente->Dolor_de_cabeza == true)
			sintomas_totales++;
		if (paciente->Dolor_de_graganta == true)
			sintomas_totales++;
		if (paciente->Contacto_estrecho == true)
			sintomas_totales++;

		if (sintomas_totales >= 2)
			paciente->resultado = eResultadoTes::Positivo;
		else if (sintomas_totales < 2)
			paciente->resultado = eResultadoTes::Negativo;
	}
	//Paciente numero 2
	if (paciente2 != NULL)
	{
		int sintomas_totales2 = 0;
		if (paciente2->Tos == true)
			sintomas_totales2++;
		if (paciente2->Mocos == true)
			sintomas_totales2++;
		if (paciente2->Fiebre == true)
			sintomas_totales2++;
		if (paciente2->Dolor_de_cabeza == true)
			sintomas_totales2++;
		if (paciente2->Dolor_de_graganta == true)
			sintomas_totales2++;
		if (paciente2->Contacto_estrecho == true)
			sintomas_totales2++;

		if (sintomas_totales2 >= 2)
			paciente2->resultado = eResultadoTes::Positivo;
		else if (sintomas_totales2 < 2)
			paciente2->resultado = eResultadoTes::Negativo;
	}
}

void cLaboratorio::avisarpaciente()
{
	if(paciente != NULL)
	{
		int vertelefono = 0;
		for (int aumento = 0; aumento < paciente->telefono.length(); aumento++)
		{
			if (paciente->telefono[aumento] == '-' || paciente->telefono[aumento] == ' ')
				aumento++;
			else if (isdigit(paciente->telefono[aumento]) == 0)
				vertelefono = 1;
		}
		if (paciente->telefono == "")
			vertelefono = 1;
		else if (paciente->telefono == " ")
			vertelefono = 1;
		if (vertelefono == 1)
		{
			cout << "No se pudo contactar con el paciente: " << paciente->Apellido << endl;
			pacsintel1 = paciente;
			paciente = NULL;
			comple = false;
		}
		else
		{
			cout << "Se mando un mensaje a " << paciente->Apellido << " con su resultado" << endl;
			paciente = NULL;
			apaciente1 = NULL;
			comple = false;
		}
	}
	if (paciente2 != NULL)
	{
		/*
		if (paciente2->telefono == "")
		{
			cout << "No se podido contactar con el paciente: " << paciente2->Apellido << endl;
			pacsintel2 = paciente2;
			paciente2 = NULL;
			comple = false;
		}
		else if (paciente2->telefono == " ")
		{
			cout << "No se podido contactar con el paciente: " << paciente2->Apellido << endl;
			pacsintel2 = paciente2;
			paciente2 = NULL;
			comple = false;
		}
		else if (paciente2->telefono == "\0")
		{
			cout << "No se podido contactar con el paciente: " << paciente2->Apellido << endl;
			pacsintel2 = paciente2;
			paciente2 = NULL;
			comple = false;
		}
		*/
		int vertelefono = 0;
		for (int aumento = 0; aumento < paciente2->telefono.length(); aumento++)
		{
			if (paciente2->telefono[aumento] == '-' || paciente2->telefono[aumento] == ' ')
				aumento++;
			else if (isdigit(paciente2->telefono[aumento]) == 0)
				vertelefono = 1;
		}
		if (paciente2->telefono == "")
			vertelefono = 1;
		else if (paciente2->telefono == " ")
			vertelefono = 1;
		if (vertelefono == 1)
		{
			cout << "No se pudo contactar con el paciente: " << paciente2->Apellido << endl;
			pacsintel2 = paciente2;
			paciente2 = NULL;
			comple = false;
		}
		else
		{
			cout << "Se mando un mensaje a " << paciente2->Apellido << " con su resultado" << endl;
			paciente2 = NULL;
			apaciente2 = NULL;
			comple = false;
		}
	}
}

void cLaboratorio::imprimirlaboratorio()
{
	cout << "Id del laboratorio: " << sid << endl;
	cout << "Nombre del Laboratorio: " << Nombre << endl;
	cout << "Ubicacion: " << Comuna << endl << endl;
}

unsigned int cLaboratorio::getid(){ return this->ID_laboratorio; }

string cLaboratorio::to_stringid(unsigned int id)
{
	this->sid = to_string(ID_laboratorio);
	return this->sid;
}