#pragma once
using namespace std;
#include<string>
#include<stdlib.h>
#include<time.h>
#include "cFecha.h"
#include "cAvion.h"
#include "cPasajero.h"
#include "EstadoVuelo.h"


class cVuelo
{
private:
	static int NumeroVuelo;
	string ID;
	EstadoVuelo estado;
	cAvion* Avion = NULL;
	cFecha* PartidaProgramada = NULL;
	cFecha* ArriboProgramado = NULL;
	cFecha* PartidaReal = NULL;
	cFecha* ArriboReal = NULL;
	string destino;
	bool Demora;

public:
	cVuelo();
	cVuelo(string _destino, int P_dia, int P_mes, int P_anio, int P_hora, int P_minutos, int A_dia, int A_mes, int A_anio, int A_hora, int A_minutos,EstadoVuelo Estado);
	~cVuelo();
	bool AsociarAvion(cAvion* avion);
	void Retraso();
	bool AgregarPasajero(cPasajero* pasajero);
	void CambiarPasajero(string DNI, cVuelo* NuevoVuelo);
	void EliminarPasajero(string DNI);
	cPasajero* getPasajero(string DNI);
	int getNumeroVuelo();
	int getCantidadPasajerosVuelo();
	string getID();
	cAvion* getAvion();
	EstadoVuelo getEstadoVuelo();
	bool getDemora();
	void setEstadoVuelo(EstadoVuelo estado);
	string to_stringVuelo() const;
	void imprimir()const;
	friend ostream& operator<<(ostream& os, const cVuelo* vuelo);
};

