#pragma once
#include<string>
#include<iostream>
#include"cListaVehiculos.h"
#include"cAmbulancia.h"
#include"cAvion.h"
#include"cHelicoptero.h"
#include"cDonante.h"
#include"cReceptor.h"
using namespace std;
class cCentroDeSalud
{
private:
	string Nombre;
	string Direccion;
	string Partido;
	string Provincia;
	long int Telefono;
	cListaVehiculos* ListaDeVehiculosDisponibles = NULL;
public:
	cCentroDeSalud();
	cCentroDeSalud(string Nombre, string Direccion, string Partido, string Provincia, long int Telefono);
	~cCentroDeSalud();
	cVehiculo* AsignarVehiculo(cReceptor* ReceptorSelecionado, cDonante* DonanteSeleccionado);
	cOrgano* RealizarAblacion(cDonante* Donante,eTipoDeOrgano TipoDeOrganoParaExtraer);
	bool RealizarTransplante(cReceptor* ReceptorSeleccionado, cVehiculo* VehiculoDeTransplante);
	string GetPartido()const;
	string GetProvincia() const;
	string ToStringCentroDeSalud() const;
	void imprimir() const;
	friend ostream& operator<<(ostream& os, const cCentroDeSalud* CentroDeSalud);
	bool operator==(const cCentroDeSalud& OtroCentroDeSalud);
};

