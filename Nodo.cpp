#include "Nodo.h"

Nodo::Nodo(Contacto* p){
	this->persona = p;
}

Contacto* Nodo::getContacto() {
	return persona;
}

Nodo::Nodo(){
	persona = new Contacto();
}

Nodo* Nodo::getNext() {
	return next;
}

Nodo* Nodo::getPred() {
	return pred;
}

void Nodo::setNext(Nodo* siguiente){
	next = siguiente;
}

void Nodo::setPred(Nodo* anterior) {
	pred = anterior;
}

