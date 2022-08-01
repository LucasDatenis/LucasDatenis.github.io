#include "cCentro_Testeo.h"

CentroDeTesteo::CentroDeTesteo(unsigned int id_centro, string _Comuna, string _Nombre)
{
	this->ID_centro = id_centro;
	this->Nombre = _Nombre;
	this->Comuna = _Comuna;
	this->sid = "";
	this->completo = false;
	this->laboratorio = NULL;
	this->paciente1 = NULL;
	this->paciente2 = NULL;
}

CentroDeTesteo::~CentroDeTesteo()
{

}

void CentroDeTesteo::Asociar_Laboratorio(cLaboratorio* lab)
{
	laboratorio = lab;
}

void CentroDeTesteo::Desasociar_Laboratorio()
{
	laboratorio = NULL;
}

void CentroDeTesteo::Mandar_Testeo(cPaciente* pac, cLaboratorio* lab)
{
	if (lab->apaciente1 == NULL)
	{
		lab->apaciente1 = pac;
	}
	else
	{
		lab->apaciente2 = pac;
	}
}


void CentroDeTesteo::altapaciente(cPaciente* pac)
{
	if (completo != true)
	{
		if (paciente1 == NULL)
			paciente1 = pac;
		else
		{
			paciente2 = pac;
			completo = true;
		}
	}
	else
		cout << "No hay mas espacios para muestras, espere a que se desocupe un cupo" << endl;
	
}

void CentroDeTesteo::bajapaciente()
{
	if (paciente1 != NULL)
	{
		if (paciente1->resultado != eResultadoTes::Sin_Resultado)
		{
			paciente1 = NULL;
			completo = false;
		}
	}
	else
	{
		if (paciente2->resultado != eResultadoTes::Sin_Resultado)
		{
			paciente2 = NULL;
			completo = false;
		}
	}

}

void CentroDeTesteo::imprimircentro()
{
	cout << "Id del centro: " << ID_centro << endl;
	cout << "Nombre del centro: " << Nombre << endl; 
	cout << "Ubicacion: " << Comuna << endl << endl;
}

unsigned int CentroDeTesteo::getid() { return this->ID_centro; }

string CentroDeTesteo::to_stringid(unsigned int id)
{
	this->sid = to_string(ID_centro);
	return this->sid;
}