#pragma once
#include<string>
#include<iostream>
#include"cListaVuelos.h"
#include"cListaAviones.h"
using namespace std;

class cAeropuerto
{
private:
	string ID;
	cListaVuelos* ListaVuelos;
	cListaAviones* ListaAviones;
	int PasajerosDia;
	int VuelosDespegaron;
	int VuelosAterrizaron;
	int DespeguesDemorados;
	int AterrizajesDemorados;
	
public:
	friend cVuelo;
	cAeropuerto();
	cAeropuerto(string ID);
	~cAeropuerto();
	cListaVuelos* getListaVuelos();
	cListaAviones* getListaAviones();
	void Despegue();
	void Aterrizaje(cVuelo* vuelo);
	bool PermisoDespegar(int pos);//recibe la pos de un avion
	bool PermisoAterrizar();
	string toString();
	void imprimir();
};

