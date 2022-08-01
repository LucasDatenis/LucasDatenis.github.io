#pragma once
#include<string>
#include<iostream>
#include"cListaValijas.h"
using namespace std;
class cPasajero
{
private:
	string DNI;
	string Nombre;
	int NumeroVuelo;
	int Asiento;
	cListaValijas* ListaValijas;
	const float peso_prom = 75;
public:
	cPasajero();
	cPasajero(string DNI, string Nombre, int NumeroVuelo, int Asiento);
	~cPasajero();
	bool AgregarEquipaje(float peso);
	float getPeso();
	int getAsiento();
	string getDNI();
	string getNombre();
	void setNumeroVuelo(int NuevoNumeorVuelo);
	string to_stringPasajero();
	void imprimir();
	void operator + ( float valija );
	void operator - (int CantidadEliminar);
	float operator [] (int pos);
};

