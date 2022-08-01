#include "cListaVuelos.h"

cListaVuelos::cListaVuelos(){
	this->CantidadVuelos = 0;
	this->ArrayVuelos = new cVuelo * [CantidadMax];
	for (int i = 0; i < CantidadMax; i++)
	{
		ArrayVuelos[i] = NULL;
	}
}

cListaVuelos::~cListaVuelos() {
	if (ArrayVuelos != NULL) {
		delete[] ArrayVuelos;
	}
}

bool cListaVuelos::AgregarVuelo(cVuelo* vuelo) {
	if (CantidadVuelos == CantidadMax) { return false; }
	int pos = getIndex(vuelo->getNumeroVuelo());
	if (pos >= 0) { return false; }
	this->ArrayVuelos[CantidadVuelos++] = vuelo;
	return true;
}

bool cListaVuelos::QuitarVuelo(int NumeroVuelo) {
	for (int i = 0; i < CantidadVuelos; i++)
	{
		if (ArrayVuelos[i]->getNumeroVuelo() == NumeroVuelo) {
			
			for (int p = i; p < CantidadVuelos-1; p++)
			{
				ArrayVuelos[p] = ArrayVuelos[p + 1];
			}
			ArrayVuelos[--CantidadVuelos] = NULL;
		}
	}
	return true;
}

int cListaVuelos::getIndex(int NumeroVuelo) {
	for (int i = 0; i < CantidadVuelos; i++) {
		if (ArrayVuelos[i]->getNumeroVuelo() == NumeroVuelo)
			return i;
	}
	return -1;
}