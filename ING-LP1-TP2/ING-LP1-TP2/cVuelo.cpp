#include "cVuelo.h"

int cVuelo::NumeroVuelo = 0;

cVuelo::cVuelo() {
	this->NumeroVuelo++;
	this->ID = to_string(NumeroVuelo);
	this->destino = "";
	this->estado = EstadoVuelo::Partida;
	this->PartidaProgramada = new cFecha(0, 0, 0, 0, 0);
	this->ArriboProgramado = new cFecha(0, 0, 0, 0, 0);
	this->Demora = false;
}

cVuelo::cVuelo(string _destino,int P_dia, int P_mes, int P_anio, int P_hora, int P_minutos, int A_dia, int A_mes, int A_anio, int A_hora, int A_minutos,EstadoVuelo Estado) {
	this->NumeroVuelo++;
	this->ID = to_string(NumeroVuelo);
	this->estado = Estado;
	this->destino = _destino;
	this->PartidaProgramada = new cFecha(P_dia, P_mes, P_anio, P_hora, P_minutos);
	this->ArriboProgramado = new cFecha(A_dia, A_mes, A_anio, A_hora, A_minutos);
	this->Demora = false;
}
cVuelo::~cVuelo() {
	delete PartidaProgramada;
	delete PartidaReal;
	delete ArriboProgramado;
	delete ArriboReal;
}

bool cVuelo::AsociarAvion(cAvion* avion) {
	this->Avion = avion;
	return true;
}

void cVuelo::Retraso() {
	srand(time(NULL));//seed
	int Puntual = rand() % 2;//el vuelo se atrasa o no aleatoriamente
	if (Puntual == 1) {
		this->PartidaReal = new cFecha(PartidaProgramada->getDia(), PartidaProgramada->getMes(), PartidaProgramada->getAnio(), PartidaProgramada->getHora() + 1, PartidaProgramada->getMinutos());
		this->ArriboReal = new cFecha(ArriboProgramado->getDia(), ArriboProgramado->getMes(), ArriboProgramado->getAnio(), ArriboProgramado->getHora() + 1, ArriboProgramado->getMinutos());
		Demora = true;
	}
	else {
		this->PartidaReal = new cFecha(PartidaProgramada->getDia(), PartidaProgramada->getMes(), PartidaProgramada->getAnio(), PartidaProgramada->getHora(), PartidaProgramada->getMinutos());
		this->ArriboReal = new cFecha(ArriboProgramado->getDia(), ArriboProgramado->getMes(), ArriboProgramado->getAnio(), ArriboProgramado->getHora(), ArriboProgramado->getMinutos());
	}
}

bool cVuelo::AgregarPasajero(cPasajero* pasajero) {
	if (true == Avion->ListaPasajeros->AgregarPasajeros(pasajero)) {
		return true;
	}
	return false;
}

void cVuelo::CambiarPasajero(string DNI, cVuelo* NuevoVuelo) {

	if (true == NuevoVuelo->AgregarPasajero(Avion->getPasajero(DNI))) {
		Avion->getPasajero(DNI)->setNumeroVuelo(NuevoVuelo->getNumeroVuelo());
		Avion->BajaPasajero(DNI);
	}

	else {
		throw exception("No se pudo cambiar de vuelo");
	}
	
}
void cVuelo::EliminarPasajero(string DNI){
	Avion->ListaPasajeros->EliminarPasajero(DNI);
}

cPasajero* cVuelo::getPasajero(string DNI) {
	return Avion->ListaPasajeros->getPasajero(DNI);
}

int cVuelo::getNumeroVuelo() {
	return NumeroVuelo;
}

int cVuelo::getCantidadPasajerosVuelo() {
	return Avion->getCantidadPasajeros();
}

string cVuelo::getID() {
	return ID;
}

cAvion* cVuelo::getAvion() {
	return Avion;
}

EstadoVuelo cVuelo::getEstadoVuelo() {
	return estado;
}

bool cVuelo::getDemora() {
	return Demora;
}

void cVuelo::setEstadoVuelo(EstadoVuelo estado) {
	this->estado = estado;
}

string cVuelo::to_stringVuelo() const {
	string stringestado;
	if (this->estado == EstadoVuelo::Arribo) {stringestado = "Arribo";}
	else { stringestado = "Partida"; }
	string stringdemora;
	if (this->Demora == false) { stringdemora = "A horario"; }
	else { stringdemora = "Demorado"; }
	string retorno;
	retorno = 
		"Numero de vuelo:" + this->ID +
		"\n\tEstado:" + stringestado +
		"\n\tPartida Programada: " + PartidaProgramada->to_stringFecha() +
		"\n\tArribo Programado: " + ArriboProgramado->to_stringFecha() +
		"\n\tVuelo:" + stringdemora;
	if (Demora == true) {
		retorno = retorno + 
			"\n\tPartida Real:\t " + PartidaReal->to_stringFecha() +
			"\n\tArribo Real:\t " + ArriboReal->to_stringFecha();
	}
	return retorno;
}

void cVuelo::imprimir() const {
	cout << to_stringVuelo() << endl;
	cout << "\n\tLista de pasajeros en el vuelo\n" << endl;
	Avion->getListaPasajeros()->listar();
}

ostream& operator<<(ostream& os, const cVuelo* vuelo){
	os << vuelo->to_stringVuelo();
	return os;
}