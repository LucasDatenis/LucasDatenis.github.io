#pragma once
#include "cVuelo.h"
using namespace std;
class cListaVuelos
{
private:
	const int CantidadMax = 10;
	int CantidadVuelos;
	cVuelo** ArrayVuelos;
public:
	friend class cAeropuerto; 
	cListaVuelos();
	~cListaVuelos();
	bool AgregarVuelo(cVuelo* vuelo);
	bool QuitarVuelo(int NumeroVuelo);
	int getIndex(int NumeroVuelo);
};

