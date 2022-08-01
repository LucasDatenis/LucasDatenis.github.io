#include "cAvion.h"
#include"cVuelo.h"
cAvion::cAvion() {
	this->ID = "";
	ListaPasajeros = new cListaPasajeros();
}

cAvion::cAvion(string ID) {
	this->ID = ID;
	ListaPasajeros = new cListaPasajeros();
}

cAvion::~cAvion() {
	delete ListaPasajeros;
}

float cAvion::CalcularPeso() {
	return (ListaPasajeros->CalcularPeso() + (Tripulacion * 75));
}

bool cAvion::AgregarPasajero(cPasajero* pasajero) {

	ListaPasajeros->AgregarPasajeros(pasajero);
	return true;
}

bool cAvion::BajaPasajero(string DNI) {
	ListaPasajeros->QuitarPasajero(DNI);
	return true;
}

bool cAvion::ChequearCargaMaxima() {
	if (CalcularPeso() <= PesoMaximo) {
		return true;
	}
	return false;
}

bool cAvion::ChequearCapacidadMaxima() {
	if (ListaPasajeros->getCantidadPasajeros() <= CapacidadPasajeros) {
		return true;
	}
	return false;
}

bool cAvion::Verificaciones() {
	if (ChequearCargaMaxima() == true && ChequearCapacidadMaxima() == true) {
		return true;
	}
	return false;
}

string cAvion::getID() {
	return ID;
}

bool cAvion::Despegar() {
	return Verificaciones();
}

int cAvion::getCantidadPasajeros() {
	return ListaPasajeros->getCantidadPasajeros();
}
cPasajero* cAvion::getPasajero(string DNI) {
	return ListaPasajeros->getPasajero(DNI);
}

cListaPasajeros* cAvion::getListaPasajeros() { 
	return ListaPasajeros; 
}