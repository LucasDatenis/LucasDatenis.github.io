#include "cAeropuerto.h"

cAeropuerto::cAeropuerto() {
	this->ID = "";
	this->PasajerosDia = 0;
	this->VuelosDespegaron = 0;
	this->VuelosAterrizaron = 0;
	this->DespeguesDemorados = 0;
	this->AterrizajesDemorados = 0;
	this->ListaVuelos = new cListaVuelos();
	this->ListaAviones = new cListaAviones();
}

cAeropuerto::cAeropuerto(string ID) {
	this->ID = ID;
	this->PasajerosDia = 0;
	this->VuelosDespegaron = 0;
	this->VuelosAterrizaron = 0;
	this->DespeguesDemorados = 0;
	this->AterrizajesDemorados = 0;
	this->ListaVuelos = new cListaVuelos();
	this->ListaAviones = new cListaAviones();
}

cAeropuerto::~cAeropuerto() {
	delete ListaAviones;
	delete ListaVuelos;
}

cListaVuelos* cAeropuerto::getListaVuelos() {
	return ListaVuelos;
}

cListaAviones* cAeropuerto::getListaAviones() {
	return ListaAviones;
}

void cAeropuerto::Despegue() {

	//Revisa la lista de vuelos y despegan automaticamente los vuelos si son Partida quitandolo de la lista de avion y de vuelos

	for (int i = 0; i < ListaVuelos->CantidadMax; i++)
	{
		if (ListaVuelos->ArrayVuelos[i] != NULL) {
			if (ListaVuelos->ArrayVuelos[i]->getEstadoVuelo() == EstadoVuelo::Partida && PermisoDespegar(i) == true) {
				//Evento random para generar una posible demora antes de despegar
				ListaVuelos->ArrayVuelos[i]->Retraso();
				//Revisa se se hay demora
				if (ListaVuelos->ArrayVuelos[i]->getDemora() == true) { DespeguesDemorados++; }
				//Incremento cantidad de pasajeros del dia
				PasajerosDia = PasajerosDia + ListaVuelos->ArrayVuelos[i]->getCantidadPasajerosVuelo();
				//Cambia el estado a arribo para cuando llegue al aeropuerto de destino
				ListaVuelos->ArrayVuelos[i]->setEstadoVuelo(EstadoVuelo::Arribo);
				//Elimino el avion de la lista del hangar del aeropuerto
				ListaAviones->QuitarAvion(ListaVuelos->ArrayVuelos[i]->getAvion());
				VuelosDespegaron++;
			}
		}
	}
}

void cAeropuerto::Aterrizaje(cVuelo* vuelo) {
	// Pasando como parametro el vuelo que va a aterrizar
	if (PermisoAterrizar() == true){
		PasajerosDia = PasajerosDia + vuelo->getCantidadPasajerosVuelo();
		ListaAviones->AgregarAvion(vuelo->getAvion());
		if (vuelo->getDemora() == true) { AterrizajesDemorados++; }
		VuelosAterrizaron++;
	}
}

bool cAeropuerto::PermisoDespegar(int pos) {
	if (ListaVuelos->ArrayVuelos[pos]->getAvion()->Despegar() == true) return true;
	else return false;
}

bool cAeropuerto::PermisoAterrizar(){
	if (ListaAviones->getCantidadAviones() < ListaAviones->getCapacidadMaximaHangar()) return true;
	throw exception ("No hay lugar");
}

string cAeropuerto::toString(){
	return "\n\tID aeropuerto:" + ID + 
		"\n\tPasajeros del dia:" + to_string(PasajerosDia) +
		"\n\tVuelos Despegaron:" + to_string(VuelosDespegaron) + 
		"\n\tVuelos Despegaron Demorados:" + to_string(DespeguesDemorados) +
		"\n\tPorcentaje de vuelos que despegaron a horario:" + to_string(((VuelosDespegaron - DespeguesDemorados) / VuelosDespegaron) * 100) + "%" +
		"\n\tVuelos aterrizaron:" + to_string(VuelosAterrizaron) +
		"\n\tVuelos aterrizaron Demorados:" + to_string(AterrizajesDemorados) + 
		"\n\tPorcentaje de vuelos que aterrizaron a horario:" + to_string(((VuelosAterrizaron - AterrizajesDemorados) / VuelosAterrizaron) * 100) + "%";
}

void cAeropuerto::imprimir() {
	cout << toString() << endl;
}