#include "cPasajero.h"
cPasajero::cPasajero() {
	this->DNI = "";
	this->Nombre = "";
	this->NumeroVuelo = 0;
	this->Asiento = 0;
	this->ListaValijas = new cListaValijas();
}

cPasajero::cPasajero(string DNI, string Nombre, int NumeroVuelo, int Asiento){
	this->DNI = DNI;
	this->Nombre = Nombre;
	this->NumeroVuelo = NumeroVuelo;
	this->Asiento = Asiento;
	this->ListaValijas = new cListaValijas();
}

cPasajero::~cPasajero() {
	delete ListaValijas;
}

bool cPasajero::AgregarEquipaje(float peso) {
	this->ListaValijas->AgregarValija(peso);
	return true;
}

float cPasajero::getPeso() {
	float PesoPasajeroConEquipaje = (ListaValijas->getPesoEquipaje()) + peso_prom;
	return PesoPasajeroConEquipaje;
}

int cPasajero::getAsiento() {
	return Asiento;
}

string cPasajero::getDNI() { 
	return DNI; 
}
string cPasajero::getNombre() {
	return Nombre; 
}

void cPasajero::setNumeroVuelo(int NuevoNumeroVuelo) {
	this->NumeroVuelo = NuevoNumeroVuelo;
}

string cPasajero::to_stringPasajero() {
	return 
		"\tNombre: " + Nombre + 
		"\tDNI: " + DNI +
		"\tNumero de vuelo: " + to_string(NumeroVuelo) +
		"\tAsiento asignado: " + to_string(Asiento) +
		"\tCantidad de Valijas: "+ to_string(ListaValijas->getCantidadValijas()) + 
		"\tPeso Equipaje: " + to_string(ListaValijas->getPesoEquipaje()) + 
		"\tPeso Pasajero+Equipaje: " + to_string(getPeso());
}

void cPasajero::imprimir() {
	cout << to_stringPasajero() << endl;
}

void cPasajero::operator+ ( float valija) {
	AgregarEquipaje(valija);
}

void cPasajero::operator-( int CantidadEliminar) {
	ListaValijas->EliminarValija(CantidadEliminar);
}

float cPasajero::operator [] (int pos) {
	float peso;
	peso = ListaValijas->getPesoValija(pos);
	return peso;
}