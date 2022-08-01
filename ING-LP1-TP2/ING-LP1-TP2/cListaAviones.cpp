#include "cListaAviones.h"
cListaAviones::cListaAviones() {
	this->CantidadAviones = 0;
	this->ArrayAviones = new cAvion * [CantidadMax];
	for (int i = 0; i < CantidadMax; i++)
	{
		ArrayAviones[i] = NULL;
	}
}

cListaAviones::~cListaAviones() {
	if (ArrayAviones != NULL) {
		delete[] ArrayAviones;
	}
}

bool cListaAviones::AgregarAvion(cAvion* avion) {
	if (CantidadAviones == CantidadMax) { return false; }
	int pos = getIndex(avion->getID());
	if (pos >= 0) { return false; }
	this->ArrayAviones[CantidadAviones++] = avion;
	return true;
}
bool cListaAviones::QuitarAvion(cAvion*avion) { 
	for (int i = 0; i < CantidadAviones; i++)
	{
		if (ArrayAviones[i]->getID()==avion->getID()){

			for (int p = i; p < CantidadAviones - 1; p++)
			{
				ArrayAviones[p] = ArrayAviones[p + 1];
			}
			ArrayAviones[--CantidadAviones] = NULL;
		}
	}
	return true;

}

int cListaAviones::getIndex(string ID) {
	for (int i = 0; i < CantidadAviones; i++) {
		if (ArrayAviones[i]->getID() == ID)
			return i;
	}
	return -1;
}