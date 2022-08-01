#pragma once
#include"cAvion.h"
using namespace std;
class cListaAviones
{
private:
	const int CantidadMax = 10;
	int CantidadAviones;
	cAvion** ArrayAviones;
public:
	cListaAviones();
	~cListaAviones();
	bool AgregarAvion(cAvion* avion);
	bool QuitarAvion(cAvion* avion);
	int getCapacidadMaximaHangar() { return CantidadMax; };
	int getCantidadAviones() { return CantidadAviones; };
	int getIndex(string ID);
};

