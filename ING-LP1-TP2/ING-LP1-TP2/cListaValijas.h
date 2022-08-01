#pragma once
#include"cValija.h"
class cListaValijas
{
private:
	const int CantidadMax = 5;
	const float PesoMax = 25;
	int CantidadValijas;
	cValija** ArrayValijas;
	float PesoActual;
public:
	cListaValijas();
	~cListaValijas();
	bool AgregarValija(float peso);
	bool EliminarValija(int CantidadEliminar);
	float getPesoEquipaje() { return PesoActual; };
	int getCantidadValijas() { return CantidadValijas; };
	float getPesoValija(int pos) { return ArrayValijas[pos]->getPeso(); }
};

